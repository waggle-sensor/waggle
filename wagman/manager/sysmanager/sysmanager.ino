//---------- I N C L U D E S --------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <Wire.h>
#include <HTU21D.h>
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

// Time (ms) to give node controller to prepare to receive message
#define NC_MESSAGE_DELAY 10

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
#define PROBLEM_SYSMON_ENVIRON "SM:e"
#define PROBLEM_SYSMON_POWER "SM:p"
#define PROBLEM_NC_TEMP "NC:t"
#define PROBLEM_NC_ENVIRON "NC:e"
#define PROBLEM_NC_POWER "NC:p"
#define PROBLEM_NC_HEARTBEAT "NC:h"
#define PROBLEM_SWITCH_TEMP "SW:t"
#define PROBLEM_SWITCH_POWER "SW:p"
#define PROBLEM_SWITCH_HEARTBEAT "SW:h"
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
#define REQUEST_TIME '1'
#define REQUEST_STATUS '2'
#define REQUEST_REBOOT_NC '3'
#define REQUEST_REBOOT_SWITCH '4'
#define REQUEST_REBOOT_GN1 '5'
#define REQUEST_REBOOT_GN2 '6'
#define REQUEST_REBOOT_GN3 '7'



//---------- G L O B A L S ----------------------------------------------------
volatile byte _timer1_cycle = false;
volatile char USART_RX_char;
volatile boolean _USART_new_char = false;

HTU21D SysMon_HTU21D;

boolean _switch_running = false;
boolean _GN1_running = false;
boolean _GN2_running = false;
boolean _GN3_running = false;

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
byte count_timeout_temp_processor_NC = 0;
byte count_timeout_temp_switch = 0;
byte count_timeout_temp_GN1 = 0;
byte count_timeout_temp_GN2 = 0;
byte count_timeout_temp_GN3 = 0;

unsigned int latest_power_SysMon;
int latest_environ_temp_SysMon_NC;
byte latest_environ_hum_SysMon_NC;
unsigned int latest_power_NC;
unsigned int latest_temp_NC;
unsigned int latest_power_switch;
unsigned int latest_temp_switch;
unsigned int latest_power_GN1;
unsigned int latest_temp_GN1;
unsigned int latest_power_GN2;
unsigned int latest_temp_GN2;
unsigned int latest_power_GN3;
unsigned int latest_temp_GN3;

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
uint8_t EEMEM E_BAD_TEMP_PROCESSOR_TIMEOUT_NC;
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
uint16_t EEMEM E_TEMP_MIN_PROCESSOR_NC;
uint16_t EEMEM E_TEMP_MAX_PROCESSOR_NC;
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
uint8_t EEMEM E_HUMIDITY_MIN_NC;
uint8_t EEMEM E_HUMIDITY_MAX_NC;
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
  // Is POST enabled?
  #ifdef BOOT_POST
    // Is everything (internal) working correctly?
    if(POST())
    {
      // Boot SysMon, node controller, and ethernet switch.  Boot successful?
      if(boot_primary())
      {
        // Boot the guest nodes
        boot_GN1();
        boot_GN2();
        boot_GN3();
      }
      else
        // Boot failed, so go to sleep
        sleep();
    }
    // Something non-fatal failed the POST
    else
      // Go to partial boot sequence
      boot_SOS();
  #else
    // Boot SysMon, node controller, and ethernet switch.  Boot successful?
    if(boot_primary())
    {
      // Boot the guest nodes
      boot_GN1();
      boot_GN2();
      boot_GN3();
    }
    else
      // Boot failed, so go to sleep
      sleep();
  #endif
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{
  // Has the timer finished a cycle?
  if(_timer1_cycle)
  {
    // Increment status report counter
    count_status_report++;

    //////
    // Increment/clear timeouts...
    //////

    // Is SysMon's environment unacceptable?
    if(!check_environ_SysMon())
      // Increment counter
      count_timeout_environ_SysMon++;
    else
      // Reset counter (we want to track timeouts, not accumulations)
      count_timeout_environ_SysMon = 0;

    // Is SysMon's power draw unacceptable?
    if(!check_power_SysMon())
      count_timeout_power_SysMon++;
    else
      count_timeout_power_SysMon = 0;


    // Is the node controller's environment unacceptable?
    if(!check_environ_NC())
      count_timeout_environ_NC++;
    else
      count_timeout_environ_NC = 0;

    // Is the node controller's processor temperature unacceptable?
    if(!check_temp_NC())
      count_timeout_temp_processor_NC++;
    else
      count_timeout_temp_processor_NC = 0;

    // Is the node controller's power draw unacceptable?
    if(!check_power_NC())
      count_timeout_power_NC++;
    else
      count_timeout_power_NC = 0;

    // Is the node controller's heartbeat not detected?
    if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
      count_timeout_heartbeat_NC++;
    else
      count_timeout_heartbeat_NC = 0;


    // Is ethernet switch operating?
    if(_switch_running)
    {
      // Is the ethernet switch's temperature unacceptable?
      if(!check_temp_switch())
        count_timeout_temp_switch++;
      else
        count_timeout_temp_switch = 0;

      // Is the ethernet switch's power draw unacceptable?
      if(!check_power_switch())
        count_timeout_power_switch++;
      else
        count_timeout_power_switch = 0;
    }


    // Is guest node 1 operating?
    if(_GN1_running)
    {
      // Is the guest node's temperature unacceptable?
      if(!check_temp_GN(1))
        count_timeout_temp_GN1++;
      else
        count_timeout_temp_GN1 = 0;

      // Is the guest node's power draw unacceptable?
      if(!check_power_GN(1))
        count_timeout_power_GN1++;
      else
        count_timeout_power_GN1 = 0;

      // Is the guest node's heartbeat not detected?
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN1))
        count_timeout_heartbeat_GN1++;
      else
        count_timeout_heartbeat_GN1 = 0;
    }


    // Is guest node 2 operating?
    if(_GN2_running)
    {
      // Is the guest node's temperature unacceptable?
      if(!check_temp_GN(2))
        count_timeout_temp_GN2++;
      else
        count_timeout_temp_GN2 = 0;

      // Is the guest node's power draw unacceptable?
      if(!check_power_GN(2))
        count_timeout_power_GN2++;
      else
        count_timeout_power_GN2 = 0;

      // Is the guest node's heartbeat not detected?
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN2))
        count_timeout_heartbeat_GN2++;
      else
        count_timeout_heartbeat_GN2 = 0;
    }


    // Is guest node 3 operating?
    if(_GN3_running)
    {
      // Is the guest node's temperature unacceptable?
      if(!check_temp_GN(3))
        count_timeout_temp_GN3++;
      else
        count_timeout_temp_GN3 = 0;

      // Is the guest node's power draw unacceptable?
      if(!check_power_GN(3))
        count_timeout_power_GN3++;
      else
        count_timeout_power_GN3 = 0;

      // Is the guest node's heartbeat not detected?
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN3))
        count_timeout_heartbeat_GN3++;
      else
        count_timeout_heartbeat_GN3 = 0;
    }

    //////
    // React to timeouts...
    //////

    // Bad power timeout for SysMon?
    if(count_timeout_power_SysMon >= eeprom_read_byte(&E_BAD_CURRENT_TIMEOUT_SYSMON))
    {
      // Inform node controller of the problem
      send_problem(PROBLEM_SYSMON_POWER);

      // Clear all of SysMon's timeout counters
      count_timeout_power_SysMon = 0;
      count_timeout_environ_SysMon = 0;

      // Go to sleep
      sleep();
    }
    // Bad environment timeout for SysMon?
    else if(count_timeout_environ_SysMon >= eeprom_read_byte(&E_BAD_ENVIRON_TIMEOUT_SYSMON))
    {
      // Inform node controller of the problem
      send_problem(PROBLEM_SYSMON_ENVIRON);

      // Clear all of SysMon's timeout counters
      count_timeout_power_SysMon = 0;
      count_timeout_environ_SysMon = 0;

      // Go to sleep
      sleep();
    }


    // Has something timed out for node controller?
    if((count_timeout_heartbeat_NC >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_NC))
      || (count_timeout_power_NC >= eeprom_read_byte(&E_BAD_CURRENT_TIMEOUT_NC))
      || (count_timeout_environ_NC >= eeprom_read_byte(&E_BAD_ENVIRON_TIMEOUT_NC))
      || (count_timeout_temp_processor_NC >= eeprom_read_byte(&E_BAD_TEMP_PROCESSOR_TIMEOUT_NC)))
    {
      // Clear all the node controller's timeout counters
      count_timeout_heartbeat_NC = 0;
      count_timeout_power_NC = 0;
      count_timeout_environ_NC = 0;
      count_timeout_temp_processor_NC = 0;

      // Reboot the node controller
      boot_NC();
    }


    // Is ethernet switch operating?
    if(_switch_running)
    {
      // Bad power timeout for ethernet switch?
      if(count_timeout_power_switch >= eeprom_read_byte(&E_BAD_CURRENT_TIMEOUT_SWITCH))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_SWITCH_POWER);

        // Clear all of switch's timeout counters
        count_timeout_power_switch = 0;
        count_timeout_temp_switch = 0;

        // Reboot the switch
        boot_switch();
      }
      // Bad temperature timeout for ethernet switch?
      else if(count_timeout_temp_switch >= eeprom_read_byte(&E_BAD_TEMP_TIMEOUT_SWITCH))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_SWITCH_TEMP);

        // Clear all of switch's timeout counters
        count_timeout_power_switch = 0;
        count_timeout_temp_switch = 0;

        // Reboot the switch
        boot_switch();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_switch = 0;
        latest_temp_switch = 0;
      }
    }


    // Is guest node 1 operating?
    if(_GN1_running)
    {
      // Bad power timeout for guest node 1?
      if(count_timeout_power_GN1 >= eeprom_read_byte(&E_BAD_CURRENT_TIMEOUT_GN1))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN1_POWER);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN1 = 0;
        count_timeout_temp_GN1 = 0;
        count_timeout_heartbeat_GN1 = 0;

        // Reboot guest node
        boot_GN1();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN1 = 0;
        latest_temp_GN1 = 0;
      }
      // Bad temperature timeout for guest node 1?
      else if(count_timeout_temp_GN1 >= eeprom_read_byte(&E_BAD_TEMP_TIMEOUT_GN1))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN1_TEMP);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN1 = 0;
        count_timeout_temp_GN1 = 0;
        count_timeout_heartbeat_GN1 = 0;

        // Reboot guest node
        boot_GN1();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN1 = 0;
        latest_temp_GN1 = 0;
      }
      // Bad heartbeat timeout for guest node 1?
      else if(count_timeout_heartbeat_GN1 >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_GN1))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN1_HEARTBEAT);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN1 = 0;
        count_timeout_temp_GN1 = 0;
        count_timeout_heartbeat_GN1 = 0;

        // Reboot guest node
        boot_GN1();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN1 = 0;
        latest_temp_GN1 = 0;
      }
    }


    // Is guest node 2 operating?
    if(_GN2_running)
    {
      // Bad power timeout for guest node 2?
      if(count_timeout_power_GN2 >= eeprom_read_byte(&E_BAD_CURRENT_TIMEOUT_GN2))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN2_POWER);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN2 = 0;
        count_timeout_temp_GN2 = 0;
        count_timeout_heartbeat_GN2 = 0;

        // Reboot guest node
        boot_GN2();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN2 = 0;
        latest_temp_GN2 = 0;
      }
      // Bad temperature timeout for guest node 2?
      else if(count_timeout_temp_GN2 >= eeprom_read_byte(&E_BAD_TEMP_TIMEOUT_GN2))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN2_TEMP);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN2 = 0;
        count_timeout_temp_GN2 = 0;
        count_timeout_heartbeat_GN2 = 0;

        // Reboot guest node
        boot_GN2();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN2 = 0;
        latest_temp_GN2 = 0;
      }
      // Bad heartbeat timeout for guest node 2?
      else if(count_timeout_heartbeat_GN2 >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_GN2))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN2_HEARTBEAT);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN2 = 0;
        count_timeout_temp_GN2 = 0;
        count_timeout_heartbeat_GN2 = 0;

        // Reboot guest node
        boot_GN2();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN2 = 0;
        latest_temp_GN2 = 0;
      }
    }


    // Is guest node 3 operating?
    if(_GN3_running)
    {
      // Bad power timeout for guest node 3?
      if(count_timeout_power_GN3 >= eeprom_read_byte(&E_BAD_CURRENT_TIMEOUT_GN3))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN3_POWER);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN3 = 0;
        count_timeout_temp_GN3 = 0;
        count_timeout_heartbeat_GN3 = 0;

        // Reboot guest node
        boot_GN3();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN3 = 0;
        latest_temp_GN3 = 0;
      }
      // Bad temperature timeout for guest node 3?
      else if(count_timeout_temp_GN3 >= eeprom_read_byte(&E_BAD_TEMP_TIMEOUT_GN3))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN3_TEMP);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN3 = 0;
        count_timeout_temp_GN3 = 0;
        count_timeout_heartbeat_GN3 = 0;

        // Reboot guest node
        boot_GN3();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN3 = 0;
        latest_temp_GN3 = 0;
      }
      // Bad heartbeat timeout for guest node 3?
      else if(count_timeout_heartbeat_GN3 >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_GN3))
      {
        // Inform node controller of the problem
        send_problem(PROBLEM_GN3_HEARTBEAT);

        // Clear all of guest node's timeout counters
        count_timeout_power_GN3 = 0;
        count_timeout_temp_GN3 = 0;
        count_timeout_heartbeat_GN3 = 0;

        // Reboot guest node
        boot_GN3();

        // Clear latest readings, in case the device failed to boot.
        // This is so the status report doesn't keep reporting the last
        // non-zero values.
        latest_power_GN3 = 0;
        latest_temp_GN3 = 0;
      }
    }


    // Time to send a status report?
    if(count_status_report >= eeprom_read_byte(&E_STATUS_REPORT_PERIOD))
    {
      // Clear the counter
      count_status_report = 0;

      send_status();
    }


    // Clear the flag for the next timer cycle
    _timer1_cycle = false;
  }

  // Received a new serial character?
  if(_USART_new_char)
  {
    // Clear flag
    _USART_new_char = false;

    // Which request was received?
    if(USART_RX_char == REQUEST_TIME)
      send_time();
    else if(USART_RX_char == REQUEST_STATUS)
      send_status();
    else if(USART_RX_char == REQUEST_REBOOT_NC)
      boot_NC();
    else if(USART_RX_char == REQUEST_REBOOT_SWITCH)
      boot_switch();
    else if(USART_RX_char == REQUEST_REBOOT_GN1)
      boot_GN1();
    else if(USART_RX_char == REQUEST_REBOOT_GN2)
      boot_GN2();
    else if(USART_RX_char == REQUEST_REBOOT_GN3)
      boot_GN3();
  }
}



//---------- S E N D _ S T A T U S --------------------------------------------
/*
   Sends a status report of all important info to the node controller.

   Message structure:
   RTC time,
   Light level (ADC value),
   Current draw (SysMon),
   Environment temperature (SysMon & NC),
   Relative humidity (SysMon & NC),
   Current draw (NC),
   Temperature of processor (NC),
   Enabled/disabled (switch),
   Running/not running (switch),
   Current draw (switch),
   Temperature (switch),
   Enabled/disabled (GN 1),
   Running/not running (GN 1),
   Current draw (GN 1),
   Temperature (GN 1),
   Enabled/disabled (GN 2),
   Running/not running (GN 2),
   Current draw (GN 2),
   Temperature (GN 2),
   Enabled/disabled (GN 3),
   Running/not running (GN 3),
   Current draw (GN 3),
   Temperature (GN 3)

   :rtype: none
*/
void send_status()
{
  String message = "";

  // Tell the node controller that a status report is coming
  Serial.println(NC_NOTIFIER_STATUS);

  // Give it time to get ready
  delay(NC_MESSAGE_DELAY);

  // Assemble the message
  message += String(RTC.get()) + NC_DELIMITER;
  message += String(analogRead(PIN_PHOTOCELL)) + NC_DELIMITER;
  message += String(latest_power_SysMon) + NC_DELIMITER;
  message += String(latest_environ_temp_SysMon_NC) + NC_DELIMITER;
  message += String(latest_environ_hum_SysMon_NC) + NC_DELIMITER;
  message += String(latest_power_NC) + NC_DELIMITER;
  message += String(latest_temp_NC) + NC_DELIMITER;
  if(eeprom_read_byte(&E_SWITCH_ENABLED))
    message += String(1) + NC_DELIMITER;
  else
    message += String(0) + NC_DELIMITER;
  message += String(_switch_running) + NC_DELIMITER;
  message += String(latest_power_switch) + NC_DELIMITER;
  message += String(latest_temp_switch) + NC_DELIMITER;
  if(eeprom_read_byte(&E_GN1_ENABLED))
    message += String(1) + NC_DELIMITER;
  else
    message += String(0) + NC_DELIMITER;
  message += String(_GN1_running) + NC_DELIMITER;
  message += String(latest_power_GN1) + NC_DELIMITER;
  message += String(latest_temp_GN1) + NC_DELIMITER;
  if(eeprom_read_byte(&E_GN2_ENABLED))
    message += String(1) + NC_DELIMITER;
  else
    message += String(0) + NC_DELIMITER;
  message += String(_GN2_running) + NC_DELIMITER;
  message += String(latest_power_GN2) + NC_DELIMITER;
  message += String(latest_temp_GN2) + NC_DELIMITER;
  if(eeprom_read_byte(&E_GN3_ENABLED))
    message += String(1) + NC_DELIMITER;
  else
    message += String(0) + NC_DELIMITER;
  message += String(_GN3_running) + NC_DELIMITER;
  message += String(latest_power_GN3) + NC_DELIMITER;
  message += String(latest_temp_GN3);

  // Send it
  Serial.println(message);
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
  delay(NC_MESSAGE_DELAY);

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
  delay(NC_MESSAGE_DELAY);

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