from global_imports import threading
from collections import namedtuple                                                                                           # used to store sensors information in the hierarchical dictionary provided by this module
import os
import Queue                                                                                                                    # to implement thread safe queues for Inter thread communication
import time
import logging

#logging.basicConfig(filename = 'GN_output.log', level=logging.INFO,format='%(name)s: %(message)s',)
#logging.basicConfig(level=logging.INFO,format='%(asctime)s %(name)s: %(message)s',)
logging.basicConfig(level=logging.CRITICAL,format='%(name)s: %(message)s',)
logger = logging.getLogger("GN")
logger.setLevel(logging.CRITICAL)

# Message retrieved/stored in the buffer_mngr's buffer will use this tuple
buffered_msg = namedtuple('buffered_msg', ['internal_msg_header', 'msg_type', 'seq_no', 'reply_id', 'msg'])
#decoded_msg = namedtuple('decoded_msg', ['ver_no', 'msg_type', 'inst_id', 'timestamp', 'seq_no', 'reply_id', 'payload'])

# Internal Msg Headers
msg_to_nc = 'msg_to_NC'
msg_from_nc = 'msg_from_NC'

# To signal successful registration
start_communication_with_nc_event = threading.Event() 
# This event is set by sensor_controller after it stores the sensors' info in config file
sensors_info_saved_event = threading.Event()

# Msg Type - Number Mapping
registration_type = '0'
data_type = '1'
command_type = '2'
reply_type = '3'
acknowledgment = 'ACK'
no_reply = '-1'
terminator = str('!@#$%^&*')
gn_registration_ack_wait_time = 5                                       # in seconds
data_ack_wait_time = 10                                                 # in secs
wait_time_for_next_msg = 0.2                                            # 100 ms
# References of Sensor threads present
sensor_thread_list = []

# config file 
config_file_name = './' + "gn.cfg"


################################################################################
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
def add_to_thread_buffer(msg_buffer, string_msg, thread_name):
    logger.debug("Buffer size of " + thread_name + ': ' + str(msg_buffer.qsize()) + "\n\n")
    if not msg_buffer.full():
        msg_buffer.put(string_msg)
    else:
        logger.info("Msg buffer FULL: So Discarding the msg................................................................................." + "\n\n")
    logger.debug("Msg added to thread's buffer.\n\n")
