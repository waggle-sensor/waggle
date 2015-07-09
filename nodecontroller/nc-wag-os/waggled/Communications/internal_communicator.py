#!/usr/bin/env python

import socket, os, os.path, time
from multiprocessing import Process, Queue
import sys
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
#sys.path.append('..')
from device_dict import DEVICE_DICT
    
with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()
    
class internal_communicator(object):
    """ This class acts as the channel of communication to and from the GN and the NC. The internal_msg_handler pulls messages from the data cache, parses the header, and sends the message to the appropriate location. 
    It also recieves messages from the GNs and pushes them into the data cache.""" 
    #TODO write logic for putting messages back in DC if GN disconnects before message is sent
    #TODO write the thing that handles messages going to the NC
    
    def __init__(self):
        pass
    
    DC_push = Queue() #stores messages to be pushed to the DC
    incoming_request = Queue() #stores the unique ID of GNs currently connected
    incoming_msg = [Queue(), Queue(), Queue(), Queue(), Queue()] #stores incoming msgs #TODO will likely need to make a separate queue for each GN
    
class internal_client_push(Process):
    """ A client process that connects to the data cache and pushes outgoing messages. """
    print 'Internal client push started...'
    
    def run(self):
        comm = internal_communicator()
        while True:
            try:
                if not comm.DC_push.empty(): #if the queue is not empty, connect to DC and send msg
                    if os.path.exists('/tmp/Data_Cache_push_server'):
                        client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                        try:
                            client_sock.connect('/tmp/Data_Cache_push_server')
                            #print "client_push connected to data cache... "
                            data = comm.DC_push.get() #theoretically pushes messages from the GN into a queue
                            #print "sending: " , data
                            client_sock.sendall(data)
                            client_sock.close() #closes socket after each message is sent #TODO is there a better way to do this?
                            #print 'client_push closed'
                            #print 'Client push going to sleep.'
                            #time.sleep(100)
                            #print 'Client push awake.'
                        except:
                            print 'Internal client push nable to connect to DC... connection likely refused.'
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
    """ A client process that connects to the data cache and pulls incoming messages out. Sends a request in the format 'i,dev' and recieves the message"""
    
    def run(self):
        comm = internal_communicator()
        print 'Internal client pull started...'
        
        while True:
            while comm.incoming_request.empty(): #sleeps until a GN initiates a pull request
                time.sleep(1)
                #print 'Client pull going to sleep.'
                #time.sleep(100)
                #print 'Client pull awake.'
            try: 
                if os.path.exists('/tmp/Data_Cache_pull_server'):
                    client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                    #print "client_pull connected to data cache... "
                    try:
                        client_sock.connect('/tmp/Data_Cache_pull_server')#opens socket when there is an incoming pull request
                        dev = comm.incoming_request.get() #gets the dev ID that is initiating the pull request
                        request = 'i, ' + dev #puts the request in the correct format for the DC
                        client_sock.send(request)
                        try:
                            msg = client_sock.recv(4028) #arbitrary, can go in config file
                        except: 
                            #print 'Client pull connection lost.'
                            client_sock.close()
                            #time.sleep(10)
                            break
                        if not msg:
                            break
                        else:
                            #print 'Client pull recieved msg: ', msg
                            comm.incoming_msg[int(dev) - 1].put(msg) #puts the message in the device's incoming queue #TODO check if this will ever fail
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
    """ Server process that listens for connections from GNs. Gets messages from the guest nodes, parses header to get device ID (can also use device IP), and msg_p, 
    adds it to the message, along with indicator flag specifying that it is an outgoing message, stores it in DC_push queue... for now."""
    
    def run(self):
        comm = internal_communicator()
        HOST = '0.0.0.0'
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
                        try:
                            header = get_header(data)
                            if header['r_uniqid'] == 0: #TODO assuming the cloud ID is 0. May need to change later
                                dev, msg_p, order = header['flags'] #unpacks the tuple containing the flags #TODO these flags do not make sense anymore and probably need to change
                                if order == False: #lifo is set to False
                                    msg_p = 5 #sets msg_p to highest priority, which is the lifo queue
                                #data = (str(order) + '|') + data #TODO keeping in here just in case the highest priority doesn't suffice as a lifo queue
                                dev = header['s_uniqid']
                                try: 
                                    dev_loc = DEVICE_DICT[str(dev)] 
                                except: 
                                    print 'Error: Internal push server unknown sender ID. Message will not be put in data cache.'
                                    break
                                #adds buffer location indicators
                                data = (str(msg_p) + '|') + data
                                data = (str(dev_loc) +',') + data
                                data = 'o,' + data #indicates that it is an outgoing message
                                #print 'Push server pushing msg into DC: ', data
                                comm.DC_push.put(data)
                            elif dev == int(HOSTNAME): #msg intended for NC sent by GN
                                try:
                                    msg = unpack(msg)
                                    print 'Message recieved for NC: ', msg[1] #just prints the message to the screen if the recipient is the NC #TODO handle messages being sent to NC from GN
                                except:
                                    print 'Unpack unsuccessful.'
                            else: 
                                    print "Unknown recipient"
                        except:
                            print "Not a valid message."
                except KeyboardInterrupt, k:
                    print "Internal push server shutting down."
                    break
        server.close()
            
class pull_server(Process):
    """ Server process that listens for connections from GNs. Gets messages from the Data Cache and sends them to connected GNs. """
    
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
                        while comm.incoming_msg[data-1].empty():#TODO each GN should have a queue
                            time.sleep(1) #sleeps then tries again
                        msg = comm.incoming_msg[data-1].get() #returns incoming messages. Will return 'False' if no messages are available.
                        client_sock.sendall(msg) #sends the msg to the GN #TODO can probably to a try here with an except that puts the message back into the DC
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
    
                