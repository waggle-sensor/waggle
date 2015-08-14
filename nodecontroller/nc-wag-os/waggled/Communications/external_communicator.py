#!/usr/bin/env python

import socket, os, os.path, time, pika, logging, datetime, sys
from multiprocessing import Process, Queue, Value
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
sys.path.append('../NC/')
from NC_configuration import *
sys.path.append('../NC/')
from internal_communicator import send

""" 
    The external communicator is the communication channel between the cloud and the DC. It consists of four processes: two pika clients for pushing and pulling to the cloud and two clients for pushing 
    and pulling to the data cache.
"""


class external_communicator(object):
    """
        This class is a convenience class that stores shared variables amongst all instances. 
    """
    
    def __init__(self):
        pass
    
    incoming = Queue() #stores messages to push into DC 
    outgoing = Queue() #stores messages going out to cloud
    cloud_connected = Value('i') #indicates if the cloud is or is not connected. Clients only connect to DC when cloud is connected. 
    params = pika.connection.URLParameters(CLOUD_ADDR) #SSL 


class pika_push(Process):
    """ 
        A pika client for rabbitMQ to push messages to the cloud. When the cloud is connected, the pull client sends pull requests and puts messages into the outgoing queue. 
        When the outgoing queue is not empty, this pika client will connect and push those messages to the cloud.
    """ 
    def run(self):
        #set log files
        #TODO The logging doesn't work for the individual processes. Log for all communications processes can be cound in /var/log
        stdout='/var/log/comms/pika_push.log'
        stderr='/var/log/comms/pika_push.err'
        
        comm = external_communicator()
        params = comm.params
        #params = pika.connection.URLParameters("amqps://waggle:waggle@10.10.10.108:5671/%2F") #SSL
        sys.stdout.write('Pika push started...\n')
        while True:
            try: 
                #connecting to cloud
                connection = pika.BlockingConnection(params)
                channel = connection.channel()
                comm.cloud_connected.value = 1 #set the flag to true when connected to cloud
                #Declaring the queue
                channel.queue_declare(queue=QUEUENAME)
                sys.stdout.write('Pika push connected to cloud.\n')
                send_registrations() #sends registration for each node and node controller configuration file
                connected = True
            except: 
                #print 'Pika_push currently unable to connect to cloud...' 
                comm.cloud_connected.value = 0 #set the flag to 0 when not connected to the cloud. I
                time.sleep(5)
                connected = False
                
            while connected:
                try:
                    while comm.outgoing.empty(): #sleeps until there are messages to send
                        time.sleep(1)
                    
                    msg = comm.outgoing.get() # gets the first item in the outgoing queue
                    #print 'Pika_push... sending msg to cloud.'
                    channel.basic_publish(exchange='waggle_in', routing_key= 'in', body= msg) #sends to cloud 
                    #connection.close()
                    
                except pika.exceptions.ConnectionClosed:
                    sys.stderr.write("Pika push connection closed. Waiting and trying again " + str(datetime.datetime.now()) + '\n')
                    print "Pika push connection closed. Waiting and trying again "
                    comm.cloud_connected.value = 0
                    time.sleep(5)
                    break #need to break this loop to reconnect
        connection.close(0)
        
class pika_pull(Process):
    """ 
        A pika client for pulling messages from the cloud. If messages are sent from the cloud, this client will put them into the incoming queue.
    """ 
    
    def run(self):
        #set log files
        #TODO The logging doesn't work for the individual processes. Log for all communications processes can be cound in /var/log
        stdout='/var/log/comms/pika_pull.log'
        stderr='/var/log/comms/pika_pull.err'
        
        sys.stdout.write('Pika pull started...\n')
        comm = external_communicator()
        params = comm.params
        #params = pika.connection.URLParameters("amqps://waggle:waggle@10.10.10.108:5671/%2F") #SSL
        while True: 
            
            try:
                try:
                    connection = pika.BlockingConnection(params) 
                    channel = connection.channel()
                    sys.stdout.write('Pika pull connection successful.\n')
                    comm.cloud_connected.value = 1 #sets indicator flag to 1 so clients will connect to data cache
                     #Creating a queue
                    try:
                        channel.queue_declare(queue=QUEUENAME)
                    except:
                        #print 'Cannot declare queuename.'
                        pass
                    channel.basic_consume(callback, queue=QUEUENAME)
                    #loop that waits for data 
                    channel.start_consuming() #TODO Can this process still publish to RabbitMQ while this is continuously looping? If so, The pika_pull and pika_push processes can and should be combined. 
                except:
                    #print 'Pika_pull currently unable to connect to cloud. Waiting before trying again.'
                    #logging.warning('Pika_pull currently unable to connect to cloud. Waiting before trying again.')
                    comm.cloud_connected.value = 0 #set the flag to 0 when not connected to the cloud
                    time.sleep(5)
               
            except pika.exceptions.ConnectionClosed:
                sys.stderr.write("Pika pull connection closed. Waiting before trying again." + str(datetime.datetime.now()) + '\n')
                print "Pika pull connection closed. Waiting before trying again."
                comm.cloud_connected.value = 0 #set the flag to false when not connected to the cloud
                time.sleep(5)
        connection.close()
                
                
#pulls the message from the cloud and puts it into incoming queue 
def callback(ch, method, properties, body):
    comm = external_communicator()
    #print 'Callback received message from cloud: ', body
    comm.incoming.put(body) 
    ch.basic_ack(delivery_tag=method.delivery_tag) #RabbitMQ will not delete message until ack received
                
            
        
class external_client_pull(Process):
    """ 
        A client process that connects to the data cache if the cloud is currently connected.  Once a message is recieved, it is put into the outgoing queue. 
        
    """
    
    def run(self):
        #set log files
        #TODO The logging doesn't work for the individual processes. Log for all communications processes can be cound in /var/log
        stdout='/var/log/comms/external_client_pull.log'
        stderr='/var/log/comms/external_client_pull.err'
        
        sys.stdout.write('External client pull started...\n')
        comm = external_communicator()
        while True:
            try:
                if comm.cloud_connected.value == 1: #checks if the cloud is connected
                    try:
                        if os.path.exists('/tmp/Data_Cache_server'):
                            client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                            client_sock.connect('/tmp/Data_Cache_server') #connects to server
                            #print "Client_pull connected to data cache... "
                            #sends the pull request indicating that it is an outgoing pull request. 
                            #TODO This can be improved (both clients combined into one) if there is a better way to distinguish incoming vs outgoing pull and pull vs push requests. 
                            data = '|o' 
                            client_sock.send(data)
                            msg = client_sock.recv(4028) #can be changed 
                            if not msg:
                                break
                            else:
                                if msg != 'False':
                                    comm.outgoing.put(msg) #puts the message in the outgoing queue
                                    client_sock.close() #closes socket after each message is sent #TODO is there a better way to do this?
                                else: 
                                    client_sock.close()
                        else:
                            sys.stdout.write('External client pull unable to connect to the data cache... path does not exist!\n')
                            time.sleep(5)
                    except:
                        sys.stdout.write('External client pull disconnected from data cache. Waiting and trying again.\n')
                        client_sock.close()
                        time.sleep(5)
                else:
                    #print 'External client pull...cloud is not connected. Waiting and trying again.'
                    time.sleep(5)
            except KeyboardInterrupt, k:
                    sys.stdout.write("External client pull shutting down.\n")
                    break
        client_sock.close()
        
        
class external_client_push(Process):
    """ 
        A client process that connects to the data cache and pushes incoming messages.
    """
    
    def run(self):
        #set log files
        #TODO The logging doesn't work for the individual processes. Log for all communications processes can be cound in /var/log
        stdout='/var/log/comms/external_client_pull.log'
        stderr='/var/log/comms/external_client_pull.err'
        
        sys.stdout.write('External client push started...\n')
        comm = external_communicator()
        
            #TODO clean up if possible
        while True:
            while comm.incoming.empty(): #sleeps until a message arrives in the incoming queue 
                time.sleep(1)
            try: 
                if os.path.exists('/tmp/Data_Cache_server'):
                    client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                    client_sock.connect('/tmp/Data_Cache_server') #opens socket when a message is in the queue
                    #print "Client_push connected to data cache... "
                    msg = comm.incoming.get() #gets the incoming message from the queue
                    client_sock.send(msg) #sends msg
                    client_sock.close()
                else:
                    sys.stdout.write("External client push-Unable to connect to Data Cache.\n")
                    time.sleep(5)
            except KeyboardInterrupt, k:
                sys.stdout.write("External client push shutting down.\n")
                break
        client_sock.close()
        
        

def send_registrations():
    """ 
        Sends registration message for NC and GNs and configuration file for node controller.
    """
    #loops through the list of nodes and send a registration for each one
    for key in DEVICE_DICT.keys():
        header_dict = {
            "msg_mj_type" : ord('r'),
            "msg_mi_type" : ord('r'),
            "s_uniqid"    : int(key)
            }
        msg = str(QUEUENAME)
        try: 
            packet = pack(header_dict, message_data = msg)
            print 'Registration made for node ID ', key
            for pack_ in packet:
                send(pack_)
            
        except Exception as e: 
            print e
    #send nodecontroller configuration file
    config = get_config() #this function is in NC_configuration
    try:
        packet = make_config_reg(config)
        for pack_ in packet:
            send(pack_)
    except Exception as e:
        print e
            
            
##uncomment for testing
#if __name__ == "__main__":
    #try:
        ##starts the pika pull client
        #pika_pull = pika_pull()
        #pika_pull.start()
        
        ##starts the pika push client
        #pika_push = pika_push()
        #pika_push.start()
        
        ##starts the push client
        #push_client = external_client_push()
        #push_client.start()
        
        ##starts the pull client
        #pull_client = external_client_pull()
        #pull_client.start()
        #while True:
            #pass
        
    #except KeyboardInterrupt, k:
        #pika_pull.terminate()
        #pika_push.terminate()
        #push_client.terminate()
        #pull_client.terminate()
        #print 'Done.'