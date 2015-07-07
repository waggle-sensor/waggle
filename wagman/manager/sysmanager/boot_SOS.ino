//---------- C O N S T A N T S ------------------------------------------------
const byte EEPROM_NUM_SOS_BOOT_TRIES_ADDR = 0x02;

const byte THRESHOLD_NUM_TRIES = 5;
const byte NO_WATCHDOG = 1;
const byte NO_TIMER = 2;
const byte NO_ADC = 3;



//---------- G L O B A L S ----------------------------------------------------
byte SOS_mode;



//---------- B O O T _ S O S --------------------------------------------------
/*
   

   :rtype: none
*/
void boot_SOS()
{
	// Get datum about how many times this boot mode has been tried
	byte num_tries = EEPROM.read(EEPROM_NUM_SOS_BOOT_TRIES_ADDR);

	// Has SOS boot been tried too many times?
	if(num_tries >= THRESHOLD_NUM_TRIES)
		// Something isn't working, so go to sleep
		sleep();

	// Record that SOS boot mode was attempted
	EEPROM.update(EEPROM_NUM_SOS_BOOT_TRIES_ADDR, ++num_tries);

	// Get datum about what failed the POST
	byte reason = EEPROM.read(EEPROM_POST_RESULT_ADDR);

	// What is the cause of the POST failure?
	switch (reason) {
	    case FAIL_WATCHDOG:
	      SOS_mode = NO_WATCHDOG;
	      break;
	    case FAIL_TIMER3:
	      SOS_mode = NO_TIMER;
	      break;
	    case FAIL_ADC:
	    	SOS_mode = NO_ADC;
	    	break;
	    // This shouldn't happen, but just in case...
	    default:
	      sleep();
	}


}