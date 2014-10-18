import asyncore
import asynchat
import socket
from global_imports import *
from nc_global_definition_section import buffered_msg,  msg_from_gn,  \
asynchat_msg_terminator,  gn_socket_list,  add_to_thread_buffer, logger, gn_socket_list_lock

"""
# One object of this class is created for each GN and this object handles all 
# communication with that GN. 
# When it receives the message from GN it will read the message till it finds 
# the terminating character of the message and then it sends the message to the buffer_mngr. 
# Also handles the sending of the data which is in its output buffer to the GN.
"""
class internal_communicator(asynchat.async_chat):

    ac_in_buffer_size = 4096
    ac_out_buffer_size = 4096
     
    ##############################################################################
    def __init__(self, gn_socket_conn, gn_addr, buffer_mngr):
        asynchat.async_chat.__init__(self, gn_socket_conn)
        self.gn_addr = gn_addr                                                                                  
        self.input_buffer = []                                                                                  
        self.output_buffer = ""                                                                                 
        self.buffer_mngr = buffer_mngr
        # Used to signal that the GN is down so stop receiving.  
        self.shutdown = 0
        self.set_terminator(asynchat_msg_terminator)                                                                         
        logger.debug("Internal Communicator for new GN initialized"+"\n\n")
        
        
    ##############################################################################
    # Called when the socket is readable
    # Appends data to the input buffer till the terminating character\
    # is detected which indicates the end of the msg after which the found_terminator is called
    def collect_incoming_data(self, data):
        if self.shutdown == 0:
            try:
                logger.debug("Data from GN being received."+"\n\n")
                self.input_buffer.append(data)                                                                          
            except Exception as inst:
                logger.critical("Exception in collect_data: " + str(inst)+"\n\n")
        else:
            logger.critical("Socket Closed."+"\n\n")
                
        
    ##############################################################################  
    # Called when the specified terminating character is detected in the received message
    # Handles the msg by calling handle_request and then empties the input_buffer\
    # to receive th next msg 
    def found_terminator(self):
        if self.shutdown == 0:
            try:
                # logger.critical("Msg received from GN:"+str('%0.4f' % time.time())\
                # +str(self.input_buffer)+"\n\n") #+
                logger.critical("Msg received from GN:"+str('%0.4f' % time.time())+"\n\n")
                self.handle_request()
                logger.debug("Incoming Msg handled."+"\n\n")
                self.input_buffer = []
            except Exception as inst:
                logger.critical("Exception in found_terminator: " + str(inst))
        else:
            logger.critical("Socket Closed."+"\n\n")
            
        
    ##############################################################################     
    # Recreates the complete msg by concatenating different fragments of it
    # and sends to buffer_mngr's buffer
    def handle_request(self):
        if self.shutdown == 0:
            msg = ''
            try:
				# recreates msg by concatenatning list's elements
                for single_msg in self.input_buffer:
                    msg = msg + single_msg                                              
                msg = buffered_msg(msg_from_gn, None, None, None, msg, self)
                # Sends msg to the buffer_mngr's buffer
                add_to_thread_buffer(self.buffer_mngr.bfr_for_out_to_in_msgs,\
                msg, "GN_msgs_buffer_mngr")                                             
                logger.debug("Msg sent to buffer_mngr."+"\n\n")
            except Exception as inst:
                logger.critical("Exception in handle_request: " + str(inst))
        else:
            logger.critical("Socket Closed."+"\n\n")
        
        
    ##############################################################################
    # Called when an error occurs
    def handle_error(self):
        try:
            logger.critical("Error!!"+"\n\n")
            self.handle_close()
        except Exception as inst:
            logger.critical("Exception in handle_error: " + str(inst)+"\n\n")
            
        
    ############################################################################## 
    # Closes the socket after removing its entries wherever present
    def handle_close(self):
        try:
            self.shutdown = 1
            self.delete_socket()
            self.close() 
            logger.critical("Socket Connection with GN closed."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in handle_close: " + str(inst)+"\n\n")
        
        
    ##############################################################################
    # Removes its entries from various GN related data structures
    def delete_socket(self):
        try:
            # Lock acquired to access global list variable and released when the 'with' block ends
            with gn_socket_list_lock:
                if self in gn_socket_list:
                    gn_socket_list.remove(self)
                current_socket_list = ''
                if gn_socket_list:
                    current_socket_list = str(gn_socket_list)
            logger.critical("Current socket list:"+current_socket_list+"\n")
        except Exception as inst:
            logger.critical("Exception in delete_socket: " + str(inst)+"\n")


    ##############################################################################
    def __del__(self):
        print self, 'Socket object died.'
   