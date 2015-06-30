#line 1 "asm.ino"
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <EEPROM.h>
#include "Arduino.h"
boolean gprf_test();
void setup();
void loop();
#line 7
boolean gprf_test()
{
                                                                           
                                 
    asm("");

    boolean result;

                                                                         
                                                                               
                                                  
    asm volatile(
                      
    "LD_Z:                                     \n\t"
    "             ld    R31, 0x01              \n\t"
    "             ld    R30, 0x00              \n\t"
    "CHECK_DONE:                               \n\t"
    "             cpi   R31, 0x0A              \n\t"
    "             brne  LOOP                   \n\t"
    "             cpi   R30, 0xFF              \n\t"
    "             breq  DONE                   \n\t"
    "LOOP:                                     \n\t"
    "             ld    R26, Z                 \n\t"                                 
    "             st    Z, 0x55                \n\t"                                 
    "             ld    R27, Z                 \n\t"                           
    "             st    Z, R26                 \n\t"                                 
    "             cpi   R27, 0x55              \n\t" 
    "             brne  BAD_RAM                \n\t"
    "             ld    R26, Z                 \n\t"                                 
    "             st    Z, 0xAA                \n\t"                                 
    "             ld    R27, Z                 \n\t"                           
    "             st    Z+, R26                \n\t"                                                    
    "             cpi   R27, 0xAA              \n\t" 
    "             brne  BAD_RAM                \n\t"
    "             jmp   CHECK_DONE             \n\t"
  );

                   
  asm volatile(
    "BAD_RAM:                                                              \n\t"
  );
  result = false;

                 
  asm volatile(
    "DONE:                                \n\t"
    );
    result = true;

    return result;
}

void setup() 
{
  gprf_test();
}



                                                                               
void loop() 
{

}

