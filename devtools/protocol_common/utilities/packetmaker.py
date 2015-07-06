# packetmaker.py
"""
	This module contains a few utilities that autogenerate complete simple packets,
	such as ping and time request packets.
"""

import sys
sys.path.append("..")
from protocol.PacketHandler import *

QUEUENAME = "fnherigfbvrefuesr"  #Insert your own fun random string here! 

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

def make_data_packet(data):
    """
    Compresses sensor data and returns a sensor data packet. 

    :param data: sensor data 
    :rtype: string 
    """ 
    msg = gPickle(data)
    header_dict = {
        "msg_mj_type" : ord('s'),
        "msg_mi_type" : ord('d')
        }
    return pack(header_dict, message_data = msg)

def registration_packet():
    """
    	Returns a registration request packet.

    	:rtype: string
    """ 
   
    header_dict = {
        "msg_mj_type" : ord('r'),
        "msg_mi_type" : ord('r')
        }
    msg = str(QUEUENAME)
        
    return pack(header_dict, message_data = msg)