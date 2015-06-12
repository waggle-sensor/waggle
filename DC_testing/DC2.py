import Queue
#internal (node) DC
import random 
from operator import itemgetter

""" Internal data cache as a service. It stores messages in buffers that are named and ordered by device priority and message priority. It also removes messages from storage when they are sent. """
    
    
#This version uses queue objects instead of lists. The queues are stored in a list of lists for organization and indexing purposes.
#This version empties the entire queue when get_msg() is called. 



class Data_Cache(object):
    #variables that are shared by all instances of internal_DC
    msg_counter = 0  #keeps track of how many messages are in the dc. It is incremented when messages are stored and decremented when messages are removed
    msg_list = set() #keeps a record of which queues contain messages
    
    #The queues
    q_5_5 = Queue.Queue()
    q_5_4 = Queue.Queue()
    q_5_3 = Queue.Queue()
    q_5_2 = Queue.Queue()
    q_5_1 = Queue.Queue()
    
    q_4_5 = Queue.Queue()
    q_4_4 = Queue.Queue()
    q_4_3 = Queue.Queue()
    q_4_2 = Queue.Queue()
    q_4_1 = Queue.Queue()
    
    q_3_5 = Queue.Queue()
    q_3_4 = Queue.Queue()
    q_3_3 = Queue.Queue()
    q_3_2 = Queue.Queue()
    q_3_1 = Queue.Queue()
    
    q_2_5 = Queue.Queue()
    q_2_4 = Queue.Queue()
    q_2_3 = Queue.Queue()
    q_2_2 = Queue.Queue()
    q_2_1 = Queue.Queue()
    
    q_1_5 = Queue.Queue()
    q_1_4 = Queue.Queue()
    q_1_3 = Queue.Queue()
    q_1_2 = Queue.Queue()
    q_1_1 = Queue.Queue()
    
    #data_cache is a matrix of queue objects (5x5 nested lists) organized by data_cache[sender_priority][message_priority]
    data_cache = [[q_5_5,q_5_4,q_5_3,q_5_2,q_5_1], #sender priority = 5
                    [q_4_5,q_4_4,q_4_3,q_4_2,q_4_1], # sender priority = 4 etc...
                    [q_3_5,q_3_4,q_3_3,q_3_2,q_3_1],
                    [q_2_5,q_2_4,q_2_3,q_2_2,q_2_1],
                    [q_1_5,q_1_4,q_1_3,q_1_2,q_1_1]] 
    def __init__(self):
        pass
    
    def store_msg(self, data):
        """ Stores messages. Expects to get a tuple with sender priority, message priority, and the msg. """ 
        if Data_Cache.msg_counter > 255999:
            #TODO write the function that writes all current stored messages to files
            pass
        else:
            Data_Cache.msg_counter += 1
            sender_p, msg_p, msg = data
            Data_Cache.data_cache[sender_p - 1][msg_p - 1].put(msg)
            Data_Cache.msg_list.add((sender_p, msg_p))
    
    @staticmethod
    def priority_list():
        """ Keeps track of buffers with messages in them. Sorts the list with highest priority first. """ 
        priority_list = sorted(list(Data_Cache.msg_list), key=itemgetter(0,1), reverse=True)
        if len(priority_list) > 0:
            return priority_list.pop(0) # returns and removes the first tuple in the list, which should be the index of the highest priority buffer. 
        else:
            pass
    
    def get_msg(self):
        """ Retrieves and removes messages from the data_cache. Gets the first (highest priority) buffer from the priority list. """ 
        #TODO implement fairness, avoid starvation
        cache_index = Data_Cache.priority_list() #returns the index of the highest priority buffer
        if cache_index is not None: #Checks for an empty list
            sender_p, msg_p = cache_index
            Data_Cache.msg_counter -= Data_Cache.data_cache[sender_p - 1][msg_p - 1].qsize() #decrements the list by the number of messages stored in the buffer
            Data_Cache.msg_list.remove((sender_p,msg_p)) #removes this buffer from the list of occupied buffers
            current_q = Data_Cache.data_cache[sender_p - 1][msg_p - 1] 
            messages = []
            while current_q.qsize() > 0:
                messages.append(current_q.get())
            return messages #returns the list of messages that were stored in the buffer
        else:
            return False
    