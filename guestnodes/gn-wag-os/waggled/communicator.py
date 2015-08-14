from multiprocessing import Process, Queue
import time, socket, sys
from msg_handler import msg_handler

"""
    This module contains the communication processes for the node. It receives messages from the NC and passes them to msg_handler.py.
    This process runs in the background after guest node configuration.
    
"""

#gets the IP address for the nodecontroller
with open('/etc/waggle/NCIP','r') as file_:
    NCIP = file_.read().strip() 
    
with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()
    

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
                            #sends incoming messages to msg_handler class 
                            msg_handler(msg)
                            s.close() #closes each time a message is received. 
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
        
        #start receiving messages
        msg_receive = receive()
        msg_receive.start()
               
    except KeyboardInterrupt, k: 
        msg_receive.terminate()
        print 'stopping...'

