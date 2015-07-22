#!/usr/bin/env python


import sys
sys.path.append('../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send


""" 
    A python script that creates a registration message packet and sends it to the NC. 
""" 

packet = packetmaker.registration_packet()
print 'Registration packet made...' 
for pack in packet:
        send(pack)