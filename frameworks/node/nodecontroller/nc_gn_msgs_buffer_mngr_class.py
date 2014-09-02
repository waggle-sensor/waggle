from waggle.device.node_controller.send_msg import send_msg
from global_imports import *
from nc_global_definition_section import buffered_msg,  msg_send,  msg_from_gn,  \
registration_type,  reply_type, command_type, command_ack_wait_time, terminator,  \
gn_socket_list, logger, config_file_name, get_instance_id,  add_to_thread_buffer, \
wait_time_for_next_msg
from config_file_functions import initialize_config_file, ConfigObj

# Incoming msgs from all GNs go into out_to_in buffer, all responses to GN's msgs are stored in a hashmap tagged by gn_id. 
# There is a separate in_to_out_buffer for cmds to be sent to each GN and also output_buffer_for_gn_cmds,
# which stores the last sent msg till the ack is received.
# gn_msgs_buffer_mngr (object of gn_msgs_buffer_mngr_class): Sends the received messages to msg_processor's buffer and messages received from msg_processor to
# the respective socket connected to the specific guest node       
class gn_msgs_buffer_mngr_class(threading.Thread):
   
    ##############################################################################  
    def __init__(self, thread_name):
        threading.Thread.__init__(self)
        self.thread_name = "Thread_" + thread_name                                            # used by logging module for printing messages related to this thread
        self.daemon = True
        self.log_file_name = "NC_msg_log"
        self.cmd_msg_handler_no = 0
        self.handler_vector_table = {}                 
        self.initialize_handler_vector_table()
        self.bfr_for_in_to_out_msgs = {}     
        self.bfr_for_sent_msgs = {}
        self.bfr_for_out_to_in_msgs = Queue.Queue(maxsize=1000)
        self.bfr_for_sent_responses = {}
        self.error_scope = 255
        self.seq_no_partition_size = 3                  # no of bytes of session_id
        self.initial_session_id = bytearray([0,0,0])
        self.gn_session_id = {}            # in bytearray
        self.nc_session_id = self.initialize_nc_session_id()                                          # in bytearray, 0 means illegal
        self.last_gn_subseq_no = {}                                      # in int
        self.last_nc_subseq_no = {}                                      # in int
        self.ackd_gn_subseq_no = {}                                      # in int
        self.ackd_nc_subseq_no = {}                                      # in int
        self.gn_window_size = 1
        self.nc_window_size = 1
        self.msg_processor = ''                                                               # to save global msg_processor's input_buffer address
        self.handler_vector_table = {}  
        self.registered_nodes = []
        self.gn_instid_socket_obj_mapping = {}                                                # Dict maintaining gn_id and socket mapping
        logger.debug(self.thread_name+" Initialized."+"\n\n")

       
    ##############################################################################
    def pass_thread_address(self, msg_processor):
        try:
            self.msg_processor = msg_processor
            logger.debug("Address of msg processor saved."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in pass_thread_address: " + str(inst)+"\n\n")

        
    ##############################################################################
    def send_in_to_out_msgs(self, filled_in_to_out_bfr_ids):
        try:
            logger.debug("Sending in_to_out msgs................................................")
            for inst_id in filled_in_to_out_bfr_ids:
                item = self.bfr_for_in_to_out_msgs[inst_id].get()
                if inst_id != 'cloud' and item.msg_type != reply_type and self.bfr_for_sent_msgs_full(inst_id):
                    # push the msg back in the queue
                    self.bfr_for_in_to_out_msgs[inst_id].put(item)
                else:
                    encoded_msg = self.gen_msg(item)
                    if inst_id != 'cloud':
                        encoded_msg = encoded_msg + terminator
                        if item.msg_type != reply_type:
                            expiration_time = self.calculate_expiration_time(item.msg_type, item.msg)
                            msg_handler_no = self.get_msg_handler_no(item.msg_type)
                            unacknowledged_msg_handler_info = [self.last_nc_subseq_no[inst_id], expiration_time, encoded_msg, msg_handler_no, inst_id]  
                            logger.debug("Buffer size of gn_msgs_buffer_mngr's output buffer before adding item: " + str(len(self.bfr_for_sent_msgs[inst_id]))+"\n\n")
                            self.add_to_sent_msgs_bfr(unacknowledged_msg_handler_info, inst_id)
                            logger.debug("Msg waiting for ACK inserted in sorted buffer.\n\n")
                        else:
                            self.bfr_for_sent_responses[inst_id].append([self.convert_to_int(item.reply_id[self.seq_no_partition_size:]), encoded_msg])
                        self.send_msg_to_gn(inst_id, encoded_msg)
                    else:
                        logger.info("Msg sent to Cloud!"+"\n\n") # + (encoded_msg)+"\n\n")
                        ret = self.send_msg_to_cloud(encoded_msg)                                                             # send msg to cloud
                        # need to handle the failure case
                        if not ret:
                            self.process_ack(item.msg_type)
                self.bfr_for_in_to_out_msgs[inst_id].task_done()
        except Exception as inst:
            logger.critical("Exception in send_in_to_out_msgs: " + str(inst)+"\n\n")

            
            
    ##############################################################################
    def send_msg_to_gn(self, inst_id, msg):
        try:
            socket_obj = self.get_socket_obj(inst_id)
            if socket_obj:
                socket_obj.push(msg) 
                logger.critical("Msg sent to GN:"+str('%0.4f' % time.time())+"\n\n")# + msg + "\n\n" )
            else:
                logger.critical("GN's socket closed. So discarding the msg------------------------------------------------------------."+ "\n\n")
        except Exception as inst:
            logger.critical("Exception in send_msg_to_gn: " + str(inst)+"\n\n")


    ##############################################################################
    def initialize_gn_data_structures(self, inst_id, socket):
        try:
            # create new socket_instid mapping
            if self.new_socket(inst_id, socket):
                self.gn_instid_socket_obj_mapping[inst_id] = socket
            if inst_id not in self.last_nc_subseq_no:
                # initialize seq_nos for communication with this inst_id
                self.last_nc_subseq_no[inst_id] = 0
                self.ackd_nc_subseq_no[inst_id] = 0
                self.last_gn_subseq_no[inst_id] = 0
                self.ackd_gn_subseq_no[inst_id] = 0
                # create in_to_out and sent_msgs bfrs for new inst_id
                self.bfr_for_in_to_out_msgs[inst_id] = Queue.Queue(100)
                self.bfr_for_sent_msgs[inst_id] = []
                self.bfr_for_sent_responses[inst_id] = []
        except Exception as inst:
            logger.critical("Exception in initialize_gn_data_structures: " + str(inst)+"\n\n")

      
    ##############################################################################    
    def process_out_to_in_msgs(self):
        try:
            logger.debug("Processing out_to_in msgs................................................")
            while not self.bfr_for_out_to_in_msgs.empty():
                item = self.bfr_for_out_to_in_msgs.get()
                logger.debug("Msg from GN:" + str(item.msg) + "\n\n")
                decoded_msg = Message.decode(item.msg)
                inst_id = decoded_msg.header.instance_id
                if (not self.new_node(decoded_msg.header.instance_id)) | (decoded_msg.header.message_type == registration_type):
                    if self.new_msg(decoded_msg):
                        self.initialize_gn_data_structures(inst_id, item.sock_or_gn_id)
                        # save new ackd and last seq_nos received from this inst_id
                        new_last_gn_subseq_no = self.convert_to_int(decoded_msg.header.sequence_id[self.seq_no_partition_size:])
                        new_ackd_gn_subseq_no = self.convert_to_int(decoded_msg.header.user_field1)
                        self.last_gn_subseq_no[inst_id] = self.get_new_seq_no(self.last_gn_subseq_no[inst_id], new_last_gn_subseq_no)
                        new_ackd_gn_subseq_no = self.get_new_seq_no(self.ackd_gn_subseq_no[inst_id], new_ackd_nc_subseq_no)
                        if self.ackd_gn_subseq_no[inst_id] != new_ackd_gn_subseq_no:
                            self.ackd_gn_subseq_no[inst_id] = new_ackd_gn_subseq_no
                            # discard the last out of gn_window buffered response if any
                            self.discard_ackd_responses(inst_id)
                        if decoded_msg.header.message_type == reply_type:
                            msg_info = self.get_msg_info_and_delete_from_output_buffer(decoded_msg.header.reply_to_id, inst_id)         
                            self.handler_vector_table[msg_info[3]](msg_info[2], inst_id, decoded_msg)        
                        else:
                            item = buffered_msg(item.internal_msg_header, decoded_msg.header.message_type, decoded_msg.header.sequence_id, decoded_msg.header.reply_to_id, decoded_msg.payloads, decoded_msg.header.instance_id)
                            add_to_thread_buffer(self.msg_processor.input_buffer, item, 'Msg_Processor')        
                    else:
                        logger.critical("OLD MSG DISCARDED...................................................")
                else:
                    logger.critical("UNKNOWN GN SO MSG DISCARDED.........................................."+ "\n\n")
                # TODO: If msg is just an ACK then don't forward it, copy this portion from GN's code, take care of extra inst_id with seq_no in unack_msg_info here
                self.bfr_for_out_to_in_msgs.task_done()
        except Exception as inst:
            logger.critical("Exception in process_out_to_in_msgs: " + str(inst)+"\n\n")
  
    
    ############################################################################## 
    def send_timed_out_msgs(self):
        try:
            for inst_id, bfr in self.bfr_for_sent_msgs.iteritems():
                if not bfr.empty():
                    timed_out_msg_info = self.get_timed_out_msg_info(bfr)
                    if timed_out_msg_info:
                        self.handler_vector_table[timed_out_msg_info[3]](timed_out_msg_info, inst_id, None)
        except Exception as inst:
            logger.critical("Exception in send_timed_out_msgs: " + str(inst)+"\n\n")
       
    
    ##############################################################################
    def run(self):
        # create in_to_out buffer for cloud
        self.bfr_for_in_to_out_msgs['cloud'] = Queue.Queue(100)
        try:
            logger.debug("Starting " + self.thread_name+"\n\n")
            wait_time = time.time() + wait_time_for_next_msg                                                              # wait for 5ms for any msg
            while True:
                filled_in_to_out_bfr_ids = self.get_filled_bfr_ids(self.bfr_for_in_to_out_msgs)
                filled_sent_msgs_bfr_ids = self.get_filled_bfr_ids(self.bfr_for_sent_msgs)
                logger.debug("Collected info about filled buffers.")
                logger.debug("in_to_out_bfr_ids:"+str(filled_in_to_out_bfr_ids)+"\n\nfilled_snet_msgs_ids:"+str(filled_sent_msgs_bfr_ids))
                while not self.bfr_for_out_to_in_msgs.empty() or filled_in_to_out_bfr_ids or filled_sent_msgs_bfr_ids:
                    self.send_in_to_out_msgs(filled_in_to_out_bfr_ids)
                    self.process_out_to_in_msgs()
                    self.send_timed_out_msgs()
                    # set time to remain attentive for next 5 ms
                    wait_time = time.time() + wait_time_for_next_msg - 0.1              # this waits only for 0.1 s as its one layer above the other threads
                    time.sleep(0.0001)
                    #print "MSG PROCESSSED----------------------------------------------------------------------------------------------------------"
                    #print "short sleep bfr mngr"
                if wait_time > time.time():
                    #print "short sleep bfr mngr"+str("%.4f"%time.time())
                    time.sleep(0.0001)
                else:
                    #print "long sleep bfr mngr"+str("%.4f"%time.time())
                    time.sleep(0.1)
        except Exception as inst:
            logger.critical("Exception in gn_msgs_bufr_mngr run: " + str(inst)+ "\n\n")
            self.run()
    
    
    ############################################################################## 
    def get_filled_bfr_ids(self, bfrdict):
        try:
            filled_bfr_ids = []
            for inst_id in bfrdict:
                if bfrdict[inst_id]:
                    filled_bfr_ids.append(inst_id)
            return filled_bfr_ids
        except Exception as inst:
            logger.critical("Exception in get_filled_bfr_ids: " + str(inst)+"\n\n")

    
    ############################################################################## 
    def bfr_for_sent_msgs_full(self, inst_id):
        try:
            return len(self.bfr_for_sent_msgs[inst_id]) >= self.nc_window_size
        except Exception as inst:
            logger.critical("Exception in bfr_for_sent_msgs_full: " + str(inst)+"\n\n")

    
    ##############################################################################
    def add_to_sent_msgs_bfr(self, msg_handler_info, inst_id):
        try:
            logger.debug("Buffer size of GN_msgs_buffer_mngr's output buffer before adding item: " + str(len(self.bfr_for_sent_msgs[inst_id]))+"\n\n")
            self.bfr_for_sent_msgs[inst_id].append(msg_handler_info)
            sorted(self.bfr_for_sent_msgs[inst_id], key=lambda x: x[1])                                              # sorted based on time
            logger.debug("Msg waiting for ACK inserted in sorted buffer."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in add_to_sent_msgs_bfr: " + str(inst)+"\n\n")

   
    ############################################################################## 
    def new_socket(self, gn_id, socket):
        try:
            if socket in gn_socket_list:
                if (gn_id in self.gn_instid_socket_obj_mapping) and (socket == self.gn_instid_socket_obj_mapping[gn_id]):
                    return False
            return True
        except Exception as inst:
            logger.critical("Exception in new_socket: " + str(inst)+"\n\n")

    
    ############################################################################## 
    def process_ack(self, msg_type):
        try:
            if msg_type == registration_type:
                self.process_reg_ack()
        except Exception as inst:
            logger.critical("Exception in process_ack: " + str(inst)+"\n\n")
       
            
    ############################################################################## 
    def process_reg_ack(self):
        try:
            config = ConfigObj(config_file_name)
            if config["Registered"] == 'NO':
                config["Registered"] = 'YES'
            for node in config["GN Info"]:
                if config['GN Info'][node]["Registered"] == 'NO':
                    config['GN Info'][node]["Registered"] = 'YES'
            config.write()
        except Exception as inst:
            logger.critical("Exception in process_reg_ack: " + str(inst)+"\n\n")

   
    ##############################################################################  
    def clean_gn_data(self, del_socket):
        try:
            inst_id = None
            if self.gn_instid_socket_obj_mapping:
                for gn_id, socket in self.gn_instid_socket_obj_mapping.items():
                        if socket == del_socket:
                            inst_id = gn_id
                            break
                if inst_id:
                    del self.gn_instid_socket_obj_mapping[inst_id]
                    logger.info("Socket and seq_no entry removed from id_socket mapping.\nSocket-ID Map:\t"+str(self.gn_instid_socket_obj_mapping)+"\nSeq-ID Map:\t"+\
                                    str(self.last_nc_seq_no)+ "\n\n")
        except Exception as inst:
            logger.critical("Exception in clean_gn_data: " + str(inst)+"\n\n")
           
   
    ##############################################################################   
    def gen_msg(self, item):
        try:
            header = MessageHeader()
            header.message_type = item.msg_type
            header.instance_id = get_instance_id()
            header.sequence_id = self.gen_nc_seq_no(item.sock_or_gn_id)
            header.user_field1 = str(self.convert_to_bytearray(self.ackd_nc_subseq_no[item.sock_or_gn_id]))
            header.reply_to_id = item.reply_id
            msg = Message()
            msg.header = header
            for each_msg in item.msg:
                msg.append(each_msg)
            msg = msg.encode()  
            logger.debug("Msg Encoded."+"\n\n")
            return msg
        except Exception as inst:
            logger.critical("Exception in gen_msg: " + str(inst)+"\n\n")

       
    ##############################################################################
    def send_msg_to_cloud(self, encoded_msg):
        try:
            send_msg(encoded_msg)                                                             # send msg to cloud
            return 0
        except Exception as inst:
            logger.critical("Exception in send_msg_to_cloud: " + str(inst)+ "\n\n")
            logger.critical("Retrying after 1 secs."+ "\n\n")
            time.sleep(.001)
            self.send_msg_to_cloud(encoded_msg)
        
        
    ##############################################################################
    # Checks whether a GN is new or not by checking entries in registered nodes or reading config 
    #file, if entry is presentin config file but not in registered nodes then it adds that node to 
    #registered_nodes list
    def new_node(self, inst_id):
        try:
            if inst_id in self.registered_nodes:
                logger.debug("Node is already known."+"\n\n")
                return False
            # Check in config file for the inst_id
            config = ConfigObj(config_file_name)
            if inst_id in config['GN Info']:
                logger.debug("Node is already known."+"\n\n")
                self.registered_nodes.append(inst_id)
                return False
            logger.debug("New node."+"\n\n")
            return True
        except Exception as inst:
            logger.critical("Exception in new_node: " + str(inst)+ "\n\n")
           
           
    ##############################################################################
    def save_session_id(self, inst_id, tag_name, session_id):
        try:
            config = ConfigObj(self.log_file_name)
            if inst_id:
                # create an entry for the GN 
                if inst_id not in config:
                    config[inst_id] = {}
                config[inst_id][tag_name] = session_id
            else:
                config[tag_name] = session_id
            config.write()
        except Exception as inst:
            logger.critical("Exception in save_session_id: " + str(inst)+"\n\n")
        
    
    
    ##############################################################################
    #checks first in self.gn_highest_seq_no, if found then returns that else checks in log file for that inst_id entry if found returns that, else returns None 
    def get_old_session_id(self, inst_id, tag_name):
        try:
            config = ConfigObj(self.log_file_name)
            if inst_id:
                if tag_name == 'GN Session ID' and inst_id in self.gn_session_id:
                        return self.gn_session_id[inst_id]
                if inst_id in config:
                    return config[inst_id][tag_name]
            else:
                if tag_name in config:
                    return config[tag_name]
            return None
        except Exception as inst:
            logger.critical("Exception in get_old_session_id: " + str(inst)+ " for:" + str(inst_id) + "\n\n")
    
    
    ################################################################################
    #def increment_byte_seq(self, byte_seq):
        #try:
            #byte_seq = bytearray(byte_seq)
            #length = len(byte_seq)
            #integer_no = sum(byte_seq[i] << ((length-1-i) * 8) for i in range(length))
            #if integer_no == 16777215:
               #integer_no = 0
            #else:
                #integer_no += 1
            #for i in range(length):
                #byte_seq[i] = (integer_no >> ((length-1-i)*8)) & 0xff 
        #except Exception as inst:
            #logger.critical("Exception in increment_byte_seq: " + str(inst)+ "\n\n")
        #return str(byte_seq)
   
     
    ##############################################################################
    # Increments the current sequence no which is maintained by NC to interact with each GN
    def gen_nc_seq_no(self, inst_id):
        try:
            if inst_id in self.last_nc_subseq_no:
                # increment the session_seq_no
                self.last_nc_subseq_no[inst_id] = self.increment_no(self.last_nc_subseq_no[inst_id])
                logger.debug("SEQUENCE NO. generated: " + self.last_nc_subseq_no[inst_id] + "for Node:"+str(inst_id)+ "\n\n")
                return str(self.nc_session_id) + str(self.convert_to_bytearray(self.last_nc_subseq_no[inst_id]))
            return None
        except Exception as inst:
            logger.critical("Exception in gen_nc_seq_no: " + str(inst)+ "\n\n")
    
    
    ##############################################################################   
    # Returns the internal_communicator object corresponding to the gn represented by gn_id = (gn_ip, gn_port)         
    def get_socket_obj(self, gn_id):
        try:
            logger.debug("Socket object corresponding to specific GN retreived."+ "\n\n")
            if gn_id in self.gn_instid_socket_obj_mapping:
                if self.gn_instid_socket_obj_mapping[gn_id] in gn_socket_list:
                    return self.gn_instid_socket_obj_mapping[gn_id]
                else:
                    del self.gn_instid_socket_obj_mapping[gn_id]
            return None
        except Exception as inst:
            logger.critical("Exception in get_socket_obj: " + str(inst)+ "\n\n")
           
       
    ##############################################################################
    def __del__(self):
        print self, 'gn_msgs_bufr_mngr object died.'
        

    ##############################################################################
    def initialize_nc_session_id(self):
        try:
            session_id = self.get_old_session_id(None, 'NC Session ID')
            if not session_id:
                session_id = str(self.initial_session_id)
            session_id = self.convert_to_bytearray(self.increment_no(self.convert_to_int(session_id)))
            self.save_session_id(None, "NC Session ID", str(session_id))
            logger.debug("Seq_no. initialized.\n\n")
            return session_id
        except Exception as inst:
            logger.critical("Exception in initialize_nc_session_id: " + str(inst)+"\n\n")
       
                
    ##############################################################################
    def close(self):
        try:
            self.external_communicator.shutdown = 1
            self.external_communicator.handle_close()
            self.external_communicator.join(1)
        except Exception as inst:
            logger.critical("Exception in close: " + str(inst)+"\n\n")

    
    ##############################################################################
    def get_new_seq_no(self, new_no, old_no):
        try:
            if (new_no != old_no) and self.in_expected_range(new_no, old_no):
                return new_no
            return old_no
        except Exception as inst:
            logger.critical("Exception in get_new_seq_no: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    def discard_ackd_responses(self, inst_id):
        try:
            if self.last_gn_subseq_no[inst_id] < self.ackd_gn_subseq_no[inst_id]:
                # wrap-up case
                lower_limit = self.last_gn_subseq_no[inst_id]
            else:
                # place holder value
                lower_limit = -1
            for response in self.bfr_for_sent_responses[inst_id]:
                # check whether the buffered_response's reply_id ie. NC's seq_no is now outside gn's current window
                if response[0] < self.ackd_gn_subseq_no[inst_id] and response[0] > lower_limit:
                    self.bfr_for_sent_responses[inst_id].remove(response)
                else:
                    # as ACKS are stored in FIFO order
                    break
        except Exception as inst:
            logger.critical("Exception in discard_ackd_responses: " + str(inst)+"\n\n")
    
    
    ##############################################################################    
    # Returns msg_info for a specific msg    
    def get_msg_info_and_delete_from_output_buffer(self, seq_no, inst_id):
        try:
            logger.debug("Buffer size of buffer_mngr's output buffer before deleting item: " + str(len(self.bfr_for_sent_msgs[inst_id]))+"\n\n")
            for msg_handler_info in self.bfr_for_sent_msgs[inst_id]:
                if msg_handler_info[0] == seq_no:
                    self.bfr_for_sent_msgs[inst_id].remove(msg_handler_info)
                    if (msg_handler_info[0] > self.ackd_nc_subseq_no[inst_id]) or (msg_handler_info[0] < self.last_nc_subseq_no[inst_id]):
                            self.ackd_nc_subseq_no[inst_id] = msg_handler_info[0]
                    logger.debug("Output buffer: "+str(output_buffer) + "\n\n")
                    logger.debug("Msg deleted from output_buffer and returned.\n\n")
                    return msg_handler_info
            return None
        except Exception as inst:
            logger.critical("Exception in get_msg_info_and_delete_from_output_buffer: " + str(inst)+"\n\n")
    

    ##############################################################################    
    # Checks for timed out msg and returns it
    def get_timed_out_msg_info(self, bfr):
        try:
            msg_handler_info = bfr[0]
            if msg_handler_info[1] < time.time():
                bfr.remove(msg_handler_info)
                return msg_handler_info
            return None
        except Exception as inst:
            logger.critical("Exception in get_timed_out_msg_info: " + str(inst)+"\n\n")
       
   
    
    ##############################################################################
    def convert_to_int(self, byte_seq):
        try:
            if byte_seq != None:
                byte_seq = bytearray(byte_seq)
                int_id = sum(byte_seq[i] << ((len(byte_seq)-1-i) * 8) for i in range(len(byte_seq)))
                return int_id
            return None
        except Exception as inst:
            logger.critical("Exception in convert_to_int: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    def convert_to_bytearray(self, int_no):
        try:
            if int_no != None:
                byte_seq = bytearray([0,0,0])
                for i in range(self.seq_no_partition_size):
                    byte_seq[i] = (int_no >> ((self.seq_no_partition_size-1-i)*8)) & 0xff 
                return byte_seq
            return None
        except Exception as inst:
            logger.critical("Exception in convert_to_bytearray: " + str(inst)+"\n\n")
    
                
                
    ##############################################################################
    def is_wrap_up(self, no2, no1):
        try:
            return no2 < (no1 - self.error_scope)
        except Exception as inst:
            logger.critical("Exception in is_wrap_up: " + str(inst)+"\n\n")
    
        
    ##############################################################################
    # session_id (not <) old_session_id-10 so either == or > or wrap up occured so good
    def in_expected_sessionseq_range(self, new_id, old_id):
        try:
            return self.in_expected_range(new_id, old_id)
        except Exception as inst:
            logger.critical("Exception in in_expected_sessionseq_range: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    # session_id (not <) old_session_id-10 so either == or > or wrap up occured so good
    def in_expected_range(self, new_id, old_id):
        try:
            # self.error_scope shows the range of session_id which may be old and should be discarded
            return (new_id > old_id) or self.is_wrap_up(new_id, old_id)
        except Exception as inst:
            logger.critical("Exception in in_expected_range: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    def in_expected_subseq_range(self, new_subseq_no, inst_id):
        try:
            if not self.is_wrap_up(self.last_gn_subseq_no[inst_id], self.ackd_gn_subseq_no[inst_id]):
                return (new_subseq_no > self.ackd_gn_subseq_no[inst_id]) and ((self.last_gn_subseq_no[inst_id] + self.gn_window_size) >= new_subseq_no)
            # due to wrap-up
            return (new_subseq_no > self.ackd_gn_subseq_no[inst_id]) or (new_subseq_no <= (self.last_gn_subseq_no[inst_id] + self.gn_window_size))
        except Exception as inst:
            logger.critical("Exception in in_expected_subseq_range: " + str(inst)+"\n\n")
    
   
    ##############################################################################
    # checks whether the subseq_no is in window range
    def subseq_no_within_gn_window(self, subseq_no):
        try:
            return 0 < subseq_no and subseq_no <= self.gn_window_size
        except Exception as inst:
            logger.critical("Exception in subseq_no_within_nc_window: " + str(inst)+"\n\n")
    
    
    
    ##############################################################################
    # checks whether new_session_id is valid or not
    def valid_new_session_id(self, old_session_id, new_session_id):
        try:
            if old_session_id:
                return self.in_expected_sessionseq_range(new_session_id, old_session_id)
            # if this GN is contacting the NC for the first time then accept any session_id
            return True
        except Exception as inst:
            logger.critical("Exception in valid_new_session_id: " + str(inst)+"\n\n")
    
    
    
    ##############################################################################
    def new_msg(self, msg):
        try:
            ret_val = False
            inst_id = msg.header.instance_id
            old_session_id = self.convert_to_int(self.get_old_session_id(inst_id, "GN Session ID"))
            new_session_id = self.convert_to_int(msg.header.sequence_id[:self.seq_no_partition_size])
            new_subseq_no = self.convert_to_int(msg.header.sequence_id[self.seq_no_partition_size:])
            # if any saved session id then
            # check whether saved one and new one match
            if old_session_id == new_session_id:
                # GN and NC are both up since they last contacted each other
                if self.last_gn_subseq_no[inst_id]:
                    if (self.in_expected_subseq_range(new_subseq_no)):
                        # check type
                        if msg.header.message_type == reply_type:
                            # check in sent_msgs bfr for corresponding msg
                            for msg in self.bfr_for_sent_msgs[inst_id]:
                                if msg[0] == msg.header.reply_to_id:                       # comparing the seq_no of bfrd msg with reply_id
                                    ret_val = True
                                    break
                        else:
                            match = 0
                            # check if its an old msg whose ACK was lost on the way
                            for response in self.bfr_for_sent_responses[inst_id]:                # comparing the seq_no of new msg with reply_id of bfrd response
                                if response[0] == msg.header.sequence_id:
                                    # resend response
                                    self.send_msg_to_gn(inst_id, response[1])
                                    match = 1
                                    break
                            # else its a new msg
                            if not match:
                                ret_val = True
                # GN is up but NC went down since they last contacted eachother so no record of session_seq_no found 
                else:
                    ret_val = True
            # check whether new session id falls in the expected range and the new seq_no is [0,0,0]/in the GN window range
            elif self.valid_new_session_id(old_session_id, new_session_id) and self.subseq_no_within_gn_window(new_subseq_no):            # in the window range
                # save new GN session_id 
                self.gn_session_id[inst_id] = self.convert_to_bytearray(new_session_id)
                self.save_session_id(inst_id, "GN Session ID", str(self.gn_session_id[inst_id]))
                ret_val = True
            return ret_val 
        except Exception as inst:
            logger.critical("Exception in new_msg: " + str(inst)+"\n\n")
    
        
    ##############################################################################    
    # Based on msg_type and sometimes msg_content, it decides how long it should wait for the ACK
    def calculate_expiration_time(self, msg_type, msg):
        try:
            if msg_type == command_type:
                wait_time = command_ack_wait_time
            logger.debug("Calculated expiration_time based on msg_type and msg.\n\n")
            return (time.time() + wait_time)
        except Exception as inst:
            logger.critical("Exception in calculate_expiration_time: " + str(inst)+"\n\n")
  
  
    ###############################################################################
    def increment_no(self, int_no):
        integer_no = copy.copy(int_no)
        try:
            if integer_no == 16777215:
               integer_no = 1
            else:
                integer_no += 1
        except Exception as inst:
            logger.critical("Exception in increment_no: " + str(inst)+ "\n\n")
        return integer_no
    
      
    ##############################################################################
    # initializes the handler_vector_table by mapping handler nos with the names
    def initialize_handler_vector_table(self):
        try:
            # initialize handler_vector_table by mapping handler no with handler name
            self.handler_vector_table[self.cmd_msg_handler_no] = self.cmd_msg_handler 
            logger.debug("Handler vector table initialized.\n\n")
        except Exception as inst:
            logger.critical("Exception in initialize_handler_vector_table: " + str(inst)+"\n\n")

        
     
    ##############################################################################
    # Based on msg_type it decides which handler should be called in the event of an ACK or no ACK
    def get_msg_handler_no(self, msg_type):
        try:
            if msg_type == command_type:
                # Registration is already done so use the next session no and seq_no = 0
                logger.debug("Fetching cmd msg handler no.\n\n")
                return self.cmd_msg_handler_no
        except Exception as inst:
            logger.critical("Exception in get_msg_handler_no: " + str(inst)+"\n\n")
        
     
    ##############################################################################
    def cmd_msg_handler(self, msg_info, inst_id, reply=None):
        try:
            logger.debug("Cmd msg handler called.\n\n")
            if reply:
                for single_response in reply.payloads:
                    if single_response.output == acknowledgment and not single_response.return_value:
                        logger.info("\t\tCMD ACK RECEIVED.\n\n")
                    else:
                        logger.critical("Unknown ACK received: Discarding..\n\n")
                return
            # handle failure
            logger.critical("Cmd Packet timeout........\n\n")
            msg_info[1] = self.calculate_expiration_time(data_type, None)
            self.add_to_sent_msgs_bfr(msg_info, inst_id)
            self.send_msg_to_gn(inst_id, msg_info[2])
            logger.info("Msg to NCR:" + str(msg_info[2])+"\n\n")
            logger.critical("Cmd msg resent......"+"\n\n")
        except Exception as inst:
            logger.critical("Exception in data_msg_handler: " + str(inst)+ "\n\n")
        
                
   