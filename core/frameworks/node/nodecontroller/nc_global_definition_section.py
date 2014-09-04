from collections import namedtuple
import os
import Queue
import time
import logging


## used for logging msgs
#logging.basicConfig(filename = 'NC_output.log', level=logging.INFO,format='%(name)s: %(message)s',)
#logging.basicConfig(level=logging.INFO,format='%(asctime)s %(name)s: %(message)s',)
logging.basicConfig(level=logging.CRITICAL,format='%(name)s: %(message)s',)
logger = logging.getLogger("NC")
logger.setLevel(logging.CRITICAL)


port_for_gn = 7001                                                       # GNs can request at this port

buffered_msg = namedtuple('buffered_msg', ['internal_msg_header', 'msg_type', 'seq_no', 'reply_id', 'msg', 'sock_or_gn_id'])

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
asynchat_msg_terminator = str('!@#$%^&*')                   # Character at the end of every msg sent between GN and NC
wait_time_for_next_msg = 0.2                   # 100 ms
command_ack_wait_time = 10                     # in secs

# to avoid race conditions between msg+processor and gn_msgs_buffr_mngr
config_file_lock = threading.Lock()

# List maintaining current GN sockets
gn_socket_list = []                  



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
def add_to_thread_buffer(msg_buffer, string_msg, thread_name):
    logger.debug("Added to thread's buffer."+"\n\n")
    logger.debug("Buffer size of " + thread_name + ':' + str(msg_buffer.qsize()) + "\n\n")
    if not msg_buffer.full():
        msg_buffer.put(string_msg)
    else:
        logger.info("Msg buffer FULL: So Discarding the msg................................................................................." + "\n\n")
    
