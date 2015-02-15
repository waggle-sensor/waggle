from global_imports import threading
from collections import namedtuple
import os
import Queue
import time
import logging


#################################################################################
"""
    # Used for logging msgs
    # Logging level can be set using level=logging.______
    # Level=critical will only display most important messages
    # (ie. printed using logger.critical). Same applies for all different levels
    # Hierarchy of levels in decreasing order of importance: Critical, error,  warning, info, debug
"""

# Below line should be uncommented if you want to log the messages to a file
logging.basicConfig(filename = 'module'+str(int(time.time()))+'.log', level=logging.CRITICAL,format='%(name)s: %(message)s',)

# Below line should be commented if you don't want to log the messages to a terminal
# In the below format: name is usually used to show from which thread or class\
# the message is displayed
# Message is the string passed in double quotes: Ex: logger.info("This will be displayed.")
#logging.basicConfig(level=logging.CRITICAL,format='%(name)s: %(message)s',)
# name="GN" as per the above format
logger = logging.getLogger("GN")

# To set the logging level uncomment the following
# logger.setLevel(logging.CRITICAL)
#################################################################################


#################################################################################
# Message to another thread is passed in the following format
buffered_msg = namedtuple('buffered_msg', ['msg_type',\
'seq_no', 'reply_id', 'msg'])
# The interpretation of fields in the above format:

"""
# When msg sent from external_communicator to buffr_mngr:
#	internal_msg_header = "msg_from_nc",  can be changed to anything depending\
#	on the sender of the msg
#	msg_type = None
#   seq_no: None
#   reply_id: None
#   msg = msg obbtained from NC
"""



"""
# When msg sent to sensor_controller's input_buffer:
#	
#	msg_type = data_type (as currently only data is sent from sensors)
#   seq_no: None as seq_no is managed by buffr_mngr
#   reply_id: -1
#   msg = data msg from sensor
"""

"""
# When msg sent from main_thread/sensor_controller to buffr_mngr:
#	
#	msg_type = msg_type of the msg to be sent
#   seq_no: None as seq_no is managed by buffr_mngr
#   reply_id: if msg = ACK then sequence no of the msg whose ACK is being sent else None
#   msg = payloads to be sent
"""

"""
# When msg sent from buffr_mngr to external_communicator:
#	The named tuple is not used but directly encoded msg with msg_header \
#	attached is added to the output buffer
"""
#################################################################################




# To signal successful registration
start_communication_with_nc_event = threading.Event()
# This event is set by sensor_controller after it stores the sensors' info in config file
sensors_info_saved_event = threading.Event()

# Constants
registration_type = '0'
data_type = '1'
command_type = '2'
reply_type = '3'
acknowledgment = 'ACK'
no_reply = '-1'
# String at the end of every msg sent between GN and NC
asynchat_msg_terminator = str('!@#$%^&*')
# Wait time in seconds before the msg is resent
gn_registration_ack_wait_time = 5
# Wait time in seconds before the msg is resent
data_ack_wait_time = 10
# Time during which the thread should remain attentive for new msg, here 200 ms
wait_time_for_next_msg = 0.2
# References of sensor threads looping for sensor data
sensor_thread_list = []
# config file
config_file_name = './' + "gn.cfg"


################################################################################
# Reads id from file
def get_instance_id():
    try:
        if get_instance_id.instance_id == None:
            # read inst_id from file
            f=open("inst_id","r")
            get_instance_id.instance_id=f.read()
            f.close()
    except Exception as inst:
            logger.critical("Exception in get_inst_id: " + str(inst))     
    return get_instance_id.instance_id
# instance_id is a static variable    
get_instance_id.instance_id = None
    

##############################################################################
# Adds the msg to another thread's buffer if buffer is not full else discards the msg
# Used by most of the threads to send msgs to other threads
def add_to_thread_buffer(msg_buffer, string_msg, thread_name):
    logger.debug("Buffer size of " + thread_name + ': ' + str(msg_buffer.qsize()) + "\n\n")
    if not msg_buffer.full():
        msg_buffer.put(string_msg)
    else:
        logger.info("Msg buffer FULL: So Discarding the msg...................\
        .............................................................." + "\n\n")
    logger.debug("Msg added to thread's buffer.\n\n")
