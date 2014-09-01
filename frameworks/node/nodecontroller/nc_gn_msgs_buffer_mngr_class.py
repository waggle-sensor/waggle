from waggle.device.node_controller.send_msg import send_msg
from global_imports import *
from nc_global_definition_section import buffered_msg,  msg_send,  msg_from_gn,  \
registration_type,  reply_type,  terminator,  gn_socket_list, logger, \
config_file_name, get_instance_id,  add_to_thread_buffer, wait_time_for_next_msg
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
        self.in_to_out_buffer = Queue.Queue(maxsize=1000)                                                       # stores all incoming as well as outgoing msgs and also internal msgs
        self.out_to_in_buffer = Queue.Queue(maxsize=1000) 
        
        self.msg_processor = ''                                                               # to save global msg_processor's input_buffer address
        self.sorted_output_msg_buffer = []
        self.reg_msg_handler_no = 0
        self.handler_vector_table = {}  
        self.log_file_name = "NC_msg_log"
        self.last_nc_seq_no = {}
        self.gn_highest_seq_no = {}
        self.gn_lowest_seq_no = {}
        self.initial_session_id = bytearray([255, 255, 255])
        self.initial_session_seq_no = bytearray([255, 255, 255])
        self.seq_no_partition_size = 3 
        self.error_scope = 100
        self.gn_window_size = 1
        self.nc_window_size = 1
        self.registered_nodes = []
        self.last_nc_seq_no['cloud'] = self.initialize_nc_to_cloud_seq_no()
        self.gn_instid_socket_obj_mapping = {}                                                # Dict maintaining gn_id and socket mapping
        logger.debug(self.thread_name+" Initialized."+"\n\n")

       
    ##############################################################################
    def pass_thread_address(self, msg_processor):
        self.msg_processor = msg_processor
        logger.debug("Address of msg processor saved."+"\n\n")
   
       
    ##############################################################################
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name+"\n\n")
            wait_time = time.time() + wait_time_for_next_msg                                                              # wait for 5ms for any msg
            while True:
                while not self.out_to_in_buffer.empty() or not self.in_to_out_buffer.empty():
                    #print "MSG Received........................................................................................................"
                    if not self.in_to_out_buffer.empty() and not self.is_output_buffer_full():
                        item = self.in_to_out_buffer.get()
                        # Send the message to internal_communicator's output_buffer to send it to GN only if the msg is an ACK or the output buffer is not full (this check is for lock step protocol)
                        logger.debug("Message to send to GN/Cloud received.:" + "\n\n")
                        encoded_msg = self.gen_msg(item)
                        if encoded_msg:
                            if item.inst_id != 'cloud':
                                encoded_msg = encoded_msg + terminator
                                socket_obj = self.get_socket_obj(item.inst_id)
                                if socket_obj:
                                    socket_obj.push(encoded_msg)                                                  # Pushes the msg to the appropriate internal_communicator object's buffer which looks over the socket associated with the specific GN
                                    logger.critical("Msg sent to GN:"+str('%0.4f' % time.time())+"\n\n")#logger.info("Msg to GN! "+"\n\n")#+str(item.inst_id)+" Msg sent: "+ encoded_msg + "\n\n" )
                                else:
                                    logger.critical("GN's socket closed. So discarding the msg------------------------------------------------------------."+ "\n\n")
                            else:
                                    logger.info("Msg sent to Cloud!"+"\n\n") # + (encoded_msg)+"\n\n")
                                    ret = self.send_msg_to_cloud(encoded_msg)                                                             # send msg to cloud
                                    # need to handle the failure case
                                    if not ret:
                                        self.process_ack(item.msg_type)
                        else:
                            logger.critical("Nonetype Msg discarded."+"\n\n")
                        self.in_to_out_buffer.task_done()
                    # Received message from GN so send it to msg_processor's input_buffer for processing
                    if not self.out_to_in_buffer.empty():
                        item = self.out_to_in_buffer.get()
                        # msg from cloud/gn received
                        logger.debug("  Msg from GN! "+"\n\n") #+ str(item.msg) + "\n\n")
                        decoded_msg = Message.decode(item.msg)
                        if (not self.new_node(decoded_msg.header.instance_id)) | (decoded_msg.header.message_type == registration_type):
                            msg_state = self.get_msg_state(decoded_msg.header.instance_id, decoded_msg.header.sequence_id)
                            if msg_state == 'wrong':
                                logger.critical("OLD MSG DISCARDED.........................................................................................\n\n")
                            # don't process the msg just send ack #TODO add the acks in output buffer before sending so that you are sure the msg has been processed before, this ack is put once the ack is received from msg_processor thread
                            elif msg_state == 'dup':
                                logger.critical("DUPLICATE MSG DISCARDED...................................................................................\n\n")
                                decoded_msg.payloads = None
                            if msg_state != 'wrong':
                                # save the new seq_no from that GN
                                self.gn_highest_seq_no[decoded_msg.header.instance_id] = decoded_msg.header.sequence_id
                                if self.new_socket(decoded_msg.header.instance_id, item.inst_id):
                                    self.gn_instid_socket_obj_mapping[decoded_msg.header.instance_id] = item.inst_id
                                if decoded_msg.header.instance_id not in self.last_nc_seq_no:
                                    self.last_nc_seq_no[decoded_msg.header.instance_id] = self.initialize_nc_to_gn_seq_no(decoded_msg.header.instance_id)
                                if decoded_msg.header.message_type != reply_type:
                                    item = buffered_msg(item.internal_msg_header, decoded_msg.header.message_type, decoded_msg.header.sequence_id, decoded_msg.header.reply_to_id, decoded_msg.payloads, decoded_msg.header.instance_id)
                                    add_to_thread_buffer(self.msg_processor.input_buffer, item, 'Msg_Processor')                                             # Sends to the msg_processor's buffer
                        else:
                            logger.critical("UNKNOWN GN SO MSG DISCARDED.........................................."+ "\n\n")
                        # TODO: If msg is just an ACK then don't forward it, copy this portion from GN's code, take care of extra inst_id with seq_no in unack_msg_info here
                        self.out_to_in_buffer.task_done()
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
    def is_output_buffer_full(self):
        # here window size can be checked 
        return len(self.sorted_output_msg_buffer) == self.nc_window_size
        
    ############################################################################## 
    def new_socket(self, gn_id, socket):
        if socket in gn_socket_list:
            if (gn_id in self.gn_instid_socket_obj_mapping) and (socket == self.gn_instid_socket_obj_mapping[gn_id]):
                return False
        return True
    
    
    ##############################################################################
    def initialize_nc_to_cloud_seq_no(self):
        return self.initialize_seq_no('cloud')

        
    ##############################################################################
    def initialize_nc_to_gn_seq_no(self, inst_id):
        return self.initialize_seq_no(inst_id)
    
    
    ############################################################################## 
    def process_ack(self, msg_type):
        if msg_type == registration_type:
            self.process_reg_ack()
            
            
    ############################################################################## 
    def process_reg_ack(self):
        config = ConfigObj(config_file_name)
        if config["Registered"] == 'NO':
            config["Registered"] = 'YES'
        for node in config["GN Info"]:
            if config['GN Info'][node]["Registered"] == 'NO':
                config['GN Info'][node]["Registered"] = 'YES'
        config.write()
        
        
    ##############################################################################
    def convert_to_int(self, byte_id):
        byte_id = bytearray(byte_id)
        length = len(byte_id)
        int_id = sum(byte_id[i] << ((length-1-i) * 8) for i in range(length))
        return int_id
    
    
    ##############################################################################
    def is_wrap_up(self, new_id, old_id):
        new_id = self.convert_to_int(new_id)
        old_id = self.convert_to_int(old_id)
        return new_id < (old_id - self.error_scope)
        
    ##############################################################################
    def is_new_id_greater(self, new_id, old_id):
        new_id = self.convert_to_int(new_id)
        old_id = self.convert_to_int(old_id)
        return new_id > old_id
    
    
    ##############################################################################
    # session_id (not <) old_session_id-10 so either == or > or wrap up occured so good
    def in_expected_range(self, new_id, old_id):
        # check for session_id very near to 0.0.0.0 because in that case self.error_scope may give wrong results
        # self.error_scope shows the range of session_id whihch may be old and should be discarded
        return self.is_new_id_greater(new_id, old_id) or self.is_wrap_up(copy.deepcopy(new_id), copy.deepcopy(old_id))
    
    
    ##############################################################################
    def check_session_seq_no(self, new_session_seq_no, inst_id):
            if (self.increment_byte_seq(self.gn_highest_seq_no[inst_id][self.seq_no_partition_size:]) == new_session_seq_no): # or falls in the GN window call within gn_window
                return 'correct'
            elif (self.gn_highest_seq_no[inst_id][self.seq_no_partition_size:] == new_session_seq_no):
                # first check the msg is actually duplicate by checking whether its present in the output buffer, erroneous case: the msg_processor thread might have crashed before processing the msg
                return 'dup'
            else:
                # window thing may go here
                return 'wrong'
    
    
    ##############################################################################
    # checks whether the session_seq_no is null or not for lock step protocol, can be modified for window thing
    def session_seq_no_within_gn_window(self, session_seq_no):
        return session_seq_no == str(bytearray([0,0,0]))
    
    ##############################################################################
    # checks whether new_session_id is valid or not
    def valid_new_session_id(self, old_session_id, new_session_id):
        if old_session_id:
            return self.in_expected_range(new_session_id, old_session_id)
        # if this GN is contacting the NC for the first time then accept any session_id
        return True
    
    
    ##############################################################################
    def get_msg_state(self, inst_id, seq_id):
        ret_val = ''
        old_session_id = self.get_old_session_id(inst_id, "GN Session ID")
        new_session_id = seq_id[:self.seq_no_partition_size]
        # if any saved session id
        # check whether saved one and new one match
        if old_session_id == new_session_id:
            # GN and NC are both up since they last contacted each other
            if inst_id in self.gn_highest_seq_no:
                # check whether session_seq_no is new or old or duplicate
                ret_val = self.check_session_seq_no(seq_id[self.seq_no_partition_size:], inst_id)
            # GN is up but NC went down since they last contacted eachother so no record of session_seq_no found 
            else:
                ret_val = 'correct'
        # check whether new session id falls in the expected range and the new seq_no is [0,0,0]/in the GN window range
        elif self.valid_new_session_id(old_session_id, new_session_id) and self.session_seq_no_within_gn_window(seq_id[self.seq_no_partition_size:]):            # in the window range
            # save new GN session_id 
            self.save_session_id(inst_id, "GN Session ID", new_session_id)
            ret_val = 'correct'
        return ret_val   
            

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
            self.last_nc_seq_no[item.inst_id] = self.gen_nc_seq_no(item.inst_id)
            if self.last_nc_seq_no[item.inst_id]:
                header = MessageHeader()
                header.message_type = item.msg_type
                header.instance_id = get_instance_id()
                header.sequence_id = self.last_nc_seq_no[item.inst_id]
                header.reply_to_id = item.reply_id
                msg = Message()
                msg.header = header
                for each_msg in item.msg:
                    msg.append(each_msg)
                msg = msg.encode()  
                logger.debug("Msg Encoded."+"\n\n")
                return msg
            del self.last_nc_seq_no[item.inst_id]
            return None
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
        config = ConfigObj(self.log_file_name)
        # create an entry for the GN 
        if inst_id not in config:
            config[inst_id] = {}
        config[inst_id][tag_name] = session_id  
        config.write()
        logger.debug("For node new session_id written: " + str(config[inst_id][tag_name])+"\n\n")
                
    
    ##############################################################################
    def initialize_seq_no(self, inst_id):
        try:
            logger.debug("Initializing seq_no."+"\n\n")
            session_id = self.get_old_session_id(inst_id, "NC Session ID")
            if not session_id:
                session_id = str(self.initial_session_id)
            session_id = self.increment_byte_seq(session_id)
            self.save_session_id(inst_id, "NC Session ID", session_id)
            return (session_id + str(self.initial_session_seq_no))
        except Exception as inst:
            logger.critical("Exception in init_seq_no: " + str(inst)+ "\n\n")
    
    
    ##############################################################################
    #checks first in self.gn_highest_seq_no, if found then returns that else checks in log file for that inst_id entry if found returns that, else returns None 
    def get_old_session_id(self, inst_id, tag_name):
        try:
            if tag_name == 'GN Session ID' and inst_id in self.gn_highest_seq_no:
                    return (self.gn_highest_seq_no[inst_id])[:self.seq_no_partition_size]
            config = ConfigObj(self.log_file_name)
            if inst_id in config and tag_name in config[inst_id]:
                return config[inst_id][tag_name]
            return None
        except Exception as inst:
            logger.critical("Exception in get_old_session_id: " + str(inst)+ " for:" + inst_id + + "\n\n")
    
    ###############################################################################
    #def increment_byte_seq(self, byte_seq):
        #byte_seq = bytearray(byte_seq)
        #try:
            #for indx in range(len(byte_seq)-1, -1, -1):
                #if byte_seq[indx] == 255:
                    ## Reset
                    #byte_seq[indx] = 0
                #else:
                    #byte_seq[indx] = byte_seq[indx] + 1
                    #break
        #except Exception as inst:
            #logger.critical("Exception in increment_byte_seq: " + str(inst)+ "\n\n")
        #return str(byte_seq)
   

    ###############################################################################
    def increment_byte_seq(self, byte_seq):
        try:
            byte_seq = bytearray(byte_seq)
            length = len(byte_seq)
            integer_no = sum(byte_seq[i] << ((length-1-i) * 8) for i in range(length))
            if integer_no == 16777215:
               integer_no = 0
            else:
                integer_no += 1
            for i in range(length):
                byte_seq[i] = (integer_no >> ((length-1-i)*8)) & 0xff 
        except Exception as inst:
            logger.critical("Exception in increment_byte_seq: " + str(inst)+ "\n\n")
        return str(byte_seq)
   
     
    ##############################################################################
    # Increments the current sequence no which is maintained by NC to interact with each GN
    def gen_nc_seq_no(self, inst_id):
        try:
            if inst_id in self.last_nc_seq_no:
                session_seq_no = self.increment_byte_seq(self.last_nc_seq_no[inst_id][self.seq_no_partition_size:])
                seq_no = self.last_nc_seq_no[inst_id][:self.seq_no_partition_size] + session_seq_no
                logger.debug("SEQUENCE NO. generated: " + seq_no + "for Node:"+str(inst_id)+ "\n\n")
                return seq_no
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

