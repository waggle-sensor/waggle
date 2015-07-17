//---------- I N C L U D E S --------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <Wire.h>



//---------- C O N S T A N T S ------------------------------------------------
const byte LED = 13;
const char NC_NOTIFIER_STATUS = '@';
const char NC_NOTIFIER_PROBLEM = '#';
const char NC_NOTIFIER_PARAMS_CORE = '$';
const char NC_NOTIFIER_PARAMS_GN = '^';
const char NC_DELIMITER = ',';
const char NC_TERMINATOR = '!';



//---------- G L O B A L S ----------------------------------------------------
volatile byte timer1_interrupt_fired = 0;
volatile byte _timer1_cycle = false;
volatile char USART_RX_char;
volatile boolean _USART_new_char = false;

// EEPROM addresses whose values are set by node controller:
// Initial values act as default
uint32_t EEMEM E_USART_BAUD;
uint16_t EEMEM E_USART_RX_BUFFER_SIZE;
uint8_t EEMEM E_MAX_NUM_SOS_BOOT_TRIES;
uint8_t EEMEM E_PRESENT_GN1;
uint8_t EEMEM E_PRESENT_GN2;
uint8_t EEMEM E_PRESENT_GN3;
uint8_t EEMEM E_PRESENT_GN4;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_NC;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_SWITCH;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN1;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN2;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN3;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN4;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_SYSMON;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_NC;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_SWITCH;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_GN1;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_GN2;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_GN3;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_GN4;
// EEPROM only stores unsigned values.  Must cast to signed when reading.
uint16_t EEMEM E_TEMP_MIN_SYSMON_SIGNED;
uint16_t EEMEM E_TEMP_MAX_SYSMON_SIGNED;
uint16_t EEMEM E_TEMP_MIN_NC_SIGNED;
uint16_t EEMEM E_TEMP_MAX_NC_SIGNED;
uint16_t EEMEM E_TEMP_MIN_SWITCH_SIGNED;
uint16_t EEMEM E_TEMP_MAX_SWITCH_SIGNED;
uint16_t EEMEM E_TEMP_MIN_GN1_SIGNED;
uint16_t EEMEM E_TEMP_MAX_GN1_SIGNED;
uint16_t EEMEM E_TEMP_MIN_GN2_SIGNED;
uint16_t EEMEM E_TEMP_MAX_GN2_SIGNED;
uint16_t EEMEM E_TEMP_MIN_GN3_SIGNED;
uint16_t EEMEM E_TEMP_MAX_GN3_SIGNED;
uint16_t EEMEM E_TEMP_MIN_GN4_SIGNED;
uint16_t EEMEM E_TEMP_MAX_GN4_SIGNED;
uint8_t EEMEM E_HUMIDITY_MIN_SYSMON;
uint8_t EEMEM E_HUMIDITY_MAX_SYSMON;

// EEPROM addresses whose values are not set by node controller:
uint8_t EEMEM E_NC_ENABLED;
uint8_t EEMEM E_SWITCH_ENABLED;
uint8_t EEMEM E_GN1_ENABLED;
uint8_t EEMEM E_GN2_ENABLED;
uint8_t EEMEM E_GN3_ENABLED;
uint8_t EEMEM E_GN4_ENABLED;
uint8_t EEMEM E_POST_RESULT;
uint8_t EEMEM E_TIMER_TEST_INCOMPLETE;
uint8_t EEMEM E_NUM_SOS_BOOT_TRIES;
uint8_t EEMEM E_FIRST_BOOT;



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

  boot_primary();
  boot_gn();

  // pinMode(PD4, OUTPUT);
  // digitalWrite(PD4, HIGH);

  // delay(500);

  // good
  // pinMode(PD7, OUTPUT);
  // digitalWrite(PD7, HIGH);
  // pinMode(PE6, INPUT);

  // good
  // pinMode(PB4, OUTPUT);
  // digitalWrite(PB4, HIGH);

  // pinMode(PB6, OUTPUT);
  // digitalWrite(PB6, HIGH);

  pinMode(PD6, OUTPUT);
  digitalWrite(PD6, HIGH);
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{
  
  // Has the timer finished a cycle?
  if(_timer1_cycle)
  {
    // Clear the flag
    _timer1_cycle = false;

    // Environ. checks go here

    // Send status report to node controller
    send_status();

    // Send problem report to node controller
    send_problem();

    if(digitalRead(PD7) == LOW)
      digitalWrite(PD6, LOW);
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

  // Increment the counter for how many timer overflows have occurred
  timer1_interrupt_fired++;

  // Set the flag to indicate a complete timer cycle
  _timer1_cycle = true;
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