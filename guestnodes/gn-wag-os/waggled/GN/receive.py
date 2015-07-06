#!/usr/bin/env python

import socket, os, os.path, sys
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *

""" This is a client socket that connects to the pull_server of the node controller to retrieve messages. """

with open('/etc/waggle/hostname','r') as file_:
    HOSTNAME = file_.read().strip()

def receive():
    HOST = '10.10.10.10'
    PORT = 9091 #port for pull_server
    
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    while True: #loop that keeps connecting to node controller
        try:
            try: 
                s.connect((HOST,PORT))
                print 'Connected...'
                request = HOSTNAME #device unique ID
                s.send(request)
                print 'Message sent: ', request
                msg = s.recv(4028) #arbitrary. Can put in a config file
                if not msg:
                        break #breaks the loop when the client socket closes
                #TODO do something with the message. Currently, just prints msg to screen
                    try:
                    msg = unpack(msg)
                    print 'Message recieved for GN: ', msg[1] 
                except:
                    print 'Unpack unsuccessful.'
                s.close() #closes each time a message is received.
                print 'Connection closed...'
            except: 
                print 'Unable to connect...'
                time.sleep(5)
        except KeyboardInterrupt, k: 
        print 'Connection disrupted...'
        print 'Socket shutting down.'
        s.close()
        break
    s.close()
    
if __name__ == "__main__":
        receive()
    
        