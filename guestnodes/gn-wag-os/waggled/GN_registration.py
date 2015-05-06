#!/usr/bin/env python


import sys
sys.path.append('../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send
from GN_configuration import *


""" 
    A python script that creates a registration message packet and sends it to the NC. 
""" 

#with open('/etc/waggle/NCID','r') as file_:
    #NC_ID = file_.read().strip() 

#send registration to NC
packet = packetmaker.make_GN_reg(int(NC_ID))
print 'Registration packet made. Sending to ', NC_ID 
for pack in packet:
    send(pack)

#TODO figure out why this is sending two registration messages