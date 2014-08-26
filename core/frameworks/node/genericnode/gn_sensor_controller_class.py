from gn_global_definition_section import *
from sensor_plugin import sensor_plugin_class


##################################################################################
# Registers sensors again even if they are registered once, to change later on
##################################################################################



# sensor_controller (object of sensor_controller_class): Processes msgs related to sensors
class sensor_controller_class(threading.Thread):
    
    logger = set_logging_level("sensor_controller")
        
    ############################################################################## 
    def __init__(self, thread_name):
        threading.Thread.__init__(self)
        self.thread_name = thread_name                                                              # used by logging module for printing messages related to this thread
        self.daemon = True
        self.input_buffer = Queue.Queue(maxsize=1000)                                                           # stores messages sent by buffer_mngr_class, main_class
        self.main_thread = ''
        self.buffer_mngr = ''
        self.sensor_msg_delimiter = str(unichr(12))
        self.logger.debug("Thread "+self.thread_name+" Initialized."+ "\n\n")
    
        
    ############################################################################## 
    def pass_thread_address(self, main_thread, buffer_mngr): 
        self.main_thread = main_thread
        self.buffer_mngr = buffer_mngr               
        self.logger.debug("Addresses of main_thread and buffer_mngr saved."+ "\n\n")
    
        
    ############################################################################## 
    # Runs forever    
    def run(self): 
        try:
            self.logger.debug("Starting " + self.thread_name+ "\n\n")
            if not self.is_config_file_initialized(get_config_file_name()):
                # Waits for the config file to be initialized
                config_file_initialized_event.wait()
                self.logger.debug("Config file initialized."+ "\n\n")
            plugin_obj = sensor_plugin_class(self.input_buffer)
            while True:
                # Checks if any unprocessed msg is in the input buffer
                if not self.input_buffer.empty():
                    self.logger.debug("Waiting for registration to be successful.."+ "\n\n")
                    if start_communication_with_nc_event.is_set():
                        item = self.input_buffer.get()
                        self.logger.debug("Msg received."+ "\n\n")
                        # process the msg
                        self.process_msg(item)
                        self.input_buffer.task_done()
                # Import new sensor files if any
                plugin_obj.plugin_sensors()
                # Puts all the sensor msgs in its input_buffer to sensor_controller's input_buffer by converting them in proper tuple format
                plugin_obj.get_sensor_msgs()  
                time.sleep(0.01)
        except Exception as inst:
            self.logger.critical("Exception: " + str(inst)+ "\n\n")
            self.run()
        finally:
            self.close()
            
        
    ##############################################################################     
    def close(self):
        for thread in sensor_thread_list:
            thread.join(1)
        self.logger.info("All per sensor threads exited."+ "\n\n")
            
        
    ##############################################################################     
    # item: buffered_msg tuple
    def process_msg(self, item):
        self.logger.debug('Msg being processed..'+ "\n\n")
        if item.internal_msg_header == msg_to_nc:
            self.logger.debug('Received sensor msg.'+ "\n\n")
            if item.msg_type == data_type:
                self.send_data_msg(item)
            
        
    ##############################################################################         
    # item: buffered_msg tuple        
    def send_data_msg(self, item):
        data_payload = DataPayload()
        data_payload.sens_id = item.msg[0]
        data_payload.read_tm = item.msg[1]
        data_payload.inst_id = get_instance_id()
        ret = True
        for reading_name, reading_type, reading_value, reading_unit, reading_note in zip(item.msg[2], item.msg[3], item.msg[4], item.msg[5], item.msg[6]):
            ret = ret and data_payload.add_item(reading_name, reading_type, reading_value, reading_unit, reading_note)
        if not ret:
            self.logger.critical("Error in packing data....................................")
        self.logger.debug("DATA PAYLOAD:" + str(data_payload) + "\n\n")
        self.send_to_buffer_mngr(data_type, item.reply_id, data_payload)
        self.logger.debug("Data msg sent to bufr mngr to send to NC." + "\n\n")
    

    ############################################################################## 
    # Adds msg to the buffer_mngr's buffer
    def send_to_buffer_mngr(self, msg_type, reply_id, msg):
        buff_msg = buffered_msg(msg_to_nc, msg_type, None, reply_id, msg)                   # adds header msg_to_nc in front of the registration message and returns whole message in string form by adding delimiter
        add_to_thread_buffer(self.buffer_mngr.msg_buffer, buff_msg, "Buffer Mngr")                                 # Sends registration msg by adding to the buffer_mngr's buffer
        self.logger.debug("Msg sent to buffer_mngr." + "\n\n")

        
    ##############################################################################  
    def is_config_file_initialized(self, config_file_name):
        return os.path.exists(config_file_name)
     
        
    ##############################################################################  
    def __del__(self):
        print self, 'Sensor Controller object died'
   