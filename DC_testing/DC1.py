#internal (node) DC
import random 
from operator import itemgetter
from multiprocessing import Process

""" Internal data cache as a service. It stores messages in buffers that are named and ordered by device priority and message priority. It also removes messages from storage when messages are sent. 
    This version uses a list of lists. Each list is a buffer cooresponding to a specific sender priority, message priority combination."""




class internal_DC(object):
    #variables that are shared by all instances of internal_DC
    msg_counter = 0  #keeps track of how many messages are in the dc. It is incremented when messages are stored and decremented when messages are removed
    msg_list = set()
    #data_cache is a matrix of lists (5x5 nested lists) organized by data_cache[sender_priority][message_priority]
    data_cache = [[[],[],[],[],[]], #sender priority = 5
                    [[],[],[],[],[]], # sender priority = 4 etc...
                    [[],[],[],[],[]],
                    [[],[],[],[],[]],
                    [[],[],[],[],[]]] 
    def __init__(self):
        pass
    
    def store_msg(self, data):
        """ Stores messages. Expects to get a tuple with sender priority, message priority, and the msg. """ 
        if internal_DC.msg_counter > 255999:
            #TODO write the function that writes all current stored messages to files
            pass
        else:
            internal_DC.msg_counter += 1
            sender_p, msg_p, msg = data
            internal_DC.data_cache[sender_p - 1][msg_p - 1].append(msg)
            internal_DC.msg_list.add((sender_p, msg_p))
    
    @staticmethod
    def priority_list():
        """ Keeps track of buffers with messages in them. Sorts the list with highest priority first. """ 
        priority_list = sorted(list(internal_DC.msg_list), key=itemgetter(0,1), reverse=True)
        if len(priority_list) > 0:
            return priority_list.pop(0) # returns and removes the first tuple in the list, which should be the index of the highest priority buffer. 
        else:
            pass
    
    def get_msg(self):
        """ Retrieves and removes messages from the data_cache. Gets the first (highest priority) buffer from the priority list. """ 
        #TODO implement fairness, avoid starvation
        cache_index = internal_DC.priority_list() #returns the index of the highest priority buffer
        if cache_index is not None:
            sender_p, msg_p = cache_index
            internal_DC.msg_counter -= len(internal_DC.data_cache[sender_p - 1][msg_p - 1]) #decrements the list by the number of messages stored in the buffer
            internal_DC.msg_list.remove((sender_p,msg_p)) #removes this buffer from the list of occupied buffers
            bffr_copy = internal_DC.data_cache[sender_p - 1][msg_p - 1] # copy of the list of messages at this index
            internal_DC.data_cache[sender_p - 1][msg_p - 1] = [] #removes all of the messages from this buffer
            return bffr_copy #returns the list of messages that were stored in the buffer
        else:
            return False
    
def __main__():
    print("main")
    dc = internal_DC()
    for j in range(100000):
        data = ''
        for i in range(1100):
            data = data + chr(random.randint(0,255))
        dc1.store_msg((random.randint(0,5),random.randint(0,5),data))
        print j 
        
if __name__ == '__main__':
    __main__()