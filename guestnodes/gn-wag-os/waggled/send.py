import time, socket, sys

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

#TODO May want to add guestnode message robustness. Currently, if node controller is currently unavailable, all guest node messages are lost. Can add a loop or
#TODO Can add robustness by making this a daemon process that plugins can connect to using unix sockets. Send process puts messages in a queue to add robustness. 
#TODO Send process can pull messages and send to NC if connected or hold on to the messages until NC connects. 

    HOST = NCIP #sets to NodeController IP
    PORT = 9090 #port for push_server

    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try: 
            s.connect((HOST,PORT))
            s.send(msg)
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
