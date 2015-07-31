from multiprocessing import Process, Queue
from msg_handler import msg_handler
import time, socket, sys

"""
    This module contains the communication processes for the node.
    
"""

#gets the IP address for the nodecontroller
with open('/etc/waggle/NCIP','r') as file_:
    NCIP = file_.read().strip() 
    
with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()
    
outgoing_msgs = Queue()

#TODO These two processes could be combined into one if node controller internal server processes are combined. Need to be able to distinguish between a push and a pull request.

class receive(Process):
    """ 
        This is a client socket that connects to the pull_server of the node controller to retrieve messages. 
        
    """
    
    def run(self):
        HOST = NCIP #Should connect to NodeController
        PORT = 9091 #port for pull_server
        
        
        while True: #loop that keeps connecting to node controller
            try:
                try: 
                    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    s.connect((HOST,PORT))
                    print 'Receive process connected...'
                    request = HOSTNAME #device unique ID
                    s.send(request)
                    time.sleep(1) #waits for pull request to go through #TODO might be unneccessary 
                    print 'Request sent: ', request
                    msg = s.recv(4028) #arbitrary. Can put in a config file
                    if msg != 'False':
                        try:
                            print 'Msg: ',msg
                            #sends incoming messages to msg_handler class 
                            msg_handler(msg)
                            s.close() #closes each time a message is received. #TODO might not need to close the socket each time
                            #print 'Connection closed...'
                        except:
                            print 'Unpack unsuccessful.'
                    else:
                        s.close() #closes each time a message is received.
                        time.sleep(1)
                        
                except Exception as e: 
                    print e
                    print 'Unable to connect to ', NCIP
                    s.close()
                    time.sleep(5)
            except Exception as e:
                print e
                print 'Connection disrupted...'
                print 'Socket shutting down.'
                s.close()
                break
        s.close()
        
class send_client(Process):
    
    """ 
    
        This is a client socket that connects to the push_server of the node controller to send messages. 
        
    """
    #stores outgoing messages. Keeps the messages from being lost if the guestnode is unable to connect to the nodecontroller
    outgoing_msgs = Queue()
    def run(self):
        HOST = NCIP #sets to NodeController IP
        PORT = 9090 #port for push_server
        
        
        while True:
            #sleep until there are messages to be sent
            try:
                while outgoing_msgs.empty():
                    time.sleep(1)
                s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                try: 
                    s.connect((HOST,PORT))
                    print 'Send client connected...'
                    #Only pulls message from queue if the connection is successful
                    msg = outgoing_msgs.get() 
                    print 'send client msg: ',msg
                    s.send(msg)
                    print 'Message sent: ', msg
                    s.close() #closes each time a message is sent.
                    #print 'Connection closed...'
                except Exception as e: 
                    #Sleep and then try again
                    print e
                    time.sleep(1)
                    #print 'Unable to connect...'
            except Exception as e:
                print e
                print 'Connection disrupted...'
                s.close()
                break
            
    def send(msg):
        """
            This function puts a msg in the outgoing queue. The messages are sent only when the nodecontroller is connected.
            
            :param string msg: The packed waggle message that needs to be sent.
        """
        print 'Putting message in queue...'
        #putting messages into a queue instead of sending them directly decreases the likelyhood of lost messages.
        outgoing_msgs.put(msg)


if __name__ == "__main__":
    
    try:
        sending = send_client()
        msg_receive = receive()
        sending.start()
        time.sleep(5)
        msg_receive.start()
    
    #try:
        #if len(sys.argv) == 2:
            #if 'start' == sys.argv[1]:
                ##start send_client process
                #sending.start()
                #time.sleep(5)
                
                ##start receiving messages
                #msg_receive.start()
                
            #elif 'stop' == sys.argv[1]:
                #msg_receive.join()
                #msg_receive.terminate()
                #sending.join()
                #sending.terminate()
                #print 'stopping...'
                
            #elif 'restart' == sys.argv[1]:
                #print 'restarting...'
                #msg_receive.join()
                #msg_receive.terminate()
                #sending.join()
                #sending.terminate()
                
                ##start receiving messages
                #msg_receive = receive()
                #msg_receive.start()
                
                ##start send_client process
                #sending = send_client()
                #sending.start()
                
            #elif 'foreground' == sys.argv[1]:
                #sending.run()
                #msg_receive.run()
            
            #else:
                #print "Unknown command"
                #sys.exit(2)
            #sys.exit(0)
        #else:
            #print "usage: %s start|stop|restart" % sys.argv[0]
            #sys.exit(2)    
    except KeyboardInterrupt, k: 
        msg_receive.join()
        msg_receive.terminate()
        sending.join()
        sending.terminate()
        print 'stopping...'

