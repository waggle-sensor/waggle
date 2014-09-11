import imp
from threading import Thread
from gn_global_definition_section import add_to_thread_buffer,  buffered_msg, \
msg_to_nc,  sensors_info_saved_event,  data_type,  no_reply,  sensor_thread_list,\
config_file_name, logger    
from global_imports import *
from config_file_functions import initialize_config_file, ConfigObj

"""
# Imports sensor modules, registers them, and starts new thread for each sensor module
# Periodically called by sensor_controller to collect sensor msgs and 
# transform them in proper format which the sensor_controller can understand and 
# puts in the input_buffer of sensor controller.
# But this is not a separate thread.
"""
class sensor_plugin_class():
    
    # Specifies the path from where sensor modules are imported
    watchdir = '../sensormodules/weatherwx0.3' #'/nfs2/nkarimi/Desktop/internal_API/2014/nikhat/sensor_modules'
        
    ############################################################################## 
    def __init__(self, output_buffer):
        self.sensor_controller_output_buffer = output_buffer
        self.sensorid_input_buffer_map = {}
        self.sensorid_output_buffer_map = {}
        self.registered_sensors = []
        
    
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
    # Updates sensors registration time to avoid repetitive registration in future
    def update_last_sensors_registration_time(self):
        config = ConfigObj(config_file_name) 
        config["last_sensors_registration_time"] = time.time()
        config.write()
        
        
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
    # Not importing __init__ to avoid recursive imports due to another __init__ \
    # file present in the directory
    def is_source_module(self, module):
        if module[1] == 'py' and module[0] != '__init__':
             return True
        return False
        
    
    ############################################################################## 
    # Checks whether the module (file) is new or already imported
    def is_new_module(self, module_name):
        if module_name in self.sensorid_input_buffer_map:
            # module is imported once since last reboot
            return False
        return True
    
    
    ############################################################################## 
    # Compares the file's modified time with the current time to check whether\
    # the sensor module should be registered or just started
    def is_new_sensor(self, sensor_file_name):
        config = ConfigObj(config_file_name)
        if "last_sensors_registration_time" in config:
            return (config["last_sensors_registration_time"] < \
            time.ctime(os.path.getmtime(watchdir+sensor_file_name+".py")))
        return True

        
    ##############################################################################
    # Imports all the sensor modules present in the watchdir and registers only \
    # the unregistered sensor modules and spawns a separate thread for all the \
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
                self.register_modules(sensor_class_objcts)
                for sensor_class_name in sensor_class_names :
                    self.sensorid_input_buffer_map[sensor_class_name] = Queue.Queue()
                    self.sensorid_output_buffer_map[sensor_class_name] = Queue.Queue()
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
    # Stores the sensor's info in confi file by calling the register function \
    # of the sensor object
    def register_modules(self, sensor_class_objcts):
        try:
            for sensor_class_obj in sensor_class_objcts:
                if self.is_new_sensor(sensor_class_obj):
                    sensor_class_obj.register()
            self.update_last_sensors_registration_time()
            self.save_registered_sensors()
        except Exception as inst:
            logger.critical("Exception in register_modules: " + str(inst)+"\n\n")
         
    
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
    # Creates a separate thread for each of the sensor modules and attaches \
    # with each sensor module and starts the sensor
    def start_sensors(self, sensor_class_objcts, sensor_class_names):
        try:
            config = ConfigObj(config_file_name)
            for sensor_class_obj, sensor_class_name in zip(sensor_class_objcts, sensor_class_names):
                t = Thread(target=self.start_sensor, args = (sensor_class_obj, \
                self.sensorid_input_buffer_map[sensor_class_name], self.sensorid_output_buffer_map[sensor_class_name]))
                self.update_sensor_thread_list(t)
                t.start()
            logger.debug("New sensors started."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in start_sensors: " + str(inst)+"\n\n")
         
        
    ############################################################################## 
    # Starts the sensor by calling start function of the sensor object
    def start_sensor(self, sensor_class_obj, input_buffer, output_buffer):
        try:
            sensor_class_obj.start(input_buffer, output_buffer)
        except Exception as inst:
            logger.critical("Exception in start_sensor: " + str(inst)+"\n\n")
        
        
    ##############################################################################  
    # Prepares a list of running sensor threads so that when the process exits\
    # they can be joined
    def update_sensor_thread_list(self, thread):
        sensor_thread_list.append(thread)
        logger.debug("Thread added: " + str(sensor_thread_list) + "\n\n")
        
    ##############################################################################
    # Collects msgs from each of the output_buffers of the sensors and converts\
    # them into proper format and puts them into sensor_controller's input_buffer
    def get_sensor_msgs(self):
        try:
            for each_sensor in self.sensorid_output_buffer_map:
                while not self.sensorid_output_buffer_map[each_sensor].empty():
                    item = self.sensorid_output_buffer_map[each_sensor].get()
                    msg_type = data_type 
                    reply_id = no_reply 
                    # Check whether sensor is properly registered or not
                    if item[0] not in self.registered_sensors:
                        for i in range(1,6):
                            item[i] = None
                        item[6] = "Error in registering sensor."
                        logger.critical("Error in registering sensor.")
                    msg = item
                    add_to_thread_buffer(self.sensor_controller_output_buffer, \
                    buffered_msg(msg_to_nc, msg_type, None, reply_id, msg), "Sensor Controller")                                
                    self.sensorid_output_buffer_map[each_sensor].task_done()
                    logger.debug("Msg sent to sensor_controller_output_buffer." + str(msg)+"\n\n")
            logger.debug("Msg sending to sensor_controller's buffer done."+"\n\n")    
        except Exception as inst:
            logger.critical("Exception in get_sensor_msgs: " + str(inst)+"\n\n")
         
        
    ##############################################################################     
    # Hook
    def send_sensor_cmd(self, sensor_id, cmd):
        # Matches sensor_id with its output queue and sends the msg to that queue
        pass
    
        
    ############################################################################## 
    def __del__(self):
        print self, 'Sensor Plugin object died'
   
