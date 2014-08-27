from nc_internal_communicator_class import internal_communicator
from nc_global_definition_section import gn_socket_list, logger 
from global_imports import threading, time
import asyncore
import asynchat
import socket

        
# nc_server (object of nc_server_class): It listens for incoming registration requests of guest nodes and once a request is 
# received, it creates a new object of class async_msg_hndler and passes the new socket's details to that.
class nc_server_class(threading.Thread, asyncore.dispatcher):
    
        
    ##############################################################################
    def __init__(self, thread_name, socket_type, port_for_gn):
        asyncore.dispatcher.__init__(self)
        threading.Thread.__init__(self)
        self.thread_name = "Thread_" + thread_name                                                          # used by logging module for printing messages related to this thread
        self.daemon = True
        self.port_for_gn = port_for_gn                                                                      # server listens at this port
        self.gn_msgs_buffer_mngr= ''                                                                        # to save global gn_msgs_buffer_mngr_buffer's input_buffer's address to pass to internal_communicator objects
        self.create_socket(socket_type, socket.SOCK_STREAM)
        logger.debug(self.thread_name+" Initialized."+"\n\n")
        
            
    ##############################################################################    
    def run(self):
        try:
            self.bind(("130.202.92.198", self.port_for_gn))
            #self.bind(("140.221.10.105", self.port_for_gn))
            #self.bind(("10.1.2.3", self.port_for_gn))
            self.listen(5)                                                                                  # starts listening for GN registration request
            logger.info("Listening on port_for_gn: " + str(self.port_for_gn)+"\n\n")
            while True:
                asyncore.loop(timeout=0.01, use_poll=False, map=None, count=1000)                                                                         # starts the loop which constantly checks whether the socket is readable or writable
                time.sleep(0.01) 
        except Exception as inst:
            logger.critical("Exception in nc_server run(): " + str(inst)+"\n\n")
            time.sleep(10)
            self.run()
            
        
    ##############################################################################
    def pass_thread_address(self, gn_msgs_buffer_mngr): 
        self.gn_msgs_buffer_mngr = gn_msgs_buffer_mngr
        logger.debug("buffer address of gn_buffer_mngr saved."+"\n\n")
    
        
    ##############################################################################
    def handle_accept(self):
        try:
            logger.info("New GN connection available." + "\n\n")
            gn_socket_conn, gn_addr = self.accept()                                                                 # New GN is trying to connect
            gn_socket_list.append(internal_communicator(gn_socket_conn, gn_addr, self.gn_msgs_buffer_mngr))           # Pass GN's details and new socketis details by creating a different socket object for that GN
            #logger.debug("Socket object corresponding to new GN created and running.")
        except:
            logger.critical("Error in handling the GN connection request."+ "\n\n")
            pass
            
        
    ##############################################################################
    def handle_close(self):
        # close all individual gn sockets
        self.close_gn_socket()
        self.close()
        logger.critical("Server Socket closed."+"\n\n")
    
        
    ##############################################################################
    def close_gn_socket(self):
        for socket in gn_socket_list:
            socket.handle_close()
            logger.info("Individual GN socket closed.")
        logger.critical("NC's individual GN sockets closed."+"\n\n")
        
        
    ##############################################################################
    def handle_error(self):
        logger.critical("Server error."+"\n\n")
        self.run()
    
        
    ##############################################################################
    def __del__(self):
        print self, 'Server object died\n\n'
