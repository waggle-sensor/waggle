#!/usr/bin/env python


import sys
sys.path.append('../../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send


""" A python script that creates and sends a ping. """ 

ping = packetmaker.make_ping_packet()
print 'Ping packet made...' 

send(ping)