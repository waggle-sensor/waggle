#!/usr/bin/env python


import sys
sys.path.append('../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send


""" 
    A python script that creates a registration message packet and sends it to the NC. 
""" 

with open('/etc/waggle/NCID','r') as file_:
    NC_ID = file_.read().strip() 

packet = packetmaker.make_GN_reg(NC_ID)
print 'Registration packet made...' 
for pack in packet:
        send(pack)