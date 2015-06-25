# packetmaker.py
"""
This module contains a few utilities that autogenerate complete simple packets,
such as ping and time request packets.
"""

import sys
sys.path.append("..")
from GN.PacketHandler import *
from gPickler import gPickler

# TODO: Find a way around two separate sequence sequences when using this module
#TODO probably need to add params recipient = , and flags = . Maybe flags can be stored in config file for each GNode 


def make_ping_packet():
    """
    Returns a simple ping request packet.
    
    :rtype: string
    """
    header_dict = {
        "msg_mj_type" : ord('p'),
        "msg_mi_type" : ord('r')
        }
    return pack(header_dict)

def make_time_packet():
    """
    Returns a simple time request packet.
    
    :rtype: string
    """
    header_dict = {
        "msg_mj_type" : ord('t'),
        "msg_mi_type" : ord('r')
        }
    return pack(header_dict)

#TODO Need to change to reflect how the GN will actually get, pack, and send data
def make_data_packet(data):
    """
    Compresses sensor data and returns a sensor data packet. 
    
    :param data: sensor data 
    :rtype: string 
    """ 
    msg = gPickler(data)
    header_dict = {
        "msg_mj_type" : ord('s'),
        "msg_mi_type" : ord('d')
        }
    return pack(header_dict, message_data = msg)
    