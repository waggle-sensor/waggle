from global_imports import *
from gn_global_definition_section import get_instance_id,  add_to_thread_buffer,  buffered_msg,  msg_to_nc, \
start_communication_with_nc_event,  data_type,  sensor_thread_list, \
config_file_name, logger, wait_time_for_next_msg, reply_type
from gn_sensor_plugin import sensor_plugin_class
from config_file_functions import initialize_config_file, ConfigObj


"""
# Creates sensor_plugin object. Calls plug_in sensors and get_sensor_msgs function\
# of this object to import sensor modules and periodically collect data from sensors.
# (For future) Can also process any msg obtained from NC
"""
class sensor_controller_class(threading.Thread):
	
	############################################################################## 
	def __init__(self, thread_name):
		threading.Thread.__init__(self)
		# can be used by logging module for printing messages related to this thread
		self.thread_name = thread_name                                                              
		self.daemon = True
		self.input_buffer = Queue.Queue(maxsize=1000)                                                           
		self.main_thread = ''
		self.buffer_mngr = ''
		self.sensor_msg_delimiter = str(unichr(12))
		logger.debug("Thread "+self.thread_name+" Initialized."+ "\n\n")
	
		
	############################################################################## 
	# Plugs in new sensors and periodically collects data from them and sends\
	# that to NC through buffer_mngr
	# (For future) Can process any cmd/reply obtained from NC
	def run(self):
		try:
			logger.debug("Starting " + self.thread_name+ "\n\n")
			plugin_obj = sensor_plugin_class(self.input_buffer)
			# Import new sensor files if any
			plugin_obj.plugin_sensors()
			wait_time = time.time() + wait_time_for_next_msg
			wait_time_set = 1
			while True:
				"""
				# Collects all the sensor msgs from their respective output_buffers and \
				# puts them into its input_buffer by converting them in proper namedtuple format
				# This might seem to be an overhead as whatever it does is reads\
				# the sensor msgs from their output_buffers and packs them in proper format
				# and puts them back in its own input_buffer and finally gets \
				# them from its input_buffer and sends them to buffer_mngr by preparing data payloads. 
				# But this approach is used to give equal FIFO processing priority to all msgs
				# irrespective of whether they are obtained from sensors or NC and reduce redundancy \
				# in the code.
				"""
				plugin_obj.get_sensor_msgs()
				while not self.input_buffer.empty():
					# Start reading the received msgs only if registration is done
					if start_communication_with_nc_event.is_set():
						item = self.input_buffer.get()
						logger.debug("Msg received."+ "\n\n")
						self.process_msg(item)
						self.input_buffer.task_done()
					# set time to remain attentive for next 200 ms
					wait_time = time.time() + wait_time_for_next_msg
					time.sleep(0.0001)
				if wait_time > time.time():
					time.sleep(0.0001)
				else:
					time.sleep(0.1)
		except Exception as inst:
			logger.critical("Exception: " + str(inst)+ "\n\n")
			self.run()
		finally:
			self.close()
	

	##############################################################################     
	# Processes received msg and based on the type decides the action 
	def process_msg(self, item):
		logger.debug('Msg being processed..'+ "\n\n")
		if item.internal_msg_header == msg_to_nc:
			# If the bfr_for_in_to_out_msgs is empty or msg to be
			# sent is a reply type then process the msg
			if item.msg_type == reply_type or self.buffer_mngr.bfr_for_in_to_out_msgs.empty():
				logger.debug('Received sensor msg.'+ "\n\n")
				if item.msg_type == data_type:
					self.send_data_msg(item)
			# protocol does not allow to send a (data/cmd) msg when
			# bfr_for_in_to_out_msgs is full so push it back in the queue 
			else:
				self.input_buffer.put(item)
			logger.debug("Length of input bfr of sensor_controller:"+str(self.input_buffer.qsize()))
				
		
	##############################################################################         
	# Prepares and sends data msg received from sensors to NC through buffer_mngr    
	def send_data_msg(self, item):
		data_payload = DataPayload()
		data_payload.sens_id = item.msg[0]
		data_payload.read_tm = item.msg[1]
		data_payload.inst_id = get_instance_id()
		ret = True
		for reading_name, reading_type, reading_value, reading_unit, reading_note in\
		zip(item.msg[2], item.msg[3], item.msg[4], item.msg[5], item.msg[6]):
			ret = (ret and data_payload.add_item(reading_name, reading_type, \
			reading_value, reading_unit, reading_note))
		if not ret:
			logger.critical("Error in packing data....................................")
		logger.debug("DATA PAYLOAD:" + str(data_payload) + "\n\n")
		self.send_to_buffer_mngr(data_type, item.reply_id, [data_payload])
		logger.debug("Data msg sent to bufr mngr to send to NC." + "\n\n")
	

	############################################################################## 
	# Adds msg to the buffer_mngr's buffer
	def send_to_buffer_mngr(self, msg_type, reply_id, msg):
		buff_msg = buffered_msg(msg_to_nc, msg_type, None, reply_id, msg)                     
		# Sends msg to buffer_mngr by adding to bfr_for_in_to_out_msgs
		add_to_thread_buffer(self.buffer_mngr.bfr_for_in_to_out_msgs, buff_msg, "Buffer Mngr")
		logger.debug("Msg sent to buffer_mngr." + "\n\n")
		
	
	############################################################################## 
	# Called by main_thread to pass the address of buffer_mngr, main_thread 
	# so that sensor_controller thread can access their variables
	def pass_thread_address(self, main_thread, buffer_mngr): 
		self.main_thread = main_thread
		self.buffer_mngr = buffer_mngr               
		logger.debug("Addresses of main_thread and buffer_mngr saved."+ "\n\n")
	

	##############################################################################   
	# Called by main_thread to join all looping sensor threads before exiting
	def close(self):
		for thread in sensor_thread_list:
			thread.join(1)
		logger.info("All per sensor threads exited."+ "\n\n")
	
	
	##############################################################################  
	def __del__(self):
		print self, 'Sensor Controller object died'
