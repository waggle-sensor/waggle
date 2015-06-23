// Adapted from Atmel Application Note AVR998 (c) 2006 Atmel

//---------- C O N S T A N T S ------------------------------------------------
const int SRAM_START_ADDR = 0x0060;
const int SRAM_START_PAGE2 = 0x0100;
const int SRAM_SIZE = 2560;
const int SRAM_END_ADDR = SRAM_START_ADDR + SRAM_SIZE - 1;

const int STACK_SAVE = 0x0250;
const int STACK_ADDR = 0x0099;

const int WDT_TIMER = 0x18;

const byte EEPROM_RESET_REASON_ADDR = 0x00;
const byte EEPROM_POST_RESULT_ADDR = 0x01;

const byte FAIL_GPRF = 1;
const byte FAIL_STACK = 2;
const byte FAIL_SREG = 3;

const byte RESET_POWER_ON = 0;
const byte RESET_EXTERNAL = 1;
const byte RESET_BROWN_OUT = 2;
const byte RESET_WATCHDOG = 3;
const byte RESET_JTAG = 4;
const byte RESET_USB = 5;
const byte RESET_WAITING = 0x80;



//---------- G L O B A L S ----------------------------------------------------
boolean _SOS_BOOT_MODE = false;



//---------- P O S T ----------------------------------------------------------
byte POST() 
{
	// General Purpose Register File failed?
	if(!gprf_test())
		test_failure(FAIL_GPRF, true);

	// stack_pointer_test

	// Status register (SREG) test failed?
	if(!status_register_test())
		test_failure(FAIL_SREG, true);
}



//---------- G P R F _ T E S T ------------------------------------------------
/*
	 Checks the General Purpose Register File (R31 - R0) for stuck bits.
	 If the test fails, 
*/
void gprf_test()
{
	// This is done in assembly because we're pretty close to metal here.
	// Each register (R31 - R0) has 0x55 and 0xAA written to and read from it, 
	// to verify that there aren't any stuck bits.
	asm volatile(
		// ZH register
		"R31_0x55_TST:                             \n"
    "							ldi  R31, 0x55               \n"
    "             cpi  R31, 0x55               \n"
    "             breq  R31_0xAA_TST           \n"
    "             jmp  Fail_GPRF               \n"
    "R31_0xAA_TST:  													 \n"
    "							ldi  R31, 0xAA               \n"
    "             cpi  R31, 0xAA               \n"
    "             breq  R30_0x55_TST           \n"
    "             jmp  Fail_GPRF               \n"
    // ZL register
    "R30_0x55_TST:                             \n"
    "							ldi  R30, 0x55               \n"
    "             cpi  R30, 0x55               \n"
    "             breq  R30_0xAA_TST           \n"
    "             jmp  Fail_GPRF               \n"
    "R30_0xAA_TST:  													 \n"
    "							ldi  R30, 0xAA               \n"
    "             cpi  R30, 0xAA               \n"
    "             breq  R29_0x55_TST           \n"
    "             jmp  Fail_GPRF               \n"
    
    // YH register
    "R29_0x55_TST:                             \n"
    "							mov R31, R29       ; save R29\n"
    "							ldi  R29, 0x55               \n"
    "             cpi  R29, 0x55               \n"
    "             breq  R29_0xAA_TST           \n"
    "             jmp  Fail_GPRF               \n"
    "R29_0xAA_TST:  													 \n"
    "							ldi  R29, 0xAA               \n"
    "             cpi  R29, 0xAA               \n"
    "             breq  R28_0x55_TST           \n"
    "             jmp  Fail_GPRF               \n"
    "R29_END_TST: 														 \n"
    "							mov R29, R31    ; restore R29\n"
    // YL register
    "R28_0x55_TST:                             \n"
    "							mov R31, R28       ; save R28\n"
    "							ldi  R28, 0x55               \n"
    "             cpi  R28, 0x55               \n"
    "             breq  R28_0xAA_TST           \n"
    "             jmp  Fail_GPRF               \n"
    "R28_0xAA_TST:  													 \n"
    "							ldi  R28, 0xAA               \n"
    "             cpi  R28, 0xAA               \n"
    "             breq  R27_0x55_TST           \n"
    "             jmp  Fail_GPRF               \n"
    "R28_END_TST: 														 \n"
    "							mov R28, R31    ; restore R28\n"
    
    // XH register
    "R27_0x55_TST:                             \n"
    "							ldi  R27, 0x55               \n"
    "             cpi  R27, 0x55               \n"
    "             breq  R27_0xAA_TST           \n"
    "             jmp  Fail_GPRF               \n"
    "R27_0xAA_TST:  													 \n"
    "							ldi  R27, 0xAA               \n"
    "             cpi  R27, 0xAA               \n"
    "             breq  R26_0x55_TST           \n"
    "             jmp  Fail_GPRF               \n"
    // XL register
    "R26_0x55_TST:                             \n"
    "							ldi  R26, 0x55               \n"
    "             cpi  R26, 0x55               \n"
    "             breq  R26_0xAA_TST           \n"
    "             jmp  Fail_GPRF               \n"
    "R26_0xAA_TST:  													 \n"
    "							ldi  R26, 0xAA               \n"
    "             cpi  R26, 0xAA               \n"
    "             breq  R26_END_TST            \n"
    "							jmp  Fail_GPRF               \n"
    "R26_END_TST:															 \n"

    // R25 - R0
    "RX_TST:     															 \n"   
    "							ldi  R30, 0x00               \n"
    "             ldi  R31, 0x00               \n"
    "RX_0x55_TST:   													 \n"
    "							ldi  R25, 0x55               \n"
    "             st  Z, R25                   \n"
    "             ldi  R25, 0x00               \n"
    "             ld  R25, Z                   \n"
    "             cpi  R25, 0x55               \n"
    "             breq  RX_0xAA_TST            \n"
    "             jmp  Fail_GPRF               \n"
    "RX_0xAA_TST:   													 \n"
    "							ldi  R25, 0xAA               \n"
    "             ST  Z, R25                   \n"
    "             ldi  R25, 0x00               \n"
    "             ld  R25, Z+                  \n"
    "             cpi  R25, 0xAA               \n"
    "             breq  RX_TST_2               \n"
    "             jmp  Fail_GPRF               \n"
    "RX_TST_2:      													 \n"
    "							cpi  r30, 25 ; test until R25\n"
    "             brne  RX_0x55_TST            \n"
    "							rjmp  Pass_GPRF 						 \n"

    // End
    "Fail_GPRF:																 \n"
    "							jmp  Fail_GPRF 							 \n"
    "Pass_GPRF:                                \n"
	);
	Serial.print("here");
	delay(100);
}



//---------- S T A C K _ P O I N T E R _ T E S T ------------------------------
/*
	 Checks the stack pointer for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 :rtype: boolean
*/
boolean stack_pointer_test()
{

}



//---------- S T A T U S _ R E G I S T E R _ T E S T --------------------------
/*
   Checks the status register (SREG) for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

   :rtype: boolean
*/
boolean status_register_test() 
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



//---------- F I N D _ R E S E T _ R E A S O N --------------------------------
/*
   Reads the MCU status register (MCUSR) for the reset flag.

   :rtype: byte
*/
byte find_reset_reason()
{
	byte i;
	byte mask = 0x01;

	// Check bits 0-5 in MCUSR
	for(i = 0; i < 6; i++)
	{
		// Is the current bit set?
		if(MCUSR & mask)
			// Found the reset flag, so exit the loop
			break;

		// Shift the mask left by 1
		mask = mask << 1;
	}

	// Return the reset reason
	return i;	
}



//---------- T E S T _ F A I L U R E ------------------------------------------
/*
	 Saves the reason for POST failure into EEPROM and aborts/modifies boot-up.

	 :param byte reason: reason for POST failure
	 :param boolean fatal: POST failure is/not fatal
*/
void test_failure(byte reason, boolean fatal)
{
	// Save POST failure to EEPROM
	EEPROM.update(EEPROM_POST_RESULT_ADDR, reason);

	// Is POST failure fatal?
	if(fatal)
	{
		// Go to sleep
		// Infinite loop is insurance, in case the chip wakes up
		while(1)
			sleep();
	}
	else
		// Set "SOS boot mode" flag
		_SOS_BOOT_MODE = true;
}



//---------- S L E E P --------------------------------------------------------
/*
	 Puts Atmel chip to sleep (power-down mode).
*/
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