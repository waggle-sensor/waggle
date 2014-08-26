from config_file_functions import *
from configobj import *

# Context is added as a static filed with value = "sensor_board"

class sensor_info():
   
    name_delimiter = '.'
   
    def __init__(self, sensor_name, complete_sensor_name, reading_interval, interval_settable, communication_type, packaging_info, vendor_id):
        self.sensor_name = sensor_name
        self.sensor_info_dict = {}
        self.sensor_info_dict["context"] = "Sensor Board"
        sensor_name, manufacturer_id, revision = complete_sensor_name.split('.')                                      # contains sensor_name, manufacturer_id and revision/year
        self.sensor_info_dict["manufacturer_id"] = manufacturer_id
        self.sensor_info_dict["revision"] = revision
        self.sensor_info_dict["sensor_name"] = sensor_name
        self.sensor_info_dict["packaging_info"] = packaging_info
        self.sensor_info_dict["vendor_id"] = vendor_id                                                # string
        self.sensor_info_dict["Sensor Reading Info"] = {}                                             # list will contain reading_info class's objects
        self.sensor_info_dict["Sensor Non-Functnl Params"] = {}
       
        param1 = param_info(0,"reading_interval", reading_interval, 'float', interval_settable)
        param2 = param_info(0,"communication_type", communication_type, 'int', 0)
        self.sensor_info_dict["Sensor Non-Functnl Params"][param1.param_name] = param1.param_info_dict
        self.sensor_info_dict["Sensor Non-Functnl Params"][param2.param_name] = param2.param_info_dict
        
       
    def add_reading(self, reading):
        self.sensor_info_dict["Sensor Reading Info"][reading.reading_name] = reading.reading_info_dict
       
   
    def add_parameter(self, param):
        self.sensor_info_dict["Sensor Non-Functnl Params"][param.param_name] = param.param_info_dict
   
   
    #def gen_reading_name(self, reading_name, reading_context):
        #return self.sensor_name + self.name_delimiter + reading_name + self.name_delimiter + reading_context

       
    #def gen_sensor_name(self, sensor_name, manufacturer_id, sensor_context):
        #return sensor_name + self.name_delimiter + manufacturer_id + self.name_delimiter + sensor_context
 
       
class reading_info():
   
    def __init__(self, reading_name, reading_type = " ", reading_unit = " ", reading_note = " "):
        self.reading_name = reading_name                                                                                    # string
        self.reading_info_dict = {}
        self.reading_info_dict["reading_type"] = reading_type                                                               # int/float/..: data type of value
        self.reading_info_dict["reading_unit"] = reading_unit                                                          # Ex: for temp celsius or fahrenheit
        self.reading_info_dict["reading_note"] = reading_note                                                          # don't know, right now blank
        self.reading_info_dict["Reading Params Info"] = {}
        self.reading_val = -1                                                                                               # Intially no value of the reading
        self.reading_time = -1                                                                                              # Initially no reading_time
       
       
    def add_parameter(self, param):
        self.reading_info_dict["Reading Params Info"][param.param_name] = param.param_info_dict
       
       
       
class param_info():
   
    def __init__(self, context, param_name, param_val = " ", param_type = " ", param_settable = " "):
        self.param_name = param_name
        self.param_info_dict = {}
        self.param_info_dict["param_val"] = param_val
        self.param_info_dict["param_type"] = param_type
        self.param_info_dict["param_settable"] = param_settable
       

      
def write_to_config_file(sensor):
    initialize_config_file(config_file_name)
    config = ConfigObj(config_file_name)
    main_section_name = "Sensors Info"
    config[main_section_name] = {}
    config[main_section_name][sensor.sensor_name] = sensor.sensor_info_dict
    # code to validate the fields goes here
    config[main_section_name][sensor.sensor_name]["Registered"] = 'yes'
    config.write()
 
 
#def write_data_to_file(data):
    #config_file_name = get_reg_file_name(sensor.sensor_name)
    #config = ConfigObj(config_file_name)
    #config[sensor.sensor_name] = sensor.sensor_info_dict
    #config.write()
    #update_pending_file_list(sensor.sensor_name, config_file_name)
   
   
def update_pending_file_list(sensor_name, file_name):
    fd = open('pending_file_list' ,"a")
    # TODO
    #acquire_file_lock(fd)
    fd.write(sensor_name + "\t" + file_name + "\n")
    #release lock