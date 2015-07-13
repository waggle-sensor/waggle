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

const byte LED = 13;
const long UART_BAUD = 57600L;
const byte CHECK_ENVIRON_COUNT = 5;
const char USART_RX_BUFFER_SIZE = 100;



//---------- G L O B A L S ----------------------------------------------------
volatile byte timer1_interrupt_fired = 0;
volatile char USART_RX_char;
volatile boolean _USART_new_char = false;



//---------- S E T U P --------------------------------------------------------
void setup() 
{
  delay(5000);

  // // Is everything (internal) working correctly?
  // if(POST())
  // {
  //   // Boot self, node controller, and ethernet switch.  Boot successful?
  //   if(boot_primary())
  //     // Boot the guest nodes
  //     boot_gn();
  // }
  // // Something non-fatal failed the POST
  // else
  //   // Go to partial boot sequence
  //   boot_SOS();

  init_primary();
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{
  
  // Has the timer overflowed enough times?
  if(timer1_interrupt_fired >= CHECK_ENVIRON_COUNT)
  {
    // Clear the Timer1 overflow counter
    timer1_interrupt_fired = 0;

    // Environ. checks go here

    // Send status report to node controller
    //send_status();
  }

  get_params_nc();

  // Received new serial data?
  // if(_USART_new_char)
  // {
  //   // Node controller requesting status report?
  //   if(USART_RX_char == "$")
  // }
}



//---------- S E N D _ S T A T U S --------------------------------------------
/*
   Sends a status report of all important info to the node controller.

   :rtype: none
*/
void send_status()
{
  Serial.println("$");
}



//---------- T I M E R 1 _ O V E R F L O W _ I N T E R R U P T ----------------
/*
   Interrupt for Timer1 overflow.  Resets the watchdog and increments the
   counter used to tell the MCU when to check the environment.

   :rtype: none
*/
ISR(TIMER1_OVF_vect)
{
  // Reset watchdog
  wdt_reset();

  // Tell the world that the interrupt fired
  timer1_interrupt_fired++;
}



//---------- U S A R T 1 _ R X _ I N T E R R U P T ----------------------------
/*
   Interrupt for USART1 receive.

   :rtype: none
*/
ISR(USART1_RX_vect)
{
  // Read and store new character
  USART_RX_char = Serial.read();

  // Set flag to tell main program that new serial data is available
  _USART_new_char = true;
}