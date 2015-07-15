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
const byte LED = 13;
const char NC_NOTIFIER_STATUS = '@';
const char NC_NOTIFIER_PROBLEM = '#';
const char NC_NOTIFIER_PARAMS = '$';
const char NC_TERMINATOR = '!';



//---------- G L O B A L S ----------------------------------------------------
volatile byte timer1_interrupt_fired = 0;
volatile char USART_RX_char;
volatile boolean _USART_new_char = false;

// EEPROM addresses whose values are set by node controller:
// Initial values act as default
unsigned long EEMEM E_UART_BAUD = 57600UL;
unsigned int EEMEM E_USART_RX_BUFFER_SIZE = 150;
byte EEMEM E_ENVIRON_CHECK_PERIOD = 5;
byte EEMEM E_MAX_NUM_SOS_BOOT_TRIES = 3;
byte EEMEM E_HEARTBEAT_TIMEOUT_NC = 5;
byte EEMEM E_HEARTBEAT_TIMEOUT_SWITCH = 5;
byte EEMEM E_HEARTBEAT_TIMEOUT_GN1 = 5;
byte EEMEM E_HEARTBEAT_TIMEOUT_GN2 = 5;
byte EEMEM E_HEARTBEAT_TIMEOUT_GN3 = 5;
byte EEMEM E_HEARTBEAT_TIMEOUT_GN4 = 5;
byte EEMEM E_BAD_TEMP_TIMEOUT_SYSMON = 5;
byte EEMEM E_BAD_TEMP_TIMEOUT_NC = 5;
byte EEMEM E_BAD_TEMP_TIMEOUT_SWITCH = 5;
byte EEMEM E_BAD_TEMP_TIMEOUT_GN1 = 5;
byte EEMEM E_BAD_TEMP_TIMEOUT_GN2 = 5;
byte EEMEM E_BAD_TEMP_TIMEOUT_GN3 = 5;
byte EEMEM E_BAD_TEMP_TIMEOUT_GN4 = 5;
int EEMEM E_TEMP_MIN_SYSMON = 0;
int EEMEM E_TEMP_MAX_SYSMON = 100;
int EEMEM E_TEMP_MIN_NC = 0;
int EEMEM E_TEMP_MAX_NC = 100;
int EEMEM E_TEMP_MIN_SWITCH = 0;
int EEMEM E_TEMP_MAX_SWITCH = 100;
int EEMEM E_TEMP_MIN_GN1 = 0;
int EEMEM E_TEMP_MAX_GN1 = 100;
int EEMEM E_TEMP_MIN_GN2 = 0;
int EEMEM E_TEMP_MAX_GN2 = 100;
int EEMEM E_TEMP_MIN_GN3 = 0;
int EEMEM E_TEMP_MAX_GN3 = 100;
int EEMEM E_TEMP_MIN_GN4 = 0;
int EEMEM E_TEMP_MAX_GN4 = 100;
byte EEMEM E_HUMIDITY_MIN_SYSMON = 0;
byte EEMEM E_HUMIDITY_MAX_SYSMON = 100;

// EEPROM addresses whose values are not set by node controller:
byte EEMEM E_NC_DISABLED = 0;
byte EEMEM E_ES_DISABLED = 0;
byte EEMEM E_POST_RESULT = 0;
byte EEMEM E_TIMER_TEST_INCOMPLETE = 0;
byte EEMEM E_NUM_SOS_BOOT_TRIES = 0;



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
  get_params_nc();
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{
  
  // Has the timer overflowed enough times?
  if(timer1_interrupt_fired >= )
  {
    // Clear the Timer1 overflow counter
    timer1_interrupt_fired = 0;

    // Environ. checks go here

    // Send status report to node controller
    send_status();

    // Send problem report to node controller
    send_problem();
  }

  //get_params_nc();

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
  // Tell the node controller that a status report is coming
  Serial.println(NC_NOTIFIER_STATUS);

  // Give it time to get ready
  delay(10);

  // Send status report
  Serial.println("status report");
}



//---------- S E N D _ P R O B L E M ------------------------------------------
/*
   Sends a problem report to the node controller.

   :rtype: none
*/
void send_problem()
{
  // Tell the node controller that a problem report is coming
  Serial.println(NC_NOTIFIER_PROBLEM);

  // Give it time to get ready
  delay(10);

  // Send problem report
  Serial.println("problem report");
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