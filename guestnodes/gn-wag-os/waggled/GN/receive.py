#!/usr/bin/env python

import socket, os, os.path

""" This is a client socket that connects to the pull_server of the node controller to retrieve messages. """

def receive():
    HOST = '10.10.10.10'
    PORT = 9091 #port for pull_server
    
    s = socket.socket(socket.AF_NET, socket.SOCK_STREAM)
    while True: #loop that keeps connecting to node controller
        try:
            try: 
                s.connect((HOST,PORT))
                print 'Connected...'
                msg = '1' #TODO change to device unique ID
                s.send(msg)
                print 'Message sent: ', msg
                msg = s.recv(4028) #arbitrary. Can put in a config file
                #TODO do something with the message. 
                print msg 
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