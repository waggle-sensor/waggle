#!/usr/bin/env python

from multiprocessing import Queue
from daemon import Daemon
import sys, os, os.path, time, atexit, socket, datetime
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
sys.path.append('../NC/')
from NC_configuration import *
sys.path.append('../NC/')
from msg_handler import msg_handler
from glob import glob

""" 
    The Data Cache stores messages between the nodes and the cloud. The main function is a unix socket server. The internal and external facing communication classes connect to
    the data cache to push or pull messages. The data cache consists of two buffers, which are matrixes of queues. Each queue cooresponds to a device location and message priority within the matrix. 
    The data cache stores messages in the queues until the available memory runs out. When the number of messages exceeds the available memory, the messages queues are cleared and the messages are written to a file. 
"""
    
#TODO clean up
#TODO make improvements. Suggestions for improvements are written as TODOs


class Data_Cache(Daemon):
   
   #dummy variables. These buffers are created when the data cache starts.
    incoming_bffr = []
    outgoing_bffr = []
    
    flush = 0 #value that indicates if the DC is flushing or not
    msg_counter = 0 #keeps track of total messages in queues
    #If the data cache flushed messages to files, this stores the the current outgoing file that messages are being read from
    outgoing_cur_file = '' #empty string if there are no files
    #If the data cache flushed messages to files, this stores a list of current files for each device 
    incoming_cur_file =  ['', '', '', '', ''] #empty string if there are no files
    
    
    def run(self):
        #lists keeping track of which queues currently have messages stored in them
        outgoing_available_queues = list() 
        incoming_available_queues = list() 

        
        #Each buffer is a matrix of queues for organization and indexing purposes.
        #make incoming buffer
        Data_Cache.incoming_bffr = make_bffr(len(PRIORITY_ORDER))
        #make outgoing buffer 
        Data_Cache.outgoing_bffr = make_bffr(len(PRIORITY_ORDER))
        
        #the main server loop
        while True:
            
            #indicates that the server is flushing the buffers. Shuts down the server until the all queues have been written to a file
            while Data_Cache.flush ==1: 
                #print 'Data_cache.flush while loop'
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
            
                if Data_Cache.flush==1: #shuts down the server until the all queues have been written to a file
                    print 'Server flush!'
                    server_sock.close()
                    os.remove('/tmp/Data_Cache_server')
                    print 'Server flush closed socket'
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
                        #'Flush' means that there is an external flush request.
                        if data == 'Flush':
                            #flush all stored messages into files
                            DC_flush(incoming_available_queues, outgoing_available_queues)
                        #Indicates that it is a pull request 
                        elif data[0] == '|': #TODO This could be improved if there is a better way to distinguish between push and pull requests and from incoming and outgoing requests
                            data, dest = data.split('|', 1) #splits to get either 'o' for outgoing request or the device location for incoming request
                            if dest != 'o':
                                msg = incoming_pull(int(dest), incoming_available_queues) #pulls a message from that device's queue
                                if msg == 'None':
                                    msg = 'False'
                                try:
                                    client_sock.sendall(msg) #sends the message
                                except:
                                    #pushes it back into the incoming queue, if the client disconnects before the message is sent
                                    try: #Will pass if data is a pull request instead of a full message 
                                        #TODO default msg_p is 5 for messages pushed back into queue. Improvement recommended.
                                        incoming_push(int(dest),5, msg, incoming_available_queues, outgoing_available_queues) 
                                    except: 
                                        pass
                            else:
                                msg = outgoing_pull(outgoing_available_queues) #pulls the highest priority message
                                if msg == None:
                                    msg = 'False'
                                try:
                                    client_sock.sendall(msg) #sends the message
                                except Exception as e:
                                    print e
                                    #pushes it back into the outgoing queue, if the client disconnects before the message is sent
                                    try:#Will pass if data is a pull request instead of a full message
                                        #TODO default msg_p is 5 for messages pushed back into queue. Improvement recommended.
                                        outgoing_push(int(dest),5,msg, outgoing_available_queues, incoming_available_queues)
                                    except Exception as e: 
                                        print e
                        
                            time.sleep(1)
                            
                        else:
                            try:
                                header = get_header(data) #uses the packet handler function get_header to unpack the header data from the message
                                flags = header['flags'] #extracts priorities
                                order = flags[2] #lifo or fifo
                                msg_p = flags[1] 
                                recipient = header['r_uniqid'] #gets the recipient ID
                                #print 'recipient: ',recipient
                                sender = header['s_uniqid']
                                for i in range(2): #loops in case device dictionary is not up-to-date
                                    if recipient == 0: #0 is the default ID for the cloud. Indicates an outgoing push.
                                        try: 
                                            dev_loc = DEVICE_DICT[str(sender)] #looks up the location of the sender device
                                            #print 'dev_loc: ' , dev_loc
                                            if order==False: #indicates lifo. lifo has highest message priority
                                                msg_p=5
                                            #pushes the message into the outgoing buffer to the queue corresponding to the device location and message priority
                                            outgoing_push(int(dev_loc), msg_p, data, outgoing_available_queues, incoming_available_queues)
                                            #If the device is registered and the push is successful, no need to try again, break the loop
                                            break 
                                        except Exception as e: 
                                            #The device dictionary may not be up to date. Need to update and try again.
                                            #If the device is still not found after first try, move on.
                                            DEVICE_DICT = update_dev_dict()
                                            
                                    #indicates an incoming push
                                    elif str(recipient) == HOSTNAME:
                                        msg_handler(data)
                                        break
                                    else:
                                        try:
                                            dev_loc = DEVICE_DICT[str(recipient)] #looks up the location of the recipient device
                                            #If the device is registered and the push is successful, no need to try again, break the loop
                                            incoming_push(int(dev_loc),msg_p,data, incoming_available_queues, outgoing_available_queues)
                                            break
                                        except Exception as e: 
                                            #The device dictionary may not be up to date. Need to update and try again.
                                            #If the device is still not found after first try, move on.
                                            DEVICE_DICT = update_dev_dict()
                            except:
                                print 'Message corrupt. Will not store in data cache.'
                            time.sleep(1)

                        
                except KeyboardInterrupt, k:
                    print "Data Cache server shutting down..."
                    break
            #server_sock.close()
            #os.remove('/tmp/Data_Cache_server')
            #break
        if os.path.exists('/tmp/Data_Cache_server'): #checking for the file for a smooth shutdown
            server_sock.close()
            os.remove('/tmp/Data_Cache_server')
            
    def stop(self):
        try:
            external_flush()
            #The data cache needs time to flush the messages before stopping the process
            time.sleep(5)
            Daemon.stop(self)
        except Exception as e:
            print e

def external_flush():
    """
        This function is called to force a flush of the data cache from an external source (i.e. before a system reboot). 
        It connects to the server socket of the data cache to request a flush. 
    """
     #connect to DC and send 'Flush'
    if os.path.exists('/tmp/Data_Cache_server'):
        client_sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        try:
            client_sock.connect('/tmp/Data_Cache_server')
            client_sock.sendall('Flush')
            client_sock.close()
        except Exception as e:
            print e
            client_sock.close()
    else: 
        print 'Data cache running?'
            

def outgoing_push(dev, msg_p, msg, outgoing_available_queues, incoming_available_queues): 
    """
        Function that pushes outgoing messages into the outgoing buffer.
        
        :param int dev: Specifies the device location in the matrix.
        :param int msg_p: Specifies the message priority location in the matrix
        :param list outgoing_available_queues: A list of tuples that specify the location of outgoing queues that currently have stored messages
        :param int msg_counter: Keeps track of the number of total messags currently being stored in the buffers.
        :param int flush: Value indicating if the data cache needs to flush the buffers into files.
        :param list incoming_available_queues: A list of tuples that specify the location of incoming queues that currently have stored messages
    """ 
    #print 'msg counter: ',Data_Cache.msg_counter
    #print 'available mem: ', AVAILABLE_MEM
    #if the msg counter is greater than or equal to the available memory, flush the outgoing queues into a file
    if Data_Cache.msg_counter>= AVAILABLE_MEM:
        
        #Calls the data cache flush method and passes in the neccessary params
        DC_flush(incoming_available_queues, outgoing_available_queues) #Flushes all messages into a file
        Data_Cache.msg_counter = 0 #resets the message counter after all buffers have been saved to a file
    
    #increments the msg_counter by 1 each time a message is pushed into the data cache
    Data_Cache.msg_counter += 1 
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
       
def incoming_push(device, msg_p, msg, incoming_available_queues, outgoing_available_queues):
    """ 
        Function that pushes incoming messages to the incoming buffer.
        
        :param int dev: Specifies the device location in the matrix.
        :param int msg_p: Specifies the message priority location in the matrix
        :param list outgoing_available_queues: A list of tuples that specify the location of outgoing queues that currently have stored messages
        :param int msg_counter: Keeps track of total messages in the data cache.
        :param int flush: Value indicating if the data cache needs to flush the buffers into files.
        :param list incoming_available_queues: A list of tuples that specify the location of incoming queues that currently have stored messages
    """ 
    #print 'msg counter: ',Data_Cache.msg_counter
    #print 'available mem: ', AVAILABLE_MEM
    #if the msg counter is greater than or equal to the available memory, flush the buffers into files
    if Data_Cache.msg_counter >= AVAILABLE_MEM: 
        #Calls the data cache flush method
        DC_flush(incoming_available_queues, outgoing_available_queues)
        Data_Cache.msg_counter = 0 #resets the message counter after all buffers have been saved to a file
    else:
        pass 
    #increments the counter by 1 each time a message is put into the buffer
    Data_Cache.msg_counter += 1
    
    #pushes the message into the queue at the specified location in the matrix
    Data_Cache.incoming_bffr[device - 1][msg_p - 1].put(msg)
    
    #adds the queue to the list of available queues
    try:
        incoming_available_queues.index(device) #checks if the device is already in the list #TODO improve this
    except:
        incoming_available_queues.append(device) #adds it to the list if it is not already there

def outgoing_pull(outgoing_available_queues):
    """ 
        Function that retrieves and removes outgoing messages from the outgoing buffer. Retrieves the highest priority messages first. Highest priority messages are determined based on message priority and device priority.
        
        :param list outgoing_available_queues: The list of outgoing queues that currently have messages stored in them.
        :param int msg_counter: Keeps track of total messages in the data cache.
        :rtype string: Returns a packed message or 'False' if no messages are available. 
    """ 
    
    #TODO implement fairness, avoid starvation
    #TODO this probably needs to be reworked 
    #TODO might want to find a better way to remove empty queues from list 
    
    
    #continues until a message is sent. 
    #Neccessary to check for empty queues whose index has not yet been removed from the list or files whose messages have all been read and sent
    while True:
    
        #are there outgoing messages stored as files?
        #if so, those need to be sent to the cloud first without needing to load all messages from the file and taking up too much RAM
        #so, send the messages one by one using a file generator object.
        #when all messages have been read from file and sent to cloud, close and delete that file from the directory.
        if len(glob('/var/dc/outgoing_msgs/*')) > 0 and Data_Cache.flush == 0: #prevents the flush from pulling messages from files
            #print 'Len(glob) outgoing_stored/* is greater than 0'
            #is there a file generator object already stored as the current file?
            if Data_Cache.outgoing_cur_file == '':
                #print 'cur_file is empty string.'
                #set the first file in the outgoing_stored directory as the current file generator object
                Data_Cache.outgoing_cur_file = open(glob('/var/dc/outgoing_msgs/*')[0]) 
                #print 'opened file'
                try: 
                    #print 'trying to read from file'
                    msg = Data_Cache.outgoing_cur_file.next().strip() #reads the next message in file, strips the \n
                    #print 'returning msg'
                    return msg
                    break
                except:
                    Data_Cache.outgoing_cur_file.close() #close the file if stop iterator error occurs
                    if os.path.isfile(Data_Cache.outgoing_cur_file.name): #make sure the file exists
                        os.remove(Data_Cache.outgoing_cur_file.name)#delete the file
                    Data_Cache.outgoing_cur_file = '' #reset to empty string
            else:
                try: 
                    msg = Data_Cache.outgoing_cur_file.next().strip() #reads the next message in file, strips the \n
                    return msg
                    break
                except:
                    Data_Cache.outgoing_cur_file.close() #close the file if stop iterator error occurs
                    if os.path.isfile(Data_Cache.outgoing_cur_file.name): #make sure the file exists
                        os.remove(Data_Cache.outgoing_cur_file.name) #delete the file
                    Data_Cache.outgoing_cur_file = '' #reset to empty string
                    
        #If there are no messages stored as files, pull messages from the queues
        else:
            #Are there any messages available?
            if len(outgoing_available_queues) == 0: #no messages available
                #print ' No messages available.'
                return 'False' 
                break
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
                    Data_Cache.msg_counter -= 1 #decrements the list by 1
                    return current_q.get()    
                    break
        
def incoming_pull(dev, incoming_available_queues):
    """ 
        Function that retrieves and removes incoming messages from the incoming buffer. Searches through all of the message priority queues for the specified device to return the highest priority message first. 
        
        :param int dev: Specifies the device location in the matrix.
        :param list incoming_available_queues: The list of incoming queues that currently have messages stored in them.
        :param int msg_counter: Keeps track of total messages in the data cache.
    """ 
    
    #continues until something is returned. 
    #Neccessary to check for files whose messages have all been read and sent but have not yet been deleted
    while True:
        #are there incoming messages stored as files for the specified dev?
        #if so, those need to be sent first without needing to load all messages from the file and taking up too much RAM
        #so, send the messages one by one using a file generator object.
        #when all messages have been read from file and sent to device, close and delete that file from the directory.
        if len(glob('/var/dc/incoming_msgs/' + str(dev) + '/*')) > 0 and Data_Cache.flush == 0: #only pulls messages from file if DC is not flushing
            #print 'Len(glob) incoming_stored/' + str(dev) + '/* is greater than 0'
            #is there a file generator object already stored as the current file?
            if Data_Cache.incoming_cur_file[dev - 1] == '':
                #set the first file in the incoming_stored/dev directory as the current file generator object
                Data_Cache.incoming_cur_file[dev -1] = open(glob('/var/dc/incoming_msgs/' + str(dev) + '/*')[0]) 
                try: 
                    msg = Data_Cache.incoming_cur_file[dev -1].next().strip() #reads the next message in file, strips the \n
                    return msg
                    break
                except:
                    Data_Cache.incoming_cur_file[dev -1].close() #close the file if stop iterator error occurs
                    if os.path.isfile(Data_Cache.incoming_cur_file[dev -1].name): #make sure the file exists
                        os.remove(Data_Cache.incoming_cur_file[dev -1].name)#delete the file
                    Data_Cache.incoming_cur_file[dev -1] = '' #reset to empty string
            else:
                try: 
                    msg = Data_Cache.incoming_cur_file[dev -1].next().strip() #reads the next message in file, strips the \n
                    return msg
                    break
                except:
                    Data_Cache.incoming_cur_file[dev -1].close() #close the file if stop iterator error occurs
                    if os.path.isfile(Data_Cache.incoming_cur_file[dev -1].name): #make sure the file exists
                        os.remove(Data_Cache.incoming_cur_file[dev -1].name)#delete the file
                    Data_Cache.incoming_cur_file[dev -1] = '' #reset to empty string
        
        #if no messages are stored in files, check for messages in queues
        else:
            try: 
                #checks to see if there are messages for the device
                #results in an error if that dev isn't in the list
                incoming_available_queues.index(dev) #TODO Probably need a better way to do this
                msg = 'False' #default 
                for i in range(4,-1,-1): # loop to search for messages starting with highest priority
                    if Data_Cache.incoming_bffr[dev - 1][i].empty(): #checks for an empty queue 
                        pass #do nothing
                    else: 
                        #decrements the counter by 1 each time a message is removed
                        Data_Cache.msg_counter -= 1 
                        msg = Data_Cache.incoming_bffr[dev - 1][i].get() #sets to message and breaks the loop
                        break
                #if the message is still false (i.e. no messages are actually available for that device), remove dev from list
                if msg == 'False':
                    incoming_available_queues.remove(dev)
                return msg
                break
            except:
                #returns false if no messages are available
                return 'None'
                break
           


def DC_flush(incoming_available_queues, outgoing_available_queues):
    """ 
        Function that temporary closes the Data Cache server to write the outgoing and incoming queues into files.
        This function is called when the data cache reaches its maximum number of messages it can store in RAM or (hopefully) before the data cache is shut down.
        
        :param int flush: Shared indicator that the data cache is being flushed. 
        :param list incoming_available_queues: The list of incoming queues that currently have messages stored in them.
        :param list outgoing_available_queues: The list of outgoing queues that currently have messages stored in them.
        :param int msg_counter: Keeps track of total messages in the data cache.
    """ 
    Data_Cache.flush = 1
    print 'Flushing!' #for testing
    #print 'Msg_counter: ' , Data_Cache.msg_counter
    ##print 'Available mem: ', AVAILABLE_MEM
    
    try:
        cur_date = str(datetime.datetime.now().strftime('%Y%m%d%H:%M:%S'))
        filename = '/var/dc/outgoing_msgs/' + cur_date #file name is date of flush
        f = open(filename, 'w')
        print 'Flushing outgoing'
        while True: #write all outgoing messages to outgoing file
            #messages are written to file with highest priority at the top
            msg = outgoing_pull(outgoing_available_queues) #returns false when all queues are empty
            if msg=='False': #no more messages available. break and close file
                break
            else:
                #write the message to the file
                f.write(msg + '\n') 
        f.close()
        print 'Flushing incoming'
        for i in PRIORITY_ORDER: #write all incoming messages to file
            #each device has a separate folder. This prevents needing to loop through all messages or all files to find messages for only the connected devices.
            #TODO Change this to /etc/waggle/dc/outgoing or something
            pathname = '/var/dc/incoming_msgs/' + str(i) + '/' #set the path
            #print 'pathname: ', pathname
            if not os.path.exists(pathname): #make sure the directory exists
                os.makedirs(pathname)
            filename = pathname + cur_date #set the file name to the date and time of flush
            #print 'filename is: ', filename
            f = open(filename, 'w')
            while True:
                #for each device, messages are stored with highest priority on the top of the file
                msg = incoming_pull(i, incoming_available_queues)
                if msg=='False':  #No more messages available. break and close file.
                    f.close()
                    break
                elif msg =='None': #No messages currently available for device. Close and remove file
                    f.close()
                    if os.path.isfile(f.name):
                        os.remove(f.name)
                    break
                else:
                    #write the message to the file
                    f.write(msg + '\n')
                    
        Data_Cache.flush = 0 #restart server
        print 'Data cache restarted'
    except Exception as e:
        print e

def get_status():
    """
    
        Function that returns the number of messages currently stored in the data cache. 
    
    """
    
    return Data_Cache.msg_counter
#TODO I don't think works

def update_device_priority(updated_priority):
    """ 
    
        Updates the order of devices in the priority list.
    
        :param list updated_priority: A list containing the new priority order of the devices.
    """
    #TODO This change is not persistant. This will need to be changed manually in NC_configuration.py
    PRIORITY_ORDER = updated_priority
     
def update_mem(memory):
    """ 
        Updates the amount of memory allocated to the data cache. 
        
        :param int memory: The amount of memory to be allocated to the data cache.
    """
    
    #TODO this will be stored in the config file
    #TODO This change is not persistant. This will need to be changed manually in NC_configuration.py
    AVAILABLE_MEM = memory 
        

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
        highest_de_p = PRIORITY_ORDER[(len(PRIORITY_ORDER)-1)] #sets it to the lowest priority as default
        highest_msg_p = 0 #default
        for i in range(len(outgoing_available_queues)): #i has to be an int
            device_p, msg_p = outgoing_available_queues[i]
            if msg_p >= highest_msg_p: #if the msg_p is higher or equal to the current highest
                if PRIORITY_ORDER.index(device_p) < PRIORITY_ORDER.index(highest_de_p): #and the device_p is higher
                    highest_de_p = device_p #then that element becomes the new highest_p
                    highest_msg_p = msg_p
                else: #but, if the device_p is lower, the element should still be the new highest_p that gets checked next
                    highest_de_p = device_p #then that element becomes the new highest_p
                    highest_msg_p = msg_p
            else:
                pass
        return (highest_de_p, highest_msg_p)           

if __name__ == "__main__":
    dc = Data_Cache('/tmp/Data_Cache.pid',stdout='/var/dc/dc_out.log', stderr='/var/dc/dc_err.log') #TODO may need to change this
    if len(sys.argv) == 2:
        if 'start' == sys.argv[1]:
            print 'starting.'
            dc.start()
            
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
                
                
                
                
                
                
                
                
                
                
                
            
        