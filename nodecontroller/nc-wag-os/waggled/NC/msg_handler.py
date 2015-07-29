# msg_handler.py

import os, os.path, sys
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send
from NC_configuration import *

def msg_handler(msg):
    """
    
        Unpacks and acts on messages sent to the node.
        
        :param string msg: The packed message sent to the node.
        
    """
    
    try:
        #unpacks the header
        header = get_header(msg)
    except: 
        print 'Message is corrupt: ', msg #TODO should this send some kind of error response? 
        
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
            for pack_ in packet:
                send(pack_)
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
            for pack_ in packet:
                send(pack_)
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
        
        sender = header['s_uniqid']
        if sender == 0:
            #message is from cloud
            #unpack the message
            reg = unpack(msg)
            print 'NC received registration: ', reg[1]
        else: 
            sender = str(sender) #convert from int to string
            with open('/etc/waggle/devices', 'r') as _file:
                lines = _file.readlines()
            #check if device is already registered
            devices = []
            #the first line of the file contains a list of already registered nodes
            #deconstruct string into list
            while not lines[0].find(',')== -1:
                device, lines[0] = lines[0].split(',',1)
                devices.append(device)
                #print 'Device loop'
            #print 'Devices: ', devices
            try:
                devices.index(sender) #if this works, the device is already registered
            #nothing else to be done
            except: 
                #if it fails, the device is not yet registered. Add to list of devices
                #print 'Adding device ',sender, 'to devices file.'
                devices.append(sender)
                #Need to find available priorities to assign it
                #the second line of the file contains a list of available priorities
                priorities = []
                while not lines[1].find(',')== -1:
                    priority, lines[1] = lines[1].split(',',1)
                    priorities.append(priority)
                #print 'Priorities: ', priorities
                device_p = priorities.pop()
                #print 'Device_p: ', device_p
                #assign the device to its priority
                #the third line of the file contains a mapping of device to its priority. 
                #This is what is used to construct the device_dict
                lines[2] = sender + ':' + device_p + ',' + lines[2]
                #print 'Lines[2]: ', lines[2]

                #put the list back together to be written back into the file
                for priority in priorities:
                    lines[1] = priority + ',' + lines[1]
                    
                #send GN registration to cloud
                header_dict = {
                    "msg_mj_type" : ord('r'),
                    "msg_mi_type" : ord('r'),
                    "s_uniqid"    : int(sender)
                    }
                msg = str(QUEUENAME)
                try: 
                    packet = pack(header_dict, message_data = msg)
                    print 'Registration made for node ID ', sender
                    for pack_ in packet:
                        send(pack_)
                except Exception as e: 
                    print e
                
            #put the list back together to be written back into the file
            for device in devices:
                lines[0] = device + ',' + lines[0]
            #print 'Device in devices: ', lines[0]
            #print "Lines: ", lines
            #write the lines back into the file
            with open('/etc/waggle/devices', 'w') as _file:
                _file.writelines(lines)
            
           
            
    #message type unrecognized 
    else: 
        print 'Message major type, ' , major, ' unrecognized.'
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
    