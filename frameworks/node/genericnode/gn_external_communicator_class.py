from gn_global_definition_section import add_to_thread_buffer, buffered_msg, \
asynchat_msg_terminator, logger
from global_imports import *
import asyncore                                                                                                                 
import asynchat                                                                                                                 
import socket                                                                                                                   

"""
# This handles all communication with NC. 
# When it receives the message from NC it will read the message till it finds\
# the terminating character of the message and then it sends the message to the buffer_mngr. 
# Also handles the sending of the data which is in its output buffer to the NC. 
"""
class external_communicator_class(asynchat.async_chat, threading.Thread):
    
    ac_in_buffer_size = 4096
    ac_out_buffer_size = 4096
    
    ##############################################################################
    def __init__(self, thread_name, nc_port, buffer_mngr):
        threading.Thread.__init__(self)
        # can be used by logging module for printing messages related to this thread
        self.thread_name = thread_name                                              
        self.daemon = True
        # Static port where NC listens and where connection request can be sent
        self.nc_port = nc_port                                                      
        asynchat.async_chat.__init__(self)
        self.input_buffer = []                                                      
        self.output_buffer = ""                                                                                                                                                      
        self.buffer_mngr = buffer_mngr
        self.set_terminator(asynchat_msg_terminator)                                             
        logger.debug("Thread "+self.thread_name+" Initialized.\n\n")
        
        
    ##############################################################################    
    # Retrieves the stored IP and connects to it and starts the polling loop.
    # In case of connection failure retries after 10 secs
    def run(self):
        try:
            nc_ip = self.get_nc_ip()
            logger.debug("Starting " + self.thread_name + "\n\n")
            self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
            self.connect( (nc_ip, self.nc_port) )                                                             
            logger.info("CONNECTED............."+"\n\n")
            while True:
                # Starts the loop which polls the open socket for *count* times,
                # comes out of the asyncore loop and then repeats after 0.011s
                # Performance widely varies based on sleep time and count's value
                # When count=0/None control will never come out of the asyncore loop
                asyncore.loop(timeout=0.01, use_poll=True, map=None)  # , count=n) can be added. n>=1                                                                   
                time.sleep(0.011)
        except Exception as inst:
            logger.critical("ERROR: Exception in run: " + str(inst) + "\n\n")
            self.close()
            logger.critical("Retry after sometime.\n\n")
            time.sleep(10)
            self.run()


    ##############################################################################    
    # Called when the socket is readable 
    # Appends data to the input buffer till the terminating character is detected
    # which indicates the end of the msg after which the found_terminator is called
    def collect_incoming_data(self, data):
        try:
            """Buffer the data"""
            self.input_buffer.append(data)
            logger.debug("Data received from NC.\n\n")
        except Exception as inst:
            logger.critical("ERROR: Exception in collect_incoming_data: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Called when the specified terminating character is detected in the received message
    # Handles the msg by calling handle_request and then empties the input_buffer\
    # to receive the next msg 
    def found_terminator(self):
        try:
                # logger.critical("Msg received from NC:"+str('%0.4f' % time.time())\
                # +str(self.input_buffer)+"\n\n") #+
                #logger.critical("Msg received from NC:"+str('%0.4f' % time.time())\
                #+ "<<<<<<<<<<<<<<<<<<<<")
                self.handle_request()
                logger.debug("Msg handled.\n\n")
                self.input_buffer = []
        except Exception as inst:
                logger.critical("ERROR: Exception in found_terminator: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Recreates the complete msg by concatenating different fragments of it
    # and sends to buffer_mngr's buffer
    def handle_request(self):
        try:
            msg = ''
                # recreates msg by concatenating (input_buffer) list's elements
            for single_msg in self.input_buffer:
                msg = msg + single_msg
            msg = buffered_msg(None, None, None, msg) 
            # Sends msg to the buffer_mngr's buffer                
            add_to_thread_buffer(self.buffer_mngr.incoming_ncAckBfr, msg, "Buffer Mngr")                                             
            logger.debug("Msg forwarded to buffer_mngr.\n\n")    
        except Exception as inst:
            logger.critical("ERROR: Exception in handle_request: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Called when an error occurs
    def handle_error(self):
        try:
            logger.critical("Error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n")
            self.handle_close()
        except Exception as inst:
            logger.critical("ERROR: Exception in handle_error: " + str(inst) + "\n\n")
    
    
    ##############################################################################
    # Loops till an IP address other than loopback is obtained
    def get_nc_ip(self):
        #while ip == '127.0.0.1':
            #logger.info("Waiting to get NC's IP..")
            #time.sleep(1)
            try:
                ip = open('nc_ip','r').readline().split('\n')[0]
                return ip
            except Exception as inst:
                logger.critical("ERROR: Exception in get_nc_ip: " + str(inst)+ "\n\n")
        
    
    
    ##############################################################################
    # Closes for sometime and reopens
    def handle_close(self):
        try:
            self.close()
            logger.critical("ERROR: Socket Connection with NC closed. Retrying...\n\n")
            time.sleep(5)
            self.run()
        except Exception as inst:
            logger.critical("ERROR: Exception in handle_close: " + str(inst) + "\n\n")
    
    
    ##############################################################################
    def __del__(self):
        logger.critical(self+'Socket object died')

