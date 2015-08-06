//---------- B O O T _ P R I M A R Y ------------------------------------------
/*
   Starts/initializes/boots self, node controller, and ethernet switch.
   Conditions for and operation of the node controller and ethernet switch are
   verified before completing boot sequence.

   Return TRUE: boot procedure executed successfully.
   Return FALSE: boot procedure failed.

   :rtype: boolean
*/
boolean boot_primary()
{
	// Initialize/start internal components
	init_primary();

   // Is this the first ever boot?
   if(eeprom_read_byte(&E_FIRST_BOOT) != 0)
      // Assign default parameters
      set_default_eeprom();

	// Booted SysMon successfully?
   if(!boot_SysMon())
      // Skip the rest of the boot sequence
      return false;

   // Booted node controller successfully?
   if(!boot_NC())
      // Skip the rest of the boot sequence
      return false;

	// Request time from node controller
	get_time_NC();

   // Request operating parameters from node controller
   get_params_core();

	// Request guest node parameters from node controller
	get_params_GNs();

   // Boot ethernet switch
   boot_switch();

	// Everything is good, so exit sequence with success
	return true;
}



//---------- B O O T _ N C ----------------------------------------------------
/*
    Boots the node controller.  Checks environment, power draw, and heartbeat.

    Return TRUE: everything is good, boot successful.
    Return FALSE: something went wrong, boot unsuccessful.

    :rtype: boolean
*/
boolean boot_NC()
{
   // Mark NC as not operational
   _NC_running = false;

   // Make sure the device is off
   digitalWrite(PIN_RELAY_NC, LOW);

   // Give the relay time to move
   delay(100);

   // Is the node controller not enabled?
   if(!eeprom_read_byte(&E_NC_ENABLED))
      // Exit with failure
      return false;

   // Is the node controller's environment not suitable?
   if(!check_environ_NC())
   {
      // Giving the node controller one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is the node controller's environment not suitable?
      if(!check_environ_NC())
         // Exit with failure
         return false;
   }

   // Is the node controller's processor temperature not suitable?
   if(!check_temp_NC())
   {
      // Giving the node controller one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is the node controller's environment not suitable?
      if(!check_temp_NC())
         // Exit with failure
         return false;
   }

   // Enable power to node controller
   digitalWrite(PIN_RELAY_NC, HIGH);

   Serial.setTimeout(600L * 1000L);
   String x = Serial.readStringUntil(NC_TERMINATOR);
   if(x != "=")
      return false;

   // Give the node controller time to boot
   delay((long)eeprom_read_word(&E_BOOT_TIME_NC) * 1000L);

   // Is the node controller not drawing an expected amount of power?
   if(!check_power_NC())
   {
      // Giving the node controller one more chance...

      // Power cycle the node controller
      power_cycle(PIN_RELAY_NC);

      // Give the node controller time to boot
      delay((long)eeprom_read_word(&E_BOOT_TIME_NC) * 1000L);

      // Is the node controller not drawing an expected amount of power?
      if(!check_power_NC())
      {
         // Turn off the node controller
         digitalWrite(PIN_RELAY_NC, LOW);

         // Mark NC as dead
         eeprom_update_byte(&E_NC_ENABLED, 0);

         // Exit with failure
         return false;
      }
   }

   // Is the node controller alive (sending a heartbeat)?
   if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
   {
      // Start at 1 boot attempt, since we had to boot to get here
      byte boot_attempts = 1;
      boolean _heartbeat_detected = false;
      
      // Try to get a heartbeat from the NC as many times as allowed
      while(boot_attempts <= eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
         // Is heartbeat not detected?
         if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
         {
            // Power cycle the node controller
            power_cycle(PIN_RELAY_NC);

            // Give the node controller time to boot
            delay((long)eeprom_read_word(&E_BOOT_TIME_NC) * 1000L);
         }
         else
            // Indicate that a heartbeat was detected
            _heartbeat_detected = true;

         // Increment counter for number of attempts
         boot_attempts++;
      }

      // Still no heartbeat detected?
      if(!_heartbeat_detected)
      {
         // Turn off the node controller
         digitalWrite(PIN_RELAY_NC, LOW);

         // Exit with failure
         return false;
      }
   }

   // Mark NC as operational
   _NC_running = true;

   // Exit with success
   return true;
}



//---------- B O O T _ S W I T C H --------------------------------------------
/*
    Boots the ethernet switch.  Checks environment and power draw.
    If something goes wrong, the node controller is notified.

    :rtype: none
*/
void boot_switch()
{
   // Mark switch as not operational
   _switch_running = false;

   // Make sure the device is off
   digitalWrite(PIN_RELAY_SWITCH, LOW);

   // Give the relay time to move
   delay(100);

   // Is the ethernet switch disabled or not present?
   if(!(eeprom_read_byte(&E_SWITCH_ENABLED)
      && eeprom_read_byte(&E_PRESENT_SWITCH)))
   {
      // Exit with failure
      return;
   }

   // Is the ethernet switch's temperature outside of safe parameters?
   if(!check_temp_switch())
   {
      // Giving the switch one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is the ethernet switch's temperature outside of safe parameters?
      if(!check_temp_switch())
      {
         // Inform node controller of failure
         send_problem(PROBLEM_SWITCH_TEMP);

         // Exit with failure
         return;
      }
   }

   // Enable power to ethernet switch
   digitalWrite(PIN_RELAY_SWITCH, HIGH);

   // Give the ethernet switch time to boot
   delay((long)eeprom_read_byte(&E_BOOT_TIME_SWITCH) * 1000L);

   // Is the ethernet switch not drawing an expected amount of power?
   if(!check_power_switch())
   {
      // Giving the ethernet switch one more chance...

      // Power cycle the switch
      power_cycle(PIN_RELAY_SWITCH);

      // Give the switch time to boot
      delay((long)eeprom_read_byte(&E_BOOT_TIME_SWITCH) * 1000L);

      // Is the ethernet switch not drawing an expected amount of power?
      if(!check_power_switch())
      {
         // Turn off the switch
         digitalWrite(PIN_RELAY_SWITCH, LOW);

         // Inform node controller of failure
         send_problem(PROBLEM_SWITCH_POWER);

         // Mark switch as dead
         eeprom_update_byte(&E_SWITCH_ENABLED, 0);

         // Exit with failure
         return;
      }
   }

   // Mark switch as operational
   _switch_running = true;
}



//---------- B O O T _ S Y S M O N --------------------------------------------
/*
    Checks environment and power draw for SysMon.

    Return TRUE: everything is good.
    Return FALSE: environment/power draw is unacceptable.

    :rtype: boolean
*/
boolean boot_SysMon()
{
   // Is SysMon drawing too much power?
   if(!check_power_SysMon())
   {
      // Giving SysMon one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_POWER_WAIT_TIME * 1000L);

      // Is SysMon drawing too much power?
      if(!check_power_SysMon())
         // Exit with failure
         return false;
   }

   // Is SysMon's environment outside of safe bounds?
   if(!check_environ_SysMon())
   {
      // Giving SysMon one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is SysMon's environment outside of safe bounds?
      if(!check_environ_SysMon())
         // Exit with failure
         return false;
   }

   // Exit with success
   return true;
}



//---------- G E T _ P A R A M S _ C O R E ------------------------------------
/*
   Request operating parameters from the node controller.  If parameters are
   different than what is already stored, the parameter is updated.  If the
   parameters are the same or not received, the previously stored values will
   be used.

   :rtype: none
*/
void get_params_core()
{
   // Send request
   Serial.println(NC_NOTIFIER_PARAMS_CORE);

   // Save the node controller's response into a string.
   // Default timeout value is 1 second
   String received_params = "";
   received_params = Serial.readStringUntil(NC_TERMINATOR);

   // Were parameters received?
   if(received_params.length() > 0)
   {
      /* Order of parameters (coming from node controller):

         USART baud rate
         USART RX buffer size
         Period at which status reports are sent to node controller
         Max number of SOS boot attempts
         Max number of subsystem boot attempts
         Max number of primary boot attempts
         Time to wait before trying to reboot non-running devices
         Present/not present (switch)
         Node controller boot time
         Ethernet switch boot time
         Heartbeat timeout (node controller)
         Heartbeat timeout (switch)
         Bad environment timeout (system monitor)
         Bad environment timeout (node controller)
         Bad processor temperature timeout (node controller)
         Bad temperature timeout (switch)
         Bad current timeout (system monitor)
         Bad current timeout (node controller)
         Bad current timeout (switch)
         Minimum temperature of environment (Celsius) (system monitor)
         Maximum temperature of environment (Celsius) (system monitor)
         Minimum temperature of environment (Celsius) (node controller)
         Maximum temperature of environment (Celsius) (node controller)
         Minimum temperature of processor (Celsius) (node controller)
         Maximum temperature of processor (Celsius) (node controller)
         Minimum temperature (Celsius) (switch)
         Maximum temperature (Celsius) (switch)
         Minimum relative humidity (%) (system monitor)
         Maximum relative humidity (%) (system monitor)
         Minimum relative humidity (%) (NC)
         Maximum relative humidity (%) (NC)
         Maximum amp draw (mA) (system monitor)
         Maximum amp draw (mA) (node controller)
         Maximum amp draw (mA) (switch)
      */

      // Temporary strings for holding each parameter
      String USART_baud = "";
      String USART_RX_buffer_size = "";
      String status_report_period = "";
      String max_num_SOS_boot_attempts = "";
      String max_num_subsystem_boot_attempts = "";
      String max_num_primary_boot_attempts = "";
      String device_reboot_period = "";
      String present_switch = "";
      String NC_boot_time = "";
      String switch_boot_time = "";
      String heartbeat_timeout_NC = "";
      String heartbeat_timeout_switch = "";
      String bad_environ_timeout_SysMon = "";
      String bad_environ_timeout_NC = "";
      String bad_temp_processor_timeout_NC = "";
      String bad_temp_timeout_switch = "";
      String bad_current_timeout_SysMon = "";
      String bad_current_timeout_NC = "";
      String bad_current_timeout_switch = "";
      String min_temp_SysMon = "";
      String max_temp_SysMon = "";
      String min_temp_NC = "";
      String max_temp_NC = "";
      String min_temp_processor_NC = "";
      String max_temp_processor_NC = "";
      String min_temp_switch = "";
      String max_temp_switch = "";
      String min_humidity_SysMon = "";
      String max_humidity_SysMon = "";
      String min_humidity_NC = "";
      String max_humidity_NC = "";
      String max_amp_SysMon = "";
      String max_amp_NC = "";
      String max_amp_switch = "";

      // Index for iterating thru the received string
      int i = 0;

      // Parse the received list of parameters:
      while(received_params[i] != NC_DELIMITER)
         USART_baud += received_params[i++];
      // Skip delimiter
      i++;

      while(received_params[i] != NC_DELIMITER)
         USART_RX_buffer_size += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         status_report_period += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_num_SOS_boot_attempts += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_num_subsystem_boot_attempts += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_num_primary_boot_attempts += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         device_reboot_period += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         present_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         NC_boot_time += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         switch_boot_time += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_environ_timeout_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_environ_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_temp_processor_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_temp_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_current_timeout_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_current_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_current_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_processor_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_processor_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_humidity_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_humidity_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_humidity_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_humidity_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_switch += received_params[i++];

      // Store new parameters in EEPROM
      eeprom_update_dword(&E_USART_BAUD, USART_baud.toInt());
      eeprom_update_word(&E_USART_RX_BUFFER_SIZE, (uint16_t)USART_RX_buffer_size.toInt());
      eeprom_update_byte(&E_STATUS_REPORT_PERIOD, (uint8_t)status_report_period.toInt());
      eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, (uint8_t)max_num_SOS_boot_attempts.toInt());
      eeprom_update_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS, (uint8_t)max_num_subsystem_boot_attempts.toInt());
      eeprom_update_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS, (uint8_t)max_num_primary_boot_attempts.toInt());
      eeprom_update_word(&E_DEVICE_REBOOT_PERIOD, (uint16_t)device_reboot_period.toInt());
      eeprom_update_byte(&E_PRESENT_SWITCH, (uint8_t)present_switch.toInt());
      eeprom_update_word(&E_BOOT_TIME_NC, (uint16_t)NC_boot_time.toInt());
      eeprom_update_byte(&E_BOOT_TIME_SWITCH, (uint8_t)switch_boot_time.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, (uint8_t)heartbeat_timeout_NC.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, (uint8_t)heartbeat_timeout_switch.toInt());
      eeprom_update_byte(&E_BAD_ENVIRON_TIMEOUT_SYSMON, (uint8_t)bad_environ_timeout_SysMon.toInt());
      eeprom_update_byte(&E_BAD_ENVIRON_TIMEOUT_NC, (uint8_t)bad_environ_timeout_NC.toInt());
      eeprom_update_byte(&E_BAD_TEMP_PROCESSOR_TIMEOUT_NC, (uint8_t)bad_temp_processor_timeout_NC.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SWITCH, (uint8_t)bad_temp_timeout_switch.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_SYSMON, (uint8_t)bad_current_timeout_SysMon.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_NC, (uint8_t)bad_current_timeout_NC.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_SWITCH, (uint8_t)bad_current_timeout_switch.toInt());
      eeprom_update_word(&E_TEMP_MIN_SYSMON, (uint16_t)min_temp_SysMon.toInt());
      eeprom_update_word(&E_TEMP_MAX_SYSMON, (uint16_t)max_temp_SysMon.toInt());
      eeprom_update_word(&E_TEMP_MIN_NC, (uint16_t)min_temp_NC.toInt());
      eeprom_update_word(&E_TEMP_MAX_NC, (uint16_t)max_temp_NC.toInt());
      eeprom_update_word(&E_TEMP_MIN_PROCESSOR_NC, (uint16_t)min_temp_processor_NC.toInt());
      eeprom_update_word(&E_TEMP_MAX_PROCESSOR_NC, (uint16_t)max_temp_processor_NC.toInt());
      eeprom_update_word(&E_TEMP_MIN_SWITCH, (uint16_t)min_temp_switch.toInt());
      eeprom_update_word(&E_TEMP_MAX_SWITCH, (uint16_t)max_temp_switch.toInt());
      eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, (uint8_t)min_humidity_SysMon.toInt());
      eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, (uint8_t)max_humidity_SysMon.toInt());
      eeprom_update_byte(&E_HUMIDITY_MIN_NC, (uint8_t)min_humidity_NC.toInt());
      eeprom_update_byte(&E_HUMIDITY_MAX_NC, (uint8_t)max_humidity_NC.toInt());
      eeprom_update_word(&E_AMP_MAX_SYSMON, (uint16_t)max_amp_SysMon.toInt());
      eeprom_update_word(&E_AMP_MAX_NC, (uint16_t)max_amp_NC.toInt());
      eeprom_update_word(&E_AMP_MAX_SWITCH, (uint16_t)max_amp_switch.toInt());
   }
}



//---------- G E T _ P A R A M S _ G N S --------------------------------------
/*
   Requests information about the guest nodes from the node controller.

   :rtype: none
*/
void get_params_GNs()
{
   // Send request
   Serial.println(NC_NOTIFIER_PARAMS_GN);

   // Save the node controller's response into a string.
   // Default timeout value is 1 second
   String received_params = "";
   received_params = Serial.readStringUntil(NC_TERMINATOR);

   // Were parameters received?
   if(received_params.length() > 0)
   {
      /* Order of parameters (coming from node controller):

         Present/not present (guest node 1)
         Present/not present (guest node 2)
         Present/not present (guest node 3)
         Boot time (guest node 1) (seconds)
         Boot time (guest node 2) (seconds)
         Boot time (guest node 3) (seconds)
         Heartbeat timeout (guest node 1)
         Heartbeat timeout (guest node 2)
         Heartbeat timeout (guest node 3)
         Bad temperature timeout (guest node 1)
         Bad temperature timeout (guest node 2)
         Bad temperature timeout (guest node 3)
         Bad current timeout (guest node 1)
         Bad current timeout (guest node 2)
         Bad current timeout (guest node 3)
         Minimum temperature (Celsius) (guest node 1)
         Maximum temperature (Celsius) (guest node 1)
         Minimum temperature (Celsius) (guest node 2)
         Maximum temperature (Celsius) (guest node 2)
         Minimum temperature (Celsius) (guest node 3)
         Maximum temperature (Celsius) (guest node 3)
         Maximum amp draw (mA) (guest node 1)
         Maximum amp draw (mA) (guest node 2)
         Maximum amp draw (mA) (guest node 3)
      */

      // Temporary strings for holding each parameter
      String present_GN1 = "";
      String present_GN2 = "";
      String present_GN3 = "";
      String boot_time_GN1 = "";
      String boot_time_GN2 = "";
      String boot_time_GN3 = "";
      String heartbeat_timeout_GN1 = "";
      String heartbeat_timeout_GN2 = "";
      String heartbeat_timeout_GN3 = "";
      String bad_temp_timeout_GN1 = "";
      String bad_temp_timeout_GN2 = "";
      String bad_temp_timeout_GN3 = "";
      String bad_current_timeout_GN1 = "";
      String bad_current_timeout_GN2 = "";
      String bad_current_timeout_GN3 = "";
      String min_temp_GN1 = "";
      String max_temp_GN1 = "";
      String min_temp_GN2 = "";
      String max_temp_GN2 = "";
      String min_temp_GN3 = "";
      String max_temp_GN3 = "";
      String max_amp_GN1 = "";
      String max_amp_GN2 = "";
      String max_amp_GN3 = "";

      // Index for iterating thru the received string
      int i = 0;

      // Parse the received list of parameters:
      while(received_params[i] != NC_DELIMITER)
         present_GN1 += received_params[i++];
      // Skip delimiter
      i++;

      while(received_params[i] != NC_DELIMITER)
         present_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         present_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         boot_time_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         boot_time_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         boot_time_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_temp_timeout_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_temp_timeout_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_temp_timeout_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_current_timeout_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_current_timeout_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_current_timeout_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_GN3 += received_params[i++];

      // Store new parameters in EEPROM
      eeprom_update_byte(&E_PRESENT_GN1, (uint8_t)present_GN1.toInt());
      eeprom_update_byte(&E_PRESENT_GN2, (uint8_t)present_GN2.toInt());
      eeprom_update_byte(&E_PRESENT_GN3, (uint8_t)present_GN3.toInt());
      eeprom_update_word(&E_BOOT_TIME_GN1, (uint16_t)boot_time_GN1.toInt());
      eeprom_update_word(&E_BOOT_TIME_GN2, (uint16_t)boot_time_GN2.toInt());
      eeprom_update_word(&E_BOOT_TIME_GN3, (uint16_t)boot_time_GN3.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, (uint8_t)heartbeat_timeout_GN1.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, (uint8_t)heartbeat_timeout_GN2.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, (uint8_t)heartbeat_timeout_GN3.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN1, (uint8_t)bad_temp_timeout_GN1.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN2, (uint8_t)bad_temp_timeout_GN2.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN3, (uint8_t)bad_temp_timeout_GN3.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN1, (uint8_t)bad_current_timeout_GN1.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN2, (uint8_t)bad_current_timeout_GN2.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN3, (uint8_t)bad_current_timeout_GN3.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN1, (uint16_t)min_temp_GN1.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN1, (uint16_t)max_temp_GN1.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN2, (uint16_t)min_temp_GN2.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN2, (uint16_t)max_temp_GN2.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN3, (uint16_t)min_temp_GN3.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN3, (uint16_t)max_temp_GN3.toInt());
      eeprom_update_word(&E_AMP_MAX_GN1, (uint16_t)max_amp_GN1.toInt());
      eeprom_update_word(&E_AMP_MAX_GN2, (uint16_t)max_amp_GN2.toInt());
      eeprom_update_word(&E_AMP_MAX_GN3, (uint16_t)max_amp_GN3.toInt());
   }
}



//---------- G E T _ T I M E _ N C --------------------------------------------
/*
   Requests a time update from the node controller.  If an update is received,
   the RTC is set to the new time.

   :rtype: none
*/
void get_time_NC()
{
   // Send request
   Serial.println(NC_NOTIFIER_TIME_REQUEST);

   // Save the node controller's response into a string.
   // Default timeout value is 1 second
   String received_time = "";
   received_time = Serial.readStringUntil(NC_TERMINATOR);

   // Was time received?
   if(received_time.length() > 0)
   {
      /* Order of values (coming from node controller):
      
      Year
      Month
      Day
      Hour
      Minute
      Second
      */

      // Temporary strings for holding each value
      String received_year = "";
      String received_month = "";
      String received_day = "";
      String received_hour = "";
      String received_minute = "";
      String received_second = "";

      // Index for iterating thru the received string
      int i = 0;

      // Parse the received list of values:
      while(received_time[i] != NC_DELIMITER)
         received_year += received_time[i++];
      // Skip delimiter
      i++;

      while(received_time[i] != NC_DELIMITER)
         received_month += received_time[i++];
      i++;

      while(received_time[i] != NC_DELIMITER)
         received_day += received_time[i++];
      i++;

      while(received_time[i] != NC_DELIMITER)
         received_hour += received_time[i++];
      i++;

      while(received_time[i] != NC_DELIMITER)
         received_minute += received_time[i++];
      i++;

      while(received_time[i] != NC_DELIMITER)
         received_second += received_time[i++];
      i++;

      // Set SysMon's time to received time
      setTime(received_hour.toInt(),
         received_minute.toInt(),
         received_second.toInt(),
         received_day.toInt(),
         received_month.toInt(),
         received_year.toInt());
      // Set RTC time to SysMon's time
      RTC.set(now());
   }
}



//---------- I N I T _ P R I M A R Y ------------------------------------------
/*
   Initializes/starts all necessary ports, peripherals, interrupts, etc.

   :rtype: none
*/
void init_primary()
{
   // Enable interrupts
   interrupts();

   // Set sleep mode to "power down" (turns off all clocks).
   // See datasheet and sleep.h file.
   set_sleep_mode(SLEEP_MODE_PWR_DOWN);

   // Start watchdog with 2 second timeout
   wdt_enable(WDTO_2S);

   // Make sure all the Timer1 registers are cleared
   TCCR1A = 0;
   TCCR1B = 0;
   TCCR1C = 0;
   TCNT1 = 0;
   OCR1A = 0;
   OCR1B = 0;
   OCR1C = 0;
   ICR1 = 0;
   TIMSK1 = 0;

   // Enable Timer1 overflow interrupt
   TIMSK1 = _BV(TOIE1);

   // Start Timer1 with prescaler of clk/256 (timeout of approx. 1 second)
   TCCR1B = _BV(CS12);

   // Join I2C bus as master
   Wire.begin();

   // Enable serial comms
   Serial.begin(eeprom_read_dword(&E_USART_BAUD));

   // Clear POST result to avoid confusion if a future boot fails
   eeprom_update_byte(&E_POST_RESULT, 0);
   // Clear the number of SOS boot attempts to start with a clean slate
   // for the next partial boot failure
   eeprom_update_byte(&E_NUM_SOS_BOOT_ATTEMPTS, 0);
   // Clear the number of primary boot attempts to start with a clean slate
   // for the next boot failure
   //eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);
   // Clear the flag for the timer test being incomplete, otherwise the next
   // POST may incorrectly mark the timer as malfunctioning
   eeprom_update_byte(&E_TIMER_TEST_INCOMPLETE, 0);

   // Set ADC reference voltage to Vcc
   analogReference(DEFAULT);
   // Read ADC channels a few times to settle them down
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_THERMISTOR_NC);
   analogRead(PIN_THERMISTOR_NC);
   analogRead(PIN_THERMISTOR_NC);
   analogRead(PIN_THERMISTOR_SWITCH);
   analogRead(PIN_THERMISTOR_SWITCH);
   analogRead(PIN_THERMISTOR_SWITCH);
   analogRead(PIN_THERMISTOR_GN1);
   analogRead(PIN_THERMISTOR_GN1);
   analogRead(PIN_THERMISTOR_GN1);
   analogRead(PIN_THERMISTOR_GN2);
   analogRead(PIN_THERMISTOR_GN2);
   analogRead(PIN_THERMISTOR_GN2);
   analogRead(PIN_THERMISTOR_GN3);
   analogRead(PIN_THERMISTOR_GN3);
   analogRead(PIN_THERMISTOR_GN3);

   // Start HTU21D
   SysMon_HTU21D.begin();

   // Start I2C transaction with SysMon's current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_SYSMON);
   // Tell sensor we're writing to "gain" register
   Wire.write(0x04);
   // Write 3 expected bytes to "gain" register (select 8 amp range)
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Start I2C transaction with NC's current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_NC);
   // Tell sensor we're writing to "gain" register
   Wire.write(0x04);
   // Write 3 expected bytes to "gain" register (select 8 amp range)
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Start I2C transaction with switch's current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_SWITCH);
   // Tell sensor we're writing to "gain" register
   Wire.write(0x04);
   // Write 3 expected bytes to "gain" register (select 8 amp range)
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Start I2C transaction with GN1's current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN1);
   // Tell sensor we're writing to "gain" register
   Wire.write(0x04);
   // Write 3 expected bytes to "gain" register (select 8 amp range)
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Start I2C transaction with GN2's current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN2);
   // Tell sensor we're writing to "gain" register
   Wire.write(0x04);
   // Write 3 expected bytes to "gain" register (select 8 amp range)
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Start I2C transaction with GN3's current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN3);
   // Tell sensor we're writing to "gain" register
   Wire.write(0x04);
   // Write 3 expected bytes to "gain" register (select 8 amp range)
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Give relays time to settle down, in case there was a chip reset
   delay(POWER_CYCLE_DELAY);

   // Set relay pins to output mode
   pinMode(PIN_RELAY_NC, OUTPUT);
   pinMode(PIN_RELAY_SWITCH, OUTPUT);
   pinMode(PIN_RELAY_GN1, OUTPUT);
   pinMode(PIN_RELAY_GN2, OUTPUT);
   pinMode(PIN_RELAY_GN3, OUTPUT);

   // Set heartbeat pins to input mode (just for clarity)
   pinMode(PIN_HEARTBEAT_NC, INPUT);
   pinMode(PIN_HEARTBEAT_SWITCH, INPUT);
   pinMode(PIN_HEARTBEAT_GN1, INPUT);
   pinMode(PIN_HEARTBEAT_GN2, INPUT);
   pinMode(PIN_HEARTBEAT_GN3, INPUT);

   Serial.println(1);
}



//---------- S E T _ D E F A U L T _ E E P R O M ------------------------------
/*
    Assigns default values to the parameters stored in EEPROM.  This function
    is only executed on the first boot of a new SysMon, to avoid writing to
    EEPROM every time.

    :rtype: none
*/
void set_default_eeprom()
{
   // EEPROM addresses whose values are set by node controller:
   eeprom_update_dword(&E_USART_BAUD, 57600);
   eeprom_update_word(&E_USART_RX_BUFFER_SIZE, 200);
   eeprom_update_byte(&E_STATUS_REPORT_PERIOD, 30);
   eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, 3);
   eeprom_update_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS, 3);
   eeprom_update_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS, 3);
   eeprom_update_word(&E_DEVICE_REBOOT_PERIOD, 15);
   eeprom_update_byte(&E_PRESENT_SWITCH, 0);
   eeprom_update_word(&E_BOOT_TIME_NC, 10);
   eeprom_update_byte(&E_BOOT_TIME_SWITCH, 5);
   eeprom_update_word(&E_BOOT_TIME_GN1, 10);
   eeprom_update_word(&E_BOOT_TIME_GN2, 10);
   eeprom_update_word(&E_BOOT_TIME_GN2, 10);
   eeprom_update_byte(&E_PRESENT_GN1, 0);
   eeprom_update_byte(&E_PRESENT_GN2, 0);
   eeprom_update_byte(&E_PRESENT_GN3, 0);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, 5);
   eeprom_update_byte(&E_BAD_ENVIRON_TIMEOUT_SYSMON, 5);
   eeprom_update_byte(&E_BAD_ENVIRON_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_BAD_TEMP_PROCESSOR_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN3, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_SYSMON, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN3, 5);
   eeprom_update_word(&E_TEMP_MIN_SYSMON, 0);
   eeprom_update_word(&E_TEMP_MAX_SYSMON, 100);
   eeprom_update_word(&E_TEMP_MIN_NC, 0);
   eeprom_update_word(&E_TEMP_MAX_NC, 100);
   // Temperatures below are ADC values (see WagMan.py on node controller)
   eeprom_update_word(&E_TEMP_MIN_PROCESSOR_NC, 115);
   eeprom_update_word(&E_TEMP_MAX_PROCESSOR_NC, 969);
   eeprom_update_word(&E_TEMP_MIN_SWITCH, 417);
   eeprom_update_word(&E_TEMP_MAX_SWITCH, 969);
   eeprom_update_word(&E_TEMP_MIN_GN1, 417);
   eeprom_update_word(&E_TEMP_MAX_GN1, 969);
   eeprom_update_word(&E_TEMP_MIN_GN2, 417);
   eeprom_update_word(&E_TEMP_MAX_GN2, 969);
   eeprom_update_word(&E_TEMP_MIN_GN3, 417);
   eeprom_update_word(&E_TEMP_MAX_GN3, 969);
   eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, 0);
   eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, 100);
   eeprom_update_byte(&E_HUMIDITY_MIN_NC, 0);
   eeprom_update_byte(&E_HUMIDITY_MAX_NC, 100);
   eeprom_update_word(&E_AMP_MAX_SYSMON, 4000);
   eeprom_update_word(&E_AMP_MAX_NC, 2500);
   eeprom_update_word(&E_AMP_MAX_SWITCH, 1500);
   eeprom_update_word(&E_AMP_MAX_GN1, 2500);
   eeprom_update_word(&E_AMP_MAX_GN2, 2500);
   eeprom_update_word(&E_AMP_MAX_GN3, 2500);

   // Save the indicator that this SysMon has booted before
   eeprom_update_byte(&E_FIRST_BOOT, 0);

   // Clear the counter for number of primary boot attempts
   eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);
}