from global_imports import *
from commands import getoutput as bashit
from gn_external_communicator_class import external_communicator_class

from gn_global_definition_section import get_instance_id,  msg_to_nc,  msg_from_nc,  start_communication_with_nc_event, \
registration_type,  data_type,  reply_type,  acknowledgment,  terminator, \
gn_registration_ack_wait_time,  data_ack_wait_time, \
config_file_name, logger, wait_time_for_next_msg

from config_file_functions import initialize_config_file, ConfigObj

##################################################################################
# Buffer manager discards any ACK which is unexpected ie. which does not have
# any corresponding waiting msg in sorted_output_buffer
# bfr_for_sent_msgs bfr_for_in_to_out_msgs bfr_for_out_to_in_msgs bfr_for_sent_responses
##################################################################################

# buffer_mngr (object of buffer_mngr_class): Sends msgs from main_thread and sensor_controller threads to the external_communicator thread
# and dispatches msgs from NC/GNs to appropriate threads by examining the msg_type or if needed then seq_no
class buffer_mngr_class(threading.Thread):
    
    
    ##############################################################################
    def __init__(self, thread_name, nc_port):
        threading.Thread.__init__(self)
        self.thread_name = thread_name                  # used for tagging the msgs related to this thread
        self.daemon = True
        self.bfr_for_in_to_out_msgs = Queue.Queue(maxsize=1000)     
        self.bfr_for_sent_msgs =[]
        self.bfr_for_out_to_in_msgs = Queue.Queue(maxsize=1000)
        self.bfr_for_sent_responses = []
        self.nc_port = nc_port                          # port at which NC listens for incoming requests, to be passed to the external_communicator_class
        self.main_thread_ = ''
        self.sensor_controller = ''
        self.external_communicator = ''
        self.log_file_name = 'GN_msg_log'
        self.communicator_thread_started = 0
        self.reg_msg_handler_no = 0
        self.data_msg_handler_no = 1
        self.handler_vector_table = {}                 
        self.initialize_handler_vector_table()
        self.error_scope = 255
        self.seq_no_partition_size = 3                  # no of bytes of session_id
        self.initial_session_id = bytearray([0,0,0])
        self.gn_session_id = self.initialize_gn_session_id()            # in bytearray
        self.nc_session_id = 0                                          # in bytearray, 0 means illegal
        self.last_gn_subseq_no = 0                                      # in int
        self.last_nc_subseq_no = 0                                      # in int
        self.ackd_gn_subseq_no = 0                                      # in int
        self.ackd_nc_subseq_no = 0                                      # in int
        self.gn_window_size = 1
        self.nc_window_size = 1
        self.temp_acks = []
        self.wait_time = 0
        #self.sent_msg_count = 0
        logger.debug("Thread "+self.thread_name+" Initialized.\n\n")
            
    
    ##############################################################################
    # initializes the handler_vector_table by mapping handler nos with the names
    def initialize_handler_vector_table(self):
        try:
            # initialize handler_vector_table by mapping handler no with handler name
            self.handler_vector_table[self.reg_msg_handler_no] = self.reg_msg_handler 
            self.handler_vector_table[self.data_msg_handler_no] = self.data_msg_handler
            logger.debug("Handler vector table initialized.\n\n")
        except Exception as inst:
            logger.critical("Exception in  initialize_handler_vector_table: " + str(inst) + "\n\n")
         
     
    ##############################################################################
    def save_session_id(self, tag_name, session_id):
        try:
            config = ConfigObj(self.log_file_name)
            config[tag_name] = session_id  
            config.write()
        except Exception as inst:
            logger.critical("Exception in save_session_id: " + str(inst) + "\n\n")
         
     
        
    ##############################################################################
    def initialize_gn_session_id(self):
        try:
            session_id = self.get_old_session_id('GN Session ID')
            if not session_id:
                session_id = str(self.initial_session_id)
            session_id = self.convert_to_bytearray(self.increment_no(self.convert_to_int(session_id)))
            self.save_session_id("GN Session ID", session_id)
            logger.debug("Seq_no. initialized.\n\n")
            return session_id
        except Exception as inst:
            logger.critical("Exception in initialize_gn_session_id: " + str(inst) + "\n\n")
         
    
    ##############################################################################
    def send_in_to_out_msg(self):
        try:
            if not self.bfr_for_in_to_out_msgs.empty():
                item = self.bfr_for_in_to_out_msgs.get()
                if item.msg_type != reply_type and self.is_bfr_for_sent_msgs_full():
                    # push the msg back in the queue
                    self.bfr_for_in_to_out_msgs.put(item)
                else:
                    # if msg is a response or ir sent_msgs_bfr is not full
                    encoded_msg = self.gen_msg(item)
                    encoded_msg = encoded_msg + terminator
                    if item.msg_type != reply_type:
                        expiration_time = self.calculate_expiration_time(item.msg_type, item.msg)
                        msg_handler_no = self.get_msg_handler_no(item.msg_type)
                        unacknowledged_msg_handler_info = [self.last_gn_subseq_no, expiration_time, encoded_msg, msg_handler_no]  
                        logger.debug("Buffer size of buffer_mngr's output buffer before adding item: " + str(len(self.bfr_for_sent_msgs))+"\n\n")
                        self.add_to_sent_msgs_bfr(unacknowledged_msg_handler_info)
                        logger.debug("Msg waiting for ACK inserted in sorted buffer.\n\n")
                    else:
                        ackd_id = self.convert_to_int(item.reply_id[self.seq_no_partition_size:])
                        if ackd_id in self.temp_acks:
                            self.temp_acks.remove(ackd_id)
                        self.bfr_for_sent_responses.append([ackd_id, encoded_msg])
                    #self.sent_msg_count += 1
                    # sending to socket corresponding to the respective GN    
                    self.external_communicator.push(encoded_msg)                              
                    #logger.critical("Msg Sent to NC:"+str('%0.4f' % time.time())+ "\tcount:" + str(self.sent_msg_count) + "\t" + str(encoded_msg)+"\n\n") # 
                    logger.critical("Msg Sent to NC:"+str('%0.4f' % time.time())+ "\n\n")
                self.bfr_for_in_to_out_msgs.task_done()
        except Exception as inst:
            logger.critical("Exception in send_in_to_out_msg: " + str(inst) + "\n\n")
         
                    
    
    ##############################################################################
    def process_out_to_in_msgs(self):
        try:
            while not self.bfr_for_out_to_in_msgs.empty():
                item = self.bfr_for_out_to_in_msgs.get()
                logger.debug("Msg from NCR:" + str(item.msg) + "\n\n")
                decoded_msg = Message.decode(item.msg)
                if self.new_msg(decoded_msg):
                    # save new ackd and last seq_nos
                    new_last_nc_subseq_no = self.convert_to_int(decoded_msg.header.sequence_id[self.seq_no_partition_size:])
                    new_ackd_nc_subseq_no = self.convert_to_int(decoded_msg.header.user_field1)
                    self.last_nc_subseq_no = self.get_new_seq_no(self.last_nc_subseq_no, new_last_nc_subseq_no)
                    new_ackd_nc_subseq_no = self.get_new_seq_no(self.ackd_nc_subseq_no, new_ackd_nc_subseq_no)
                    if self.ackd_nc_subseq_no != new_ackd_nc_subseq_no:
                        self.ackd_nc_subseq_no = new_ackd_nc_subseq_no
                        # discard the last out of nc_window buffered response if any
                        self.discard_ackd_responses()
                    if decoded_msg.header.message_type == reply_type:
                        subseq_no = self.convert_to_int(decoded_msg.header.reply_to_id[self.seq_no_partition_size:])
                        msg_info = self.get_msg_info_and_delete_from_output_buffer(subseq_no)   
                        self.handler_vector_table[msg_info[3]](msg_info, decoded_msg)   
                    else:
                        # save the last_gn_subseq_no till its ack is actually inserted after receiving from msg_processor
                        self.temp_acks.append(new_last_nc_subseq_no)
                        # a new cmd from NC so pass it to apt thread: sensor_ctlr or main_class
                        self.dispatch_cmd(decoded_msg)
                else:
                    logger.critical("OLD MSG DISCARDED...................................................\n\n")
                self.bfr_for_out_to_in_msgs.task_done()
        except Exception as inst:
            logger.critical("Exception in process_out_to_in_msgs: " + str(inst) + "\n\n")
         
     
    ############################################################################## 
    def send_timed_out_msg(self):
        try:
            if self.bfr_for_sent_msgs:
                timed_out_msg_info = self.get_timed_out_msg_info()
                if timed_out_msg_info:
                    self.handler_vector_table[timed_out_msg_info[3]](timed_out_msg_info, None)
        except Exception as inst:
            logger.critical("Exception in send_timed_out_msg: " + str(inst) + "\n\n")
         
    
    ##############################################################################
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name + "\n\n")
            if not self.communicator_thread_started:
                self.external_communicator = external_communicator_class("external_communicator", self.nc_port, self) 
                self.external_communicator.start()
                self.communicator_thread_started = 1
            wait_time = time.time() + wait_time_for_next_msg
            wait_time_set = 1
            while True:
                while (not self.bfr_for_out_to_in_msgs.empty()) or (not self.bfr_for_in_to_out_msgs.empty()) or (self.bfr_for_sent_msgs):
                    self.send_in_to_out_msg()
                    self.process_out_to_in_msgs()
                    self.send_timed_out_msg()
                    # set time to remain attentive for next 100 ms
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
            time.sleep(10)
            self.run()
                
                
    ##############################################################################
    def close(self):
        try:
            self.external_communicator.shutdown = 1
            self.external_communicator.handle_close()
            self.external_communicator.join(1)
        except Exception as inst:
            logger.critical("Exception in close: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    def add_to_sent_msgs_bfr(self, msg_handler_info):
        try:
            logger.debug("Buffer size of GN_msgs_buffer_mngr's output buffer before adding item: " + str(len(self.bfr_for_sent_msgs))+"\n\n")
            self.bfr_for_sent_msgs.append(msg_handler_info)
            sorted(self.bfr_for_sent_msgs, key=lambda x: x[1])                                              # sorted based on time
            logger.debug("Msg waiting for ACK inserted in sorted buffer."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in add_to_sent_msgs_bfr: " + str(inst) + "\n\n")
         
    
    
    
    ##############################################################################
    def get_new_seq_no(self, new_no, old_no):
        try:
            if (new_no != old_no) and self.in_expected_range(new_no, old_no):
                return new_no
            return old_no
        except Exception as inst:
            logger.critical("Exception in get_new_seq_no: " + str(inst)+"\n\n")
    
        
    
    ##############################################################################
    #TODO: hook to dispatch cmds to apt thread: main or sensor_controller
    def dispatch_cmd(self, decoded_msg):
        pass
    
    
    ##############################################################################
    def discard_ackd_responses(self):
        try:
            if self.last_nc_subseq_no < self.ackd_nc_subseq_no:
                # wrap-up case
                lower_limit = self.last_nc_subseq_no
            else:
                # place holder value
                lower_limit = -1
            for response in self.bfr_for_sent_responses:
                # check whether the buffered_response's reply_id ie. NC's seq_no is now outside nc's current window
                if response[0] < self.ackd_nc_subseq_no and response[0] > lower_limit:
                    self.bfr_for_sent_responses.remove(response)
                else:
                    # as ACKS are stored in FIFO order
                    break
        except Exception as inst:
            logger.critical("Exception in discard_ackd_responses: " + str(inst)+"\n\n")
    
    
    ##############################################################################    
    # Returns msg_info for a specific msg    
    def get_msg_info_and_delete_from_output_buffer(self, subseq_no):
        try:
            logger.debug("Buffer size of buffer_mngr's output buffer before deleting item: " + str(len(self.bfr_for_sent_msgs))+"\n\n")
            for msg_handler_info in self.bfr_for_sent_msgs:
                if msg_handler_info[0] == subseq_no:
                    self.bfr_for_sent_msgs.remove(msg_handler_info)
                    if msg_handler_info[0] > self.ackd_gn_subseq_no or msg_handler_info[0] < self.last_gn_subseq_no:
                            self.ackd_gn_subseq_no = msg_handler_info[0]
                    logger.debug("Msg deleted from bfr_for_sent_msgs and returned.\n\n")
                    return msg_handler_info
            return None
        except Exception as inst:
            logger.critical("Exception in get_msg_info_and_delete_from_output_buffer: " + str(inst)+"\n\n")
    

    ##############################################################################    
    # Checks for timed out msg and returns it
    def get_timed_out_msg_info(self):
        try:
            msg_handler_info = self.bfr_for_sent_msgs[0]
            if msg_handler_info[1] < time.time():
                self.bfr_for_sent_msgs.remove(msg_handler_info)
                return msg_handler_info
            return None
        except Exception as inst:
            logger.critical("Exception in get_timed_out_msg_info: " + str(inst)+"\n\n")
       
   
    ############################################################################## 
    def is_bfr_for_sent_msgs_full(self):
        try:
            # here window size can be checked 
            return len(self.bfr_for_sent_msgs) >= self.gn_window_size
        except Exception as inst:
            logger.critical("Exception in is_bfr_for_sent_msgs_full: " + str(inst)+"\n\n")
    
    
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
    def in_expected_subseq_range(self, new_subseq_no):
        try:
            if not self.is_wrap_up(self.last_nc_subseq_no, self.ackd_nc_subseq_no):
                return (new_subseq_no > self.ackd_nc_subseq_no) and ((self.last_nc_subseq_no + self.nc_window_size) >= new_subseq_no)
            # due to wrap-up
            return (new_subseq_no > self.ackd_nc_subseq_no) or (new_subseq_no <= (self.last_nc_subseq_no + self.nc_window_size))
        except Exception as inst:
            logger.critical("Exception in in_expected_subseq_range: " + str(inst)+"\n\n")
    
   
    ##############################################################################
    # checks whether the subseq_no is in window range
    def subseq_no_within_nc_window(self, subseq_no):
        try:
            return 0 < subseq_no and subseq_no <= self.nc_window_size
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
            old_session_id = self.convert_to_int(self.get_old_session_id("NC Session ID"))
            new_session_id = self.convert_to_int(msg.header.sequence_id[:self.seq_no_partition_size])
            new_subseq_no = self.convert_to_int(msg.header.sequence_id[self.seq_no_partition_size:])
            # if any saved session id then
            # check whether saved one and new one match
            if old_session_id == new_session_id:
                # GN and NC are both up since they last contacted each other
                if self.last_nc_subseq_no:
                    if (self.in_expected_subseq_range(new_subseq_no)):
                        # check type
                        if msg.header.message_type == reply_type:
                            # check in sent_msgs bfr for corresponding msg
                            for sent_msg in self.bfr_for_sent_msgs:
                                if sent_msg[0] == self.convert_to_int(msg.header.reply_to_id[self.seq_no_partition_size:]):                       # comparing the seq_no of bfrd msg with reply_id
                                    return True
                            logger.critical("DUP ACK received: "+str(new_subseq_no)+".............................................\n\n")
                        else:
                            # check if its an old msg whose ACK was lost on the way
                            for response in self.bfr_for_sent_responses:                # comparing the seq_no of new msg with reply_id of bfrd response
                                if response[0] == new_subseq_no:
                                    logger.critical("ACK Lost so old msg received: "+str(new_subseq_no)+".............................................\n\n")
                                    # resend response
                                    self.external_communicator.push(response[1])
                                    return False
                            for temp_ack in self.temp_acks:
                                if temp_ack == new_subseq_no:
                                    logger.critical("ACK Lost so old msg received: "+str(new_subseq_no)+".............................................\n\n")
                                    return False
                            # else its a new msg
                            ret_val = True
                    else:
                        logger.critical("Unexpected subseq_no received: "+str(new_subseq_no)+".............................................\n\n")
                # GN is up but NC went down since they last contacted eachother so no record of session_seq_no found 
                else:
                    ret_val = True
            # check whether new session id falls in the expected range and the new seq_no is [0,0,0]/in the GN window range
            elif self.valid_new_session_id(old_session_id, new_session_id) and self.subseq_no_within_nc_window(new_subseq_no):            # in the window range
                # save new GN session_id 
                self.nc_session_id = self.convert_to_bytearray(new_session_id)
                self.save_session_id("NC Session ID", self.nc_session_id)
                ret_val = True
            else:
                logger.critical("Unexpected seq_no received: "+str(new_session_id)+"\t"+\
                    str(new_subseq_no)+".............................................\n\n")
            return ret_val 
        except Exception as inst:
            logger.critical("Exception in new_msg: " + str(inst)+"\n\n")
    
  
    
    ##############################################################################
    # Based on msg_type it decides which handler should be called in the event of an ACK or no ACK
    def get_msg_handler_no(self, msg_type):
        try:
            if msg_type == registration_type:
                # Registration is already done so use the next session no and seq_no = 0
                logger.debug("Fetching registration msg handler no.\n\n")
                return self.reg_msg_handler_no
            elif msg_type == data_type:
                # Registration is already done so use the next session no and seq_no = 0
                logger.debug("Fetching data msg handler no.\n\n")
                return self.data_msg_handler_no
        except Exception as inst:
            logger.critical("Exception in get_msg_handler_no: " + str(inst)+"\n\n")
    
        
        
    ##############################################################################    
    # Based on msg_type and sometimes msg_content, it decides how long it should wait for the ACK
    def calculate_expiration_time(self, msg_type, msg):
        try:
            if msg_type == registration_type:
                wait_time = gn_registration_ack_wait_time
            elif msg_type == data_type:
                wait_time = data_ack_wait_time
            logger.debug("Calculated expiration_time based on msg_type and msg.\n\n")
            return (time.time() + wait_time)
        except Exception as inst:
            logger.critical("Exception in calculate_expiration_time: " + str(inst)+"\n\n")
    
    

    ##############################################################################    
    def get_old_session_id(self, tag_name):
        try:
            if tag_name == 'NC Session ID' and self.nc_session_id:
                return self.nc_session_id
            config = ConfigObj(self.log_file_name)
            if tag_name in config:
                return config[tag_name]
            return None
        except Exception as inst:
            logger.critical("Exception in get_old_session_id: " + str(inst)+"\n\n")
    
    
    
    ##############################################################################
    def gen_msg(self, item):
        try:
            header = MessageHeader()
            header.instance_id = get_instance_id()
            header.message_type = item.msg_type
            header.sequence_id = self.gen_gn_seq_no()
            header.user_field1 = str(self.convert_to_bytearray(self.ackd_gn_subseq_no))
            header.reply_to_id = item.reply_id
            msg = Message()
            msg.header = header
            for each_msg in item.msg:
                msg.append(each_msg)
            msg = msg.encode()   
            return msg
        except Exception as inst:
            logger.critical("Exception in gen_msg: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    # Increments the current sequence no which is maintained with NC
    def gen_gn_seq_no(self):
        try:
            # increment the session_seq_no
            self.last_gn_subseq_no = self.increment_no(self.last_gn_subseq_no)
            logger.debug("\tSUBSEQUENCE NO. gen:" + str(self.last_gn_subseq_no)+"\n\n")
            return str(self.gn_session_id) + str(self.convert_to_bytearray(self.last_gn_subseq_no))
        except Exception as inst:
            logger.critical("Exception in gen_gn_seq_no: " + str(inst)+"\n\n")
    
        
   
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
    def pass_thread_address(self, main_thread, sensor_controller):
        try:
            self.main_thread = main_thread
            self.sensor_controller = sensor_controller
            logger.debug("Addresses of main_thread and sensor_controller saved.\n\n")
        except Exception as inst:
            logger.critical("Exception in pass_thread_address: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    def reg_msg_handler(self, msg_info, reply=None):
        try:
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
            self.add_to_sent_msgs_bfr(msg_info)
            self.external_communicator.push(msg_info[2])
            logger.info("Msg to NCR:" + str(msg_info[2])+"\n\n")
            logger.critical("Registration msg resent......"+"\n\n")
        except Exception as inst:
            logger.critical("Exception in reg_msg_handler: " + str(inst)+ "\n\n")
        
        
     
    ##############################################################################
    def data_msg_handler(self, msg_info, reply=None):
        try:
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
            self.add_to_sent_msgs_bfr(msg_info)
            self.external_communicator.push(msg_info[2])
            logger.info("Msg to NCR:" + str(msg_info[2])+"\n\n")
            logger.critical("Data msg resent......"+"\n\n")
        except Exception as inst:
            logger.critical("Exception in data_msg_handler: " + str(inst)+ "\n\n")
        
                
            
     
    ##############################################################################
    def __del__(self):
        print self, 'bufr_mngr object died'