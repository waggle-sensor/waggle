import asyncore
import asynchat
import socket
import logging
import threading
import Queue
import sys
import datetime
import time
import copy
from collections import namedtuple
from configobj import *
from config_file_functions import *
from logging_module import *
from waggle.common.util import get_current_time
from waggle.common.util import get_instance_id
from waggle.common.messaging_d import *
from waggle.device.node_controller.send_msg import send_msg

## used for logging msgs
##logging.basicConfig(filename = 'NC_output.log', level=logging.INFO,format='%(name)s: %(message)s',)
#logging.basicConfig(level=logging.INFO,format='%(asctime)s %(name)s: %(message)s',)
# This file uses 3rd party package called configobj.py which is present in the . folder
logger = set_logging_level(None)

port_for_gn = 7001                                                       # GNs can request at this port

buffered_msg = namedtuple('buffered_msg', ['internal_msg_header', 'msg_type', 'seq_no', 'reply_id', 'msg', 'inst_id'])

# Internal Msg Headers
msg_send = 'msg_send'
msg_from_gn = 'msg_from_gn'
msg_from_cloud = 'msg_from_cloud'


""" Here gn_id has two different meanings depending on the thread from which the msg is received. 
    If its from msg_processor then it contains inst_id of GN. If its from internal_communicator then it contains the socket object corresponding to the sender GN
"""
# Msg Type - Number Mapping
registration_type = '0'
data_type = '1'
command_type = '2'
reply_type = '3'
acknowledgment = 'ACK'
no_reply = '-1'
terminator = str('!@#$%^&*')

# List maintaining current GN sockets
gn_socket_list = []                  

# Variable keeping track of time
current_time = time.time()

# config file 
config_file_name = './' + "nc.cfg"

############################################################################## 
def get_instance_id():
    if get_instance_id.instance_id == None:
        mac_addr = ''
        mmcid = "sdcardid"
        try:
            interface_no = 0
            while 1:
                if os.path.exists('/sys/class/net/eth'+str(interface_no)+'/address'):
                    mac_addr = open('/sys/class/net/eth'+str(interface_no)+"/address").read()
                    mac_addr = mac_addr.split('\n')
                    mac_addr = mac_addr[0].replace(':','')
                    break
                else:
                    interface_no += 1
            if os.path.exists('/sys/block/mmcblk0/device/cid'):
                mmcid = open('/sys/block/mmcblk0/device/cid').read()
                mmcid = mmcid.split('\n')
                mmcid = mmcid[0]
            get_instance_id.instance_id = mac_addr + mmcid
        except Exception as inst:
            logger.critical("Exception in get_inst_id: " + str(inst)+"\n\n")
    return get_instance_id.instance_id
get_instance_id.instance_id = None    

        

    
##############################################################################   
# Returns the current time in string form
def get_current_time():
    logger.debug("Current time retrieved."+"\n\n")
    return time.strftime ('%Y.%m.%d.%H.%M.%S')

    
##############################################################################   
def add_to_thread_buffer(msg_buffer, string_msg, thread_name):
    logger.debug("Added to thread's buffer."+"\n\n")
    logger.debug("Buffer size of " + thread_name + ':' + str(msg_buffer.qsize()) + "\n\n")
    if not msg_buffer.full():
        msg_buffer.put(string_msg)
    else:
        logger.info("Msg buffer FULL: So Discarding the msg................................................................................." + "\n\n")
    
##############################################################################   
# Adds to the sorted buffer passed as an arg and then sorts the buffer based on the expiration_time field of the unacknowledged_msg_handler_info
def add_to_sorted_output_buffer(msg_buffer, unacknowledged_msg_handler_info):
    logger.debug("Buffer size of GN_msgs_buffer_mngr's output buffer before adding item: " + str(len(msg_buffer))+"\n\n")
    msg_buffer.append(unacknowledged_msg_handler_info)
    sorted(msg_buffer, key=lambda x: x[2])                                              # sorted based on time
    logger.debug("Msg waiting for ACK inserted in sorted buffer."+"\n\n")
    
##############################################################################       
# Returns msg_info for a specific msg    
def get_msg_info_and_delete_from_output_buffer(output_buffer, seq_no):
    logger.debug("Buffer size of buffer_mngr's output buffer before deleting item: " + str(len(output_buffer))+"\n\n")
    for msg_handler_info in output_buffer:
        if msg_handler_info[0] == seq_no:
            logger.debug("Timed out msg deleted from output_buffer and returned."+"\n\n")
            return output_buffer.remove(msg_handler_info)
    return None

     
##############################################################################      
# Adds given no of seconds to current time
def add_to_current_time(seconds):
    d1 = datetime.now() + datetime.timedelta(seconds = seconds)
    logger.debug ("Added to current time: "+str(seconds)+"\n\n")
    #time1 = datetime.datetime.strptime(time1, "%Y.%m.%d.%H.%M.%S")
    #return (time1 + datetime.timedelta(0, time2))
    # d1 = time.time() + seconds
    return d1

    
##############################################################################   
# Adds secs           
def add_time(time1, time2):
    d1 = datetime.datetime.now() + datetime.timedelta(time2)
    #time1 = datetime.datetime.strptime(time1, "%Y.%m.%d.%H.%M.%S")
    #return (time1 + datetime.timedelta(0, time2))
    logger.debug ("Added two timings."+"\n\n")
    return d1
