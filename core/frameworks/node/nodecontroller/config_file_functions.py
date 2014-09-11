from global_imports import os
from configobj import ConfigObj
       
############################################################################## 
# Initializes the config file by adding the main sections
def initialize_config_file(config_file_name):
    if not os.path.exists(config_file_name):
        config = ConfigObj(config_file_name)
        config["Registered"] = 'NO'
        config["Systems Info"] = {}
        config["GN Info"] = {}
        config.write()
        #logger.debug("Config File Initialized."+"\n\n")
        
