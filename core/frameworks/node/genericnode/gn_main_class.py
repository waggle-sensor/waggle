from global_imports import *
from gn_buffer_mngr_class import buffer_mngr_class
from gn_sensor_controller_class import sensor_controller_class
from get_node_info import get_node_info
from gn_global_definition_section import get_instance_id, add_to_thread_buffer, \
buffered_msg, msg_to_nc, msg_from_nc, start_communication_with_nc_event, \
sensors_info_saved_event, registration_type, \
no_reply, config_file_name, logger, wait_time_for_next_msg
from config_file_functions import initialize_config_file, ConfigObj

"""
# Stores system's info in config file
# Spawns all other threads
# Sends registration request to buffer_mngr to forward it to NC.
"""
class main_class():

    ##############################################################################
    def __init__(self, thread_name, nc_port):
        # can be used by logging module for printing messages related to this thread
        self.thread_name = thread_name
        self.reg_msg_handler_no = 0
        self.update_handler_no = 1
        self.status_handler_no = 2
        self.input_buffer = Queue.Queue(maxsize=1000)
        self.nc_port = nc_port
        self.sensor_controller = ''
        self.buffer_mngr = ''
        logger.debug("info Thread "+self.thread_name+" Initialized."+ "\n\n")


    ##############################################################################
    # Stores system's info, spawns threads, sends registration request \
    # and (for future) can process any msg intended for it received from NC
    def run(self):
        try:
            logger.debug("Starting " + self.thread_name+ "\n\n")
            self.store_node_info()
            self.sensor_controller = sensor_controller_class("sensor_controller")
            self.buffer_mngr = buffer_mngr_class("buffer_mngr", self.nc_port)
            self.sensor_controller.pass_thread_address(self, self.buffer_mngr)
            self.buffer_mngr.pass_thread_address(self, self.sensor_controller)
            self.sensor_controller.start()
            self.buffer_mngr.start()
            logger.critical("All threads started:"+str('%0.4f' % time.time())+"\n\n")
            self.register_gn()
            wait_time = time.time() + wait_time_for_next_msg
            wait_time_set = 1
            while True:
                while (not self.input_buffer.empty()):
                    item = self.input_buffer.get()
                    logger.debug("Msg received in buffer:"+str(item)+ "\n\n")
                    internal_msg_header = item.internal_msg_header
                    if internal_msg_header == msg_from_nc:
                        process_external_msg(item)
                    else:
                        logger.critical("Unknown Msg Received: Discarding the msg\
                        ............." + "\n\n")
                    self.input_buffer.task_done()
                    # set time to remain attentive for next 200 ms
                    wait_time = time.time() + wait_time_for_next_msg
                    time.sleep(0.0001)
                if wait_time > time.time():
                    time.sleep(0.0001)
                else:
                    time.sleep(1)
        except Exception as inst:
            logger.critical("Exception in main_class: " + str(inst)+ "\n\n")
        finally:
            self.sensor_controller.close()
            self.sensor_controller.join(1)
            self.buffer_mngr.close()
            self.buffer_mngr.join(1)
            logger.critical("All child threads exited. Parent Exiting..."+ "\n\n")


    ##############################################################################
    # Stores the node's sw/hw info in config file
    def store_node_info(self):
        if os.path.exists(config_file_name):
            config = ConfigObj(config_file_name)
            if config["Systems Info"] != {}:
                # gn.cfg is already present
                return
        else:
            initialize_config_file(config_file_name)
            ret_val = get_node_info(config_file_name)
        logger.debug("System's Info stored in config file."+ "\n\n")


    ##############################################################################
    # Calls apt function based on whether it is registered or not
    def register_gn(self):
        logger.debug("Checking whether registration is done or not."+ "\n\n")
        if self.check_registration_status():
            # Registration already done so just send msg to NC saying that I am up
            self.send_ready_notification()
        else:
            self.send_GN_registration_request()


    ##############################################################################
    # Checks by reading the config file whether registration has been done or not.
    def check_registration_status(self):
        config = ConfigObj(config_file_name)
        if config["Registered"] == "YES":
            logger.debug("System Info: " + config["Systems Info"]+ "\n\n")
            logger.info("Registration already done."+ "\n\n")
            return True
        logger.info("Registration not done."+ "\n\n")
        return False


    ##############################################################################
    # After sensor infon is saved in config file, this prepares registration msg
    # and sends to buffer_mngr's buffer for sending it to NC
    def send_GN_registration_request(self):
        # This event is set by sensor_controller after it stores the sensors' info in config file
        logger.debug("Waiting for sensors info."+ "\n\n")
        # Waits till sensor_plugin object finishes writing to the config file
        # so that race conditions don't occur
        sensors_info_saved_event.wait()
        config = ConfigObj(config_file_name)
        temp_config = {}
        temp_config["Systems Info"] = config["Systems Info"]
        temp_config["Sensors Info"] = config["Sensors Info"]
        reg_payload = RegistrationPayload()
        reg_payload.sys_info = dict(temp_config)
        reg_payload.instance_id = get_instance_id()
        self.send_to_buffer_mngr(registration_type, no_reply, [reg_payload])


    ##############################################################################
    # Function Incomplete: Sends "Ready" packet to NC as GN is already registered
    def send_ready_notification(self):
        # Waits till sensor_plugin object finishes writing new sensor's info \
        # to the config file so that race conditions don't occur
        sensors_info_saved_event.wait()
        # TODO: Read sensors info here and prepare reg_payload
        self.send_to_buffer_mngr(registration_type, no_reply, reg_payload)


    ##############################################################################
    # Adds msg to the buffer_mngr's buffer
    def send_to_buffer_mngr(self, msg_type, reply_id, msg):
        buff_msg = buffered_msg(msg_to_nc, msg_type, None, reply_id, msg)
        add_to_thread_buffer(self.buffer_mngr.bfr_for_in_to_out_msgs, buff_msg, "Buffer Mngr")
        logger.debug ("Msg sent to buffer_mngr."+ "\n\n")


    ##############################################################################
    # Hook
    def process_external_msg(self, item):
        logger.debug("Processing NC's msg."+ "\n\n")
        # Add stuff to process any command received from NC

    ##############################################################################
    # Hook
    def process_cmd(self, msg):
        logger.debug("Command from NC received."+ "\n\n")
        if msg == "Update":
            #TODO
            update_cmd_handler()

        elif msg == "Status":
            #TODO
            get_status()


    ##############################################################################
    def __del__(self):
        print self, 'Main object died'
