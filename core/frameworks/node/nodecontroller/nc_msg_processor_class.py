from global_imports import *
from nc_gn_msgs_buffer_mngr_class import gn_msgs_buffer_mngr_class
from nc_server_class import nc_server_class
from get_node_info import get_node_info
import socket
from nc_global_definition_section import logger, buffered_msg,  msg_send,  \
msg_from_gn,  registration_type,  data_type,  command_type,  reply_type,  \
acknowledgment,  no_reply, config_file_name, get_instance_id,  \
add_to_thread_buffer, wait_time_for_next_msg
from config_file_functions import initialize_config_file, ConfigObj
from collections import defaultdict


# msg_processor (object of msg_processor_class): Responsible for spawning other threads, processing all the packets and responding to 
# cloud's or guest nodes' messages are processed
class msg_processor_class():
    
    ##############################################################################
    def __init__(self, thread_name, port_for_gn, gn_msgs_buffer_mngr, nc_server):
        
        self.thread_name = "Thread_" + thread_name																	# used by logging module for printing messages related to this thread
        self.input_buffer = Queue.Queue(maxsize=1000)																			# stores all incoming msgs from GNs/gn_msgs_buffer_mngr thread
        self.port_for_gn = port_for_gn																				# to be passed to nc_server_class so that it starts listening for guest's requests on that port
        self.gn_msgs_buffer_mngr =  gn_msgs_buffer_mngr                                                             # to save this global instance and pass to other objects when needed
        self.nc_server = nc_server                                                                                  # to save this global instance and pass to other objects when needed
        logger.debug(self.thread_name+" Initialized."+"\n\n")
        
        
    ##############################################################################    
    # Runs forever
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name+"\n\n")
            self.store_system_info()
            # Instantiates threads
            self.gn_msgs_buffer_mngr = gn_msgs_buffer_mngr_class("gn_msgs_buffer_mngr")
            self.nc_server = nc_server_class("nc_server_class", socket.AF_INET, self.port_for_gn)
            self.gn_msgs_buffer_mngr.pass_thread_address(self)
            self.nc_server.pass_thread_address(self.gn_msgs_buffer_mngr)
            # Starts Threads
            self.gn_msgs_buffer_mngr.start()
            self.nc_server.start()
            logger.critical("All threads Started:"+str('%0.4f' % time.time())+"\n\n")
            wait_time = time.time() + wait_time_for_next_msg                                                              # wait for 5ms for any msg
            while True:
                while not self.input_buffer.empty():
                    item = self.input_buffer.get()
                    logger.debug("Msg received."+"\n\n")
                    # Waits on the buffer till a msg is received
                    if item.internal_msg_header == msg_from_gn:
                        logger.debug("Msg from GN received:"+"\n\n")
                        self.process_external_msg(item)                                                                     # processes msgs obtained from NC/GNs
                    self.input_buffer.task_done()
                    wait_time = time.time() + wait_time_for_next_msg
                    #print "main MSG PROCESSED_---------------------------------------------------------------------"+str("%.4f"%time.time())
                    time.sleep(0.0001)
                if wait_time > time.time():
                    #print "main short sleep main"+str("%.4f"%time.time())
                    time.sleep(0.0001)
                else:
                    #print "main long sleep main"+str("%.4f"%time.time())
                    time.sleep(0.1)
        except Exception as inst:
            logger.critical("Exception in main: " + str(inst)+"\n\n")
            
        finally:
            self.gn_msgs_buffer_mngr.join(1)
            self.nc_server.handle_close()
            self.nc_server.join(1)
            logger.critical("All child threads exited. Parent Exiting..."+"\n\n")
       
        
    ##############################################################################
    # Stores the node's sw/hw info in config file
    def store_system_info(self):
        if os.path.exists(config_file_name):
            config = ConfigObj(config_file_name)
            if config["Systems Info"] != {}:                                            
                # nc.cfg is already present
                return
        initialize_config_file(config_file_name)
        ret_val = get_node_info(config_file_name)
        if not ret_val:
            return 0
        # Error
        return 1
        
        
    ##############################################################################
    # Extracts the msg_id and checks in the output sorted msg queue if its a reply of some msg, 
    # if so then deletes that msg from the output sorted msg queue, takes required action after deleting by calling the msg handler and passing the reply to it
    # If its a new msg then processes based on msg_type 
    def process_external_msg(self, item):
        logger.debug("GN msg being processed."+"\n\n")
        if item.msg_type == registration_type:																								  
            self.process_gn_registration_msg(item)                                                             # Registration request
        
        elif item.msg_type == data_type:                                                                                         
            self.process_data_msg(item)																		  # Data received
        
        elif item.msg_type == command_type:
            self.process_cmd_msg(item)                                                                         # Command received
        
        else:
            logger.critical("Unknown Msg type received......"+"\n\n")
                
            
        
    ##############################################################################
    # Function: Stores the information in gns_info_dict by calling update_gns_info_dict
    def process_data_msg(self, item):
        logger.debug("DATA MSG Received.................................."+"\n\n")
        if item.msg != None:                                                     
            self.send_data_msg('cloud', item.msg)                                # sends msg to bufr mngr to send it to cloud
        self.send_ack(item.seq_no, item.inst_id, 0)                              # sends msg to bufr mngr to send ACK to gn
        logger.debug("Data ACK sent to gn_msgs_buffer_mngr."+"\n\n")
   
   
       
    ##############################################################################
    def send_data_msg(self, inst_id, data_payloads):
        buff_msg = buffered_msg(msg_send, data_type, None, no_reply, data_payloads, inst_id)                   # adds header msg_to_nc in front of the registration message and returns whole message in string form by adding delimiter
        add_to_thread_buffer(self.gn_msgs_buffer_mngr.in_to_out_buffer, buff_msg, 'GN_msgs_buffer_mngr')                                 # Sends registration msg by adding to the buffer_mngr's buffer
        logger.debug("Data msg sent to bufr mngr to send to cloud."+"\n\n")
    
    
        
    ##############################################################################
    # Function: Stores the information in gns_info_dict by calling update_gns_info_dict
    def process_cmd_msg(self, item):
        logger.debug("CMD Received........................................"+"\n\n")
    
    
        
    ##############################################################################
    # Input: Received Msg
    # Function: Stores the information in gns_info_dict by calling update_gns_info_dict
    def process_gn_registration_msg(self, item):
        # store gn info in config file
        # add to cloud thread's buffer and send ACK
        logger.debug("REGISTRATION Msg Received..........................."+"\n\n")
        if item.msg != None:
            config = ConfigObj(config_file_name)
            # if GN is not registered, for 2nd level ack you need to check if it has any additional info related to registration
            if item.inst_id not in config["GN Info"]:
                # Store GN info in config file
                self.register_gn(item.msg)
                self.send_reg_msg('cloud')                                    # sends msg to bufr mngr to send it to cloud
        self.send_ack(item.seq_no, item.inst_id, 0, str(int(time.time())))                                     # sends msg to bufr mngr to send ACK to gn
        logger.debug("REGISTRATION ACK sent to gn_msgs_buffer_mngr."+"\n\n")
   
       
    ##############################################################################
    # Adds msg to the buffer_mngr's buffer
    def send_to_buffer_mngr(self, msg_type, reply_id, msg, inst_id):
        logger.debug ("Msg sent to buffer_mngr."+"\n\n")

       
    ##############################################################################
    def send_reg_msg(self, inst_id):
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
            buff_msg = buffered_msg(msg_send, registration_type, None, no_reply, [reg_payload], inst_id)                   # adds header msg_to_nc in front of the registration message and returns whole message in string form by adding delimiter
            add_to_thread_buffer(self.gn_msgs_buffer_mngr.in_to_out_buffer, buff_msg, 'GN_msgs_buffer_mngr')                                 # Sends registration msg by adding to the buffer_mngr's buffer
            logger.debug("Registration msg sent to bufr mngr to send to cloud."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in send_reg_msg:" + str(inst)+"\n\n")
           
        
    ##############################################################################
    def send_ack(self, reply_id, inst_id, ret_val, special_reg_ack=None):
        msg = ReplyPayload()
        msg.return_value = ret_val
        if special_reg_ack:
            msg.output = special_reg_ack
        else:
            msg.output = acknowledgment
        buff_msg = buffered_msg(msg_send, reply_type, None, reply_id, [msg], inst_id)                   # adds header msg_to_nc in front of the registration message and returns whole message in string form by adding delimiter
        add_to_thread_buffer(self.gn_msgs_buffer_mngr.in_to_out_buffer, buff_msg, 'GN_msgs_buffer_mngr')                                 # Sends registration msg by adding to the buffer_mngr's buffer
        
        
    ##############################################################################
    def register_gn(self, gn_info):
        try:
            for single_gn_info in gn_info:
                config = ConfigObj(config_file_name)
                config["GN Info"][single_gn_info.instance_id] = single_gn_info.sys_info
                config["GN Info"][single_gn_info.instance_id]["Registered"] = 'NO'
                config.write()
                config = ConfigObj(config_file_name)
                logger.info("GN registration info saved in config file."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in register_gn:" + str(inst)+"\n\n")
        
        
        
    ##############################################################################    
    def __del__(self):
        print self, 'msg_processor object died.'
   