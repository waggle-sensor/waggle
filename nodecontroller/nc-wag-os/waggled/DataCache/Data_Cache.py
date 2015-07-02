#!/usr/bin/env python

from multiprocessing import Process, Queue, Manager
import random 
from operator import itemgetter
from daemon import Daemon
import sys, os, os.path, time, atexit, socket

""" The Data Cache stores messages in buffers that are named and ordered by device priority and message priority. It also removes messages from storage when they are sent. 
    This version is a service/process that is started by the system admin. """
    
#TODO clean up
#TODO write the function that writes all current stored messages to files

class Data_Cache(Daemon):
    #The priority list is now a list containing the number corresponding to a unique device. The highest priority no longer corresponds to the highest number, but rather the order in which the elements are in the list
    priority_list = [5,4,3,2,1] 
    available_mem = 255999 #default
    #dummy variables 
    incoming_bffr = []
    outgoing_fifo_bffr = []
    outgoing_lifo_bffr = []
    
    
    def run(self):
        
        #create a manager for shared information between server processes
        mgr = Manager()
        outgoing_lifo_available_queues = mgr.list()
        outgoing_fifo_available_queues = mgr.list()
        incoming_available_queues = mgr.list()
        msg_counter = mgr.Value('i',0)  #keeps track of how many messages are in the dc. It is incremented when messages are stored and decremented when messages are removed

        
        #Each buffer is a matrix of queues for organization and indexing purposes.
        #make incoming buffer
        Data_Cache.incoming_bffr = make_bffr(len(Data_Cache.priority_list))
        #make outgoing fifo buffer 
        Data_Cache.outgoing_fifo_bffr = make_bffr(len(Data_Cache.priority_list))
        #make outgoing lifo buffer 
        Data_Cache.outgoing_lifo_bffr = make_bffr(len(Data_Cache.priority_list))
        
       
        print 'Data Cache started.'
        
        try:
            pull = Process(target=pull_server, args =(incoming_available_queues, outgoing_fifo_available_queues, outgoing_lifo_available_queues, msg_counter))
            pull.start()
        
            push = Process(target=push_server, args =(incoming_available_queues, outgoing_fifo_available_queues, outgoing_lifo_available_queues, msg_counter))
            push.start()
            while True:
                pass
            
        except KeyboardInterrupt, k:
            pull.terminate()
            push.terminate()
            print 'Data Cache shutting down...'
           
   
def outgoing_push(order, dev, msg_p, msg, outgoing_fifo_available_queues, outgoing_lifo_available_queues, msg_counter): 
    """ Stores outgoing messages to the cloud. Expects to get pull order (lifo or fifo),device ID, message priority, and the msg. """ 
    
    if msg_counter.value > Data_Cache.available_mem:
        
        msg_counter.value = 0 #resets the message counter after all buffers have been saved to a file
    else:
        pass #TODO need to write to file here
    msg_counter.value += 1 
    try:
        if order == 'False': 
            current_queue = Data_Cache.outgoing_lifo_bffr[dev - 1][msg_p - 1]
            current_queue.put(msg)
            try:
                outgoing_lifo_available_queues.index((dev, msg_p)) #throws an error if this is not already in the list
            except: 
                outgoing_lifo_available_queues.append((dev, msg_p)) #prevents duplicates
        elif order == 'True': 
            Data_Cache.outgoing_fifo_bffr[(dev - 1)][(msg_p - 1)].put(msg)
            try:
                outgoing_fifo_available_queues.index((dev, msg_p))#throws an error if this is not already in the list
            except: 
                outgoing_fifo_available_queues.append((dev, msg_p)) #prevents duplicates
                print 'out_going push fifo queue len: ', len(outgoing_fifo_available_queues)
        else:
            print 'Unrecognized priority flag...' #TODO This probably needs to send back an error message to the sender
    except:
        print 'Unable to store in data cache...'#TODO this is a quick fix for Raj, but this actually needs to be addressed and handled. An error will occur if the flags always use the default value. Check packetmaker
                
       
def incoming_push(device, msg_p, msg, incoming_available_queues, msg_counter):
    """ Stores messages going to guest nodes. Needs, device priority, message priority, msg, and the shared incoming list""" 
    if msg_counter > Data_Cache.available_mem: #TODO probably needs to set as an attribute or something
        #TODO write the function that writes all current stored messages to files
        msg_counter.value = 0 #resets the message counter after all buffers have been saved to a file
    else:
        pass 
    msg_counter.value += 1
    Data_Cache.incoming_bffr[device - 1][msg_p - 1].put(msg)
    try:
        incoming_available_queues.index((device, msg_p))
    except:
        incoming_available_queues.append((device, msg_p))


def outgoing_pull(outgoing_fifo_available_queues, outgoing_lifo_available_queues, msg_counter):
    """ Retrieves and removes outgoing messages from the DC. Gets the first (highest priority) buffer from the priority list and returns the first message stored there. 
        For fairness, it removes one msg from fifo then lifo each time it is called.""" 
    #TODO implement fairness, avoid starvation
    #TODO this needs to be reworked 
    #TODO might want to find a better way to remove empty queues from list 
    queue_check = True #continues until a message is sent. Neccessary to check for empty queues whose index has not yet been removed from the list
    while queue_check:
        if len(outgoing_fifo_available_queues) == 0: #no messages available
            print ' No messages available.'
            queue_check = False
            return 'False' 
        else:
            fifo_cache_index = get_priority(outgoing_fifo_available_queues) #returns the index of the highest priority queue in fifo buffer
            sender_p, msg_p = fifo_cache_index
            current_q = Data_Cache.outgoing_fifo_bffr[sender_p - 1][msg_p - 1]
            if current_q.empty():
                outgoing_fifo_available_queues.remove(fifo_cache_index) # removes it from the list of available queues 
            else: 
                msg_counter.value -= 1 #decrements the list by 1
                queue_check = False
                return current_q.get()       
        
    #if len(outgoing_lifo_available_queues) == 0: #no messages available
        #print 'outgoing PULL queue len: ', len(outgoing_lifo_available_queues)
        #print ' No messages available.'
        #return 'False'
    #else:
        #lifo_cache_index = Data_Cache.get_priority(outgoing_lifo_available_queues) #returns the index of the highest priority queue in lifo buffer
        #if lifo_cache_index is not None: #Checks for an empty list
            #sender_p, msg_p = lifo_cache_index
            #Data_Cache.msg_counter -= 1 #decrements the list by 1
            #current_q = Data_Cache.outgoing_lifo_bffr[sender_p - 1][msg_p - 1]
            #return current_q.get()
        #else:
            #outgoing_lifo_available_queues.remove(lifo_cache_index) # removes it from the list of available queues
            #return 'False' #outgoing messages can be pulled in a loop until there are no messages left
    #print 'outgoing PULL fifo queue len: ', len(outgoing_fifo_available_queues)
        #print ' No messages available.'
        #return 'False'
   
def incoming_pull(device, incoming_available_queues):
    """ Pulls messages from the DC to send to guest nodes. Returns False if no messages are available.""" 
    if len(incoming_available_queues) > 0: # checks to see if there are any messages available
        for i in range(4,-1,-1): # loop to search for messages starting with highest priority
            if Data_Cache.incoming_bffr[device - 1][i].empty(): #checks for an empty queue 
                pass
            else: 
                return Data_Cache.incoming_bffr[device- 1][i].get()
    else:
        return False
        
         
def sys_flush():
    """ TODO Called by the system monitor before a reboot. Flushes all messages into a file.""" 
    pass
    

def self_flush():
    """ TODO Flushes all messages to a file when the max number of messages has been reached. """ 
    pass
    

def get_status():
    """ Returns the number of messages currently stored. """
    
    return Data_Cache.msg_counter #TODO This will probably not work
    

def update_device_priority(new_list):
    """ Updates the order of devices in the priority list/dictionary. """
    
    Data_Cache.priority = new_list #TODO this might not work
     
def update_mem(memory):
    """ Updates the amount of memory allocated to the data cache. """
    #can put it in a config file 
    Data_Cache.available_mem = memory #TODO this probably wont work
        

def make_bffr(length):
    """ Generates a buffer that is a list of lists containing queues. """
    buff = []
    for i in range(length):
        buff_in = []
        for j in range(5):
            buff_in.append(Queue())
        buff.append(buff_in)
    return buff
                

def get_priority(a_list):
    """ Returns the highest priority queue index from list of available queues """ 
    
    if len(a_list) == 0:
        return None
    else:
        highest_de_p = Data_Cache.priority_list[(len(Data_Cache.priority_list)-1)] #sets it to the lowest priority as default
        highest_msg_p = 0 #default
        for i in range(len(a_list)): #i has to be an int
            device_p, msg_p = a_list[i]
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
                
def push_server(incoming_available_queues, outgoing_fifo_available_queues, outgoing_lifo_available_queues, msg_counter):
    """ The Data Cache server that handles push requests. """
    
    if os.path.exists('/tmp/Data_Cache_push_server'): #checking for the file
        os.remove('/tmp/Data_Cache_push_server')
    print "Opening push socket..."
    
    #creates a UNIX, STREAMing socket
    server_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    server_sock.bind('/tmp/Data_Cache_push_server') #binds to this file path
    #become a server socket
    server_sock.listen(5)

    while True:
    #accept connections from outside
        
        client_sock, address = server_sock.accept()
        print "Push server connected."
        #TODO Is there a better way to do this?
        while True:
            try:
                data = client_sock.recv(4028) #arbitrary 
                if not data:
                    break #breaks the loop so the server can accept other connections #TODO or does it?
                else:
                    data, msg = data.split('|', 1) #TODO probably a better way to do this
                    dest, data = data.split(',',1) #incoming or outgoing
                    dev, data = data.split(',',1) # device
                    msg_p, order = data.split(',',1) #message priority and order
                    if dest == 'o': #outgoing push 
                        outgoing_push(order,int(dev),int(msg_p), msg, outgoing_fifo_available_queues, outgoing_lifo_available_queues, msg_counter)
                    else: 
                        incoming_push(int(dev),int(msg_p),msg, incoming_available_queues, msg_counter)
                    print "-" * 20 
            except KeyboardInterrupt, k:
                print "Data Cache shutting down..."
                break
    print "-" * 20
    print "Data Cache push server socket shutting down..."
    serversocket.close()
    os.remove('/tmp/Data_Cache_push_server')
        

def pull_server(incoming_available_queues, outgoing_fifo_available_queues, outgoing_lifo_available_queues, msg_counter):
    """ The Data Cache server that handles pull requests. An incoming pull request will be a string in the format 'i,deviceP'. An outgoing pull request will be a string in the format 'o '. """
    if os.path.exists('/tmp/Data_Cache_pull_server'): #checking for the file
        os.remove('/tmp/Data_Cache_pull_server')
    print "Opening pull socket..."
    
    #creates a UNIX, STREAMing socket
    server_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    server_sock.bind('/tmp/Data_Cache_pull_server') #binds to this file path
    #become a server socket
    server_sock.listen(5)
    

    while True:
    #accept connections from outside
        client_sock, address = server_sock.accept()
        #TODO Is there a better way to do this?
        try:
            data = client_sock.recv(40) #TODO 40 bites is the expected size of pull requests
            if not data:
                break
            else:
               #TODO write logic in case the NC breaks before msg is sent
                if data.find(',') != -1: #splits the incoming data into individual messages just in case many messages are sent at once
                    line, dev = data.split(',', 1) #TODO need to change to reflect message protocol
                    msg = incoming_pull(dev, incoming_available_queues, msg_counter) #pulls a message from that device's queue
                    print 'Pull server sending msg.'
                else:
                    msg = outgoing_pull(outgoing_fifo_available_queues, outgoing_lifo_available_queues,msg_counter)
                    print 'Pull server sending msg.'
                
                client_sock.sendall(msg) #sends the message
                
        except KeyboardInterrupt, k:
            print "Data Cache shutting down..."
            serversocket.close()
            os.remove('/tmp/Data_Cache_pull_server')
    print "-" * 20
    print "Data Cache pull server socket shutting down..."
    server_sock.close()
    os.remove('/tmp/Data_Cache_pull_server')
    
        
if __name__ == "__main__":
    dc = Data_Cache('/tmp/waggle.d/Data_Cache.pid')
    if len(sys.argv) == 2:
        if 'start' == sys.argv[1]:
            dc.start()
            print 'starting.'
        elif 'stop' == sys.argv[1]:
            dc.stop()
            print 'stopping'
        elif 'restart' == sys.argv[1]:
            dc.restart()
            print 'restart'
        elif 'foreground' == sys.argv[1]:
            dc.run()
        else:
            print "Unknown command"
            sys.exit(2)
        sys.exit(0)
    else:
        print "usage: %s start|stop|restart" % sys.argv[0]
        sys.exit(2)                
                
                
                
                
                
                
                
                
                
                
                
            
        