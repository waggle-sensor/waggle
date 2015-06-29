#!/usr/bin/env python

import socket, os, os.path, time, pika
from multiprocessing import Process, Queue
import sys
sys.path.append("..")
from protocol.src.PacketHandler import *

""" This is the communication channel between the cloud and the DC. It consists of a pika client process for RabbitMQ to push and pull messages to and from the cloud and push and pull client processes connected to the DC. """
#TODO add checks for any priorities outside of range - send back to cloud. -- probably need to unpack and repack the message or can just send an error with previous header as payload or something?
#TODO dictionary needs to be made to map device with their 'priority' 

#sets the queue name to the hostname of the node for now
#TODO Queue name and host name need to be different
with open('/etc/waggle/hostname','r') as file_:
    QUEUENAME = file_.read()
    
class external_communicator(object):
    
    def __init__(self):
        pass
    
    incoming = Queue() #stores messages to push into DC
    outgoing = Queue() #stores messages going out to cloud
    
    @staticmethod
    def __cloud_connected__(data):
        cloud_connected = data
    
class pika_push(Process):
    """ A pika client for rabbitMQ to push messages to the cloud. """ 
    def run(self):
        comm = external_communicator()
        print 'Pika push started...'
        while True:
            try:
                try: #TODO find out what happens if cloud isn't readily available. Does it time out after a certain time or just keep hanging on until a connection is made?
                    #connecting to cloud
                    connection = pika.BlockingConnection(pika.ConnectionParameters('reptile.mcs.anl.gov')) #TODO change this to cloud IP
                    channel = connection.channel()
                    comm.__cloud_connected__(True) #set the flag to true when connected to cloud
                except: 
                    print 'Pika_push currently unable to connect to cloud...' 
                    comm.__cloud_connected__(False) #set the flag to false when not connected to the cloud
                
                #Creating a queue
                channel.queue_declare(queue=QUEUENAME) #TODO change this to queue ID
                while comm.outgoing.empty(): #sleeps until there are messages to send
                    
                    time.sleep(1)
                #Sending a message through the default exchange ' '. 
                msg = comm.outgoing.get() # gets the first item in the outgoing queue
                channel.basic_publish(exchange= 'waggle_in', routing_key= 'in', body= msg) #sends to cloud #TODO change routing_key to unique ID
                
                #close connection to flush the network buffers and send msg
                connection.close()
                comm.cloud_connected = False #change the flag to false when not connected to cloud
            except KeyboardInterrupt, k:
                        print "Shutting down."
                        break
        connection.close()
        
class pika_pull(Process):
    """ A pika client for pulling messages from the cloud. """ 
    
    def run(self):
        print 'Pika pull started...'
        comm = external_communicator()
        while True: 
            try:#TODO find out what happens if cloud isn't readily available. Does it time out after a certain time or just keep hanging on until a connection is made?
                #connecting to a broker on the local machine
                connection = pika.BlockingConnection(pika.ConnectionParameters('reptile.mcs.anl.gov')) 
                channel = connection.channel()
                
            except:
                print 'Pika_pull currently unable to connect to cloud...' 
                break
            #Creating a queue
            channel.queue_declare(queue=QUEUENAME) #TODO change this to queue ID
            channel.basic_consume(callback, queue=QUEUENAME) #TODO change queue to unique ID
            #TODO need to find out if it will send all messages in queue at once or if it will push one at a time?
            #loop that waits for data 
            channel.start_consuming()
                
#pulls the message from the cloud and puts it into incoming queue 
def callback(ch, method, properties, body):
    comm.incoming.put(body) #TODO does this work?
    ch.basic_ack(delivery_tag=method.delivery_tag) #RabbitMQ will not delete message until ack received
                
            
        
class client_pull(Process):
    """ A client process that connects to the data cache and pulls outgoing messages. Sends a pull request in the format 'o '"""
    #TODO pika needs a flag to signal that the cloud is connected
    
    def run(self):
        print 'Client pull started...'
        comm = external_communicator()
        while True:
            try:
                time.sleep(10)
                while comm.__cloud_connected__: #checks if the cloud is connected
                    if os.path.exists('/tmp/Data_Cache_pull_server'):
                        client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                        client_sock.connect('/tmp/Data_Cache_pull_server') #connects to server
                        print "Client_pull connected to data cache... "
                        data = 'o  ' #sends the pull request in the correct format
                        print "sending: " , data
                        client_sock.send(data)
                        msg = client_sock.recv(4028) #can be changed #TODO find out what happens if the server closes the client's connection...
                        if not msg:
                            print 'if not msg'
                            break
                        else:
                            print 'Recieved msg: ', msg
                            if msg != 'False':
                                comm.outgoing.put(msg) #puts the message in the outgoing queue
                                client_sock.close() #closes socket after each message is sent #TODO is there a better way to do this?
                            else: 
                                time.sleep(10)
            except KeyboardInterrupt, k:
                    print "Shutting down."
                    break

class client_push(Process):
    """ A client process that connects to the data cache and pushes incoming messages. """
    
    def run(self):
        print 'Client push started...'
        comm = external_communicator()
        if os.path.exists('/tmp/Data_Cache_push_server'):
            client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
            #TODO rearrange this to make more sense?
            while True:
                while comm.incoming.empty(): #sleeps until a message arrives in the incoming queue 
                    time.sleep(1)
                try: 
                    client_sock.connect('/tmp/Data_Cache_push_server') #opens socket when a message is in the queue
                    print "Client_push connected to data cache... "
                    msg = comm.incoming.get() #gets the incoming message from the queue
                    header = get_header(msg)
                    #TODO Need to make a device priority dictionary stored on the node itself.
                    #TODO Do a check to make sure the recipient is actually a part of this node, return error if not
                    flags = header['flags'] #extracts priorities
                    dev = header['r_uniqid'] #gets the recipient ID
                    #TODO write dictionary mapping device ID to priorities
                    if dev == QUEUENAME: 
                        print msg #just prints the message to the screen if the recipient is the NC #TODO handle messages being sent to NC 
                    else:
                        msg_p = flags[1]
                        #add flags to msg in correct format
                        msg += (str(msg_p) + '|')
                        msg += (str(dev) + ',') #TODO need to change to look up device priority in dictionary before sending message 
                        msg += 'i,' #incoming push
                        print "sending: " , msg
                        client_sock.send(msg) #sends msg
                        client_sock.close() #closes the socket
                except KeyboardInterrupt, k:
                    print "Shutting down."
                    break
            client_sock.close()
        else:
            print "Couldn't Connect!"
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
        