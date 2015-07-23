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
   if(eeprom_read_byte(&E_FIRST_BOOT) != 0)
      // Assign default parameters
      set_default_eeprom();

	// Is SysMon drawing too much power?
	if(!check_power_self())
      // Skip the rest of the boot sequence
      return false;

	// Is SysMon's environment outside of safe bounds?
	if(!check_environ_self())
      // Skip the rest of the boot sequence
      return false;

	// Is the node controller not enabled?
	if(!eeprom_read_byte(&E_NC_ENABLED))
		// Skip the rest of the boot sequence
      return false;

	// Check that the node controller's environment is suitable
	check_environ_nc();

	// Enable power to node controller
   digitalWrite(PIN_RELAY_NC, HIGH);

   // Give the node controller time to boot
   delay(eeprom_read_word(&E_NC_BOOT_TIME) * 1000);

	// Is the node controller not drawing expected amount of power?
	if(!check_power_nc())
      // Skip the rest of the boot sequence
      return false;

	// Is the node controller alive (sending a "heartbeat")?
	if(!check_heartbeat_nc())
   {
      for(byte boot_attempts = 0; 
         boot_attempts < eeprom_read_byte(&E_MAX_NUM_NC_BOOT_ATTEMPTS);
         boot_attemps++)
      {
         // Is "heartbeat" not detected?
         if(!check_heartbeat_nc())
         {
            // Power cycle the node controller
            digitalWrite(PIN_RELAY_NC, LOW);
            delay(100);
            digitalWrite(PIN_RELAY_NC, HIGH);

            // Give the node controller time to boot
            delay(eeprom_read_word(&E_NC_BOOT_TIME) * 1000);

            // Is the node controller not drawing an expected amount of power?
            if(!check_power_nc())
               // Skip the rest of the boot sequence
               return false;
         }
      }
   }

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

	// Join I2C bus as master
	Wire.begin();

	// Enable serial comms
   Serial.begin(eeprom_read_dword(&E_USART_BAUD));

   // Clear POST result to avoid confusion if a future boot fails
   eeprom_update_byte(&E_POST_RESULT, 0);
   // Clear the number of SOS boot attempts to start with a clean slate
   // for the next partial boot failure
   eeprom_update_byte(&E_NUM_SOS_BOOT_ATTEMPTS, 0);
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
   eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, 3);
   eeprom_update_byte(&E_MAX_NUM_NC_BOOT_ATTEMPTS, 3);
   eeprom_update_word(&E_NC_BOOT_TIME, 30);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SYSMON, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN3, 5);
   eeprom_update_word(&E_AMP_NOISE_CEILING, 31);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_SYSMON, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN3, 5);
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
   eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, 30);
   eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, 100);
   eeprom_update_word(&E_AMP_MAX_SYSMON, 400);
   eeprom_update_word(&E_AMP_MAX_NC, 4000);
   eeprom_update_word(&E_AMP_MAX_SWITCH, 1500);
   eeprom_update_word(&E_AMP_MAX_GN1, 4000);
   eeprom_update_word(&E_AMP_MAX_GN2, 4000);
   eeprom_update_word(&E_AMP_MAX_GN3, 4000);

   // Save the indicator that this SysMon has booted before
   eeprom_update_byte(&E_FIRST_BOOT, 0);
}



//---------- C H E C K _ P O W E R _ S E L F ----------------------------------
/*
   Reads the SysMon's current sensor.

   Return TRUE: SysMon is drawing expected current.
   Return FALSE: SysMon is drawing too much current.

   :rtype: boolean
*/
boolean check_power_self()
{
   byte msb, csb, lsb;
   
   // Start I2C transaction with current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_SYSMON);
   // Tell sensor we want to read "data" register
   Wire.write(0);
   // Sensor expects restart condition, so end I2C transaction (no stop bit)
   Wire.endTransmission(0);
   // Ask sensor for data
   Wire.requestFrom(ADDR_CURRENT_SENSOR_SYSMON, 3);

   // Read the 3 bytes that the sensor returns
   if(Wire.available())
   {
      msb = Wire.read();
      // We only care about the data, so the mask hides the SYNC flag
      csb = Wire.read() & 0x01;
      lsb = Wire.read();
   }
   else
      // Exit with failure
      return false;

   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Calculate milliamps from raw sensor data
   unsigned int milliamps = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

   // Is measured current below allowed maximum?
   if(milliamps < eeprom_read_word(&E_AMP_MAX_SYSMON))
      // Exit with success
      return true;

   // Exit with failure
   return false;
}



//---------- C H E C K _ E N V I R O N _ S E L F ------------------------------
/*
   Reads the HTU21D sensor.  If the environment is unsafe, the function 
   returns FALSE.  If the environment is acceptable, the function returns TRUE.

   :rtype: boolean
*/
boolean check_environ_self()
{
   // Read temperature and truncate it (so we don't deal with floats)
   int temp = SysMon_HTU21D.readTemperature();

   // Read humidity and truncate it (so we don't deal with floats)
   byte humidity = SysMon_HTU21D.readHumidity();

   // Is measured temperature acceptable?
   if(((int)eeprom_read_word(&E_TEMP_MIN_SYSMON_SIGNED) < temp)
      && (temp < (int)eeprom_read_word(&E_TEMP_MAX_SYSMON_SIGNED))
      && (eeprom_read_byte(&E_HUMIDITY_MIN_SYSMON) < humidity)
      && (humidity < eeprom_read_byte(&E_HUMIDITY_MAX_SYSMON)))
   {
      // Exit with success
      return true;
   }

   // Exit with failure
   return false;
}



//---------- C H E C K _ E N V I R O N _ N C ----------------------------------
/*
   Reads thermistor to check if the environment is suitable for safe operation
   of the node controller.  If it is not safe, then we monitor it until it 
   is safe.

   :rtype: none
*/
void check_environ_nc()
{

}



//---------- C H E C K _ P O W E R _ N C --------------------------------------
/*
   Reads the node controller's current sensor.  If the node controller is not
   drawing any power or is drawing too much power, we'll shut it down.

   Return TRUE: node controller is drawing expected current.
   Return FALSE: node controller is drawing no/too much current.

   :rtype: boolean
*/
boolean check_power_nc()
{
   byte msb, csb, lsb;
   
   // Start I2C transaction with current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_NC);
   // Tell sensor we want to read "data" register
   Wire.write(0);
   // Sensor expects restart condition, so end I2C transaction (no stop bit)
   Wire.endTransmission(0);
   // Ask sensor for data
   Wire.requestFrom(ADDR_CURRENT_SENSOR_NC, 3);

   // Read the 3 bytes that the sensor returns
   if(Wire.available())
   {
      msb = Wire.read();
      // We only care about the data, so the mask hides the SYNC flag
      csb = Wire.read() & 0x01;
      lsb = Wire.read();
   }
   else
      // Exit with failure
      return false;

   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Calculate milliamps from raw sensor data
   unsigned int milliamps = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

   // Is measured current below allowed maximum?
   if(milliamps < eeprom_read_word(&E_AMP_MAX_NC))
      // Exit with success
      return true;

   // Exit with failure
   return false;
}



//---------- C H E C K _ H E A R T B E A T _ N C ------------------------------
/*
   Checks that the node controller is alive and sending a heartbeat.

   Return TRUE: node controller's heartbeat is good.
   Return FALSE: node controller's heartbeat is not good.

   :rtype: boolean
*/
boolean check_heartbeat_nc()
{
   // Is "heartbeat" detected?
   if(digitalRead(PIN_HEARTBEAT_NC))
      // Exit with success
      return true;

   // Exit with failure
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
         Max number of node controller boot attempts
         Node controller boot time
         Heartbeat timeout (node controller)
         Heartbeat timeout (switch)
         Bad temperature timeout (system monitor)
         Bad temperature timeout (node controller)
         Bad temperature timeout (switch)
         Bad current timeout (system monitor)
         Bad current timeout (node controller)
         Bad current timeout (switch)
         Current noise ceiling (mA)
         Minimum temperature (Celsius) (signed) (system monitor)
         Maximum temperature (Celsius) (signed) (system monitor)
         Minimum temperature (Celsius) (signed) (node controller)
         Maximum temperature (Celsius) (signed) (node controller)
         Minimum temperature (Celsius) (signed) (switch)
         Maximum temperature (Celsius) (signed) (switch)
         Minimum relative humidity (%) (system monitor)
         Maximum relative humidity (%) (system monitor)
         Maximum amp draw (mA) (system monitor)
         Maximum amp draw (mA) (node controller)
         Maximum amp draw (mA) (switch)
      */

      // Temporary strings for holding each parameter
      String USART_baud;
      String USART_RX_buffer_size = "";
      String max_num_SOS_boot_attempts = "";
      String max_num_NC_boot_attempts = "";
      String NC_boot_time = "";
      String heartbeat_timeout_NC = "";
      String heartbeat_timeout_switch = "";
      String bad_temp_timeout_sysmon = "";
      String bad_temp_timeout_NC = "";
      String bad_temp_timeout_switch = "";
      String bad_current_timeout_sysmon = "";
      String bad_current_timeout_NC = "";
      String bad_current_timeout_switch = "";
      String current_noise_ceiling = "";
      String min_temp_sysmon = "";
      String max_temp_sysmon = "";
      String min_temp_NC = "";
      String max_temp_NC = "";
      String min_temp_switch = "";
      String max_temp_switch = "";
      String min_humidity_sysmon = "";
      String max_humidity_sysmon = "";
      String max_amp_sysmon = "";
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
         max_num_SOS_boot_attempts += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_num_NC_boot_attempts += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         NC_boot_time += received_params[i++];
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
         bad_current_timeout_sysmon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_current_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         bad_current_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         current_noise_ceiling += received_params[i++];
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
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_sysmon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_switch += received_params[i++];

      // Store new parameters in EEPROM
      eeprom_update_dword(&E_USART_BAUD, USART_baud.toInt());
      eeprom_update_word(&E_USART_RX_BUFFER_SIZE, (uint16_t)USART_RX_buffer_size.toInt());
      eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, (uint8_t)max_num_SOS_boot_attempts.toInt());
      eeprom_update_byte(&E_MAX_NUM_NC_BOOT_ATTEMPTS, (uint8_t)max_num_NC_boot_attempts.toInt());
      eeprom_update_word(&E_NC_BOOT_TIME, (uint16_t)NC_boot_time.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, (uint8_t)heartbeat_timeout_NC.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, (uint8_t)heartbeat_timeout_switch.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SYSMON, (uint8_t)bad_temp_timeout_sysmon.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_NC, (uint8_t)bad_temp_timeout_NC.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_SWITCH, (uint8_t)bad_temp_timeout_switch.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_SYSMON, (uint8_t)bad_current_timeout_sysmon.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_NC, (uint8_t)bad_current_timeout_NC.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_SWITCH, (uint8_t)bad_current_timeout_switch.toInt());
      eeprom_update_word(&E_AMP_NOISE_CEILING, (uint16_t)current_noise_ceiling.toInt());
      // EEPROM does not store data types.  Must cast to signed when reading.
      eeprom_update_word(&E_TEMP_MIN_SYSMON_SIGNED, (uint16_t)min_temp_sysmon.toInt());
      eeprom_update_word(&E_TEMP_MAX_SYSMON_SIGNED, (uint16_t)max_temp_sysmon.toInt());
      eeprom_update_word(&E_TEMP_MIN_NC_SIGNED, (uint16_t)min_temp_NC.toInt());
      eeprom_update_word(&E_TEMP_MAX_NC_SIGNED, (uint16_t)max_temp_NC.toInt());
      eeprom_update_word(&E_TEMP_MIN_SWITCH_SIGNED, (uint16_t)min_temp_switch.toInt());
      eeprom_update_word(&E_TEMP_MAX_SWITCH_SIGNED, (uint16_t)max_temp_switch.toInt());
      eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, (uint8_t)min_humidity_sysmon.toInt());
      eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, (uint8_t)max_humidity_sysmon.toInt());
      eeprom_update_word(&E_AMP_MAX_SYSMON, (uint16_t)max_amp_sysmon.toInt());
      eeprom_update_word(&E_AMP_MAX_NC, (uint16_t)max_amp_NC.toInt());
      eeprom_update_word(&E_AMP_MAX_SWITCH, (uint16_t)max_amp_switch.toInt());
   }
}



//---------- G E T _ P A R A M S _ G N S --------------------------------------
/*
   Requests information about the guest nodes from the node controller.
   If the node controller takes too long to send the info, we skip booting the 
   guest nodes.

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
         Heartbeat timeout (guest node 1)
         Heartbeat timeout (guest node 2)
         Heartbeat timeout (guest node 3)
         Bad temperature timeout (guest node 1)
         Bad temperature timeout (guest node 2)
         Bad temperature timeout (guest node 3)
         Bad current timeout (guest node 1)
         Bad current timeout (guest node 2)
         Bad current timeout (guest node 3)
         Minimum temperature (Celsius) (signed) (guest node 1)
         Maximum temperature (Celsius) (signed) (guest node 1)
         Minimum temperature (Celsius) (signed) (guest node 2)
         Maximum temperature (Celsius) (signed) (guest node 2)
         Minimum temperature (Celsius) (signed) (guest node 3)
         Maximum temperature (Celsius) (signed) (guest node 3)
         Maximum amp draw (mA) (guest node 1)
         Maximum amp draw (mA) (guest node 2)
         Maximum amp draw (mA) (guest node 3)

      */

      // Temporary strings for holding each parameter
      String present_GN1 = "";
      String present_GN2 = "";
      String present_GN3 = "";
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
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, (uint8_t)heartbeat_timeout_GN1.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, (uint8_t)heartbeat_timeout_GN2.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, (uint8_t)heartbeat_timeout_GN3.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN1, (uint8_t)bad_temp_timeout_GN1.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN2, (uint8_t)bad_temp_timeout_GN2.toInt());
      eeprom_update_byte(&E_BAD_TEMP_TIMEOUT_GN3, (uint8_t)bad_temp_timeout_GN3.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN1, (uint8_t)bad_current_timeout_GN1.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN2, (uint8_t)bad_current_timeout_GN2.toInt());
      eeprom_update_byte(&E_BAD_CURRENT_TIMEOUT_GN3, (uint8_t)bad_current_timeout_GN3.toInt());
      // EEPROM does not store data types.  Must cast to signed when reading.
      eeprom_update_word(&E_TEMP_MIN_GN1_SIGNED, (uint16_t)min_temp_GN1.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN1_SIGNED, (uint16_t)max_temp_GN1.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN2_SIGNED, (uint16_t)min_temp_GN2.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN2_SIGNED, (uint16_t)max_temp_GN2.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN3_SIGNED, (uint16_t)min_temp_GN3.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN3_SIGNED, (uint16_t)max_temp_GN3.toInt());
      eeprom_update_word(&E_AMP_MAX_GN1, (uint16_t)max_amp_GN1.toInt());
      eeprom_update_word(&E_AMP_MAX_GN2, (uint16_t)max_amp_GN2.toInt());
      eeprom_update_word(&E_AMP_MAX_GN3, (uint16_t)max_amp_GN3.toInt());

      return true;
   }
   // No parameters received?
   else
      return false;
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