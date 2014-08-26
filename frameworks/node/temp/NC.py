"""
There are total 3 threads:
        
main_t (object of main_thread): Responsible for spawning other threads, processing all the packets and responding to 
cloud's or guest nodes' messages 

gn_msgs_buffer_mngr (object of gn_msgs_buffer_mngr_class): Sends the received messages to main_t's buffer and messages received from main_t to 
the respective socket connected to the specific guest node

nc_server_t (object of nc_server_thread): It listens for incoming registration requests of guest nodes and once a request is 
received, it creates a new object of class internal_communicator and passes the new socket, GN's details to that.
"""
"""
internal_communicator object: When it receives the message it will read the message till it finds the terminating character 
of the message (here it is '\n') and then it adds the message to the gn_msgs_buffer_mngr's buffer: msg_buffer. It also handles the sending
of the data which is in its output buffer.

"""
"""
Questions: should the nc send the registration info to the cloud when gn registers

add event buffer to get replies
send ack for data
send ack for gn_reg
"""

import asyncore
import asynchat
import socket
import logging
import threading
import Queue
import sys
from collections import namedtuple


gn_msgs_buffer_mngr = ''
main_t = ''
nc_server_t = ''

port_for_gn = 8000																								# GNs can request at this port

# Maintains the mapping of internal_communicator object to the corresponding GN represented by gn_id = inst_id
gn_id_socket_obj_mapping = {}

buffered_msg = namedtuple('buffered_msg', ['internal_msg_header', 'msg_gn_mapping'])
msg_gn_mapping = namedtuple('msg_gn_mapping',['gn_socket_obj', 'msg'])
            
        

logging.basicConfig(level=logging.DEBUG,
                    format='%(name)s: %(message)s',
                    )                   

# Returns the internal header like "send_external_msg"/"received_gn_msg"/"received_internal_msg" which is used to distinguish messages present in the buffers inside the NCR
def get_internal_msg_header(msg):
    internal_header_and_msg = msg.split("/")
    return internal_header_and_msg[0]

# Extracts the GN's id which is (ip, port) and msg body
def extract_gn_id_and_msg(msg):
    gn_id_and_msg = msg[1].split("/")
    return msg[0], gn_id_and_msg[1]
    
# Adds internal header like "send_external_msg"/"received_gn_msg"/"received_internal_msg" to the msg
def add_internal_msg_header(msg, header):
    return header + "/" + msg
    
# Adds GN's id which is (gn_ip, gn_port) to the message to indicate the sender GN
def add_gn_id(msg, gn_id):
    return [gn_id,msg]

# Returns the current time in string form
def get_current_time():
    return time.strftime ('%Y.%m.%d.%H.%M.%S')

    
# One object of this class is created for each GN and this object handles all communication with that GN. When it receives the message from GN it will read the message till it finds the terminating character 
# of the message (here it is '\n') and then it adds the message to the gn_msgs_buffer_mngr's buffer: msg_buffer. It also handles the sending
# of the data to the GN which is in its output buffer.
class internal_communicator(asynchat.async_chat):

    logger = logging.getLogger('internal_communicator')
    
    def __init__(self, gn_socket_conn, gn_addr):
        #try: 
        asynchat.async_chat.__init__(self, gn_socket_conn)
        self.gn_addr = gn_addr																					# contains (gn's ip, gn's port), through which it communicates with NC
        self.input_buffer = []																					# stores incoming message
        self.output_buffer = ""																				# stores outgoing message
        self.gn_socket_conn = gn_socket_conn																	# socket specific to each GN
        # gn_id_socket_obj_mapping[gn_addr] = self																					
        self.gn_id_socket_obj_mapped = 0																		# 0 indicates that inst_id of GN is not yet mapped to this object instance 
        self.set_terminator("[0]")																				# terminating character indicating the end of the msg received
        #self.daemon = True
        # TODO: check if this is the proper place to start
        asyncore.loop()																							# loops constantly to check whether the socket is writable or readable
        #except KeyboardInterrupt:
        #    self.logger.debug("Ctrl+c caught")
        #    sys.exit()
    
            
            
    # Called when the socket is readable    
    def collect_incoming_data(self, data):
        
        self.input_buffer.append(data)																			# Buffer the data
        
    # Called when the specified terminating character is detected in the received message (here '\n')
    def found_terminator(self):
        self.logger.debug("Msg received")
        self.handle_request()
        self.input_buffer = []
        
    # Adds "received_gn_msg" header to the front of the received message and also (ip, port) of the sender GN as a tuple
    # So the incoming msg gets transformed to the form: [(ip, port), "received_gn_msg" + original msg]
    # Then it adds the this newly created msg to msg_buffer
    def handle_request(self):
        global gn_msgs_buffer_mngr
    
        decoded_msg = self.input_buffer #decode(self.input_buffer)                                                                           # msg decoding api will return a msg object
            
        if self.gn_id_socket_obj_mapped == 0:
            self.logger.debug("First msg from new GN received.")
            inst_id = "gn1"     # decoded_msg.inst_id
            gn_id_socket_obj_mapping[inst_id] = self
            self.gn_id_socket_obj_mapped = 1
        msg_and_gn = msg_gn_mapping(self, decoded_msg)
        msg = buffered_msg('received_gn_msg', msg_and_gn)
        gn_msgs_buffer_mngr.msg_buffer.put(msg)
        
    
        
# nc_server_t (object of nc_server_thread): It listens for incoming registration requests of guest nodes and once a request is 
# received, it creates a new object of class async_msg_hndler and passes the new socket's details to that.
class nc_server_thread(threading.Thread, asyncore.dispatcher):
    
    logger = logging.getLogger('nc_server_thread')
    
    def __init__(self, thread_name, socket_type, port_for_gn):
        
        asyncore.dispatcher.__init__(self)
        threading.Thread.__init__(self)
        self.thread_name = "Thread_" + thread_name																	# used by logging module for printing messages related to this thread
        self.daemon = True
        self.port_for_gn = port_for_gn																				# server listens at this port
        self.logger.debug(self.thread_name+" Initialized.")
        self.create_socket(socket_type, socket.SOCK_STREAM)
        self.bind(("", port_for_gn))
        
    def run(self):
        try:
            self.logger.debug("Starting " + self.thread_name)
            self.listen(5)																								# starts listening for GN registration request
            self.logger.debug("listening on port_for_gn: " + str(self.port_for_gn))
            asyncore.loop()																								# loops constantly to check whether any new GN is trying to connect
        except KeyboardInterrupt:
            self.logger.debug("Ctrl+c caught")
            sys.exit()
    
    
    def handle_accept(self):
        try:
            self.logger.debug( "connection available")
            gn_socket_conn, gn_addr = self.accept()																	# New GN is trying to connect
            internal_communicator(gn_socket_conn, gn_addr)																	# Pass GN's details and new socketis details by creating a different socket object for that GN
        except KeyboardInterrupt:
            self.logger.debug("Ctrl+c caught")
            sys.exit()
    
    
# gn_msgs_buffer_mngr (object of gn_msgs_buffer_mngr_class): Sends the received messages to main_t's buffer and messages received from main_t to 
# the respective socket connected to the specific guest node        
class gn_msgs_buffer_mngr_class(threading.Thread):
    
    logger = logging.getLogger('gn_msgs_buffer_mngr_class')
    global main_t
    def __init__(self, thread_name):
        
        threading.Thread.__init__(self)
        self.thread_name = "Thread_" + thread_name																	# used by logging module for printing messages related to this thread
        self.daemon = True
        self.msg_buffer = Queue.Queue()																			# stores all incoming as well as outgoing msgs and also internal msgs
        self.logger.debug(self.thread_name+" Initialized.")
        
    def run(self):
        global main_t

        try:
            self.logger.debug("Starting " + self.thread_name)
            # Waits on the buffer till a msg is received       
            while True:
                item = self.msg_buffer.get()
                self.logger.debug("item present in the queue!")
                internal_header = item.internal_msg_header                  								# extracts the header from the data part of the msg
                #  internal_header can be:
                #    1. send_external_msg
                #    2. received_gn_msg
                #    3. received_internal_msg
                self.logger.debug("header:"+str(internal_header))
                # Send the message to internal_communicator's output_buffer to send it to GN
                if  internal_header == "send_external_msg":
                    gn_id, msg = extract_gn_id_and_msg(item)
                    self.logger.debug("To GN: "+str(gn_id)+" Msg: "+str(msg))
                    socket_obj = self.get_socket_obj(gn_id)							
                    socket_obj.push(msg)													# Pushes the msg to the appropriate internal_communicator object's buffer which looks over the socket associated with the specific GN
                
                # Received message from GN so send it to main_t's input_buffer for processing
                elif internal_header == "received_gn_msg":
                    self.logger.debug("From GN: "+str(item.msg_gn_mapping.gn_socket_obj)+" Msg: "+str(item.msg_gn_mapping.msg))
                    main_t.input_buffer.put(item)																		# Sends to the main_t's buffer
                
                else:
                    self.logger.debug("Unknown Msg......................................................")
                    sys.exit()
                
                
                self.msg_buffer.task_done()
        except KeyboardInterrupt:
            self.logger.debug("Ctrl+c caught")
            sys.exit()
    
            
    # Returns the internal_communicator object corresponding to the gn represented by gn_id = (gn_ip, gn_port)          
    def get_socket_obj(self, gn_id):
        socket_obj = gn_id_socket_obj_mapping[gn_id]
        return socket_obj
        
        
# main_t (object of main_thread): Responsible for spawning other threads, processing all the packets and responding to 
# cloud's or guest nodes' messages are processed
class main_thread():
    
    logger = logging.getLogger("main_thread")
    
    # Dict which maintains a mapping of each gn_id and all its information
    # Uses gn_id as the 1st level key, sensor_ids as the second level key, reading_name as the third level key and each reading_name's param_name
    # as the 4th level key and then the values and attributes are the values of the 4th level key (param_name)
    gns_info_dict = {}

    def __init__(self, thread_name, port_for_gn):
        
        self.thread_name = "Thread_" + thread_name																	# used by logging module for printing messages related to this thread
        self.input_buffer = Queue.Queue()																			# stores all incoming msgs from GNs/gn_msgs_buffer_mngr thread
        self.port_for_gn = port_for_gn																				# to be passed to nc_server_thread so that it starts listening for guest's requests on that port
        self.logger.debug(self.thread_name+" Initialized.")
        
    # Runs forever
    def run(self):
        global gn_msgs_buffer_mngr
        global nc_server_t
        try:
            self.logger.debug("Starting " + self.thread_name)
            # Instantiates threads
            gn_msgs_buffer_mngr = gn_msgs_buffer_mngr_class("gn_msgs_buffer_mngr")
            nc_server_t = nc_server_thread("nc_server_thread", socket.AF_INET, self.port_for_gn)
            # Starts Threads
            gn_msgs_buffer_mngr.start()
            nc_server_t.start()
        
            while True:
                #self.logger.debug("Looping " + self.thread_name)
                if not self.input_buffer.empty():
                    item = self.input_buffer.get()
                    internal_header = item.internal_msg_header
                    
                    # Waits on the buffer till a msg is received 
                    if internal_header == "send_external_msg":
                        # adds "send_external_msg" header to the msg and also gn_id = (IP, port)
                        # So the sending msg in gn_msgs_buffer_mngr's buffer will have the form: [(IP, port), "send_external_msg" + original_msg]
                        # process it
                        pass
                    
                    elif internal_header == "received_gn_msg":
                        self.process_external_msg(item)                                               # processes msgs obtained from NC/GNs
                        """	
                        gn_id, msg = extract_gn_id_and_msg(item)
                        self.add_to_gns_info_dict(gn_id, msg)
                        # msg_type, inst_id, sensor_id, reading_time, params_list =  msg_parse.get_ (msg, 0)
                        # GN's registration request
                        if msg_type==0:
                            gn_reg_ack = "Reg_done\n"
                            item = add_internal_msg_header(gn_reg_ack, "send_external_msg")											# so that gn_msgs_buffer_mngr will recognize it as msg for the outer world                    
                            gn_msgs_buffer_mngr.msg_buffer.put([gn_id, item])													# Adds to gn_msgs_buffer_mngr's buffer to send it by adding gn_id = (IP, port) 
                        # Data received from GN
                        elif msg_type == 1:
                            self.logger.debug("Msg received:"+msg)
                            self.update_gns_info_dict(inst_id, sensor_id, reading_time, params_list)						# Stores the recent readings from the GN in gns_info_dict
                        """
                    self.input_buffer.task_done()
                
        except KeyboardInterrupt:
            self.logger.debug("Ctrl+c caught")
            gn_msgs_buffer_mngr.join(1)
            nc_server_t.join(1)
            sys.exit()
    
    # Returns the msg by packing all params using delimiters and adding msg_content = ACK at the end
    def prepare_msg(msg_type, seq_no, reply_id, data):
        # Call proper handlers by converting the data into arrays
        return "1[2]"+str(msg_type)+"[2]gn1[2]" + str(datetime.datetime.now())+"[2]"+str(seq_no) + "[2]"+str(reply_id)+"[1]" + data + "[0]"
        
    """
    # send ACK as soon as some msg is received
    def send_ack(self, msg):
        
        msg_header1 = extract_header1(msg)
        msg_header2 = extract_header2(msg)
        msg_fields1 = get_msg_fields(msg_header1, delimiter_indx)                                               # returns the individual fields of msg_header1 which are delimited by index specified by delimiter_indx
        msg_fields2 = get_msg_fields(msg_header2, delimiter)                                                    # returns the individual fields of msg_header2 which are delimited by index specified by delimiter_indx
        # change msg_type, timestamp, seq_no, reply_id, get inst_id
        now = get_current_time()
        inst_id = msg_fields1[2]                                                                                # assumed that inst_id will be at 4th position in Header level 1
        seq_no = get_seq_no(inst_id)                                                                            # gets the next seq_no for the particular gn (inst_id) from the table gn_id_and_seq_no_dict
        reply_id = msg_fields1[4]                                                                               # assumed that seq_no will be at 5th position in Header level 1, so assigns the seq_no of original msg to reply_id
        send_msg = prepare_ack(version_no, "2", now, inst_id, seq_no, reply_id)
        self.push(send_msg)                                                                                     # sends the immediate ACK 
    """    
    
    # Extracts the msg_id and checks in the output sorted msg queue if its a reply of some msg, 
    # if so then deletes that msg from the output sorted msg queue, takes required action after deleting by calling the msg handler and passing the reply to it
    # If its a new msg then processes based on msg_type 
    def process_external_msg(self, item):
        msg_gn_tuple = item.msg_gn_mapping
        msg = msg_gn_tuple.msg
        self.logger.debug("external msg being processed:"+str(msg))
        gn_socket = msg_gn_tuple.gn_socket_obj
        if msg.reply_id != -1:                                                                                  # its a reply
            if msg.payload != "ACK":
                # send ack for the msg received
                seq_no = gen_seq_no(gn_id)                                                                          # generates the next seq_no for the specific gn who is identified using gn_id
                msg = prepare_msg(2, seq_no, msg.seq_no, "ACK")
                msg_gn_tuple = msg_gn_mapping(gn_socket, msg)
                item = buffered_msg("send_external_msg", msg_gn_tuple)
                add_to_thread_buffer(gn_msgs_buffer_mngr, item)                                  # adds to gn_msgs_buffer_mngr's msg_buffer so that it can send to NC through internal_communicator's object
            # get from the sorted_output_msg_buffer the unacknowledged_msg_info with the same msg_id
            msg_info = get_msg_info_and_delete_from_output_buffer(self.sorted_output_msg_buffer, msg.reply_id)         # removes the msg_info from output sorted msg queue and returns it                                  
            handler[msg_info[3]](msg)                                                                                     # calls the handler whose no is stored in the msg_info at index 3
        # a new msg is received     
        else:
            if msg_type == "0":																								  # Data received
                process_data_msg(msg)
            elif msg_type == "1":
                process_cmd_msg(msg)																						  # Command received
            elif msg_type == "3":
                process_gn_registration_msg																					  # Registration request
            else:
                self.logger.debug("Unknown Msg type received: Aborting...........................................................................")
                exit(-1)
                
            
    # TODO:
    # Input: 
    # Function: Stores the information in gns_info_dict by calling update_gns_info_dict
    def process_data_msg(self, inst_id, sensor_id, reading_time, params_list):
        self.logger.debug("DATA MSG Processed........................................")
        
    
    # TODO:
    # Input: 
    # Function: Stores the information in gns_info_dict by calling update_gns_info_dict
    def process_cmd_msg(self, inst_id, sensor_id, reading_time, params_list):
        self.logger.debug("CMD Processed........................................")
    
    
    # TODO:
    # Input: 
    # Function: Stores the information in gns_info_dict by calling update_gns_info_dict
    def process_reg_msg(self, inst_id, sensor_id, reading_time, params_list):
        #  store gn info in config file
        self.logger.debug("REG MSG Processed........................................")
    
    
    # Input: inst_id - instance id, sensor_id - id of the sensor who has sent the readings, reading_time - time at which reading is taken, params_list - list of reading_name and corresponding values
    # Function: Stores the information in gns_info_dict 
    def update_gns_info(self, inst_id, sensor_id, reading_time, params_list):
        
        pass
    
    # Input: Takes gn_id which is the (ip, port) of GN and msg obtained from GN
    # Function: Creates an entry for the new GN in gns_info_dict and stores that gn's information by parsing the received registration request  
    def add_to_gns_info(self, gn_id, msg):
        self.gns_info_dict[gn_id] = msg     
        
        

# main_t object is created which starts everything else             
main_t = main_thread("main", port_for_gn)  
main_t.run()
    
