#!/usr/bin/env python


import sys
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
sys.path.append('../../../../devtools/protocol_common/')
from protocol.PacketHandler import *
from send import send
from NC_configuration import *

#with open('/etc/waggle/queuename','r') as file_:
    #QUEUENAME = file_.read().strip() 

"""
    A python script that creates a registration message from the NC and sends it to the internal communication to put in the DC.
""" 
#script that sends the registration
#try:
    #packet = packetmaker.registration_packet()
    #print 'Registration packet made...' 
    #for pack in packet:
        #send(pack)
#except: 
    #print 'Unable to pack message'
        
#TODO add these to the packet maker class
#function that returns the registration
def NC_registration():
    try:
        packet = packetmaker.registration_packet(QUEUENAME)
        print 'NC registration packet made...' 
        for pack in packet:
            return pack
    except: 
        print 'Unable to pack message'

def GN_registration():
    """ 
        Sends registration message for each GN.
    """
    #TODO make it go through the list of GNs and send a registration for each one
    for key in DEVICE_DICT.keys():
        header_dict = {
            "msg_mj_type" : ord('r'),
            "msg_mi_type" : ord('r'),
            "s_uniqid"    : int(key)
            }
        msg = str(QUEUENAME)
        try: 
            packet = pack(header_dict, message_data = msg)
            print 'Registration made for node ID ', key
            for pack_ in packet:
                send(pack_)
            
        except Exception as e: 
            print e
    
