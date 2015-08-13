#!/usr/bin/env python


import sys
sys.path.append('../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send


""" 
    A python script that creates a de-registration message packet and sends it to the NC. 
""" 

with open('/etc/waggle/NCID','r') as file_:
    NC_ID = file_.read().strip() 

#send de-registration to NC
packet = packetmaker.deregistration_packet(int(NC_ID))
print 'De-registration packet made. Sending to ', NC_ID 
for pack in packet:
    send(pack)

