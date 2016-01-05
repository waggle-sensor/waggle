#!/usr/bin/env python

import sys
sys.path.append('../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send

def data_packet(data):
    """
    This script makes a sensor packet and sends it to the NC. 
    
    :param string data: The sensor data.
    
    """
    packet = packetmaker.make_data_packet(data)
    for pack in packet:
            send(pack)

