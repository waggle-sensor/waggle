import time
#while 1:
    #try:
        #from waggle.device.node_controller.send_msg import send_msg
        #break
    #except:
        #print "Cloud not ready yet... waiting...", time.asctime()
        #time.sleep(3)
#print ">>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<"


from global_imports import *
from nc_global_definition_section import buffered_msg, \
registration_type,  reply_type, command_type, command_ack_wait_time, asynchat_msg_terminator,  \
gn_socket_list, logger, config_file_name, get_instance_id,  add_to_thread_buffer, \
wait_time_for_next_msg, config_file_lock, gn_socket_list_lock, data_type, registration_type
from config_file_functions import initialize_config_file, ConfigObj


# NOTES---------------------------------------------------------------------------

"""
sequence no = session_id(3 bytes) + subseq_no(3 bytes)
"""

"""
unacknowledged_msg_handler_info is saved in bfr_for_sent_msgs
unacknowledged_msg_handler_info's format: [session_id, \
highest_nc_subseq_no[inst_id], expiration_time, encoded_msg, msg_handler_no, inst_id]
"""

"""
Responses stored in sent_moduleAckBfr have the format:
(session_id, subseq_no, encoded_msg)
"""

"""
Sequence nos stored in unprocessed_seqNos have the format:
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
            self.log_file_name = "session_ids"
            #self.handler_vector_table = {}
            #self.initialize_handler_vector_table()
            ###############################
            """
            # Below are dictionaries representing different types of buffers
            # for each GN
            # key=inst_id
            """
            self.outgoing_ncMsgBfr = {}
            self.sent_ncMsgBfr = {}           # for future use
            self.outgoing_ncAckBfr = {}
            # Stores only sent replies/ACKs
            self.sent_ncAckBfr = {}
            self.incoming_moduleMsgBfr = Queue.Queue(maxsize=1000)
            # Stores the sequence nos which are received but unacknowledged
            self.unprocessed_gnSeqNos = {}
            ###############################
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
            self.highest_gn_subseq_no = {}
            # subseq_no of the last msg (excluding duplicate) sent to GN by NC
            self.highest_nc_subseq_no = {}
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
            # keeps track of all registered GNs
            self.registered_nodes = []
            # Dict maintaining gn_id and socket mapping
            self.gn_socket_mapping = {}
            logger.debug(self.thread_name+" Initialized.")
        except Exception as inst:
            logger.critical("Exception in init(): " + str(inst))


    ##############################################################################
    # main loop which loops through all the buffers constantly
    def run(self):
        try:
            # initializes data structures for cloud
            self.init_nc_related_node_data_structures('cloud')
            logger.debug("Starting " + self.thread_name)
            wait_time_set=0
            while True:
                filled_outgoingBfr_ids=self.get_filled_outgoing_bfr_ids()
                while (not self.incoming_moduleMsgBfr.empty()) or (not self.outgoing_ncMsgBfr['cloud'].empty()) or filled_outgoingBfr_ids:
                    self.process_incoming_moduleMsg()
                    if not self.outgoing_ncMsgBfr['cloud'].empty():
                        item = self.outgoing_ncMsgBfr['cloud'].get()
                        encoded_msg = self.gen_msg(item)
                        self.send_msg_to_cloud(encoded_msg)
                    self.send_ncAcks(filled_outgoingBfr_ids)
                    filled_outgoingBfr_ids=[]
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
            logger.critical("Exception in gn_msgs_bufr_mngr run: " + str(inst))
            #self.run()


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
            logger.critical("Exception in initialize_nc_session_id: " + str(inst))


    ##############################################################################
    # Resets the data structures for a GN when GN fist contacts NC since NC is up
    def init_nc_related_node_data_structures(self, inst_id):
        try:
            # initialize these structures only if they don't exist
            if inst_id not in self.highest_nc_subseq_no:
                self.highest_nc_subseq_no[inst_id] = self.default_seq_no
                self.ackd_nc_subseq_no[inst_id] = self.default_seq_no
                self.outgoing_ncMsgBfr[inst_id] = Queue.Queue(100)
                self.sent_ncMsgBfr[inst_id] = []
        except Exception as inst:
            logger.critical("Exception in init_nc_related_node_data_structures:\
            " + str(inst))


    ##############################################################################
    # Resets the data structures for a GN when it comes up
    def init_node_specific_data_structures(self, inst_id):
        try:
            self.highest_gn_subseq_no[inst_id] = self.default_seq_no
            self.ackd_gn_subseq_no[inst_id] = self.default_seq_no
            self.unprocessed_gnSeqNos[inst_id] = []
            self.sent_ncAckBfr[inst_id] = []
            self.outgoing_ncAckBfr[inst_id] = Queue.Queue(100)
        except Exception as inst:
            logger.critical("Exception in init_node_specific_data_structures: "\
            + str(inst))


    ##############################################################################
    # Create socket_instid mapping so correct socket can be retrieved based on
    # inst_id of the msg, to send msg to the GN
    def map_socket(self, inst_id, socket):
        try:
            with gn_socket_list_lock:
                if socket in gn_socket_list:
                    self.gn_socket_mapping[inst_id] = socket
                elif inst_id in self.gn_socket_mapping and self.gn_socket_mapping[inst_id]==socket:
                    del self.gn_socket_mapping[inst_id]
        except Exception as inst:
            logger.critical("Exception in map_socket: " + str(inst)+"\n")


    ##############################################################################
    # Called by msg_processor class to pass the address of msg_processor
    # thread so that buffer_mngr thread can access msg_processor's variables
    def pass_thread_address(self, msg_processor):
        try:
            self.msg_processor = msg_processor
            logger.debug("Address of msg processor saved.")
        except Exception as inst:
            logger.critical("Exception in pass_thread_address: " + str(inst))


    ##############################################################################
    def get_filled_outgoing_bfr_ids(self):
        filled_outgoingBfr_ids=[]
        for inst_id in self.outgoing_ncAckBfr:
            if not self.outgoing_ncAckBfr[inst_id].empty():
                filled_outgoingBfr_ids.append(inst_id)                
        return filled_outgoingBfr_ids

    ##############################################################################
    # Sends msgs to GNs through internal_communicator and msg to cloud directly
    # by reading one msg from each node's (GN/Cloud) queue everytime
    # Attaches msg_header and encodes msg and saves it before sending
    def send_ncAcks(self, filled_outgoingBfr_ids):
        try:
            for inst_id in filled_outgoingBfr_ids:
                logger.debug("Length of in_to_out bfr:"+str(self.outgoing_ncAckBfr[inst_id].qsize()))
                item = self.outgoing_ncAckBfr[inst_id].get()
                encoded_msg = self.gen_msg(item)
                encoded_msg = encoded_msg + asynchat_msg_terminator
                # reply_id indicates the seq_no of the msg whose ACK is being sent
                # extract the session_id and subseq_no from reply_id
                session_id = self.convert_to_int(item.reply_id[:self.seq_no_partition_size])
                subseq_no = self.convert_to_int(item.reply_id[self.seq_no_partition_size:])
                for msg_id in self.unprocessed_gnSeqNos[inst_id]:
                    if msg_id[0] == session_id and msg_id[1] == subseq_no:
                        self.unprocessed_gnSeqNos[inst_id].remove(msg_id)
                # Check whether this is not a response for the old msg with old session_id
                #if session_id == self.gn_session_id[inst_id]:
                self.sent_ncAckBfr[inst_id].append((\
                session_id, subseq_no, encoded_msg))
                # as its an old msg don't send it
                #else:
                    #logger.critical("Session id of GN: "+str(inst_id)+\
                    #" has changed so discarding msg.............\n\n")
                    #send_msg = 0
                #if send_msg:
                self.send_msg_to_gn(inst_id, encoded_msg)
                self.outgoing_ncAckBfr[inst_id].task_done()
        
        except Exception as inst:
            logger.critical("Exception in send_ncAcks: " + str(inst))
        


    ##############################################################################
    # Processes msgs in the incoming_moduleMsgBfr coming from GNs
    # Decodes msg and decides whether it should be accepted or not
    # Processes simple ACKS and forwards other msgs (reg/data) to msg_processor
    def process_incoming_moduleMsg(self):
        try:
            if not self.incoming_moduleMsgBfr.empty():
                item = self.incoming_moduleMsgBfr.get()
                logger.debug("Msg from GN:"  +  str(item.msg) )
                try:
                    decoded_msg = Message.decode(item.msg)
                except Exception as inst:
                    logger.critical("Exception while decoding msg: " + str(inst) )
                    logger.critical("So discarding msg............." + str(inst) )
                    self.incoming_moduleMsgBfr.task_done()
                    return 
                inst_id = decoded_msg.header.instance_id
                # check for the authenticity of the sender
                if (not self.new_node(decoded_msg.header.instance_id)) | \
                (decoded_msg.header.message_type == registration_type):
                    self.map_socket(inst_id, item.sock_or_gn_id)
                    # check whether the msg is new or duplicate
                    if self.new_msg(decoded_msg):
                        # data/registration msg obtained so send it to msg_processor
                        if decoded_msg.header.message_type == data_type or decoded_msg.header.message_type == registration_type:
                            session_id = self.convert_to_int(decoded_msg.header.sequence_id[:self.seq_no_partition_size])
                            subseq_no = self.convert_to_int(decoded_msg.header.sequence_id[self.seq_no_partition_size:])
                            # prepare the msg in proper format to insert into msg_processor's incoming_moduleMsgBfr
                            item = buffered_msg(decoded_msg.header.message_type, decoded_msg.header.sequence_id, \
                            decoded_msg.header.reply_to_id, decoded_msg.payloads, decoded_msg.header.instance_id)
                            # save the highest_gn_subseq_no temporarily until the msg is processed 
                            # and the ACK (received from the msg_processor thread) is saved in outgoing_moduleAckBfr 
                            self.unprocessed_gnSeqNos[inst_id].append((session_id, subseq_no))
                            # send to msg_processor's incoming_moduleMsgBfr
                            add_to_thread_buffer(self.msg_processor.incoming_moduleMsgBfr, item, 'Msg_Processor')
                            #print "sent to msg processor"+str('%0.4f' % time.time())
                    else:
                        logger.critical("OLD MSG DISCARDED.............\n\n")
                else:
                    logger.critical("UNKNOWN GN SO MSG DISCARDED.............")
                self.incoming_moduleMsgBfr.task_done()
            
        except Exception as inst:
            logger.critical("Exception in process_incoming_moduleMsg: " + str(inst))
        

    ##############################################################################
    ## Resend expired msg
    #def send_timed_out_msgs(self):
        #try:
            #for inst_id, bfr in self.sent_ncMsgBfr.iteritems():
                #if bfr:
                    #timed_out_msg_info = self.get_timed_out_msg_info(bfr)
                    #if timed_out_msg_info:
                        #self.handler_vector_table[timed_out_msg_info[4]]\
                        #(timed_out_msg_info, inst_id, None)
        #except Exception as inst:
            #logger.critical("Exception in send_timed_out_msgs: " + str(inst))


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
                    # time.time()) + str(msg) ) #+
                    # logger.critical("Msg sent to GN "+str(inst_id)+":"+\
                    # str('%0.4f' % time.time())+":"+\
                    # str(self.highest_nc_subseq_no[inst_id])+ ":"+\
                    # str(self.ackd_nc_subseq_no[inst_id])  )
                    logger.critical("Msg sent to GN "+str(inst_id)+":"+\
                    str('%0.4f' % time.time()) + ">>>>>>>>>>>>>>>>>>>>" )
                except Exception as inst:
                    logger.critical("Exception in send_msg_to_gn: " + str(inst))
                    self.send_msg_to_gn(inst_id, msg)
            else:
                logger.critical("GN's socket closed. So discarding the msg..............")
        except Exception as inst:
            logger.critical("Exception in send_msg_to_gn: " + str(inst))


    ##############################################################################
    # sends msg to cloud by calling imported send_msg function
    def send_msg_to_cloud(self, encoded_msg):
        try:
            #logger.critical("Msg to Cloud Start: "+str('%0.4f' % time.time()))
            #send_msg(encoded_msg)
            #logger.critical("Msg to Cloud Stop: "+str('%0.4f' % time.time()))
            return 0
        except Exception as inst:
            logger.critical("Exception in send_msg_to_cloud: " + str(inst))
	    return 1


    ###############################################################################
    ## Checks whether first msg in bfr_for_sent_msgs has timed out and if so,
    ## returns it
    #def get_timed_out_msg_info(self, bfr):
        #try:
            #msg_handler_info = bfr[0]
            #if msg_handler_info[2] < time.time():
                #bfr.remove(msg_handler_info)
                #return msg_handler_info
            #return None
        #except Exception as inst:
            #logger.critical("Exception in get_timed_out_msg_info: " + str(inst))


    ###############################################################################
    ## Gets the inst_ids whose corresponding in_to_out_msgs_bfr is not empty
    #def get_filled_in_to_out_msgs_bfr_ids(self):
        #try:
            #filled_bfr_ids = []
            #for inst_id in self.outgoing_ncAckBfr:
                #if not self.outgoing_ncAckBfr[inst_id].empty():
                    #filled_bfr_ids.append(inst_id)
            #return filled_bfr_ids
        #except Exception as inst:
            #logger.critical("Exception in get_filled_bfr_ids: " + str(inst))


    ###############################################################################
    ## Gets the inst_ids whose corresponding sent_msgs_bfr is not empty
    #def get_filled_sent_msgs_bfr_ids(self):
        #try:
            #filled_bfr_ids = []
            #for inst_id in self.sent_ncMsgBfr:
                #if self.sent_ncMsgBfr[inst_id]:
                    #filled_bfr_ids.append(inst_id)
            #return filled_bfr_ids
        #except Exception as inst:
            #logger.critical("Exception in get_filled_bfr_ids: " + str(inst))


    ###############################################################################
    ## Decides whether the bfr is full or not based on the nc's window size
    #def is_bfr_for_sent_msgs_full(self, inst_id):
        #try:
            #return len(self.sent_ncMsgBfr[inst_id]) >= self.nc_window_size
        #except Exception as inst:
            #logger.critical("Exception in is_bfr_for_sent_msgs_full: " + str(inst))


    ###############################################################################
    ## Saves a copy of the sent msg (which is not Reg/data/ACK)
    #def add_to_sent_msgs_bfr(self, msg_handler_info, inst_id):
        #try:
            #logger.debug("Buffer size of GN_msgs_buffer_mngr's output buffer \
            #before adding item: " + str(len(self.sent_ncMsgBfr[inst_id])))
            #self.sent_ncMsgBfr[inst_id].append(msg_handler_info)
            ## sorted based on time so retrieval for expired msgs is in FIFO order
            #sorted(self.sent_ncMsgBfr[inst_id], key=lambda x: x[2])
            #logger.debug("Msg waiting for ACK inserted in sorted buffer.")
        #except Exception as inst:
            #logger.critical("Exception in add_to_sent_msgs_bfr: " + str(inst))


    ##############################################################################
    # Discards all the old msgs in the sent_moduleAckBfr whose reply_id is
    # behind or equal to the acknowledged seq_no in the sequence sent by the GN
    def discard_ackd_responses(self, inst_id):
        try:
            for response in self.sent_ncAckBfr[inst_id]:
                # If session_id doesn't match means its probably an old response so delete it
                if response[0] != self.gn_session_id[inst_id]:
                    self.sent_ncAckBfr[inst_id].remove(response)
                # check whether the buffered_response's reply_id ie. GN's subseq_no\
                # is now outside GN's current window
                elif self.response_rcvd_by_gn(self.ackd_gn_subseq_no[inst_id], response[1]):
                    # discard the response
                    self.sent_ncAckBfr[inst_id].remove(response)
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


    ###############################################################################
    ## From bfr_for_sent_msgs deletes & returns msg_info for a specific msg whose ACK is obtained
    #def get_and_del_saved_msg(self, session_id, subseq_no, inst_id):
        #try:
            #logger.debug("Buffer size of buffer_mngr's output buffer before \
            #deleting item: " + str(len(self.sent_ncMsgBfr[inst_id]))+"\n")
            #for msg_handler_info in self.sent_ncMsgBfr[inst_id]:
                #if msg_handler_info[0] == session_id and msg_handler_info[1] == subseq_no:
                    #self.sent_ncMsgBfr[inst_id].remove(msg_handler_info)
                    #if (msg_handler_info[1] == self.ackd_nc_subseq_no[inst_id]+1) or\
                    #(msg_handler_info[1] == 1 and self.ackd_nc_subseq_no[inst_id]==self.upper_seq_bytes_limit):
                        ## Set the ackd_nc_subseq_no equal to the oldest waiting msg's highest_nc_subseq_no
                        ## minus 1 (or max subseq_no as shown below in a special case) if the bfr is not empty
                        #if self.sent_ncMsgBfr[inst_id]:
                            #oldest_highest_nc_subseq_no = self.find_oldest_highest_nc_subseq_no(inst_id)
                            ## check the border case: if ACK of msg, whose subseq_no has reached to the max limit, is received
                            ## and the oldest msg waiting in the bfr has subseq_no=1
                            #if msg_handler_info[1] == self.upper_seq_bytes_limit and oldest_highest_nc_subseq_no==1:
                                #self.ackd_nc_subseq_no[inst_id] = self.upper_seq_bytes_limit
                            #else:
                                ## As the protocol allows to receive msgs in any sequence (when window_size>1)
                                ## as far as they are in the expected range (which is decided
                                ## by the window size of the sending party), it is not necessary
                                ## that the ACKs will always be *accepted* in order and hence
                                ## ackd_nc_subseq_no is always not simply incremented by 1
                                ## but set 1 less than the current oldest waiting packet's no
                                ## in the buffer
                                #self.ackd_nc_subseq_no[inst_id] = oldest_highest_nc_subseq_no - 1
                        ## as bfr is empty that means NC is not expecting any ACK from GN so
                        ## set ackd_nc_subseq_no=highest_nc_subseq_no maintained with this GN
                        #else:
                            #self.ackd_nc_subseq_no[inst_id] = self.highest_nc_subseq_no[inst_id]

                    #logger.debug("Msg deleted from output_buffer and returned.\n")
                    #return msg_handler_info
            #return None
        #except Exception as inst:
            #logger.critical("Exception in get_and_del_saved_msg: " + str(inst)+"\n")


    ###############################################################################
    ## Returns the highest_nc_subseq_no of the oldest waiting msg
    #def find_oldest_highest_nc_subseq_no(self, inst_id):
        #try:
            #logger.debug("Searching for the oldest subseq_no sent by NC."+"\n")
            ## initializing with the highest_nc_subseq_no of the first msg in the bfr
            #first_msg = self.sent_ncMsgBfr[inst_id][0]
            #min_subseq_no = first_msg[1]
            #max_subseq_no = first_msg[1]
            ## find the min and max highest_nc_subseq_no to find the the subseq_no which is the oldest,
            ## if there is no wrap up then it will be the min highest_nc_subseq_no else it will be max highest_nc_subseq_no
            #for msg_handler_info in self.sent_ncMsgBfr[inst_id]:
                #if msg_handler_info[1] > max_subseq_no:
                    ## set max_subseq_no
                    #max_subseq_no = msg_handler_info[1]
                #elif msg_handler_info[1] < min_subseq_no:
                    ## set min_subseq_no
                    #min_subseq_no = msg_handler_info[1]
            ## check for wrap-up, if difference between the two is too large
            ## then it means its a wrap-up case so the oldest is not the min but the
            ## max_subseq_no
            #if max_subseq_no - min_subseq_no > self.error_scope:
                #return max_subseq_no
            #return min_subseq_no
        #except Exception as inst:
            #logger.critical("Exception in get_and_del_saved_msg: " + str(inst)+"\n")


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
            logger.critical("Exception in process_ack: " + str(inst))


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
            logger.critical("Exception in process_reg_ack: " + str(inst))


    ##############################################################################
    # Returns the internal_communicator object corresponding to the GN if the socket is still alive
    # Else None
    def get_socket_obj(self, gn_id):
        try:
            logger.debug("Socket object corresponding to specific GN retrieved."+ "\n")
            if gn_id in self.gn_socket_mapping:
                # Lock acquired to access global list variable and released when the with block ends
                with gn_socket_list_lock:
                    # If live socket then return
                    if self.gn_socket_mapping[gn_id] in gn_socket_list:
                        return self.gn_socket_mapping[gn_id]
                    else:
                        del self.gn_socket_mapping[gn_id]
            return None
        except Exception as inst:
            logger.critical("Exception in get_socket_obj: " + str(inst)+ "\n")


    ###############################################################################
    ## Decides whether a socket is new or not by checking the global data
    ## structure gn_socket_list and socket_instid mapping
    #def new_socket(self, gn_id, socket):
        #try:
            #if 
            
            #socket_mapped = False
            #if (gn_id in self.gn_socket_mapping) and \
            #(socket == self.gn_socket_mapping[gn_id]):
                #socket_mapped = True
            ## Lock acquired to access global list variable and released when the with block ends
            #with gn_socket_list_lock:
                #if socket in gn_socket_list:
                    #if socket_mapped:
                        #return False
                    #return True
            ## Remove the old socket if present
            #if socket_mapped:
                #del self.gn_socket_mapping[gn_id]
            #return False
        #except Exception as inst:
            #logger.critical("Exception in new_socket: " + str(inst)+"\n")


    ##############################################################################
    # Checks whether a GN is new or not by checking entries in registered nodes
    # or reading config file, if entry is present in config file but not in
    # registered nodes then it adds that node to registered_nodes list
    def new_node(self, inst_id):
        try:
            if inst_id in self.registered_nodes:
                logger.debug("Node is already known.")
                return False
            # Lock acquired
            with config_file_lock:
                logger.critical("Config file lock acquired.............\n\n")
                # Check in config file for the inst_id
                config = ConfigObj(config_file_name)
                if inst_id in config['GN Info']:
                    logger.debug("Node is already known.")
                    self.registered_nodes.append(inst_id)
                    logger.critical("Config file lock released.............\n\n")
                    return False
                # Lock released
                logger.critical("Config file lock released.............\n\n")
            logger.debug("New node.")
            return True
        except Exception as inst:
            logger.critical("Exception in new_node: " + str(inst))


    ##############################################################################
    # Generates msg by attaching the msg_header to the payloads received from
    # msg_processor thread
    def gen_msg(self, item):
        try:
            header = MessageHeader()
            header.message_type = item.msg_type
            header.instance_id = get_instance_id()
            # saves the session_id + new subseq_no which is called: highest_nc_subseq_no
            header.sequence_id = self.gen_nc_seq_no(item.sock_or_gn_id)
            # To indicate the last subseq_no of NC till which all ACKs ie replies from this GN have been received
            # NOTE: Its important to increment the highest_nc_subseq_no first
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
                logger.critical("Exception while encoding msg: " + str(inst) )
            logger.debug("Msg Encoded.")
            return msg
        except Exception as inst:
            logger.critical("Exception in gen_msg: " + str(inst))


    ##############################################################################
    # Increments the current sequence no which is maintained with GN
    def gen_nc_seq_no(self, inst_id):
        try:
            if inst_id in self.highest_nc_subseq_no:
                self.highest_nc_subseq_no[inst_id] = self.increment_no(self.highest_nc_subseq_no[inst_id])
                logger.info("Sequence no. generated: " + str(self.highest_nc_subseq_no[inst_id]) +\
                "for Node:"+str(inst_id))
                return str(self.convert_to_bytearray(self.nc_session_id)) +\
                str(self.convert_to_bytearray(self.highest_nc_subseq_no[inst_id]))
            return None
        except Exception as inst:
            logger.critical("Exception in gen_nc_seq_no: " + str(inst))

    ##############################################################################
    # *If needed* then sets the current ackd_subseq_no to highest_nc_subseq_no which is maintained with GN
    def gen_nc_ackd_subseq_no(self, inst_id, msg_type):
        try:
            # If bfr_for_sent_msgs corresponding to this GN is empty means
            # there are no pending unacknowledged *msgs* (not ACKS as ACKS don't require ACK)
            # sent by NC->this GN AND if this msg is an *ACK* so the ackd_nc_subseq_no
            # can be safely set equal to highest_nc_subseq_no maintained with this GN
            # to indicate that NC has received all ACKs for all the msgs sent by it (if any from NC->GN)
            # or in short NC is not expecting any ACK
            if msg_type == reply_type and (not self.sent_ncMsgBfr[inst_id]):
                # assign the recently incremented highest_nc_subseq_no
                self.ackd_nc_subseq_no[inst_id] = self.highest_nc_subseq_no[inst_id]
            return str(self.convert_to_bytearray(self.ackd_nc_subseq_no[inst_id]))
        except Exception as inst:
            logger.critical("Exception in gen_nc_seq_no: " + str(inst))


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
            logger.critical("Exception in increment_no: " + str(inst))


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
            logger.critical("Exception in convert_to_int: " + str(inst))


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
            logger.critical("Exception in convert_to_bytearray: " + str(inst))


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
            logger.critical("Exception in get_new_no: " + str(inst))


    ##############################################################################
    # Checks for wrap-up by comparing new and old nos
    def is_wrap_up(self, no2, no1):
        try:
            return no2 < (no1 - self.error_scope)
        except Exception as inst:
            logger.critical("Exception in is_wrap_up: " + str(inst))


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
            logger.critical("Exception in in_expected_range: " + str(inst))


    ##############################################################################
    # Checks whether new session_id falls in expected range or not
    # ie. If new_id is greater than old_id, or less than old_id (in
    # case of wrap-up) it falls in expected range
    def in_expected_sessionseq_range(self, new_id, old_id):
        try:
            return self.in_expected_range(new_id, old_id)
        except Exception as inst:
            logger.critical("Exception in in_expected_sessionseq_range: " + str(inst))


    ##############################################################################
    # Checks whether new subseq_no is valid or not
    def in_expected_subseq_range(self, new_subseq_no, inst_id):
        try:
            upper_limit = self.highest_gn_subseq_no[inst_id] + self.gn_window_size
            # 1. Ex: highest_gn_subseq_no == ackd_gn_subseq_no so acceptable msgs can fall in range
            #    highest_gn_subseq_no < *HERE* <= highest_gn_subseq_no + gn_window_size
            # 2. Ex: ackd_gn_subseq_no < highest_gn_subseq_no so acceptable msgs can fall in range
            #    ackd_gn_subseq_no < *HERE* <= highest_gn_subseq_no + gn_window_size
            # 3. Ex: ackd_gn_subseq_no > highest_gn_subseq_no so acceptable msgs can fall in range
            #    ackd_gn_subseq_no < *HERE* <= upper_seq_bytes_limit OR 0 < *HERE* <= (highest_gn_subseq_no + gn_window_size)
            #    Explanation for limit_due_to_wrap_up: suppose upper_seq_bytes_limit=255 and gn_window_size=2
            #    and highest_gn_subseq_no=254 then upper_limit(calculated above)=256 which is invalid
            #    so set another limit_due_to_wrap_up which will be (in this case): 1
            #    Wrap-up can occur in both 1 & 2 cases above and 3rd is essentially wrap up
            if upper_limit > self.upper_seq_bytes_limit:
                limit_due_to_wrap_up = (self.highest_gn_subseq_no[inst_id] + \
                self.gn_window_size) - (self.upper_seq_bytes_limit)
                upper_limit = self.upper_seq_bytes_limit
            else:
                # placeholder value
                limit_due_to_wrap_up = -1
                
            #return (ackd_gn_subseq_no < new_subseq_no <= upper_limit) or (0 < new_subseq_no <= limit_due_to_wrap_up) 
            if self.highest_gn_subseq_no[inst_id] >= self.ackd_gn_subseq_no[inst_id]:
                return (self.ackd_gn_subseq_no[inst_id] < new_subseq_no <= upper_limit) or\
                (0 < new_subseq_no <= limit_due_to_wrap_up)
            return (self.ackd_gn_subseq_no[inst_id] < new_subseq_no <= \
            self.upper_seq_bytes_limit) or (0 < new_subseq_no <= upper_limit)
        except Exception as inst:
            logger.critical("Exception in in_expected_subseq_range: " + str(inst))


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
            logger.critical("Exception in valid_new_session_id: " + str(inst))
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
            " for:" + str(inst_id) )


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
            logger.critical("Exception in save_session_id: " + str(inst))


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
                # check if the GN's inst_id in the self.highest_gn_subseq_no dict is present or not
                if inst_id in self.highest_gn_subseq_no:
                    if (self.in_expected_subseq_range(new_subseq_no, inst_id)):
                        match = 0
                        # check for duplicate old msg whose ACK is already sent
                        for response in self.sent_ncAckBfr[inst_id]:
                            # comparing the seq_no of new msg with reply_id of bfrd response
                            if response[0] == new_session_id and response[1] == new_subseq_no:
                                logger.critical("ACK Lost so old msg with\
                                subseq_no:"+str(new_subseq_no)+ " received.............\n\n")
                                # resend response
                                self.send_msg_to_gn(inst_id, response[2])
                                match = 1
                        if not match:
                            # check if the msg has been already received
                            # but not responded so it does not have any entry in bfrd_responses
                            for seq_no in self.unprocessed_gnSeqNos[inst_id]:
                                # comparing the subseq_no of new msg with
                                # saved subseq_no not yet acknowledged
                                if seq_no[0] == new_session_id and seq_no[1] == new_subseq_no:
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
                # For this GN: update current ackd_gn_subseq_no and highest_gn_subseq_no based on the new received nos 
                new_highest_gn_subseq_no = self.convert_to_int(msg.header.sequence_id[self.seq_no_partition_size:])
                new_ackd_gn_subseq_no = self.convert_to_int(msg.header.user_field1)
                self.highest_gn_subseq_no[inst_id] = self.get_new_no(new_highest_gn_subseq_no, self.highest_gn_subseq_no[inst_id])
                new_ackd_gn_subseq_no = self.get_new_no(new_ackd_gn_subseq_no, self.ackd_gn_subseq_no[inst_id])
                if self.ackd_gn_subseq_no[inst_id] != new_ackd_gn_subseq_no:
                    self.ackd_gn_subseq_no[inst_id] = new_ackd_gn_subseq_no
                    # discard all responses whose ACKs are received
                    self.discard_ackd_responses(inst_id)
            else:
                logger.critical("Unexpected seq_no received: "+str(new_subseq_no)+\
                    ": when highest_gn_subseq_no: "+str(self.highest_gn_subseq_no[inst_id])\
                        +": ackd_gn_subseq_no: "+str(self.ackd_gn_subseq_no[inst_id]))
                logger.critical("new_session_id: "+str(new_session_id)+\
                    ": old_session_id: "+str(old_session_id))
            logger.debug("new_subseq_no:"+str(new_subseq_no))
            logger.debug("highest_gn_subseq_no[inst_id]"+str(self.highest_gn_subseq_no[inst_id]))
            logger.debug("ackd_gn_subseq_no[inst_id]"+str(self.ackd_gn_subseq_no[inst_id]))
            return ret_val
        except Exception as inst:
            logger.critical("Exception in new_msg: " + str(inst))

    ##############################################################################
    def __del__(self):
        print self, 'gn_msgs_bufr_mngr object died.'




