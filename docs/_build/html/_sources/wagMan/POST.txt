POST.ino
========

**POST**

|    Power on self test.  This subroutine calls the tests to verify correct
|    operation of the MCU.  Nothing external to the MCU is tested here.
| 
|    If everything is working correctly, this function will return true.
|    If a fatal failure occurs, the MCU will sleep, thus preventing the rest of
|    the MCU's program from running. If a non-fatal failure occurs, the function
|    will return false.  Failures will (attempt to) be recorded into EEPROM.
| 
|    Note: This POST is not perfect.  There is some redundancy and a few
|    assumptions are made, so do not rely solely on this for mission-critical
|    applications.
| 
|    Adapted from Atmel Application Note AVR998 (c) 2006 Atmel.
|

   :returns:
      boolean

---------

**gprf_test**

| 	 Checks the General Purpose Register File (R31 - R0) for stuck bits.
| 	 Return of TRUE means it passed the test.
| 	 Return of FALSE means it failed the test.
| 
| 	 This code is designed to work in the default Arduino environment, so 
| 	 setting compiler flags is not an option.  The "optimize(0)" attribute is 
| 	 used to prevent the compiler from optimizing this function.  All of the
|    tests in the POST routine disable optimization, to be safe, because much
|    of what is happening has no effect outside the function.
|

   :returns:
      boolean

---------

**stack_pointer_test**

| 	 Checks the stack pointer for stuck bits.
| 	 Return of TRUE means it passed the test.
| 	 Return of FALSE means it failed the test.
| 
| 	 This code is designed to work in the default Arduino environment, so 
|    setting compiler flags is not an option.  The "optimize(0)" attribute is 
|    used to prevent the compiler from optimizing this function.  All of the
|    tests in the POST routine disable optimization, to be safe, because much
|    of what is happening has no effect outside the function.
|

   :returns:
      boolean

---------

**status_register_test**

|    Checks the status register (SREG) for stuck bits.
|    Return of TRUE means it passed the test.
| 	 Return of FALSE means it failed the test.
| 
| 	 This code is designed to work in the default Arduino environment, so 
|    setting compiler flags is not an option.  The "optimize(0)" attribute is 
|    used to prevent the compiler from optimizing this function.  All of the
|    tests in the POST routine disable optimization, to be safe, because much
|    of what is happening has no effect outside the function.
|

   :returns:
      boolean

---------

**sram_test**

|    Checks the SRAM for stuck bits.
|    Return of TRUE means it passed the test.
| 	 Return of FALSE means it failed the test.
| 
| 	 This code is designed to work in the default Arduino environment, so 
|    setting compiler flags is not an option.  The "optimize(0)" attribute is 
|    used to prevent the compiler from optimizing this function.  All of the
|    tests in the POST routine disable optimization, to be safe, because much
|    of what is happening has no effect outside the function.
|

   :returns:
      boolean

---------

**watchdog_test**

| 	 Checks the reason for reset.  If it was a watchdog reset, we move on.
| 	 If it wasn't, enable the watchdog and wait.
| 	 Return of TRUE means it passed the test.
| 	 Return of FALSE means it failed the test.
| 
| 	 This code is designed to work in the default Arduino environment, so 
|    setting compiler flags is not an option.  The "optimize(0)" attribute is 
|    used to prevent the compiler from optimizing this function.  All of the
|    tests in the POST routine disable optimization, to be safe, because much
|    of what is happening has no effect outside the function.
|

   :returns:
      boolean

---------

**ADC_test**

|    Checks that the ADC is functioning correctly.
|    Return of TRUE means it passed the test.
|    Return of FALSE means it failed the test.
| 
|    This code is designed to work in the default Arduino environment, so 
|    setting compiler flags is not an option.  The "optimize(0)" attribute is 
|    used to prevent the compiler from optimizing this function.  All of the
|    tests in the POST routine disable optimization, to be safe, because much
|    of what is happening has no effect outside the function.
|

   :returns:
      boolean

---------

**timer1_test**

|    Checks all registers for stuck bits and lets the timer overflow, which
|    tests the timer and the interrupt (thus, the interrupt controller, too).
|    Return of TRUE means it passed the test.
|    Return of FALSE means it failed the test.
| 
|    This code is designed to work in the default Arduino environment, so 
|    setting compiler flags is not an option.  The "optimize(0)" attribute is 
|    used to prevent the compiler from optimizing this function.  All of the
|    tests in the POST routine disable optimization, to be safe, because much
|    of what is happening has no effect outside the function.
|

   :returns:
      boolean

---------

**interrupt_test**

|    Checks that the interrupt controller executes interrupt service routines.
|    Return of TRUE means it passed the test.
|    Return of FALSE means it failed the test.
| 
|    This code is designed to work in the default Arduino environment, so 
|    setting compiler flags is not an option.  The "optimize(0)" attribute is 
|    used to prevent the compiler from optimizing this function.  All of the
|    tests in the POST routine disable optimization, to be safe, because much
|    of what is happening has no effect outside the function.
|

   :returns:
      boolean

---------

**find_reset_reason**

|    Reads the MCU status register (MCUSR) for the reset flag.
|

   :returns:
      byte

---------

**test_failure**

| 	 Saves the reason for POST failure into EEPROM and aborts/modifies boot-up.
|

   :Parameters:
      reason (byte): reason for POST failure
      fatal (boolean): POST failure is/not fatal


---------

**sleep**

| 	 Puts Atmel chip to sleep (power-down mode)

