from nc_global_definition_section import *

# Delete the seq no id mapping entry when gn goes down, clean up everything related to the disconnected gn


# One object of this class is created for each GN and this object handles all communication with that GN. 
# When it receives the message from GN it will read the message till it finds the terminating character 
# of the message and then it adds the message to the gn_msgs_buffer_mngr's buffer: msg_buffer. It also handles the sending
# of the data to the GN which is in its output buffer.
class internal_communicator(asynchat.async_chat):

    logger = set_logging_level("Internal Communicator")
    #logger = logging.getLogger(None)
    ac_in_buffer_size = 4096
    ac_out_buffer_size = 4096
     
    ##############################################################################
    def __init__(self, gn_socket_conn, gn_addr, gn_msgs_buffer_mngr):
        asynchat.async_chat.__init__(self, gn_socket_conn)
        self.gn_addr = gn_addr                                                                                  # contains (gn's ip, gn's port), through which it communicates with NC
        self.input_buffer = []                                                                                  # stores incoming message
        self.output_buffer = ""                                                                                 # stores outgoing message
        self.gn_msgs_buffer_mngr = gn_msgs_buffer_mngr
        self.shutdown = 0
        self.set_terminator(terminator)                                                                         # terminating character indicating the end of the msg received
        self.logger.debug("Internal Communicator for new GN initialized"+"\n\n")
        
        
    ##############################################################################
    # Called when the socket is readable    
    def collect_incoming_data(self, data):
        if self.shutdown == 0:
            try:
                self.logger.debug("Data from GN being received."+"\n\n")
                self.input_buffer.append(data)                                                                          # Buffer the data
            except Exception as inst:
                self.logger.critical("Exception: " + str(inst)+"\n\n")
        else:
            self.logger.critical("Socket Closed."+"\n\n")
         
                
        
    ##############################################################################  
    # Called when the specified terminating character is detected in the received message (here '\n')
    def found_terminator(self):
        if self.shutdown == 0:
            try:
                self.logger.info("Msg from GN:"+str(self.input_buffer)+"\n\n")
                self.handle_request()
                self.logger.debug("Incoming Msg handled."+"\n\n")
                self.input_buffer = []
            except Exception as inst:
                self.logger.critical("Exception: " + str(inst))
        else:
            self.logger.critical("Socket Closed."+"\n\n")
            
        
    ##############################################################################     
    # Recreates the complete msg by concatenating different fragments of it and sends to gn_msgs_buffer_mngr's buffer
    def handle_request(self):
        if self.shutdown == 0:
            msg = ''
            try:
                for single_msg in self.input_buffer:
                    msg = msg + single_msg                                              # convert msg from a list element to a string
                msg = buffered_msg(msg_from_gn, None, None, None, msg, self)
                add_to_thread_buffer(self.gn_msgs_buffer_mngr.msg_buffer, msg, "GN_msgs_buffer_mngr")                                             # Sends to the gn_msgs_buffer_mngr's buffer
                self.logger.debug("Msg sent to gn_msgs_buffer_mngr."+"\n\n")
            except Exception as inst:
                self.logger.critical("Exception: " + str(inst))
        else:
            self.logger.critical("Socket Closed."+"\n\n")
        
        
    ##############################################################################
    def handle_error(self):
        try:
            self.logger.critical("Error!!"+"\n\n")
            self.handle_close()
        except Exception as inst:
            self.logger.critical("Exception: " + str(inst)+"\n\n")
            
        
    ##############################################################################    
    def handle_close(self):
        try:
            self.shutdown = 1
            self.delete_socket()
            self.close() 
            self.logger.critical("Socket Connection with GN closed."+"\n\n")
        except Exception as inst:
            self.logger.critical("Exception: " + str(inst)+"\n\n")
        
        
    ##############################################################################
    def delete_socket(self):
        try:
            if self in gn_socket_list:
                gn_socket_list.remove(self)
            self.logger.critical("Current socket list:"+str(gn_socket_list)+"\n\n")
            self.gn_msgs_buffer_mngr.clean_gn_data(self)
            
        except Exception as inst:
            self.logger.critical("Exception: " + str(inst)+"\n\n")
        
        
    ##############################################################################
    def __del__(self):
        print self, 'Socket object died.'
   