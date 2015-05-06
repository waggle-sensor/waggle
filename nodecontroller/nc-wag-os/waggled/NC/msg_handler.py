# msg_handler.py

import os, os.path, sys
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send

def msg_handler(msg):
    """
    
        Unpacks and acts on messages sent to the node.
        
        :param string msg: The packed message sent to the node.
        
    """
    
    try:
        #unpacks the header
        header = get_header(msg)
    except: 
        print 'Message is corrupt.' #TODO should this send some kind of error response? 
        
    #get the major header type
    major = chr(header['msg_mj_type'])
    minor = chr(header['msg_mi_type'])
    
    #large file transfer
    if major == 'F':
        #TODO pass to packet reassembler
        pass
    
    #small file transfer
    elif major == 'f':
        #TODO do something with this file
        pass
    
    #ping
    elif major == 'p':
        #ping request. 
        if minor == 'r':
            #send a ping response
            packet = packetmaker.make_ping_packet()
            for pack in packet:
                send(pack)
         #ping answer
        else:
            #unpack the message
            ping = unpack(msg)
            #print out the body of the message
            print 'Node received: ', ping[1]
    #time
    elif major == 't':
        #time request
        if minor == 'r':
            #send time
            packet = packetmaker.make_time_packet()
            for pack in packet:
                send(pack)
        #time answer
        else:
            #unpack the message
            time = unpack(msg)
            #print out the body of the message
            print 'Node received time: ', time[1]
    #sensor data
    elif major == 's':
        #TODO do stuff here 
        pass 
    
    #registration
    elif major =='r':
        #TODO do stuff here 
        #unpack the message
        reg = unpack(msg)
        #print out the body of the message
        print 'NC received registration: ', reg[1]
    
    #message type unrecognized 
    else: 
        print 'Message major type, ' , major, ' unrecognized.'
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
    