from global_imports import *
from commands import getoutput as bashit
from gn_external_communicator_class import external_communicator_class

from gn_global_definition_section import get_instance_id,  add_to_sorted_output_buffer, \
get_msg_info_and_delete_from_output_buffer,  add_to_current_time, \
get_timed_out_msg_info,  msg_to_nc,  msg_from_nc,  start_communication_with_nc_event, \
registration_type,  data_type,  reply_type,  acknowledgment,  terminator, \
gn_registration_ack_wait_time,  data_ack_wait_time, \
config_file_name, logger, wait_time_for_next_msg

from config_file_functions import initialize_config_file, ConfigObj

##################################################################################
# Buffer manager discards any ACK which is unexpected ie. which does not have
# any corresponding waiting msg in sorted_output_buffer
##################################################################################

# buffer_mngr (object of buffer_mngr_class): Sends msgs from main_thread and sensor_controller threads to the external_communicator thread
# and dispatches msgs from NC/GNs to appropriate threads by examining the msg_type or if needed then seq_no
class buffer_mngr_class(threading.Thread):
    
    
    ##############################################################################
    def __init__(self, thread_name, nc_port):
        threading.Thread.__init__(self)
        self.thread_name = thread_name                  # used for tagging the msgs related to this thread
        self.daemon = True
        self.in_to_out_buffer = Queue.Queue(maxsize=1000)     # stores all msgs coming from sensor_controller_class, main_class, external_communicator_class and also any internal msg intended for buffer_mngr_class
        self.out_to_in_buffer = Queue.Queue(maxsize=1000)      # stores all msgs coming from the external world
        self.nc_port = nc_port                          # port at which NC listens for incoming requests, to be passed to the external_communicator_class
        self.main_thread_ = ''
        self.sensor_controller = ''
        self.external_communicator = ''
        self.log_file_name = 'GN_msg_log'
        self.communicator_thread_started = 0
        self.sorted_output_buffer = [] 
        self.reg_msg_handler_no = 0
        self.data_msg_handler_no = 1
        self.handler_vector_table = {}                 
        self.initial_session_id = bytearray([255, 255, 255])
        self.initial_session_seq_no = bytearray([255, 255, 255])
        self.last_gn_seq_no = self.initialize_gn_seq_no()
        self.nc_highest_seq_no = ''
        self.nc_lowest_seq_no = ''
        self.gn_window_size = 1
        self.nc_window_size = 1
        self.seq_no_partition_size = 3                  # no of bytes of session_id
        self.wait_time = 0
        self.initialize_handler_vector_table()
        logger.debug("Thread "+self.thread_name+" Initialized.\n\n")
            
    
    ##############################################################################
    # initializes the handler_vector_table by mapping handler nos with the names
    def initialize_handler_vector_table(self):
        # initialize handler_vector_table by mapping handler no with handler name
        self.handler_vector_table[self.reg_msg_handler_no] = self.reg_msg_handler 
        self.handler_vector_table[self.data_msg_handler_no] = self.data_msg_handler
        logger.debug("Handler vector table initialized.\n\n")
     
     
    ##############################################################################
    def save_session_id(self, tag_name, session_id):
        config = ConfigObj(self.log_file_name)
        config[tag_name] = session_id  
        config.write()
     
        
    ##############################################################################
    def initialize_gn_seq_no(self):
        session_id = self.get_old_session_id('GN Session ID')
        if not session_id:
            session_id = str(self.initial_session_id)
        session_id = self.increment_byte_seq(session_id)
        self.save_session_id("GN Session ID", session_id)
        logger.debug("Seq_no. initialized.\n\n")
        return session_id + str(self.initial_session_seq_no)
    
        
    ##############################################################################
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name + "\n\n")
            count = 0
            # Creates new thread
            if not self.communicator_thread_started:
                self.external_communicator = external_communicator_class("external_communicator", self.nc_port, self) 
                # Starts new Thread
                self.external_communicator.start()
                self.communicator_thread_started = 1
            wait_time = time.time() + wait_time_for_next_msg
            wait_time_set = 1
            # Waits on the msg_buffer till a msg is received       
            while True:
                while (not self.out_to_in_buffer.empty()) or (not self.in_to_out_buffer.empty()):
                    if not self.out_to_in_buffer.empty():
                        item = self.out_to_in_buffer.get()
                        logger.debug("Msg from NCR:" + str(item.msg) + "\n\n")
                        logger.debug("Output Buffer: " + str(self.sorted_output_buffer) + "\n\n")
                        decoded_msg = Message.decode(item.msg)
                        msg_state = self.get_msg_state(decoded_msg.header.instance_id, decoded_msg.header.sequence_id)
                        if msg_state == 'wrong':
                            logger.critical("OLD MSG DISCARDED.........................................................................................\n\n")
                            # don't process the msg just send ack #TODO add the acks in output buffer before sending so that so that you are sure the msg has been processed before, this ack is put once the ack is received from msg_processor thread
                        elif msg_state == 'dup':
                            logger.critical("DUPLICATE MSG DISCARDED. SENDING ACK........................................................................................\n\n")
                            decoded_msg.payloads = None
                        if msg_state != 'wrong':
                            # save NC's new seq_no
                            self.nc_highest_seq_no = decoded_msg.header.sequence_id
                            if decoded_msg.header.message_type == reply_type:
                                msg_info = get_msg_info_and_delete_from_output_buffer(self.sorted_output_buffer, decoded_msg.header.reply_to_id)         # removes the msg_info from output sorted msg queue and returns it
                                if msg_info:
                                    self.handler_vector_table[msg_info[3]](msg_info[2], decoded_msg)        # calls the handler whose no is stored in the msg_info at index 3 and passes the original msg and the reply received
                                else:
                                    logger.critical("ACK Discarded................................................................................\n\n")
                        self.out_to_in_buffer.task_done()
                    if not self.in_to_out_buffer.empty() and not self.is_output_buffer_full():
                        item = self.in_to_out_buffer.get()
                        #if not NC_down:
                        encoded_msg = self.gen_msg(item)
                        encoded_msg = encoded_msg + terminator
                        if item.msg_type != reply_type:
                            expiration_time = self.calculate_expiration_time(item.msg_type, item.msg)
                            msg_handler_no = self.get_msg_handler_no(item.msg_type)
                            unacknowledged_msg_handler_info = [self.last_gn_seq_no, expiration_time, encoded_msg, msg_handler_no]   # contains seq_no, expiration_time, registration msg, handler no corresponding to the handler which will be called when this msg times out or acknowledged
                            add_to_sorted_output_buffer(self.sorted_output_buffer, unacknowledged_msg_handler_info)
                        self.external_communicator.push(encoded_msg)                                                           # pushes to the output buffer of external_communicator_class
                        logger.critical("Msg Sent to NC:"+str('%0.4f' % time.time())+"\n\n")# + str(encoded_msg)+"\n\n")
                        #else:
                            #logger.critical("\n\nNC's socket closed. So buffering the msg.")
                            #time.sleep(5)
                        self.in_to_out_buffer.task_done()
                    # Check in output_buffer for pending registration msg and if that msg has timed out
                    # Extract msg info and change the registration handler function to resend the msg by preparing a buffer msg and inserting in the bufr mngr's queue
                    timed_out_msg_info = get_timed_out_msg_info(self.sorted_output_buffer)
                    if timed_out_msg_info:
                        self.handler_vector_table[timed_out_msg_info[3]](timed_out_msg_info, None)
                    # set time to remain attentive for next 5 ms
                    wait_time = time.time() + wait_time_for_next_msg - .1               # this waits for .1 s only as its one level above the other threads
                    #print "short sleep bfr mngr"
                    time.sleep(0.0001)
                if wait_time > time.time():
                    #print "short sleep bfr mngr"
                    time.sleep(0.0001)
                else:
                    #print "long sleep bfr mngr"
                    time.sleep(0.1)
        except Exception as inst:
            logger.critical("Exception in bufr_mngr run: " + str(inst) + "\n\n")
            if not self.external_communicator.isAlive():
                logger.critical("External Communicator dead.")
                self.communicator_thread_started = 0
                logger.critical("Waiting for socket to get closed.")
                time.sleep(2)
            else:
                logger.critical("External Communicator not dead.")
            self.run()
                
                
    ##############################################################################
    def close(self):
        self.external_communicator.shutdown = 1
        self.external_communicator.handle_close()
        self.external_communicator.join(1)
     
    ############################################################################## 
    def is_output_buffer_full(self):
        # here window size can be checked 
        return len(self.sorted_output_buffer) == self.nc_window_size
    
    
    ##############################################################################
    def convert_to_int(self, byte_id):
        byte_id = bytearray(byte_id)
        int_id = sum(byte_id[i] << ((len(byte_id)-1-i) * 8) for i in range(len(byte_id)))
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
        # self.error_scope shows the range of session_id which may be old and should be discarded
        return self.is_new_id_greater(new_id, old_id) or self.is_wrap_up(copy.deepcopy(new_id), copy.deepcopy(old_id))
    
    
    ##############################################################################
    def check_session_seq_no(self, new_session_seq_no):
            if (self.increment_byte_seq(self.nc_highest_seq_no[self.seq_no_partition_size:]) == new_session_seq_no): # or falls in the GN window call within gn_window
                return 'correct'
            elif (self.nc_highest_seq_no[self.seq_no_partition_size:] == new_session_seq_no):
                # first check the msg is actually duplicate by checking whether its present in the output buffer, erroneous case: the msg_processor thread might have crashed before processing the msg
                return 'dup'
            else:
                # window thing may go here
                return 'wrong'
    
    
    ##############################################################################
    # checks whether the session_seq_no is null or not for lock step protocol, can be modified for window thing
    def session_seq_no_within_nc_window(self, session_seq_no):
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
        old_session_id = self.get_old_session_id("NC Session ID")
        new_session_id = seq_id[:self.seq_no_partition_size]
        # if any saved session id
        # check whether saved one and new one match
        if old_session_id == new_session_id:
            # GN and NC are both up since they last contacted each other
            if self.nc_highest_seq_no:
                # check whether session_seq_no is new or old or duplicate
                ret_val = self.check_session_seq_no(seq_id[self.seq_no_partition_size:])
            # GN is up but NC went down since they last contacted eachother so no record of session_seq_no found 
            else:
                ret_val = 'correct'
        # check whether new session id falls in the expected range and the new seq_no is [0,0,0]/in the GN window range
        elif self.valid_new_session_id(old_session_id, new_session_id) and self.session_seq_no_within_nc_window(seq_id[self.seq_no_partition_size:]):            # in the window range
            # save new GN session_id 
            self.save_session_id("NC Session ID", new_session_id)
            ret_val = 'correct'
        return ret_val   
  
  
    ##############################################################################
    # Based on msg_type it decides which handler should be called in the event of an ACK or no ACK
    def get_msg_handler_no(self, msg_type):
        if msg_type == registration_type:
            # Registration is already done so use the next session no and seq_no = 0
            logger.debug("Fetching registration msg handler no.\n\n")
            return self.reg_msg_handler_no
        elif msg_type == data_type:
            # Registration is already done so use the next session no and seq_no = 0
            logger.debug("Fetching data msg handler no.\n\n")
            return self.data_msg_handler_no
        
        
    ##############################################################################    
    # Based on msg_type and sometimes msg_content, it decides how long it should wait for the ACK
    def calculate_expiration_time(self, msg_type, msg):
        if msg_type == registration_type:
            wait_time = gn_registration_ack_wait_time
        elif msg_type == data_type:
            wait_time = data_ack_wait_time
        logger.debug("Calculated expiration_time based on msg_type and msg.\n\n")
        return add_to_current_time(wait_time)

    
    ##############################################################################    
    def get_old_session_id(self, tag_name):
        if tag_name == 'NC Session ID' and self.nc_highest_seq_no:
            return self.nc_highest_seq_no[:self.seq_no_partition_size]
        config = ConfigObj(self.log_file_name)
        if tag_name in config:
            return config[tag_name]
        return None
    
    ##############################################################################
    def gen_msg(self, item):
        try:
            self.gen_gn_seq_no()
            header = MessageHeader()
            header.instance_id = get_instance_id()
            header.message_type = item.msg_type
            header.sequence_id = self.last_gn_seq_no
            header.reply_to_id = item.reply_id
            msg = Message()
            msg.header = header
            msg.append(item.msg)
            msg = msg.encode()   
            return msg
        except Exception as inst:
            logger.critical("Exception in gen_msg: " + str(inst)+"\n\n")
            
    
    ##############################################################################
    # Increments the current sequence no which is maintained with NC
    def gen_gn_seq_no(self):
        # increment the session_seq_no
        session_seq_no = self.increment_byte_seq(self.last_gn_seq_no[self.seq_no_partition_size:])
        self.last_gn_seq_no = self.last_gn_seq_no[:self.seq_no_partition_size] + session_seq_no
        logger.debug("\tSEQUENCE NO. gen:" + self.last_gn_seq_no+"\n\n")
        
        
    ################################################################################
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
    def pass_thread_address(self, main_thread, sensor_controller): 
        self.main_thread = main_thread
        self.sensor_controller = sensor_controller
        logger.debug("Addresses of main_thread and sensor_controller saved.\n\n")
    
    
    ##############################################################################
    def reg_msg_handler(self, msg_info, reply):
        logger.debug("Registration msg handler called.\n\n")
        if reply:
            for single_response in reply.payloads:
                if single_response.return_value == 0:
                    logger.info("\t\tRegistration ACK received.\n\n")
                    # change status to YES in config file
                    config = ConfigObj(config_file_name)
                    config["Registered"] = "YES"
                    config["UTC Time"] = single_response.output
                    bashit("date -s@"+str(single_response.output))
                    config.write()
                    start_communication_with_nc_event.set()
                    logger.info("Start_communication_with_nc_event is set.\n\n")
                else:
                    logger.critical("Unknown ACK received: Discarding..\n\n")
            return   
        # handle failure
        logger.critical("Registration timeout........\n\n")
        msg_info[1] = self.calculate_expiration_time(registration_type, None)
        add_to_sorted_output_buffer(self.sorted_output_buffer, msg_info)
        self.external_communicator.push(msg_info[2])
        logger.info("Msg to NCR:" + str(msg_info[2])+"\n\n")
        logger.critical("Registration msg resent......"+"\n\n")
        
     
    ##############################################################################
    def data_msg_handler(self, msg_info, reply):
        logger.debug("Data msg handler called.\n\n")
        if reply:
            for single_response in reply.payloads:
                if single_response.output == acknowledgment and not single_response.return_value:
                    logger.info("\t\tData ACK received.\n\n")
                else:
                    logger.critical("Unknown ACK received: Discarding..\n\n")
            return
        # handle failure
        logger.critical("Data Packet timeout........\n\n")
        msg_info[1] = self.calculate_expiration_time(data_type, None)
        add_to_sorted_output_buffer(self.sorted_output_buffer, msg_info)
        self.external_communicator.push(msg_info[2])
        logger.info("Msg to NCR:" + str(msg_info[2])+"\n\n")
        logger.critical("Data msg resent......"+"\n\n")
                
            
     
    ##############################################################################
    def __del__(self):
        print self, 'bufr_mngr object died'