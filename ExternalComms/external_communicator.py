#!/usr/bin/env python

import socket, os, os.path, time, PacketHandler
from multiprocessing import Process, Queue

""" This is the communication channel between the cloud and the DC. It consists of a pika client process for RabbitMQ to push and pull messages to and from the cloud and push and pull client processes connected to the DC. """
class external_communicator(object):
    
    def __init__():
        pass
    
    incoming = Queue() #stores messages to push into DC
    outgoing = Queue() #stores messages going out to cloud
    cloud_connected = False
    

class client_pull(Process):
    """ A client process that connects to the data cache and pulls outgoing messages. Sends a pull request in the format 'o '"""
    #TODO pika needs a flag to signal that the cloud is connected
    
    def run(self):
        comm = external_communicator()
        while True:
            try:
                while comm.cloud_connected: #checks if the cloud is connected
                    if os.path.exists('/tmp/Data_Cache_pull_server'):
                        client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                        client_sock.connect('/tmp/Data_Cache_pull_server') #connects to server
                        print "Ready"
                        data = 'o  ' #sends the pull request in the correct format
                        print "sending: " , data
                        client_sock.sendall()
                        time.sleep(1) #waits... may not be neccessary
                        msg = client_sock.recv(4028) #can be changed #TODO find out what happens if the server closes the client's connection...
                        if msg != False:
                            comm.outgoing.put(msg) #puts the message in the outgoing queue
                            client_sock.close() #closes socket after each message is sent #TODO is there a better way to do this?
                        else: pass
            except KeyboardInterrupt, k:
                    print "Shutting down."
                    break

class client_push(Process):
    """ A client process that connects to the data cache and pushes incoming messages. """
    
    def run(self):
        comm = external_communicator()
        print "Connecting to data cache... client_push"
        if os.path.exists('/tmp/Data_Cache_push_server'):
            client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
            print "Ready"
            while True:
                while incoming.empty(): #sleeps until a message arrives in the incoming queue 
                    time.sleep(1)
                try: 
                    client_sock.connect('/tmp/Data_Cache_push_server') #opens socket when a message is in the queue
                    msg = comm.incoming.get() #gets the incoming message from the queue
                    header = PacketHandler.unpack_header(msg)
                    #TODO may need to do a check to make sure the recipient is actually a part of this node
                    #TODO Need to confirm that the cloud will send the correct device priority or need to make a dictionary stored on the node itself.
                    flags = header['flags'] #extracts priorities
                    dev = flags[0]
                    msg_p = flags[1]
                    #add flags to msg in correct format
                    msg += (str(msg_p) + '|')
                    msg += (str(dev) + ',')
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
        