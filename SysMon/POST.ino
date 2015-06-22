// Adapted from Atmel Application Note AVR998 (c) 2006 Atmel

//---------- C O N S T A N T S ------------------------------------------------
const int SRAM_START_ADDR = 0x0060;
const int SRAM_START_PAGE2 = 0x0100;
const int SRAM_SIZE = 2560;
const int SRAM_END_ADDR = SRAM_START_ADDR + SRAM_SIZE - 1;

const int STACK_SAVE = 0x0250;
const int STACK_ADDR = 0x0099;

const int WDT_TIMER = 0x18;

const byte EEPROM_RESET_REASON_ADDR = 0;
const byte EEPROM_POST_RESULT_ADDR = 1;

const byte CPU_SR_FAIL = 0x01;



//---------- P O S T ----------------------------------------------------------
byte POST() 
{
	// CPU status register test failed?
	if(!cpu_status_register_test())
	{
		// Save POST failure to EEPROM
		EEPROM.update(EEPROM_POST_RESULT_ADDR, CPU_SR_FAIL);

		// Failure is fatal, so go to sleep
		// Infinite loop is insurance, in case the chip wakes up
		while(1)
			sleep();
	}
}



//---------- F I N D _ R E S E T _ R E A S O N --------------------------------
byte find_reset_reason() 
{
	
}



//---------- C P U _ S T A T U S _ R E G I S T E R _ T E S T ------------------
boolean cpu_status_register_test() 
{
	byte read_sreg, save_sreg;

	// Save current state of SREG
	save_sreg = SREG;

	// Write value to SREG
	SREG = 0x55;

	// Read value in SREG
	read_sreg = SREG;

	// Restore original state of SREG
	SREG = save_sreg;

	// Is the value read from SREG not the expected value?
	if(read_sreg != 0x55)
		// Exit test with failure
		return false;
	else
	{
		// Save current state of SREG
		save_sreg = SREG;

		// Write value to SREG
		SREG = 0xAA;

		// Read value in SREG
		read_sreg = SREG;

		// Restore original state of SREG
		SREG = save_sreg;

		// Is the value read from SREG the expected value?
		if(read_sreg == 0xAA)
			// Exit test with success
			return true;
		else
			// Exit test with failure
			return false;
	}
}



//---------- S L E E P --------------------------------------------------------
void sleep()
{
	// Disable interrupts so nothing weird happens
	noInterrupts();

	// Set power-down mode to draw the least amount of power possible
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);

	// Enable sleep
	sleep_enable();

	// Go to sleep
	sleep_mode();

	// Give the SLEEP instruction time to execute
	delay(10);
}

TO DO:
	flash and eeprom need to be checksummed