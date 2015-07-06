#!/usr/bin/env python

import socket, os, os.path, time, pika
from multiprocessing import Process, Queue, Value
import sys
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
sys.path.append('..')
from device_dict import DEVICE_DICT

""" This is the communication channel between the cloud and the DC. It consists of a pika client process for RabbitMQ to push and pull messages to and from the cloud and push and pull client processes connected to the DC. """
#TODO add checks for any priorities outside of range - send back to cloud. -- probably need to unpack and repack the message or can just send an error with previous header as payload or something?
#TODO dictionary needs to be made to map device with their 'priority' 

#sets the queue name to the hostname of the node for now
#TODO Queue name and host name need to be different
with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()

with open('/etc/waggle/queuename','r') as file_:
    QUEUENAME = file_.read().strip()    
    
class external_communicator(object):
    
    def __init__(self):
        pass
    
    incoming = Queue() #stores messages to push into DC #TODO should have a queue for each GN
    outgoing = Queue() #stores messages going out to cloud
    cloud_connected = Value('i')
    
class pika_push(Process):
    """ A pika client for rabbitMQ to push messages to the cloud. """ 
    def run(self):
        comm = external_communicator()
        creds = pika.PlainCredentials('guest1', 'guest1')
        #params = pika.ConnectionParameters('beehive.wa8.gl',5672, '/', creds) 
        #params = pika.ConnectionParameters('10.10.10.108',5672, '/', creds) 
        params = pika.ConnectionParameters('10.10.10.139',5672, '/', creds) 
        print 'Pika push started...'
        while True:
            try:
                try: 
                    #connecting to cloud
                    connection = pika.BlockingConnection(params)
                    channel = connection.channel()
                    comm.cloud_connected.value = 1 #set the flag to true when connected to cloud
                    #Creating a queue
                    channel.queue_declare(queue=QUEUENAME)
                    print 'Pika push connection successful'
                    while comm.outgoing.empty(): #sleeps until there are messages to send
                        time.sleep(1)
                    
                    msg = comm.outgoing.get() # gets the first item in the outgoing queue
                    print 'Pika_push... sending msg to cloud.'
                    channel.basic_publish(exchange='waggle_in', routing_key= 'in', body= msg) #sends to cloud 
                except: 
                    print 'Pika_push currently unable to connect to cloud...' 
                    comm.cloud_connected.value = 0 #set the flag to 0 when not connected to the cloud
                    time.sleep(5)
            except pika.exceptions.ConnectionClosed:
                        print "Pika push connection closed. Waiting 5 seconds and trying again."
                        comm.cloud_connected.value = 0
                        time.sleep(5)
        connection.close()
        
class pika_pull(Process):
    """ A pika client for pulling messages from the cloud. """ 
    
    def run(self):
        print 'Pika pull started...'
        comm = external_communicator()
        creds = pika.PlainCredentials('guest1', 'guest1')
        #params = pika.ConnectionParameters('beehive.wa8.gl',5672, '/', creds) #beehive.wa8.gl
        #params = pika.ConnectionParameters('10.10.10.108',5672, '/', creds) #beehive.wa8.gl
        params = pika.ConnectionParameters('10.10.10.139',5672, '/', creds)
        while True: 
            try:
                try:
                    connection = pika.BlockingConnection(params) 
                    channel = connection.channel()
                    print 'Pika pull connection successful.'
                    comm.cloud_connected.value = 1
                     #Creating a queue
                    channel.queue_declare(queue=QUEUENAME)
                    channel.basic_consume(callback, queue=QUEUENAME)
                    #loop that waits for data 
                    channel.start_consuming()
                except:
                    print 'Pika_pull currently unable to connect to cloud. Waiting 5 seconds before trying again.' 
                    comm.cloud_connected.value = 0 #set the flag to 0 when not connected to the cloud
                    time.sleep(5)
               
            except pika.exceptions.ConnectionClosed:
                        print "Pika pull connection closed. Waiting 5 seconds before trying again."
                        comm.cloud_connected.value = 0 #set the flag to false when not connected to the cloud
                        time.sleep(5)
        connection.close()
                
                
#pulls the message from the cloud and puts it into incoming queue 
def callback(ch, method, properties, body):
    comm = external_communicator()
    print 'Callback received message from cloud: ', body
    comm.incoming.put(body) #TODO does this work?
    ch.basic_ack(delivery_tag=method.delivery_tag) #RabbitMQ will not delete message until ack received
                
            
        
class client_pull(Process):
    """ A client process that connects to the data cache and pulls outgoing messages. Sends a pull request in the format 'o '"""
    #TODO pika needs a flag to signal that the cloud is connected
    #TODO find out what happens if the server disconnects
    
    def run(self):
        print 'Client pull started...'
        comm = external_communicator()
        while True:
            try:
                if comm.cloud_connected.value == 1: #checks if the cloud is connected
                    if os.path.exists('/tmp/Data_Cache_pull_server'):
                        client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                        client_sock.connect('/tmp/Data_Cache_pull_server') #connects to server
                        print "Client_pull connected to data cache... "
                        data = 'o  ' #sends the pull request in the correct format
                        client_sock.send(data)
                        msg = client_sock.recv(4028) #can be changed #TODO find out what happens if the server closes the client's connection...
                        if not msg:
                            break
                        else:
                            print 'Client pull recieved msg.'
                            if msg != 'False':
                                comm.outgoing.put(msg) #puts the message in the outgoing queue
                                client_sock.close() #closes socket after each message is sent #TODO is there a better way to do this?
                            else: 
                                time.sleep(5)
                    else:
                        print 'Client pull unable to connect to the cloud...'
                else:
                    print 'Client pull...cloud is not connected. Waiting 5 seconds and trying again.'
                    time.sleep(5)
            except KeyboardInterrupt, k:
                    print "Shutting down."
                    break
        client_sock.close()
        
        
class client_push(Process):
    """ A client process that connects to the data cache and pushes incoming messages. """
    
    def run(self):
        print 'Client push started...'
        comm = external_communicator()
        
            #TODO rearrange this to make more sense?
        while True:
            while comm.incoming.empty(): #sleeps until a message arrives in the incoming queue 
                time.sleep(1)
            try: 
                if os.path.exists('/tmp/Data_Cache_push_server'):
                    client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                    client_sock.connect('/tmp/Data_Cache_push_server') #opens socket when a message is in the queue
                    print "Client_push connected to data cache... "
                    msg = comm.incoming.get() #gets the incoming message from the queue
                    try:
                        header = get_header(msg)
                        #TODO Do a check to make sure the recipient is actually a part of this node, return error if not
                        flags = header['flags'] #extracts priorities
                        dev = header['r_uniqid'] #gets the recipient ID
                        #TODO write dictionary mapping device ID to priorities
                        if dev == int(HOSTNAME): #msg intended for NC
                            try:
                                msg = unpack(msg)
                                print 'Message recieved from cloud: ', msg[1] #just prints the message to the screen if the recipient is the NC #TODO handle messages being sent to NC 
                            except:
                                print 'Unpack unsuccessful.'
                            client_sock.close() #closes the socket
                        else:
                            try: 
                                dev_loc = DEVICE_DICT[str(dev)] #TODO can change PacketHandler to keep the uniqueID as a string
                            except: 
                                print 'Error: Unknown recipient ID. Message will not be put in data cache.'
                                break
                            msg_p = flags[1]
                            #add flags to msg in correct format
                            msg += (str(msg_p) + '|')
                            msg += (str(dev_loc) + ',') #TODO need to change to look up device priority in dictionary before sending message 
                            msg += 'i,' #incoming push
                            print "Client push sending msg to DC. "
                            client_sock.send(msg) #sends msg
                            client_sock.close()
                    except:
                        print "Not a valid message. Will not be put into the DC"
                        client_sock.close() #closes the socket
                else:
                    print "Unable to connect to Data Cache."
            except KeyboardInterrupt, k:
                print "Shutting down."
                break
        client_sock.close()
        
        print "Done."
        
        
if __name__ == "__main__":
    try:
        #starts the pull server
        pika_pull = pika_pull()
        pika_pull.start()
        
        #starts the push server 
        pika_push = pika_push()
        pika_push.start()
        
        #starts the push client
        push_client = client_push()
        push_client.start()
        
        #starts the pull client
        pull_client = client_pull()
        pull_client.start()
        while True:
            pass
        
    except KeyboardInterrupt, k:
        pika_pull.terminate()
        pika_push.terminate()
        push_client.terminate()
        pull_client.terminate()
        print 'Done.'
        