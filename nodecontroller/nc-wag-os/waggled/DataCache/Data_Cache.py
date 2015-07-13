#!/usr/bin/env python

from multiprocessing import Process, Queue, Manager
from daemon import Daemon
import sys, os, os.path, time, atexit, socket, datetime
sys.path.append('../Communications/')
from device_dict import DEVICE_DICT

""" The Data Cache stores messages in buffers that are named and ordered by device priority and message priority. """
    
#TODO clean up
#TODO Figure out what to do once DC has messages stored in files

class Data_Cache(Daemon):
    #The priority list is now a list containing the number corresponding to a unique device. The highest priority no longer corresponds to the highest number, but rather the order in which the elements are in the list
    priority_list = [5,4,3,2,1] 
    available_mem = 255999 #default
    #dummy variables 
    incoming_bffr = []
    outgoing_fifo_bffr = []
    outgoing_lifo_bffr = []
    
    
    def run(self):
        
        #creates a manager for shared information between server processes
        mgr = Manager()
        outgoing_available_queues = mgr.list()
        incoming_available_queues = mgr.list()
        msg_counter = mgr.Value('i',0)  #keeps track of how many messages are in the dc. It is incremented when messages are stored and decremented when messages are removed
        flush = mgr.Value('i',0) #indicator value. Default is 0, indicating that the data cache is running as normal. It will be changed to 1 if the data cache is flushing stored messages into files.

        
        #Each buffer is a matrix of queues for organization and indexing purposes.
        #make incoming buffer
        Data_Cache.incoming_bffr = make_bffr(len(Data_Cache.priority_list))
        #make outgoing fifo buffer 
        Data_Cache.outgoing_fifo_bffr = make_bffr(len(Data_Cache.priority_list))
        #make outgoing lifo buffer 
        #Data_Cache.outgoing_lifo_bffr = make_bffr(len(Data_Cache.priority_list))
        
        while True:
            while flush.value ==1: #shuts down the server until the all queues have been written to a file
                time.sleep(1)
            if os.path.exists('/tmp/Data_Cache_server'): #checking for the file
                os.remove('/tmp/Data_Cache_server')
            print "Opening pull socket..."
            
            #creates a UNIX, STREAMing socket
            server_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
            server_sock.bind('/tmp/Data_Cache_server') #binds to this file path
            #become a server socket
            server_sock.listen(5)
    
            while True:
            #accept connections from outside
                if flush.value==1: #shuts down the server until the all queues have been written to a file
                    print 'Pull Server flush!'
                    server_sock.close()
                    os.remove('/tmp/Data_Cache_server')
                    break
                client_sock, address = server_sock.accept()
                #TODO Is there a better way to do this?
                try:
                    data = client_sock.recv(2048) #arbitrary
                    print 'server received: ', data
                    if not data:
                        break
                    else:
                    #TODO write logic in case the NC breaks before msg is sent. Currently, messages are stored in a queue so the node will get the message once it reconnects.
                        if data.find('|') != -1: #Indicates that it is a pull request 
                            dest, data = data.split('|', 1) #splits to get either 'o' for outgoing request or the device location for incoming request
                            if dest != 'o':
                                msg = incoming_pull(int(dest), incoming_available_queues, msg_counter) #pulls a message from that device's queue
                                if msg == None:
                                    msg = 'False'
                                try:
                                    client_sock.sendall(msg) #sends the message
                                except:
                                    #pushes it back into the incoming queue, if the client disconnects before the message is sent
                                    incoming_push(int(dest),5, msg, incoming_available_queues, msg_counter, flush, outgoing_available_queues) #TODO default msg_p is 5 for messages pushed back into queue. Improvement recommended.
                            else:
                                msg = outgoing_pull(outgoing_available_queues, msg_counter)
                                if msg == None:
                                    msg = 'False'
                                try:
                                    client_sock.sendall(msg) #sends the message
                                except:
                                    #pushes it back into the outgoing queue, if the client disconnects before the message is sent
                                    outgoing_push(int(dest),5,msg, outgoing_available_queues, msg_counter, flush, incoming_available_queues)#TODO default msg_p is 5 for messages pushed back into queue. Improvement recommended.
                        
                            time.sleep(1)
                            
                        else:
                            try:
                                header = get_header(data)
                                flags = header['flags'] #extracts priorities
                                order = flags[2]
                                msg_p = flags[1]
                                recipient = header['r_uniqid'] #gets the recipient ID
                                sender = header['s_uniqid']
                                if recipient == 0: #0 is the default ID for the cloud. Indicates an outgoing push.
                                    try: 
                                        dev_loc = DEVICE_DICT[str(sender)] #looks up the location of the sender device
                                        if order==False: #indicates lifo. lifo has highest message priority
                                            msg_p=5
                                        outgoing_push(dev_loc, msg_p, data, outgoing_available_queues, msg_counter, flush, incoming_available_queues)
                                    except: 
                                        print 'Unknown sender ID. Message will not be stored in data cache.'
                                else: #indicates an incoming push
                                    try:
                                        dev_loc = DEVICE_DICT[str(sender)] #looks up the location of the sender device
                                        incoming_push(dev_loc,msg_p,data, incoming_available_queues, msg_counter, flush, outgoing_available_queues)
                                    except: 
                                        print 'Unknown recipient ID. Message will not be stored in data cache.'
                            except:
                                print 'Message corrupt. Will not store in data cache.'
                            time.sleep(1)

                        
                except KeyboardInterrupt, k:
                    print "Data Cache pull server shutting down..."
                    server_sock.close()
                    os.remove('/tmp/Data_Cache_server')
            #server_sock.close()
            #os.remove('/tmp/Data_Cache_pull_server')
        server_sock.close()
        os.remove('/tmp/Data_Cache_server')
        
       
        #print 'Data Cache started.'
        
        #try:
            #pull = Process(target=pull_server, args =(incoming_available_queues, outgoing_available_queues,  msg_counter, flush))
            #pull.start()
        
            #push = Process(target=push_server, args =(incoming_available_queues, outgoing_available_queues,  msg_counter,flush))
            #push.start()
            #while True:
                #pass
            
        #except KeyboardInterrupt, k:
            ##DC_flush(flush, incoming_available_queues, outgoing_available_queues, msg_counter) #flushes all messages to a file before shutting down.
            #pull.terminate()
            #push.terminate()
            #print 'Data Cache shutting down...'
           
   
def outgoing_push(dev, msg_p, msg, outgoing_available_queues, msg_counter, flush, incoming_available_queues): 
    """ Stores outgoing messages to the cloud. Expects to get device ID, message priority, and the msg, the lists outgoing and incoming available queues, and the flush indicator. """ 
    
    if msg_counter.value >= Data_Cache.available_mem:
        DC_flush(flush, incoming_available_queues, outgoing_available_queues, msg_counter) #Flushes all messages into a file
        msg_counter.value = 0 #resets the message counter after all buffers have been saved to a file
    
    msg_counter.value += 1 
    try:
        Data_Cache.outgoing_fifo_bffr[(dev - 1)][(msg_p - 1)].put(msg)
        try:
            outgoing_available_queues.index((dev, msg_p)) #throws an error if this is not already in the list
        except: 
            outgoing_available_queues.append((dev, msg_p)) #prevents duplicates
    except:
        print 'Outgoing push unable to store in data cache...'#TODO Should an error message be sent back to the recipient?
       
def incoming_push(device, msg_p, msg, incoming_available_queues, msg_counter, flush, outgoing_available_queues):
    """ Stores messages going to guest nodes. Needs, device priority, message priority, msg, and the shared incoming list""" 
    
    if msg_counter.value >= Data_Cache.available_mem: 
        DC_flush(flush, incoming_available_queues, outgoing_available_queues, msg_counter)
        msg_counter.value = 0 #resets the message counter after all buffers have been saved to a file
    else:
        pass 
    msg_counter.value += 1
    Data_Cache.incoming_bffr[device - 1][msg_p - 1].put(msg)
    try:
        incoming_available_queues.index(device) #checks if the device is already in the list #TODO improve this
    except:
        incoming_available_queues.append(device) #adds it to the list if it is not already there

def outgoing_pull(outgoing_available_queues, msg_counter):
    """ Retrieves and removes outgoing messages from the DC. Gets the first (highest priority) buffer from the priority list and returns the first message stored there. """ 
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
            cache_index = get_priority(outgoing_available_queues) #returns the index of the highest priority queue in fifo buffer
            sender_p, msg_p = cache_index
            current_q = Data_Cache.outgoing_fifo_bffr[sender_p - 1][msg_p - 1]
            if current_q.empty():
                outgoing_available_queues.remove(cache_index) # removes it from the list of available queues 
            else: 
                msg_counter.value -= 1 #decrements the list by 1
                queue_check = False
                return current_q.get()       
        
def incoming_pull(dev, incoming_available_queues, msg_counter):
    """ Pulls messages from the DC to send to guest nodes. Returns False if no messages are available.""" 
    try: 
        incoming_available_queues.index(dev) #checks to see if there are messages for the device #TODO Probably need a better way to do this
        for i in range(4,-1,-1): # loop to search for messages starting with highest priority
            if Data_Cache.incoming_bffr[dev - 1][i].empty(): #checks for an empty queue 
                pass
            else: 
                msg_counter.value -= 1 
                return Data_Cache.incoming_bffr[dev - 1][i].get()
    except:
        return 'False'


def DC_flush(flush, incoming_available_queues, outgoing_available_queues, msg_counter):
    """ Flushes all stored messages to files. Temporarily shuts down the push and pull server while the queues are being written to files.""" 
    flush.value = 1
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
    flush.value = 0 #restart servers 

def get_status():
    """ Returns the number of messages currently stored. """
    
    return Data_Cache.msg_counter.value #TODO This will not work
    

def update_device_priority(new_list):
    """ Updates the order of devices in the priority list/dictionary. """
    
    Data_Cache.priority = new_list 
     
def update_mem(memory):
    """ Updates the amount of memory allocated to the data cache. """
    
    #can put it in a config file 
    Data_Cache.available_mem = memory 
        

def make_bffr(length):
    """ Generates a buffer that is a list of lists containing queues. """
    buff = []
    for i in range(length):
        buff_in = []
        for j in range(5): #Assuming that messages can only have priority 1-5
            buff_in.append(Queue())
        buff.append(buff_in)
    return buff
                

def get_priority(a_list):
    """ Returns the highest priority queue index from list of available queues """ 
    
    if len(a_list) == 0:
        return 'False'
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
                
#def push_server(incoming_available_queues, outgoing_available_queues, msg_counter, flush):
    #""" The Data Cache server that handles push requests. """
    
    #while True:
        #while flush.value ==1: #shuts down the server until the all queues have been written to a file
            #time.sleep(1)
        #if os.path.exists('/tmp/Data_Cache_push_server'): #checking for the file
            #os.remove('/tmp/Data_Cache_push_server')
        #print "Opening push socket..."
        
        ##creates a UNIX, STREAMing socket
        #server_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        #server_sock.bind('/tmp/Data_Cache_push_server') #binds to this file path
        ##become a server socket
        #server_sock.listen(5)

        ##TODO Is there a better way to do this?
        #while True:
            #if flush.value==1: #shuts down the server until the all queues have been written to a file
                #print 'Push Server flush!'
                #break
            #client_sock, address = server_sock.accept()
            #try:
                #data = client_sock.recv(4028) #arbitrary 
                #print 'Push server received: ', data
                #if not data:
                    #break #breaks the loop so the server can accept other connections #TODO or does it?
                #else:
                    #data, msg = data.split('|', 1) #TODO probably a better way to do this
                    #dest, data = data.split(',',1) #incoming or outgoing
                    #dev_loc, msg_p = data.split(',',1) # device queue location and msg_p
                    #if dest == 'o': #outgoing push 
                        #outgoing_push(int(dev_loc),int(msg_p), msg, outgoing_available_queues, msg_counter, flush, incoming_available_queues)
                    #else: 
                        #incoming_push(int(dev_loc),int(msg_p),msg, incoming_available_queues, msg_counter, flush, outgoing_available_queues)
                    ##print 'Push server going to sleep.'
                    ##time.sleep(100)
                    ##print 'Push server awake.'
            #except KeyboardInterrupt, k:
                #print "Data Cache push server shutting down..."
                #server_sock.close()
                #os.remove('/tmp/Data_Cache_push_server')
                #break
        #server_sock.close()
        #os.remove('/tmp/Data_Cache_push_server')
        
    #print "Data Cache push server socket shutting down..."
    #server_sock.close()
    #os.remove('/tmp/Data_Cache_push_server')
    

#def pull_server(incoming_available_queues, outgoing_available_queues, msg_counter, flush):
    #""" The Data Cache server that handles pull requests. An incoming pull request will be a string in the format 'i,deviceP'. An outgoing pull request will be a string in the format 'o '. """
    #while True:
        #while flush.value ==1: #shuts down the server until the all queues have been written to a file
            #time.sleep(1)
        #if os.path.exists('/tmp/Data_Cache_pull_server'): #checking for the file
            #os.remove('/tmp/Data_Cache_pull_server')
        #print "Opening pull socket..."
        
        ##creates a UNIX, STREAMing socket
        #server_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        #server_sock.bind('/tmp/Data_Cache_pull_server') #binds to this file path
        ##become a server socket
        #server_sock.listen(5)
   
        #while True:
        ##accept connections from outside
            #if flush.value==1: #shuts down the server until the all queues have been written to a file
                #print 'Pull Server flush!'
                #break
            #client_sock, address = server_sock.accept()
            ##TODO Is there a better way to do this?
            #try:
                #data = client_sock.recv(40) #TODO 40 bites is the expected size of pull requests
                ##print 'pull_server received: ', data
                #if not data:
                    #break
                #else:
                ##TODO write logic in case the NC breaks before msg is sent. Currently, messages are stored in a queue so the node will get the message once it reconnects.
                    #if data.find(',') != -1: #splits the incoming data into individual messages just in case many messages are sent at once
                        #dest, dev = data.split(',', 1) #splits into destination (incoming or outgoing) and device ID if applicable
                        #msg = incoming_pull(int(dev), incoming_available_queues, msg_counter) #pulls a message from that device's queue
                        #if msg == None:
                            #msg = 'False'
                        #try:
                            #client_sock.sendall(msg) #sends the message
                        #except:
                            ##pushes it back into the incoming queue, if the client disconnects before the message is sent
                            #incoming_push(int(dev),5, msg, incoming_available_queues, msg_counter, flush, outgoing_available_queues) #TODO default msg_p is 5 for messages pushed back into queue. Improvement recommended.
                    #else:
                        #msg = outgoing_pull(outgoing_available_queues, msg_counter)
                        #if msg == None:
                            #msg = 'False'
                        #try:
                            #client_sock.sendall(msg) #sends the message
                        #except:
                            ##pushes it back into the outgoing queue, if the client disconnects before the message is sent
                            #outgoing_push(int(dev),5,msg, outgoing_available_queues, msg_counter, flush, incoming_available_queues)#TODO default msg_p is 5 for messages pushed back into queue. Improvement recommended.
                     
                    #time.sleep(1)
                    ##print 'Pull server going to sleep.'
                    ##time.sleep(100)
                    ##print 'Pull server awake.'
                    
                    
            #except KeyboardInterrupt, k:
                #print "Data Cache pull server shutting down..."
                #server_sock.close()
                #os.remove('/tmp/Data_Cache_pull_server')
        #server_sock.close()
        #os.remove('/tmp/Data_Cache_pull_server')
    #server_sock.close()
    #os.remove('/tmp/Data_Cache_pull_server')
    
#uncomment for testing    
        
if __name__ == "__main__":
    dc = Data_Cache('/tmp/waggle.d/Data_Cache.pid')
    if len(sys.argv) == 2:
        if 'start' == sys.argv[1]:
            dc.start()
            print 'starting.'
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
                
                
                
                
                
                
                
                
                
                
                
            
        