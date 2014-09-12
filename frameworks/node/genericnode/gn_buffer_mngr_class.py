from global_imports import *
from commands import getoutput as bashit
from gn_external_communicator_class import external_communicator_class

from gn_global_definition_section import get_instance_id,  msg_to_nc,  msg_from_nc,  start_communication_with_nc_event, \
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
 unacknowledged_msg_handler_info is saved in bfr_for_sent_msgs
 unacknowledged_msg_handler_info's format: [session_id, \
 last_gn_subseq_no, expiration_time, encoded_msg, msg_handler_no, inst_id]
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
			self.bfr_for_in_to_out_msgs = Queue.Queue(maxsize=1000)
			# Stores only sent reg/data/cmds not replies/ACKs
			self.bfr_for_sent_msgs =[]
			self.bfr_for_out_to_in_msgs = Queue.Queue(maxsize=1000)
			# Stores only sent replies/ACKs
			self.bfr_for_sent_responses = []
			# Stores the sequence nos which are received but unacknowledged
			self.temp_acks = []							     
			###############################
			# Port where NC listens for GNs
			self.nc_port = nc_port                          
			self.main_thread_ = ''
			self.sensor_controller = ''
			self.external_communicator = ''
			self.log_file_name = 'GN_msg_log'
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
			self.last_gn_subseq_no = self.default_seq_no  
			# subseq_no of the last msg (excluding duplicate) sent to GN
			self.last_nc_subseq_no = self.default_seq_no 
			# subseq_no of the last msg of GN (excluding duplicate) acknowledged by NC
			self.ackd_gn_subseq_no = self.default_seq_no 
			# subseq_no of the last msg of NC (excluding duplicate) acknowledged by GN
			self.ackd_nc_subseq_no = self.default_seq_no                                      
			# currently all tests are done using same window_size for GN and NC
			self.gn_window_size = 1
			self.nc_window_size = 1
			logger.debug("Thread "+self.thread_name+" Initialized.\n\n")
		except Exception as inst:
			logger.critical("Exception in  init function: " + str(inst) + "\n\n")
		

	##############################################################################
	# Loops through all the buffers constantly
	def run(self):
		try:
			logger.debug("Starting " + self.thread_name + "\n\n")
			if not self.communicator_thread_started:
				self.external_communicator = external_communicator_class("external_communicator", self.nc_port, self) 
				self.external_communicator.start()
				self.communicator_thread_started = 1
			wait_time = time.time() + wait_time_for_next_msg
			wait_time_set = 1
			while True:
				while (not self.bfr_for_out_to_in_msgs.empty()) or\
				(not self.bfr_for_in_to_out_msgs.empty()) or (self.bfr_for_sent_msgs):
					self.send_in_to_out_msg()
					self.process_out_to_in_msg()
					self.send_timed_out_msg()
					# set time to remain attentive for few ms
					wait_time = time.time() + wait_time_for_next_msg              
					time.sleep(0.0001)
				if wait_time > time.time():
					time.sleep(0.0001)
				else:
					time.sleep(0.1)
		except Exception as inst:
			logger.critical("Exception in bufr_mngr run: " + str(inst) + "\n\n")
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
			logger.debug("Addresses of main_thread and sensor_controller saved.\n\n")
		except Exception as inst:
			logger.critical("Exception in pass_thread_address: " + str(inst)+"\n\n")


	##############################################################################
	# Initializes the handler_vector_table by mapping handler nos with the names
	# To call a function, its no. is used  as an index in handler_vector_table
	def initialize_handler_vector_table(self):
		try:
			self.handler_vector_table[self.reg_msg_handler_no] = self.reg_msg_handler 
			self.handler_vector_table[self.data_msg_handler_no] = self.data_msg_handler
			logger.debug("Handler vector table initialized.\n\n")
		except Exception as inst:
			logger.critical("Exception in  initialize_handler_vector_table: " + str(inst) + "\n\n")
		
	
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
			logger.debug("Seq_no. initialized.\n\n")
			return session_id
		except Exception as inst:
			logger.critical("Exception in initialize_gn_session_id: " + str(inst) + "\n\n")
		
	
	##############################################################################
	# Resets the data structures related to NC when GN first contacts NC after
	# NC is up
	def reset_nc_specific_data_structures(self):
		try:
			self.last_nc_subseq_no = self.default_seq_no
			self.ackd_nc_subseq_no = self.default_seq_no
			self.temp_acks = []                               
			self.bfr_for_sent_responses = []
		except Exception as inst:
			logger.critical("Exception in reset_nc_specific_data_structures: " + str(inst)+"\n\n")

	
	##############################################################################
	# Sends msgs to NC through external_communicator by reading one msg 
	# from the queue everytime
	# Attaches msg_header and encodes msg and saves it before sending
	def send_in_to_out_msg(self):
		try:
			if not self.bfr_for_in_to_out_msgs.empty():
				send_msg = 1
				item = self.bfr_for_in_to_out_msgs.get()				
				if item.msg_type != reply_type and self.is_bfr_for_sent_msgs_full():
					# push the msg back in the queue as the msg is not a simple
					# reply and the sent_msgs buffer is full so protocol does 
					# not allow to send any new msg
					self.bfr_for_in_to_out_msgs.put(item)
				else:
					encoded_msg = self.gen_msg(item)
					encoded_msg = encoded_msg + asynchat_msg_terminator
					# save the copy of msg in sent_msgs buffer
					if item.msg_type != reply_type:
						expiration_time = self.calculate_expiration_time(item.msg_type, item.msg)
						msg_handler_no = self.get_msg_handler_no(item.msg_type)
						unacknowledged_msg_handler_info = [self.gn_session_id,\
						self.last_gn_subseq_no, expiration_time, encoded_msg, msg_handler_no]  
						logger.debug("Buffer size of buffer_mngr's output buffer\
						before adding item: " + str(len(self.bfr_for_sent_msgs))+"\n\n")
						self.add_to_sent_msgs_bfr(unacknowledged_msg_handler_info)
						logger.debug("Msg waiting for ACK inserted in sorted buffer.\n\n")
					# save the copy of ACK in sent_responses buffer
					else:
						session_id = self.convert_to_int(item.reply_id[:self.seq_no_partition_size])
						ackd_id = self.convert_to_int(item.reply_id[self.seq_no_partition_size:])
						for msg_id in self.temp_acks:
							if msg_id[0] == session_id and msg_id[1] == ackd_id:
								self.temp_acks.remove(msg_id)
						# Check whether this is not a response for the old msg with old session_id
						if session_id == self.nc_session_id:
							self.bfr_for_sent_responses.append((session_id, ackd_id, encoded_msg))
						# as its an old msg don't send it
						else:
							send_msg = 0
							logger.critical("Session id of NC has changed so \
							discarding msg..............\n\n")
					if send_msg:
						self.send_msg_to_nc(encoded_msg)
				self.bfr_for_in_to_out_msgs.task_done()
		except Exception as inst:
			logger.critical("Exception in send_in_to_out_msg: " + str(inst) + "\n\n")
		
					
	
	##############################################################################
	# Processes msgs in the bfr_for_out_to_in_msgs coming from NC
	# Decodes msg and decides whether it should be accepted or not
	# Processes simple ACKS and forwards other msgs (in future cmd) to main_thread 
	# or sensor_controller
	def process_out_to_in_msg(self):
		try:
			if not self.bfr_for_out_to_in_msgs.empty():
				item = self.bfr_for_out_to_in_msgs.get()
				logger.debug("Msg from NCR:" + str(item.msg) + "\n\n")
				try:
					decoded_msg = Message.decode(item.msg)
				except Exception as inst:
					logger.critical("Exception while decoding msg: " + str(inst) + "\n\n")
					logger.critical("So discarding msg............." + str(inst) + "\n\n")
					self.bfr_for_out_to_in_msgs.task_done()
					return
				# check whether the msg is new or duplicate
				if self.new_msg(decoded_msg):
					# when an ACK is obtained delete the corresponding waiting msg
					if decoded_msg.header.message_type == reply_type:
						session_id = self.convert_to_int(decoded_msg.header.reply_to_id[:self.seq_no_partition_size])
						subseq_no = self.convert_to_int(decoded_msg.header.reply_to_id[self.seq_no_partition_size:])
						msg_info = self.get_and_del_saved_msg(session_id, subseq_no)   
						self.handler_vector_table[msg_info[4]](msg_info, decoded_msg)   
					# (For future use) cmd obtained so send it to proper thread
					else:
						session_id = self.convert_to_int(decoded_msg.header.sequence_id[:self.seq_no_partition_size])
						subseq_no = self.convert_to_int(decoded_msg.header.sequence_id[self.seq_no_partition_size:])
						# save the last_nc_subseq_no till its ack is actually
						# inserted after receiving from another thread
						self.temp_acks.append((session_id, subseq_no))
						# a new cmd from NC so send it to apt thread: sensor_ctlr or main_class
						self.dispatch_cmd(decoded_msg)
				else:
					logger.critical("OLD MSG DISCARDED.............\n\n")
				self.bfr_for_out_to_in_msgs.task_done()
		except Exception as inst:
			logger.critical("Exception in process_out_to_in_msg: " + str(inst) + "\n\n")
		
	
	##############################################################################
	# Resend timed out msg
	def send_timed_out_msg(self):
		try:
			if self.bfr_for_sent_msgs:
				timed_out_msg_info = self.get_timed_out_msg_info()
				if timed_out_msg_info:
					self.handler_vector_table[timed_out_msg_info[4]](timed_out_msg_info, None)
		except Exception as inst:
			logger.critical("Exception in send_timed_out_msg: " + str(inst) + "\n\n")
		
	
	##############################################################################
	# Sends msg to NC by pushing it in the output buffer of external_communicator
	def send_msg_to_nc(self, msg):
		try:
			self.external_communicator.push(msg)
			# logger.critical("Msg Sent to NC:"+str('%0.4f' % time.time())+ \
			# "\tcount:" + str(self.sent_msg_count) + "\t" + str(encoded_msg)+"\n\n") # 
			# logger.critical("Msg Sent to NC:"+str('%0.4f' % time.time())+":"\
			# +str(self.last_gn_subseq_no)+ ":"+str(self.ackd_gn_subseq_no)+"\n\n")
			logger.critical("Msg Sent to NC:"+str('%0.4f' % time.time())+"\n\n")
		except Exception as inst:
			logger.critical("Exception in send_msg_to_nc: " + str(inst)+"\n\n")
			self.send_msg_to_nc()
	
	
	##############################################################################    
	# Checks whether first msg in bfr_for_sent_msgs has timed out and if so, 
	# returns it
	def get_timed_out_msg_info(self):
		try:
			msg_handler_info = self.bfr_for_sent_msgs[0]
			if msg_handler_info[2] < time.time():
				self.bfr_for_sent_msgs.remove(msg_handler_info)
				return msg_handler_info
			return None
		except Exception as inst:
			logger.critical("Exception in get_timed_out_msg_info: " + str(inst)+"\n\n")
	

	##############################################################################
	# Saves copy of the sent msg (not data/reg/ACK) in buffer of respective GN
	def add_to_sent_msgs_bfr(self, msg_handler_info):
		try:
			logger.debug("Buffer size of GN_msgs_buffer_mngr's output buffer \
			before adding item: " + str(len(self.bfr_for_sent_msgs))+"\n\n")
			self.bfr_for_sent_msgs.append(msg_handler_info)
			# sorted based on time so retrieval for expired msgs is in FIFO order
			sorted(self.bfr_for_sent_msgs, key=lambda x: x[2])                                              
			logger.debug("Msg waiting for ACK inserted in sorted buffer."+"\n\n")
		except Exception as inst:
			logger.critical("Exception in add_to_sent_msgs_bfr: " + str(inst) + "\n\n")
		

	##############################################################################
	#TODO: hook to dispatch cmds to apt thread: main or sensor_controller
	def dispatch_cmd(self, decoded_msg):
		pass
	
	
	##############################################################################
	# Discards all the old msgs in the bfr_for_sent_responses whose reply_id is
	# behind or equal to the acknowledged seq_no in the sequence sent by the NC
	def discard_ackd_responses(self):
		try:
			if self.last_nc_subseq_no < self.ackd_nc_subseq_no:
				# wrap-up case
				lower_limit = self.last_nc_subseq_no
			else:
				# place holder value
				lower_limit = -1
			for response in self.bfr_for_sent_responses:
				if response[0] != self.nc_session_id:
					self.bfr_for_sent_responses.remove(response)
				# check whether the buffered_response's reply_id ie. NC's \
				# seq_no is now outside nc's current window
				elif lower_limit < response[1] <= self.ackd_nc_subseq_no:
					self.bfr_for_sent_responses.remove(response)
				else:
					# as ACKS are stored in FIFO order
					break
		except Exception as inst:
			logger.critical("Exception in discard_ackd_responses: " + str(inst)+"\n\n")
	
	
	##############################################################################    
	# From bfr_for_sent_msgs deletes & returns msg_info for a specific msg whose ACK is obtained  
	def get_and_del_saved_msg(self, session_id, subseq_no):
		try:
			logger.debug("Buffer size of buffer_mngr's output buffer before \
			deleting item: " + str(len(self.bfr_for_sent_msgs))+"\n\n")
			for msg_handler_info in self.bfr_for_sent_msgs:
				if msg_handler_info[0] == session_id and msg_handler_info[1] == subseq_no:
					self.bfr_for_sent_msgs.remove(msg_handler_info)
					if msg_handler_info[1] > self.ackd_gn_subseq_no or\
					msg_handler_info[1] < self.last_gn_subseq_no:
						self.ackd_gn_subseq_no = msg_handler_info[1]
					logger.debug("Msg deleted from bfr_for_sent_msgs and returned.\n\n")
					return msg_handler_info
			return None
		except Exception as inst:
			logger.critical("Exception in get_and_del_saved_msg: " + str(inst)+"\n\n")
	

	##############################################################################
	# Decides whether the bfr is full or not based on the gn's window size
	def is_bfr_for_sent_msgs_full(self):
		try:
			return len(self.bfr_for_sent_msgs) >= self.gn_window_size
		except Exception as inst:
			logger.critical("Exception in is_bfr_for_sent_msgs_full: " + str(inst)+"\n\n")
	
	
	##############################################################################
	# Generates msg by attaching the msg_header to the payloads received from 
	# main_thread or sensor_controller
	def gen_msg(self, item):
		try:
			header = MessageHeader()
			header.instance_id = get_instance_id()
			header.message_type = item.msg_type
			header.sequence_id = self.gen_gn_seq_no()
			header.user_field1 = str(self.convert_to_bytearray(self.ackd_gn_subseq_no))
			header.reply_to_id = item.reply_id
			msg = Message()
			msg.header = header
			for each_msg in item.msg:
				msg.append(each_msg)
			try:
				msg = msg.encode()   
			except Exception as inst:
				logger.critical("Exception while encoding msg: " + str(inst) + "\n\n")
			return msg
		except Exception as inst:
			logger.critical("Exception in gen_msg: " + str(inst)+"\n\n")
	
	
	##############################################################################
	# Increments the current subseq_no which is maintained with NC
	def gen_gn_seq_no(self):
		try:
			self.last_gn_subseq_no = self.increment_no(self.last_gn_subseq_no)
			logger.debug("\tSUBSEQUENCE NO. gen:" + str(self.last_gn_subseq_no)+"\n\n")
			return str(self.convert_to_bytearray(self.gn_session_id)) +\
			str(self.convert_to_bytearray(self.last_gn_subseq_no))
		except Exception as inst:
			logger.critical("Exception in gen_gn_seq_no: " + str(inst)+"\n\n")
	
		
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
			logger.critical("Exception in increment_no: " + str(inst)+ "\n\n")
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
			logger.critical("Exception in get_new_no: " + str(inst)+"\n\n")
		
	
	##############################################################################
	# Checks for wrap-up by comparing old and new nos
	def is_wrap_up(self, no2, no1):
		try:
			return no2 < (no1 - self.error_scope)
		except Exception as inst:
			logger.critical("Exception in is_wrap_up: " + str(inst)+"\n\n")
	
		
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
	def in_expected_subseq_range(self, new_subseq_no):
		try:
			upper_limit = self.last_nc_subseq_no + self.nc_window_size
			if self.last_nc_subseq_no > self.ackd_nc_subseq_no:
				if upper_limit > self.upper_seq_bytes_limit:
					limit_due_to_wrap_up = (self.last_nc_subseq_no + \
					self.nc_window_size) - (self.upper_seq_bytes_limit)
					upper_limit = self.upper_seq_bytes_limit
				else:
					limit_due_to_wrap_up = 0
				return (self.ackd_nc_subseq_no < new_subseq_no <= upper_limit) or\
				(0 < new_subseq_no < limit_due_to_wrap_up)
			# due to wrap-up
			return (self.ackd_nc_subseq_no < new_subseq_no <=\
			self.upper_seq_bytes_limit) or (0 < new_subseq_no <= upper_limit)
		except Exception as inst:
			logger.critical("Exception in in_expected_subseq_range: " + str(inst)+"\n\n")

			
	##############################################################################
	# checks whether new_session_id is valid or not
	def valid_new_session_id(self, old_session_id, new_session_id):
		try:
			if old_session_id:
				return self.in_expected_sessionseq_range(new_session_id, old_session_id)
			# if this GN is contacting the NC for the first time then accept any session_id from NC
			return True
		except Exception as inst:
			logger.critical("Exception in valid_new_session_id: " + str(inst)+"\n\n")

		
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
			logger.critical("Exception in get_old_session_id: " + str(inst)+"\n\n")
	
	
	##############################################################################
	# saves the NC or GN session id in log file
	def save_session_id(self, tag_name, session_id):
		try:
			config = ConfigObj(self.log_file_name)
			config[tag_name] = session_id  
			config.write()
		except Exception as inst:
			logger.critical("Exception in save_session_id: " + str(inst) + "\n\n")
	
		
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
				if self.last_nc_subseq_no:
					if (self.in_expected_subseq_range(new_subseq_no)):
						# ACK obtained
						if msg.header.message_type == reply_type:
							reply_subseq_no = self.convert_to_int(msg.header.reply_to_id[self.seq_no_partition_size:])
							# check in sent_msgs bfr for corresponding msg waiting for ACK
							for sent_msg in self.bfr_for_sent_msgs:
								# comparing the seq_no of bfrd msg with reply_id of new msg
								if sent_msg[1] == reply_subseq_no:                       
									ret_val = True
							if not ret_val:
								logger.critical("DUP ACK received for old \
								subseq_no: "+str(reply_subseq_no)+".............\n\n")
						else:
							match = 0
							# check for duplicate old msg whose ACK is already sent
							for response in self.bfr_for_sent_responses:                
								# comparing the seq_no of new msg with reply_id of bfrd response
								if response[1] == new_subseq_no:
									logger.critical("ACK Lost so old msg with subseq_no:"+str(new_subseq_no)+ " received.............\n\n")
									# resend response
									self.send_msg_to_nc(response[2])
									match = 1
							if not match:
								# check if the msg has been already received 
								# but not responded so it does not have any entry in bfrd_responses
								for ack in self.temp_acks:                
									# comparing the subseq_no of new msg with
									# saved subseq_no not yet acknowledged
									if ack[1] == new_subseq_no:
										logger.critical("Old msg with subseq_no: "\
									    	+str(new_subseq_no)+ " received whose ACK\
									    	is not yet sent.............\n\n")
										match = 1
							if not match:
								# else its a new msg
								ret_val = True
					else:
						logger.critical("Unexpected subseq_no received: "\
						+str(new_subseq_no)+":"+str(self.last_nc_subseq_no)+\
						":"+str(self.ackd_nc_subseq_no)+"\n\n")
				# NC is up but GN went down since they last contacted eachother\
				# so no record of subseq_no found 
				else:
					logger.critical("Expected session_id received..........\n\n")
					self.reset_nc_specific_data_structures()
					# save new NC session_id 
					self.nc_session_id = new_session_id
					ret_val = True
			# check whether new session id falls in the expected range with any subseq_no
			elif self.valid_new_session_id(old_session_id, new_session_id):
				logger.critical("Valid new session_id received.............\n\n")
				self.reset_nc_specific_data_structures()
				# save new NC session_id 
				self.nc_session_id = new_session_id
				self.save_session_id("NC Session ID", self.nc_session_id)
				ret_val = True
			else:
				logger.critical("Unexpected seq_no received: "+str(new_session_id)+"\t"+\
					str(new_subseq_no)+".............\n\n")
			if ret_val:
				# save ackd and new seq_nos received from this inst_id
				new_last_nc_subseq_no = self.convert_to_int(msg.header.sequence_id[self.seq_no_partition_size:])
				new_ackd_nc_subseq_no = self.convert_to_int(msg.header.user_field1)
				self.last_nc_subseq_no = self.get_new_no(new_last_nc_subseq_no, self.last_nc_subseq_no)
				new_ackd_nc_subseq_no = self.get_new_no(new_ackd_nc_subseq_no, self.ackd_nc_subseq_no)
				if self.ackd_nc_subseq_no != new_ackd_nc_subseq_no:
					self.ackd_nc_subseq_no = new_ackd_nc_subseq_no
					# discard all responses whose ACKs are received
					self.discard_ackd_responses()
			else:
				logger.critical("Unexpected no received: "+str(new_subseq_no)+\
				": when last_nc_subseq_no: "+str(self.last_nc_subseq_no)+\
				": ackd_nc_subseq_no: "+str(self.ackd_nc_subseq_no)+"\n\n")
				logger.critical("new_session_id: "+str(new_session_id)+\
				" old_session_id: "+str(old_session_id)+"\n\n")
			logger.debug("new_subseq_no:"+str(new_subseq_no))
			logger.debug("last_nc_subseq_no:"+str(self.last_nc_subseq_no))
			logger.debug("ackd_nc_subseq_no:"+str(self.ackd_nc_subseq_no))
			return ret_val 
		except Exception as inst:
			logger.critical("Exception in new_msg: " + str(inst)+"\n\n")
	
	
	##############################################################################
	# Based on msg_type it decides which handler should be called in the event of an ACK or no ACK
	def get_msg_handler_no(self, msg_type):
		try:
			if msg_type == registration_type:
				logger.debug("Fetching registration msg handler no.\n\n")
				return self.reg_msg_handler_no
			elif msg_type == data_type:
				logger.debug("Fetching data msg handler no.\n\n")
				return self.data_msg_handler_no
		except Exception as inst:
			logger.critical("Exception in get_msg_handler_no: " + str(inst)+"\n\n")
		
		
	##############################################################################
	# Takes action based on whether the ACK is obtained or the msg has timed out
	def reg_msg_handler(self, msg_info, reply=None):
		try:
			logger.debug("Registration msg handler called.\n\n")
			if reply:
				for single_response in reply.payloads:
					if single_response.return_value == 0:
						logger.info("\t\tRegistration ACK received.\n\n")
						# change status to YES in config file
						config = ConfigObj(config_file_name)
						config["Registered"] = "YES"
						config["UTC Time"] = single_response.output
						bashit("date -s@"+str(single_response.output))
						config.write()
						start_communication_with_nc_event.set()
						logger.info("Start_communication_with_nc_event is set.\n\n")
					else:
						logger.critical("Unknown ACK received: Discarding..\n\n")
				return   
			# handle failure
			logger.critical("Registration timeout.............\n\n")
			msg_info[2] = self.calculate_expiration_time(registration_type, None)
			self.add_to_sent_msgs_bfr(msg_info)
			self.send_msg_to_nc(msg_info[3])
			logger.critical("Registration msg resent............."+"\n\n")
		except Exception as inst:
			logger.critical("Exception in reg_msg_handler: " + str(inst)+ "\n\n")
		
		
	##############################################################################
	# Takes action based on whether the ACK is obtained or the msg has timed out
	def data_msg_handler(self, msg_info, reply=None):
		try:
			logger.debug("Data msg handler called.\n\n")
			if reply:
				for single_response in reply.payloads:
					if single_response.output == acknowledgment and not single_response.return_value:
						logger.info("\t\tData ACK received.\n\n")
					else:
						logger.critical("Unknown ACK received: Discarding..\n\n")
				return
			# handle failure
			logger.critical("Data Packet timeout.............\n\n")
			msg_info[2] = self.calculate_expiration_time(data_type, None)
			self.add_to_sent_msgs_bfr(msg_info)
			self.send_msg_to_nc(msg_info[3])
			logger.critical("Data msg resent............."+"\n\n")
		except Exception as inst:
			logger.critical("Exception in data_msg_handler: " + str(inst)+ "\n\n")
		
				
	##############################################################################    
	# Based on msg_type and sometimes msg_content, it decides how long it should wait for the ACK
	def calculate_expiration_time(self, msg_type, msg):
		try:
			if msg_type == registration_type:
				wait_time = gn_registration_ack_wait_time
			elif msg_type == data_type:
				wait_time = data_ack_wait_time
			logger.debug("Calculated expiration_time based on msg_type and msg.\n\n")
			return (time.time() + wait_time)
		except Exception as inst:
			logger.critical("Exception in calculate_expiration_time: " + str(inst)+"\n\n")
	
	
	##############################################################################
	# Called by main_thread while exiting
	def close(self):
		try:
			self.external_communicator.shutdown = 1
			self.external_communicator.handle_close()
			self.external_communicator.join(1)
		except Exception as inst:
			logger.critical("Exception in close: " + str(inst)+"\n\n")
	
	
	##############################################################################
	def __del__(self):
		print self, 'bufr_mngr object died'
