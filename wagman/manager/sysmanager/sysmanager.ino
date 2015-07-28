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
//#define BOOT_POST

// Node controller (JP1)
#define PIN_RELAY_NC 4
#define PIN_HEARTBEAT_NC 5
// Network switch (JP2)
#define PIN_RELAY_SWITCH 6
#define PIN_HEARTBEAT_SWITCH 7
// Guest node 1 (JP3)
#define PIN_RELAY_GN1 8
#define PIN_HEARTBEAT_GN1 9
// Guest node 2 (JP4)
#define PIN_RELAY_GN2 10
#define PIN_HEARTBEAT_GN2 11
// Guest node 3 (JP5)
#define PIN_RELAY_GN3 12
#define PIN_HEARTBEAT_GN3 13
// Thermistors (JP10)
#define PIN_THERMISTOR_NC A0
#define PIN_THERMISTOR_SWITCH A1
#define PIN_THERMISTOR_GN1 A2
#define PIN_THERMISTOR_GN2 A3
#define PIN_THERMISTOR_GN3 A4
// Light detector
#define PIN_PHOTOCELL A5

// Period of heartbeat for ODroids (ms)
// This needs to be small and an even number
#define HEARTBEAT_PERIOD_ODROID 40

// Delay after bad environment reading during boot (seconds)
#define BOOT_BAD_ENVIRON_WAIT_TIME 5
// Delay after bad power reading during boot (seconds)
#define BOOT_BAD_POWER_WAIT_TIME 1

// I2C addresses for current sensors
#define ADDR_CURRENT_SENSOR_SYSMON 0x60
#define ADDR_CURRENT_SENSOR_NC 0x62
#define ADDR_CURRENT_SENSOR_SWITCH 0x63
#define ADDR_CURRENT_SENSOR_GN1 0x68
#define ADDR_CURRENT_SENSOR_GN2 0x6A
#define ADDR_CURRENT_SENSOR_GN3 0x6B

// Resolution of current sensors (with 8A range) (mA)
#define MILLIAMPS_PER_STEP 16

// Special characters for interacting with the node controller
#define NC_NOTIFIER_STATUS '@'
#define NC_NOTIFIER_PROBLEM '#'
#define NC_NOTIFIER_PARAMS_CORE '$'
#define NC_NOTIFIER_PARAMS_GN '^'
#define NC_NOTIFIER_TIME_REQUEST '*'
#define NC_NOTIFIER_TIME_SEND '('
#define NC_DELIMITER ','
#define NC_TERMINATOR '!'

// Messages to send to node controller
#define PROBLEM_SYSMON_TEMP "SM:t"
#define PROBLEM_SYSMON_POWER "SM:p"
#define PROBLEM_NC_TEMP "NC:t"
#define PROBLEM_NC_POWER "NC:p"
#define PROBLEM_SWITCH_TEMP "SW:t"
#define PROBLEM_SWITCH_POWER "SW:p"
#define PROBLEM_GN1_TEMP "GN1:t"
#define PROBLEM_GN1_POWER "GN1:p"
#define PROBLEM_GN1_HEARTBEAT "GN1:h"
#define PROBLEM_GN2_TEMP "GN2:t"
#define PROBLEM_GN2_POWER "GN2:p"
#define PROBLEM_GN2_HEARTBEAT "GN2:h"
#define PROBLEM_GN3_TEMP "GN3:t"
#define PROBLEM_GN3_POWER "GN3:p"
#define PROBLEM_GN3_HEARTBEAT "GN3:h"

// Messages that might be received from node controller
#define REQUEST_TIME "1"
#define REQUEST_STATUS "2"
#define REQUEST_REBOOT_NC "3"
#define REQUEST_REBOOT_SWITCH "4"
#define REQUEST_REBOOT_GN1 "5"
#define REQUEST_REBOOT_GN2 "6"
#define REQUEST_REBOOT_GN3 "7"



//---------- G L O B A L S ----------------------------------------------------
volatile byte timer1_interrupt_fired = 0;
volatile byte _timer1_cycle = false;
volatile char USART_RX_char;
volatile boolean _USART_new_char = false;

HTU21D SysMon_HTU21D;

boolean _GN1_booted = false;
boolean _GN2_booted = false;
boolean _GN3_booted = false;

byte count_status_report = 0;
byte count_timeout_heartbeat_NC = 0;
byte count_timeout_heartbeat_switch = 0;
byte count_timeout_heartbeat_GN1 = 0;
byte count_timeout_heartbeat_GN2 = 0;
byte count_timeout_heartbeat_GN3 = 0;
byte count_timeout_power_SysMon = 0;
byte count_timeout_power_NC = 0;
byte count_timeout_power_switch = 0;
byte count_timeout_power_GN1 = 0;
byte count_timeout_power_GN2 = 0;
byte count_timeout_power_GN3 = 0;
byte count_timeout_environ_SysMon = 0;
byte count_timeout_environ_NC = 0;
byte count_timeout_temp_switch = 0;
byte count_timeout_temp_GN1 = 0;
byte count_timeout_temp_GN2 = 0;
byte count_timeout_temp_GN3 = 0;


// EEPROM addresses whose values are set by node controller:
uint32_t EEMEM E_USART_BAUD;
uint16_t EEMEM E_USART_RX_BUFFER_SIZE;
uint8_t EEMEM E_STATUS_REPORT_PERIOD;
uint8_t EEMEM E_MAX_NUM_SOS_BOOT_ATTEMPTS;
uint8_t EEMEM E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS;
uint16_t EEMEM E_BOOT_TIME_NC;
uint8_t EEMEM E_BOOT_TIME_SWITCH;
uint16_t EEMEM E_BOOT_TIME_GN1;
uint16_t EEMEM E_BOOT_TIME_GN2;
uint16_t EEMEM E_BOOT_TIME_GN3;
uint8_t EEMEM E_PRESENT_GN1;
uint8_t EEMEM E_PRESENT_GN2;
uint8_t EEMEM E_PRESENT_GN3;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_NC;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_SWITCH;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN1;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN2;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN3;
uint8_t EEMEM E_BAD_ENVIRON_TIMEOUT_SYSMON;
uint8_t EEMEM E_BAD_ENVIRON_TIMEOUT_NC;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_SWITCH;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_GN1;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_GN2;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_GN3;
uint16_t EEMEM E_AMP_NOISE_CEILING;
uint8_t EEMEM E_BAD_CURRENT_TIMEOUT_SYSMON;
uint8_t EEMEM E_BAD_CURRENT_TIMEOUT_NC;
uint8_t EEMEM E_BAD_CURRENT_TIMEOUT_SWITCH;
uint8_t EEMEM E_BAD_CURRENT_TIMEOUT_GN1;
uint8_t EEMEM E_BAD_CURRENT_TIMEOUT_GN2;
uint8_t EEMEM E_BAD_CURRENT_TIMEOUT_GN3;
uint16_t EEMEM E_TEMP_MIN_SYSMON;
uint16_t EEMEM E_TEMP_MAX_SYSMON;
uint16_t EEMEM E_TEMP_MIN_NC;
uint16_t EEMEM E_TEMP_MAX_NC;
uint16_t EEMEM E_TEMP_MIN_SWITCH;
uint16_t EEMEM E_TEMP_MAX_SWITCH;
uint16_t EEMEM E_TEMP_MIN_GN1;
uint16_t EEMEM E_TEMP_MAX_GN1;
uint16_t EEMEM E_TEMP_MIN_GN2;
uint16_t EEMEM E_TEMP_MAX_GN2;
uint16_t EEMEM E_TEMP_MIN_GN3;
uint16_t EEMEM E_TEMP_MAX_GN3;
uint8_t EEMEM E_HUMIDITY_MIN_SYSMON;
uint8_t EEMEM E_HUMIDITY_MAX_SYSMON;
uint16_t EEMEM E_AMP_MAX_SYSMON;
uint16_t EEMEM E_AMP_MAX_NC;
uint16_t EEMEM E_AMP_MAX_SWITCH;
uint16_t EEMEM E_AMP_MAX_GN1;
uint16_t EEMEM E_AMP_MAX_GN2;
uint16_t EEMEM E_AMP_MAX_GN3;
// EEPROM addresses whose values are not set by node controller:
uint8_t EEMEM E_NC_ENABLED;
uint8_t EEMEM E_SWITCH_ENABLED;
uint8_t EEMEM E_GN1_ENABLED;
uint8_t EEMEM E_GN2_ENABLED;
uint8_t EEMEM E_GN3_ENABLED;
uint8_t EEMEM E_POST_RESULT;
uint8_t EEMEM E_TIMER_TEST_INCOMPLETE;
uint8_t EEMEM E_NUM_SOS_BOOT_ATTEMPTS;
uint8_t EEMEM E_FIRST_BOOT;



//---------- S E T U P --------------------------------------------------------
void setup() 
{
  // Debug
  delay(5000);

  // Is POST enabled?
  #ifdef BOOT_POST
    // Is everything (internal) working correctly?
    if(POST())
    {
      // Boot SysMon, node controller, and ethernet switch.  Boot successful?
      if(boot_primary())
        // Boot the guest nodes
        boot_GN();
    }
    // Something non-fatal failed the POST
    else
      // Go to partial boot sequence
      boot_SOS();
  #else
    // Boot SysMon, node controller, and ethernet switch.  Boot successful?
    if(boot_primary())
      // Boot the guest nodes
      boot_GN();
  #endif

  // Clear counter, since its been counting for awhile already
  timer1_interrupt_fired = 0;
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{
  // Has the timer finished a cycle?
  if(_timer1_cycle)
  {
    // Increment status report counter
    count_status_report++;

    // Is SysMon's environment unacceptable?
    if(!check_environ_SysMon())
      // Increment counter
      count_timeout_environ_SysMon++;
    // Is SysMon's power draw unacceptable?
    if(!check_power_SysMon())
      // Increment counter
      count_timeout_power_SysMon++;

    // Is the node controller's environment unacceptable?
    if(!check_environ_NC())
      // Increment counter
      count_timeout_environ_NC++;
    // Is the node controller's power draw unacceptable?
    if(!check_power_NC())
      // Increment counter
      count_timeout_power_NC++;
    // Is the node controller's heartbeat not detected?
    if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
      // Increment counter
      count_timeout_heartbeat_NC++;

    // Is the ethernet switch's temperature unacceptable?
    if(!check_temp_switch())
      // Increment counter
      count_timeout_temp_switch++;
    // Is the ethernet switch's power draw unacceptable?
    if(!check_power_switch())
      // Increment counter
      count_timeout_power_switch++;

    // Is guest node 1 operating?
    if(_GN1_booted)
    {
      // Is the guest node's temperature unacceptable?
      if(!check_temp_GN(1))
        // Increment counter
        count_timeout_temp_GN1++;
      // Is the guest node's power draw unacceptable?
      if(!check_power_GN(1))
        // Increment counter
        count_timeout_power_GN1++;
      // Is the guest node's heartbeat not detected?
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN1))
        // Increment counter
        count_timeout_heartbeat_GN1++;
    }

    // Is guest node 2 operating?
    if(_GN2_booted)
    {
      // Is the guest node's temperature unacceptable?
      if(!check_temp_GN(2))
        // Increment counter
        count_timeout_temp_GN2++;
      // Is the guest node's power draw unacceptable?
      if(!check_power_GN(2))
        // Increment counter
        count_timeout_power_GN2++;
      // Is the guest node's heartbeat not detected?
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN2))
        // Increment counter
        count_timeout_heartbeat_GN2++;
    }

    // Is guest node 3 operating?
    if(_GN3_booted)
    {
      // Is the guest node's temperature unacceptable?
      if(!check_temp_GN(3))
        // Increment counter
        count_timeout_temp_GN3++;
      // Is the guest node's power draw unacceptable?
      if(!check_power_GN(3))
        // Increment counter
        count_timeout_power_GN3++;
      // Is the guest node's heartbeat not detected?
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN3))
        // Increment counter
        count_timeout_heartbeat_GN3++;
    }

    // Time to send a status report?
    if(count_status_report >= eeprom_read_byte(&E_STATUS_REPORT_PERIOD))
      send_status();

    // Clear the flag for the next timer cycle
    _timer1_cycle = false;
  }

  // Received a new serial character?
  if(_USART_new_char)
  {
    // Clear flag
    _USART_new_char = false;

    // Which request was received?
    switch (USART_RX_char) {
      case REQUEST_TIME:
        send_time();
        break;

      case REQUEST_STATUS:
        send_status();
        break;

      case REQUEST_REBOOT_NC:
        boot_NC();
        break;

      case REQUEST_REBOOT_SWITCH:
        boot_switch();
        break;

      case REQUEST_REBOOT_GN1:
        boot_GN1();
        break;

      case REQUEST_REBOOT_GN2:
        boot_GN2();
        break;

      case REQUEST_REBOOT_GN3:
        boot_GN3();
        break;

      default:
        break;
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

  Serial.print("Light: ");
  Serial.println(analogRead(PIN_PHOTOCELL));
}



//---------- S E N D _ T I M E ------------------------------------------------
/*
   Sends the RTC time to the node controller.

   :rtype: none
*/
void send_time()
{
  // Tell the node controller that a time report is coming
  Serial.println(NC_NOTIFIER_TIME_SEND);

  // Give it time to get ready
  delay(10);

  // Get time from RTC and send it to the node controller
  Serial.println(RTC.get());
}



//---------- S E N D _ P R O B L E M ------------------------------------------
/*
   Sends a problem report to the node controller.

   :param String problem: description of the problem

   :rtype: none
*/
void send_problem(String problem)
{
  // Tell the node controller that a problem report is coming
  Serial.println(NC_NOTIFIER_PROBLEM);

  // Give it time to get ready
  delay(10);

  // Send problem report
  Serial.println(problem);
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