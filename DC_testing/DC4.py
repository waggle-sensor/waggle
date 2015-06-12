from collections import deque
#internal (node) DC
import random 
from operator import itemgetter

""" Internal data cache as a service. It stores messages in buffers that are named and ordered by device priority and message priority. It also removes messages from storage when they are sent. """
    
    
#This version uses queue objects instead of lists. The queues are stored in a list of lists for organization and indexing purposes.
#This version pulls one message at a time from a queue when get_msg() is called. 



class Data_Cache(object):
    #variables that are shared by all instances of internal_DC
    msg_counter = 0  #keeps track of how many messages are in the dc. It is incremented when messages are stored and decremented when messages are removed
    msg_list = [] #keeps a record of messages
    
    #The deques
    d_5_5 = deque()
    d_5_4 = deque()
    d_5_3 = deque()
    d_5_2 = deque()
    d_5_1 = deque()
    
    d_4_5 = deque()
    d_4_4 = deque()
    d_4_3 = deque()
    d_4_2 = deque()
    d_4_1 = deque()
    
    d_3_5 = deque()
    d_3_4 = deque()
    d_3_3 = deque()
    d_3_2 = deque()
    d_3_1 = deque()
    
    d_2_5 = deque()
    d_2_4 = deque()
    d_2_3 = deque()
    d_2_2 = deque()
    d_2_1 = deque()
    
    d_1_5 = deque()
    d_1_4 = deque()
    d_1_3 = deque()
    d_1_2 = deque()
    d_1_1 = deque()
    
    #data_cache is a matrix of queue objects (5x5 nested lists) organized by data_cache[sender_priority][message_priority]
    data_cache = [[d_5_5,d_5_4,d_5_3,d_5_2,d_5_1], #sender priority = 5
                    [d_4_5,d_4_4,d_4_3,d_4_2,d_4_1], # sender priority = 4 etc...
                    [d_3_5,d_3_4,d_3_3,d_3_2,d_3_1],
                    [d_2_5,d_2_4,d_2_3,d_2_2,d_2_1],
                    [d_1_5,d_1_4,d_1_3,d_1_2,d_1_1]] 
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
            Data_Cache.data_cache[sender_p - 1][msg_p - 1].appendleft(msg)
            Data_Cache.msg_list.append((sender_p, msg_p))
    
    @staticmethod
    def priority_list():
        """ Keeps track of buffers with messages in them. Sorts the list with highest priority first. """ 
        priority_list = sorted(Data_Cache.msg_list, key=itemgetter(0,1), reverse=True)
        if len(priority_list) > 0:
            return priority_list.pop(0) # returns and removes the first tuple in the list, which should be the index of the highest priority buffer. 
        else:
            pass
    
    def get_msg(self):
        """ Retrieves and removes messages from the data_cache. Gets the first (highest priority) buffer from the priority list and returns the first message stored there. """ 
        #TODO implement fairness, avoid starvation 
        cache_index = Data_Cache.priority_list() #returns the index of the highest priority buffer
        if cache_index is not None: #Checks for an empty list
            sender_p, msg_p = cache_index
            Data_Cache.msg_counter -= 1 #decrements the list by 1
            Data_Cache.msg_list.remove((sender_p,msg_p)) #removes this buffer from the list of occupied buffers
            current_d = Data_Cache.data_cache[sender_p - 1][msg_p - 1] 
            return current_q.pop()
        else:
            return False
    