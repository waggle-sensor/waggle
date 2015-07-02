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
                msg = HOSTNAME #device unique ID
                s.send(msg)
                print 'Message sent: ', msg
                msg = s.recv(4028) #arbitrary. Can put in a config file
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
        except KeyboardInterrupt, k: 
            print 'Connection disrupted...'
            break
    s.close()
    
if __name__ == "__main__":
    receive()