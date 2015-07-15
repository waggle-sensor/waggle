#!/usr/bin/env python

import socket, os, os.path, time
from multiprocessing import Process, Queue
import sys
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
#sys.path.append('..')
from device_dict import DEVICE_DICT
    
#gets the NC hostname 
with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()
    
class internal_communicator(object):
    """
        The internal communicator is the channel of communication between the GNs and the data cache. It consists of four processes: Push and pull client processes to communicate with the data cache
        and push and pull server processes for communicating with the GNs. 
    
    """ 
    #TODO write logic for putting messages back in DC if GN disconnects before message is sent
    #TODO write the thing that handles messages going to the NC
    #TODO Could combine processes: one server and one client instead of two.
    
    def __init__(self):
        pass
    
    DC_push = Queue() #stores messages to be pushed to the DC
    incoming_request = Queue() #stores the unique ID of GNs currently connected
    
    #stores incoming msgs. Each guest node has a unique queue that corresponds to the location in the device dictionary.
    incoming_msg = [Queue(), Queue(), Queue(), Queue(), Queue()] 
    
class internal_client_push(Process):
    """ 
        A client process that connects to the data cache and pushes outgoing messages. 
    """
    print 'Internal client push started...'
    
    def run(self):
        comm = internal_communicator()
        while True:
            try:
                #if the queue is not empty, connect to DC and send msg
                if not comm.DC_push.empty(): 
                    if os.path.exists('/tmp/Data_Cache_server'):
                        client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                        try:
                            client_sock.connect('/tmp/Data_Cache_server')
                            #print "client_push connected to data cache... "
                            data = comm.DC_push.get() #Gets message out of the queue and sends to data cache
                            #print "sending: " , data
                            client_sock.sendall(data)
                            client_sock.close() #closes socket after each message is sent #TODO is there a better way to do this?
                        except:
                            print 'Internal client push unable to connect to DC... connection likely refused.'
                            time.sleep(5)
                            client_sock.close()
                        
                    else: 
                        time.sleep(5)
                        print 'Internal client push unable to connect to DC...'
                else: 
                    time.sleep(1) #else, wait until messages are in queue
            except KeyboardInterrupt, k:
                    print "Shutting down."
                    break
        client_sock.close()

class internal_client_pull(Process):
    """ 
        A client process that connects to the data cache, sends a pull request, and retrieves the message from the data cache. 
        When a GN connects to the pull server, the device ID is put into a queue. When the queue is not empty, this process
        pulls the device location and sends it as the pull request.
    """
    
    def run(self):
        comm = internal_communicator()
        print 'Internal client pull started...'
        
        while True:
            while comm.incoming_request.empty(): #sleeps until a GN initiates a pull request
                time.sleep(1)
            try: 
                if os.path.exists('/tmp/Data_Cache_server'):
                    client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                    print "client_pull connected to data cache... "
                    try:
                        client_sock.connect('/tmp/Data_Cache_server')#opens socket when there is an incoming pull request
                        dev = comm.incoming_request.get() #gets the dev ID that is initiating the pull request
                        request = dev + '|' #puts the request in the correct format for the DC
                        print 'Internal client pull sending request: ', request
                        client_sock.send(request)
                        try:
                            msg = client_sock.recv(4028) #arbitrary, can go in config file
                        except: 
                            #print 'Client pull connection lost.'
                            client_sock.close()
                            time.sleep(1)
                            break
                        if not msg:
                            break
                        else:
                            #print 'Client pull recieved msg: ', msg
                            comm.incoming_msg[int(dev) - 1].put(msg) #puts the message in the device's incoming queue 
                            client_sock.close() #closes socket after each message is sent #TODO is there a better way to do this?
                            
                                    
                    except:
                        print 'Internal client pull unable to connect to DC... connection likely refused.'
                        client_sock.close()
                        time.sleep(5)
                else:
                    print "Internal client pull unable to connect to DC."
                    time.sleep(1)
            except KeyboardInterrupt, k:
                print "Internal client pull shutting down."
                break
        client_sock.close()
        
class push_server(Process):
    """ 
        Server process that listens for connections from GNs. Once a GN connects and sends the message, the push server puts the message into the DC_Push queue, where it will be pulled out and sent by the push client. 
    """
    
    def run(self):
        comm = internal_communicator()
        HOST = '10.10.10.10'
        PORT = 9090
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.bind((HOST,PORT))
        server.listen(5) #supports up to 5 threads, one for each GN
        print 'Internal push server process started...'
        
        while True:
            conn, addr = server.accept()
            #print "Push server connected to ", addr
            while True:
                try:
                    data = conn.recv(4028) 
                    if not data:
                        break #breaks the loop when the client socket closes
                    else:
                        print 'Push server pushing msg into DC: ', data
                        comm.DC_push.put(data)
                       
                except KeyboardInterrupt, k:
                    print "Internal push server shutting down."
                    break
        server.close()
            
class pull_server(Process):
    """ 
        Server process that listens for connections from GNs. When a guest node connects, it sends its unique ID. The pull server puts that ID into a queue. The ID gets pulled out by the pull client and sent
        to the data cache. The client pull recieves a message from the data cache, puts it into the corresponding GN's queue. When the queue is not empty, the pull server pulls the message out and sends it to
        GN. If the GN disconnects before this process is complete, the pull server puts the message back into the DC_push queue to be put back into the data cache.
        
    """
    
    def run(self):
        comm = internal_communicator()
        HOST = '0.0.0.0'
        PORT = 9091
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.bind((HOST,PORT))
        server.listen(5) #supports up to 5 threads, one for each GN
        print 'Internal pull server process started...'
        
        while True:
            client_sock, addr = server.accept()
            #print "Connected to ", addr
            while True:
                try:
                    data = client_sock.recv(4028) #Guest nodes connect and send their uniq_ID
                    #print 'Pull server received: ', data
                    if not data:
                        break
                    else:
                        try:
                            data = DEVICE_DICT[data] #gets the device queue location from dictionary
                        except:
                            print 'Error...Internal pull server device not in dictionary.'
                        comm.incoming_request.put(str(data)) #Unique ID goes into incoming requests queue. These get pulled out by the pull_client as pull requests
                        while comm.incoming_msg[data-1].empty():
                            time.sleep(1) #sleeps then tries again
                        msg = comm.incoming_msg[data-1].get() #returns incoming messages. 
                        try: 
                            client_sock.sendall(msg) #sends the msg to the GN 
                        except: 
                            #puts the message back into the DC_push queue if the GN disconnects before the message is sent.
                            print 'Putting message back into DC_push queue...'
                            comm.DC_push.put(data)
                except KeyboardInterrupt, k:
                    print "Internal pull server shutting down."
                    server.close()
                    break
        server.close()
    
#uncomment for testing
#if __name__ == "__main__":
    #try:
        ##starts the pull server
        #pull_serv = pull_server()
        #pull_serv.start()
        
        ##starts the push server 
        #push_serv = push_server()
        #push_serv.start()
        
        ##starts the push client
        #push_client = internal_client_push()
        #push_client.start()
        
        ##starts the pull client
        #pull_client = internal_client_pull()
        #pull_client.start()
        #while True:
            #pass
        
    #except KeyboardInterrupt, k:
        #pull_serv.terminate()
        #push_serv.terminate()
        #push_client.terminate()
        #pull_client.terminate()
        #print 'Done.'
    
                