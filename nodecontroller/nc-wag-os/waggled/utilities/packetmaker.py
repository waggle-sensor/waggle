# packetmaker.py
"""
This module contains a few utilities that autogenerate complete simple packets,
such as ping and time request packets.
"""

with open('/etc/waggle/hostname','r') as file_:
    QUEUENAME = file_.read()
    

from gPickler import gPickle
import sys
sys.path.append("..")
from protocol.src.PacketHandler import *

# TODO: Find a way around two separate sequence sequences when using this module


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
    #TODO add dictionary information in param
    :param data: sensor data 
    :rtype: string 
    """ 
    msg = gPickle(data)
    header_dict = {
        "msg_mj_type" : ord('s'),
        "msg_mi_type" : ord('d'),
        "flags"       : (1,5,True) #TODO this should not be specified here. Maybe put in a config file or have a method to change these values.
        }
    return pack(header_dict, message_data = msg)

def registration_packet():
    """
    Returns a registration packet. 
    """ 
   
    header_dict = {
        "msg_mj_type" : ord('r'),
        "msg_mi_type" : ord('r'),
        "flags"       : (1,5,True)
        }
    msg = str(QUEUENAME) #TODO Should be a randomly generated string
        
    return pack(header_dict, message_data = msg)