#!/usr/bin/env python

import socket, os, os.path, sys
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
from msg_handler import msg_handler

""" 
    This is a client socket that connects to the pull_server of the node controller to retrieve messages. 
"""

with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()

def receive():
    HOST = '10.10.10.10' #TODO will need to change to localhost
    PORT = 9091 #port for pull_server
    
    
    while True: #loop that keeps connecting to node controller
        try:
            try: 
                s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                s.connect((HOST,PORT))
                print 'Connected...'
                request = HOSTNAME #device unique ID
                s.send(request)
                time.sleep(1) #waits for pull request to go through #TODO might be unneccessary 
                #print 'Request sent: ', request
                msg = s.recv(4028) #arbitrary. Can put in a config file
                if msg != 'False':
                    try:
                        
                        msg_handler(msg)
                        s.close() #closes each time a message is received. #TODO might not need to close the socket each time
                        #print 'Connection closed...'
                    except:
                        print 'Unpack unsuccessful.'
                else:
                    s.close() #closes each time a message is received.
                    time.sleep(1)
                    
            except: 
                print 'Unable to connect...'
                s.close()
                time.sleep(5)
        except KeyboardInterrupt, k: 
            print 'Connection disrupted...'
            print 'Socket shutting down.'
            s.close()
            break
    s.close()
    

    
if __name__ == "__main__":
        receive()
    
        