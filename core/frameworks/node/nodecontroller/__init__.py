"""
There are total 3 threads:
        
main_t (object of main_thread): Responsible for spawning other threads, processing all the packets and responding to 
cloud's or guest nodes' messages 

gn_msgs_buffer_mngr (object of gn_msgs_buffer_mngr_class): Sends the received messages to main_t's buffer and messages received from main_t to 
the respective socket connected to the specific guest node

nc_server_t (object of nc_server_thread): It listens for incoming registration requests of guest nodes and once a request is 
received, it creates a new object of class internal_communicator and passes the new socket, GN's details to that.
"""
"""
internal_communicator object: When it receives the message it will read the message till it finds the terminating character 
of the message and then it adds the message to the gn_msgs_buffer_mngr's buffer. It also handles the sending
of the data which is in output buffer.

"""
"""
Questions: should the nc send the registration info to the cloud when gn registers

add event buffer to get replies
send ack for data
send ack for gn_reg
"""
import time
from commands import getoutput
#getoutput("rm -f lshw_result.xml")
getoutput("rm -f NC_output.log")
#getoutput("rm -f nc.cfg")
#getoutput("rm -f NC_msg_log")


from nc_global_definition_section import port_for_gn, logger
from nc_msg_processor_class import msg_processor_class


logger.critical("NC Starts:"+str('%0.4f' % time.time())+"\n\n")
msg_processor = ''
gn_msgs_buffer_mngr = ''
nc_server = ''

# msg_processor object is initialized which starts everything else
msg_processor = msg_processor_class("msg_processor_class", port_for_gn, gn_msgs_buffer_mngr, nc_server)  
msg_processor.run()
    
