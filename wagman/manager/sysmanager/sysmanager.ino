//---------- I N C L U D E S --------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/eeprom.h>
#include <Wire.h>
#include <HTU21D.h>
#include <Time.h>
#include <MCP79412RTC.h>
#include <SoftReset.h>



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

// Delay before enabling relay after disabling it
#define POWER_CYCLE_DELAY 2000

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

boolean _NC_running = false;
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
unsigned int count_device_reboot = 0;

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
uint8_t EEMEM E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS;
uint16_t EEMEM E_DEVICE_REBOOT_PERIOD;
uint8_t EEMEM E_PRESENT_SWITCH;
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
uint8_t EEMEM E_NUM_PRIMARY_BOOT_ATTEMPTS;
uint8_t EEMEM E_FIRST_BOOT;



//---------- S E T U P --------------------------------------------------------
/*
   Call all appropriate boot routines, depending on enabled/disabled status
   of POST.

   :rtype: none
*/
void setup() 
{
  // Disable watchdog to avoid a reset loop
  wdt_disable();

  // Is POST enabled?
  #ifdef BOOT_POST
    // Is everything (internal) working correctly?
    if(POST())
    {
      // Boot SysMon, node controller, and ethernet switch.  Boot successful?
      if(boot_primary())
      {
        // Boot the guest nodes
        boot_GN(1);
        boot_GN(2);
        boot_GN(3);
      }
      else
      {
        // Grab how many boot attempts have occurred (+1 for this attempt)
        byte num_attempts = eeprom_read_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS) + 1;

        // Add failed boot attempt to the counter
        eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, num_attempts);

        // Number of boot attempts not yet reached maximum allowed?
        if(num_attempts <= eeprom_read_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS))
        {
          // Disable watchdog
          wdt_disable();
          // Set watchdog for short timeout
          wdt_enable(WDTO_15MS);

          // Wait
          while(1);
        }
        else
          // We're done trying, so go to sleep
          sleep();
      }
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
      boot_GN(1);
      boot_GN(2);
      boot_GN(3);
    }
    else
    {
      // Grab how many boot attempts have occurred (+1 for this attempt)
      byte num_attempts = eeprom_read_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS) + 1;

      // Add failed boot attempt to the counter
      eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, num_attempts);

      // Number of boot attempts not yet reached maximum allowed?
      if(num_attempts < eeprom_read_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS))
      {
        Serial.println(2);

        soft_restart();
      }
      else
      {
        // Clear the counter for number of primary boot attempts.
        // We want to start with a clean slate after reset.
        eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);

        Serial.println(3);
        delay(5);

        // We're done trying, so go to sleep
        noInterrupts();
        sleep_mode();
      }
    }
  #endif
}



//---------- L O O P ----------------------------------------------------------
/*
   Main operation of SysMon.  Monitors the system and keeps track of any
   timeouts, then responds appropriately to them.  Any devices that are turned
   off but not permanently disabled are rebooted after some time.

   :rtype: none
*/
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


    // Is node controller operating?
    if(_NC_running)
    {
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
    }


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


    // Increment counter for rebooting devices that aren't running
    count_device_reboot++;


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


    // Is node controller operating?
    if(_NC_running)
    {
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
        boot_GN(1);

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
        boot_GN(1);

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
        boot_GN(1);

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
        boot_GN(2);

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
        boot_GN(2);

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
        boot_GN(2);

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
        boot_GN(3);

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
        boot_GN(3);

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
        boot_GN(3);

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


    // Time to try to reboot any devices that aren't running?
    if(count_device_reboot >= eeprom_read_word(&E_DEVICE_REBOOT_PERIOD))
    {
      // Clear the counter
      count_device_reboot = 0;

      // Is the node controller enabled but not running?
      if((! _NC_running) && eeprom_read_byte(&E_NC_ENABLED))
        // Try to boot the node controller
        boot_NC();

      // Is the ethernet switch enabled but not running?
      if((! _switch_running) && eeprom_read_byte(&E_SWITCH_ENABLED))
        // Try to boot the switch
        boot_switch();

      // Is the guest node present & enabled but not running?
      if((! _GN1_running) && eeprom_read_byte(&E_GN1_ENABLED)
        && eeprom_read_byte(&E_PRESENT_GN1))
        // Try to boot the guest node
        boot_GN(1);

      // Is the guest node present & enabled but not running?
      if((! _GN2_running) && eeprom_read_byte(&E_GN2_ENABLED)
        && eeprom_read_byte(&E_PRESENT_GN2))
        // Try to boot the guest node
        boot_GN(2);

      // Is the guest node present & enabled but not running?
      if((! _GN3_running) && eeprom_read_byte(&E_GN3_ENABLED)
        && eeprom_read_byte(&E_PRESENT_GN3))
        // Try to boot the guest node
        boot_GN(3);
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
      boot_GN(1);
    else if(USART_RX_char == REQUEST_REBOOT_GN2)
      boot_GN(2);
    else if(USART_RX_char == REQUEST_REBOOT_GN3)
      boot_GN(3);
  }
}



//---------- C H E C K _ E N V I R O N _ N C ----------------------------------
/*
   Reads the HTU21D sensor.

   Return TRUE: environment is acceptable.
   Return FALSE: environment is unacceptable.

   :rtype: boolean
*/
boolean check_environ_NC()
{
   // Read temperature and truncate it (so we don't deal with floats)
   latest_environ_temp_SysMon_NC = (int)SysMon_HTU21D.readTemperature();

   // Read humidity and truncate it (so we don't deal with floats)
   latest_environ_hum_SysMon_NC = (byte)SysMon_HTU21D.readHumidity();

   // Is measured temperature acceptable?
   if(((int)eeprom_read_word(&E_TEMP_MIN_NC) < latest_environ_temp_SysMon_NC)
      && (latest_environ_temp_SysMon_NC < (int)eeprom_read_word(&E_TEMP_MAX_NC))
      && (eeprom_read_byte(&E_HUMIDITY_MIN_NC) < latest_environ_hum_SysMon_NC)
      && (latest_environ_hum_SysMon_NC < eeprom_read_byte(&E_HUMIDITY_MAX_NC)))
   {
      // Exit with success
      return true;
   }

   // Exit with failure
   return false;
}



//---------- C H E C K _ E N V I R O N _ S Y S M O N --------------------------
/*
   Reads the HTU21D sensor.

   Return TRUE: environment is acceptable.
   Return FALSE: environment is unacceptable.

   :rtype: boolean
*/
boolean check_environ_SysMon()
{
   // Read temperature and truncate it (so we don't deal with floats)
   latest_environ_temp_SysMon_NC = (int)SysMon_HTU21D.readTemperature();

   // Read humidity and truncate it (so we don't deal with floats)
   latest_environ_hum_SysMon_NC = (byte)SysMon_HTU21D.readHumidity();

   // Is measured temperature acceptable?
   if(((int)eeprom_read_word(&E_TEMP_MIN_SYSMON) < latest_environ_temp_SysMon_NC)
      && (latest_environ_temp_SysMon_NC < (int)eeprom_read_word(&E_TEMP_MAX_SYSMON))
      && (eeprom_read_byte(&E_HUMIDITY_MIN_SYSMON) < latest_environ_hum_SysMon_NC)
      && (latest_environ_hum_SysMon_NC < eeprom_read_byte(&E_HUMIDITY_MAX_SYSMON)))
   {
      // Exit with success
      return true;
   }

   // Exit with failure
   return false;
}



//---------- C H E C K _ H E A R T B E A T _ O D R O I D ----------------------
/*
   Checks that the ODroid is alive and sending a heartbeat.

   Return TRUE: heartbeat is good.
   Return FALSE: heartbeat is not good.

   :param byte device: the pin number of the device being checked

   :rtype: boolean
*/
boolean check_heartbeat_odroid(byte device)
{
   boolean result = false;

   // Get first heartbeat sample
   byte sample1 = digitalRead(device);

   // Wait for half the heartbeat period
   delay(HEARTBEAT_PERIOD_ODROID / 2);

   // Get second heartbeat sample
   byte sample2 = digitalRead(device);

   // Are the samples different? (which indicates a changing heartbeat)
   if(sample1 != sample2)
      // Success!
      result = true;
   else
   {
      // Trying one more time, in case we encountered edges...

      // Wait just a bit to move past possible edges
      delay(2);

      // Get first heartbeat sample
      sample1 = digitalRead(device);

      // Wait for half the heartbeat period
      delay(HEARTBEAT_PERIOD_ODROID / 2);

      // Get second heartbeat sample
      sample2 = digitalRead(device);

      // Are the samples different? (which indicates a changing heartbeat)
      if(sample1 != sample2)
         // Success!
         result = true;
   }

   return result;
}



//---------- C H E C K _ P O W E R _ G N --------------------------------------
/*
   Reads the specified guest node's current sensor.

   Return TRUE: guest node is drawing expected current.
   Return FALSE: guest node is drawing no/too much current.

   :param byte gn: which guest node's power draw to check (1, 2 or 3)

   :rtype: boolean
*/
boolean check_power_GN(byte gn)
{
  byte msb, csb, lsb;
  int addr;

  // Which guest node is being checked?
  switch (gn) {
    case 1:
      // Assign the correct I2C address
      addr = ADDR_CURRENT_SENSOR_GN1;
      break;

    case 2:
      // Assign the correct I2C address
      addr = ADDR_CURRENT_SENSOR_GN2;
      break;

    case 3:
      // Assign the correct I2C address
      addr = ADDR_CURRENT_SENSOR_GN3;
      break;

    default:
      // Invalid guest node, so exit with failure
      return false;
  }

  // Start I2C transaction with current sensor
  Wire.beginTransmission(addr);
  // Tell sensor we want to read "data" register
  Wire.write(0);
  // Sensor expects restart condition, so end I2C transaction (no stop bit)
  Wire.endTransmission(0);
  // Ask sensor for data
  Wire.requestFrom(addr, 3);

  // Read the 3 bytes that the sensor returns
  if(Wire.available())
  {
    msb = Wire.read();
    // We only care about the data, so the mask hides the SYNC flag
    csb = Wire.read() & 0x01;
    lsb = Wire.read();
  }
  else
    // Exit with failure
    return false;

  // End I2C transaction (with stop bit)
  Wire.endTransmission(1);

  // Calculate milliamps from raw sensor data
  unsigned int milliamps = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

  // Which guest node is being checked?
  switch (gn) {
    case 1:
      // Store power reading in global variable
      latest_power_GN1 = milliamps;

      // Is measured current below allowed maximum?
      if(latest_power_GN1 < eeprom_read_word(&E_AMP_MAX_GN1))
        // Exit with success
        return true;

    case 2:
      // Store power reading in global variable
      latest_power_GN2 = milliamps;

      // Is measured current below allowed maximum?
      if(latest_power_GN2 < eeprom_read_word(&E_AMP_MAX_GN2))
        // Exit with success
        return true;

    case 3:
      // Store power reading in global variable
      latest_power_GN3 = milliamps;

      // Is measured current below allowed maximum?
      if(latest_power_GN3 < eeprom_read_word(&E_AMP_MAX_GN3))
        // Exit with success
        return true;

    default:
      // Invalid guest node, so exit with failure
      return false;
  }

  // Exit with failure
  return false;
}



//---------- C H E C K _ P O W E R _ N C --------------------------------------
/*
   Reads the node controller's current sensor.

   Return TRUE: node controller is drawing expected current.
   Return FALSE: node controller is drawing no/too much current.

   :rtype: boolean
*/
boolean check_power_NC()
{
   byte msb, csb, lsb;
   
   // Start I2C transaction with current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_NC);
   // Tell sensor we want to read "data" register
   Wire.write(0);
   // Sensor expects restart condition, so end I2C transaction (no stop bit)
   Wire.endTransmission(0);
   // Ask sensor for data
   Wire.requestFrom(ADDR_CURRENT_SENSOR_NC, 3);

   // Read the 3 bytes that the sensor returns
   if(Wire.available())
   {
      msb = Wire.read();
      // We only care about the data, so the mask hides the SYNC flag
      csb = Wire.read() & 0x01;
      lsb = Wire.read();
   }
   else
      // Exit with failure
      return false;

   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Calculate milliamps from raw sensor data
   latest_power_NC = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

   // Is measured current below allowed maximum?
   if(latest_power_NC < eeprom_read_word(&E_AMP_MAX_NC))
      // Exit with success
      return true;

   // Exit with failure
   return false;
}



//---------- C H E C K _ P O W E R _ S W I T C H ------------------------------
/*
   Reads the network switch's current sensor.

   Return TRUE: switch is drawing expected current.
   Return FALSE: switch is drawing no/too much current.

   :rtype: boolean
*/
boolean check_power_switch()
{
   byte msb, csb, lsb;
   
   // Start I2C transaction with current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_SWITCH);
   // Tell sensor we want to read "data" register
   Wire.write(0);
   // Sensor expects restart condition, so end I2C transaction (no stop bit)
   Wire.endTransmission(0);
   // Ask sensor for data
   Wire.requestFrom(ADDR_CURRENT_SENSOR_SWITCH, 3);

   // Read the 3 bytes that the sensor returns
   if(Wire.available())
   {
      msb = Wire.read();
      // We only care about the data, so the mask hides the SYNC flag
      csb = Wire.read() & 0x01;
      lsb = Wire.read();
   }
   else
      // Exit with failure
      return false;

   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Calculate milliamps from raw sensor data
   latest_power_switch = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

   // Is measured current below allowed maximum?
   if(latest_power_switch < eeprom_read_word(&E_AMP_MAX_SWITCH))
      // Exit with success
      return true;

   // Exit with failure
   return false;
}



//---------- C H E C K _ P O W E R _ S Y S M O N ------------------------------
/*
   Reads the SysMon's current sensor.

   Return TRUE: SysMon is drawing expected current.
   Return FALSE: SysMon is drawing too much current.

   :rtype: boolean
*/
boolean check_power_SysMon()
{
   byte msb, csb, lsb;
   
   // Start I2C transaction with current sensor
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_SYSMON);
   // Tell sensor we want to read "data" register
   Wire.write(0);
   // Sensor expects restart condition, so end I2C transaction (no stop bit)
   Wire.endTransmission(0);
   // Ask sensor for data
   Wire.requestFrom(ADDR_CURRENT_SENSOR_SYSMON, 3);

   // Read the 3 bytes that the sensor returns
   if(Wire.available())
   {
      msb = Wire.read();
      // We only care about the data, so the mask hides the SYNC flag
      csb = Wire.read() & 0x01;
      lsb = Wire.read();
   }
   else
      // Exit with failure
      return false;

   // End I2C transaction (with stop bit)
   Wire.endTransmission(1);

   // Calculate milliamps from raw sensor data
   latest_power_SysMon = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

   // Is measured current below allowed maximum?
   if(latest_power_SysMon < eeprom_read_word(&E_AMP_MAX_SYSMON))
      // Exit with success
      return true;

   // Exit with failure
   return false;
}



//---------- C H E C K _ T E M P _ G N ----------------------------------------
/*
   Reads the thermistor for the specified guest node.

   Return TRUE: temperature is acceptable.
   Return FALSE: temperature is unacceptable.

   :param byte gn: which guest node's temperature to check (1, 2 or 3)

   :rtype: boolean
*/
boolean check_temp_GN(byte gn)
{
  // Which guest node is being checked?
  switch (gn) {
    case 1:
      // Get ADC result from thermistor
      latest_temp_GN1 = analogRead(PIN_THERMISTOR_GN1);

      // Is measured temperature acceptable?
      if((eeprom_read_word(&E_TEMP_MIN_GN1) < latest_temp_GN1)
          && (latest_temp_GN1 < eeprom_read_word(&E_TEMP_MAX_GN1)))
      {
        // Exit with success
        return true;
      }
      else
        // Exit with failure
        return false;

    case 2:
      // Get ADC result from thermistor
      latest_temp_GN2 = analogRead(PIN_THERMISTOR_GN2);

      // Is measured temperature acceptable?
      if((eeprom_read_word(&E_TEMP_MIN_GN2) < latest_temp_GN2)
          && (latest_temp_GN2 < eeprom_read_word(&E_TEMP_MAX_GN2)))
      {
        // Exit with success
        return true;
      }
      else
        // Exit with failure
        return false;

    case 3:
      // Get ADC result from thermistor
      latest_temp_GN3 = analogRead(PIN_THERMISTOR_GN3);

      // Is measured temperature acceptable?
      if((eeprom_read_word(&E_TEMP_MIN_GN3) < latest_temp_GN3)
          && (latest_temp_GN3 < eeprom_read_word(&E_TEMP_MAX_GN3)))
      {
        // Exit with success
        return true;
      }
      else
        // Exit with failure
        return false;

    default:
      // Invalid guest node, so exit with failure
      return false;
  }
}



//---------- C H E C K _ T E M P _ N C ----------------------------------------
/*
   Reads the node controller's thermistor to determine if the processor's
   temperature is within the safe operating parameters.

   Return TRUE: temperature is safe.
   Return FALSE: temperature is unsafe.

   :rtype: boolean
*/
boolean check_temp_NC()
{
   // Read thermistor
   latest_temp_NC = analogRead(PIN_THERMISTOR_NC);

   // Is measured temperature acceptable?
   if((eeprom_read_word(&E_TEMP_MIN_PROCESSOR_NC) < latest_temp_NC)
      && (latest_temp_NC < eeprom_read_word(&E_TEMP_MAX_PROCESSOR_NC)))
   {
      // Exit with success
      return true;
   }

   // Exit with failure
   return false;
}



//---------- C H E C K _ T E M P _ S W I T C H --------------------------------
/*
   Reads the switch's thermistor to determine if the temperature is within
   the safe operating parameters.

   Return TRUE: temperature is safe.
   Return FALSE: temperature is unsafe.

   :rtype: boolean
*/
boolean check_temp_switch()
{
   // Read thermistor
   latest_temp_switch = analogRead(PIN_THERMISTOR_SWITCH);

   // Is measured temperature acceptable?
   if((eeprom_read_word(&E_TEMP_MIN_SWITCH) < latest_temp_switch)
      && (latest_temp_switch < eeprom_read_word(&E_TEMP_MAX_SWITCH)))
   {
      // Exit with success
      return true;
   }

   // Exit with failure
   return false;
}



//---------- P O W E R _ C Y C L E  -------------------------------------------
/*
   Power cycle the device specified by the argument.

   :param byte device: pin number of the relay to power cycle

   :rtype: none
*/
void power_cycle(byte device)
{
   // Turn off the device
   digitalWrite(device, LOW);
   // Wait for it...
   delay(POWER_CYCLE_DELAY);
   // Turn on the device
   digitalWrite(device, HIGH);
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