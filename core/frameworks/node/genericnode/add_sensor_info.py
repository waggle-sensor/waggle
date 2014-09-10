from config_file_functions import initialize_config_file, ConfigObj
from gn_global_definition_section import config_file_name


class sensor_info():
   
    name_delimiter = '.'
   
    # Initializes various attributes of the sensor object
    def __init__(self, sensor_name, complete_sensor_name, reading_interval, interval_settable, communication_type, packaging_info, vendor_id):
        self.complete_sensor_name = complete_sensor_name
        self.sensor_info_dict = {}
        self.sensor_info_dict["context"] = "Sensor Board"
        sensor_name, manufacturer_id, revision = complete_sensor_name.split('.')                      # contains sensor_name, manufacturer_id and revision/year
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
        
    # Adds reading to the sensor object   
    def add_reading(self, reading):
        self.sensor_info_dict["Sensor Reading Info"][reading.reading_name] = reading.reading_info_dict
       
   	# Adds non functional parameter to the sensor object
    def add_parameter(self, param):
        self.sensor_info_dict["Sensor Non-Functnl Params"][param.param_name] = param.param_info_dict
   
 
       
class reading_info():
   
   	# Initializes various attributes of the reading
    def __init__(self, reading_name, reading_type = " ", reading_unit = " ", reading_note = " "):
        self.reading_name = reading_name                                                                                    # string
        self.reading_info_dict = {}
        self.reading_info_dict["reading_type"] = reading_type                                                               # int/float/..: data type of value
        self.reading_info_dict["reading_unit"] = reading_unit                                                          # Ex: for temp celsius or fahrenheit
        self.reading_info_dict["reading_note"] = reading_note                                                          # don't know, right now blank
        self.reading_info_dict["Reading Params Info"] = {}
        self.reading_val = -1                                                                                               # Intially no value of the reading
        self.reading_time = -1                                                                                              # Initially no reading_time
       
    # Adds functional parameter to the reading object
    def add_parameter(self, param):
        self.reading_info_dict["Reading Params Info"][param.param_name] = param.param_info_dict
       
       
       
class param_info():
   
   	# Initializes various attributes of the parameter
    def __init__(self, context, param_name, param_val = " ", param_type = " ", param_settable = " "):
        self.param_name = param_name
        self.param_info_dict = {}
        self.param_info_dict["param_val"] = param_val
        self.param_info_dict["param_type"] = param_type
        self.param_info_dict["param_settable"] = param_settable
       

# Writes the sensor objects to config file      
def write_to_config_file(sensor):
    config = ConfigObj(config_file_name)
    main_section_name = "Sensors Info"
    config[main_section_name][sensor.complete_sensor_name] = sensor.sensor_info_dict
    # code to validate the fields goes here
    config[main_section_name][sensor.complete_sensor_name]["Registered"] = 'YES'
    config.write()