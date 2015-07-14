//---------- C O N S T A N T S ------------------------------------------------
const byte NO_WATCHDOG = 1;
const byte NO_TIMER = 2;
const byte NO_ADC = 3;
const byte NO_INTERRUPT = 4;



//---------- G L O B A L S ----------------------------------------------------
byte SOS_mode;

// These are set (updated) by the node controller:
byte THRESHOLD_NUM_TRIES = 5;



//---------- B O O T _ S O S --------------------------------------------------
/*
   If a non-critical internal component failed the POST, this subroutine 
   attempts to boot enough to let the node controller inform the cloud there
   is a problem.

   :rtype: none
*/
void boot_SOS()
{
	// Initialize/start internal components
	init_SOS();

	// Check that SysMon is drawing an expected amount of power
	check_power_self();

	// Check that the SysMon's environment is suitable.
	// If the check fails, it could be the environment or the I2C
	check_environ_self();

	// Get datum about number of times SOS boot mode has been tried
	byte num_tries = EEPROM.read(EEPROM_NUM_SOS_BOOT_TRIES);

	// Has SOS boot been tried too many times?
	if(num_tries >= THRESHOLD_NUM_TRIES)
		// Something isn't working, so go to sleep
		sleep();

	// Record that SOS boot mode was attempted
	EEPROM.update(EEPROM_NUM_SOS_BOOT_TRIES, ++num_tries);

	// ADC ok?
	if(SOS_mode != NO_ADC)
		// Check that the node controller's environment is suitable
		check_environ_nc();
	// ADC not ok?
	else if(SOS_mode == NO_ADC)
		// This is here as notice that proceeding without ADC introduces some
		// risk to the node controller, since its environ. can't be measured.
		asm("nop");

	// Is the node controller disabled?
	if(EEPROM.read(EEPROM_NC_DISABLED))
		// Nothing for us to do, so go to sleep
		sleep();

	// Enable power to node controller

	// Check that the node controller is drawing an expected amount of power
	check_power_nc();

	// Check that the node controller is alive (sending a "heartbeat")
	check_heartbeat_nc();

	// Report the POST failure to the node controller
	report_failure_POST();
}



//---------- I N I T _ S O S --------------------------------------------------
/*
   Initializes/starts all necessary ports, peripherals, interrupts, etc.

   :rtype: none
*/
void init_SOS()
{
  // What is the cause of the POST failure?
	switch (EEPROM.read(EEPROM_POST_RESULT)) {
	    case FAIL_WATCHDOG:
	      SOS_mode = NO_WATCHDOG;
	      break;
	    case FAIL_TIMER1:
	      SOS_mode = NO_TIMER;
	      break;
	    case FAIL_ADC:
	    	SOS_mode = NO_ADC;
	    	break;
	    case FAIL_INTERRUPT:
	    	SOS_mode = NO_INTERRUPT;
	    	break;
	    // This shouldn't happen, but just in case...
	    default:
	      sleep();
	}

	// Watchdog, timer, and interrupts ok?
	if((SOS_mode != NO_WATCHDOG) && (SOS_mode != NO_TIMER) && (SOS_mode != NO_INTERRUPT))
		// Enable watchdog with 2 second timeout
		wdt_enable(WDTO_2S);
	// Watchdog, timer, or interrupts not ok?
	else
		// This is here as notice that proceeding without the watchdog introduces
		// the risk of SysMon hanging forever.
		asm("nop");

	// Timer ok?
	if(SOS_mode != NO_TIMER)
	{
		// Interrupts ok?
		if(SOS_mode != NO_INTERRUPT)
			// Enable Timer1 overflow interrupt
			TIMSK1 |= _BV(TOIE1);

		// Start Timer1 with prescaler of clk/256 (timeout of approx. 1 second)
		TCCR1B |= _BV(CS12);
	}

	// Set LED pin to output so we can turn on the LED
  pinMode(LED, OUTPUT);

	// Join I2C bus as master.
	// We're hoping I2C works, because we don't currently have a way to test it
	Wire.begin();

	// Enable serial comms.
	// We're hoping UART works, because we don't currently have a way to test it
  Serial.begin(UART_BAUD);
}



//---------- R E P O R T _ F A I L U R E _ P O S T ----------------------------
/*
   Sends info about the POST failure to the node controller, waits for
   the node controller to send failure info to the cloud (or until timeout),
   then goes to sleep

   :rtype: none
*/
void report_failure_POST()
{

}