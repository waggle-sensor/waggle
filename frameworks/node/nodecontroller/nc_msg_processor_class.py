from global_imports import *
from nc_buffer_mngr_class import buffer_mngr_class
from nc_server_class import nc_server_class
from get_node_info import get_node_info
import socket
from nc_global_definition_section import logger, buffered_msg, \
registration_type,  data_type,  command_type,  reply_type,  \
acknowledgment,  no_reply, config_file_name, get_instance_id,  \
add_to_thread_buffer, wait_time_for_next_msg, config_file_lock
from config_file_functions import initialize_config_file, ConfigObj
from collections import defaultdict


"""
# Stores system's info
# Instantiates and starts buffer_mngr and nc_server
# Processes registration and data msgs obtained from GNs and sends them to cloud and ACKs to GNs
"""
class msg_processor_class():

    ##############################################################################
    def __init__(self, thread_name, port_for_gn):
        # can be used by logging module for printing messages related to this thread
        self.thread_name = "Thread_" + thread_name
        self.incoming_moduleMsgBfr = Queue.Queue(maxsize=1000)
        self.port_for_gn = port_for_gn
        self.buffer_mngr =  ''
        self.nc_server = ''
        logger.debug(self.thread_name+" Initialized.")


    ##############################################################################
    # Stores system's info, spawns other threads and at present processes reg/data msgs from GNs
    # and sends them to cloud and ACKs to GNs through buffer_mngr
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name)
            self.store_system_info()
            self.buffer_mngr = buffer_mngr_class("buffer_mngr")
            self.nc_server = nc_server_class("nc_server_class", socket.AF_INET, self.port_for_gn)
            self.buffer_mngr.pass_thread_address(self)
            self.nc_server.pass_thread_address(self.buffer_mngr)
            self.buffer_mngr.start()
            self.nc_server.start()
            logger.critical("All threads Started:"+str('%0.4f' % time.time()))
            wait_time_set=0;
            while True:
                if not self.incoming_moduleMsgBfr.empty():
                    #print "GN DATA MSG^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"+str('%0.4f' % time.time())
                    item = self.incoming_moduleMsgBfr.get()
                    logger.debug("Msg from GN received.")
                    self.process_external_msg(item)
                    self.incoming_moduleMsgBfr.task_done()
                    time.sleep(0.0001)
                    wait_time_set=0
                    #print "DATA MSG PROCESSED^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"+str('%0.4f' % time.time())
                else:
                    if wait_time_set==0: 
                        wait_time = time.time() + wait_time_for_next_msg
                        wait_time_set=1;
                    if wait_time > time.time():
                        time.sleep(0.0001)
                    else:
                        time.sleep(0.1)
        except Exception as inst:
            logger.critical("Exception in main: " + str(inst))

        finally:
            self.buffer_mngr.join(1)
            self.nc_server.handle_close()
            self.nc_server.join(1)
            logger.critical("All child threads exited. Parent Exiting...")


    ##############################################################################
    # Stores the node's sw/hw info in config file
    def store_system_info(self):
        with config_file_lock:
            logger.critical("Config file lock acquired-----------------------\
            -------------------------------------------\n\n")
            if os.path.exists(config_file_name):
                config = ConfigObj(config_file_name)
                # nc.cfg is already present
                if config["Systems Info"] != {}:
                    logger.critical("Config file lock released---------------\
                    ---------------------------------------------------\n\n")
                    return 0
            initialize_config_file(config_file_name)
            ret_val = get_node_info(config_file_name)
            if not ret_val:
                logger.critical("Config file lock released-------------------------------\
                -----------------------------------\n\n")
                return 0
            # Error
            logger.critical("Config file lock released-----------------------------------\
            -------------------------------\n\n")
            logger.critical("Error in getting node info!!!!")
            return 1


    ###############################################################################
    ## Returns True if the bfr_for_in_to_out_msgs of this inst_id is empty or the msg is reg/data
    ## and not a command, so the reply is simple ACK which is not saved in sent_msgs bfr.
    ## So as per the protocol even if bfr_for_in_to_out_msgs is full the ACK can be sent.
    #def can_send_msg(self, inst_id, msg_type):
        #return self.buffer_mngr.bfr_for_in_to_out_msgs[inst_id].empty() or (msg_type != command_type)


    ##############################################################################
    # Dispatches the msg to proper function by examining msg_type
    def process_external_msg(self, item):
        logger.debug("GN msg being processed.")
        if item.msg_type == registration_type:
            self.process_gn_registration_msg(item)
        elif item.msg_type == data_type:
            self.process_data_msg(item)
        elif item.msg_type == command_type:
            self.process_cmd_msg(item)
        else:
            logger.critical("Unknown Msg type received......")


    ##############################################################################
    # Registers GN if not registered yet and then sends reg msg to cloud
    # Always sends ACK to GN
    def process_gn_registration_msg(self, item):
        logger.debug("REGISTRATION Msg Received...........................")
        if item.msg != None:
            with config_file_lock:
                logger.critical("Config file lock acquired------------------------------------------------------------------\n\n")
                config = ConfigObj(config_file_name)
                # if GN is not registered
                if item.sock_or_gn_id not in config["GN Info"]:
                    self.register_gn(item.msg)
                    self.send_reg_msg_to_cloud('cloud')
                logger.critical("Config file lock released------------------------------------------------------------------\n\n")
        self.send_ack(item.seq_no, item.sock_or_gn_id, 0, str(int(time.time())))
        logger.debug("REGISTRATION ACK sent to buffer_mngr.")


    ##############################################################################
    # Saves GN's info in config file and sets registration status = "NO"
    def register_gn(self, gn_info):
        try:
            for single_gn_info in gn_info:
                config = ConfigObj(config_file_name)
                config["GN Info"][single_gn_info.instance_id] = single_gn_info.sys_info
                config["GN Info"][single_gn_info.instance_id]["Registered"] = 'NO'
                config.write()
                logger.info("GN registration info saved in config file.")
        except Exception as inst:
            logger.critical("Exception in register_gn:" + str(inst))


    ##############################################################################
    # Sends its own system's info if its not registered and also all GNs' info \
    # which are unregistered with the cloud
    def send_reg_msg_to_cloud(self, inst_id):
        try:
            reg_payload = RegistrationPayload()
            config = ConfigObj(config_file_name)
            l=lambda:defaultdict(l)
            reg_dict = l()
            if config["Registered"] == 'NO':
                reg_dict["Systems Info"] = config["Systems Info"]
            for node in config["GN Info"]:
                if config["GN Info"][node]["Registered"] == 'NO':
                    # append this GN's info to the registration dict
                    reg_dict["GN Info"][node]["Systems Info"] = config["GN Info"][node]["Systems Info"]
                    reg_dict["GN Info"][node]["Sensors Info"] = config["GN Info"][node]["Sensors Info"]
            reg_payload.sys_info = reg_dict
            reg_payload.instance_id = get_instance_id()
            buff_msg = buffered_msg(registration_type, None, no_reply, [reg_payload], inst_id)
            # Sends registration msg by sending to buffer_mngr
            add_to_thread_buffer(self.buffer_mngr.outgoing_ncMsgBfr[inst_id], buff_msg, 'buffer_mngr')
            logger.debug("Registration msg sent to bufr mngr to send to cloud.")
        except Exception as inst:
            logger.critical("Exception in send_reg_msg_to_cloud:" + str(inst))


    ##############################################################################
    # Sends data msg to cloud and ACK to GN
    def process_data_msg(self, item):
        logger.debug("DATA MSG Received..................................")
        if item.msg != None:
            # sends msg to bufr mngr to send it to cloud
            self.send_data_msg('cloud', item.msg)
        # sends msg to bufr mngr to send ACK to GN
        self.send_ack(item.seq_no, item.sock_or_gn_id, 0)
        logger.debug("Data ACK sent to buffer_mngr.")


    ##############################################################################
    # Sends msg to buffer_mngr to forward to GN/cloud (right now only used for cloud)
    def send_data_msg(self, inst_id, data_payloads):
        buff_msg = buffered_msg(data_type, None, no_reply, data_payloads, inst_id)
        add_to_thread_buffer(self.buffer_mngr.outgoing_ncMsgBfr[inst_id], buff_msg, 'buffer_mngr')
        logger.debug("Data msg sent to bufr mngr to send to cloud/GN.")


    
    ##############################################################################
    # Sends ACK to GN for reg/data msg currently, can be extended for all types
    # special_reg_ack is used to send current time to the GN while sending Reg ACK
    def send_ack(self, reply_id, inst_id, ret_val, special_reg_ack=None):
        msg = ReplyPayload()
        msg.return_value = ret_val
        if special_reg_ack:
            msg.output = special_reg_ack
        else:
            msg.output = acknowledgment
        buff_msg = buffered_msg(reply_type, None, reply_id, [msg], inst_id)
        add_to_thread_buffer(self.buffer_mngr.outgoing_ncAckBfr[inst_id], buff_msg, 'GN_msgs_buffer_mngr')


    ##############################################################################
    def __del__(self):
        print self, 'msg_processor object died.'

