// Adapted from Atmel Application Note AVR998 (c) 2006 Atmel

//---------- C O N S T A N T S ------------------------------------------------
const int SRAM_START_ADDR = 0x0060;
const int SRAM_START_PAGE2 = 0x0100;
const int SRAM_SIZE = 2560;
const int SRAM_END_ADDR = SRAM_START_ADDR + SRAM_SIZE - 1;

const int STACK_SAVE = 0x0250;
const int STACK_ADDR = 0x0099;

const byte WDT_TIMER = 0x18;

const byte EEPROM_RESET_REASON_ADDR = 0x00;
const byte EEPROM_POST_RESULT_ADDR = 0x01;

const byte FAIL_GPRF = 1;
const byte FAIL_STACK = 2;
const byte FAIL_SREG = 3;
const byte FAIL_SRAM = 4;

const byte RESET_POWER_ON = 0;
const byte RESET_EXTERNAL = 1;
const byte RESET_BROWN_OUT = 2;
const byte RESET_WATCHDOG = 3;
const byte RESET_JTAG = 4;
const byte RESET_USB = 5;
const byte RESET_WAITING = 0x80;



//---------- G L O B A L S ----------------------------------------------------
boolean _SOS_BOOT_MODE = false;

/* See http://www.nongnu.org/avr-libc/user-manual/mem_sections.html and 
http://www.atmel.com/webdoc/AVRLibcReferenceManual/
group__demo__project_1demo_project_map.html for more. */
// Symbol from the linker that contains the last word of data (vars and such).
// The .data section follows the .text section, so this is the end of the
// flash memory that we would want to verify.
extern int __data_load_end;



//---------- P O S T ----------------------------------------------------------
void POST() 
{
	String ch = "success";

	Serial.println((unsigned int)&__data_load_end, HEX);

	// General Purpose Register File failed?
	if(!gprf_test())
		test_failure(FAIL_GPRF, true);

	// Stack pointer failed?
	if(!stack_pointer_test())
		test_failure(FAIL_STACK, true);

	// Status register (SREG) test failed?
	if(!status_register_test())
		test_failure(FAIL_SREG, true);

	// SRAM test failed?
	if(!sram_test())
		test_failure(FAIL_SRAM, true);

	Serial.println(ch);
}



//---------- G P R F _ T E S T ------------------------------------------------
/*
	 Checks the General Purpose Register File (R31 - R0) for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
	 setting compiler flags is not an option.  The "noinline" attribute is 
	 used to prevent the compiler from inlining this function.

	 :rtype: boolean
*/
__attribute__((noinline)) boolean gprf_test()
{
	// Insurance against the compiler optimizing away this function through
	// means other than inlining.
	asm("");

	boolean result;

	// This is done in assembly because we're pretty close to metal here.
	// Each register (R31 - R0) has 0x55 and 0xAA written to and read from it, 
	// to verify that there aren't any stuck bits.
	asm volatile(
		// ZH register
		"R31_0x55_TST:                             \n\t"
    "							ldi   R31, 0x55              \n\t"
    "             cpi   R31, 0x55              \n\t"
    "             breq  R31_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R31_0xAA_TST:  													 \n\t"
    "							ldi   R31, 0xAA              \n\t"
    "             cpi   R31, 0xAA              \n\t"
    "             breq  R30_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    // ZL register
    "R30_0x55_TST:                             \n\t"
    "							ldi   R30, 0x55              \n\t"
    "             cpi   R30, 0x55              \n\t"
    "             breq  R30_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R30_0xAA_TST:  													 \n\t"
    "							ldi   R30, 0xAA              \n\t"
    "             cpi   R30, 0xAA              \n\t"
    "             breq  R29_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    
    // YH register
    "R29_0x55_TST:                             \n\t"
    "							mov   R31, R29     ; save R29\n\t"
    "							ldi   R29, 0x55              \n\t"
    "             cpi   R29, 0x55              \n\t"
    "             breq  R29_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R29_0xAA_TST:  													 \n\t"
    "							ldi   R29, 0xAA              \n\t"
    "             cpi   R29, 0xAA              \n\t"
    "             breq  R29_END_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R29_END_TST: 														 \n\t"
    "							mov   R29, R31  ; restore R29\n\t"
    // YL register
    "R28_0x55_TST:                             \n\t"
    "							mov   R31, R28     ; save R28\n\t"
    "							ldi   R28, 0x55              \n\t"
    "             cpi   R28, 0x55              \n\t"
    "             breq  R28_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R28_0xAA_TST:  													 \n\t"
    "							ldi   R28, 0xAA              \n\t"
    "             cpi   R28, 0xAA              \n\t"
    "             breq  R28_END_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R28_END_TST: 														 \n\t"
    "							mov   R28, R31  ; restore R28\n\t"
    
    // XH register
    "R27_0x55_TST:                             \n\t"
    "							ldi   R27, 0x55              \n\t"
    "             cpi   R27, 0x55              \n\t"
    "             breq  R27_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R27_0xAA_TST:  													 \n\t"
    "							ldi   R27, 0xAA              \n\t"
    "             cpi   R27, 0xAA              \n\t"
    "             breq  R26_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    // XL register
    "R26_0x55_TST:                             \n\t"
    "							ldi   R26, 0x55              \n\t"
    "             cpi   R26, 0x55              \n\t"
    "             breq  R26_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R26_0xAA_TST:  													 \n\t"
    "							ldi   R26, 0xAA              \n\t"
    "             cpi   R26, 0xAA              \n\t"
    "             breq  RX_TST                 \n\t"
    "							jmp   Fail_GPRF              \n\t"

    // R25 - R0
    "RX_TST:     															 \n\t"   
    "							ldi   R30, 0x00    ; clear ZL\n\t"
    "             ldi   R31, 0x00    ; clear ZH\n\t"
    "RX_0x55_TST:   													 \n\t"
    "							ldi   R25, 0x55              \n\t"
    "             st    Z, R25                 \n\t"
    "             ldi   R25, 0x00              \n\t"
    "             ld    R25, Z                 \n\t"
    "             cpi   R25, 0x55              \n\t"
    "             breq  RX_0xAA_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "RX_0xAA_TST:   													 \n\t"
    "							ldi   R25, 0xAA              \n\t"
    "             ST    Z, R25                 \n\t"
    "             ldi   R25, 0x00              \n\t"
    "             ld    R25, Z+                \n\t"
    "             cpi   R25, 0xAA              \n\t"
    "             breq  RX_TST_2               \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "RX_TST_2:      													 \n\t"
    "							cpi   r30, 25; test until R25\n\t"
    "             brne  RX_0x55_TST            \n\t"
    "							clr   r1 ; R1 must be cleared\n\t"
    "							jmp   Pass_GPRF 						 \n\t"
  );

	// Test failure
  asm volatile(
    "Fail_GPRF:																 \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_GPRF:                                \n\t"
	);
	result = true;

	return result;
}



//---------- S T A C K _ P O I N T E R _ T E S T ------------------------------
/*
	 Checks the stack pointer for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
	 setting compiler flags is not an option.  The "noinline" attribute is 
	 used to prevent the compiler from inlining this function.

	 :rtype: boolean
*/
__attribute__((noinline)) boolean stack_pointer_test()
{
	// Insurance against the compiler optimizing away this function through
	// means other than inlining.
	asm("");

	boolean result;

	// This is done in assembly because we're pretty close to metal here.
	// Each register (SPL & SPH) has 0x55 and 0xAA written to and read from it,
	// to verify that there aren't any stuck bits.
	asm volatile(
		"SP_TST:																	 \n\t"
			// Save stack pointer   
			"						in    R23, 0x3E              \n\t"
      "           in    R22, 0x3D              \n\t"

      // SPL register
      "SPL_0x55_TST:  												 \n\t"
      "						ldi   R24, 0x55              \n\t"
      "           out   0x3D, R24              \n\t"
      "           in    R24, 0x3D              \n\t"
      "           cpi   R24, 0x55              \n\t"
      "           breq  SPL_0xAA_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      "SPL_0xAA_TST:  												 \n\t"
      "						ldi   R24, 0xAA              \n\t"
      "           out   0x3D, R24              \n\t"
      "           in    R24, 0x3D              \n\t"
      "           cpi   R24, 0xAA              \n\t"
      "           breq  SPH_0x55_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      // SPH register
      "SPH_0x55_TST:  												 \n\t"
      "						ldi   R25, 0x07			         \n\t"
      "           andi  R25, 0x55              \n\t"
      "           out   0x3E, R25              \n\t"
      "           in    R24, 0x3E              \n\t"
      "           cp    R24, R25               \n\t"
      "           breq  SPH_0xAA_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      "SPH_0xAA_TST:  												 \n\t"
      "						ldi   R25, 0x07              \n\t"
      "           andi  R25, 0xAA              \n\t"
      "           out   0x3E, R25              \n\t"
      "           in    R24, 0x3E              \n\t"
      "           cp    R24, R25               \n\t"
      "           breq  RESTORE_SP             \n\t"
      "           jmp   Fail_SP                \n\t"

      // Restore stack pointer
      "RESTORE_SP:    												 \n\t"
      "						out   0x3E, R23              \n\t"
      "           out   0x3D, R22              \n\t"
      "           jmp   Pass_SP                \n\t"
  );

	// Test failure
  asm volatile(
    "Fail_SP:																   \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_SP:																   \n\t"
	);
	result = true;

	return result;
}



//---------- S T A T U S _ R E G I S T E R _ T E S T --------------------------
/*
   Checks the status register (SREG) for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
	 setting compiler flags is not an option.  The "noinline" attribute is 
	 used to prevent the compiler from inlining this function.

   :rtype: boolean
*/
__attribute__((noinline)) boolean status_register_test() 
{
	// Insurance against the compiler optimizing away this function through
	// means other than inlining.
	asm("");

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



//---------- S R A M _ T E S T ------------------------------------------------
/*
   Checks the SRAM for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
	 setting compiler flags is not an option.  The "noinline" attribute is 
	 used to prevent the compiler from inlining this function.

   :rtype: boolean
*/
__attribute__((noinline)) boolean sram_test()
{   
  // Insurance against the compiler optimizing away this function through
	// means other than inlining.
	asm("");

  // Tell the compiler to put these into registers, since putting them
  // into memory means they're trying to verify themselves.

  // 16 bits
  register byte *p_val asm("Z");
  register byte i asm("GPIOR1");
  register byte save asm("GPIOR2");
 
  // Each location has 0x55 and 0xAA written to and read from it,
  // to verify that there aren't any stuck bits.
  for(p_val = (byte *) SRAM_START_ADDR;
  		p_val < ((byte *) (SRAM_END_ADDR + 1));
  		p_val++)
    {
    	// Save the value being stored at the current memory address
      save = *p_val;

      // Write 0x55
      *p_val = 0x55;
      // Read the stored value
      i = *p_val;
      // Is stored value not 0x55?
      if(i != 0x55)
      	// Exit test with failure
      	return false;

      // Write 0xAA
      *p_val = 0xAA;
      // Read the stored value
      i = *p_val;
      // Is stored value not 0xAA?
      if(i != 0xAA)
      	// Exit test with failure
      	return false;

      // Restore the original value to the current memory address
      *p_val = save;
    }
  
  // Exit test with success
  return true;
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

	// Allow time for EEPROM to finish writing
	delay(10);

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