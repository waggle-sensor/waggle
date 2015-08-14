# packetmaker.py
"""
    This module contains a few utilities that autogenerate complete simple packets,
    such as ping and time request packets.
"""
from gPickler import gPickle
import sys, os, os.path
sys.path.append("..")
from protocol.PacketHandler import *


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

def registration_packet(queuename):
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

def make_config_reg(config):
    """
        Returns a configuration registration packet. 
        
        :param config: node configuration file
        :rtype: string
        
    """
    header_dict = {
        "msg_mj_type" : ord('r'),
        "msg_mi_type" : ord('n')
        }
    return pack(header_dict, message_data = config)
    
def make_GN_reg(recp_ID):
    """
        Returns a guestnode registration packet to send to the node controller.
    """
    
    header_dict = {
        "msg_mj_type" : ord('r'),
        "msg_mi_type" : ord('r'),
        "r_uniqid" : recp_ID
        
        }
    

    return pack(header_dict, message_data = '')

#TODO may want to add an additional option argument to specify sender_id so that server can send a de-registration message for a GN
def deregistration_packet(recp_ID):
    """
        Returns a deregistration request packet.

        :param recp_ID: Unique ID of the message recipient
        :rtype: string
    """ 

    header_dict = {
        "msg_mj_type" : ord('r'),
        "msg_mi_type" : ord('d'),
        "r_uniqid" : recp_ID
        }
  
        
    return pack(header_dict, message_data = '')














