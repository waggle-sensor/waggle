#!/usr/bin/env python


import sys
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
sys.path.append('../Communications/')
from internal_communicator import send


"""
    A python script that creates and sends a time request.
"""
packet = packetmaker.make_time_packet()
print 'Time request packet made...' 
for pack in packet:
    send(pack)
