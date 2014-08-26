from gn_external_communicator_class import external_communicator_class
from gn_global_definition_section import *
from commands import getoutput as bashit

##################################################################################
# Buffer manager discards any ACK which is unexpected ie. which does not have any corresponding waiting msg in sorted_output_msg_buffer
##################################################################################

# buffer_mngr (object of buffer_mngr_class): Sends msgs from main_thread and sensor_controller threads to the external_communicator thread
# and dispatches msgs from NC/GNs to appropriate threads by examining the msg_type or if needed then seq_no
class buffer_mngr_class(threading.Thread):
    
    logger = set_logging_level("buffer_mngr")
    
    ##############################################################################
    def __init__(self, thread_name, nc_ip, nc_port):
        threading.Thread.__init__(self)
        self.thread_name = thread_name                  # used for tagging the msgs related to this thread
        self.daemon = True
        self.msg_buffer = Queue.Queue(maxsize=1000)                 # stores all incoming as well as outgoing msgs coming from sensor_controller_class, main_class, external_communicator_class and also any internal msg intended for buffer_mngr_class
        self.nc_ip = nc_ip                              # to pass to the external_communicator_class
        self.nc_port = nc_port                          # port at which NC listens for incoming requests, to be passed to the external_communicator_class
        self.main_thread_ = ''
        self.sensor_controller = ''
        self.external_communicator = ''
        self.communicator_thread_started = 0
        self.sorted_output_msg_buffer = [] 
        self.reg_msg_handler_no = 0
        self.data_msg_handler_no = 1
        self.handler_vector_table = {}                 
        self.seq_no_delimiter = str(unicode(280))
        self.initial_session_id = bytearray([255, 255, 255])
        self.initial_session_seq_no = bytearray([255, 255, 255])
        self.seq_no = self.initialize_seq_no()
        self.initialize_handler_vector_table()
        self.logger.debug("Thread "+self.thread_name+" Initialized.\n\n")
            
    
    ##############################################################################
    # initializes the handler_vector_table by mapping handler nos with the names
    def initialize_handler_vector_table(self):
        # initialize handler_vector_table by mapping handler no with handler name
        self.handler_vector_table[self.reg_msg_handler_no] = self.reg_msg_handler 
        self.handler_vector_table[self.data_msg_handler_no] = self.data_msg_handler
        self.logger.debug("Handler vector table initialized.\n\n")
        
        
    ##############################################################################
    def initialize_seq_no(self):
        session_id = self.get_session_id()
        if not session_id:
            session_id = copy.deepcopy(self.initial_session_id)
        self.increment_byte_seq(session_id)
        config = ConfigObj(get_log_file_name())
        config["Session_ID"] = str(session_id)
        config.write()
        self.logger.debug("Seq_no. initialized.\n\n")
        return (str(session_id + self.seq_no_delimiter + self.initial_session_seq_no))
        
        
    ##############################################################################
    def run(self):
        try:
            self.logger.debug("Starting " + self.thread_name + "\n\n")
            # Creates new thread
            if not self.communicator_thread_started:
                self.external_communicator = external_communicator_class("external_communicator", self.nc_ip, self.nc_port, self) 
                # Starts new Thread
                self.external_communicator.start()
                self.communicator_thread_started = 1
            # Waits on the msg_buffer till a msg is received       
            while True:
                if not self.msg_buffer.empty():
                    item = self.msg_buffer.get()
                    if item.internal_msg_header == msg_to_nc:
                        #if not NC_down:
                        encoded_msg = self.gen_msg(item)
                        encoded_msg = encoded_msg + terminator
                        if item.msg_type != reply_type:
                            expiration_time = self.calculate_expiration_time(item.msg_type, item.msg)
                            msg_handler_no = self.get_msg_handler_no(item.msg_type)
                            unacknowledged_msg_handler_info = [self.seq_no, expiration_time, encoded_msg, msg_handler_no]   # contains seq_no, expiration_time, registration msg, handler no corresponding to the handler which will be called when this msg times out or acknowledged
                            add_to_sorted_output_buffer(self.sorted_output_msg_buffer, unacknowledged_msg_handler_info)
                        self.external_communicator.push(encoded_msg)                                                               # pushes to the output buffer of external_communicator_class
                        if item.msg_type != registration_type:
                            self.logger.info("Msg to NCR:" + str(encoded_msg)+"\n\n")
                        #else:
                            #self.logger.critical("\n\nNC's socket closed. So buffering the msg.")
                            #time.sleep(5)
                    # Pushes all received_external_msg msgs to either main_thread's buffer or sensor_controller's buffer
                    elif item.internal_msg_header == msg_from_nc:
                        self.logger.debug("Msg from NCR:" + str(item.msg) + "\n\n")
                        self.logger.debug("Output Buffer: " + str(self.sorted_output_msg_buffer) + "\n\n")
                        decoded_msg = Message.decode(item.msg)
                        # Can contain multiple payloads
                        #TODO if decoded_msg.header.sequence_id < received_seq_no
                        for single_payload in decoded_msg.payloads:
                            item = buffered_msg(item.internal_msg_header, decoded_msg.header.message_type, decoded_msg.header.sequence_id, decoded_msg.header.reply_to_id, single_payload)
                            # reply so handled by this thread
                            if decoded_msg.header.message_type == reply_type:
                                # based on reply_id it gets the corresponding thread instance and sends to its input_buffer
                                # thread_inst = self.get_thread_inst(msg.reply_id)
                                msg_info = get_msg_info_and_delete_from_output_buffer(self.sorted_output_msg_buffer, decoded_msg.header.reply_to_id)         # removes the msg_info from output sorted msg queue and returns it 
                                if msg_info:
                                    self.handler_vector_table[msg_info[3]](msg_info[2], decoded_msg)        # calls the handler whose no is stored in the msg_info at index 3 and passes the original msg and the reply received
                                else:
                                    self.logger.critical("ACK Discarded................................................................................\n\n")
                            else:
                                self.logger.critical("Unknown Msg Received: Discarding the msg.\n\n")
                    else:
                        self.logger.critical("Unknown Msg received: Discarding...\n\n")
                    self.msg_buffer.task_done()
                # Check in output_buffer for pending registration msg and if that msg has timed out
                # Extract msg info and change the registration handler function to resend the msg by preparing a buffer msg and inserting in the bufr mngr's queue
                timed_out_msg_info = get_timed_out_msg_info(self.sorted_output_msg_buffer) 
                if timed_out_msg_info:
                    self.handler_vector_table[timed_out_msg_info[3]](timed_out_msg_info, None) 
                time.sleep(0.01)
        except Exception as inst:
            self.logger.critical("Exception in bufr_mngr run: " + str(inst) + "\n\n")
            self.logger.critical("Waiting for socket to get closed.")
            time.sleep(2)
            if not self.external_communicator.isAlive():
                self.logger.critical("External Communicator dead.")
                self.communicator_thread_started = 0
            else:
                self.logger.critical("External Communicator not dead.")
            self.run()
                
                
    ##############################################################################
    def close(self):
        self.external_communicator.shutdown = 1
        self.external_communicator.handle_close()
        self.external_communicator.join(1)
            
            
    ##############################################################################
    # Based on msg_type it decides which handler should be called in the event of an ACK or no ACK
    def get_msg_handler_no(self, msg_type):
        if msg_type == registration_type:
            # Registration is already done so use the next session no and seq_no = 0
            self.logger.debug("Fetching registration msg handler no.\n\n")
            return self.reg_msg_handler_no
        elif msg_type == data_type:
            # Registration is already done so use the next session no and seq_no = 0
            self.logger.debug("Fetching data msg handler no.\n\n")
            return self.data_msg_handler_no
        
        
    ##############################################################################    
    # Based on msg_type and sometimes msg_content, it decides how long it should wait for the ACK
    def calculate_expiration_time(self, msg_type, msg):
        if msg_type == registration_type:
            wait_time = gn_registration_ack_wait_time
        elif msg_type == data_type:
            wait_time = data_ack_wait_time
        self.logger.debug("Calculated expiration_time based on msg_type and msg.\n\n")
        return add_to_current_time(wait_time)

    
    ##############################################################################    
    def get_session_id(self):
        if os.path.exists(get_log_file_name()):
            # Read from log file the last session_id
            config = ConfigObj(get_log_file_name())
            if config["Session_ID"]:
                self.logger.debug("Session_id read from the file: " + str(config["Session_ID"]) + "\n\n")
                return bytearray(config["Session_ID"])
        self.logger.debug("No session_id.\n\n")
        return None
    
    
    ##############################################################################
    def gen_msg(self, item):
        try:
            self.gen_seq_no()
            header = MessageHeader()
            header.instance_id = get_instance_id()
            header.message_type = item.msg_type
            header.sequence_id = self.seq_no
            header.reply_to_id = item.reply_id
            msg = Message()
            msg.header = header
            msg.append(item.msg)
            msg = msg.encode()   
            return msg
        except Exception as inst:
            self.logger.critical("Exception in gen_msg: " + str(inst)+"\n\n")
            
    
    ##############################################################################
    # Increments the current sequence no which is maintained with NC
    def gen_seq_no(self):
        seq_no = self.seq_no.split(self.seq_no_delimiter)
        seq_no[1] = self.increment_byte_seq(bytearray(seq_no[1]))
        self.seq_no = str (seq_no[0] + self.seq_no_delimiter + seq_no[1])
        self.logger.debug("\tSEQUENCE NO. gen:" + str(bytearray(self.seq_no))+"\n\n")
        
        
    ##############################################################################
    def increment_byte_seq(self, byte_seq):
        try:
            for indx in range(len(byte_seq)-1, -1, -1):
                if byte_seq[indx] == 255:
                    # Reset
                    byte_seq[indx] = 0
                else:
                    byte_seq[indx] = byte_seq[indx] + 1
                    break
        except Exception as inst:
            self.logger.critical("Exception in increment_byte_seq: " + str(inst)+"\n\n")
        return byte_seq
    
      
    ##############################################################################   
    def pass_thread_address(self, main_thread, sensor_controller): 
        self.main_thread = main_thread
        self.sensor_controller = sensor_controller
        self.logger.debug("Addresses of main_thread and sensor_controller saved.\n\n")
    
    
    ##############################################################################
    def reg_msg_handler(self, msg_info, reply):
        self.logger.debug("Registration msg handler called.\n\n")
        if reply:
            for single_response in reply.payloads:
                if single_response.return_value == 0:
                    self.logger.info("\t\tRegistration ACK received.\n\n")
                    # change status to YES in config file
                    config = ConfigObj(get_config_file_name())
                    config["Registered"] = "YES"
                    config["UTC Time"] = single_response.output
                    bashit("date -s@"+str(single_response.output))
                    config.write()
                    start_communication_with_nc_event.set()
                    self.logger.info("Start_communication_with_nc_event is set.\n\n")
                else:
                    self.logger.critical("Unknown ACK received: Discarding..\n\n")
            return   
        # handle failure
        self.logger.critical("Registration timeout........\n\n")
        msg_info[1] = self.calculate_expiration_time(registration_type, None)
        add_to_sorted_output_buffer(self.sorted_output_msg_buffer, msg_info)
        self.external_communicator.push(msg_info[2])
        self.logger.info("Msg to NCR:" + str(msg_info[2])+"\n\n")
        self.logger.critical("Registration msg resent......"+"\n\n")
        
     
    ##############################################################################
    def data_msg_handler(self, msg_info, reply):
        self.logger.debug("Data msg handler called.\n\n")
        if reply:
            for reply in reply.payloads:
                if reply.output == acknowledgment:
                    self.logger.info("\t\tData ACK received.\n\n")
                else:
                    self.logger.critical("Unknown ACK received: Discarding..\n\n")
            return
        # handle failure
        self.logger.critical("Data Packet timeout........\n\n")
        msg_info[1] = self.calculate_expiration_time(data_type, None)
        add_to_sorted_output_buffer(self.sorted_output_msg_buffer, msg_info)
        self.external_communicator.push(msg_info[2])
        self.logger.info("Msg to NCR:" + str(msg_info[2])+"\n\n")
        self.logger.critical("Data msg resent......"+"\n\n")
                
            
     
    ##############################################################################
    def __del__(self):
        print self, 'bufr_mngr object died'