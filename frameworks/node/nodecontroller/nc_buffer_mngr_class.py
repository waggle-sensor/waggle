##################################################################################ORIGINAL FILE#######################################################3

from waggle.device.node_controller.send_msg import send_msg
from global_imports import *
from nc_global_definition_section import buffered_msg,  msg_send,  msg_from_gn,  \
registration_type,  reply_type, command_type, command_ack_wait_time, asynchat_msg_terminator,  \
gn_socket_list, logger, config_file_name, get_instance_id,  add_to_thread_buffer, \
wait_time_for_next_msg, config_file_lock, gn_socket_list_lock
from config_file_functions import initialize_config_file, ConfigObj

##################################################################################

# NOTES---------------------------------------------------------------------------

"""
sequence no = session_id(3 bytes) + subseq_no(3 bytes)
"""

"""
unacknowledged_msg_handler_info is saved in bfr_for_sent_msgs
unacknowledged_msg_handler_info's format: [session_id, \
last_nc_subseq_no[inst_id], expiration_time, encoded_msg, msg_handler_no, inst_id]
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
# Collects msgs from msg_processor, encodes them, attaches msg header to the msg
# and sends it to the internal_communicator thread to forward to GN. 
# Implements the lock step protocol
# Decodes msgs obtained from GN, decides whether GN is authentic and msg is valid
# or not and if so, dispatches msgs to msg_processor thread if needed.
# Handles simple ACKs. 
"""
class buffer_mngr_class(threading.Thread):

    ##############################################################################
    # Initializes global variables and data structures  
    def __init__(self, thread_name):
        try:
            threading.Thread.__init__(self)
            # can be used by logging module for printing messages related to this thread
            self.thread_name = "Thread_" + thread_name                                            
            self.daemon = True
            self.log_file_name = "NC_msg_log"
            self.cmd_msg_handler_no = 0
            self.handler_vector_table = {}                 
            self.initialize_handler_vector_table()
            ###############################
            """ 
            # Below are dictionaries representing different types of buffers 
            # for each GN
            # key=inst_id 
            """
            self.bfr_for_in_to_out_msgs = {} 
            # Stores only sent cmds not replies/ACKs and \
            # there is no reg/data msg sent from NC
            self.bfr_for_sent_msgs = {}
            self.bfr_for_out_to_in_msgs = Queue.Queue(maxsize=1000)
            # Stores only sent replies/ACKs
            self.bfr_for_sent_responses = {}
            # Stores the sequence nos which are received but unacknowledged
            self.temp_acks = {}
            ###############################x
            self.error_scope = 255
            self.default_seq_no = 0
            self.upper_seq_bytes_limit = 16777215
            # Specifies the no of bytes after which the subseq_no starts
            self.seq_no_partition_size = 3                  
            self.initial_session_id = self.default_seq_no
            self.gn_session_id = {}            
            self.nc_session_id = self.initialize_nc_session_id()                                          
            ###############################
            """ 
            # Below are dictionaries storing each guest node, cloud's details related 
            # to sequence nos
            # key=inst_id 
            """
            # subseq_no of the last msg (excluding duplicate) sent to NC by GN
            self.last_gn_subseq_no = {}                                      
            # subseq_no of the last msg (excluding duplicate) sent to GN by NC
            self.last_nc_subseq_no = {}                                      
            # subseq_no of the last msg of GN (excluding duplicate) acknowledged by NC
            self.ackd_gn_subseq_no = {}                                      
            # subseq_no of the last msg of NC (excluding duplicate) acknowledged by GN
            self.ackd_nc_subseq_no = {}                                      
            ##############################
            # currently all tests are done using same window_size for GN and NC
            self.gn_window_size = 1
            self.nc_window_size = 1
            # to save global msg_processor's address
            self.msg_processor = ''                                                               
            self.handler_vector_table = {}                                                         
            self.registered_nodes = []
            # Dict maintaining gn_id and socket mapping
            self.gn_instid_socket_obj_mapping = {}                                                
            logger.debug(self.thread_name+" Initialized."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in init(): " + str(inst)+"\n\n")
            
            
    ##############################################################################
    # main loop which loops through all the buffers constantly
    def run(self):
        try:
            # initializes data structures for cloud
            self.init_nc_related_node_data_structures('cloud')
            logger.debug("Starting " + self.thread_name+"\n\n")
            wait_time = time.time() + wait_time_for_next_msg                                                           
            while True:
                filled_in_to_out_bfr_ids = self.get_filled_in_to_out_msgs_bfr_ids()
                filled_sent_msgs_bfr_ids = self.get_filled_sent_msgs_bfr_ids()
                while not self.bfr_for_out_to_in_msgs.empty() or\
                filled_in_to_out_bfr_ids or filled_sent_msgs_bfr_ids:
                    self.send_in_to_out_msgs(filled_in_to_out_bfr_ids)
                    self.process_out_to_in_msg()
                    self.send_timed_out_msgs()
                    filled_in_to_out_bfr_ids = []
                    filled_sent_msgs_bfr_ids = []
                    # set time to remain attentive for few ms
                    wait_time = time.time() + wait_time_for_next_msg             
                    time.sleep(0.0001)
                    logger.debug("short sleep bfr mngr")
                if wait_time > time.time():
                    logger.debug("short sleep bfr mngr"+str("%.4f"%time.time()))
                    time.sleep(0.0001)
                else:
                    logger.debug("long sleep bfr mngr"+str("%.4f"%time.time()))
                    time.sleep(0.1)
        except Exception as inst:
            logger.critical("Exception in gn_msgs_bufr_mngr run: " + str(inst)+ "\n\n")
            self.run()

    
    ##############################################################################
    # Initializes NC's session id when NC starts by incrementing the old id if any
    def initialize_nc_session_id(self):
        try:
            session_id = self.get_old_session_id(None, 'NC Session ID')
            if not session_id:
                session_id = self.initial_session_id
            session_id = int (session_id)
            session_id = self.increment_no(session_id)
            self.save_session_id(None, "NC Session ID", session_id)
            logger.debug("Seq_no. initialized.\n\n")
            return session_id
        except Exception as inst:
            logger.critical("Exception in initialize_nc_session_id: " + str(inst)+"\n\n")
    
                
    ##############################################################################
    # Resets the data structures for a GN when GN fist contacts NC since NC is up
    def init_nc_related_node_data_structures(self, inst_id):
        try:
            # initialize these structures only if they don't exist
            if inst_id not in self.last_nc_subseq_no:
                self.last_nc_subseq_no[inst_id] = self.default_seq_no
                self.ackd_nc_subseq_no[inst_id] = self.default_seq_no
                self.bfr_for_in_to_out_msgs[inst_id] = Queue.Queue(100)
                self.bfr_for_sent_msgs[inst_id] = []
        except Exception as inst:
            logger.critical("Exception in init_nc_related_node_data_structures:\
            " + str(inst)+"\n\n")

    
    ##############################################################################
    # Resets the data structures for a GN when it comes up 
    def init_node_specific_data_structures(self, inst_id):
        try:
            self.last_gn_subseq_no[inst_id] = self.default_seq_no
            self.ackd_gn_subseq_no[inst_id] = self.default_seq_no
            self.temp_acks[inst_id] = []                                
            self.bfr_for_sent_responses[inst_id] = []
        except Exception as inst:
            logger.critical("Exception in init_node_specific_data_structures: "\
            + str(inst)+"\n\n")

    
    ##############################################################################
    # Create socket_instid mapping so correct socket can be retrieved based on
    # inst_id of the msg, to send msg to the GN
    def init_socket(self, inst_id, socket):
        try:
            if self.new_socket(inst_id, socket):
                self.gn_instid_socket_obj_mapping[inst_id] = socket
        except Exception as inst:
            logger.critical("Exception in init_socket: " + str(inst)+"\n")

    
    ##############################################################################
    # Called by msg_processor class to pass the address of msg_processor 
    # thread so that buffer_mngr thread can access msg_processor's variables
    def pass_thread_address(self, msg_processor):
        try:
            self.msg_processor = msg_processor
            logger.debug("Address of msg processor saved."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in pass_thread_address: " + str(inst)+"\n\n")
    
        
    ##############################################################################
    # Sends msgs to GNs through internal_communicator and msg to cloud directly 
    # by reading one msg from each node's (GN/Cloud) queue everytime
    # Attaches msg_header and encodes msg and saves it before sending
    def send_in_to_out_msgs(self, filled_in_to_out_bfr_ids):
        try:
            for inst_id in filled_in_to_out_bfr_ids:
                send_msg = 1
                logger.debug("Length of in_to_out bfr:"+str(self.bfr_for_in_to_out_msgs[inst_id].qsize()))
                item = self.bfr_for_in_to_out_msgs[inst_id].get()
                if inst_id != 'cloud' and item.msg_type != reply_type and self.is_bfr_for_sent_msgs_full(inst_id):
                    # push the msg back in the queue as the msg is not a simple
                    # reply and the sent_msgs buffer is full so protocol does 
                    # not allow to send any new msg
                    self.bfr_for_in_to_out_msgs[inst_id].put(item)
                else:
                    encoded_msg = self.gen_msg(item)
                    if inst_id != 'cloud':
                        encoded_msg = encoded_msg + asynchat_msg_terminator
                        # save the copy of msg in sent_msgs buffer
                        if item.msg_type != reply_type:
                            expiration_time = self.calculate_expiration_time(item.msg_type, item.msg)
                            msg_handler_no = self.get_msg_handler_no(item.msg_type)
                            unacknowledged_msg_handler_info = [self.nc_session_id,\
                            self.last_nc_subseq_no[inst_id], expiration_time, encoded_msg, msg_handler_no, inst_id]  
                            logger.debug("Buffer size of buffer_mngr's output buffer\
                            before adding item: " + str(len(self.bfr_for_sent_msgs[inst_id]))+"\n\n")
                            self.add_to_sent_msgs_bfr(unacknowledged_msg_handler_info, inst_id)
                            logger.debug("Msg waiting for ACK inserted in sorted buffer.\n\n")
                        # save the copy of ACK in sent_responses buffer
                        else:
                            session_id = self.convert_to_int(item.reply_id[:self.seq_no_partition_size])
                            ackd_id = self.convert_to_int(item.reply_id[self.seq_no_partition_size:])
                            for msg_id in self.temp_acks[inst_id]:
                                if msg_id[0] == session_id and msg_id[1] == ackd_id:
                                    self.temp_acks[inst_id].remove(msg_id)
                            # Check whether this is not a response for the old msg with old session_id
                            if session_id == self.gn_session_id[inst_id]:
                                self.bfr_for_sent_responses[inst_id].append((\
                                session_id, ackd_id, encoded_msg))
                            # as its an old msg don't send it
                            else:
                                logger.critical("Session id of GN: "+str(inst_id)+\
                                " has changed so discarding msg.............\n\n")
                                send_msg = 0
                        if send_msg:
                            self.send_msg_to_gn(inst_id, encoded_msg)
                    else:
                        ret = self.send_msg_to_cloud(encoded_msg)                                                             
                        # TODO: need to handle the failure case
                        if not ret:
                                self.process_ack(item.msg_type)
                self.bfr_for_in_to_out_msgs[inst_id].task_done()
        except Exception as inst:
            logger.critical("Exception in send_in_to_out_msgs: " + str(inst)+"\n\n")

    

    ############################################################################## 
    # Processes msgs in the bfr_for_out_to_in_msgs coming from GNs 
    # Decodes msg and decides whether it should be accepted or not
    # Processes simple ACKS and forwards other msgs (reg/data) to msg_processor 
    def process_out_to_in_msg(self):
        try:
            if not self.bfr_for_out_to_in_msgs.empty():
                item = self.bfr_for_out_to_in_msgs.get()
                logger.debug("Msg from GN:"  +  str(item.msg) + "\n\n")
                try:
                    decoded_msg = Message.decode(item.msg)
                except Exception as inst:
                    logger.critical("Exception while decoding msg: " + str(inst) + "\n\n")
                    logger.critical("So discarding msg............." + str(inst) + "\n\n")
                    self.bfr_for_out_to_in_msgs.task_done()
                    return
                inst_id = decoded_msg.header.instance_id
                # check for the authenticity of the sender
                if (not self.new_node(decoded_msg.header.instance_id)) | \
                (decoded_msg.header.message_type == registration_type):
                    self.init_socket(inst_id, item.sock_or_gn_id)
                    # check whether the msg is new or duplicate
                    if self.new_msg(decoded_msg):
                        # when an ACK is obtained delete the corresponding waiting msg
                        if decoded_msg.header.message_type == reply_type:
                            session_id = self.convert_to_int(decoded_msg.header.reply_to_id[:self.seq_no_partition_size])
                            subseq_no = self.convert_to_int(decoded_msg.header.reply_to_id[self.seq_no_partition_size:])
                            msg_info = self.get_and_del_saved_msg(session_id, subseq_no, inst_id) 
                            if msg_info:
                                self.handler_vector_table[msg_info[4]](inst_id, msg_info, decoded_msg)        
                        # data/registration msg obtained so send it to msg_processor
                        else:
                            session_id = self.convert_to_int(decoded_msg.header.sequence_id[:self.seq_no_partition_size])
                            subseq_no = self.convert_to_int(decoded_msg.header.sequence_id[self.seq_no_partition_size:])
                            # prepare the msg in proper format to insert into msg_processor's input_buffer
                            item = buffered_msg(item.internal_msg_header, \
                            decoded_msg.header.message_type, decoded_msg.header.sequence_id, \
                            decoded_msg.header.reply_to_id, decoded_msg.payloads, decoded_msg.header.instance_id)
                            # save the last_gn_subseq_no till its ack is sent after receiving from msg_processor thread
                            self.temp_acks[inst_id].append((session_id, subseq_no))
                            # send to msg_processor's input_buffer
                            add_to_thread_buffer(self.msg_processor.input_buffer, item, 'Msg_Processor')        
                    else:
                        logger.critical("OLD MSG DISCARDED.............\n\n")
                else:
                    logger.critical("UNKNOWN GN SO MSG DISCARDED............."+ "\n\n")
                self.bfr_for_out_to_in_msgs.task_done()
        except Exception as inst:
            logger.critical("Exception in process_out_to_in_msg: " + str(inst)+"\n\n")

    
    ############################################################################## 
    # Resend expired msg
    def send_timed_out_msgs(self):
        try:
            for inst_id, bfr in self.bfr_for_sent_msgs.iteritems():
                if bfr:
                    timed_out_msg_info = self.get_timed_out_msg_info(bfr)
                    if timed_out_msg_info:
                        self.handler_vector_table[timed_out_msg_info[4]]\
                        (timed_out_msg_info, inst_id, None)
        except Exception as inst:
            logger.critical("Exception in send_timed_out_msgs: " + str(inst)+"\n\n")

    
    ##############################################################################
    # Retrieves socket object (internal_communicator object) corresponding to 
    # the GN based on the inst_id of the msg and pushes the msg to that socket        
    def send_msg_to_gn(self, inst_id, msg):
        try:
            socket_obj = self.get_socket_obj(inst_id)
            if socket_obj:
                try:
                    socket_obj.push(msg) 
                    # logger.critical("Msg sent to GN:"+str('%0.4f' % \
                    # time.time()) + str(msg)+"\n\n" ) #+ 
                    # logger.critical("Msg sent to GN "+str(inst_id)+":"+\
                    # str('%0.4f' % time.time())+":"+\
                    # str(self.last_nc_subseq_no[inst_id])+ ":"+\
                    # str(self.ackd_nc_subseq_no[inst_id]) + "\n\n" )
                    logger.critical("Msg sent to GN "+str(inst_id)+":"+\
                    str('%0.4f' % time.time()) + "\n\n" )
                except Exception as inst:
                    logger.critical("Exception in send_msg_to_gn: " + str(inst)+"\n\n")
                    self.send_msg_to_gn(inst_id, msg)
            else:
                logger.critical("GN's socket closed. So discarding the msg.............."+ "\n\n")
        except Exception as inst:
            logger.critical("Exception in send_msg_to_gn: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    # sends msg to cloud by calling imported send_msg function
    def send_msg_to_cloud(self, encoded_msg):
        try:
            send_msg(encoded_msg)                                                             
            #logger.critical("Msg sent to Cloud!: "+str('%0.4f' % time.time())\
            # + "\tcount:" +str(self.sent_msg_count)+"\t"+(encoded_msg)+"\n\n") # + +"\n\n")
            #logger.critical("Msg sent to Cloud: "+str('%0.4f' % time.time()))
            #logger.critical("Msg sent to Cloud: "+str('%0.4f' % time.time())+\
            # "\t"+(encoded_msg)+"\n\n")
            return 0
        except Exception as inst:
            logger.critical("Exception in send_msg_to_cloud: " + str(inst)+ "\n\n")
            # NOTE: below lines are commented out because  of continuous pika errors the max length of recursion was exceeding the limits
	    # logger.critical("Retrying after 1 secs."+ "\n\n")
            # time.sleep(.001)
            # self.send_msg_to_cloud(encoded_msg)
	    return 1
    

    ##############################################################################    
    # Checks whether first msg in bfr_for_sent_msgs has timed out and if so, 
    # returns it
    def get_timed_out_msg_info(self, bfr):
        try:
            msg_handler_info = bfr[0]
            if msg_handler_info[2] < time.time():
                bfr.remove(msg_handler_info)
                return msg_handler_info
            return None
        except Exception as inst:
            logger.critical("Exception in get_timed_out_msg_info: " + str(inst)+"\n\n")
    

    ############################################################################## 
    # Gets the inst_ids whose corresponding in_to_out_msgs_bfr is not empty
    def get_filled_in_to_out_msgs_bfr_ids(self):
        try:
            filled_bfr_ids = []
            for inst_id in self.bfr_for_in_to_out_msgs:
                if not self.bfr_for_in_to_out_msgs[inst_id].empty():
                    filled_bfr_ids.append(inst_id)
            return filled_bfr_ids
        except Exception as inst:
            logger.critical("Exception in get_filled_bfr_ids: " + str(inst)+"\n\n")

            
    ############################################################################## 
    # Gets the inst_ids whose corresponding sent_msgs_bfr is not empty
    def get_filled_sent_msgs_bfr_ids(self):
        try:
            filled_bfr_ids = []
            for inst_id in self.bfr_for_sent_msgs:
                if self.bfr_for_sent_msgs[inst_id]:
                    filled_bfr_ids.append(inst_id)
            return filled_bfr_ids
        except Exception as inst:
            logger.critical("Exception in get_filled_bfr_ids: " + str(inst)+"\n\n")

            
    ############################################################################## 
    # Decides whether the bfr is full or not based on the nc's window size
    def is_bfr_for_sent_msgs_full(self, inst_id):
        try:
            return len(self.bfr_for_sent_msgs[inst_id]) >= self.nc_window_size
        except Exception as inst:
            logger.critical("Exception in is_bfr_for_sent_msgs_full: " + str(inst)+"\n\n")

            
    ##############################################################################
    # Saves a copy of the sent msg (which is not Reg/data/ACK)
    def add_to_sent_msgs_bfr(self, msg_handler_info, inst_id):
        try:
            logger.debug("Buffer size of GN_msgs_buffer_mngr's output buffer \
            before adding item: " + str(len(self.bfr_for_sent_msgs[inst_id]))+"\n\n")
            self.bfr_for_sent_msgs[inst_id].append(msg_handler_info)
            # sorted based on time so retrieval for expired msgs is in FIFO order
            sorted(self.bfr_for_sent_msgs[inst_id], key=lambda x: x[2])                                              
            logger.debug("Msg waiting for ACK inserted in sorted buffer."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in add_to_sent_msgs_bfr: " + str(inst)+"\n\n")

            
    ##############################################################################
    # Discards all the old msgs in the bfr_for_sent_responses whose reply_id is
    # behind or equal to the acknowledged seq_no in the sequence sent by the GN
    def discard_ackd_responses(self, inst_id):
        try:
            for response in self.bfr_for_sent_responses[inst_id]:
                # If session_id doesn't match means its probably an old response so delete it
                if response[0] != self.gn_session_id[inst_id]:
                    self.bfr_for_sent_responses[inst_id].remove(response)
                # check whether the buffered_response's reply_id ie. GN's subseq_no\
                # is now outside GN's current window
                elif self.response_rcvd_by_gn(self.ackd_gn_subseq_no[inst_id], response[1]):
                    # discard the response
                    self.bfr_for_sent_responses[inst_id].remove(response)
                else:
                    # as ACKS are stored in FIFO order
                    break
        except Exception as inst:
            logger.critical("Exception in discard_ackd_responses: " + str(inst)+"\n")
            
            
    ##############################################################################
    # checks whether the ACK corresponding to the reply_id has already been received
    # by the GN or not based on the newly received ackd_gn_subseq_no
    def response_rcvd_by_gn(self, ackd_no, reply_id):
        # Explanation for 1st OR Condtion: If reply_id > ackd_no then if the difference between them is too large then
        # that means there is wrap up so the response is old but as the subseq_no is about
        # to reach the max limit so reply_id > ackd_no
        # Explanation for 2nd OR Condtion: If reply_id is not greater than ackd_no then its either == or < ackd_no
        # and if the difference is not very large. Necessary to check diff for special case of wrap-up 
        # Ex: (say) reply_id = 2 due to wrap up and ackd_id = 255(lets say its the max. limit) then in this case 
        # the response should not be deleted as its ahead in the sequence and not yet acknowledged by GN
        if (self.is_gt(reply_id,ackd_no) and self.diff_large(reply_id,ackd_no)) or ((not self.is_gt(reply_id, ackd_no)) and (not self.diff_large(ackd_no, reply_id))):
            return True
        return False
    
    ##############################################################################
    # checks whether no1 is greater than no2
    def is_gt(self, no1, no2):
        return no1>no2
        
        
    ##############################################################################
    # checks whether no1 is greater than no2
    def diff_large(self, no1, no2):
        return (no1-no2)>self.error_scope
        
        
    ##############################################################################    
    # From bfr_for_sent_msgs deletes & returns msg_info for a specific msg whose ACK is obtained   
    def get_and_del_saved_msg(self, session_id, subseq_no, inst_id):
        try:
            logger.debug("Buffer size of buffer_mngr's output buffer before \
            deleting item: " + str(len(self.bfr_for_sent_msgs[inst_id]))+"\n")
            for msg_handler_info in self.bfr_for_sent_msgs[inst_id]:
                if msg_handler_info[0] == session_id and msg_handler_info[1] == subseq_no:
                    self.bfr_for_sent_msgs[inst_id].remove(msg_handler_info)
                    if (msg_handler_info[1] == self.ackd_nc_subseq_no[inst_id]+1) or\
                    (msg_handler_info[1] == 1 and self.ackd_nc_subseq_no[inst_id]==self.upper_seq_bytes_limit):
                        # Set the ackd_nc_subseq_no equal to the oldest waiting msg's last_nc_subseq_no
                        # minus 1 (or max subseq_no as shown below in a special case) if the bfr is not empty
                        if self.bfr_for_sent_msgs[inst_id]:
                            oldest_last_nc_subseq_no = self.find_oldest_last_nc_subseq_no(inst_id)
                            # check the border case: if ACK of msg, whose subseq_no has reached to the max limit, is received
                            # and the oldest msg waiting in the bfr has subseq_no=1
                            if msg_handler_info[1] == self.upper_seq_bytes_limit and oldest_last_nc_subseq_no==1:
                                self.ackd_nc_subseq_no[inst_id] = self.upper_seq_bytes_limit
                            else:
                                # As the protocol allows to receive msgs in any sequence (when window_size>1)
                                # as far as they are in the expected range (which is decided
                                # by the window size of the sending party), it is not necessary
                                # that the ACKs will always be *accepted* in order and hence
                                # ackd_nc_subseq_no is always not simply incremented by 1
                                # but set 1 less than the current oldest waiting packet's no
                                # in the buffer
                                self.ackd_nc_subseq_no[inst_id] = oldest_last_nc_subseq_no - 1
                        # as bfr is empty that means NC is not expecting any ACK from GN so 
                        # set ackd_nc_subseq_no=last_nc_subseq_no maintained with this GN
                        else:
                            self.ackd_nc_subseq_no[inst_id] = self.last_nc_subseq_no[inst_id]
                        
                    logger.debug("Msg deleted from output_buffer and returned.\n")
                    return msg_handler_info
            return None
        except Exception as inst:
            logger.critical("Exception in get_and_del_saved_msg: " + str(inst)+"\n")

            
    ##############################################################################
    # Returns the last_nc_subseq_no of the oldest waiting msg
    def find_oldest_last_nc_subseq_no(self, inst_id):
        try:
            logger.debug("Searching for the oldest subseq_no sent by NC."+"\n")
            # initializing with the last_nc_subseq_no of the first msg in the bfr
            first_msg = self.bfr_for_sent_msgs[inst_id][0]
            min_subseq_no = first_msg[1]
            max_subseq_no = first_msg[1]
            # find the min and max last_nc_subseq_no to find the the subseq_no which is the oldest, 
            # if there is no wrap up then it will be the min last_nc_subseq_no else it will be max last_nc_subseq_no
            for msg_handler_info in self.bfr_for_sent_msgs[inst_id]:
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
            logger.critical("Exception in get_and_del_saved_msg: " + str(inst)+"\n")
    

    ##############################################################################
    # Ideally this should be called when the ACK comes back from the cloud but
    # currently as nothing comes from the cloud so just to update the 
    # registration status to 'YES' this function is called after registration 
    # msg is successfully sent to the cloud
    def process_ack(self, msg_type):
        try:
            if msg_type == registration_type:
                self.process_reg_ack()
        except Exception as inst:
            logger.critical("Exception in process_ack: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    # Changes the registration status of all GNs and itself to 'YES' so next 
    # time when a new GN tries to register redundant info is not sent        
    def process_reg_ack(self):
        try:
            with config_file_lock:
                logger.critical("Config file lock acquired.............\n\n")
                config = ConfigObj(config_file_name)
                if config["Registered"] == 'NO':
                    config["Registered"] = 'YES'
                for node in config["GN Info"]:
                    if config['GN Info'][node]["Registered"] == 'NO':
                        config['GN Info'][node]["Registered"] = 'YES'
                config.write()
                logger.critical("Config file lock released.............\n\n")
        except Exception as inst:
            logger.critical("Exception in process_reg_ack: " + str(inst)+"\n\n")
    

    ##############################################################################
    # Returns the internal_communicator object corresponding to the GN
    def get_socket_obj(self, gn_id):
        try:
            logger.debug("Socket object corresponding to specific GN retrieved."+ "\n")
            if gn_id in self.gn_instid_socket_obj_mapping:
                # Lock acquired to access global list variable and released when the with block ends
                with gn_socket_list_lock:
                    # If live socket then return
                    if self.gn_instid_socket_obj_mapping[gn_id] in gn_socket_list:
                        return self.gn_instid_socket_obj_mapping[gn_id]
                    else:
                        del self.gn_instid_socket_obj_mapping[gn_id]
            return None
        except Exception as inst:
            logger.critical("Exception in get_socket_obj: " + str(inst)+ "\n")


    ##############################################################################
    # Decides whether a socket is new or not by checking the global data
    # structure gn_socket_list and socket_instid mapping
    def new_socket(self, gn_id, socket):
        try:
            socket_mapped = False
            if (gn_id in self.gn_instid_socket_obj_mapping) and \
            (socket == self.gn_instid_socket_obj_mapping[gn_id]):
                socket_mapped = True
            # Lock acquired to access global list variable and released when the with block ends
            with gn_socket_list_lock:
                if socket in gn_socket_list:
                    if socket_mapped:
                        return False
                    return True
            # Remove the old socket if present
            if socket_mapped:
                del self.gn_instid_socket_obj_mapping[gn_id]
            return False
        except Exception as inst:
            logger.critical("Exception in new_socket: " + str(inst)+"\n")


    ##############################################################################
    # Checks whether a GN is new or not by checking entries in registered nodes
    # or reading config file, if entry is present in config file but not in 
    # registered nodes then it adds that node to registered_nodes list
    def new_node(self, inst_id):
        try:
            if inst_id in self.registered_nodes:
                logger.debug("Node is already known."+"\n\n")
                return False
            # Lock acquired
            with config_file_lock:
                logger.critical("Config file lock acquired.............\n\n")
                # Check in config file for the inst_id
                config = ConfigObj(config_file_name)
                if inst_id in config['GN Info']:
                    logger.debug("Node is already known."+"\n\n")
                    self.registered_nodes.append(inst_id)
                    logger.critical("Config file lock released.............\n\n")
                    return False
                # Lock released
                logger.critical("Config file lock released.............\n\n")
            logger.debug("New node."+"\n\n")
            return True
        except Exception as inst:
            logger.critical("Exception in new_node: " + str(inst)+ "\n\n")
    
    
    ##############################################################################  
    # Generates msg by attaching the msg_header to the payloads received from 
    # msg_processor thread
    def gen_msg(self, item):
        try:
            header = MessageHeader()
            header.message_type = item.msg_type
            header.instance_id = get_instance_id()
            # saves the session_id + new subseq_no which is called: last_nc_subseq_no
            header.sequence_id = self.gen_nc_seq_no(item.sock_or_gn_id)
            # To indicate the last subseq_no of NC till which all ACKs ie replies from this GN have been received 
            # NOTE: Its important to increment the last_nc_subseq_no first 
            # (which is done in above function call: gen_nc_seq_no) and then call gen_nc_ackd_subseq_no
            header.user_field1 = self.gen_nc_ackd_subseq_no(item.sock_or_gn_id, item.msg_type) 
            header.reply_to_id = item.reply_id
            msg = Message()
            msg.header = header
            for each_msg in item.msg:
                msg.append(each_msg)
            try:
                msg = msg.encode()  
            except Exception as inst:
                logger.critical("Exception while encoding msg: " + str(inst) + "\n\n")
            logger.debug("Msg Encoded."+"\n\n")
            return msg
        except Exception as inst:
            logger.critical("Exception in gen_msg: " + str(inst)+"\n\n")
            
        
    ##############################################################################
    # Increments the current sequence no which is maintained with GN
    def gen_nc_seq_no(self, inst_id):
        try:
            if inst_id in self.last_nc_subseq_no:
                self.last_nc_subseq_no[inst_id] = self.increment_no(self.last_nc_subseq_no[inst_id])
                logger.info("Sequence no. generated: " + str(self.last_nc_subseq_no[inst_id]) +\
                "for Node:"+str(inst_id)+ "\n\n")
                return str(self.convert_to_bytearray(self.nc_session_id)) +\
                str(self.convert_to_bytearray(self.last_nc_subseq_no[inst_id]))
            return None
        except Exception as inst:
            logger.critical("Exception in gen_nc_seq_no: " + str(inst)+ "\n\n")
    
    ##############################################################################
    # *If needed* then sets the current ackd_subseq_no to last_nc_subseq_no which is maintained with GN
    def gen_nc_ackd_subseq_no(self, inst_id, msg_type):
        try:
            # If bfr_for_sent_msgs corresponding to this GN is empty means
            # there are no pending unacknowledged *msgs* (not ACKS as ACKS don't require ACK) 
            # sent by NC->this GN AND if this msg is an *ACK* so the ackd_nc_subseq_no
            # can be safely set equal to last_nc_subseq_no maintained with this GN 
            # to indicate that NC has received all ACKs for all the msgs sent by it (if any from NC->GN)
            # or in short NC is not expecting any ACK
            if msg_type == reply_type and (not self.bfr_for_sent_msgs[inst_id]):
                # assign the recently incremented last_nc_subseq_no
                self.ackd_nc_subseq_no[inst_id] = self.last_nc_subseq_no[inst_id]
            return str(self.convert_to_bytearray(self.ackd_nc_subseq_no[inst_id]))
        except Exception as inst:
            logger.critical("Exception in gen_nc_seq_no: " + str(inst)+ "\n\n")

    
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
            return integer_no
        except Exception as inst:
            logger.critical("Exception in increment_no: " + str(inst)+ "\n\n")
            
            
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
            logger.critical("Exception in convert_to_int: " + str(inst)+"\n\n")
    
    
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
            logger.critical("Exception in convert_to_bytearray: " + str(inst)+"\n\n")
    
                
    ##############################################################################
    # Decides and returns the no which is ahead in the sequence of msgs sent by the GN
    # Ex: 001->002, returns 002
    # Ex: 255->001, returns 001
    def get_new_no(self, new_no, old_no):
        try:
            if (new_no != old_no) and self.in_expected_range(new_no, old_no):
                return new_no
            return old_no
        except Exception as inst:
            logger.critical("Exception in get_new_no: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    # Checks for wrap-up by comparing new and old nos
    def is_wrap_up(self, no2, no1):
        try:
            return no2 < (no1 - self.error_scope)
        except Exception as inst:
            logger.critical("Exception in is_wrap_up: " + str(inst)+"\n\n")
    
        
    ##############################################################################
    # Checks whether new session_id falls in expected range or not
    # ie. If new_id is greater than old_id, or less than old_id (in
    # case of wrap-up) it falls in expected range
    def in_expected_range(self, new_id, old_id):
        try:
            # self.error_scope shows the range of session_id which may be old\
            # and should be discarded
            return (new_id > old_id) or self.is_wrap_up(new_id, old_id)
        except Exception as inst:
            logger.critical("Exception in in_expected_range: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    # Checks whether new session_id falls in expected range or not
    # ie. If new_id is greater than old_id, or less than old_id (in
    # case of wrap-up) it falls in expected range
    def in_expected_sessionseq_range(self, new_id, old_id):
        try:
            return self.in_expected_range(new_id, old_id)
        except Exception as inst:
            logger.critical("Exception in in_expected_sessionseq_range: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    # Checks whether new subseq_no is valid or not
    def in_expected_subseq_range(self, new_subseq_no, inst_id):
        try:
            upper_limit = self.last_gn_subseq_no[inst_id] + self.gn_window_size
            # 1. Ex: last_gn_subseq_no == ackd_gn_subseq_no so acceptable msgs can fall in range  
            #    last_gn_subseq_no < *HERE* <= last_gn_subseq_no + gn_window_size
            # 2. Ex: ackd_gn_subseq_no < last_gn_subseq_no so acceptable msgs can fall in range
            #    ackd_gn_subseq_no < *HERE* <= last_gn_subseq_no + gn_window_size
            # 3. Ex: ackd_gn_subseq_no > last_gn_subseq_no so acceptable msgs can fall in range
            #    ackd_gn_subseq_no < *HERE* <= upper_seq_bytes_limit OR 0 < *HERE* <= (last_gn_subseq_no + gn_window_size)
            #    Explanation for limit_due_to_wrap_up: suppose upper_seq_bytes_limit=255 and gn_window_size=2 
            #    and last_gn_subseq_no=254 then upper_limit(calculated above)=256 which is invalid
            #    so set another limit_due_to_wrap_up which will be (in this case): 1
            #    Wrap-up can occur in both 1 & 2 cases above and 3rd is essentially wrap up
            if upper_limit > self.upper_seq_bytes_limit:
                limit_due_to_wrap_up = (self.last_gn_subseq_no[inst_id] + \
                self.gn_window_size) - (self.upper_seq_bytes_limit)
                upper_limit = self.upper_seq_bytes_limit
            else:
                # placeholder value
                limit_due_to_wrap_up = 0
            if self.last_gn_subseq_no[inst_id] >= self.ackd_gn_subseq_no[inst_id]:
                return (self.ackd_gn_subseq_no[inst_id] < new_subseq_no <= upper_limit) or\
                (0 < new_subseq_no <= limit_due_to_wrap_up)
            return (self.ackd_gn_subseq_no[inst_id] < new_subseq_no <= \
            self.upper_seq_bytes_limit) or (0 < new_subseq_no <= upper_limit)
        except Exception as inst:
            logger.critical("Exception in in_expected_subseq_range: " + str(inst)+"\n\n")
    
    
    ##############################################################################
    # checks whether new_session_id is valid or not
    # if old_session_id is None then any new session id is considered as valid\
    # else if its in expected range then only its considered as valid
    def valid_new_session_id(self, old_session_id, new_session_id):
        try:
            if old_session_id:
                return self.in_expected_sessionseq_range(new_session_id, old_session_id)
            # if this GN is contacting the NC for the first time then accept any session_id from GN
            return True
        except Exception as inst:
            logger.critical("Exception in valid_new_session_id: " + str(inst)+"\n\n")
            return False
    
    
    ##############################################################################
    # When GN's session_id is queried, it checks first in self.gn_session_id,\
    # if found then returns that else checks in log file for that inst_id entry
    # if found returns that, else returns None 
    # When NC's session_id is querued it is read from log file
    def get_old_session_id(self, inst_id, tag_name):
        try:
            log = ConfigObj(self.log_file_name)
            # check if session_id of a GN is queried 
            if inst_id:
                # Since NC is up has this GN ever contacted NC? 
                if tag_name == 'GN Session ID' and inst_id in self.gn_session_id:
                    return self.gn_session_id[inst_id]
                # Has this GN ever contacted NC? 
                if inst_id in log:
                    return int(log[inst_id][tag_name])
            # Session ID of NC is queried
            else:
                if tag_name in log:
                    return int(log[tag_name])
            return None
        except Exception as inst:
            logger.critical("Exception in get_old_session_id: " + str(inst)+\
            " for:" + str(inst_id) + "\n\n")
    
    
    ##############################################################################
    # saves the NC or GN session id in log file
    def save_session_id(self, inst_id, tag_name, session_id):
        try:
            log = ConfigObj(self.log_file_name)
            if inst_id:
                # create an entry for the GN 
                if inst_id not in log:
                    log[inst_id] = {}
                # ex: log[guest_node_id]["GN Session ID"]
                log[inst_id][tag_name] = session_id                                     
            else:
                log[tag_name] = session_id
            log.write()
        except Exception as inst:
            logger.critical("Exception in save_session_id: " + str(inst)+"\n\n")
        
    
    ##############################################################################
    # Decides whether new msg is actually new or duplicate
    def new_msg(self, msg):
        try:
            ret_val = False
            inst_id = msg.header.instance_id
            old_session_id = self.get_old_session_id(inst_id, "GN Session ID")
            new_session_id = self.convert_to_int(msg.header.sequence_id[:self.seq_no_partition_size])
            new_subseq_no = self.convert_to_int(msg.header.sequence_id[self.seq_no_partition_size:])
            # if any saved session id then check whether saved one and new one match
            if old_session_id == new_session_id:
                # GN and NC are both up since they last contacted each other
                if inst_id in self.last_gn_subseq_no:
                    if (self.in_expected_subseq_range(new_subseq_no, inst_id)):
                        # ACK obtained
                        if msg.header.message_type == reply_type:
                            reply_subseq_no = self.convert_to_int(msg.header.reply_to_id[self.seq_no_partition_size:])
                            # check in sent_msgs bfr for corresponding msg waiting for ACK
                            for sent_msg in self.bfr_for_sent_msgs[inst_id]:
                                # comparing the seq_no of bfrd msg with reply_id of new msg
                                if sent_msg[1] == reply_subseq_no:                       
                                    ret_val =  True
                            if not ret_val:
                                logger.critical("DUP ACK received for old \
                                subseq_no: "+str(reply_subseq_no)+".............\n\n")
                        else:
                            match = 0
                            # check for duplicate old msg whose ACK is already sent
                            for response in self.bfr_for_sent_responses[inst_id]: 
                                # comparing the seq_no of new msg with reply_id of bfrd response
                                if response[1] == new_subseq_no:
                                    logger.critical("ACK Lost so old msg with\
                                    subseq_no:"+str(new_subseq_no)+ " received.............\n\n")
                                    # resend response
                                    self.send_msg_to_gn(inst_id, response[2])
                                    match = 1
                            if not match:
                                # check if the msg has been already received 
                                # but not responded so it does not have any entry in bfrd_responses
                                for ack in self.temp_acks[inst_id]:
                                    # comparing the subseq_no of new msg with 
                                    # saved subseq_no not yet acknowledged
                                    if ack[1] == new_subseq_no:
                                        logger.critical("Old msg with subseq_no:\
                                        "+str(new_subseq_no)+ " received whose\
                                        ACK is not yet sent.............\n\n")
                                        match = 1
                            if not match:
                                # else its a new msg
                                ret_val = True
                    else:
                        logger.critical("Unexpected subseq_no received: "+\
                        str(new_subseq_no)+".............\n\n")
                # GN is up but NC went down since they last contacted \
                # eachother so no record of subseq_no found 
                else:
                    logger.critical("Expected session_id received.............\n\n")
                    self.init_nc_related_node_data_structures(inst_id)
                    self.init_node_specific_data_structures(inst_id)
                    # save new GN session_id 
                    self.gn_session_id[inst_id] = new_session_id
                    ret_val = True
            # check whether new session id falls in the expected range and the new seq_no is 1
            elif self.valid_new_session_id(old_session_id, new_session_id) and new_subseq_no == 1:
                logger.critical("Valid new session_id received.............\n\n")
                self.init_nc_related_node_data_structures(inst_id)
                self.init_node_specific_data_structures(inst_id)
                # save new GN session_id 
                self.gn_session_id[inst_id] = new_session_id
                self.save_session_id(inst_id, "GN Session ID", self.gn_session_id[inst_id])
                ret_val = True
            else:
                logger.critical("Unexpected seq_no received: "+str(new_session_id)+"\t"+\
                    str(new_subseq_no)+".............\n\n")
            if ret_val:
                # save ackd and new seq_nos received from this inst_id
                new_last_gn_subseq_no = self.convert_to_int(msg.header.sequence_id[self.seq_no_partition_size:])
                new_ackd_gn_subseq_no = self.convert_to_int(msg.header.user_field1)
                self.last_gn_subseq_no[inst_id] = self.get_new_no(new_last_gn_subseq_no, self.last_gn_subseq_no[inst_id])
                new_ackd_gn_subseq_no = self.get_new_no(new_ackd_gn_subseq_no, self.ackd_gn_subseq_no[inst_id])
                if self.ackd_gn_subseq_no[inst_id] != new_ackd_gn_subseq_no:
                    self.ackd_gn_subseq_no[inst_id] = new_ackd_gn_subseq_no
                    # discard all responses whose ACKs are received
                    self.discard_ackd_responses(inst_id)
            else:
                logger.critical("Unexpected seq_no received: "+str(new_subseq_no)+\
                    ": when last_gn_subseq_no: "+str(self.last_gn_subseq_no[inst_id])\
                        +": ackd_gn_subseq_no: "+str(self.ackd_gn_subseq_no[inst_id])+"\n\n")
                logger.critical("new_session_id: "+str(new_session_id)+\
                    ": old_session_id: "+str(old_session_id)+"\n\n")
            logger.debug("new_subseq_no:"+str(new_subseq_no))
            logger.debug("last_gn_subseq_no[inst_id]"+str(self.last_gn_subseq_no[inst_id]))
            logger.debug("ackd_gn_subseq_no[inst_id]"+str(self.ackd_gn_subseq_no[inst_id]))
            return ret_val 
        except Exception as inst:
            logger.critical("Exception in new_msg: " + str(inst)+"\n\n")    
    
        
    ##############################################################################
    # Called by msg_processor while exiting
    def close(self):
        try:
            self.external_communicator.shutdown = 1
            self.external_communicator.handle_close()
            self.external_communicator.join(1)
        except Exception as inst:
            logger.critical("Exception in close: " + str(inst)+"\n\n")

    
    ##############################################################################
    def __del__(self):
        print self, 'gn_msgs_bufr_mngr object died.'
    

    """
    """
    
    # Below functions are never tested as no commands come from the cloud but provided as hooks
    
    """
    """
    ##############################################################################
    # initializes the handler_vector_table by mapping handler nos with the names
    def initialize_handler_vector_table(self):
        try:
            self.handler_vector_table[self.cmd_msg_handler_no] = self.cmd_msg_handler 
            logger.debug("Handler vector table initialized.\n\n")
        except Exception as inst:
            logger.critical("Exception in initialize_handler_vector_table: " + str(inst)+"\n\n")

    
    ##############################################################################
    # Based on msg_type it decides which handler should be called in the event of an ACK or no ACK
    def get_msg_handler_no(self, msg_type):
        try:
            if msg_type == command_type:
                logger.debug("Fetching cmd msg handler no.\n\n")
                return self.cmd_msg_handler_no
        except Exception as inst:
            logger.critical("Exception in get_msg_handler_no: " + str(inst)+"\n\n")
        
    
    ##############################################################################
    # Takes action based on whether the ACK is obtained or the msg has timed out
    def cmd_msg_handler(self, inst_id, msg_info, reply=None):
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
            logger.critical("Cmd Packet timeout.............\n\n")
            msg_info[2] = self.calculate_expiration_time(data_type, None)
            self.add_to_sent_msgs_bfr(msg_info, inst_id)
            self.send_msg_to_gn(inst_id, msg_info[3])
            logger.critical("Cmd msg resent............."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in data_msg_handler: " + str(inst)+ "\n\n")
    
    
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
        
                

