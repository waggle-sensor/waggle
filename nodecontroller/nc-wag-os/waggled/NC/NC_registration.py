#!/usr/bin/env python


import sys
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send


"""
    A python script that creates a registration message from the NC and sends it to the internal communication to put in the DC.
""" 

try:
    packet = packetmaker.registration_packet()
    print 'Registration packet made...' 
    for pack in packet:
        send(pack)
except: 
    print 'Unable to pack message'
