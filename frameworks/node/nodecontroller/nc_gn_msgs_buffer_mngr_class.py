
from nc_global_definition_section import *

# gn_msgs_buffer_mngr (object of gn_msgs_buffer_mngr_class): Sends the received messages to msg_processor's buffer and messages received from msg_processor to
# the respective socket connected to the specific guest node       
class gn_msgs_buffer_mngr_class(threading.Thread):
   
    logger = set_logging_level('gn_msgs_buffer_mngr_class') #logging.getLogger('gn_msgs_buffer_mngr_class') 
    #logger = logging.getLogger(None)   
    ##############################################################################  
    def __init__(self, thread_name):
       
        threading.Thread.__init__(self)
        self.thread_name = "Thread_" + thread_name                                            # used by logging module for printing messages related to this thread
        self.daemon = True
        self.msg_buffer = Queue.Queue(maxsize=1000)                                                       # stores all incoming as well as outgoing msgs and also internal msgs
        self.msg_processor = ''                                                               # to save global msg_processor's input_buffer address
        self.sorted_output_msg_buffer = []
        self.reg_msg_handler_no = 0
        self.handler_vector_table = {}  
        self.seq_no_id_mapping = {}
        self.initial_session_id = bytearray([255, 255, 255])
        self.initial_session_seq_no = bytearray([255, 255, 255])
        self.seq_no_partition_size = 3 
        self.seq_no_id_mapping['cloud'] = self.initialize_seq_no('cloud')
        self.last_gn_seq_no = {}
        self.gn_instid_socket_obj_mapping = {}                                                # Dict maintaining gn_id and socket mapping
        self.logger.debug(self.thread_name+" Initialized."+"\n\n")

       
    ##############################################################################
    def pass_thread_address(self, msg_processor):
        self.msg_processor = msg_processor
        self.logger.debug("Address of msg processor saved."+"\n\n")
   
       
    ##############################################################################
    def run(self):
        try:
            self.logger.debug("Starting " + self.thread_name+"\n\n")
            # Waits on the buffer till a msg is received      
            while True:
                if not self.msg_buffer.empty():
                    item = self.msg_buffer.get()
                    if item.internal_msg_header == msg_send:                                                           # Send the message to internal_communicator's output_buffer to send it to GN
                        self.logger.debug("Message to send to GN/Cloud received.:" + "\n\n")
                        encoded_msg = self.gen_msg(item)
                        if encoded_msg:
                            if item.inst_id != 'cloud':
                                encoded_msg = encoded_msg + terminator
                                socket_obj = self.get_socket_obj(item.inst_id)
                                if socket_obj:
                                    socket_obj.push(encoded_msg)                                                  # Pushes the msg to the appropriate internal_communicator object's buffer which looks over the socket associated with the specific GN
                                    self.logger.info("Msg to GN: "+str(item.inst_id)+" Msg sent: "+ encoded_msg + "\n\n" )
                                else:
                                    self.logger.critical("GN's socket closed. So discarding the msg------------------------------------------------------------."+ "\n\n")
                            else:
                                    self.logger.info("Msg sent to Cloud:" + (encoded_msg)+"\n\n")
                                    self.send_msg_to_cloud(encoded_msg)                                                             # send msg to cloud
                        else:
                            self.logger.critical("Nonetype Msg discarded."+"\n\n")
                    # Received message from GN so send it to msg_processor's input_buffer for processing
                    elif item.internal_msg_header == msg_from_gn:                                                                   # msg from cloud/gn received
                        self.logger.debug("  Msg from GN: " + str(item.msg) + "\n\n")
                        decoded_msg = Message.decode(item.msg)
                        if (not self.new_node(decoded_msg.header.instance_id)) | (decoded_msg.header.message_type == registration_type):
                            action = self.get_action(decoded_msg.header.instance_id, decoded_msg.header.sequence_id)
                            if action == 'discard':
                                self.logger.info("OLD MSG DISCARDED.........................................................................................\n\n")
                                continue
                            elif action == 'dup':
                                self.logger.info("DUPLICATE MSG DISCARDED. SENDING ACK........................................................................................\n\n")
                                decoded_msg.payloads = None
                            if item.inst_id in gn_socket_list and (item.inst_id not in self.gn_instid_socket_obj_mapping):
                                self.gn_instid_socket_obj_mapping[decoded_msg.header.instance_id] = item.inst_id
                            if decoded_msg.header.instance_id not in self.seq_no_id_mapping:
                                self.seq_no_id_mapping[decoded_msg.header.instance_id] = self.initialize_seq_no(decoded_msg.header.instance_id)
                            item = buffered_msg(item.internal_msg_header, decoded_msg.header.message_type, decoded_msg.header.sequence_id, decoded_msg.header.reply_to_id, decoded_msg.payloads, decoded_msg.header.instance_id)
                            add_to_thread_buffer(self.msg_processor.input_buffer, item, 'Msg_Processor')                                             # Sends to the msg_processor's buffer
                        else:
                            self.logger.critical("UNKNOWN GN SO MSG DISCARDED.........................................."+ "\n\n")
                            continue
                            # TODO: If msg is just an ACK then don't forward it, copy this portion from GN's code, take care of extra inst_id with seq_no in unack_msg_info here
                    self.msg_buffer.task_done()
                time.sleep(0.01)
        except Exception as inst:
            self.logger.critical("Exception in gn_msgs_bufr_mngr run: " + str(inst)+ "\n\n")
            self.run()
    
    
    #checks first in self.last_gn_seq_no, if found then returns that else checks in log file for that inst_id entry if found returns that, else returns None 
    def get_last_gn_session_id(self, inst_id):
        if inst_id in self.last_gn_seq_no:
            return (self.last_gn_seq_no[inst_id])[:self.seq_no_partition_size]
        config = ConfigObj(get_log_file_name())
        if inst_id in config['GN session_id']:
            return config['GN session_id'][inst_id]
        return None
    
        
          
    # session_id (not <) old_session_id-10 so either == or > or wrap up occured so good
    def expected_session_id(self, old_id, new_id, inst_id):
        if new_id > old_id or (new_id < (old_id - self.error_scope)):
            
            return True
        return False
    
    
    # Returns false if new session_seq_no is greater by more than 1 than the expected no 
    def expected_session_seq_no(new_session_seq_no):
        if inst_id in self.last_gn_seq_no:
            if ((self.last_gn_seq_no[self.seq_no_partition_size:]+1) == new_session_seq_no):
                return True
            return False
        return True
    
    
    def get_action(self, inst_id, seq_id):
        # Since NC is up, atleast once this GN has contacted it
        if inst_id in self.last_gn_seq_no:
            # GN might have gone down since last interaction so expected_session_id and new_session_id differ
            if self.get_last_gn_session_id(inst_id) != seq_id[:self.seq_no_partition_size]:
                # check whether the msg is not an old packet with an old session id
                if self.expected_session_id(self.get_last_gn_session_id(inst_id), seq_id[:self.seq_no_partition_size]) and seq_id[:self.seq_no_partition_size] == bytearray([0,0,0]):
                    # change id in log_file
                    config = ConfigObj(get_log_file_name())
                    config['GN session_id'][inst_id] = new_id
                    config.write()
                    ret_val = 'process_new_msg'
                else:
                    self.logger.debug('WRONG MSG RECEIVED. DISCARDING........................................................................\n\n')
                    ret_val = 'discard'
            # GN is still up since last communication
            else:
                # check for valid session_seq_no
                if increment_byte_seq(self.last_gn_seq_no[inst_id]) == seq_id:
                    ret_val = 'process_new_msg'
                elif (self.last_gn_seq_no[inst_id] == seq_id):
                    ret_val = 'dup'
                else:
                    ret_val = 'discard'
        elif self.expected_session_id(self.get_last_gn_session_id(inst_id), seq_id[:self.seq_no_partition_size]) and seq_id[:self.seq_no_partition_size] == bytearray([0,0,0]):
            
        
            
            
        if :
            
        elif :
            # save the new seq_no from that GN
            self.last_gn_seq_no[decoded_msg.header.instance_id] = decoded_msg.header.sequence_id
            #self.logger.info("Socket allocated: " + str(self.gn_instid_socket_obj_mapping)+"\n\n")
            
            
    ##############################################################################  
    def is_socket_available(self, inst_id):
        #self.logger.info("Socket-ID List:" + str(self.gn_instid_socket_obj_mapping)+"\n\n")
        return (inst_id in self.gn_instid_socket_obj_mapping)
   
   
    ##############################################################################  
    def clean_gn_data(self, del_socket):
        inst_id = ''
        for gn_id, socket in self.gn_instid_socket_obj_mapping.items():
                if socket == del_socket:
                    inst_id = gn_id
                    break
        del self.gn_instid_socket_obj_mapping[inst_id]
        #del self.seq_no_id_mapping[inst_id]
        self.logger.info("Socket and seq_no entry removed from id_socket mapping.\nSocket-ID Map:\t"+str(self.gn_instid_socket_obj_mapping)+"\nSeq-ID Map:\t"+\
                           str(self.seq_no_id_mapping)+ "\n\n")
                       
   
    ##############################################################################   
    def gen_msg(self, item):
        try:
            self.seq_no_id_mapping[item.inst_id] = self.gen_seq_no(item.inst_id)
            if self.seq_no_id_mapping[item.inst_id] != None:
                header = MessageHeader()
                header.message_type = item.msg_type
                header.instance_id = get_instance_id()
                header.sequence_id = self.seq_no_id_mapping[item.inst_id]
                header.reply_to_id = item.reply_id
                msg = Message()
                msg.header = header
                for each_msg in item.msg:
                    msg.append(each_msg)
                msg = msg.encode()  
                self.logger.debug("Msg Encoded."+"\n\n")
                return msg
            del self.seq_no_id_mapping[item.inst_id]
            return None
        except Exception as inst:
            self.logger.critical("Exception in gen_msg: " + str(inst)+"\n\n")
           
       
    ##############################################################################
    def send_msg_to_cloud(self, encoded_msg):
        try:
            send_msg(encoded_msg)                                                             # send msg to cloud
            self.logger.info('Msg sent to cloud successfully.'+ "\n\n")
        except Exception as inst:
            self.logger.critical("Exception in send_msg_to_cloud: " + str(inst)+ "\n\n")
            self.logger.critical("Retrying after 1 secs."+ "\n\n")
            time.sleep(1)
            self.send_msg_to_cloud(encoded_msg)
   
   
    ##############################################################################
    # Checks whether a GN is new or not by checking entries in registered nodes or reading config file, if entry is presentin config file but not in registered nodes then it adds that node to registered_nodes list
    def new_node(self, inst_id):
        try:
            if inst_id in self.registered_nodes:
                self.logger.debug("Node is already known."+"\n\n")
                return False
            # Check in config file for the inst_id
            config = ConfigObj(get_log_file_name())
            if inst_id in config:
                self.logger.debug("Node is already known."+"\n\n")
                self.registered_nodes.append(inst_id)
                return False
            self.logger.debug("New node."+"\n\n")
            return True
        except Exception as inst:
            self.logger.critical("Exception in new_node: " + str(inst)+ "\n\n")
           
       
    ##############################################################################
    def initialize_seq_no(self, inst_id):
        try:
            self.logger.debug("Initializing seq_no."+"\n\n")
            config = ConfigObj(get_log_file_name())
            if self.new_node(inst_id):
                session_id = copy.deepcopy(self.initial_session_id)
                config[inst_id] = {}
            else:
                self.logger.debug("Node already present in the records."+"\n\n")
                session_id = self.get_session_id(inst_id)
            session_id = self.increment_byte_seq(session_id)
            config[inst_id]["Session ID"] = session_id  
            config.write()
            self.logger.debug("For node new session_id written: " + str(config[inst_id]["Session ID"])+"\n\n")
            return (str(session_id + self.initial_session_seq_no))
        except Exception as inst:
            self.logger.critical("Exception in init_seq_no: " + str(inst)+ "\n\n")
           
       
    ##############################################################################
    def get_session_id(self, inst_id):
        try:
            # Read from log file the last session_id
            config = ConfigObj(get_log_file_name())
            self.logger.debug("Session_id read from the file: " + str(config[inst_id]["Session ID"])+"\n\n")
            return config[inst_id]["Session ID"]
        except Exception as inst:
            self.logger.critical("Exception in get_session_id: " + str(inst)+ "\n\n")
           
       
    ##############################################################################
    def increment_byte_seq(self, byte_seq):
        byte_seq = bytearray(byte_seq)
        try:
            for indx in range(len(byte_seq)-1, -1, -1):
                if byte_seq[indx] == 255:
                    # Reset
                    byte_seq[indx] = 0
                else:
                    byte_seq[indx] = byte_seq[indx] + 1
                    break
        except Exception as inst:
            self.logger.critical("Exception in increment_byte_seq: " + str(inst)+ "\n\n")
        return str(byte_seq)
   
     
    ##############################################################################
    # Increments the current sequence no which is maintained by NC to interact with each GN
    def gen_seq_no(self, inst_id):
        try:
            if inst_id in self.seq_no_id_mapping:
                seq_no = self.seq_no_id_mapping[inst_id][:self.seq_no_partition_size]
                seq_no[1] = self.increment_byte_seq(seq_no[1])
                seq_no = seq_no[0] + seq_no[1]
                self.logger.debug("SEQUENCE NO. generated: " + seq_no + "for Node:"+str(inst_id)+ "\n\n")
                return seq_no
            return None
        except Exception as inst:
            self.logger.critical("Exception in gen_seq_no: " + str(inst)+ "\n\n")
           
       
    ##############################################################################   
    # Returns the internal_communicator object corresponding to the gn represented by gn_id = (gn_ip, gn_port)         
    def get_socket_obj(self, gn_id):
        try:
            self.logger.debug("Socket object corresponding to specific GN retreived."+ "\n\n")
            if gn_id in self.gn_instid_socket_obj_mapping:
                if self.gn_instid_socket_obj_mapping[gn_id] in gn_socket_list:
                    return self.gn_instid_socket_obj_mapping[gn_id]
                else:
                    del self.gn_instid_socket_obj_mapping[gn_id]
            return None
        except Exception as inst:
            self.logger.critical("Exception in get_socket_obj: " + str(inst)+ "\n\n")
           
       
    ##############################################################################
    def __del__(self):
        print self, 'gn_msgs_bufr_mngr object died.'

