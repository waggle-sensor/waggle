#!/usr/bin/env python


import sys
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
sys.path.append('../Communications/')
from internal_communicator import send


""" 
    A python script that creates and sends a ping. 
""" 
packet = packetmaker.make_ping_packet()
print 'Ping packet made...' 
for pack in packet:
    send(pack)
print 'Ping packet sent.'