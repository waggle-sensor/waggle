import imp
from threading import Thread
from gn_global_definition_section import add_to_thread_buffer,  buffered_msg,  msg_to_nc,  sensors_info_saved_event,  data_type,  no_reply,  sensor_thread_list, config_file_name, logger    
from global_imports import *
 
class sensor_plugin_class():
    
    watchdir = '../sensormodules/weatherwx0.3' #'/nfs2/nkarimi/Desktop/internal_API/2014/nikhat/sensor_modules'
        
    ############################################################################## 
    def __init__(self, output_buffer):
        self.sensors_output_buffer = Queue.Queue()
        self.sensor_controller_output_buffer = output_buffer
        self.sensorid_input_buffer_map = {}
        
    ############################################################################## 
    def initialize_registered_modules_list(self):
        registered_modules = []
        if os.path.exists(config_file_name):
            config = ConfigObj(config_file_name)
            if config["Sensors Info"] != {}:
                for sensor_name in config["Sensors Info"]:
                    registered_modules.append(sensor_name)
        return registered_modules    
    
     
    ############################################################################## 
    # Returns a list of new modules available
    def import_new_sensor_modules(self):
        sensor_modules = []
        try:
            module_names = self.extract_module_names(self.list_dir())
            if module_names:
                logger.debug ("Sensor Modules:"+"\n\n")
                for module_name in module_names:
                    f, filename, description = imp.find_module(module_name)
                    logger.debug('Desc: ' + str(description) + '\n ' + 'Filename:' + str(filename) + '\n' + 'File Desc:' + str(f)+"\n\n")
                    module = imp.load_module(filename, f, module_name, description)
                    sensor_modules.append(module) 
                    logger.debug('New module loaded.'+"\n\n")
                return (sensor_modules, module_names)
            logger.debug('No new nodules.'+"\n\n")
            return None, None
        except Exception as inst:
            logger.critical("Exception in import_new_sensor_modules: " + str(inst)+"\n\n")
            
        
    ############################################################################## 
    def update_last_registration__time(self):
        config = ConfigObj(config_file_name) 
        config["last_registration_time"] = time.time()
        config.write()
        
        
    ##############################################################################     
    def list_dir(self):
        return os.listdir(self.watchdir)

       
    ##############################################################################      
    def extract_module_names(self, module_list):
        try:
            module_names = []
            for module in module_list:
                if not os.path.isdir(module):
                    module = module.split('.')
                    if self.is_source_module(module) and self.is_new_module(module[0]): #if os.path.isdir(module): 
                        module_names.append(module[0])
            logger.debug("New module names extracted."+"\n\n")
            return module_names
        except Exception as inst:
            logger.critical("Exception in extract_module_names: " + str(inst)+"\n\n")
    
    
        
    ############################################################################## 
    def is_source_module(self, module):
        if module[1] == 'py' and module[0] != '__init__':
             return True
        return False
        
    
    ############################################################################## 
    def is_new_module(self, module_name):
        if module_name in self.sensorid_input_buffer_map:
            # module is imported once since last reboot
            return False
        return True
    
    
    ############################################################################## 
    def is_new_sensor(self, sensor_file_name):
        config = ConfigObj(config_file_name)
        if "last_registration_time" in config:
            return (config["last_registration_time"] < time.ctime(os.path.getmtime(watchdir+sensor_file_name+".py")))
        return True

        
    ##############################################################################     
    def plugin_sensors(self):
        try:
            sensor_modules, sensor_class_names = self.import_new_sensor_modules()
            #for sensor_class_name in sensor_class_names:
            #imp.find_module("sensor_code.py", sensor_class_name.__path__)
            logger.debug("Module extracted from package."+"\n\n")
            if sensor_class_names:    
                sensor_class_objcts = []
                for module_name, sensor_class_name in zip(sensor_modules, sensor_class_names):
                    if sensor_class_name != '__init__':
                        try:
                            sensor_class_name = getattr(module_name, sensor_class_name)
                            sensor_class_obj = sensor_class_name()
                            sensor_class_objcts.append(sensor_class_obj)
                        except Exception as inst:
                            logger.critical("Exception in plugin loop: " + str(inst)+"\n\n")
                self.register_modules(sensor_class_objcts)
                for sensor_class_name in sensor_class_names :
                    self.sensorid_input_buffer_map[sensor_class_name] = Queue.Queue()
                logger.debug("Sensors added to registered sensors' list and their input buffers created."+"\n\n")
                if not sensors_info_saved_event.is_set():
                    sensors_info_saved_event.set()
                    logger.debug("Sensors_info_saved_event set."+"\n\n")
                self.start_sensors(sensor_class_objcts, sensor_class_names)
                return
        except Exception as inst:
            logger.critical("Exception in plugin_sensors: " + str(inst)+"\n\n")
            
        
    ##############################################################################     
    def register_modules(self, sensor_class_objcts):
        try:
            for sensor_class_obj in sensor_class_objcts:
                if self.is_new_sensor(sensor_class_obj):
                    sensor_class_obj.register()
            self.update_last_registration__time()
        except Exception as inst:
            logger.critical("Exception in register_modules: " + str(inst)+"\n\n")
         
    
    ##############################################################################     
    def is_sensor_registered(self, sensor_name):
        try:
            config = ConfigObj(config_file_name)
            for sensor in config["Sensors Info"]:
                if config["Sensors Info"][sensor]["Registered"] == 'yes':
                   return True
            return False 
        except Exception as inst:
            logger.critical("Exception in update_registered_sensors_list: " + str(inst)+"\n\n")
    
    
    
    ############################################################################## 
    def start_sensors(self, sensor_class_objcts, sensor_class_names):
        try:
            for sensor_class_obj, sensor_class_name in zip(sensor_class_objcts, sensor_class_names):
                t = Thread(target=self.start_sensor, args = (sensor_class_obj,self.sensorid_input_buffer_map[sensor_class_name], self.sensors_output_buffer))
                self.update_sensor_thread_list(t)
                t.start()
            logger.debug("New sensors started."+"\n\n")
        except Exception as inst:
            logger.critical("Exception in start_sensors: " + str(inst)+"\n\n")
         
        
    ############################################################################## 
    def start_sensor(self, sensor_class_obj, input_buffer, output_buffer):
        try:
            sensor_class_obj.start(input_buffer, output_buffer)
        except Exception as inst:
            logger.critical("Exception in start_sensor: " + str(inst)+"\n\n")
        
        
    ##############################################################################     
    def update_sensor_thread_list(self, thread):
        sensor_thread_list.append(thread)
        logger.debug("Thread added: " + str(sensor_thread_list) + "\n\n")
        
    ############################################################################## 
    def get_sensor_msgs(self):
        try:
            while not self.sensors_output_buffer.empty():
                item = self.sensors_output_buffer.get()
                msg_type = data_type 
                reply_id = no_reply 
                # Check whether sensor is properly registered or not
                if not self.is_sensor_registered(item[0]):
                    for i in range(1,6):
                        item[i] = None
                    item[6] = "Error in registering sensor."
                msg = item
                add_to_thread_buffer(self.sensor_controller_output_buffer, buffered_msg(msg_to_nc, msg_type, None, reply_id, msg), "Sensor Controller")                                 # Sends registration msg by adding to the buffer_mngr's buffer
                logger.debug("Msg sent to sensor_controller_output_buffer." + str(msg)+"\n\n")
            logger.debug("Msg sending to sensor_controller's buffer done."+"\n\n")    
        except Exception as inst:
            logger.critical("Exception in get_sensor_msgs: " + str(inst)+"\n\n")
         
        
    ##############################################################################      
    def send_sensor_cmd(self, sensor_id, cmd):
        # Matches sensor_id with its output queue and sends the msg to that queue
        pass
    
        
    ############################################################################## 
    def __del__(self):
        print self, 'Sensor Plugin object died'
   