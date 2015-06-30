#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <EEPROM.h>
boolean sram_test()
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
    "LD_Z:                                     \n\t"
    "             ldi    R31, 0x01             \n\t"
    "             ldi    R30, 0x00             \n\t"
    "CHECK_DONE:                               \n\t"
    "             cpi   R31, 0x0A              \n\t"
    "             brne  LOOP                   \n\t"
    "             cpi   R30, 0xFF              \n\t"
    "             breq  DONE                   \n\t"
    "LOOP:                                     \n\t"
    "             ld    R26, Z                 \n\t"    // Temp store contents in R26
    "             st    Z, 0x55                \n\t"    // Store 0x55 at RAM location
    "             ld    R27, Z                 \n\t"    // Read to confirm 0x55
    "             st    Z, R26                 \n\t"    // Place old contents back in
    "             cpi   R27, 0x55              \n\t" 
    "             brne  BAD_RAM                \n\t"
    "             ld    R26, Z                 \n\t"    // Temp store contents in R26
    "             st    Z, 0xAA                \n\t"    // Store 0xAA at RAM location
    "             ld    R27, Z                 \n\t"    // Read to confirm 0xAA
    "             st    Z+, R26                \n\t"    // Place old contents back in, move to next addr
    "             cpi   R27, 0xAA              \n\t" 
    "             breq  CHECK_DONE             \n\t"
  );

    // Test failure
  asm volatile(
    "BAD_RAM:                                                              \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "DONE:                                \n\t"
    );
    result = true;

    return result;
}

void setup() 
{
  sram_test();
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{

}
