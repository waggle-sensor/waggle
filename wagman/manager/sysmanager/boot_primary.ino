//---------- C O N S T A N T S ------------------------------------------------




//---------- G L O B A L S ----------------------------------------------------




//---------- B O O T _ P R I M A R Y ------------------------------------------
/*
   Starts/initializes/boots self, node controller, and ethernet switch.
   Conditions for and operation of the node controller and ethernet switch are
   verified before completing boot sequence.

   :rtype: boolean
*/
boolean boot_primary()
{
	// Initialize/start internal components
	init_primary();

   // Is this the first ever boot?
   if(E_FIRST_BOOT)
      // Set default EEPROM values
      set_default_eeprom();

	// Check that SysMon is drawing an expected amount of power
	check_power_self();

	// Check that the SysMon's environment is suitable
	check_environ_self();

	// Is the node controller not enabled?
	if(!eeprom_read_byte(&E_NC_ENABLED))
		// Nothing for us to do, so go to sleep
		sleep();

	// Check that the node controller's environment is suitable
	check_environ_nc();

	// Enable power to node controller

	// Check that the node controller is drawing an expected amount of power
	check_power_nc();

	// Check that the node controller is alive (sending a "heartbeat")
	check_heartbeat_nc();

	// Request time from node controller
	get_time_nc();

   // Request operating parameters from node controller
   get_params_core();

	// Request guest node info from node controller.  No info received?
	if(!get_params_GNs())
		// Skip the rest of the boot sequence
		return false;

	// Is the ethernet switch enabled?
	if(!eeprom_read_byte(&E_SWITCH_ENABLED))
		// Skip the rest of the boot sequence
		return false;

	// Check that the ethernet switch's environment is suitable
	check_environ_switch();

	// Enable power to ethernet switch

	// Check that the ethernet switch is drawing an expected amount of power
	check_power_switch();

	// Check that the ethernet switch is alive (sending a "heartbeat")
	check_heartbeat_switch();

	// Everything is good, so exit sequence with success
	return true;
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

	// Set LED pin to output so we can turn on the LED
   pinMode(LED, OUTPUT);

	// Join I2C bus as master
	Wire.begin();

	// Enable serial comms
   Serial.begin(eeprom_read_dword(&E_USART_BAUD));

   // Clear POST result to avoid confusion if a future boot fails
   eeprom_update_byte(&E_POST_RESULT, 0);
   // Clear the number of SOS boot attempts to start with a clean slate
   // for the next partial boot failure
   eeprom_update_byte(&E_NUM_SOS_BOOT_TRIES, 0);
   // Clear the flag for the timer test being incomplete, otherwise the next
   // POST may incorrectly mark the timer as malfunctioning
   eeprom_update_byte(&E_TIMER_TEST_INCOMPLETE, 0);

   // Set ADC reference voltage to 5V
   analogReference(DEFAULT);
   // Read ADC channels a few times to settle them down
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_JP10_10);
   analogRead(PIN_JP10_10);
   analogRead(PIN_JP10_10);

   // Start HTU21D
   SysMon_HTU21D.begin();
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
   eeprom_update_word(&E_USART_RX_BUFFER_SIZE, 150);
   eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_TRIES, 3);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN4, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SYSMON, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN3, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN4, 5);
   eeprom_update_word(&E_TEMP_MIN_SYSMON_SIGNED, 0);
   eeprom_update_word(&E_TEMP_MAX_SYSMON_SIGNED, 100);
   eeprom_update_word(&E_TEMP_MIN_NC_SIGNED, 0);
   eeprom_update_word(&E_TEMP_MAX_NC_SIGNED, 100);
   eeprom_update_word(&E_TEMP_MIN_SWITCH_SIGNED, 0);
   eeprom_update_word(&E_TEMP_MAX_SWITCH_SIGNED, 100);
   eeprom_update_word(&E_TEMP_MIN_GN1_SIGNED, 0);
   eeprom_update_word(&E_TEMP_MAX_GN1_SIGNED, 100);
   eeprom_update_word(&E_TEMP_MIN_GN2_SIGNED, 0);
   eeprom_update_word(&E_TEMP_MAX_GN2_SIGNED, 100);
   eeprom_update_word(&E_TEMP_MIN_GN3_SIGNED, 0);
   eeprom_update_word(&E_TEMP_MAX_GN3_SIGNED, 100);
   eeprom_update_word(&E_TEMP_MIN_GN4_SIGNED, 0);
   eeprom_update_word(&E_TEMP_MAX_GN4_SIGNED, 100);
   eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, 30);
   eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, 100);

   // Save the indicator that this SysMon has booted before
   eeprom_update_byte(&E_FIRST_BOOT, 0);
}



//---------- C H E C K _ P O W E R _ S E L F ----------------------------------
/*
   Reads its own current sensor.  If too much power is being drawn, we shut
   ourselves down.

   :rtype: none
*/
void check_power_self()
{

}



//---------- C H E C K _ E N V I R O N _ S E L F ------------------------------
/*
   Gets temperature and humidity info from the sensor, then checks if the 
   environment is suitable for safe operation of the system monitor.  If it is
   not safe, then we go to sleep.

   :rtype: none
*/
void check_environ_self()
{

}



//---------- C H E C K _ E N V I R O N _ N C ----------------------------------
/*
   Gets temperature and humidity info from the sensor, then checks if the 
   environment is suitable for safe operation of the node controller.  If it
   is not safe, then we monitor it until it is safe.

   :rtype: none
*/
void check_environ_nc()
{

}



//---------- C H E C K _ P O W E R _ N C --------------------------------------
/*
   Reads the node controller's current sensor.  If the node controller is not
   drawing any power or is drawing too much power, we'll shut it down and go
   to sleep.

   :rtype: none
*/
void check_power_nc()
{

}



//---------- C H E C K _ H E A R T B E A T _ N C ------------------------------
/*
   Checks that the node controller is alive and sending a heartbeat.  If it is
   not, then power cycle it and try again.  If a reboot is tried too many
   times, the node controller is assumed to be dead, so we go to sleep.

   :rtype: none
*/
void check_heartbeat_nc()
{

}



//---------- G E T _ P A R A M S _ G N S --------------------------------------
/*
   Requests information about the guest nodes from the node controller.
   Expected data for each guest nodes contains: present/not present, acceptable
   environmental conditions, and expected power draw.  If the node controller
   takes too long to send the info, we skip booting the guest nodes.

   :rtype: boolean
*/
boolean get_params_GNs()
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
         Present/not present (guest node 4)
         Heartbeat timeout (guest node 1)
         Heartbeat timeout (guest node 2)
         Heartbeat timeout (guest node 3)
         Heartbeat timeout (guest node 4)
         Bad temperature timeout (guest node 1)
         Bad temperature timeout (guest node 2)
         Bad temperature timeout (guest node 3)
         Bad temperature timeout (guest node 4)
         Minimum temperature (Celsius) (signed) (guest node 1)
         Maximum temperature (Celsius) (signed) (guest node 1)
         Minimum temperature (Celsius) (signed) (guest node 2)
         Maximum temperature (Celsius) (signed) (guest node 2)
         Minimum temperature (Celsius) (signed) (guest node 3)
         Maximum temperature (Celsius) (signed) (guest node 3)
         Minimum temperature (Celsius) (signed) (guest node 4)
         Maximum temperature (Celsius) (signed) (guest node 4)
      */

      // Temporary strings for holding each parameter
      String present_GN1 = "";
      String present_GN2 = "";
      String present_GN3 = "";
      String present_GN4 = "";
      String heartbeat_timeout_GN1 = "";
      String heartbeat_timeout_GN2 = "";
      String heartbeat_timeout_GN3 = "";
      String heartbeat_timeout_GN4 = "";
      String bad_temp_timeout_GN1 = "";
      String bad_temp_timeout_GN2 = "";
      String bad_temp_timeout_GN3 = "";
      String bad_temp_timeout_GN4 = "";
      String min_temp_GN1 = "";
      String max_temp_GN1 = "";
      String min_temp_GN2 = "";
      String max_temp_GN2 = "";
      String min_temp_GN3 = "";
      String max_temp_GN3 = "";
      String min_temp_GN4 = "";
      String max_temp_GN4 = "";

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
         present_GN4 += received_params[i++];
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
         heartbeat_timeout_GN4 += received_params[i++];
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
         bad_temp_timeout_GN4 += received_params[i++];
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
         min_temp_GN4 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_GN4 += received_params[i++];
      i++;

      // Store new parameters in EEPROM
      eeprom_update_byte(&E_PRESENT_GN1, (uint8_t)present_GN1.toInt());
      eeprom_update_byte(&E_PRESENT_GN2, (uint8_t)present_GN2.toInt());
      eeprom_update_byte(&E_PRESENT_GN3, (uint8_t)present_GN3.toInt());
      eeprom_update_byte(&E_PRESENT_GN4, (uint8_t)present_GN4.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, (uint8_t)heartbeat_timeout_GN1.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, (uint8_t)heartbeat_timeout_GN2.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, (uint8_t)heartbeat_timeout_GN3.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN4, (uint8_t)heartbeat_timeout_GN4.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN1, (uint8_t)bad_temp_timeout_GN1.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN2, (uint8_t)bad_temp_timeout_GN2.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN3, (uint8_t)bad_temp_timeout_GN3.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN4, (uint8_t)bad_temp_timeout_GN4.toInt());
      // EEPROM only stores unsigned values.  Must cast to signed when reading.
      eeprom_update_word(&E_TEMP_MIN_GN1_SIGNED, (uint16_t)min_temp_GN1.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN1_SIGNED, (uint16_t)max_temp_GN1.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN2_SIGNED, (uint16_t)min_temp_GN2.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN2_SIGNED, (uint16_t)max_temp_GN2.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN3_SIGNED, (uint16_t)min_temp_GN3.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN3_SIGNED, (uint16_t)max_temp_GN3.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN4_SIGNED, (uint16_t)min_temp_GN4.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN4_SIGNED, (uint16_t)max_temp_GN4.toInt());

      return true;
   }
   // No parameters received?
   else
      return false;
}



//---------- G E T _ T I M E _ N C --------------------------------------------
/*
   Requests a time update from the node controller.  If a time update is
   received, the RTC is initialized with that time.  If a time update is not
   recieved, the RTC is started without a time correction.

   :rtype: none
*/
void get_time_nc()
{

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
         Max number of SOS boot attempts
         Heartbeat timeout (node controller)
         Heartbeat timeout (switch)
         Bad temperature timeout (system monitor)
         Bad temperature timeout (node controller)
         Bad temperature timeout (switch)
         Minimum temperature (Celsius) (signed) (system monitor)
         Maximum temperature (Celsius) (signed) (system monitor)
         Minimum temperature (Celsius) (signed) (node controller)
         Maximum temperature (Celsius) (signed) (node controller)
         Minimum temperature (Celsius) (signed) (switch)
         Maximum temperature (Celsius) (signed) (switch)
         Minimum relative humidity (%) (system monitor)
         Maximum relative humidity (%) (system monitor)
      */

      // Temporary strings for holding each parameter
      String USART_baud;
      String USART_RX_buffer_size = "";
      String max_num_SOS_boot_tries = "";
      String heartbeat_timeout_NC = "";
      String heartbeat_timeout_switch = "";
      String bad_temp_timeout_sysmon = "";
      String bad_temp_timeout_NC = "";
      String bad_temp_timeout_switch = "";
      String min_temp_sysmon = "";
      String max_temp_sysmon = "";
      String min_temp_NC = "";
      String max_temp_NC = "";
      String min_temp_switch = "";
      String max_temp_switch = "";
      String min_humidity_sysmon = "";
      String max_humidity_sysmon = "";

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
         max_num_SOS_boot_tries += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_temp_timeout_sysmon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_temp_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_temp_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_sysmon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_sysmon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_humidity_sysmon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_humidity_sysmon += received_params[i++];

      // Store new parameters in EEPROM
      eeprom_update_dword(&E_USART_BAUD, USART_baud.toInt());
      eeprom_update_word(&E_USART_RX_BUFFER_SIZE, (uint16_t)USART_RX_buffer_size.toInt());
      eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_TRIES, (uint8_t)max_num_SOS_boot_tries.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, (uint8_t)heartbeat_timeout_NC.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, (uint8_t)heartbeat_timeout_switch.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SYSMON, (uint8_t)bad_temp_timeout_sysmon.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_NC, (uint8_t)bad_temp_timeout_NC.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SWITCH, (uint8_t)bad_temp_timeout_switch.toInt());
      // EEPROM only stores unsigned values.  Must cast to signed when reading.
      eeprom_update_word(&E_TEMP_MIN_SYSMON_SIGNED, (uint16_t)min_temp_sysmon.toInt());
      eeprom_update_word(&E_TEMP_MAX_SYSMON_SIGNED, (uint16_t)max_temp_sysmon.toInt());
      eeprom_update_word(&E_TEMP_MIN_NC_SIGNED, (uint16_t)min_temp_NC.toInt());
      eeprom_update_word(&E_TEMP_MAX_NC_SIGNED, (uint16_t)max_temp_NC.toInt());
      eeprom_update_word(&E_TEMP_MIN_SWITCH_SIGNED, (uint16_t)min_temp_switch.toInt());
      eeprom_update_word(&E_TEMP_MAX_SWITCH_SIGNED, (uint16_t)max_temp_switch.toInt());
      eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, (uint8_t)min_humidity_sysmon.toInt());
      eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, (uint8_t)max_humidity_sysmon.toInt());
   }
}



//---------- C H E C K _ E N V I R O N _ S W I T C H --------------------------
/*
   Gets temperature info from the thermistor, then checks if the 
   environment is suitable for safe operation of the ethernet switch.  If it
   is not safe, then we monitor it until it is safe.

   :rtype: none
*/
void check_environ_switch()
{

}



//---------- C H E C K _ P O W E R _ S W I T C H ------------------------------
/*
   Reads the ethernet switch's current sensor.  If the ethernet switch is not
   drawing any power or is drawing too much power, we'll shut it down and
   inform the node controller (and wait for it to inform the cloud), then go
   to sleep.

   :rtype: none
*/
void check_power_switch()
{

}



//---------- C H E C K _ H E A R T B E A T _ S W I T C H ----------------------
/*
   Checks that the ethernet switch is alive and sending a heartbeat.  If it is
   not, then power cycle it and try again.  If a reboot is tried too many
   times, the ethernet switch is assumed to be dead, so we inform the node 
   controller (and wait for it to inform the cloud), then go to sleep.

   :rtype: none
*/
void check_heartbeat_switch()
{

}