import sys 
import os

#Adding the directory where the sensor file is to PYYTHONPATH. 
file = os.path.join(os.getcwd(), os.listdir(os.getcwd())[0])
sys.path.append(os.path.dirname(os.path.dirname(file))+'/sensormodules/envsenseV1/')

import time
from gn_global_definition_section import logger
from gn_main_class import main_class

logger.critical("Starts:"+str('%0.4f' % time.time())+"\n\n")
# port at which GN can contact NC
nc_port = 7001
# main_thread starts everything else
main_thread = main_class("main_thread", nc_port)
main_thread.run()
