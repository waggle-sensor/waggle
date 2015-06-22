#!/usr/bin/env python

import Queue
import random 
from operator import itemgetter
from daemon import Daemon
import sys, os, os.path, time, atexit, socket

""" The Data Cache stores messages in buffers that are named and ordered by device priority and message priority. It also removes messages from storage when they are sent. 
    This version is a service/process that is started by the system admin. """
    
    
#Each buffer is a matrix of queues for organization and indexing purposes.


class Data_Cache(Daemon):
    
    msg_counter = 0  #keeps track of how many messages are in the dc. It is incremented when messages are stored and decremented when messages are removed
    incoming_available_queues = set() #keeps a record of non-empty queues
    outgoing_lifo_available_queues = set() # a set prevents multiples of the same queue reference
    outgoing_fifo_available_queues = set()
    available_mem = 255999 #default
    
    #initially assumes that the highest number is the highest priority for now TODO figure out where the priority actually comes from
    priority_list = [5,4,3,2,1] #The priority list is now a list containing the number corresponding to a unique device. The highest priority no longer corresponds to the highest number, but rather the order in which the elements are in the list.
    
    #dummy variables 
    incoming_bffr = []
    outgoing_fifo_bffr = []
    outgoing_lifo_bffr = []
    
    def run(self):
        #make external buffer
        incoming_bffr = Data_Cache.make_bffr(len(Data_Cache.priority_list))
        #make internal fifo buffer 
        outgoing_fifo_bffr = Data_Cache.make_bffr(len(Data_Cache.priority_list))
        #make internal lifo buffer 
        outgoing_lifo_bffr = Data_Cache.make_bffr(len(Data_Cache.priority_list))
        
        print 'Data Cache started.'
        
        if os.path.exists('/tmp/Data_Cache_unix_socket_example'): #checking for the file
            os.remove('/tmp/Data_Cache_unix_socket_example')
        print "opening socket..."
        
        #creates a UNIX, STREAMing socket
        server_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        server_sock.bind('/tmp/Data_Cache_unix_socket_example') #binds to this file path
        #become a server socket
        server_sock.listen(5)

        while True:
        #accept connections from outside
            client_sock, address = server_sock.accept()
            print "connection accepted."
            #TODO change all of this to actually do something meaningful
            while True:
                try:
                    buffer = ''
                    data = client_sock.recv(4096) #TODO change this
                    if not data:
                        time.sleep(1)
                    else:
                        buffer += data
                        while buffer.find(')') != -1: #splits the incoming data into individual messages just in case many messages are sent at once
                            line, buffer = buffer.split(')', 1) #TODO need to change to reflect message protocol
                            Data_Cache.parse_data(list(line))
                            print "-" * 20 
                            print data
                        if "DONE" == data:
                            break
                except KeyboardInterrupt, k:
                    print "Data Cache shutting down..."
                    break
        print "-" * 20
        print "Data Cache server socket shutting down..."
        serversocket.close()
        os.remove('/tmp/Data_Cache_unix_socket_example')
        
    @staticmethod    
    def outgoing_push(data):
        """ Stores outgoing messages to the cloud. Expects to get a tuple with pull order (lifo or fifo),device ID, message priority, and the msg. """ 
        if Data_Cache.msg_counter > Data_Cache.available_mem:
            #TODO write the function that writes all current stored messages to files
            Data_Cache.msg_counter = 0 #resets the message counter after all buffers have been saved to a file
        else:
            pass
        Data_Cache.msg_counter += 1
        order, device, msg_p, msg = data
        if order == 'l': #TODO does this work?
            Data_Cache.outgoing_lifo_bffr[device - 1][msg_p - 1].put(msg)
            Data_Cache.outgoing_lifo_available_queues.add((device, msg_p))
        elif order == 'f': #TODO does this work?
            Data_Cache.outgoing_fifo_bffr[device - 1][msg_p - 1].put(msg)
            Data_Cache.outgoing_fifo_available_queues.add((device, msg_p))
                
    @staticmethod        
    def incoming_push(data):
        """ Stores messages going to guest nodes. Expects to get a tuple with device #, message priority, and the msg. """ 
        if Data_Cache.msg_counter > Data_Cache.available_mem:
            #TODO write the function that writes all current stored messages to files
            Data_Cache.msg_counter = 0 #resets the message counter after all buffers have been saved to a file
        else:
            pass
        Data_Cache.msg_counter += 1
        device, msg_p, msg = data
        Data_Cache.incoming_bffr[device - 1][msg_p - 1].put(msg)
        Data_Cache.incoming_available_queues.add((device, msg_p))

    @staticmethod
    def outgoing_pull():
        """ Retrieves and removes outgoing messages from the DC. Gets the first (highest priority) buffer from the priority list and returns the first message stored there. 
            For fairness, it removes one msg from fifo then lifo each time it is called.""" 
        #TODO implement fairness, avoid starvation
        fifo_cache_index = Data_Cache.get_priority(list(outgoing_fifo_available_queues)) #returns the index of the highest priority queue in fifo buffer
        lifo_cache_index = Data_Cache.get_priority(list(outgoing_lifo_available_queues)) #returns the index of the highest priority queue in lifo buffer
        if fifo_cache_index is not None: #Checks for an empty queue
            sender_p, msg_p = fifo_cache_index
            Data_Cache.msg_counter -= 1 #decrements the list by 1
            current_q = Data_Cache.outgoing_fifo_bffr[sender_p - 1][msg_p - 1]
            return current_q.get()
        else:
            Data_Cache.outgoing_fifo_available_queues.remove(fifo_cache_index) # removes it from the list of available queues
            return False #outgoing messages can be pulled in a loop until there are no messages left
        
        if lifo_cache_index is not None: #Checks for an empty list
            sender_p, msg_p = lifo_cache_index
            Data_Cache.msg_counter -= 1 #decrements the list by 1
            current_q = Data_Cache.outgoing_lifo_bffr[sender_p - 1][msg_p - 1]
            return current_q.get()
        else:
            Data_Cache.outgoing_lifo_available_queues.remove(lifo_cache_index) # removes it from the list of available queues
            return False #outgoing messages can be pulled in a loop until there are no messages left
        
    @staticmethod    
    def incoming_pull(device):
        """ Pulls messages from the DC to send to guest nodes. Returns False if no messages are available.""" 
        if len(incoming_available_queues) > 0: # checks to see if there are any messages available
            for i in range(4,-1,-1): # loop to search for messages starting with highest priority
                if incoming_bffr[device - 1][i].empty(): #checks for an empty queue 
                    pass
                else: 
                    return incoming_bffr[device- 1][i].get()
                    break
        else:
            return False
        
    @staticmethod           
    def sys_flush():
        """ Called by the system monitor before a reboot. Flushes all messages into a file.""" 
        pass
    
    @staticmethod
    def self_flush():
        """ Flushes all messages to a file when the max number of messages has been reached. """ 
        pass
    
    @staticmethod
    def get_status():
        """ Returns the number of messages currently stored. """
        return Data_Cache.msg_counter
    
     
    def update_device_priority(self, new_list):
        """ Updates the order of devices in the priority list/dictionary. """
        Data_Cache.priority = new_list
     
    def update_mem(self, memory):
        """ Updates the amount of memory allocated to the data cache. """
        #can put it in a config file 
        Data_Cache.available_mem = memory
        
    @staticmethod
    def make_bffr(length):
        """ Generates a buffer that is a list of lists containing queues. """
        buff = []
        for i in range(length):
            buff_in = []
            for j in range(5):
                buff_in.append(Queue.Queue())
            buff.append(buff_in)
        return buff
                
    @staticmethod
    def get_priority(a_list):
        """ Returns the highest priority queue index from list of available queues """ 
        if a_list.empty():
            return None
        else:
            highest_de_p = Data_Cache.prioritylist[(len(Data_Cache.prioritylist)-1)] #sets it to the lowest priority as default
            highest_msg_p = 0 #default
            for i in range(len(a_list)): #i has to be an int
                device_p, msg_p = a_list[i]
                if msg_p >= highest_msg_p: #if the msg_p is higher or equal to the current highest
                    if Data_Cache.prioritylist.index(device_p) < Data_Cache.prioritylist.index(highest_de_p): #and the device_p is higher
                        highest_de_p = device_p #then that element becomes the new highest_p
                        highest_msg_p = msg_p
                    else: #but, if the device_p is lower, the element should still be the new highest_p that gets checked next
                        highest_de_p = device_p #then that element becomes the new highest_p
                        highest_msg_p = msg_p
                else:
                    pass
            return (highest_de_p, highest_msg_p)           
        
    @staticmethod    
    def parse_data(data):
        #TODO This may just be for testing purposes.
        #TODO This is probably where it'll parse the header to find where the messages needs to be stored.
        print data
        destination = data.pop(1)
        if destination == 'o':
            Data_Cache.outgoing_push((data[2], data[3], data[4], data[5])) 
        else: 
            pass #TODO finish this
                
                
if __name__ == "__main__":
    dc = Data_Cache('/tmp/waggle.d/Data_Cache-example.pid')
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
                
                
                
                
                
                
                
                
                
                
                
            
        