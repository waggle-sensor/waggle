#!/usr/bin/env python

from multiprocessing import Process, Queue, Manager
from daemon import Daemon
import sys, os, os.path, time, atexit, socket, datetime
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
sys.path.append('../Communications/')
from device_dict import DEVICE_DICT

""" 
    The Data Cache stores messages between the nodes and the cloud. The main function is a unix socket server. The internal and external facing communication classes connect to
    the data cache to push or pull messages. The data cache consists of two buffers, which are matrixes of queues. Each queue cooresponds to a device location and message priority within the matrix. 
    The data cache stores messages in the queues until the available memory runs out. When the number of messages exceeds the available memory, the messages queues are cleared and the messages are written to a file. 
"""
    
#TODO clean up
#TODO Figure out what to do once DC has messages stored in files


class Data_Cache(Daemon):
    #The priority list is now a list containing the number corresponding to a unique device. The highest priority no longer corresponds to the highest number, but rather the order in which the elements are in the list
    priority_list = [5,4,3,2,1] 
    available_mem = 255999 #default
   
   #dummy variables 
    incoming_bffr = []
    outgoing_bffr = []
    
    
    def run(self):
        
        #lists keeping track of which queues currently have messages stored in them
        outgoing_available_queues = list() 
        incoming_available_queues = list() 
        msg_counter = 0  #keeps track of how many messages are in the dc. It is incremented when messages are stored and decremented when messages are removed
        flush = 0 #indicator value. Default is 0, indicating that the data cache is running as normal. It will be changed to 1 if the data cache is flushing stored messages into files.

        
        #Each buffer is a matrix of queues for organization and indexing purposes.
        #make incoming buffer
        Data_Cache.incoming_bffr = make_bffr(len(Data_Cache.priority_list))
        #make outgoing buffer 
        Data_Cache.outgoing_bffr = make_bffr(len(Data_Cache.priority_list))
        
        #the main server loop
        while True:
            
            #indicates that the server is flushing the buffers. Shuts down the server until the all queues have been written to a file
            while flush ==1: 
                time.sleep(1)
            if os.path.exists('/tmp/Data_Cache_server'): #checking for the file
                os.remove('/tmp/Data_Cache_server')
            print "Opening server socket..."
            
            #creates a UNIX, STREAMing socket
            server_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
            server_sock.bind('/tmp/Data_Cache_server') #binds to this file path
            
            #become a server socket
            server_sock.listen(5)
    
            while True:
            
                if flush==1: #shuts down the server until the all queues have been written to a file
                    print 'Server flush!'
                    server_sock.close()
                    os.remove('/tmp/Data_Cache_server')
                    break
                
                #accept connections from outside
                client_sock, address = server_sock.accept()
                #TODO Is there a better way to do this?
                try:
                    data = client_sock.recv(2048) #arbitrary
                    #print 'Server received: ', data
                    if not data:
                        break
                    else:
                        if data.find('|') != -1: #Indicates that it is a pull request 
                            #print 'if data.find'
                            dest, data = data.split('|', 1) #splits to get either 'o' for outgoing request or the device location for incoming request
                            if dest != 'o':
                                msg = incoming_pull(int(dest), incoming_available_queues, msg_counter) #pulls a message from that device's queue
                                if msg == None:
                                    msg = 'False'
                                try:
                                    client_sock.sendall(msg) #sends the message
                                except:
                                    #pushes it back into the incoming queue, if the client disconnects before the message is sent
                                    #TODO default msg_p is 5 for messages pushed back into queue. Improvement recommended.
                                    incoming_push(int(dest),5, msg, incoming_available_queues, msg_counter, flush, outgoing_available_queues) 
                            else:
                                msg = outgoing_pull(outgoing_available_queues, msg_counter) #pulls the highest priority message
                                if msg == None:
                                    msg = 'False'
                                try:
                                    client_sock.sendall(msg) #sends the message
                                except:
                                    #pushes it back into the outgoing queue, if the client disconnects before the message is sent
                                    #TODO default msg_p is 5 for messages pushed back into queue. Improvement recommended.
                                    outgoing_push(int(dest),5,msg, outgoing_available_queues, msg_counter, flush, incoming_available_queues)
                        
                            time.sleep(1)
                            
                        else:
                            try:
                                header = get_header(data) #uses the packet handler function get_header to unpack the header data from the message
                                flags = header['flags'] #extracts priorities
                                order = flags[2] #lifo or fifo
                                msg_p = flags[1] 
                                recipient = header['r_uniqid'] #gets the recipient ID
                                sender = header['s_uniqid']
                                if recipient == 0: #0 is the default ID for the cloud. Indicates an outgoing push.
                                    try: 
                                        dev_loc = DEVICE_DICT[str(sender)] #looks up the location of the sender device
                                        if order==False: #indicates lifo. lifo has highest message priority
                                            msg_p=5
                                        #pushes the message into the outgoing buffer to the queue corresponding to the device location and message priority
                                        outgoing_push(dev_loc, msg_p, data, outgoing_available_queues, msg_counter, flush, incoming_available_queues)
                                    except: 
                                        print 'Unknown sender ID. Message will not be stored in data cache.'
                                else: #indicates an incoming push
                                    try:
                                        dev_loc = DEVICE_DICT[str(recipient)] #looks up the location of the recipient device
                                        incoming_push(dev_loc,msg_p,data, incoming_available_queues, msg_counter, flush, outgoing_available_queues)
                                    except: 
                                        print 'Unknown recipient ID. Message will not be stored in data cache.'
                            except:
                                print 'Message corrupt. Will not store in data cache.'
                            time.sleep(1)

                        
                except KeyboardInterrupt, k:
                    print "Data Cache pull server shutting down..."
                    break
            server_sock.close()
            os.remove('/tmp/Data_Cache_pull_server')
        server_sock.close()
        os.remove('/tmp/Data_Cache_server')
        
   
def outgoing_push(dev, msg_p, msg, outgoing_available_queues, msg_counter, flush, incoming_available_queues): 
    """
        Function that pushes outgoing messages into the outgoing buffer.
        
        :param int dev: Specifies the device location in the matrix.
        :param int msg_p: Specifies the message priority location in the matrix
        :param list outgoing_available_queues: A list of tuples that specify the location of outgoing queues that currently have stored messages
        :param int msg_counter: Keeps track of the number of total messags currently being stored in the buffers.
        :param int flush: Value indicating if the data cache needs to flush the buffers into files.
        :param list incoming_available_queues: A list of tuples that specify the location of incoming queues that currently have stored messages
    """ 
    
    #if the msg counter is greater than or equal to the available memory, flush the buffers into files
    if msg_counter>= Data_Cache.available_mem:
        #Calls the data cache flush method and passes in the neccessary params
        DC_flush(flush, incoming_available_queues, outgoing_available_queues, msg_counter) #Flushes all messages into a file
        msg_counter = 0 #resets the message counter after all buffers have been saved to a file
    
    #increments the msg_counter by 1 each time a message is pushed into the data cache
    msg_counter += 1 
    try:
        #pushes the message into the queue at the specified location in the matrix
        Data_Cache.outgoing_bffr[(dev - 1)][(msg_p - 1)].put(msg)
        
        #adds the queue to the list of available queues
        try:
            outgoing_available_queues.index((dev, msg_p)) #throws an error if this is not already in the list
        except: 
            outgoing_available_queues.append((dev, msg_p)) #prevents duplicates
    except:
        print 'Outgoing push unable to store in data cache...'#TODO Should an error message be sent back to the recipient?
       
def incoming_push(device, msg_p, msg, incoming_available_queues, msg_counter, flush, outgoing_available_queues):
    """ 
        Function that pushes incoming messages to the incoming buffer.
        
        :param int dev: Specifies the device location in the matrix.
        :param int msg_p: Specifies the message priority location in the matrix
        :param list outgoing_available_queues: A list of tuples that specify the location of outgoing queues that currently have stored messages
        :param int msg_counter: Keeps track of total messages in the data cache.
        :param int flush: Value indicating if the data cache needs to flush the buffers into files.
        :param list incoming_available_queues: A list of tuples that specify the location of incoming queues that currently have stored messages
    """ 
    
    #if the msg counter is greater than or equal to the available memory, flush the buffers into files
    if msg_counter >= Data_Cache.available_mem: 
        #Calls the data cache flush method
        DC_flush(flush, incoming_available_queues, outgoing_available_queues, msg_counter)
        msg_counter = 0 #resets the message counter after all buffers have been saved to a file
    else:
        pass 
    #increments the counter by 1 each time a message is put into the buffer
    msg_counter += 1
    
    #pushes the message into the queue at the specified location in the matrix
    Data_Cache.incoming_bffr[device - 1][msg_p - 1].put(msg)
    
    #adds the queue to the list of available queues
    try:
        incoming_available_queues.index(device) #checks if the device is already in the list #TODO improve this
    except:
        incoming_available_queues.append(device) #adds it to the list if it is not already there

def outgoing_pull(outgoing_available_queues, msg_counter):
    """ 
        Function that retrieves and removes outgoing messages from the outgoing buffer. Retrieves the highest priority messages first. Highest priority messages are determined based on message priority and device priority.
        
        :param list outgoing_available_queues: The list of outgoing queues that currently have messages stored in them.
        :param int msg_counter: Keeps track of total messages in the data cache.
        :rtype string: Returns a packed message or 'False' if no messages are available. 
    """ 
    
    #TODO implement fairness, avoid starvation
    #TODO this probably needs to be reworked 
    #TODO might want to find a better way to remove empty queues from list 
    
    queue_check = True #continues until a message is sent. Neccessary to check for empty queues whose index has not yet been removed from the list
    while queue_check:
        if len(outgoing_available_queues) == 0: #no messages available
            #print ' No messages available.'
            queue_check = False
            return 'False' 
        else:
            #Calls the function that returns the highest priority tuple in the list
            cache_index = get_priority(outgoing_available_queues) #returns the index of the highest priority queue in fifo buffer
            sender_p, msg_p = cache_index
            current_q = Data_Cache.outgoing_bffr[sender_p - 1][msg_p - 1]
            
            #checks if the queue is empty
            if current_q.empty():
                #removes it from the list of available queues 
                outgoing_available_queues.remove(cache_index) 
            else: 
                msg_counter -= 1 #decrements the list by 1
                queue_check = False
                return current_q.get()       
        
def incoming_pull(dev, incoming_available_queues, msg_counter):
    """ 
        Function that retrieves and removes incoming messages from the incoming buffer. Searches through all of the message priority queues for the specified device to return the highest priority message first. 
        
        :param int dev: Specifies the device location in the matrix.
        :param list incoming_available_queues: The list of incoming queues that currently have messages stored in them.
        :param int msg_counter: Keeps track of total messages in the data cache.
    """ 
    try: 
        #checks to see if there are messages for the device
        incoming_available_queues.index(dev) #TODO Probably need a better way to do this
        for i in range(4,-1,-1): # loop to search for messages starting with highest priority
            if Data_Cache.incoming_bffr[dev - 1][i].empty(): #checks for an empty queue 
                pass
            else: 
                #decrements the counter by 1 each time a message is removed
                msg_counter -= 1 
                return Data_Cache.incoming_bffr[dev - 1][i].get()
    except:
        #returns false if no messages are available
        return 'False'


def DC_flush(flush, incoming_available_queues, outgoing_available_queues, msg_counter):
    """ 
        Function that flushes all stored messages from the buffers to files. Temporarily shuts down the push and pull server while the queues are being written to files.
        
        :param int flush: Shared indicator that the data cache is being flushed. 
        :param list incoming_available_queues: The list of incoming queues that currently have messages stored in them.
        :param list outgoing_available_queues: The list of outgoing queues that currently have messages stored in them.
        :param int msg_counter: Keeps track of total messages in the data cache.
    """ 
    flush = 1
    print 'Flushing!' #for testing
    print 'Msg_counter: ' , msg_counter
    print 'Available mem: ', Data_Cache.available_mem
    
    date = datetime.datetime.now().strftime('%Y %m %d %H:%M:%S')
    filename = 'outgoing' + date #file name has buffer being flushed and date
    f = open(filename, 'w')
    while True: #write all outgoing messages to outgoing file
        msg = outgoing_pull(outgoing_available_queues, msg_counter) #returns false when all queues are empty
        if msg=='False':
            break
        else:
            f.write(msg + '/n') 
    f.close()
    filename = 'incoming' + date
    f = open(filename, 'w')
    for i in Data_Cache.priority_list: #write all incoming messages to file
        while True:
            msg = incoming_pull(i, incoming_available_queues, msg_counter)
            if msg=='False':
                break
            else:
                f.write(msg + '/n')
    f.close()
    flush= 0 #restart servers 

def get_status():
    """
    
        Function that returns the number of messages currently stored in the data cache. 
    
    """
    
    return Data_Cache.msg_counter.value #TODO This will not work
    

def update_device_priority(updated_priority):
    """ 
    
        Updates the order of devices in the priority list.
    
        :param list updated_priority: A list containing the new priority order of the devices.
    """
    
    Data_Cache.priority = updated_priority
     
def update_mem(memory):
    """ 
        Updates the amount of memory allocated to the data cache. 
        
        :param int memory: The amount of memory to be allocated to the data cache.
    """
    
    #can put it in a config file 
    Data_Cache.available_mem = memory 
        

def make_bffr(length):
    """ 
        Generates a buffer, which is a matrix containing queues. 
    
        :param int length: Specifies the number of rows in the matrix
        :rtype list buff: The matrix containing queues
    """
    buff = []
    #device priority
    for i in range(length):
        buff_in = []
        for j in range(5): #Assuming that messages can only have priority 1-5
            buff_in.append(Queue())
        buff.append(buff_in)
    return buff
                

def get_priority(outgoing_available_queues):
    """ 
        Function that finds the highest priority queue in the list. Highest priority is determined by comparing message priority and device priority.
        
        :param list outgoing_available_queues: The list of outgoing queues that currently have messages stored in them.
        :rtype: tuple(device_priority, message_priority) or string 'False'
    """ 
    #returns False if there are no messages available
    if len(outgoing_available_queues) == 0:
        return 'False'
    else:
        highest_de_p = Data_Cache.priority_list[(len(Data_Cache.priority_list)-1)] #sets it to the lowest priority as default
        highest_msg_p = 0 #default
        for i in range(len(outgoing_available_queues)): #i has to be an int
            device_p, msg_p = outgoing_available_queues[i]
            if msg_p >= highest_msg_p: #if the msg_p is higher or equal to the current highest
                if Data_Cache.priority_list.index(device_p) < Data_Cache.priority_list.index(highest_de_p): #and the device_p is higher
                    highest_de_p = device_p #then that element becomes the new highest_p
                    highest_msg_p = msg_p
                else: #but, if the device_p is lower, the element should still be the new highest_p that gets checked next
                    highest_de_p = device_p #then that element becomes the new highest_p
                    highest_msg_p = msg_p
            else:
                pass
        return (highest_de_p, highest_msg_p)           
                
#uncomment for testing    
        
if __name__ == "__main__":
    dc = Data_Cache('/tmp/waggle.d/Data_Cache.pid')
    if len(sys.argv) == 2:
        if 'start' == sys.argv[1]:
            print 'starting.'
            dc.start()
            #dc.run()
            
        elif 'stop' == sys.argv[1]:
            dc.stop()
            print 'stopping'
        elif 'restart' == sys.argv[1]:
            dc.restart()
            print 'restart'
        elif 'foreground' == sys.argv[1]: #called for debugging purposes. 
            dc.run()
        else:
            print "Unknown command"
            sys.exit(2)
        sys.exit(0)
    else:
        print "usage: %s start|stop|restart" % sys.argv[0]
        sys.exit(2)                
                
                
                
                
                
                
                
                
                
                
                
            
        