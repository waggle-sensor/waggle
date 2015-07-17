#!/usr/bin/env python

import sys
sys.path.append('../../../devtools/protocol_common/')
from utilities import packetmaker
from send import send

def data_packet(data):
    """
    This function packs and sends sensor data. 
    
    :param string data: The sensor data.
    
    """
    packet = packetmaker.make_data_packet(data)
    for pack in packet:
            send(pack)

