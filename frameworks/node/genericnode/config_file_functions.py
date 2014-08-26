from configobj import *
#from logging_module import set_logging_level
import os

#logger = set_logging_level("GN_config_file_functions")

    
    
############################################################################## 
def initialize_config_file(config_file_name):
    
    if not os.path.exists(config_file_name):
        config = ConfigObj(config_file_name)
        config["Systems Info"] = {}
        config["Sensors Info"] = {}
        config["Registered"] = "NO"
        config.write()
        #logger.debug("Config File Initialized.")
    else:
        #logger.debug("Config file already initialized.")
        pass

        
