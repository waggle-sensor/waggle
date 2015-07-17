//---------- I N C L U D E S --------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <Wire.h>
#include <SparkFunHTU21D.h>
#include <Time.h>
#include <MCP79412RTC.h>



//---------- C O N S T A N T S ------------------------------------------------
#define PIN_RELAY2 PB6

#define PIN_HEARTBEAT2 PB5

#define PIN_PHOTOCELL PF5
#define PIN_JP10_10 PF4

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

HTU21D SysMon_HTU21D;

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

  Serial.println(SysMon_HTU21D.readTemperature());
  Serial.println(SysMon_HTU21D.readHumidity());  

  RTC.set(0);
}


byte x = 0;
//---------- L O O P ----------------------------------------------------------
void loop() 
{
  // Has the timer finished a cycle?
  if(_timer1_cycle)
  {
    Serial.println(RTC.get());

    // Clear the flag
    _timer1_cycle = false;

    // Environ. checks go here

    // Send status report to node controller
    send_status();

    // Send problem report to node controller
    send_problem();

    if(digitalRead(PIN_HEARTBEAT2) == LOW)
    {
      x++;
      if(x == eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_NC))
      {
        digitalWrite(PIN_RELAY2, LOW);

        delay(200);

        digitalWrite(PIN_RELAY2, HIGH);

        x = 0;
      }
    }
  }
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
  String report = "P:" +
                  String(analogRead(PIN_PHOTOCELL)) +
                  ",T:" +
                  String(analogRead(PIN_JP10_10));

  Serial.println(report);
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