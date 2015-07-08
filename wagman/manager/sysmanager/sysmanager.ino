//---------- I N C L U D E S --------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <EEPROM.h>
#include <Wire.h>



//---------- C O N S T A N T S ------------------------------------------------
// Address of POST result
const byte EEPROM_POST_RESULT = 0x0000;
// Address of number of times SOS boot mode has been tried
const byte EEPROM_NUM_SOS_BOOT_TRIES = 0x0001;
// Address of enabled/disabled status of node controller
const byte EEPROM_NC_DISABLED = 0x0002;
// Address of enabled/disabled status of ethernet switch
const byte EEPROM_ES_DISABLED = 0x0003;
// Address of lower temperature limit for system monitor
const byte EEPROM_SYSMON_ENVIRON_TEMP_LOW = 0x0004;
// Address of upper temperature limit for system monitor
const byte EEPROM_SYSMON_ENVIRON_TEMP_HIGH = 0x0005;
// Address of lower relative humidity limit for system monitor
const byte EEPROM_SYSMON_ENVIRON_RH_LOW = 0x0006;
// Address of upper relative humidity limit for system monitor
const byte EEPROM_SYSMON_ENVIRON_RH_HIGH = 0x0007;
// Address of lower temperature limit for node controller
const byte EEPROM_NC_ENVIRON_TEMP_LOW = 0x0008;
// Address of upper temperature limit for node controller
const byte EEPROM_NC_ENVIRON_TEMP_HIGH = 0x0009;
// Address of flag for incomplete timer test
const byte EEPROM_TIMER_TEST_INCOMPLETE = 0x000A;


const byte PIN_LED = 13;



//---------- S E T U P --------------------------------------------------------
void setup() 
{  
  // Make sure everything (internal) is working correctly
  POST();

  // Boot self, node controller, and ethernet switch.  Boot successful?
  if(boot_primary())
    // Boot the guest nodes
    boot_gn();
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{

}



//---------- T I M E R 1 _ O V E R F L O W _ I N T E R R U P T ----------------
/*
   Interrupt for Timer1 overflow (used for resetting watchdog).

   :rtype: none
*/
ISR(TIMER1_OVF_vect)
{
  // Reset watchdog
  wdt_reset();
}