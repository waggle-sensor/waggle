#!/usr/bin/env python

import socket, os, os.path, time

""" 
    Handshake.py makes an initial connection to the NC push server. 
    The NC sends the queuename for registration with the cloud and saves it to a file.
"""



#HOST = '10.10.10.108' #node controller Odroid IP
HOST = 'NodeController' #Should connect to NodeController
PORT = 9090 #port for push_server

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    try: 
        s.connect((HOST,PORT))
        print 'Connected...'
        s.send('Hello') #TODO in the future, this will be the hostname or something else
        time.sleep(2)
        print 'Message sent.'
        
        #get queuename
        queuename = s.recv(4028)
        print 'queuename is: ', queuename
        s.close() 
        print 'Connection closed...'
        
        #write the queuename to a file
        file_ = open('/etc/waggle/queuename', 'w') 
        file_.write(queuename)
        file_.close()
        
    except: 
        print 'Unable to connect...'
except KeyboardInterrupt, k: 
    print 'Connection disrupted...'
    s.close()