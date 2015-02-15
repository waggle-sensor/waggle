from global_imports import *
from commands import getoutput as bashit
from gn_external_communicator_class import external_communicator_class

from gn_global_definition_section import get_instance_id, start_communication_with_nc_event, \
registration_type,  data_type,  reply_type,  acknowledgment,  asynchat_msg_terminator, \
gn_registration_ack_wait_time,  data_ack_wait_time, \
config_file_name, logger, wait_time_for_next_msg

from config_file_functions import initialize_config_file, ConfigObj

##################################################################################
# NOTES---------------------------------------------------------------------------

"""
sequence no = session_id(3 bytes) + subseq_no(3 bytes)
"""

"""
unacknowledged_msg_handler_info is saved in sent_gnMsgBfr
unacknowledged_msg_handler_info's format: [session_id, \
highest_gn_subseq_no, expiration_time, encoded_msg, msg_handler_no, inst_id]
"""

"""
Responses stored in bfr_for_sent_responses have the format:
(session_id, subseq_no, encoded_msg)
"""

"""
Sequence nos stored in temp_acks have the format:
(session_id, subseq_no)
"""
##################################################################################



"""
# Collects msgs from main_thread and sensor_controller threads, encodes them, 
# attaches msg header to the msg and sends it to the external_communicator 
# thread to forward to NC. 
# Implements the lock step protocol
# Decodes msgs obtained from NC and decides whether its a valid msg and if so, 
# dispatches msgs to appropriate threads by examining the msg_type.
# Handles simple ACKs. 
"""
class buffer_mngr_class(threading.Thread):
    
    ##############################################################################
    # Initializes the global variables and data structures
    def __init__(self, thread_name, nc_port):
        try:
            threading.Thread.__init__(self)
            # can be used for tagging the msgs related to this thread
            self.thread_name = thread_name                  
            self.daemon = True
            ###############################
            """ 
            # Below are different types of buffers 
            """
            self.outgoing_gnMsgBfr = Queue.Queue(maxsize=1000)
            self.incoming_ncAckBfr = Queue.Queue(maxsize=1000)
            # Stores only sent reg/data/cmds not replies/ACKs
            self.sent_gnMsgBfr =[]
            ###############################
            # Port where NC listens for GNs
            self.nc_port = nc_port                          
            self.main_thread_ = ''
            self.sensor_controller = ''
            self.external_communicator = ''
            self.log_file_name = 'session_ids'
            self.communicator_thread_started = 0
            self.reg_msg_handler_no = 0
            self.data_msg_handler_no = 1
            self.handler_vector_table = {}                 
            self.initialize_handler_vector_table()
            # Default for session_id/last_subseq_no/ackd_subseq_no and mean nothing 
            self.default_seq_no = 0                                             
            self.error_scope = 255
            self.upper_seq_bytes_limit = 16777215
            # Specifies the no of bytes after which the subseq_no starts
            self.seq_no_partition_size = 3                  
            self.initial_session_id = self.default_seq_no
            self.gn_session_id = self.initialize_gn_session_id()   
            self.nc_session_id = self.default_seq_no 
            # subseq_no of the last msg (excluding duplicate) sent to NC
            self.highest_gn_subseq_no = self.default_seq_no  
            # subseq_no of the last msg (excluding duplicate) sent to GN
            self.highest_nc_subseq_no = self.default_seq_no 
            # subseq_no of the last msg of GN (excluding duplicate) acknowledged by NC
            self.ackd_gn_subseq_no = self.default_seq_no 
            # subseq_no of the last msg of NC (excluding duplicate) acknowledged by GN
            self.ackd_nc_subseq_no = self.default_seq_no                                      
            # currently all tests are done using same window_size for GN and NC
            self.gn_window_size = 1
            self.nc_window_size = 1
            logger.debug("Thread "+self.thread_name+" Initialized.")
        except Exception as inst:
            logger.critical("ERROR: Exception in  init function: " + str(inst))
        

    ##############################################################################
    # Loops through all the buffers constantly
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name )
            if not self.communicator_thread_started:
                self.external_communicator = external_communicator_class("external_communicator", self.nc_port, self) 
                self.external_communicator.start()
                self.communicator_thread_started = 1
            wait_time_set = 0
            while True:
                while (not self.outgoing_gnMsgBfr.empty()) or (self.sent_gnMsgBfr) or (not self.incoming_ncAckBfr.empty()):
                    self.send_in_to_out_msg()
                    self.process_out_to_in_msg()
                    self.send_timed_out_msg()
                    time.sleep(0.0001)
                    wait_time_set=0
                else:
                    if wait_time_set==0: 
                        wait_time = time.time() + wait_time_for_next_msg
                        wait_time_set=1;
                    if wait_time > time.time():
                        time.sleep(0.0001)
                    else:
                        time.sleep(0.1)
        except Exception as inst:
            logger.critical("ERROR: Exception in bufr_mngr run: " + str(inst) )
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
    # Called by main_thread to pass the address of sensor_controller, main_thread 
    # so that buffer_mngr thread can access their variables
    def pass_thread_address(self, main_thread, sensor_controller):
        try:
            self.main_thread = main_thread
            self.sensor_controller = sensor_controller
            logger.debug("Addresses of main_thread and sensor_controller saved.")
        except Exception as inst:
            logger.critical("ERROR: Exception in pass_thread_address: " + str(inst))


    ##############################################################################
    # Initializes the handler_vector_table by mapping handler nos with the names
    # To call a function, its no. is used  as an index in handler_vector_table
    def initialize_handler_vector_table(self):
        try:
            self.handler_vector_table[self.reg_msg_handler_no] = self.reg_msg_handler 
            self.handler_vector_table[self.data_msg_handler_no] = self.data_msg_handler
            logger.debug("Handler vector table initialized.")
        except Exception as inst:
            logger.critical("ERROR: Exception in  initialize_handler_vector_table: " + str(inst) )
        
    
    ##############################################################################
    # Initializes GN's session id when GN starts by incrementing the old id if any
    def initialize_gn_session_id(self):
        try:
            session_id = self.get_old_session_id('GN Session ID')
            if not session_id:
                session_id = self.initial_session_id
            session_id = int (session_id)
            session_id = self.increment_no(session_id)
            self.save_session_id("GN Session ID", session_id)
            logger.debug("Seq_no. initialized.")
            return session_id
        except Exception as inst:
            logger.critical("ERROR: Exception in initialize_gn_session_id: " + str(inst) )
        
    
    ##############################################################################
    # Resets the data structures related to NC when GN first contacts NC after
    # NC is up
    def reset_nc_specific_data_structures(self):
        try:
            self.highest_nc_subseq_no = self.default_seq_no
            self.ackd_nc_subseq_no = self.default_seq_no
        except Exception as inst:
            logger.critical("ERROR: Exception in reset_nc_specific_data_structures: " + str(inst))

    
    ##############################################################################
    # Sends msgs to NC through external_communicator by reading one msg 
    # from the queue everytime
    # Attaches msg_header and encodes msg and saves it before sending
    def send_in_to_out_msg(self):
        try:
            if not self.outgoing_gnMsgBfr.empty() and not self.is_sent_gnMsgBfr_full():
                item = self.outgoing_gnMsgBfr.get()				
                encoded_msg = self.gen_msg(item)
                encoded_msg = encoded_msg + asynchat_msg_terminator
                # save the copy of msg in sent_msgs buffer
                # send only if its not a reply (currently only reg/data msgs are present in the bfr)
                expiration_time = self.calculate_expiration_time(item.msg_type, item.msg)
                msg_handler_no = self.get_msg_handler_no(item.msg_type)
                unacknowledged_msg_handler_info = [self.gn_session_id,\
                self.highest_gn_subseq_no, expiration_time, encoded_msg, msg_handler_no]  
                logger.debug("Buffer size of buffer_mngr's output buffer\
                before adding item: " + str(len(self.sent_gnMsgBfr)))
                self.add_to_sent_msgs_bfr(unacknowledged_msg_handler_info)
                logger.debug("Msg waiting for ACK inserted in sorted buffer.")
                self.send_msg_to_nc(encoded_msg)
                self.outgoing_gnMsgBfr.task_done()
        except Exception as inst:
            logger.critical("ERROR: Exception in send_in_to_out_msg: " + str(inst) )
        
                    
    
    ##############################################################################
    # Processes msgs in the incoming_ncAckBfr coming from NC
    # Decodes msg and decides whether it should be accepted or not
    # Processes simple ACKS and forwards other msgs (in future cmd) to main_thread 
    # or sensor_controller
    def process_out_to_in_msg(self):
        try:
            if not self.incoming_ncAckBfr.empty():
                item = self.incoming_ncAckBfr.get()
                logger.debug("Msg from NCR:" + str(item.msg) )
                try:
                    decoded_msg = Message.decode(item.msg)
                    logger.critical(str(item.msg) + " of len:"+str(len(item.msg)) )
                except Exception as inst:
                    logger.critical("ERROR: Exception while decoding msg: " + str(inst) )
                    logger.critical("Discarding msg " + str(item.msg) + " of len:"+str(len(item.msg)) )
                    self.incoming_ncAckBfr.task_done()
                    return
                # check whether the msg is new or duplicate
                if self.new_msg(decoded_msg):
                    # when an ACK is obtained delete the corresponding waiting msg
                    if decoded_msg.header.message_type == reply_type:
                        session_id = self.convert_to_int(decoded_msg.header.reply_to_id[:self.seq_no_partition_size])
                        subseq_no = self.convert_to_int(decoded_msg.header.reply_to_id[self.seq_no_partition_size:])
                        msg_info = self.get_and_del_saved_msg(session_id, subseq_no)   
                        self.handler_vector_table[msg_info[4]](msg_info, decoded_msg)   
                    
                else:
                    logger.critical("OLD MSG DISCARDED.............")
                self.incoming_ncAckBfr.task_done()
        except Exception as inst:
            logger.critical("ERROR: Exception in process_out_to_in_msg: " + str(inst) )
        
    
    ##############################################################################
    # Resend timed out msg
    def send_timed_out_msg(self):
        try:
            if self.sent_gnMsgBfr:
                timed_out_msg_info = self.get_timed_out_msg_info()
                if timed_out_msg_info:
                    self.handler_vector_table[timed_out_msg_info[4]](timed_out_msg_info, None)
        except Exception as inst:
            logger.critical("ERROR: Exception in send_timed_out_msg: " + str(inst) )
        
    
    ##############################################################################
    # Sends msg to NC by pushing it in the output buffer of external_communicator
    def send_msg_to_nc(self, msg):
        try:
            self.external_communicator.push(msg)
            # logger.critical("Msg Sent to NC:"+str('%0.4f' % time.time())+ \
            # "\tcount:" + str(self.sent_msg_count) + "\t" + str(encoded_msg)) # 
            # logger.critical("Msg Sent to NC:"+str('%0.4f' % time.time())+":"\
            # +str(self.highest_gn_subseq_no)+ ":"+str(self.ackd_gn_subseq_no))
            logger.critical("Msg "+str(self.highest_gn_subseq_no)+" Sent to NC:"+str('%0.4f' % time.time())+">>>>>>>>>>>>>>>>>>>>")
        except Exception as inst:
            logger.critical("ERROR: Exception in send_msg_to_nc: " + str(inst))
            self.send_msg_to_nc()
    
    
    ##############################################################################    
    # Checks whether first msg in sent_gnMsgBfr has timed out and if so, 
    # returns it
    def get_timed_out_msg_info(self):
        try:
            msg_handler_info = self.sent_gnMsgBfr[0]
            if msg_handler_info[2] < time.time():
                self.sent_gnMsgBfr.remove(msg_handler_info)
                return msg_handler_info
            return None
        except Exception as inst:
            logger.critical("ERROR: Exception in get_timed_out_msg_info: " + str(inst))
    

    ##############################################################################
    # Saves copy of the sent msg (not data/reg/ACK) in buffer of respective GN
    def add_to_sent_msgs_bfr(self, msg_handler_info):
        try:
            logger.debug("Buffer size of GN_msgs_buffer_mngr's output buffer \
            before adding item: " + str(len(self.sent_gnMsgBfr)))
            self.sent_gnMsgBfr.append(msg_handler_info)
            # sorted based on time so retrieval for expired msgs is in FIFO order
            sorted(self.sent_gnMsgBfr, key=lambda x: x[2])                                              
            logger.debug("Msg waiting for ACK inserted in sorted buffer.")
        except Exception as inst:
            logger.critical("ERROR: Exception in add_to_sent_msgs_bfr: " + str(inst) )
        

    ##############################################################################
    #TODO: hook to dispatch cmds to apt thread: main or sensor_controller
    def dispatch_cmd(self, decoded_msg):
        pass
    
    ###############################################################################
    ## Discards all the old msgs in the bfr_for_sent_responses whose reply_id is
    ## behind or equal to the acknowledged seq_no in the sequence sent by the NC
    #def discard_ackd_responses(self):
        #try:
            #for response in self.bfr_for_sent_responses:
                ## If session_id doesn't match means its probably an old response so delete it
                #if response[0] != self.nc_session_id:
                    #self.bfr_for_sent_responses.remove(response)
                ## check whether the buffered_response's reply_id ie. NC's subseq_no\
                ## is now outside NC's current window
                #elif self.response_rcvd_by_nc(self.ackd_nc_subseq_no, response[1]):
                    #self.bfr_for_sent_responses.remove(response)
                #else:
                    ## as ACKS are stored in FIFO order
                    #break
        #except Exception as inst:
            #logger.critical("ERROR: Exception in discard_ackd_responses: " + str(inst))
            
            
    ###############################################################################
    ## checks whether the ACK corresponding to the reply_id has already been received
    ## by the NC or not based on the newly received ackd_nc_subseq_no
    #def response_rcvd_by_nc(self, ackd_no, reply_id):
        ## Explanation for 1st OR Condtion: If reply_id > ackd_no then if the difference between them is too large then
        ## that means there is wrap up so the response is old but as the subseq_no is about
        ## to reach the max limit so reply_id > ackd_no
        ## Explanation for 2nd OR Condtion: If reply_id is not greater than ackd_no then its either == or < ackd_no
        ## and if the difference is not very large. Necessary to check diff for special case of wrap-up 
        ## Ex: (say) reply_id = 2 due to wrap up and ackd_id = 255(lets say its the max. limit) then in this case 
        ## the response should not be deleted as its ahead in the sequence and not yet acknowledged by NC
        #if (self.is_gt(reply_id,ackd_no) and self.diff_large(reply_id,ackd_no)) or ((not self.is_gt(reply_id, ackd_no)) and (not self.diff_large(ackd_no, reply_id))):
            #return True
        #return False
    
    ###############################################################################
    ## checks whether no1 is greater than no2
    #def is_gt(self, no1, no2):
        #return no1>no2
        
        
    ###############################################################################
    ## checks whether no1 is greater than no2
    #def diff_large(self, no1, no2):
        #return (no1-no2)>self.error_scope
        
        
    ##############################################################################    
    # From sent_gnMsgBfr deletes & returns msg_info for a specific msg whose ACK is obtained   
    def get_and_del_saved_msg(self, session_id, subseq_no):
        try:
            logger.debug("Buffer size of buffer_mngr's output buffer before \
            deleting item: " + str(len(self.sent_gnMsgBfr))+"\n")
            for msg_handler_info in self.sent_gnMsgBfr:
                if msg_handler_info[0] == session_id and msg_handler_info[1] == subseq_no:
                    self.sent_gnMsgBfr.remove(msg_handler_info)
                    if (msg_handler_info[1] == self.ackd_gn_subseq_no+1) or\
                    (msg_handler_info[1] == 1 and self.ackd_gn_subseq_no==self.upper_seq_bytes_limit):
                        # Set the ackd_gn_subseq_no equal to the oldest waiting msg's highest_gn_subseq_no
                        # minus 1 (or max subseq_no as shown below in a special case) if the bfr is not empty
                        if self.sent_gnMsgBfr:
                            oldest_highest_gn_subseq_no = self.find_oldest_highest_gn_subseq_no()
                            # check the border case: if ACK of msg, whose subseq_no has reached to the max limit, is received
                            # and the oldest msg waiting in the bfr has subseq_no=1
                            if msg_handler_info[1] == self.upper_seq_bytes_limit and oldest_highest_gn_subseq_no==1:
                                self.ackd_gn_subseq_no = self.upper_seq_bytes_limit
                            else:
                                # As the protocol allows to receive msgs in any sequence (when window_size>1)
                                # as far as they are in the expected range (which is decided
                                # by the window size of the sending party), it is not necessary
                                # that the ACKs will always be *accepted* in order and hence
                                # ackd_gn_subseq_no is always not simply incremented by 1
                                # but set 1 less than the current oldest waiting packet's no
                                # in the buffer
                                self.ackd_gn_subseq_no = oldest_highest_gn_subseq_no - 1
                        # as bfr is empty that means gn is not expecting any ACK from GN so 
                        # set ackd_gn_subseq_no=highest_gn_subseq_no maintained with this GN
                        else:
                            self.ackd_gn_subseq_no = self.highest_gn_subseq_no
                        
                    logger.debug("Msg deleted from output_buffer and returned.\n")
                    return msg_handler_info
            return None
        except Exception as inst:
            logger.critical("ERROR: Exception in get_and_del_saved_msg: " + str(inst))

            
    ##############################################################################
    # Returns the highest_gn_subseq_no of the oldest waiting msg
    def find_oldest_highest_gn_subseq_no(self):
        try:
            logger.debug("Searching for the oldest subseq_no sent by gn."+"\n")
            # initializing with the highest_gn_subseq_no of the first msg in the bfr
            first_msg = self.sent_gnMsgBfr[0]
            min_subseq_no = first_msg[1]
            max_subseq_no = first_msg[1]
            # find the min and max highest_gn_subseq_no to find the the subseq_no which is the oldest, 
            # if there is no wrap up then it will be the min highest_gn_subseq_no else it will be max highest_gn_subseq_no
            for msg_handler_info in self.sent_gnMsgBfr:
                if msg_handler_info[1] > max_subseq_no:
                    # set max_subseq_no
                    max_subseq_no = msg_handler_info[1]
                elif msg_handler_info[1] < min_subseq_no:
                    # set min_subseq_no
                    min_subseq_no = msg_handler_info[1]
            # check for wrap-up, if difference between the two is too large
            # then it means its a wrap-up case so the oldest is not the min but the 
            # max_subseq_no
            if max_subseq_no - min_subseq_no > self.error_scope:
                return max_subseq_no
            return min_subseq_no
        except Exception as inst:
            logger.critical("ERROR: Exception in get_and_del_saved_msg: " + str(inst))
    

    ##############################################################################
    # Decides whether the bfr is full or not based on the gn's window size
    def is_sent_gnMsgBfr_full(self):
        try:
            return len(self.sent_gnMsgBfr) >= self.gn_window_size
        except Exception as inst:
            logger.critical("ERROR: Exception in is_sent_gnMsgBfr_full: " + str(inst))
    
    
    ##############################################################################
    # Generates msg by attaching the msg_header to the payloads received from 
    # main_thread or sensor_controller
    def gen_msg(self, item):
        try:
            header = MessageHeader()
            header.instance_id = get_instance_id()
            header.message_type = item.msg_type
            # saves the session_id + new subseq_no which is called: highest_nc_subseq_no
            header.sequence_id = self.gen_gn_seq_no()
            # To indicate the last subseq_no of GN till which all ACKs ie replies from NC have been received 
            # NOTE: Its important to increment the highest_gn_subseq_no first 
            # (which is done in above function call: gen_gn_seq_no) and then call gen_gn_ackd_subseq_no
            header.user_field1 = self.gen_gn_ackd_subseq_no(item.msg_type) 
            header.reply_to_id = item.reply_id
            msg = Message()
            msg.header = header
            for each_msg in item.msg:
                msg.append(each_msg)
            try:
                msg = msg.encode()   
            except Exception as inst:
                logger.critical("ERROR: Exception while encoding msg: " + str(inst) )
            return msg
        except Exception as inst:
            logger.critical("ERROR: Exception in gen_msg: " + str(inst))
    
    
    ##############################################################################
    # Increments the current subseq_no which is maintained with NC
    def gen_gn_seq_no(self):
        try:
            self.highest_gn_subseq_no = self.increment_no(self.highest_gn_subseq_no)
            logger.debug("\tSUBSEQUENCE NO. gen:" + str(self.highest_gn_subseq_no))
            return str(self.convert_to_bytearray(self.gn_session_id)) +\
            str(self.convert_to_bytearray(self.highest_gn_subseq_no))
        except Exception as inst:
            logger.critical("ERROR: Exception in gen_gn_seq_no: " + str(inst))
    
        
    ##############################################################################
    # *If needed* then sets the current ackd_subseq_no to highest_gn_subseq_no which is maintained with NC
    def gen_gn_ackd_subseq_no(self, msg_type):
        try:
            # If sent_gnMsgBfr is empty means
            # there are no pending unacknowledged *msgs* (not ACKS as ACKS don't require ACK) 
            # sent by GN->NC AND if this msg is an *ACK* so the ackd_gn_subseq_no
            # can be safely set equal to highest_gn_subseq_no maintained with NC
            # to indicate that GN has received all ACKs for all the msgs sent by it (if any from GN->NC)
            # or in short GN is not expecting any ACK
            # following if condition will never be true (currently) because GN never sends any ACK to the NC
            if msg_type == reply_type and (not self.sent_gnMsgBfr):
                # assign the recently incremented highest_gn_subseq_no
                self.ackd_gn_subseq_no = self.highest_gn_subseq_no
            return str(self.convert_to_bytearray(self.ackd_gn_subseq_no))
        except Exception as inst:
            logger.critical("ERROR: Exception in gen_gn_seq_no: " + str(inst))
    
    
    ###############################################################################
    # increments the session_id or subseq_no by 1
    def increment_no(self, int_no):
        integer_no = copy.copy(int_no)
        try:
            if integer_no == self.upper_seq_bytes_limit:
                # reset it to 1 
                integer_no = self.default_seq_no + 1
            else:
                integer_no += 1
        except Exception as inst:
            logger.critical("ERROR: Exception in increment_no: " + str(inst))
        return integer_no
    
    
    ##############################################################################
    # Converts bytearray to int
    def convert_to_int(self, byte_seq):
        try:
            if byte_seq != None:
                byte_seq = bytearray(byte_seq)
                int_id = sum(byte_seq[i] << ((len(byte_seq)-1-i) * 8) for i in range(len(byte_seq)))
                return int_id
            return None
        except Exception as inst:
            logger.critical("ERROR: Exception in convert_to_int: " + str(inst))
    
    
    ##############################################################################
    # Converts int to bytearray
    def convert_to_bytearray(self, int_no):
        try:
            if int_no != None:
                byte_seq = bytearray([0,0,0])
                for i in range(self.seq_no_partition_size):
                    byte_seq[i] = (int_no >> ((self.seq_no_partition_size-1-i)*8)) & 0xff 
                return byte_seq
            return None
        except Exception as inst:
            logger.critical("ERROR: Exception in convert_to_bytearray: " + str(inst))
    
                
    #############################################################################
    # Decides and returns the no which is ahead in the sequence sent
    # Ex: 001->002, returns 002
    # Ex: 255->001, returns 001
    def get_new_no(self, new_no, old_no):
        try:
            if (new_no != old_no) and self.in_expected_range(new_no, old_no):
                return new_no
            return old_no
        except Exception as inst:
            logger.critical("ERROR: Exception in get_new_no: " + str(inst))
        
    
    ##############################################################################
    # Checks for wrap-up by comparing old and new nos
    def is_wrap_up(self, no2, no1):
        try:
            return no2 < (no1 - self.error_scope)
        except Exception as inst:
            logger.critical("ERROR: Exception in is_wrap_up: " + str(inst))
    
        
    ##############################################################################
    # Checks whether new id falls in expected range or not
    # ie. If new_id is greater than old_id, or less than old_id (in
    # case of wrap-up) it falls in expected range
    def in_expected_range(self, new_id, old_id):
        try:
            # self.error_scope shows the range of session_id which may be old\
            # and should be discarded
            return (new_id > old_id) or self.is_wrap_up(new_id, old_id)
        except Exception as inst:
            logger.critical("ERROR: Exception in in_expected_range: " + str(inst))
    
    
    ##############################################################################
    # Checks whether new session_id falls in expected range or not
    # ie. If new_id is greater than old_id, or less than old_id (in
    # case of wrap-up) it falls in expected range
    def in_expected_sessionseq_range(self, new_id, old_id):
        try:
            return self.in_expected_range(new_id, old_id)
        except Exception as inst:
            logger.critical("ERROR: Exception in in_expected_sessionseq_range: " + str(inst))
    
    
    ##############################################################################
    # Checks whether new subseq_no is valid or not
    def in_expected_subseq_range(self, new_subseq_no):
        try:
            upper_limit = self.highest_nc_subseq_no + self.nc_window_size
            # 1. Ex: highest_nc_subseq_no == ackd_nc_subseq_no so acceptable msgs can fall in range  
            #    highest_nc_subseq_no < *HERE* <= highest_nc_subseq_no + nc_window_size
            # 2. Ex: ackd_nc_subseq_no < highest_nc_subseq_no so acceptable msgs can fall in range
            #    ackd_nc_subseq_no < *HERE* <= highest_nc_subseq_no + nc_window_size
            # 3. Ex: ackd_nc_subseq_no > highest_nc_subseq_no so acceptable msgs can fall in range
            #    ackd_nc_subseq_no < *HERE* <= upper_seq_bytes_limit OR 0 < *HERE* <= (highest_nc_subseq_no + nc_window_size)
            #    Explanation for limit_due_to_wrap_up: suppose upper_seq_bytes_limit=255 and nc_window_size=2 
            #    and highest_nc_subseq_no=254 then upper_limit(calculated above)=256 which is invalid
            #    so set another limit_due_to_wrap_up which will be (in this case): 1
            #    Wrap-up can occur in both 1 & 2 cases above and 3rd is essentially wrap up
            if upper_limit > self.upper_seq_bytes_limit:
                limit_due_to_wrap_up = (self.highest_nc_subseq_no + \
                self.nc_window_size) - (self.upper_seq_bytes_limit)
                upper_limit = self.upper_seq_bytes_limit
            else:
                # placeholder value
                limit_due_to_wrap_up = 0
            if self.highest_nc_subseq_no >= self.ackd_nc_subseq_no:
                return (self.ackd_nc_subseq_no < new_subseq_no <= upper_limit) or\
                (0 < new_subseq_no <= limit_due_to_wrap_up)
            return (self.ackd_nc_subseq_no < new_subseq_no <= \
            self.upper_seq_bytes_limit) or (0 < new_subseq_no <= upper_limit)
        except Exception as inst:
            logger.critical("ERROR: Exception in in_expected_subseq_range: " + str(inst))
    
    
            
    ##############################################################################
    # checks whether new_session_id is valid or not
    def valid_new_session_id(self, old_session_id, new_session_id):
        try:
            if old_session_id:
                return self.in_expected_sessionseq_range(new_session_id, old_session_id)
            # if this GN is contacting the NC for the first time then accept any session_id from NC
            return True
        except Exception as inst:
            logger.critical("ERROR: Exception in valid_new_session_id: " + str(inst))

        
    ##############################################################################  
    # When NC's session_id is queried, it checks first in self.nc_session_id, 
    # if found then returns that else checks in log file for that inst_id entry 
    # if found returns that, else returns None 
    # When GN's session_id is queried it is read from log file
    def get_old_session_id(self, tag_name):
        try:
            if tag_name == 'NC Session ID' and self.nc_session_id:
                return self.nc_session_id
            config = ConfigObj(self.log_file_name)
            if tag_name in config:
                return int(config[tag_name])
            return None
        except Exception as inst:
            logger.critical("ERROR: Exception in get_old_session_id: " + str(inst))
    
    
    ##############################################################################
    # saves the NC or GN session id in log file
    def save_session_id(self, tag_name, session_id):
        try:
            config = ConfigObj(self.log_file_name)
            config[tag_name] = session_id  
            config.write()
        except Exception as inst:
            logger.critical("ERROR: Exception in save_session_id: " + str(inst) )
    
        
    ##############################################################################
    # Decides whether new msg is actually new or duplicate
    def new_msg(self, msg):
        try:
            ret_val = False
            inst_id = msg.header.instance_id
            old_session_id = self.get_old_session_id("NC Session ID")
            new_session_id = self.convert_to_int(msg.header.sequence_id[:self.seq_no_partition_size])
            new_subseq_no = self.convert_to_int(msg.header.sequence_id[self.seq_no_partition_size:])
            # if any saved session id then check whether saved one and new one match
            if old_session_id == new_session_id:
                # GN and NC are both up since they last contacted each other
                if self.highest_nc_subseq_no:
                    if (self.in_expected_subseq_range(new_subseq_no)):
                        # ACK obtained
                        if msg.header.message_type == reply_type:
                            reply_session_id = self.convert_to_int(msg.header.reply_to_id[:self.seq_no_partition_size])
                            reply_subseq_no = self.convert_to_int(msg.header.reply_to_id[self.seq_no_partition_size:])
                            # check in sent_msgs bfr for corresponding msg waiting for ACK
                            for sent_msg in self.sent_gnMsgBfr:
                                # comparing the seq_no of bfrd msg with reply_id of new msg
                                if sent_msg[0] == reply_session_id and sent_msg[1] == reply_subseq_no:                       
                                    ret_val = True
                            if not ret_val:
                                logger.critical("ERROR: DUP ACK received for old \
                                subseq_no: "+str(reply_subseq_no)+".............")
                        
                    else:
                        logger.critical("ERROR: Unexpected subseq_no received: "\
                        +str(new_subseq_no)+":"+str(self.highest_nc_subseq_no)+\
                        ":"+str(self.ackd_nc_subseq_no))
                # NC is up but GN went down since they last contacted eachother\
                # so no record of subseq_no found 
                else:
                    logger.critical("Expected session_id received..........")
                    self.reset_nc_specific_data_structures()
                    # save new NC session_id 
                    self.nc_session_id = new_session_id
                    ret_val = True
            # check whether new session id falls in the expected range with any subseq_no
            elif self.valid_new_session_id(old_session_id, new_session_id):
                logger.critical("Valid new session_id received.............")
                self.reset_nc_specific_data_structures()
                # save new NC session_id 
                self.nc_session_id = new_session_id
                self.save_session_id("NC Session ID", self.nc_session_id)
                ret_val = True
            else:
                logger.critical("ERROR: Unexpected seq_no received: "+str(new_session_id)+"\t"+\
                    str(new_subseq_no)+".............")
            if ret_val:
                # save ackd and new seq_nos received from this inst_id
                new_highest_nc_subseq_no = self.convert_to_int(msg.header.sequence_id[self.seq_no_partition_size:])
                new_ackd_nc_subseq_no = self.convert_to_int(msg.header.user_field1)
                self.highest_nc_subseq_no = self.get_new_no(new_highest_nc_subseq_no, self.highest_nc_subseq_no)
                new_ackd_nc_subseq_no = self.get_new_no(new_ackd_nc_subseq_no, self.ackd_nc_subseq_no)
                # for future use
                if self.ackd_nc_subseq_no != new_ackd_nc_subseq_no:
                    self.ackd_nc_subseq_no = new_ackd_nc_subseq_no
                    # for future use: discard all responses whose ACKs are received
                    # self.discard_ackd_responses()
            else:
                logger.critical("Unexpected no received: "+str(new_subseq_no)+\
                ": when highest_nc_subseq_no: "+str(self.highest_nc_subseq_no)+\
                ": ackd_nc_subseq_no: "+str(self.ackd_nc_subseq_no))
                logger.critical("new_session_id: "+str(new_session_id)+\
                " old_session_id: "+str(old_session_id))
            logger.debug("new_subseq_no:"+str(new_subseq_no))
            logger.debug("highest_nc_subseq_no:"+str(self.highest_nc_subseq_no))
            logger.debug("ackd_nc_subseq_no:"+str(self.ackd_nc_subseq_no))
            return ret_val 
        except Exception as inst:
            logger.critical("ERROR: Exception in new_msg: " + str(inst))
    
    
    ##############################################################################
    # Based on msg_type it decides which handler should be called in the event of an ACK or no ACK
    def get_msg_handler_no(self, msg_type):
        try:
            if msg_type == registration_type:
                logger.debug("Fetching registration msg handler no.")
                return self.reg_msg_handler_no
            elif msg_type == data_type:
                logger.debug("Fetching data msg handler no.")
                return self.data_msg_handler_no
        except Exception as inst:
            logger.critical("ERROR: Exception in get_msg_handler_no: " + str(inst))
        
        
    ##############################################################################
    # Takes action based on whether the ACK is obtained or the msg has timed out
    def reg_msg_handler(self, msg_info, reply=None):
        try:
            logger.debug("Registration msg handler called.")
            if reply:
                for single_response in reply.payloads:
                    if single_response.return_value == 0:
                        logger.info("\t\tRegistration ACK received.")
                        # change status to YES in config file
                        config = ConfigObj(config_file_name)
                        config["Registered"] = "YES"
                        config["UTC Time"] = single_response.output
                        bashit("date -s@"+str(single_response.output))
                        config.write()
                        start_communication_with_nc_event.set()
                        logger.info("Start_communication_with_nc_event is set.")
                    else:
                        logger.critical("ERROR: Unknown ACK received: Discarding..")
                return   
            # handle failure
            logger.critical("Registration timeout.............")
            msg_info[2] = self.calculate_expiration_time(registration_type, None)
            self.add_to_sent_msgs_bfr(msg_info)
            self.send_msg_to_nc(msg_info[3])
            logger.critical("Registration msg resent.............")
        except Exception as inst:
            logger.critical("ERROR: Exception in reg_msg_handler: " + str(inst))
        
        
    ##############################################################################
    # Takes action based on whether the ACK is obtained or the msg has timed out
    def data_msg_handler(self, msg_info, reply=None):
        try:
            logger.debug("Data msg handler called.")
            if reply:
                for single_response in reply.payloads:
                    if single_response.output == acknowledgment and not single_response.return_value:
                        logger.info("\t\tData ACK received.")
                    else:
                        logger.critical("Unknown ACK received: Discarding..")
                return
            # handle failure
            logger.critical("Data Packet timeout.............")
            msg_info[2] = self.calculate_expiration_time(data_type, None)
            self.add_to_sent_msgs_bfr(msg_info)
            self.send_msg_to_nc(msg_info[3])
            logger.critical("Data msg resent.............")
        except Exception as inst:
            logger.critical("ERROR: Exception in data_msg_handler: " + str(inst))
        
                
    ##############################################################################    
    # Based on msg_type and sometimes msg_content, it decides how long it should wait for the ACK
    def calculate_expiration_time(self, msg_type, msg):
        try:
            if msg_type == registration_type:
                wait_time = gn_registration_ack_wait_time
            elif msg_type == data_type:
                wait_time = data_ack_wait_time
            logger.debug("Calculated expiration_time based on msg_type and msg.")
            return (time.time() + wait_time)
        except Exception as inst:
            logger.critical("ERROR: Exception in calculate_expiration_time: " + str(inst))
    
    
    ##############################################################################
    # Called by main_thread while exiting
    def close(self):
        try:
            self.external_communicator.shutdown = 1
            self.external_communicator.handle_close()
            self.external_communicator.join(1)
        except Exception as inst:
            logger.critical("ERROR: Exception in close: " + str(inst))
    
    
    ##############################################################################
    def __del__(self):
        print self, 'bufr_mngr object died'
