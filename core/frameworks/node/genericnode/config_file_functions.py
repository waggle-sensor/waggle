from global_imports import os
from configobj import ConfigObj

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

        
