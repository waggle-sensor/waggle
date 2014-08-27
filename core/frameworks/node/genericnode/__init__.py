import time
from commands import getoutput
#getoutput("rm -f lshw_result.xml")
getoutput("rm -f gn.cfg")
#getoutput("rm -f GN_msg_log")
getoutput("rm -f GN_output.log")
getoutput("rm -f *sensor1c")
"""
4 threads:
1.  main_thread (object of main_class): Spawns other threads and processes any messages intended for itself

2.  sensor_controller (object of sensor_controller_class): Handles all communication with sensors

3.  buffer_mngr (object of buffer_mngr_class): Sends msgs from main_thread and sensor_controller threads to the external_communicator thread 
    and dispatches received_external_msg msgs to appropriate threads by examining the msg_type or if needed then seq_no

4.  external_communicator (object of External_communicator_class): Handles the sending and receiving of messages 

"""
from gn_global_definition_section import logger
from gn_main_class import main_class


    
if __name__ == "__main__":
    logger.critical("Starts:"+str('%0.4f' % time.time())+"\n\n")
    main_thread = ''
    sensor_controller = ''                                                 # global object of sensor_controller_class which manages all sensors related messages
    buffer_mngr = ''                                                       # global object of buffer_mngr_class which manages the buffer for sent and received messages
    nc_port = 7001                                                         # port at which Gn can contact NC
    # Program starts execution by calling main_class's object
    main_thread = main_class("main_thread", nc_port, sensor_controller, buffer_mngr)     
    main_thread.run()
