from gn_global_definition_section import add_to_thread_buffer, buffered_msg, msg_from_nc, terminator, logger
from global_imports import *
import asyncore                                                                                                                 # required for aynchronous sockets
import asynchat                                                                                                                 # required for aynchronous sockets
import socket                                                                                                                   # required for sockets

# external_communicator (object of external_communicator_class): Handles the sending and receiving of messages     
class external_communicator_class(asynchat.async_chat, threading.Thread):
    
    ac_in_buffer_size = 4096
    ac_out_buffer_size = 4096
    
    ##############################################################################
    def __init__(self, thread_name, nc_ip, nc_port, buffer_mngr):
        threading.Thread.__init__(self)
        self.thread_name = thread_name                                              # Used to tag msgs related to this thread by logging module
        self.daemon = True
        self.nc_ip = nc_ip                                                          # Used to connect to NC
        self.nc_port = nc_port                                                      # Static port where NC listens and where connection request can be sent
        asynchat.async_chat.__init__(self)
        self.input_buffer = []                                                      # input buffer to store incoming msgs from NC/GNs
        self.output_buffer = ""                                                     # output buffer to buffer the msgs if the socket is not yet writable                                                                                                   
        self.buffer_mngr = buffer_mngr
        self.shutdown = 0
        self.set_terminator(terminator)                                             # used to detect the end of the incoming msg and take required action once the whole msg is received
        logger.debug("Thread "+self.thread_name+" Initialized.\n\n")
        
    
    ##############################################################################    
    # Called when the socket is readable 
    # Function: Appends data to the input buffer till the terminating character is detected which indicates the end of the msg
    def collect_incoming_data(self, data):
        try:
            if self.shutdown == 0:
                """Buffer the data"""
                self.input_buffer.append(data)
                logger.debug("Data received from NC.\n\n")
        except Exception as inst:
             logger.critical("Exception in collect_incoming_data: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Called when the specified terminating character is detected in the received message
    # Function: Handles the msg by calling handle_request and then empties the input_buffer to receive th next msg 
    def found_terminator(self):
        try:
            if self.shutdown == 0:
                logger.info("Msg from NC!"+"\n\n") #+str(self.input_buffer)+"\n\n")
                self.handle_request()
                logger.debug("Msg handled.\n\n")
                self.input_buffer = []
            else:
                logger.critical("Socket is closed.\n\n")
        except Exception as inst:
             logger.critical("Exception in found_terminator: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Function: Adds msg_from_nc header in the front of the received message 
    # So the incoming msg gets transformed to the form: [msg_from_nc + original msg]
    # Then it adds this msg to buffer  
    def handle_request(self):
        try:
            msg = ''
            if self.shutdown == 0:
                # Creating the full msg by concatenating different fragments of it
                for single_msg in self.input_buffer:
                    msg = msg + single_msg
                msg = buffered_msg(msg_from_nc, None, None, None, msg) 
                add_to_thread_buffer(self.buffer_mngr.msg_buffer, msg, "Buffer Mngr")                                             # Sends to the buffer_mngr's buffer
                logger.debug("Msg forwarded to buffer_mngr.\n\n")    
        except Exception as inst:
             logger.critical("Exception in handle_request: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Called in case of any errors while sending
    def handle_error(self):
        try:
            logger.critical("Error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n")
            self.handle_close()
        except Exception as inst:
            logger.critical("Exception in handle_error: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Thread starts its execution from here    
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name + "\n\n")
            self.shutdown = 0
            self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
            self.connect( (self.nc_ip, self.nc_port) )                                                              # tries to connect to the NC at the specified port no
            logger.info("CONNECTED......................................................."+"\n\n")
            while True:
                asyncore.loop(timeout=0.01, use_poll=False, map=None, count=1000)                                                                                         # starts the loop which constantly checks whether the socket is readable or writable
                time.sleep(0.01)
        except Exception as inst:
            logger.critical("Exception in run: " + str(inst) + "\n\n")
            self.shutdown = 1
            self.handle_close()
            logger.critical("Error in connecting with the NC.\n\n") 
            time.sleep(10)
            self.run()
    
    
    ##############################################################################
    def handle_close(self):
        try:
            if self.shutdown == 0:
                self.shutdown = 1
                NC_down = 1
                self.close()
                logger.critical("Socket Connection with NC closed.\n\n")
                # Notify buffer_mngr that NC is down
                logger.critical("Retry after sometime.\n\n")
                time.sleep(10)
                self.run()
            else:                                                           # A global exception raised by main thread to exit
                self.close()
                logger.critical("Socket Connection with NC closed.\n\n")                
        except Exception as inst:
             logger.critical("Exception in handle_close: " + str(inst) + "\n\n")
    
    
    ##############################################################################
    def __del__(self):
        print self, 'Socket object died'
   
