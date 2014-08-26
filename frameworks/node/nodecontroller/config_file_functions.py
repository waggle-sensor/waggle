from configobj import *
#from logging_module import *
import os

#logger = set_logging_level("NC_config_file_functions")
    
############################################################################## 
def initialize_config_file(config_file_name):
    if not os.path.exists(config_file_name):
        config = ConfigObj(config_file_name)
        config["Systems Info"] = {}
        config["GN Info"] = {}
        config.write()
        #logger.debug("Config File Initialized."+"\n\n")
        
