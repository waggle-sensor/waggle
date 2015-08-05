from multiprocessing import Process, Queue
import time, socket, sys

"""
    This module contains the communication processes for the node.
    
"""

#gets the IP address for the nodecontroller
with open('/etc/waggle/NCIP','r') as file_:
    NCIP = file_.read().strip() 
    
with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()
    
def send(msg):
    
    """ 
    
        This is a client socket that connects to the push_server of the node controller to send messages. 
        
        :param string msg: The packed waggle message that needs to be sent.
        
    """

#TODO May want to add guestnode message robustness. If node controller is currently unavailable, all guest node messages are lost.
    HOST = NCIP #sets to NodeController IP
    PORT = 9090 #port for push_server

    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try: 
            s.connect((HOST,PORT))
            s.send(msg)
            #print 'Message sent: ', msg
            s.close() #closes each time a message is sent.
        #print 'Connection closed...'
        except Exception as e: 
            print e
            time.sleep(1)
            #print 'Unable to connect...'
    except Exception as e:
        print e
        print 'Connection disrupted...'
        s.close()


from msg_handler import msg_handler

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
                    #print 'Receive process connected...'
                    request = HOSTNAME #device unique ID
                    s.send(request)
                    time.sleep(1) #waits for pull request to go through #TODO might be unneccessary 
                    #print 'Request sent: ', request
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
        

if __name__ == "__main__":
    
    try:
        if len(sys.argv) == 2:
            if 'start' == sys.argv[1]:
                #start receiving messages
                msg_receive = receive()
                msg_receive.start()
                print 'Ready to receive messages.'
                
            elif 'stop' == sys.argv[1]:
                msg_receive.join()
                msg_receive.terminate()
                print 'stopping...'
                
            elif 'restart' == sys.argv[1]:
                print 'restarting...'
                msg_receive.join()
                msg_receive.terminate()
                
                #start receiving messages
                msg_receive = receive()
                msg_receive.start()
                
            elif 'foreground' == sys.argv[1]:
                msg_receive.run()
            
            else:
                print "Unknown command"
                sys.exit(2)
            sys.exit(0)
        else:
            print "usage: %s start|stop|restart" % sys.argv[0]
            sys.exit(2)    
    except KeyboardInterrupt, k: 
        msg_receive.join()
        msg_receive.terminate()
        print 'stopping...'

