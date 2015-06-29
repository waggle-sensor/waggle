// Adapted from Atmel Application Note AVR998 (c) 2006 Atmel

//---------- C O N S T A N T S ------------------------------------------------
const int SRAM_START_ADDR = 0x0060;
const int SRAM_START_PAGE2 = 0x0100;
const int SRAM_SIZE = 2560;
const int SRAM_END_ADDR = SRAM_START_ADDR + SRAM_SIZE - 1;

const int STACK_SAVE = 0x0250;
const int STACK_ADDR = 0x0099;

const byte EEPROM_RESET_REASON_ADDR = 0x00;
const byte EEPROM_POST_RESULT_ADDR = 0x01;

const byte FAIL_GPRF = 1;
const byte FAIL_STACK = 2;
const byte FAIL_SREG = 3;
const byte FAIL_SRAM = 4;
const byte FAIL_FLASH = 5;
const byte FAIL_WATCHDOG = 6;
const byte FAIL_INTERRUPT = 7;
const byte FAIL_ADC = 8;
const byte FAIL_TIMER0 = 9;

const boolean FATAL_GPRF = true;
const boolean FATAL_STACK = true;
const boolean FATAL_SREG = true;
const boolean FATAL_SRAM = true;
const boolean FATAL_FLASH = true;
const boolean FATAL_WATCHDOG = true;
const boolean FATAL_INTERRUPT = false;
const boolean FATAL_ADC = false;
const boolean FATAL_TIMER0 = false;

const byte RESET_POWER_ON = 0;
const byte RESET_EXTERNAL = 1;
const byte RESET_BROWN_OUT = 2;
const byte RESET_WATCHDOG = 3;
const byte RESET_JTAG = 4;
const byte RESET_USB = 5;

const byte ADC_TEST_THRESHOLD = 512;



//---------- G L O B A L S ----------------------------------------------------
boolean _SOS_BOOT_MODE = false;
// Flag to use while waiting for interrupt
boolean volatile interrupt_fired = false;



//---------- P O S T ----------------------------------------------------------
void POST() 
{
  // Find reason for reset
  byte reason = find_reset_reason();

  // Disable watchdog so it doesn't reset the chip before we're ready
  wdt_disable();

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

  // Debug
  delay(8000);

	// Watchdog test failed?
	// if(!watchdog_test(reason));
	// 	test_failure(FAIL_WATCHDOG, FATAL_WATCHDOG);

  // ADC test failed?
  if(!ADC_test())
    test_failure(FAIL_ADC, FATAL_ADC);

  // Timer0 (watchdog reset timer) test failed?
  if(!timer0_test())
    test_failure(FAIL_TIMER0, FATAL_TIMER0);
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



//---------- W A T C H D O G _ T E S T ----------------------------------------
/*
	 Checks the reason for reset.  If it was a watchdog reset, we move on.
	 If it wasn't, enable the watchdog and wait.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
	 setting compiler flags is not an option.  The "noinline" attribute is 
	 used to prevent the compiler from inlining this function.

   :rtype: boolean
*/
__attribute__((noinline)) boolean watchdog_test(byte reason)
{
	// Insurance against the compiler optimizing away this function through
	// means other than inlining.
	asm("");

	// Was reset not due to watchdog?
	if((reason & RESET_WATCHDOG) != RESET_WATCHDOG)
	{
		Serial.println("not watchdog reset");

		wdt_enable(WDTO_1S);
		Serial.println("enabled");
	}
	if((reason & RESET_WATCHDOG) == RESET_WATCHDOG)
    Serial.println("watchdog reset");

	return true;
}

// TEMP
int data = 0;
//---------- A D C _ T E S T --------------------------------------------------
/*
   Checks that the ADC is functioning correctly.
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "noinline" attribute is 
   used to prevent the compiler from inlining this function.

   :rtype: boolean
*/
__attribute__((noinline)) boolean ADC_test()
{
  // Insurance against the compiler optimizing away this function through
  // means other than inlining.
  asm("");

  // Set AREF to the ATmega's internal reference
  analogReference(INTERNAL);

  // Wait, then read ADC a few times to let things settle down
  delay(50);
  analogRead(INTERNAL);
  analogRead(INTERNAL);
  analogRead(INTERNAL);

  // Read ADC with INTERNAL as input
  int value = analogRead(INTERNAL);

  Serial.println(value);

  // Is the reported ADC value close enough?
  // Theoretically, the value should be 1023 (10-bit conversion)
  if(value > ADC_TEST_THRESHOLD)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;

  // TEMP
  data = 5;
}



//---------- T I M E R 0 _ T E S T --------------------------------------------
/*
   Checks all registers for stuck bits and lets the timer overflow, which
   tests the timer and the interrupt.
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "noinline" attribute is 
   used to prevent the compiler from inlining this function.

   :rtype: boolean
*/
__attribute__((noinline)) boolean timer0_test()
{
  // Insurance against the compiler optimizing away this function through
  // means other than inlining.
  asm("");

  /* These comments apply to all register tests in this function */
  // Load first test value
  TCCR0A = 0x55;
  // Is the register not storing the test value?
  // See datasheet for unused bits
  if(TCCR0A != 0x51)
    // Exit test with failure
    return false;
  // Load second test value
  TCCR0A = 0xAA;
  // Is the register not storing the test value?
  // See datasheet for unused bits
  if(TCCR0A != 0xA2)
    // Exit test with failure
    return false;
  // Reset the register
  TCCR0A = 0;

  TCCR0B = 0x55;
  if(TCCR0B != 0x45)
    return false;
  TCCR0B = 0xAA;
  if(TCCR0B != 0x8A)
    return false;
  TCCR0B = 0;

  TCNT0 = 0x55;
  if(TCNT0 != 0x55)
    return false;
  TCNT0 = 0xAA;
  if(TCNT0 != 0xAA)
    return false;
  TCNT0 = 0;

  OCR0A = 0x55;
  if(OCR0A != 0x55)
    return false;
  OCR0A = 0xAA;
  if(OCR0A != 0xAA)
    return false;
  OCR0A = 0;

  OCR0B = 0x55;
  if(OCR0B != 0x55)
    return false;
  OCR0B = 0xAA;
  if(OCR0B != 0xAA)
    return false;
  OCR0B = 0;

  TIMSK0 = 0x55;
  if(TIMSK0 != 0x05)
    return false;
  TIMSK0 = 0xAA;
  if(TIMSK0 != 0x02)
    return false;
  TIMSK0 = 0;

  TIFR0 = 0x55;
  if(TIFR0 != 0x05)
    return false;
  TIFR0 = 0xAA;
  if(TIFR0 != 0x02)
    return false;
  TIFR0 = 0;

  // By default, timer is set for normal, overflow, non-PWM mode.
  // Enable overflow interrupt
  TIMSK0 |= (1 << TOIE0);
  // Set timer for no clock prescaling (this starts the timer)
  TCCR0B |= (1 << CS00);

  // Wait for timer interrupt
  while(!interrupt_fired);
  // Reset flag
  interrupt_fired = false;

  // Exit test with success
  return true;
}

/*


CAN'T USE TIMER0.  ARDUINO USES THAT FOR delay() AND millis()


*/

//---------- T I M E R 0 _ O V E R F L O W _ I N T E R R U P T ----------------
ISR(TIMER0_OVF_vect)
{
  // Set flag to indicate that the interrupt fired
  interrupt_fired = true;
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