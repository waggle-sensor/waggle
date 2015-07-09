//---------- C O N S T A N T S ------------------------------------------------
const int SRAM_START_ADDR = 0x0060;
const int SRAM_START_PAGE2 = 0x0100;
const int SRAM_SIZE = 2560;
const int SRAM_END_ADDR = SRAM_START_ADDR + SRAM_SIZE - 1;

const byte FAIL_GPRF = 1;
const byte FAIL_STACK = 2;
const byte FAIL_SREG = 3;
const byte FAIL_SRAM = 4;
const byte FAIL_FLASH = 5;
const byte FAIL_WATCHDOG = 6;
const byte FAIL_ADC = 7;
const byte FAIL_TIMER1 = 8;
const byte FAIL_INTERRUPT = 9;

const boolean FATAL_GPRF = true;
const boolean FATAL_STACK = true;
const boolean FATAL_SREG = true;
const boolean FATAL_SRAM = true;
const boolean FATAL_FLASH = true;
const boolean FATAL_WATCHDOG = false;
const boolean FATAL_ADC = false;
const boolean FATAL_TIMER1 = false;
const boolean FATAL_INTERRUPT = false;

const byte RESET_POWER_ON = 0;
const byte RESET_EXTERNAL = 1;
const byte RESET_BROWN_OUT = 2;
const byte RESET_WATCHDOG = 3;
const byte RESET_JTAG = 4;
const byte RESET_USB = 5;

const int ADC_TEST_THRESHOLD = 512;


//---------- G L O B A L S ----------------------------------------------------
boolean _SOS_boot_mode = false;
boolean _watchdog_good = false;



//---------- P O S T ----------------------------------------------------------
/*
   Power on self test.  This subroutine calls the tests to verify correct
   operation of the MCU.  Nothing external to the MCU is tested here.

   If everything is working correctly, this function will return true.
   If a fatal failure occurs, the MCU will sleep, thus preventing the rest of
   the MCU's program from running. If a non-fatal failure occurs, the function
   will return false.  Failures will (attempt to) be recorded into EEPROM.

   Note: This POST is not perfect.  There is some redundancy and a few
   assumptions are made, so do not rely solely on this for mission-critical
   applications.

   Adapted from Atmel Application Note AVR998 (c) 2006 Atmel.

   :rtype: boolean
*/
boolean POST() 
{
  // Disable watchdog so it doesn't reset the chip before we're ready
  wdt_disable();

  // Disable interrupts so nothing unexpected happens
  noInterrupts();

  // Find reason for reset
  byte reason = find_reset_reason();

  // General Purpose Register File failed?
	if(!gprf_test())
		test_failure(FAIL_GPRF, FATAL_GPRF);

	// Stack pointer failed?
	if(!stack_pointer_test())
		test_failure(FAIL_STACK, FATAL_STACK);

	// Status register (SREG) test failed?
	if(!status_register_test())
		test_failure(FAIL_SREG, FATAL_SREG);

	// SRAM test failed?
	if(!sram_test())
		test_failure(FAIL_SRAM, FATAL_SRAM);

	// Flash test failed?
	//if(!flash_test())
		//test_failure(FAIL_FLASH, FATAL_FLASH);

	// Watchdog test failed?
	if(!watchdog_test(reason));
		test_failure(FAIL_WATCHDOG, FATAL_WATCHDOG);
  else
    // Mark watchdog as functional (used to test the timer)
    _watchdog_good = true;

  // ADC test failed?
  if(!ADC_test())
    test_failure(FAIL_ADC, FATAL_ADC);

  // Timer1 test failed?
  if(!timer1_test())
    test_failure(FAIL_TIMER1, FATAL_TIMER1);

  // Interrupt controller test failed?
  if(!interrupt_test())
    test_failure(FAIL_INTERRUPT, FATAL_INTERRUPT);

  
}



//---------- G P R F _ T E S T ------------------------------------------------
/*
	 Checks the General Purpose Register File (R31 - R0) for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
	 setting compiler flags is not an option.  The "optimize(0)" attribute is 
	 used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

	 :rtype: boolean
*/
__attribute__((optimize(0))) boolean gprf_test()
{
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

  // Is the result TRUE?
	if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- S T A C K _ P O I N T E R _ T E S T ------------------------------
/*
	 Checks the stack pointer for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

	 :rtype: boolean
*/
__attribute__((optimize(0))) boolean stack_pointer_test()
{
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

	// Is the result TRUE?
  if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- S T A T U S _ R E G I S T E R _ T E S T --------------------------
/*
   Checks the status register (SREG) for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean status_register_test() 
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



//---------- S R A M _ T E S T ------------------------------------------------
/*
   Checks the SRAM for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean sram_test()
{
  boolean result;
  
  // This is done in assembly because we're pretty close to metal here.
  // Each RAM address (0x0100 - 0x0AFF) has 0x55 and 0xAA written to and read from it, 
  // to verify that there aren't any stuck bits.
  asm volatile(
    "LD_INITS:                                 \n\t"
    "             ldi   R31, 0x01              \n\t"
    "             ldi   R30, 0x00              \n\t"
    "             ldi   R28, 0x55              \n\t"
    "             ldi   R29, 0xAA              \n\t"
    "CHECK_DONE:                               \n\t"
                  // Compare ZH to 0x0A
    "             cpi   R31, 0x0A              \n\t"
    "             brne  LOOP                   \n\t"
                  // Compare ZL to 0xFF
    "             cpi   R30, 0xFF              \n\t"
                  // If both match, test complete
    "             breq  Pass_RAM               \n\t"
    "LOOP:                                     \n\t"
                  // Temp store contents in R26
    "             ld    R26, Z                 \n\t"
                  // Store 0x55 at RAM location
    "             st    Z, R28                 \n\t"
                  // Read to confirm 0x55
    "             ld    R27, Z                 \n\t"
    "             cpi   R27, 0x55              \n\t" 
                  // If equal, continue to 0xAA Test
    "             brne  Fail_RAM               \n\t"
                  // Store 0xAA at RAM location
    "             st    Z, R29                 \n\t"
                  // Read to confirm 0xAA
    "             ld    R27, Z                 \n\t"
                  // Place old contents back in, increment addr
    "             st    Z+, R26                \n\t"
    "             cpi   R27, 0xAA              \n\t" 
    "             brne  Fail_RAM               \n\t"
                  // If equal, continue to next iteration
    "             jmp   CHECK_DONE             \n\t"
  );

  // Test failure
  asm volatile(
    "Fail_RAM:                                 \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_RAM:                                 \n\t"
  );
  result = true;

  // Is the result TRUE?
  if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- W A T C H D O G _ T E S T ----------------------------------------
/*
	 Checks the reason for reset.  If it was a watchdog reset, we move on.
	 If it wasn't, enable the watchdog and wait.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean watchdog_test(byte reason)
{
  Serial.println(reason);

  // Was reset not due to watchdog?
  if((reason & RESET_WATCHDOG) != RESET_WATCHDOG)
  {
    Serial.println("not watchdog reset");
    wdt_enable(WDTO_1S);
    Serial.println("enabled");
    delay(2000);
    Serial.print("watchdog did not reset");
    return false;
  }

  if((reason & RESET_WATCHDOG) == RESET_WATCHDOG)
    Serial.println("watchdog reset");
  return true;
}



//---------- A D C _ T E S T --------------------------------------------------
/*
   Checks that the ADC is functioning correctly.
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean ADC_test()
{
  // Set AREF to the ATmega's internal reference
  analogReference(INTERNAL);

  // Wait, then read ADC a few times to let things settle down.
  // ATmega32U4 datasheet recommends this.
  delay(50);
  analogRead(INTERNAL);
  analogRead(INTERNAL);
  analogRead(INTERNAL);

  // Read ADC with INTERNAL as input
  int value = analogRead(INTERNAL);

  // Is the reported ADC value close enough?
  // Theoretically, the value should be 1023 (10-bit conversion)
  if(value > ADC_TEST_THRESHOLD)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- T I M E R 1 _ T E S T --------------------------------------------
/*
   Checks all registers for stuck bits and lets the timer overflow, which
   tests the timer and the interrupt (thus, the interrupt controller, too).
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean timer1_test()
{
  /* These comments apply to all register tests in this function */
  // Load first test value
  TCCR1A = 0x55;
  // Is the register not storing the test value?
  // See datasheet for unused bits
  if((TCCR1A & 0x55) != 0x55)
    // Exit test with failure
    return false;
  // Load second test value
  TCCR1A = 0xAA;
  // Is the register not storing the test value?
  // See datasheet for unused bits
  if((TCCR1A & 0xAA) != 0xAA)
    // Exit test with failure
    return false;
  // Reset the register
  TCCR1A = 0;

  TCCR1B = 0x55;
  if((TCCR1B & 0x55) != 0x55)
    return false;
  TCCR1B = 0xAA;
  if((TCCR1B & 0xAA) != 0x8A)
    return false;
  TCCR1B = 0;

  TCNT1 = 0x5555;
  if((TCNT1 & 0x5555) != 0x5555)
    return false;
  TCNT1 = 0xAAAA;
  if((TCNT1 & 0xAAAA) != 0xAAAA)
    return false;
  TCNT1 = 0;

  OCR1A = 0x5555;
  if((OCR1A & 0x5555) != 0x5555)
    return false;
  OCR1A = 0xAAAA;
  if((OCR1A & 0xAAAA) != 0xAAAA)
    return false;
  OCR1A = 0;

  TIMSK1 = 0x55;
  if((TIMSK1 & 0x55) != 0x05)
    return false;
  TIMSK1 = 0xAA;
  if((TIMSK1 & 0xAA) != 0x2A)
    return false;
  TIMSK1 = 0;

  // Did we arrive here after a watchdog reset due to a bad timer?
  if(EEPROM.read(EEPROM_TIMER_TEST_INCOMPLETE) == 1)
    // Exit test with failure
    return false;

  // Did watchdog pass its test?
  // If it did not, we have no reliable way to test the timer without failure
  // resulting in an infinite loop.  An infinite loop prevents us from
  // getting to the partial boot sequence, so if the watchdog is bad, we'll
  // have to trust that the timer works, without this explicit test.
  if(_watchdog_good)
  {
    // Mark timer test as incomplete
    EEPROM.update(EEPROM_TIMER_TEST_INCOMPLETE, 1);

    // Enable watchdog
    wdt_enable(WDTO_60MS);

    // Start timer (with prescaler of clk/8)
    TCCR1B |= (1 << CS11);

    // Wait for counter to overflow
    while(! (TIFR1 & _BV(TOV1));

    // Disable watchdog
    wdt_disable();

    // Clear the clock prescaling (this turns off the timer)
    TCCR1B = 0;
    // Clear the timer's counter
    TCNT1 = 0;
    // Clear the overflow flag
    TIFR1 = _BV(TOV1);

    // Mark timer test as complete
    EEPROM.update(EEPROM_TIMER_TEST_INCOMPLETE, 0);
  }

  // Exit test with success
  return true;
}



//---------- I N T E R R U P T _ T E S T --------------------------------------
/*
   Checks that the interrupt controller executes interrupt service routines.
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean interrupt_test()
{

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
		mask <<= 1;
	}

  // Clear MCUSR
  MCUSR = 0;

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
	EEPROM.update(EEPROM_POST_RESULT, (1 << reason));

	// Allow time for EEPROM to finish writing
	delay(5);

	// Is POST failure fatal?
	if(fatal)
		// Go to sleep
		sleep();
	else
		// Set flag for SOS boot mode
    _SOS_boot_mode = true;
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

	// Chew on this until the chip falls asleep
	while(1);
}