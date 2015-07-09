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

	// Check that SysMon is drawing an expected amount of power
	check_power_self();

	// Check that the SysMon's environment is suitable
	check_environ_self();

	// Is the node controller disabled?
	if(EEPROM.read(EEPROM_NC_DISABLED))
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

	// Request guest node info from node controller.  No info received?
	if(!get_gn_info())
		// Skip the rest of the boot sequence
		return false;

	// Is the ethernet switch disabled?
	if(EEPROM.read(EEPROM_ES_DISABLED))
		// Skip the rest of the boot sequence
		return false;

	// Check that the ethernet switch's environment is suitable
	check_environ_es();

	// Enable power to ethernet switch

	// Check that the ethernet switch is drawing an expected amount of power
	check_power_es();

	// Check that the ethernet switch is alive (sending a "heartbeat")
	check_heartbeat_es();

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

	// Enable Timer1 overflow interrupt
	TIMSK1 |= _BV(TOIE1);
	// Start Timer1 with prescaler of clk/256 (timeout of approx. 1 second)
	TCCR1B |= _BV(CS12);

	// Set LED pin to output so we can turn on the LED
  pinMode(PIN_LED, OUTPUT);

	// Join I2C bus as master
	Wire.begin();

	// Enable serial comms
  Serial.begin(UART_BAUD);
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



//---------- G E T _ G N _ I N F O --------------------------------------------
/*
   Requests information about the guest nodes from the node controller.
   Expected data for each guest nodes contains: present/not present, acceptable
   environmental conditions, and expected power draw.  If the node controller
   takes too long to send the info, we skip booting the guest nodes.

   :rtype: boolean
*/
boolean get_gn_info()
{
	return true;
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



//---------- C H E C K _ E N V I R O N _ E S ----------------------------------
/*
   Gets temperature info from the thermistor, then checks if the 
   environment is suitable for safe operation of the ethernet switch.  If it
   is not safe, then we monitor it until it is safe.

   :rtype: none
*/
void check_environ_es()
{

}



//---------- C H E C K _ P O W E R _ E S --------------------------------------
/*
   Reads the ethernet switch's current sensor.  If the ethernet switch is not
   drawing any power or is drawing too much power, we'll shut it down and
   inform the node controller (and wait for it to inform the cloud), then go
   to sleep.

   :rtype: none
*/
void check_power_es()
{

}



//---------- C H E C K _ H E A R T B E A T _ E S ------------------------------
/*
   Checks that the ethernet switch is alive and sending a heartbeat.  If it is
   not, then power cycle it and try again.  If a reboot is tried too many
   times, the ethernet switch is assumed to be dead, so we inform the node 
   controller (and wait for it to inform the cloud), then go to sleep.

   :rtype: none
*/
void check_heartbeat_es()
{

}