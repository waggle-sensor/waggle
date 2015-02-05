from gn_global_definition_section import add_to_thread_buffer, buffered_msg, \
msg_from_nc, asynchat_msg_terminator, logger
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
        # Used to signal that the NC is down so stop receiving. At present there is no 
        # way to signal to stop sending to asynchat when NC is down, asynchat buffers msgs 
        # in the output_buffer until connection is restablished 
        self.shutdown = 0
        self.set_terminator(asynchat_msg_terminator)                                             
        logger.debug("Thread "+self.thread_name+" Initialized.\n\n")
        
        
    ##############################################################################    
    # Retrieves the stored IP and connects to it and starts the polling loop.
    # In case of connection failure retries after 10 secs
    def run(self):
        try:
            nc_ip = self.get_nc_ip()
            logger.debug("Starting " + self.thread_name + "\n\n")
            self.shutdown = 0
            self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
            self.connect( (nc_ip, self.nc_port) )                                                             
            logger.info("CONNECTED............."+"\n\n")
            while True:
                # Starts the loop which polls the open socket for *count* times,
                # comes out of the asyncore loop and then repeats after 0.01s
                # Performance widely varies based on sleep time and count's value
                # When count=0/None control will never come out of the asyncore loop
                asyncore.loop(timeout=0.01, use_poll=True, map=None)  # , count=n) can be added. n>=1                                                                   
                time.sleep(0.01)
        except Exception as inst:
            logger.critical("Exception in run: " + str(inst) + "\n\n")
            self.shutdown = 1
            self.handle_close()
            logger.critical("Error in connecting with the NC.\n\n") 
            time.sleep(10)
            self.run()


    ##############################################################################    
    # Called when the socket is readable 
    # Appends data to the input buffer till the terminating character is detected
    # which indicates the end of the msg after which the found_terminator is called
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
    # Handles the msg by calling handle_request and then empties the input_buffer\
    # to receive the next msg 
    def found_terminator(self):
        try:
            if self.shutdown == 0:
                # logger.critical("Msg received from NC:"+str('%0.4f' % time.time())\
                # +str(self.input_buffer)+"\n\n") #+
                logger.critical("Msg received from NC:"+str('%0.4f' % time.time())\
                + "<<<<<<<<<<<<<<<<<<<<")
                self.handle_request()
                logger.debug("Msg handled.\n\n")
                self.input_buffer = []
            else:
                logger.critical("Socket is closed.\n\n")
        except Exception as inst:
            logger.critical("Exception in found_terminator: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Recreates the complete msg by concatenating different fragments of it
    # and sends to buffer_mngr's buffer
    def handle_request(self):
        try:
            msg = ''
            if self.shutdown == 0:
                # recreates msg by concatenating list's elements
                for single_msg in self.input_buffer:
                    msg = msg + single_msg
                msg = buffered_msg(msg_from_nc, None, None, None, msg) 
                # Sends msg to the buffer_mngr's buffer                
                add_to_thread_buffer(self.buffer_mngr.bfr_for_out_to_in_msgs, msg, "Buffer Mngr")                                             
                logger.debug("Msg forwarded to buffer_mngr.\n\n")    
        except Exception as inst:
            logger.critical("Exception in handle_request: " + str(inst) + "\n\n")
    
    
    ##############################################################################    
    # Called when an error occurs
    def handle_error(self):
        try:
            logger.critical("Error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n")
            self.handle_close()
        except Exception as inst:
            logger.critical("Exception in handle_error: " + str(inst) + "\n\n")
    
    
    ##############################################################################
    # Loops till an IP address other than loopback is obtained
    def get_nc_ip(self):
        ip = '127.0.0.1'
        return ip
        while ip == '127.0.0.1':
            logger.info("Waiting to get NC's IP..")
            time.sleep(1)
            try:
                ip = open('nc_ip','r').read()
            except Exception as inst:
                logger.critical("Exception in get_nc_ip: " + str(inst)+ "\n\n")
        return ip
    
    
    ##############################################################################
    # Closes the socket and returns when called by buffer_mngr \
    # else closes the socket for sometime and reopens
    def handle_close(self):
        try:
            if self.shutdown == 0:
                self.shutdown = 1
                NC_down = 1
                self.close()
                logger.critical("Socket Connection with NC closed.\n\n")
                logger.critical("Retry after sometime.\n\n")
                time.sleep(10)
                self.run()
            # When this function called by buffer_mngr
            else:                                                           
                self.close()
                logger.critical("Socket Connection with NC closed.\n\n")                
        except Exception as inst:
            logger.critical("Exception in handle_close: " + str(inst) + "\n\n")
    
    
    ##############################################################################
    def __del__(self):
        print self, 'Socket object died'

