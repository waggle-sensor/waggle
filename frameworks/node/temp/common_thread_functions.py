import logging
import threading

# used for logging msgs
logging.basicConfig(level=logging.NOTSET,format='%(name)s: %(message)s',)

 
# handler for logging msgs                    
logging_level = 2

def set_logging_level(context_name):
    logger = logging.getLogger(context_name)
        
    if logging_level == 0:
        logger.setLevel(0)
    elif logging_level == 1:
        logger.setLevel(10)
    elif logging_level == 2:
        logger.setLevel(20)
    elif logging_level == 3:
        logger.setLevel(30)
    elif logging_level == 4:
        logger.setLevel(40)
    elif logging_level == 5:
        logger.setLevel(50)
        
    return logger
    
    
def add_to_thread_buffer(msg_buffer, string_msg):
    msg_buffer.put(string_msg)

# Output: If msg is present in the output buffer it returns true else false 
def is_present_in_output_buffer(output_buffer,seq_no):
    for msg_handler_info in output_buffer:
        if (msg_handler_info[0] == seq_no):
            return True
    # a new msg
    return False

# Adds to the sorted buffer passed as an arg and then sorts the buffer based on the expiration_time field of the unacknowledged_msg_handler_info
def add_to_sorted_output_buffer(msg_buffer, unacknowledged_msg_handler_info):
    msg_buffer.append(unacknowledged_msg_handler_info)
    sorted(msg_buffer, key=lambda x: x[1])
    logger.debug("Inserted in sorted buffer")
    
    
# Output: Returns list of msg_info which contain exipred msgs
def get_timed_out_msgs():
    timed_out_msg_info_list = []
    for msg_handler_info in output_buffer:
        if (msg_expired(msg_handler_info[1],datetime.datetime.now())):
            # this event has happened so handle it
            timed_out_msg_info_list.append(msg_handler_info)
    return timed_out_msg_info_list
            
    
# Returns msg_info for a specific msg    
def get_msg_info_and_delete_from_output_buffer(output_buffer, seq_no):
    for msg_handler_info in output_buffer:
        if msg_handler_info[0] == seq_no:
            # output_buffer.remove(msg_handler_info)
            return output_buffer.remove(msg_handler_info)
            
    
# Output: Returns True if the msg's expiration time is less than the current time or else false 
def msg_expired(self, next_schduld_time, now):
    # year, month, day = extract_date(next_schduld_time)
    # hour, minute, second, microsecond
    return ((now - next_schduld_time) > 0)
    # today8am = now.replace(hour=8, minute=0, second=0, microsecond=0)
    # now < today8am
    
"""    
# Output: Returns list of msg_info which contain exipred msgs
def get_timed_out_msgs(sorted_output_msg_buffer):
    timed_out_msg_info_list = []
    logger.debug("Checking for timed out msgs.")
    for msg_handler_info in output_buffer:
        if (msg_expired(msg_handler_info[1],datetime.datetime.now())):
            logger.debug("Timed out msg present!")
            # this event has happened so handle it
            timed_out_msg_info_list.append(msg_handler_info)
    return timed_out_msg_info_list
"""      

"""
# Output: Returns True if the msg's expiration time is less than the current time or else false 
def msg_expired(self, next_schduld_time, now):
    # year, month, day = extract_date(next_schduld_time)
    # hour, minute, second, microsecond
    return ((now - next_schduld_time) > 0)
    # today8am = now.replace(hour=8, minute=0, second=0, microsecond=0)
    # now < today8am

"""
    
    
"""

# Stores sensors' information like parameters and their attributes and start_time, time_interval between two readings etc. in hierarchical dictionary structure
# it stores None in "reading_val" and "reading_time" attributes as the sensors have not been started. "reading_time" keeps track of the time when a new reading is taken.
# Arg sensors_info has format: [[sensor_id, start time, time_interval, bidirectional, reading_names[], param_names[], param_val[]],[sensor_id, start time, time_interval, bidirectional, reading_names[], param_names[], param_val[]]..]
# TODO: Ask params obtained when sensors are not started?
def create_sensors_info_dict(sensors_info):
    logger.debug("Inside create_sensors_info_dict.")
    time_interval = 10                                          # in secs
    sensors_info = msg_parse.parse_multiple_sensor_msgs(sensors_info) 
    # self.logger.debug (sensors_info)
    # insert the info in sensors_info_dict
    for single_sensor_params in sensors_info:
        single_sensor_info = {}
        single_sensor_info["reading_time"] = None
        single_sensor_info["start_time"] = single_sensor_params[1]
        single_sensor_info["time_interval"] = time_interval
        # extract and insert params one by one
        for reading_name, reading_unit, reading_val, reading_type, node_id in \
        zip(single_sensor_params[2], single_sensor_params[3], single_sensor_params[4], single_sensor_params[5], single_sensor_params[6]):
            params_info = {}
            params_info["reading_val"] = reading_val                                                                                    
            params_info["type"] = reading_type
            params_info["unit"] = reading_unit
            params_info["node_id"] = node_id
            # here other params entries will also be added in future like for temp "high", "crit"
            single_sensor_info[reading_name] = params_info                                                                          
        sensors_info_dict[str(single_sensor_params[0])] = single_sensor_info
        time_interval += 10
    #self.logger.debug ((sensors_info_dict))
    
    
# Updates the sensors_info_dict (hierarchical dict) with the new values            
# Updation can be of 2nd level keys' values like start_time, time interval, or of 3rd level keys' values like parameters' values 
# If updation to 2nd level keys' values is required, the arg sensors_info has format: [[sensor_id, param_names[], param_val[]],[sensor_id, param_names[], param_val[]]..]
# If updation to 3rd level keys' values is required, the arg sensors_info has format: [[sensor_id, reading_time, reading_names[], param_names[], param_val[]],[sensor_id, reading_time, reading_names[], param_names[], param_val[]]..]
def update_sensors_info_dict(update_dict_level, sensors_info):
    logger.debug("Inside update_sensors_info_dict.")
    sensors_info = msg_parse.parse_multiple_sensor_msgs(sensors_info) 
    # If updation to common paramters is needed like start_time, time_interval etc.
    if update_dict_level == 1:
        for single_sensor_info in sensors_info:
            sensor_id = str(single_sensor_info[0])
            for param_name, param_val \
            in zip(single_sensor_info[1], single_sensor_info[2]):
                sensors_info_dict[sensor_id][param_name] = param_val
    elif update_dict_level == 2:
        for single_sensor_info in sensors_info:
            sensor_id = str(single_sensor_info[0]) 
            
            sensors_info_dict[sensor_id]["reading_time"] = single_sensor_info[1]
            for reading_name, param_name, param_val \
            in zip(single_sensor_info[2], single_sensor_info[3], single_sensor_info[4]):
                self.logger.debug ("readingname:"+str(reading_name))
                sensors_info_dict[sensor_id][reading_name][param_name] = param_val
# self.logger.debug "sensors_info"+str(sensors_info_dict)
# self.logger.debug ("values updated")
"""
"""
# Adds internal header like "send_external_msg"/"received_external_msg"/"received_internal_msg" to the msg
def add_internal_msg_header(msg, header):
    header_and_msg = header + "/" + msg
    return header_and_msg
    
    
# Returns the internal header like "send_external_msg"/"received_external_msg"/"received_internal_msg" which is used to distinguish messages present in the buffers inside the GN 
def extract_internal_msg_header(msg):
    header_and_msg = msg.split("/")
    return header_and_msg[0]
"""
"""    
# Generates last_seq_no_to_nc by incrementing the global last_seq_no_to_nc by 1
# TODO: Implement the mapping of local seq_no to global seq_no
def gen_next_seq_no_to_nc(seq_no):
    seq_no += 1
    logger.debug("Next seq_no generated.")
    return seq_no
    
    
# Adds seq_no either internal or seq_no in the front of the msg  
def add_seq_no(msg, seq_no):
    return (str(seq_no)+"*"+msg)

   
# Returns the seq_no present in the beginning of the msg
def extract_seq_no(msg):
    msg = msg.split('*')
    return int(msg[0])


# msg is in string form and msg_type is in int
def add_msg_type(msg, msg_type):
    array = [msg, msg_type]
    # Calls Tony's function to convert to string by adding msg_type in front of the msg and separating both with delimiter
    convertTostr(array,0)                                                                                                           # 0 is the index in DELIMITERS array 

        
# Returns only the msg part 
def remove_internal_msg_header(msg):
    msg = msg.split("/")
    return msg[1]
"""

"""    
# Makes a new entry of seq_no:thread_name mapping
def add_to_unacknowledged_msg_thread_mapping(seq_no, thread_inst):
    unacknowledged_msg_thread_mapping[seq_no] = thread_inst
    logger.debug("Inside add_to_unacknowledged_msg_thread_mapping.")
"""       

"""        
# Returns the internal header like "send_external_msg"/"received_gn_msg"/"received_internal_msg" which is used to distinguish messages present in the buffers inside the NCR
def get_internal_msg_header(msg):
    internal_header_and_msg = msg.split("/")
    return internal_header_and_msg[0]

# Extracts the GN's id which is (ip, port) and msg body
def extract_gn_id_and_msg(msg):
    gn_id_and_msg = msg[1].split("/")
    return msg[0], gn_id_and_msg[1]
    
# Adds internal header like "send_external_msg"/"received_gn_msg"/"received_internal_msg" to the msg
def add_internal_msg_header(msg, header):
    return header + "/" + msg
    
# Adds GN's id which is (gn_ip, gn_port) to the message to indicate the sender GN
def add_gn_id(msg, gn_id):
    return [gn_id,msg]
"""

logger = set_logging_level("Inside imported file common_thread_functions.py: ")
        