# registrationprocess.py
import sys
import os
sys.path.append("..")
sys.path.append("/usr/lib/waggle/")
from multiprocessing import Process, Manager
import pika
from protocol.PacketHandler import *
import logging
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.CRITICAL)
from crcmod.predefined import mkCrcFun
from cassandra.cluster import Cluster
import time

with open('/etc/waggle/cassandra_ip','r') as f:
    CASSANDRA_IP = f.read().strip()

class RegProcess(Process):
    """
        This process handles all registration requests.
        It is responsible to receiving all requests, updating the routing table,
        and writing the routing information to a permanent file.
    """


    def __init__(self,routing_table):
        """
            Starts up the Registration Process
        """
        super(RegProcess,self).__init__()
        self.routing_table = routing_table

        # Set up the Rabbit connection
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
        self.channel = self.connection.channel()
        self.channel.basic_qos(prefetch_count=1)
        # Declare this process's queue
        self.channel.queue_declare("registration")
        self.channel.basic_consume(self.callback, queue='registration')
        self.session = None
        self.cluster = None

    def callback(self,ch,method,props,body):
        """
            Handles incoming registration messages, including:
                Initial registration (subtype 'r')
                SSL Certificate Registration (subtype 's')
                Configuration file registration (subtype 'n')

            Each subtype is handled as a apart of an if-elif statement.
        """
        print ("Received a registration request.")

        # Unpack the header and see if it is already registered
        header,msg = unpack(body)
        minor_type = None
        if header["msg_mi_type"] == ord('r'):
            if header["s_uniqid"] in self.routing_table:
                minor_type = ord('a');
            else:
                print "Registering new node."
                # Add the node to the registration file and make and bind its queue
                with open('registrations/nodes.txt','a+') as nodeList:
                    nodeList.write("{}:{}\n".format(str(header["s_uniqid"]),msg))
                self.channel.queue_declare(msg)
                self.channel.queue_bind(exchange='internal',queue=msg,routing_key=msg)
                self.routing_table[header["s_uniqid"]] = msg
                minor_type = ord('n')

            # Send the node a registration confirmation.
            resp_header = {
                    "msg_mj_type" : ord('r'),
                    "msg_mi_type" : minor_type,
                    "r_uniqid"    : header["s_uniqid"],
                    "resp_session": header["snd_session"]
            }
            msg = "Congratulations node {}! You are registered under the queue {}!".format(header["s_uniqid"],msg)
            for packet in pack(resp_header,msg):
                response = packet
            self.channel.basic_publish(exchange='waggle_in',routing_key="in",body=response)

        elif header["msg_mi_type"] == ord('s'): # They want to get an SSL Certificate
            print "Someone wants an SSL cert."
            # Write the request to a file to be used by the CA for signing
            replyQueue = msg.split("\n")[0]
            msg = "\n".join(msg.split("\n")[1:])
            print replyQueue
            certFile = "/tmp/" + self.name
            with open(certFile + "_req.pem","w+") as cert:
                cert.write(msg)
            cmd = "openssl ca -config /usr/lib/waggle/SSL/waggleca/openssl.cnf " + \
                "-in " + certFile + "_req.pem" + " -out " + certFile + "_cert.pem " + \
                "-notext -batch -extensions client_ca_extensions"
            os.system(cmd)
            cert = ""
            with open(certFile + "_cert.pem","r") as cert:
            	cert = cert.read()
            	print cert
            ch.basic_publish(exchange='',
                 routing_key=replyQueue,
                 body=cert)

        elif header["msg_mi_type"] == ord('n'): # They are sending us a config file.
        # Cassandra note: If the node is already in the node_info table,
        # then this will preform an UPSERT of the config file instead of an INSERT.
        # This is inherent to Cassandra, so is not explicitly stated here.
            try:
                self.cassandra_insert(header,msg)
            except Exception:
                print "Cassandra connection failed. Will retry soon..."
                ch.basic_nack(delivery_tag = method.delivery_tag)
                time.sleep(1)
                self.cassandra_connect()
                return


        ch.basic_ack(delivery_tag = method.delivery_tag)

    def cassandra_insert(self,header,data):
    """
        Insert a list of data into the currently connected Cassandra database.
    """
        try:
            prepared_statement = self.session.prepare("INSERT INTO node_info" + \
                " (node_id, timestamp, config_file)" + \
                " VALUES (?, ?, ?)")
            bound_statement = prepared_statement.bind([header["s_uniqid"],time.time()*1000,data])
            self.session.execute(bound_statement)
        except Exception as e:
            raise


    def cassandra_connect(self):
    """
        Try to establish a new connection to Cassandra.
    """
        try:
            self.cluster.shutdown()
        except:
            pass
        self.cluster = Cluster(contact_points=[CASSANDRA_IP])

        try: # Might not immediately connect. That's fine. It'll try again if/when it needs to.
            self.session = self.cluster.connect('waggle')
        except:
            print "WARNING: Cassandra connection to " + CASSANDRA_IP + " failed."
            print "The process will attempt to re-connect at a later time."

    def run(self):
        self.cassandra_connect()
        self.channel.start_consuming()


    def join(self):
        super(RegProcess,self).terminate()
        self.connection.close()
