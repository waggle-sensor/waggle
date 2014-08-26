from configobj import *
#from logging_module import *
import os

#logger = set_logging_level("NC_config_file_functions")
path = "./"

    
############################################################################## 
def get_config_file_name():
    return path + "nc.cfg"

    
##############################################################################     
def get_reg_file_name(sensor_name):
    return path + sensor_name + "0"

    
############################################################################## 
def initialize_config_file(config_file_name):
    if not os.path.exists(config_file_name):
        config = ConfigObj(config_file_name)
        config["Systems Info"] = {}
        config["GN Info"] = {}
        config.write()
        #logger.debug("Config File Initialized."+"\n\n")
        
