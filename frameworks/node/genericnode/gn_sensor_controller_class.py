import imp
from global_imports import *
from config_file_functions import initialize_config_file, ConfigObj
from threading import Thread
from gn_global_definition_section import get_instance_id,  add_to_thread_buffer,  buffered_msg,  \
start_communication_with_nc_event,  data_type,  sensor_thread_list, \
config_file_name, logger, sensors_info_saved_event, no_reply, wait_time_for_next_msg



"""
# Imports sensor modules, registers them, and starts new thread for each sensor module
# Periodically collects sensor msgs and transforms them in proper format and 
# after registration is done it sends sensor msgs to buffer_mngr.
"""
class sensor_controller_class(threading.Thread):
    
    # Specifies the path from where sensor modules are imported
    watchdir = '../sensormodules/weatherwx0.3' #'/nfs2/nkarimi/Desktop/internal_API/2014/nikhat/sensor_modules'
    
    
    ############################################################################## 
    def __init__(self, thread_name):
        threading.Thread.__init__(self)
        # can be used by logging module for printing messages related to this thread
        self.thread_name = thread_name                                                              
        self.daemon = True
        self.sensorBoard_input_queue = {}
        self.sensorBoard_output_queue = {}
        self.registered_sensors = []
        self.main_thread = ''
        self.buffer_mngr = ''
        self.count=0
            
        logger.debug("Thread "+self.thread_name+" Initialized."+ "\n\n")
    
        
    ############################################################################## 
    # Plugs in new sensors and periodically collects data from them and sends\
    # that to NC through buffer_mngr
    # (For future) Can process any cmd/reply obtained from NC
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name+ "\n\n")
            # Import new sensor files if any
            self.plugin_sensors()
            wait_time_set = 1
            wait_time=0
            # Start reading the received msgs only if registration is done
            while not start_communication_with_nc_event.is_set():
                pass
            while True:
                self.count = self.count+1
                queue_empty = self.get_sensor_msgs()
                if queue_empty==1:
                    time.sleep(0.0001)
                    wait_time_set=0
                else:
                    if wait_time_set==0: 
                        wait_time = time.time() + wait_time_for_next_msg
                        wait_time_set=1;
                    if wait_time > time.time():
                        time.sleep(0.0001)
                    else:
                        time.sleep(0.1)
                
                
        except Exception as inst:
            logger.critical("ERROR: Exception: " + str(inst)+ "\n\n")
            #self.run()
        finally:
            self.close()
            
            
    ##############################################################################
    # Collects msgs from each of the output_buffers of the sensors and converts
    # them into proper format and puts them into sensor_controller's input_buffer
    def get_sensor_msgs(self):
        try:
            queue_empty=0
            for each_sensor in self.sensorBoard_output_queue:
                if not self.sensorBoard_output_queue[each_sensor].empty():
                    queue_empty=1
                    msg = self.sensorBoard_output_queue[each_sensor].get()
                    # Check whether sensor is properly registered or not
                    if msg[0] not in self.registered_sensors:
                        for i in range(1,6):
                            msg[i] = None
                        msg[6] = "Error in registering sensor."
                        logger.critical("Error in registering sensor.")
                    
                    data_payload = DataPayload()
                    data_payload.sens_id = msg[0]
                    data_payload.read_tm = msg[1]
                    data_payload.inst_id = get_instance_id()
                    ret = True
                    for reading_name, reading_type, reading_value, reading_unit, reading_note in\
                    zip(msg[2], msg[3], msg[4], msg[5], msg[6]):
                        ret = (ret and data_payload.add_item(reading_name, reading_type, \
                        reading_value, reading_unit, reading_note))
                    if not ret:
                        logger.critical("ERROR in packing data....................................")
                    logger.debug("DATA PAYLOAD:" + str(data_payload) + "\n\n")
                    self.send_to_buffer_mngr(data_type, no_reply, [data_payload])
                    self.sensorBoard_output_queue[each_sensor].task_done()
            return queue_empty
            
        except Exception as inst:
            logger.critical("Exception in get_sensor_msgs: " + str(inst)+"\n\n")
    

    ##############################################################################
    # Imports all the sensor modules present in the watchdir and registers only
    # the unregistered sensor modules and spawns a separate thread for all the
    # imported modules and starts all of them
    def plugin_sensors(self):
        try:
            imported_sensor_modules, sensor_class_names = self.import_new_sensor_modules()
            logger.debug("Module extracted from package."+"\n\n")
            if sensor_class_names:    
                sensor_class_objcts = []
                for module_name, sensor_class_name in zip(imported_sensor_modules, sensor_class_names):
                    if sensor_class_name != '__init__':
                        try:
                            # Loads the class dynamically from the imported module
                            # So essentially the sensor_class_name (class name)\
                            # and the module_name (file name) must match
                            sensor_class = getattr(module_name, sensor_class_name)
                            # create an object of the above class
                            sensor_class_obj = sensor_class()
                            sensor_class_objcts.append(sensor_class_obj)
                        except Exception as inst:
                            logger.critical("Exception in plugin loop: " + str(inst)+"\n\n")
                self.register_modules(sensor_class_objcts, sensor_class_names)
                for sensor_class_name in sensor_class_names:
                    self.sensorBoard_input_queue[sensor_class_name] = Queue.Queue()
                    self.sensorBoard_output_queue[sensor_class_name] = Queue.Queue()
                logger.debug("Sensors' info added to the config file and their buffers created.")      
                self.start_sensors(sensor_class_objcts, sensor_class_names)
                # Notify to the other threads that the sensors' info has been \
                # saved in config file. Used to avoid race conditions.
                if not sensors_info_saved_event.is_set():
                    sensors_info_saved_event.set()
                    logger.debug("Sensors_info_saved_event set."+"\n\n")
                return
        except Exception as inst:
            logger.critical("Exception in plugin_sensors: " + str(inst)+"\n\n")
            

    ############################################################################## 
    # Imports new modules and returns their list
    def import_new_sensor_modules(self):
        imported_sensor_modules = []
        try:
            module_names = self.extract_module_names(self.list_dir())
            if module_names:
                logger.debug ("Sensor Modules:"+"\n\n")
                for module_name in module_names:
                    # Finds the module
                    f, filename, description = imp.find_module(module_name)
                    logger.debug('Desc: ' + str(description) + '\n ' + 'Filename:'\
                    + str(filename) + '\n' + 'File Desc:' + str(f)+"\n\n")
                    # Loads the module 
                    module = imp.load_module(filename, f, module_name, description)
                    imported_sensor_modules.append(module) 
                    logger.debug('New module loaded.'+"\n\n")
                return (imported_sensor_modules, module_names)
            logger.debug('No new nodules.'+"\n\n")
            return None, None
        except Exception as inst:
            logger.critical("Exception in import_new_sensor_modules: " + str(inst)+"\n\n")
            
        
    ##############################################################################  
    # Sends a list of directories/files present in the watchdir
    def list_dir(self):
        return os.listdir(self.watchdir)


    ############################################################################## 
    # Extracts and sends the valid and new sensor modules' (files') names
    def extract_module_names(self, module_list):
        try:
            module_names = []
            for module in module_list:
                if not os.path.isdir(module):
                    module = module.split('.')
                    if self.is_source_module(module) and self.is_new_module(module[0]):
                        module_names.append(module[0])
            logger.debug("New module names extracted."+"\n\n")
            return module_names
        except Exception as inst:
            logger.critical("Exception in extract_module_names: " + str(inst)+"\n\n")
    

    ############################################################################## 
    # Checks if its the name of a valid python source module
    # Not importing __init__ to avoid recursive imports due to another __init__
    # file present in the directory
    def is_source_module(self, module):
        if module[1] == 'py' and module[0] != '__init__':
            return True
        return False
        
    
    ############################################################################## 
    # Checks whether the module (file) is new or already imported
    def is_new_module(self, module_name):
        if module_name in self.sensorBoard_input_queue:
            # module is imported once since last reboot
            return False
        return True
    

    ##############################################################################
    # Stores the sensor's info in config file by calling the register function
    # of the sensor object
    def register_modules(self, sensor_class_objcts, sensor_file_names):
        try:
            for sensor_class_obj, sensor_file_name in zip(sensor_class_objcts, sensor_file_names):
                if self.is_new_sensor(sensor_file_name):
                    sensor_class_obj.register()
            self.update_last_sensors_registration_time()
            self.save_registered_sensors()
        except Exception as inst:
            logger.critical("Exception in register_modules: " + str(inst)+"\n\n")
        
    
    ############################################################################## 
    # Compares the file's modified time with the current time to check whether
    # the sensor module should be registered and or just started
    def is_new_sensor(self, sensor_file_name):
        try:
            config = ConfigObj(config_file_name)
            if "last_sensors_registration_time" in config:
                return (config["last_sensors_registration_time"] < \
                time.ctime(os.path.getmtime(self.watchdir+'/'+str(sensor_file_name)+".py")))
            return True
        except Exception as inst:
            logger.critical("Exception in is_new_sensor: " + str(inst)+"\n\n")
 
 
    ############################################################################## 
    # Updates sensors registration time to avoid repetitive registration in future
    def update_last_sensors_registration_time(self):
        config = ConfigObj(config_file_name) 
        config["last_sensors_registration_time"] = time.time()
        config.write()
        

    ###############################################################################
    # Prepares a list of the registered sensors
    # Useful in case of on the go plugin of sensors ie. without stopping the system
    def save_registered_sensors(self):
        try:
            config = ConfigObj(config_file_name)
            for sensor_name in config['Sensors Info']:
                if config["Sensors Info"][sensor_name]["Registered"] == 'YES':
                    self.registered_sensors.append(sensor_name)
        except Exception as inst:
            logger.critical("Exception in is_sensor_registered: " + str(inst)+"\n\n")


    ##############################################################################
    # Creates a separate thread for each of the sensor modules and attaches the thread
    # with each sensor module and starts the sensor
    def start_sensors(self, sensor_class_objcts, sensor_class_names):
        try:
            config = ConfigObj(config_file_name)
            for sensor_class_obj, sensor_class_name in zip(sensor_class_objcts, sensor_class_names):
                t = Thread(target=self.start_sensor, args = (sensor_class_obj, \
                self.sensorBoard_input_queue[sensor_class_name], self.sensorBoard_output_queue[sensor_class_name]))
                self.update_sensor_thread_list(t)
                t.start()
            logger.debug("New sensors started."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in start_sensors: " + str(inst)+"\n\n")
        
        
    ##############################################################################  
    # Prepares a list of running sensor threads so that when the process exits
    # they can be joined
    def update_sensor_thread_list(self, thread):
        sensor_thread_list.append(thread)
        logger.debug("Thread added: " + str(sensor_thread_list) + "\n\n")
        

    ############################################################################## 
    # Starts the sensor by calling start function of the sensor object
    def start_sensor(self, sensor_class_obj, input_buffer, output_buffer):
        try:
            sensor_class_obj.start(input_buffer, output_buffer)
        except Exception as inst:
            logger.critical("Exception in start_sensor: " + str(inst)+"\n\n")
    
        
    ############################################################################## 
    # Adds msg to the buffer_mngr's buffer
    def send_to_buffer_mngr(self, msg_type, reply_id, msg):
        buff_msg = buffered_msg(msg_type, None, reply_id, msg)                     
        # Sends msg to buffer_mngr by adding to bfr_for_in_to_out_msgs
        add_to_thread_buffer(self.buffer_mngr.outgoing_gnMsgBfr, buff_msg, "Buffer Mngr")
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
        logger.critical(self + 'Sensor Controller object died')
        
        


