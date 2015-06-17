import Queue
#internal (node) DC
import random 
from operator import itemgetter
from multiprocessing import Process

""" Internal data cache as a service. It stores messages in buffers that are named and ordered by device priority and message priority. It also removes messages from storage when they are sent. 
    This version is initialized by the system admin. """
    
    
#This version uses queue objects instead of lists. The queues are stored in a list of lists for organization and indexing purposes.




class Data_Cache(object):
    
    def __init__(self): 
        pass
    
    
    msg_counter = 0  #keeps track of how many messages are in the dc. It is incremented when messages are stored and decremented when messages are removed
    incoming_available_queues = set() #keeps a record of non-empty queues
    outgoing_lifo_available_queues = set() # a set prevents multiples of the same queue reference
    outgoing_fifo_available_queues = set()
    available_mem = 255999
    
    #initially assumes that the highest number is the highest priority for now TODO figure out where the priority actually comes from
    priority_list = [5,4,3,2,1] #The priority list is now a list containing the number corresponding to a unique device. The highest priority no longer corresponds to the highest number, but rather the order in which the elements are in the list.
    #make external buffer
    incoming_bffr = Data_Cache.make_bffr(len(priority))
    #make internal fifo buffer 
    outgoing_fifo_bffr = Data_Cache.make_bffr(len(priority))
    
    #make internal lifo buffer 
    outgoing_lifo_bffr = Data_Cache.make_bffr(len(priority))
        
    #should only be initilized by sys admin like this:
    #dc = Process(target=Data_Cache, args=(self))
    #dc.start()
    
        
    def outgoing_push(self, data):
        """ Stores outgoing messages to the cloud. Expects to get a tuple with pull order (lifo or fifo),device ID, message priority, and the msg. """ 
        if Data_Cache.msg_counter > Data_Cache.available_mem:
            #TODO write the function that writes all current stored messages to files
            Data_Cache.msg_counter = 0 #resets the message counter after all buffers have been saved to a file
        else:
            pass
        Data_Cache.msg_counter += 1
        order, device, msg_p, msg = data
        if order == 'lifo': #TODO does this work?
            Data_Cache.outgoing_lifo_bffr[device - 1][msg_p - 1].put(msg)
            Data_Cache.outgoing_lifo_available_queues.add((device, msg_p))
        elif order == 'fifo': #TODO does this work?
            Data_Cache.outgoing_fifo_bffr[device - 1][msg_p - 1].put(msg)
            Data_Cache.outgoing_fifo_available_queues.add((device, msg_p))
                
            
    def incoming_push(self, data):
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

    def outgoing_pull(self):
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
        
        
    def sys_flush():
        """ Called by the system monitor before a reboot. Flushes all messages into a file.""" 
        pass
    
    @staticmethod
    def self_flush():
        """ Flushes all messages to a file when the max number of messages has been reached. """ 
        pass
    
    @staticmethod
    def get_status():
        """ Returns the number of messages currently stored to the system admin. """
        return Data_Cache.msg_counter
    
    @staticmethod  
    def update_device_priority(new_list):
        """ Updates the order of devices in the priority list/dictionary."""
        Data_Cache.priority = new_list
        pass
    
    @staticmethod  
    def update_mem(memory):
        """ Updates the amount of memory allocated to the data cache. """
        #can put it in a config file 
        Data_Cache.available_mem = memory
        
    @staticmethod
    def make_bffr(self, length):
        """ Generates a buffer that is a list of lists containing queues. """
        buff = []
        for i in range(length):
            buff_in = []
            for j in range(5):
                buff_in.append(Queue.Queue())
            buff.append(buff_in)
        return buff
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            
        