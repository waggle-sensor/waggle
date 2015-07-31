#!/usr/bin/env python

import socket, os, os.path, time

""" 
    This is a client socket that connects to the push_server of the node controller to send messages. It is called as a function with the packed message as an argument. 
    
    :param string msg: The packed waggle message that needs to be sent.
"""
#gets the IP address for the nodecontroller
with open('/etc/waggle/NCIP','r') as file_:
    IP = file_.read().strip() 

def send(msg):
    HOST = NCIP #should set it to NodeController IP
    PORT = 9090 #port for push_server
    
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        try: 
            s.connect((HOST,PORT))
            #print 'Connected...'
            s.send(msg)
            time.sleep(1) 
            #print 'Message sent: ', msg
            
            s.close() #closes each time a message is sent.
            #print 'Connection closed...'
        except: 
            print 'Unable to connect...'
    except KeyboardInterrupt, k: 
        print 'Connection disrupted...'
        s.close()