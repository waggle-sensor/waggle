#include <Arduino.h>
#line 1
#line 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
//---------- I N C L U D E S --------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/eeprom.h>
#include <Wire.h>
#include "./libs/HTU21D/HTU21D.h"
#include "./libs/Time/Time.h"
#include "./libs/MCP79412RTC/MCP79412RTC.h"
#include "./libs/SoftReset/SoftReset.h"



//---------- C O N S T A N T S ------------------------------------------------
//#define BOOT_POST
#define SERIAL_DEBUG_ON 0x01
#define POWER_ON_BOOT 0x00
#define RE_BOOT 0x01

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
// Time (ms) to give node controller to prepare for shutdown
#define NC_SHUTDOWN_DELAY 5000
// Time (ms) to give node controller to acquire the time from the internet
#define NC_TIME_ACQUIRE_DELAY 20000

// Period of SysMon's requests for updated time from NC
#define TIME_UPDATE_REQUEST_PERIOD 3600

// Special characters for interacting with the node controller
#define NC_NOTIFIER_STATUS '@'
#define NC_NOTIFIER_PROBLEM '#'
#define NC_NOTIFIER_PARAMS_CORE '$'
#define NC_NOTIFIER_PARAMS_GN '^'
#define NC_NOTIFIER_TIME_REQUEST '*'
#define NC_NOTIFIER_TIME_SEND '('
#define NC_NOTIFIER_CONFIG_DONE "="
#define NC_NOTIFIER_SHUTDOWN '?'
#define NC_DELIMITER ','
#define NC_TERMINATOR '!'

// Messages to send to node controller
#define PROBLEM_SYSMON_ENVIRON "SM,e"
#define PROBLEM_SYSMON_POWER "SM,p"
#define PROBLEM_NC_TEMP "NC,t"
#define PROBLEM_NC_ENVIRON "NC,e"
#define PROBLEM_NC_POWER "NC,p"
#define PROBLEM_NC_HEARTBEAT "NC,h"
#define PROBLEM_SWITCH_TEMP "SW,t"
#define PROBLEM_SWITCH_POWER "SW,p"
// Currently no implementation of heartbeat for switch.
// Most switches will not have a reliable source of heartbeat to tie into.
// Could use NC to emulate heartbeat for switch.
#define PROBLEM_SWITCH_HEARTBEAT "SW,h"
#define PROBLEM_GN1_TEMP "GN1,t"
#define PROBLEM_GN1_POWER "GN1,p"
#define PROBLEM_GN1_HEARTBEAT "GN1,h"
#define PROBLEM_GN2_TEMP "GN2,t"
#define PROBLEM_GN2_POWER "GN2,p"
#define PROBLEM_GN2_HEARTBEAT "GN2,h"
#define PROBLEM_GN3_TEMP "GN3,t"
#define PROBLEM_GN3_POWER "GN3,p"
#define PROBLEM_GN3_HEARTBEAT "GN3,h"

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

HTU21D SysMon_HTU21D;

boolean _NC_running = false;
boolean _switch_running = false;
boolean _GN1_running = false;
boolean _GN2_running = false;
boolean _GN3_running = false;

byte count_status_report = 0;
long count_time_update_request = 0;
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
uint16_t EEMEM E_CONFIG_TIME_NC;
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
uint8_t EEMEM E_ENVIRON_TIMEOUT_SYSMON;
uint8_t EEMEM E_ENVIRON_TIMEOUT_NC;
uint8_t EEMEM E_TEMP_PROCESSOR_TIMEOUT_NC;
uint8_t EEMEM E_TEMP_TIMEOUT_SWITCH;
uint8_t EEMEM E_TEMP_TIMEOUT_GN1;
uint8_t EEMEM E_TEMP_TIMEOUT_GN2;
uint8_t EEMEM E_TEMP_TIMEOUT_GN3;
uint8_t EEMEM E_POWER_TIMEOUT_SYSMON;
uint8_t EEMEM E_POWER_TIMEOUT_NC;
uint8_t EEMEM E_POWER_TIMEOUT_SWITCH;
uint8_t EEMEM E_POWER_TIMEOUT_GN1;
uint8_t EEMEM E_POWER_TIMEOUT_GN2;
uint8_t EEMEM E_POWER_TIMEOUT_GN3;
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
uint16_t EEMEM E_MILLIAMP_MAX_SYSMON;
uint16_t EEMEM E_MILLIAMP_MAX_NC;
uint16_t EEMEM E_MILLIAMP_MAX_SWITCH;
uint16_t EEMEM E_MILLIAMP_MAX_GN1;
uint16_t EEMEM E_MILLIAMP_MAX_GN2;
uint16_t EEMEM E_MILLIAMP_MAX_GN3;
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
 *  Call all appropriate boot routines, depending on enabled/disabled status
 *  of POST.
 *
 *  :rtype: none
 */
#line 252 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
void setup();
#line 384 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
void loop();
#line 968 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_environ_NC();
#line 1001 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_environ_SysMon();
#line 1036 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_heartbeat_odroid(byte device);
#line 1093 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_power_GN(byte gn);
#line 1202 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_power_NC();
#line 1253 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_power_switch();
#line 1304 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_power_SysMon();
#line 1357 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_temp_GN(byte gn);
#line 1424 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_temp_NC();
#line 1453 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
boolean check_temp_switch();
#line 1479 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
void get_time_NC();
#line 1510 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
void power_cycle(byte device);
#line 1530 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
void send_problem(String problem);
#line 1582 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
void send_status();
#line 1641 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
void send_time();
#line 1661 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/sysmanager.ino"
void sleep_SysMon();
#line 58 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean POST();
#line 162 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean gprf_test();
#line 309 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean stack_pointer_test();
#line 399 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean status_register_test();
#line 459 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean sram_test();
#line 540 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean watchdog_test(byte reason);
#line 582 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean ADC_test();
#line 624 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean timer1_test();
#line 740 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
boolean interrupt_test();
#line 789 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
byte find_reset_reason();
#line 822 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
void test_failure(byte reason, boolean fatal);
#line 845 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
void sleep();
#line 22 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_SOS.ino"
void boot_SOS();
#line 80 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_SOS.ino"
void init_SOS();
#line 143 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_SOS.ino"
void report_failure_POST();
#line 10 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_gn.ino"
void boot_GN(byte gn);
#line 12 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
boolean boot_primary();
#line 91 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
boolean boot_NC(void);
#line 100 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
boolean boot_NC(boolean which_type);
#line 291 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
void boot_switch();
#line 378 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
boolean boot_SysMon();
#line 423 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
void get_params_core();
#line 703 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
void get_params_GNs();
#line 906 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
void init_current_sensor(byte Which_Current_Sensor);
#line 926 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
void init_primary();
#line 1109 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
void set_default_eeprom();
#line 252
void setup()
{
    // Disable watchdog to avoid a reset loop
    wdt_disable();

    #ifdef SERIAL_DEBUG_ON
    delay(4000);
    Serial.begin(57600);
    Serial.println("S0");
    #endif

    // Is POST enabled?
    #ifdef BOOT_POST

    #ifdef SERIAL_DEBUG_ON
    Serial.println("S1");
    #endif
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
            if(num_attempts < eeprom_read_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS))
                soft_restart();
            else
            {
                // Clear the counter for number of primary boot attempts.
                // We want to start with a clean slate after reset.
                eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);

                // Give it time to write to EEPROM, just to be sure
                delay(10);

                // We're done trying, so go to sleep
                sleep_SysMon();
            }
        }
    }
    // Something non-fatal failed the POST
    else
        // Go to partial boot sequence
        boot_SOS();

    #else
    // Boot SysMon, node controller, and ethernet switch.  Boot successful?
    #ifdef SERIAL_DEBUG_ON
    Serial.println("S3");
    #endif

    if(boot_primary())
    {
        // Boot the guest nodes
        #ifdef SERIAL_DEBUG_ON
        Serial.println("S4");
        #endif
        boot_GN(1);
        boot_GN(2);
        boot_GN(3);
    }

    else
    {
        #ifdef SERIAL_DEBUG_ON
        Serial.println("S5");
        #endif


        // Grab how many boot attempts have occurred (+1 for this attempt)
        byte num_attempts = eeprom_read_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS) + 1;

        // Add failed boot attempt to the counter
        eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, num_attempts);

        // Number of boot attempts not yet reached maximum allowed?
        if(num_attempts < eeprom_read_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS))
        {
            #ifdef SERIAL_DEBUG_ON
            Serial.println(num_attempts);
            Serial.println(eeprom_read_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS));
            Serial.println("Soft Restart");
            delay(2000);
            #endif
            delay(2000);
//             soft_restart();
        }
        else
        {
            // Clear the counter for number of primary boot attempts.
            // We want to start with a clean slate after reset.
            eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);

            // Give it time to write to EEPROM, just to be sure
            delay(10);

            #ifdef SERIAL_DEBUG_ON
            Serial.println("S.");
            #endif

            // We're done trying, so go to sleep
            sleep_SysMon();
        }


    }
    #endif
}



//---------- L O O P ----------------------------------------------------------
/*
 *  Main operation of SysMon.  Monitors the system and keeps track of any
 *  timeouts, then responds appropriately to them.  Any devices that are turned
 *  off but not permanently disabled are rebooted after some time.
 *
 *  :rtype: none
 */
void loop()
{

    // Has the timer finished a cycle?
    if(_timer1_cycle)
    {
        #ifdef SERIAL_DEBUG_ON
        Serial.println("T1");
        #endif
        // Increment status report counter
        count_status_report++;

        // Increment time request counter
        count_time_update_request++;

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
        if(count_timeout_power_SysMon >= eeprom_read_byte(&E_POWER_TIMEOUT_SYSMON))
        {
            // Inform node controller of the problem
            send_problem(PROBLEM_SYSMON_POWER);

            // Clear all of SysMon's timeout counters
            count_timeout_power_SysMon = 0;
            count_timeout_environ_SysMon = 0;

            // Reboot SysMon
            soft_restart();
        }
        // Bad environment timeout for SysMon?
        else if(count_timeout_environ_SysMon >= eeprom_read_byte(&E_ENVIRON_TIMEOUT_SYSMON))
        {
            // Inform node controller of the problem
            send_problem(PROBLEM_SYSMON_ENVIRON);

            // Clear all of SysMon's timeout counters
            count_timeout_power_SysMon = 0;
            count_timeout_environ_SysMon = 0;

            // Reboot SysMon
            soft_restart();
        }


        // Is node controller operating?
        if(_NC_running)
        {
            // Bad heartbeat timeout for NC?
            if(count_timeout_heartbeat_NC >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_NC))
            {
                // Inform node controller of the problem
                send_problem(PROBLEM_NC_HEARTBEAT);

                // Clear all of NC's timeout counters
                count_timeout_power_NC = 0;
                count_timeout_temp_processor_NC = 0;
                count_timeout_environ_NC = 0;
                count_timeout_heartbeat_NC = 0;

                // Reboot the node controller
                boot_NC();
            }
            // Bad power timeout for NC?
            else if(count_timeout_power_NC >= eeprom_read_byte(&E_POWER_TIMEOUT_NC))
            {
                // Inform node controller of the problem
                send_problem(PROBLEM_NC_POWER);

                // Clear all of NC's timeout counters
                count_timeout_power_NC = 0;
                count_timeout_temp_processor_NC = 0;
                count_timeout_environ_NC = 0;
                count_timeout_heartbeat_NC = 0;

                // Reboot the node controller
                boot_NC();
            }
            // Bad environment timeout for NC?
            else if(count_timeout_environ_NC >= eeprom_read_byte(&E_ENVIRON_TIMEOUT_NC))
            {
                // Inform node controller of the problem
                send_problem(PROBLEM_NC_ENVIRON);

                // Clear all of NC's timeout counters
                count_timeout_power_NC = 0;
                count_timeout_temp_processor_NC = 0;
                count_timeout_environ_NC = 0;
                count_timeout_heartbeat_NC = 0;

                // Reboot the node controller
                boot_NC();
            }
            // Bad processor temperature timeout for NC?
            else if(count_timeout_temp_processor_NC >= eeprom_read_byte(&E_TEMP_PROCESSOR_TIMEOUT_NC))
            {
                // Inform node controller of the problem
                send_problem(PROBLEM_NC_TEMP);

                // Clear all of NC's timeout counters
                count_timeout_power_NC = 0;
                count_timeout_temp_processor_NC = 0;
                count_timeout_environ_NC = 0;
                count_timeout_heartbeat_NC = 0;

                // Reboot the node controller
                boot_NC();
            }
        }


        // Is ethernet switch operating?
        if(_switch_running)
        {
            // Bad power timeout for ethernet switch?
            if(count_timeout_power_switch >= eeprom_read_byte(&E_POWER_TIMEOUT_SWITCH))
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
            else if(count_timeout_temp_switch >= eeprom_read_byte(&E_TEMP_TIMEOUT_SWITCH))
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
            if(count_timeout_power_GN1 >= eeprom_read_byte(&E_POWER_TIMEOUT_GN1))
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
            else if(count_timeout_temp_GN1 >= eeprom_read_byte(&E_TEMP_TIMEOUT_GN1))
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
            if(count_timeout_power_GN2 >= eeprom_read_byte(&E_POWER_TIMEOUT_GN2))
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
            else if(count_timeout_temp_GN2 >= eeprom_read_byte(&E_TEMP_TIMEOUT_GN2))
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
            if(count_timeout_power_GN3 >= eeprom_read_byte(&E_POWER_TIMEOUT_GN3))
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
            else if(count_timeout_temp_GN3 >= eeprom_read_byte(&E_TEMP_TIMEOUT_GN3))
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

            // Send it
            send_status();
        }


        // Time to request updated time from NC?
        if(count_time_update_request >= TIME_UPDATE_REQUEST_PERIOD)
        {
            // Clear the counter
            count_time_update_request = 0;

            // Request time
            get_time_NC();
        }

        // Received a new serial character?
        if(Serial.available() > 0)
        {
            char incoming = Serial.read();

            // Which request was received?
            if(incoming == REQUEST_TIME)
                send_time();
            else if(incoming == REQUEST_STATUS)
                send_status();
            else if(incoming == REQUEST_REBOOT_NC)
                boot_NC();
            else if(incoming == REQUEST_REBOOT_SWITCH)
                boot_switch();
            else if(incoming == REQUEST_REBOOT_GN1)
                boot_GN(1);
            else if(incoming == REQUEST_REBOOT_GN2)
                boot_GN(2);
            else if(incoming == REQUEST_REBOOT_GN3)
                boot_GN(3);
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
            if((! _switch_running) && eeprom_read_byte(&E_SWITCH_ENABLED)
                && eeprom_read_byte(&E_PRESENT_SWITCH))
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
}



//---------- C H E C K _ E N V I R O N _ N C ----------------------------------
/*
 *  Reads the HTU21D sensor.
 *
 *  Return TRUE: environment is acceptable.
 *  Return FALSE: environment is unacceptable.
 *
 *  :rtype: boolean
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
 *  Reads the HTU21D sensor.
 *
 *  Return TRUE: environment is acceptable.
 *  Return FALSE: environment is unacceptable.
 *
 *  :rtype: boolean
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
 *  Checks that the ODroid is alive and sending a heartbeat.
 *
 *  Return TRUE: heartbeat is good.
 *  Return FALSE: heartbeat is not good.
 *
 *  :param byte device: the pin number of the device being checked
 *
 *  :rtype: boolean
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

    delay(2000);

    return result;
}



//---------- C H E C K _ P O W E R _ G N --------------------------------------
/*
 *  Reads the specified guest node's current sensor.
 *
 *  Return TRUE: guest node is drawing expected current.
 *  Return FALSE: guest node is drawing no/too much current.
 *
 *  :param byte gn: which guest node's power draw to check (1, 2 or 3)
 *
 *  :rtype: boolean
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
            if(latest_power_GN1 < eeprom_read_word(&E_MILLIAMP_MAX_GN1))
                // Exit with success
                return true;

            break;

        case 2:
            // Store power reading in global variable
            latest_power_GN2 = milliamps;

            // Is measured current below allowed maximum?
            if(latest_power_GN2 < eeprom_read_word(&E_MILLIAMP_MAX_GN2))
                // Exit with success
                return true;

            break;

        case 3:
            // Store power reading in global variable
            latest_power_GN3 = milliamps;

            // Is measured current below allowed maximum?
            if(latest_power_GN3 < eeprom_read_word(&E_MILLIAMP_MAX_GN3))
                // Exit with success
                return true;

            break;

        default:
            // Invalid guest node, so exit with failure
            return false;
    }

    // Exit with failure
    return false;
}



//---------- C H E C K _ P O W E R _ N C --------------------------------------
/*
 *  Reads the node controller's current sensor.
 *
 *  Return TRUE: node controller is drawing expected current.
 *  Return FALSE: node controller is drawing no/too much current.
 *
 *  :rtype: boolean
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
    if(latest_power_NC < eeprom_read_word(&E_MILLIAMP_MAX_NC))
        // Exit with success
        return true;

    // Exit with failure
    return false;
}



//---------- C H E C K _ P O W E R _ S W I T C H ------------------------------
/*
 *  Reads the network switch's current sensor.
 *
 *  Return TRUE: switch is drawing expected current.
 *  Return FALSE: switch is drawing no/too much current.
 *
 *  :rtype: boolean
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
    if(latest_power_switch < eeprom_read_word(&E_MILLIAMP_MAX_SWITCH))
        // Exit with success
        return true;

    // Exit with failure
    return false;
}



//---------- C H E C K _ P O W E R _ S Y S M O N ------------------------------
/*
 *  Reads the SysMon's current sensor.
 *
 *  Return TRUE: SysMon is drawing expected current.
 *  Return FALSE: SysMon is drawing too much current.
 *
 *  :rtype: boolean
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
    if(latest_power_SysMon < eeprom_read_word(&E_MILLIAMP_MAX_SYSMON))
        // Exit with success
        return true;

    // Exit with failure
    return false;
}



//---------- C H E C K _ T E M P _ G N ----------------------------------------
/*
 *  Reads the thermistor for the specified guest node.
 *
 *  Return TRUE: temperature is acceptable.
 *  Return FALSE: temperature is unacceptable.
 *
 *  :param byte gn: which guest node's temperature to check (1, 2 or 3)
 *
 *  :rtype: boolean
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
 *  Reads the node controller's thermistor to determine if the processor's
 *  temperature is within the safe operating parameters.
 *
 *  Return TRUE: temperature is safe.
 *  Return FALSE: temperature is unsafe.
 *
 *  :rtype: boolean
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
 *  Reads the switch's thermistor to determine if the temperature is within
 *  the safe operating parameters.
 *
 *  Return TRUE: temperature is safe.
 *  Return FALSE: temperature is unsafe.
 *
 *  :rtype: boolean
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



//---------- G E T _ T I M E _ N C --------------------------------------------
/*
 *  Requests a time update from the node controller.  If an update is received,
 *  the RTC is set to the new time.
 *
 *  :rtype: none
 */
void get_time_NC()
{
    // Send request
    Serial.println(NC_NOTIFIER_TIME_REQUEST);

    // Save the node controller's response into a string.
    // Default timeout value is 1 second
    String received_time = "";
    received_time = Serial.readStringUntil(NC_TERMINATOR);

    // Was time received?
    if(received_time.length() > 0)
    {
        // Convert received time (string) to a number
        unsigned long seconds_since_epoch = received_time.toInt();

        // Set RTC time
        RTC.set(seconds_since_epoch);
    }
}



//---------- P O W E R _ C Y C L E  -------------------------------------------
/*
 *  Power cycle the device specified by the argument.
 *
 *  :param byte device: pin number of the relay to power cycle
 *
 *  :rtype: none
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
 *  Sends a problem report to the node controller.
 *
 *  :param String problem: description of the problem
 *
 *  :rtype: none
 */
void send_problem(String problem)
{
    // Tell the node controller that a problem report is coming
    Serial.println(NC_NOTIFIER_PROBLEM);

    // Give it time to get ready
    delay(NC_MESSAGE_DELAY);

    // Prepend the timestamp
    problem = String(RTC.get()) + NC_DELIMITER + problem;

    // Send problem report
    Serial.println(problem);

    // Give it time to send, in case another message is going to be sent
    // right after this
    delay(NC_MESSAGE_DELAY);
}



//---------- S E N D _ S T A T U S --------------------------------------------
/*
 *  Sends a status report of all important info to the node controller.
 *
 *  Message structure:
 *  RTC time (seconds since epoch),
 *  Light level (ADC value),
 *  Current draw (SysMon) (mA),
 *  Environment temperature (SysMon & NC) (Celsius),
 *  Relative humidity (SysMon & NC) (%),
 *  Current draw (NC) (mA),
 *  Temperature of processor (NC) (ADC value),
 *  Enabled/disabled (switch),
 *  Running/not running (switch),
 *  Current draw (switch) (mA),
 *  Temperature (switch) (ADC value),
 *  Enabled/disabled (GN 1),
 *  Running/not running (GN 1),
 *  Current draw (GN 1) (mA),
 *  Temperature (GN 1) (ADC value),
 *  Enabled/disabled (GN 2),
 *  Running/not running (GN 2),
 *  Current draw (GN 2) (mA),
 *  Temperature (GN 2) (ADC value),
 *  Enabled/disabled (GN 3),
 *  Running/not running (GN 3),
 *  Current draw (GN 3) (mA),
 *  Temperature (GN 3) (ADC value)
 *
 *  :rtype: none
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
 *  Sends the RTC time to the node controller.
 *
 *  :rtype: none
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



//---------- S L E E P _ S Y S M O N ------------------------------------------
/*
 *  Puts SysMon into sleep mode.
 *
 *  :rtype: none
 */
void sleep_SysMon()
{
    // Try disabling watchdog before noInterrupts() and see if chip
    // stays asleep.
    // Disable interrupts to stop things from waking up SysMon
    // noInterrupts();

    // Go to sleep
    // sleep_mode();



    // Temporary patch until sleep is working.
    // Should disable/clear all timer registers.
    // Should disable watchdog.
    // The goal is to have minimal core activity.
    // Infinite loop with nop().
    digitalWrite(PIN_RELAY_NC, LOW);
    digitalWrite(PIN_RELAY_SWITCH, LOW);
    digitalWrite(PIN_RELAY_GN1, LOW);
    digitalWrite(PIN_RELAY_GN2, LOW);
    digitalWrite(PIN_RELAY_GN3, LOW);
    while(1);
}



//---------- T I M E R 1 _ O V E R F L O W _ I N T E R R U P T ----------------
/*
 *  Interrupt for Timer1 overflow.  Resets the watchdog and increments the
 *  counter used to tell the MCU when to check the environment.
 *
 *  :rtype: none
 */
ISR(TIMER1_OVF_vect)
{
    // Reset watchdog
    wdt_reset();

    // Set the flag to indicate a complete timer cycle
    _timer1_cycle = true;
}

#line 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/POST.ino"
//---------- C O N S T A N T S ------------------------------------------------
const byte RESET_POWER_ON = 0;
const byte RESET_EXTERNAL = 1;
const byte RESET_BROWN_OUT = 2;
const byte RESET_WATCHDOG = 3;
const byte RESET_JTAG = 4;
const byte RESET_USB = 5;

const byte FAIL_GPRF = 1;
const byte FAIL_STACK = 2;
const byte FAIL_SREG = 3;
const byte FAIL_SRAM = 4;
const byte FAIL_FLASH = 5;
const byte FAIL_WATCHDOG = 6;
const byte FAIL_ADC = 7;
const byte FAIL_TIMER1 = 8;
const byte FAIL_INTERRUPT = 9;

const boolean FATAL_GPRF = true;
const boolean FATAL_STACK = true;
const boolean FATAL_SREG = true;
const boolean FATAL_SRAM = true;
const boolean FATAL_FLASH = true;
const boolean FATAL_WATCHDOG = false;
const boolean FATAL_ADC = false;
const boolean FATAL_TIMER1 = false;
const boolean FATAL_INTERRUPT = false;

const int ADC_TEST_THRESHOLD = 512;



//---------- G L O B A L S ----------------------------------------------------
boolean _SOS_boot_mode = false;
boolean _watchdog_good = false;
volatile boolean _external_interrupt = false;



//---------- P O S T ----------------------------------------------------------
/*
   Power on self test.  This subroutine calls the tests to verify correct
   operation of the MCU.  Nothing external to the MCU is tested here.

   If everything is working correctly, this function will return true.
   If a fatal failure occurs, the MCU will sleep, thus preventing the rest of
   the MCU's program from running. If a non-fatal failure occurs, the function
   will return false.  Failures will (attempt to) be recorded into EEPROM.

   Note: This POST is not perfect.  There is some redundancy and a few
   assumptions are made, so do not rely solely on this for mission-critical
   applications.

   Adapted from Atmel Application Note AVR998 (c) 2006 Atmel.

   :rtype: boolean
*/
boolean POST() 
{
  // Find reason for reset
  byte reason = find_reset_reason();

  // Disable watchdog so it doesn't reset the chip before we're ready
  wdt_disable();

  Serial.begin(57600);

  delay(1000);

  // General Purpose Register File failed?
	if(!gprf_test())
		test_failure(FAIL_GPRF, FATAL_GPRF);

  Serial.println("GPRF");
  delay(5);

	// Stack pointer failed?
	if(!stack_pointer_test())
		test_failure(FAIL_STACK, FATAL_STACK);

  Serial.println("stack");
  delay(5);

	// Status register (SREG) test failed?
	if(!status_register_test())
		test_failure(FAIL_SREG, FATAL_SREG);

  Serial.println("SREG");
  delay(5);

	// SRAM test failed?
	if(!sram_test())
		test_failure(FAIL_SRAM, FATAL_SRAM);

  Serial.println("SRAM");
  delay(5);

	// Flash test failed?
	//if(!flash_test())
		//test_failure(FAIL_FLASH, FATAL_FLASH);

	// Watchdog test failed?
	if(!watchdog_test(reason))
		test_failure(FAIL_WATCHDOG, FATAL_WATCHDOG);
  else
    // Mark watchdog as functional (used to test the timer)
    _watchdog_good = true;

  Serial.println("watchdog");
  delay(5);

  // ADC test failed?
  if(!ADC_test())
    test_failure(FAIL_ADC, FATAL_ADC);

  Serial.println("ADC");
  delay(5);

  // Timer1 test failed?
  if(!timer1_test())
    test_failure(FAIL_TIMER1, FATAL_TIMER1);

  Serial.println("Timer");
  delay(5);

  // Interrupt controller test failed?
  if(!interrupt_test())
    test_failure(FAIL_INTERRUPT, FATAL_INTERRUPT);

  Serial.println("interrupt");
  delay(5);

  // Did anything non-fatal fail?
  if(_SOS_boot_mode)
  {
    Serial.println("SOS");
    delay(10);
    // Exit test with failure
    return false;
  }

  // Exit test with success
  return true;
}



//---------- G P R F _ T E S T ------------------------------------------------
/*
	 Checks the General Purpose Register File (R31 - R0) for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
	 setting compiler flags is not an option.  The "optimize(0)" attribute is 
	 used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

	 :rtype: boolean
*/
__attribute__((optimize(0))) boolean gprf_test()
{
	boolean result;

	// This is done in assembly because we're pretty close to metal here.
	// Each register (R31 - R0) has 0x55 and 0xAA written to and read from it, 
	// to verify that there aren't any stuck bits.
	asm volatile(
		// ZH register
		"R31_0x55_TST:                             \n\t"
    "							ldi   R31, 0x55              \n\t"
    "             cpi   R31, 0x55              \n\t"
    "             breq  R31_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R31_0xAA_TST:  													 \n\t"
    "							ldi   R31, 0xAA              \n\t"
    "             cpi   R31, 0xAA              \n\t"
    "             breq  R30_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    // ZL register
    "R30_0x55_TST:                             \n\t"
    "							ldi   R30, 0x55              \n\t"
    "             cpi   R30, 0x55              \n\t"
    "             breq  R30_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R30_0xAA_TST:  													 \n\t"
    "							ldi   R30, 0xAA              \n\t"
    "             cpi   R30, 0xAA              \n\t"
    "             breq  R29_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    
    // YH register
    "R29_0x55_TST:                             \n\t"
    "							mov   R31, R29     ; save R29\n\t"
    "							ldi   R29, 0x55              \n\t"
    "             cpi   R29, 0x55              \n\t"
    "             breq  R29_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R29_0xAA_TST:  													 \n\t"
    "							ldi   R29, 0xAA              \n\t"
    "             cpi   R29, 0xAA              \n\t"
    "             breq  R29_END_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R29_END_TST: 														 \n\t"
    "							mov   R29, R31  ; restore R29\n\t"
    // YL register
    "R28_0x55_TST:                             \n\t"
    "							mov   R31, R28     ; save R28\n\t"
    "							ldi   R28, 0x55              \n\t"
    "             cpi   R28, 0x55              \n\t"
    "             breq  R28_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R28_0xAA_TST:  													 \n\t"
    "							ldi   R28, 0xAA              \n\t"
    "             cpi   R28, 0xAA              \n\t"
    "             breq  R28_END_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R28_END_TST: 														 \n\t"
    "							mov   R28, R31  ; restore R28\n\t"
    
    // XH register
    "R27_0x55_TST:                             \n\t"
    "							ldi   R27, 0x55              \n\t"
    "             cpi   R27, 0x55              \n\t"
    "             breq  R27_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R27_0xAA_TST:  													 \n\t"
    "							ldi   R27, 0xAA              \n\t"
    "             cpi   R27, 0xAA              \n\t"
    "             breq  R26_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    // XL register
    "R26_0x55_TST:                             \n\t"
    "							ldi   R26, 0x55              \n\t"
    "             cpi   R26, 0x55              \n\t"
    "             breq  R26_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R26_0xAA_TST:  													 \n\t"
    "							ldi   R26, 0xAA              \n\t"
    "             cpi   R26, 0xAA              \n\t"
    "             breq  RX_TST                 \n\t"
    "							jmp   Fail_GPRF              \n\t"

    // R25 - R0
    "RX_TST:     															 \n\t"   
    "							ldi   R30, 0x00    ; clear ZL\n\t"
    "             ldi   R31, 0x00    ; clear ZH\n\t"
    "RX_0x55_TST:   													 \n\t"
    "							ldi   R25, 0x55              \n\t"
    "             st    Z, R25                 \n\t"
    "             ldi   R25, 0x00              \n\t"
    "             ld    R25, Z                 \n\t"
    "             cpi   R25, 0x55              \n\t"
    "             breq  RX_0xAA_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "RX_0xAA_TST:   													 \n\t"
    "							ldi   R25, 0xAA              \n\t"
    "             ST    Z, R25                 \n\t"
    "             ldi   R25, 0x00              \n\t"
    "             ld    R25, Z+                \n\t"
    "             cpi   R25, 0xAA              \n\t"
    "             breq  RX_TST_2               \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "RX_TST_2:      													 \n\t"
    "							cpi   r30, 25; test until R25\n\t"
    "             brne  RX_0x55_TST            \n\t"
    "							clr   r1 ; R1 must be cleared\n\t"
    "							jmp   Pass_GPRF 						 \n\t"
  );

	// Test failure
  asm volatile(
    "Fail_GPRF:																 \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_GPRF:                                \n\t"
	);
	result = true;

  // Is the result TRUE?
	if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- S T A C K _ P O I N T E R _ T E S T ------------------------------
/*
	 Checks the stack pointer for stuck bits.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

	 :rtype: boolean
*/
__attribute__((optimize(0))) boolean stack_pointer_test()
{
	boolean result;

	// This is done in assembly because we're pretty close to metal here.
	// Each register (SPL & SPH) has 0x55 and 0xAA written to and read from it,
	// to verify that there aren't any stuck bits.
	asm volatile(
		"SP_TST:																	 \n\t"
			// Save stack pointer   
			"						in    R23, 0x3E              \n\t"
      "           in    R22, 0x3D              \n\t"

      // SPL register
      "SPL_0x55_TST:  												 \n\t"
      "						ldi   R24, 0x55              \n\t"
      "           out   0x3D, R24              \n\t"
      "           in    R24, 0x3D              \n\t"
      "           cpi   R24, 0x55              \n\t"
      "           breq  SPL_0xAA_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      "SPL_0xAA_TST:  												 \n\t"
      "						ldi   R24, 0xAA              \n\t"
      "           out   0x3D, R24              \n\t"
      "           in    R24, 0x3D              \n\t"
      "           cpi   R24, 0xAA              \n\t"
      "           breq  SPH_0x55_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      // SPH register
      "SPH_0x55_TST:  												 \n\t"
      "						ldi   R25, 0x07			         \n\t"
      "           andi  R25, 0x55              \n\t"
      "           out   0x3E, R25              \n\t"
      "           in    R24, 0x3E              \n\t"
      "           cp    R24, R25               \n\t"
      "           breq  SPH_0xAA_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      "SPH_0xAA_TST:  												 \n\t"
      "						ldi   R25, 0x07              \n\t"
      "           andi  R25, 0xAA              \n\t"
      "           out   0x3E, R25              \n\t"
      "           in    R24, 0x3E              \n\t"
      "           cp    R24, R25               \n\t"
      "           breq  RESTORE_SP             \n\t"
      "           jmp   Fail_SP                \n\t"

      // Restore stack pointer
      "RESTORE_SP:    												 \n\t"
      "						out   0x3E, R23              \n\t"
      "           out   0x3D, R22              \n\t"
      "           jmp   Pass_SP                \n\t"
  );

	// Test failure
  asm volatile(
    "Fail_SP:																   \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_SP:																   \n\t"
	);
	result = true;

	// Is the result TRUE?
  if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- S T A T U S _ R E G I S T E R _ T E S T --------------------------
/*
   Checks the status register (SREG) for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean status_register_test() 
{
	byte read_sreg, save_sreg;

	// Save current state of SREG
	save_sreg = SREG;

	// Write value to SREG
	SREG = 0x55;

	// Read value in SREG
	read_sreg = SREG;

	// Restore original state of SREG
	SREG = save_sreg;

	// Is the value read from SREG not the expected value?
	if(read_sreg != 0x55)
		// Exit test with failure
		return false;
	else
	{
		// Save current state of SREG
		save_sreg = SREG;

		// Write value to SREG
		SREG = 0xAA;

		// Read value in SREG
		read_sreg = SREG;

		// Restore original state of SREG
		SREG = save_sreg;

		// Is the value read from SREG the expected value?
		if(read_sreg == 0xAA)
			// Exit test with success
			return true;
		else
			// Exit test with failure
			return false;
	}
}



//---------- S R A M _ T E S T ------------------------------------------------
/*
   Checks the SRAM for stuck bits.
   Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean sram_test()
{
  boolean result;
  
  // This is done in assembly because we're pretty close to metal here.
  // Each RAM address (0x0100 - 0x0AFF) has 0x55 and 0xAA written to and read from it, 
  // to verify that there aren't any stuck bits.
  asm volatile(
    "LD_INITS:                                 \n\t"
    "             ldi   R31, 0x01              \n\t"
    "             ldi   R30, 0x00              \n\t"
    "             ldi   R28, 0x55              \n\t"
    "             ldi   R29, 0xAA              \n\t"
    "CHECK_DONE:                               \n\t"
                  // Compare ZH to 0x0A
    "             cpi   R31, 0x0A              \n\t"
    "             brne  LOOP                   \n\t"
                  // Compare ZL to 0xFF
    "             cpi   R30, 0xFF              \n\t"
                  // If both match, test complete
    "             breq  Pass_RAM               \n\t"
    "LOOP:                                     \n\t"
                  // Temp store contents in R26
    "             ld    R26, Z                 \n\t"
                  // Store 0x55 at RAM location
    "             st    Z, R28                 \n\t"
                  // Read to confirm 0x55
    "             ld    R27, Z                 \n\t"
    "             cpi   R27, 0x55              \n\t" 
                  // If equal, continue to 0xAA Test
    "             brne  Fail_RAM               \n\t"
                  // Store 0xAA at RAM location
    "             st    Z, R29                 \n\t"
                  // Read to confirm 0xAA
    "             ld    R27, Z                 \n\t"
                  // Place old contents back in, increment addr
    "             st    Z+, R26                \n\t"
    "             cpi   R27, 0xAA              \n\t" 
    "             brne  Fail_RAM               \n\t"
                  // If equal, continue to next iteration
    "             jmp   CHECK_DONE             \n\t"
  );

  // Test failure
  asm volatile(
    "Fail_RAM:                                 \n\t"
  );
  result = false;

  // Test success
  asm volatile(
    "Pass_RAM:                                 \n\t"
  );
  result = true;

  // Is the result TRUE?
  if(result)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- W A T C H D O G _ T E S T ----------------------------------------
/*
	 Checks the reason for reset.  If it was a watchdog reset, we move on.
	 If it wasn't, enable the watchdog and wait.
	 Return of TRUE means it passed the test.
	 Return of FALSE means it failed the test.

	 This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean watchdog_test(byte reason)
{
  Serial.println(reason);
  delay(100);

  // Was reset not due to watchdog?
  //if((reason & RESET_WATCHDOG) != RESET_WATCHDOG)
  if(reason != RESET_WATCHDOG)
  {
    Serial.println("not watchdog reset");
    wdt_enable(WDTO_8S);
    Serial.println("enabled");
    delay(9000);
    Serial.println("watchdog did not reset");
    return false;
  }

  //if((reason & RESET_WATCHDOG) == RESET_WATCHDOG)
  if(reason == RESET_WATCHDOG)
  {
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);
  }
  return true;
}



//---------- A D C _ T E S T --------------------------------------------------
/*
   Checks that the ADC is functioning correctly.
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean ADC_test()
{
  // Set AREF to the ATmega's internal reference
  analogReference(INTERNAL);

  // Wait, then read ADC a few times to let things settle down.
  // ATmega32U4 datasheet recommends this.
  delay(50);
  analogRead(INTERNAL);
  analogRead(INTERNAL);
  analogRead(INTERNAL);

  // Read ADC with INTERNAL as input
  int value = analogRead(INTERNAL);

  // Is the reported ADC value close enough?
  // Theoretically, the value should be 1023 (10-bit conversion)
  if(value > ADC_TEST_THRESHOLD)
    // Exit test with success
    return true;
  else
    // Exit test with failure
    return false;
}



//---------- T I M E R 1 _ T E S T --------------------------------------------
/*
   Checks all registers for stuck bits and lets the timer overflow, which
   tests the timer and the interrupt (thus, the interrupt controller, too).
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean timer1_test()
{
  // Disable interrupts (since we're fiddling with interrupt controls)
  noInterrupts();

  /* These comments apply to all register tests in this function */
  // Load first test value
  TCCR1A = 0x55;
  // Is the register not storing the test value?
  // See datasheet for unused bits
  if((TCCR1A & 0x55) != 0x55)
    // Exit test with failure
    return false;
  // Load second test value
  TCCR1A = 0xAA;
  // Is the register not storing the test value?
  // See datasheet for unused bits
  if((TCCR1A & 0xAA) != 0xAA)
    // Exit test with failure
    return false;
  // Reset the register
  TCCR1A = 0;

  TCCR1B = 0x55;
  if((TCCR1B & 0x55) != 0x55)
    return false;
  TCCR1B = 0xAA;
  if((TCCR1B & 0xAA) != 0x8A)
    return false;
  TCCR1B = 0;

  TCNT1 = 0x5555;
  if((TCNT1 & 0x5555) != 0x5555)
    return false;
  TCNT1 = 0xAAAA;
  if((TCNT1 & 0xAAAA) != 0xAAAA)
    return false;
  TCNT1 = 0;

  OCR1A = 0x5555;
  if((OCR1A & 0x5555) != 0x5555)
    return false;
  OCR1A = 0xAAAA;
  if((OCR1A & 0xAAAA) != 0xAAAA)
    return false;
  OCR1A = 0;

  TIMSK1 = 0x55;
  if((TIMSK1 & 0x55) != 0x05)
    return false;
  TIMSK1 = 0xAA;
  if((TIMSK1 & 0xAA) != 0x2A)
    return false;
  TIMSK1 = 0;

  // Enable interrupts
  interrupts();

  // Did we arrive here after a watchdog reset due to a bad timer?
  if(eeprom_read_byte(&E_TIMER_TEST_INCOMPLETE))
    // Exit test with failure
    return false;

  // Did watchdog pass its test?
  // If it did not, we have no reliable way to test the timer without failure
  // resulting in an infinite loop.  An infinite loop prevents us from
  // getting to the partial boot sequence, so if the watchdog is bad, we'll
  // have to trust that the timer works, without this explicit test.
  if(_watchdog_good)
  {
    // Mark timer test as incomplete
    eeprom_update_byte(&E_TIMER_TEST_INCOMPLETE, 1);

    // Enable watchdog
    wdt_enable(WDTO_60MS);

    // Start timer (with prescaler of clk/8)
    TCCR1B = (1 << CS11);

    // Wait for counter to overflow
    while(! (TIFR1 & _BV(TOV1)));

    // Disable watchdog
    wdt_disable();

    // Clear the clock prescaling (this turns off the timer)
    TCCR1B = 0;
    // Clear the timer's counter
    TCNT1 = 0;
    // Clear the overflow flag
    TIFR1 = _BV(TOV1);

    // Mark timer test as complete
    eeprom_update_byte(&E_TIMER_TEST_INCOMPLETE, 0);
  }

  // Exit test with success
  return true;
}



//---------- I N T E R R U P T _ T E S T --------------------------------------
/*
   Checks that the interrupt controller executes interrupt service routines.
   Return of TRUE means it passed the test.
   Return of FALSE means it failed the test.

   This code is designed to work in the default Arduino environment, so 
   setting compiler flags is not an option.  The "optimize(0)" attribute is 
   used to prevent the compiler from optimizing this function.  All of the
   tests in the POST routine disable optimization, to be safe, because much
   of what is happening has no effect outside the function.

   :rtype: boolean
*/
__attribute__((optimize(0))) boolean interrupt_test()
{
  // Set pin INT0 to output (to enable software control of interrupt)
  pinMode(INT0, OUTPUT);

  // Enable INT0 interrupt.  Without setting any bits in EICRA, the default
  // is for an interrupt to trigger when the pin is low.
  EIMSK |= _BV(INT0);

  // Trigger the interrupt
  digitalWrite(INT0, LOW);

  // Give the pin time to change state (if necessary)
  delay(1);

  // Did the interrupt fire?
  if(_external_interrupt)
    // Exit with success
    return true;
  else
    // Exit with failure
    return false;
}



//---------- E X T E R N A L _ I N T 0 _ I N T E R R U P T --------------------
/*
   Interrupt for external interrupt INT0.

   :rtype: none
*/
ISR(INT0_vect)
{
  // Disable INT0 interrupt
  EIMSK = 0;

  // Set flag to indicate that the ISR executed
  _external_interrupt = true;
}



//---------- F I N D _ R E S E T _ R E A S O N --------------------------------
/*
   Reads the MCU status register (MCUSR) for the reset flag.

   :rtype: byte
*/
byte find_reset_reason()
{
	byte i;
	byte mask = 0x01;

	// Check bits 0-5 in MCUSR
	for(i = 0; i < 6; i++)
	{
    // Is the current bit set?
		if(MCUSR & mask)
			// Found the reset flag, so exit the loop
			break;

		// Shift the mask left by 1
		mask <<= 1;
	}

  // Clear MCUSR
  MCUSR = 0;

	// Return the reset reason
	return i;	
}



//---------- T E S T _ F A I L U R E ------------------------------------------
/*
	 Saves the reason for POST failure into EEPROM and aborts/modifies boot-up.

	 :param byte reason: reason for POST failure
	 :param boolean fatal: POST failure is/not fatal
*/
void test_failure(byte reason, boolean fatal)
{
	// Save POST failure to EEPROM
	eeprom_update_byte(&E_POST_RESULT, reason);

	// Allow time for EEPROM to finish writing
	delay(5);

	// Is POST failure fatal?
	if(fatal)
		// Go to sleep
		sleep();
	else
		// Set flag for SOS boot mode
    _SOS_boot_mode = true;
}



//---------- S L E E P --------------------------------------------------------
/*
	 Puts Atmel chip to sleep (power-down mode).
*/
void sleep()
{
	// Disable interrupts so nothing weird happens
	noInterrupts();

	// Set power-down mode to draw the least amount of power possible
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);

	// Enable sleep
	sleep_enable();

	// Go to sleep
	sleep_mode();

	// Chew on this until the chip falls asleep
	while(1);
}
#line 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_SOS.ino"
//---------- C O N S T A N T S ------------------------------------------------
const byte NO_WATCHDOG = 1;
const byte NO_TIMER = 2;
const byte NO_ADC = 3;
const byte NO_INTERRUPT = 4;



//---------- G L O B A L S ----------------------------------------------------
byte SOS_mode;



//---------- B O O T _ S O S --------------------------------------------------
/*
   If a non-critical internal component failed the POST, this subroutine 
   attempts to boot enough to let the node controller inform the cloud there
   is a problem.

   :rtype: none
*/
void boot_SOS()
{
	// // Initialize/start internal components
	// init_SOS();

	// // Check that SysMon is drawing an expected amount of power
	// check_power_self();

	// // Check that the SysMon's environment is suitable.
	// // If the check fails, it could be the environment or the I2C
	// check_environ_self();

	// // Get datum about number of times SOS boot mode has been tried
	// byte num_tries = eeprom_read_byte(&E_NUM_SOS_BOOT_ATTEMPTS);

	// // Has SOS boot been tried too many times?
	// if(num_tries >= eeprom_read_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS))
	// 	// Something isn't working, so go to sleep
	// 	sleep();

	// // Record that SOS boot mode was attempted
	// eeprom_update_byte(&E_NUM_SOS_BOOT_ATTEMPTS, ++num_tries);

	// // ADC ok?
	// if(SOS_mode != NO_ADC)
	// 	// Check that the node controller's environment is suitable
	// 	check_environ_nc();
	// // ADC not ok?
	// else if(SOS_mode == NO_ADC)
	// 	// This is here as notice that proceeding without ADC introduces some
	// 	// risk to the node controller, since its environ. can't be measured.
	// 	asm("nop");

	// // Is the node controller not enabled?
	// if(!eeprom_read_byte(&E_NC_ENABLED))
	// 	// Nothing for us to do, so go to sleep
	// 	sleep();

	// // Enable power to node controller

	// // Check that the node controller is drawing an expected amount of power
	// check_power_nc();

	// // Check that the node controller is alive (sending a "heartbeat")
	// check_heartbeat_nc();

	// // Report the POST failure to the node controller
	// report_failure_POST();
}



//---------- I N I T _ S O S --------------------------------------------------
/*
   Initializes/starts all necessary ports, peripherals, interrupts, etc.

   :rtype: none
*/
void init_SOS()
{
 //  // What is the cause of the POST failure?
	// switch (eeprom_read_byte(&E_POST_RESULT)) {
	//     case FAIL_WATCHDOG:
	//       SOS_mode = NO_WATCHDOG;
	//       break;
	//     case FAIL_TIMER1:
	//       SOS_mode = NO_TIMER;
	//       break;
	//     case FAIL_ADC:
	//     	SOS_mode = NO_ADC;
	//     	break;
	//     case FAIL_INTERRUPT:
	//     	SOS_mode = NO_INTERRUPT;
	//     	break;
	//     // This shouldn't happen, but just in case...
	//     default:
	//       sleep();
	// }

	// // Watchdog, timer, and interrupts ok?
	// if((SOS_mode != NO_WATCHDOG) && (SOS_mode != NO_TIMER) && 
	// 	(SOS_mode != NO_INTERRUPT))
	// 	// Enable watchdog with 2 second timeout
	// 	wdt_enable(WDTO_2S);
	// // Watchdog, timer, or interrupts not ok?
	// else
	// 	// This is here as notice that proceeding without the watchdog introduces
	// 	// the risk of SysMon hanging forever.
	// 	asm("nop");

	// // Timer ok?
	// if(SOS_mode != NO_TIMER)
	// {
	// 	// Interrupts ok?
	// 	if(SOS_mode != NO_INTERRUPT)
	// 		// Enable Timer1 overflow interrupt
	// 		TIMSK1 |= _BV(TOIE1);

	// 	// Start Timer1 with prescaler of clk/256 (timeout of approx. 1 second)
	// 	TCCR1B |= _BV(CS12);
	// }

	// // Join I2C bus as master.
	// // We're hoping I2C works, because we don't currently have a way to test it
	// Wire.begin();

	// // Enable serial comms.
	// // We're hoping UART works, because we don't currently have a way to test it
 //  Serial.begin(eeprom_read_dword(&E_USART_BAUD));
}



//---------- R E P O R T _ F A I L U R E _ P O S T ----------------------------
/*
   Sends info about the POST failure to the node controller, waits for
   the node controller to send failure info to the cloud (or until timeout),
   then goes to sleep

   :rtype: none
*/
void report_failure_POST()
{

}
#line 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_gn.ino"
//---------- B O O T _ G N ----------------------------------------------------
/*
   Boots guest node.  Checks temperature, power draw, and heartbeat.
   If something goes wrong, the node controller is notified.

   :param byte gn: which guest node to boot (1, 2, or 3)

   :rtype: none
*/
void boot_GN(byte gn)
{
  byte pin_relay, pin_heartbeat;
  String problem_temp, problem_power, problem_heartbeat;
  byte *enabled, *present;
  unsigned int *boot_time;

  // Which guest node is being booted?
  switch (gn) {
    case 1:
      // Mark guest node as not operational
      _GN1_running = false;

      // Assign variables for this guest node
      pin_relay = PIN_RELAY_GN1;
      pin_heartbeat = PIN_HEARTBEAT_GN1;
      problem_temp = PROBLEM_GN1_TEMP;
      problem_power = PROBLEM_GN1_POWER;
      problem_heartbeat = PROBLEM_GN1_HEARTBEAT;
      enabled = &E_GN1_ENABLED;
      present = &E_PRESENT_GN1;
      boot_time = &E_BOOT_TIME_GN1;

      break;
    case 2:
      // Mark guest node as not operational
      _GN2_running = false;

      // Assign variables for this guest node
      pin_relay = PIN_RELAY_GN2;
      pin_heartbeat = PIN_HEARTBEAT_GN2;
      problem_temp = PROBLEM_GN2_TEMP;
      problem_power = PROBLEM_GN2_POWER;
      problem_heartbeat = PROBLEM_GN2_HEARTBEAT;
      enabled = &E_GN2_ENABLED;
      present = &E_PRESENT_GN2;
      boot_time = &E_BOOT_TIME_GN2;
      
      break;
    case 3:
      // Mark guest node as not operational
      _GN3_running = false;

      // Assign variables for this guest node
      pin_relay = PIN_RELAY_GN3;
      pin_heartbeat = PIN_HEARTBEAT_GN3;
      problem_temp = PROBLEM_GN3_TEMP;
      problem_power = PROBLEM_GN3_POWER;
      problem_heartbeat = PROBLEM_GN3_HEARTBEAT;
      enabled = &E_GN3_ENABLED;
      present = &E_PRESENT_GN3;
      boot_time = &E_BOOT_TIME_GN3;
      
      break;
    // Invalid guest node
    default:
      return;
  }

  // Make sure the device is off
  digitalWrite(pin_relay, LOW);

  // Give the device time to rest
  delay(POWER_CYCLE_DELAY);

  // Is guest node enabled and expected to be present?
  if(eeprom_read_byte(enabled) && eeprom_read_byte(present))
  {
    // Is the guest node's temperature outside of safe parameters?
    if(!check_temp_GN(gn))
    {
      // Giving the guest node one more chance...

      // Wait for things to settle down, perhaps
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

      // Is the guest node's temperature outside of safe parameters?
      if(!check_temp_GN(gn))
      {
        // Inform node controller of failure
        send_problem(problem_temp);

        // Exit with failure
        return;
      }
    }

    // Turn on the guest node
    digitalWrite(pin_relay, HIGH);

    // Give the guest node time to boot
    delay((long)eeprom_read_word(boot_time) * 1000L);

    // Is the guest node not drawing an expected amount of power?
    if(!check_power_GN(gn))
    {
      // Giving the guest node one more chance...

      // Power cycle the guest node
      power_cycle(pin_relay);

      // Give the guest node time to boot
      delay((long)eeprom_read_word(boot_time) * 1000L);

      // Is the guest node not drawing an expected amount of power?
      if(!check_power_GN(gn))
      {
        // Turn off the guest node
        digitalWrite(pin_relay, LOW);

        // Inform node controller of failure
        send_problem(problem_power);

        // Mark GN as dead
        eeprom_update_byte(enabled, 0);

        // Exit with failure
        return;
      }
    }

    // Is the guest node alive (sending a heartbeat)?
    if(!check_heartbeat_odroid(pin_heartbeat))
    {
      // Start at 1 boot attempt, since we had to boot to get here
      byte boot_attempts = 1;
      boolean _heartbeat_detected = false;

      // Try to get a heartbeat from the GN as many times as allowed
      while (boot_attempts < eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
        // Is heartbeat not detected?
        if(!check_heartbeat_odroid(pin_heartbeat))
        {
          // Power cycle the guest node
          power_cycle(pin_relay);

          // Give the guest node time to boot
          delay((long)eeprom_read_word(boot_time) * 1000L);
        }
        else
          // Indicate that a heartbeat was detected
          _heartbeat_detected = true;

        // Increment counter for number of attempts
        boot_attempts++;
      }

      // Still no heartbeat detected?
      if(!_heartbeat_detected)
      {
        // Turn off the guest node
        digitalWrite(pin_relay, LOW);

        // Inform node controller of failure
        send_problem(problem_heartbeat);

        // Exit with failure
        return;
      }
    }

    // Which guest node is being booted?
    switch (gn) {
      case 1:
        // Mark guest node as operational
        _GN1_running = true;

        break;
      case 2:
        // Mark guest node as operational
        _GN2_running = true;
        
        break;
      case 3:
        // Mark guest node as operational
        _GN3_running = true;
        
        break;
      // Invalid guest node
      default:
        return;
    }
  }
}
#line 1 "/media/rajesh/Bharadwaja/github/waggle/wagman/manager/sysmanager/boot_primary.ino"
//---------- B O O T _ P R I M A R Y ------------------------------------------
/*
 *  Starts/initializes/boots self, node controller, and ethernet switch.
 *  Conditions for and operation of the node controller and ethernet switch are
 *  verified before completing boot sequence.
 *
 *  Return TRUE: boot procedure executed successfully.
 *  Return FALSE: boot procedure failed.
 *
 *  :rtype: boolean
 */
boolean boot_primary()
{
    // Initialize/start internal components
    #ifdef SERIAL_DEBUG_ON
    Serial.println("BP0");
    #endif

    init_primary();

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BP1");
    #endif

    // Is this the first ever boot?
    if(eeprom_read_byte(&E_FIRST_BOOT) != 0)
        // Assign default parameters
        set_default_eeprom();

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BP2");
    #endif

    // Booted SysMon successfully?
    if(!boot_SysMon())
        // Skip the rest of the boot sequence

        return false;

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BP3");
    #endif

    // Booted node controller successfully?
    if(!boot_NC())
        // Skip the rest of the boot sequence
        return false;


    #ifdef SERIAL_DEBUG_ON
    Serial.println("BP4");
    #endif

    // Give node controller the chance to acquire the time from the internet
    delay(NC_TIME_ACQUIRE_DELAY);

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BP5");
    #endif

    // Request time from node controller
    get_time_NC();

    // Request operating parameters from node controller
    get_params_core();

    // Request guest node parameters from node controller
    get_params_GNs();

    // Boot ethernet switch
    boot_switch();

    // Everything is good, so exit sequence with success
    return true;
}



//---------- B O O T _ N C ----------------------------------------------------
/*
 *   Boots the node controller.  Checks environment, power draw, and heartbeat.
 *
 *   This function is overloaded, with the default type being POWER_ON_BOOT.
 *
 *   Return TRUE: everything is good, boot successful.
 *   Return FALSE: something went wrong, boot unsuccessful.
 *
 *   :rtype: boolean
 */

boolean boot_NC(void)
{
    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC0");
    #endif
    return boot_NC(POWER_ON_BOOT);
}


boolean boot_NC(boolean which_type)
{

    if (which_type == RE_BOOT)
    {
        #ifdef SERIAL_DEBUG_ON
        Serial.println("BNC1");
        #endif
    // Tell NC that it is about to be shut down, in case this is a reboot
    Serial.println(NC_NOTIFIER_SHUTDOWN);
    // Give it time to shut down properly
    delay((long)NC_SHUTDOWN_DELAY);

    // Turn NC off (disable the relay)
    digitalWrite(PIN_RELAY_NC, LOW);

    // Give the device time to rest
    delay(POWER_CYCLE_DELAY);

    // Mark NC as not operational
    _NC_running = false;

    }

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC2");
    #endif

    // Is the node controller not enabled?
    if(!eeprom_read_byte(&E_NC_ENABLED))
        // Exit with failure
        return false;

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC3");
    #endif

    // Is the node controller's environment not suitable?
    if(!check_environ_NC())
    {
        // Giving the node controller one more chance...

        // Wait for things to settle down, perhaps
        delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

        // Is the node controller's environment not suitable?
        if(!check_environ_NC())
            // Exit with failure
            return false;
    }

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC4");
    #endif

    // Is the node controller's processor temperature not suitable?
    if(!check_temp_NC())
    {
        // Giving the node controller one more chance...
        #ifdef SERIAL_DEBUG_ON
        Serial.println("BNC4.1");
        #endif
        // Wait for things to settle down, perhaps
        delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

        // Is the node controller's environment not suitable?
        if(!check_temp_NC())
            #ifdef SERIAL_DEBUG_ON
            Serial.println("BNC4.2");
            #endif
            // Exit with failure
            return false;
    }


    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC5");
    #endif

    // Enable power to node controller
    digitalWrite(PIN_RELAY_NC, HIGH);

    // Give NC time to be configured, in case this is a new NC...

    // Set serial receive timeout to time specified by parameter
//     Serial.setTimeout((long)eeprom_read_word(&E_CONFIG_TIME_NC) * 1000L);
    // Wait for notification from NC that it is configured for WagMan
    String config_WagMan = Serial.readStringUntil(NC_TERMINATOR);
    // Return serial receive timeout to default (1000 ms)
    Serial.setTimeout(1000L);
    // Did NC fail to notify us that it is configured?

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC6");
    #endif

    if(config_WagMan != NC_NOTIFIER_CONFIG_DONE)
        // Exit with failure
        return false;

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC7");
    #endif

    // Is the node controller not drawing an expected amount of power?
    if(!check_power_NC())
    {
        // Giving the node controller one more chance...

        // Power cycle the node controller
        power_cycle(PIN_RELAY_NC);

        // Give the node controller time to boot
        delay((long)eeprom_read_word(&E_BOOT_TIME_NC) * 1000L);

        // Is the node controller not drawing an expected amount of power?
        if(!check_power_NC())
        {
            // Turn off the node controller
            digitalWrite(PIN_RELAY_NC, LOW);

            // Mark NC as dead
            eeprom_update_byte(&E_NC_ENABLED, 0);

            // Exit with failure
            return false;
        }
    }

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC8");
    #endif

    // Is the node controller alive (sending a heartbeat)?
    if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
    {
        // Start at 1 boot attempt, since we had to boot to get here
        byte boot_attempts = 1;
        boolean _heartbeat_detected = false;

        // Try to get a heartbeat from the NC as many times as allowed
        while(boot_attempts < eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
        {
            // Is heartbeat not detected?
            if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
            {
                // Power cycle the node controller
                power_cycle(PIN_RELAY_NC);

                // Give the node controller time to boot
                delay((long)eeprom_read_word(&E_BOOT_TIME_NC) * 1000L);
            }
            else
                // Indicate that a heartbeat was detected
                _heartbeat_detected = true;

            // Increment counter for number of attempts
            boot_attempts++;
        }

        // Still no heartbeat detected?
        if(!_heartbeat_detected)
        {
            // Turn off the node controller
            digitalWrite(PIN_RELAY_NC, LOW);

            // Exit with failure
            return false;
        }
    }

    #ifdef SERIAL_DEBUG_ON
    Serial.println("BNC9");
    #endif

    // Mark NC as operational
    _NC_running = true;

    // Exit with success
    return true;
}



//---------- B O O T _ S W I T C H --------------------------------------------
/*
 *   Boots the ethernet switch.  Checks environment and power draw.
 *   If something goes wrong, the node controller is notified.
 *
 *   :rtype: none
 */
void boot_switch()
{
    // Mark switch as not operational
    _switch_running = false;

    // Make sure the device is off
    digitalWrite(PIN_RELAY_SWITCH, LOW);

    // Give the device time to rest
    delay(POWER_CYCLE_DELAY);

    // Is the ethernet switch disabled or not present?
    if(!(eeprom_read_byte(&E_SWITCH_ENABLED)
        && eeprom_read_byte(&E_PRESENT_SWITCH)))
    {
        // Exit with failure
        return;
    }

    // Is the ethernet switch's temperature outside of safe parameters?
    if(!check_temp_switch())
    {
        // Giving the switch one more chance...

        // Wait for things to settle down, perhaps
        delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

        // Is the ethernet switch's temperature outside of safe parameters?
        if(!check_temp_switch())
        {
            // Inform node controller of failure
            send_problem(PROBLEM_SWITCH_TEMP);

            // Exit with failure
            return;
        }
    }

    // Enable power to ethernet switch
    digitalWrite(PIN_RELAY_SWITCH, HIGH);

    // Give the ethernet switch time to boot
    delay((long)eeprom_read_byte(&E_BOOT_TIME_SWITCH) * 1000L);

    // Is the ethernet switch not drawing an expected amount of power?
    if(!check_power_switch())
    {
        // Giving the ethernet switch one more chance...

        // Power cycle the switch
        power_cycle(PIN_RELAY_SWITCH);

        // Give the switch time to boot
        delay((long)eeprom_read_byte(&E_BOOT_TIME_SWITCH) * 1000L);

        // Is the ethernet switch not drawing an expected amount of power?
        if(!check_power_switch())
        {
            // Turn off the switch
            digitalWrite(PIN_RELAY_SWITCH, LOW);

            // Inform node controller of failure
            send_problem(PROBLEM_SWITCH_POWER);

            // Mark switch as dead
            eeprom_update_byte(&E_SWITCH_ENABLED, 0);

            // Exit with failure
            return;
        }
    }

    // Mark switch as operational
    _switch_running = true;
}



//---------- B O O T _ S Y S M O N --------------------------------------------
/*
 *   Checks environment and power draw for SysMon.
 *
 *   Return TRUE: everything is good.
 *   Return FALSE: environment/power draw is unacceptable.
 *
 *   :rtype: boolean
 */
boolean boot_SysMon()
{
    // Is SysMon drawing too much power?
    if(!check_power_SysMon())
    {
        // Giving SysMon one more chance...

        // Wait for things to settle down, perhaps
        delay((long)BOOT_BAD_POWER_WAIT_TIME * 1000L);

        // Is SysMon drawing too much power?
        if(!check_power_SysMon())
            // Exit with failure
            return false;
    }

    // Is SysMon's environment outside of safe bounds?
    if(!check_environ_SysMon())
    {
        // Giving SysMon one more chance...

        // Wait for things to settle down, perhaps
        delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

        // Is SysMon's environment outside of safe bounds?
        if(!check_environ_SysMon())
            // Exit with failure
            return false;
    }

    // Exit with success
    return true;
}



//---------- G E T _ P A R A M S _ C O R E ------------------------------------
/*
 *  Request operating parameters from the node controller.  If parameters are
 *  different than what is already stored, the parameter is updated.  If the
 *  parameters are the same or not received, the previously stored values will
 *  be used.
 *
 *  :rtype: none
 */
void get_params_core()
{
    // Send request
    Serial.println(NC_NOTIFIER_PARAMS_CORE);

    // Save the node controller's response into a string.
    // Default timeout value is 1 second
    String received_params = "";
    received_params = Serial.readStringUntil(NC_TERMINATOR);

    // Were parameters received?
    if(received_params.length() > 0)
    {
        /* Order of parameters (coming from node controller):
         *
         *        USART baud rate
         *        USART RX buffer size
         *        Period at which status reports are sent to node controller
         *        Max number of SOS boot attempts
         *        Max number of subsystem boot attempts
         *        Max number of primary boot attempts
         *        Time to wait before trying to reboot non-running devices
         *        Present/not present (switch)
         *        Node controller boot time
         *        Node controller first-time configuration time
         *        Ethernet switch boot time
         *        Heartbeat timeout (node controller)
         *        Heartbeat timeout (switch)
         *        Environment timeout (system monitor)
         *        Environment timeout (node controller)
         *        Processor temperature timeout (node controller)
         *        Temperature timeout (switch)
         *        Power timeout (system monitor)
         *        Power timeout (node controller)
         *        Power timeout (switch)
         *        Minimum temperature of environment (Celsius) (system monitor)
         *        Maximum temperature of environment (Celsius) (system monitor)
         *        Minimum temperature of environment (Celsius) (node controller)
         *        Maximum temperature of environment (Celsius) (node controller)
         *        Minimum temperature of processor (Celsius) (node controller)
         *        Maximum temperature of processor (Celsius) (node controller)
         *        Minimum temperature (Celsius) (switch)
         *        Maximum temperature (Celsius) (switch)
         *        Minimum relative humidity (%) (system monitor)
         *        Maximum relative humidity (%) (system monitor)
         *        Minimum relative humidity (%) (NC)
         *        Maximum relative humidity (%) (NC)
         *        Maximum amp draw (mA) (system monitor)
         *        Maximum amp draw (mA) (node controller)
         *        Maximum amp draw (mA) (switch)
         */

        // Temporary strings for holding each parameter
        String USART_baud = "";
        String USART_RX_buffer_size = "";
        String status_report_period = "";
        String max_num_SOS_boot_attempts = "";
        String max_num_subsystem_boot_attempts = "";
        String max_num_primary_boot_attempts = "";
        String device_reboot_period = "";
        String present_switch = "";
        String NC_boot_time = "";
        String NC_config_time = "";
        String switch_boot_time = "";
        String heartbeat_timeout_NC = "";
        String heartbeat_timeout_switch = "";
        String environ_timeout_SysMon = "";
        String environ_timeout_NC = "";
        String temp_processor_timeout_NC = "";
        String temp_timeout_switch = "";
        String power_timeout_SysMon = "";
        String power_timeout_NC = "";
        String power_timeout_switch = "";
        String min_temp_SysMon = "";
        String max_temp_SysMon = "";
        String min_temp_NC = "";
        String max_temp_NC = "";
        String min_temp_processor_NC = "";
        String max_temp_processor_NC = "";
        String min_temp_switch = "";
        String max_temp_switch = "";
        String min_humidity_SysMon = "";
        String max_humidity_SysMon = "";
        String min_humidity_NC = "";
        String max_humidity_NC = "";
        String max_amp_SysMon = "";
        String max_amp_NC = "";
        String max_amp_switch = "";

        // Index for iterating thru the received string
        int i = 0;

        // Parse the received list of parameters:
        while(received_params[i] != NC_DELIMITER)
            USART_baud += received_params[i++];
        // Skip delimiter
        i++;

        while(received_params[i] != NC_DELIMITER)
            USART_RX_buffer_size += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            status_report_period += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_num_SOS_boot_attempts += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_num_subsystem_boot_attempts += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_num_primary_boot_attempts += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            device_reboot_period += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            present_switch += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            NC_boot_time += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            NC_config_time += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            switch_boot_time += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            heartbeat_timeout_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            heartbeat_timeout_switch += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            environ_timeout_SysMon += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            environ_timeout_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            temp_processor_timeout_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            temp_timeout_switch += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            power_timeout_SysMon += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            power_timeout_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            power_timeout_switch += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_temp_SysMon += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_temp_SysMon += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_temp_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_temp_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_temp_processor_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_temp_processor_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_temp_switch += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_temp_switch += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_humidity_SysMon += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_humidity_SysMon += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_humidity_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_humidity_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_amp_SysMon += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_amp_NC += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_amp_switch += received_params[i++];

        // Store new parameters in EEPROM
        eeprom_update_dword(&E_USART_BAUD, USART_baud.toInt());
        eeprom_update_word(&E_USART_RX_BUFFER_SIZE, (uint16_t)USART_RX_buffer_size.toInt());
        eeprom_update_byte(&E_STATUS_REPORT_PERIOD, (uint8_t)status_report_period.toInt());
        eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, (uint8_t)max_num_SOS_boot_attempts.toInt());
        eeprom_update_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS, (uint8_t)max_num_subsystem_boot_attempts.toInt());
        eeprom_update_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS, (uint8_t)max_num_primary_boot_attempts.toInt());
        eeprom_update_word(&E_DEVICE_REBOOT_PERIOD, (uint16_t)device_reboot_period.toInt());
        eeprom_update_byte(&E_PRESENT_SWITCH, (uint8_t)present_switch.toInt());
        eeprom_update_word(&E_BOOT_TIME_NC, (uint16_t)NC_boot_time.toInt());
        eeprom_update_word(&E_CONFIG_TIME_NC, (uint16_t)NC_config_time.toInt());
        eeprom_update_byte(&E_BOOT_TIME_SWITCH, (uint8_t)switch_boot_time.toInt());
        eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, (uint8_t)heartbeat_timeout_NC.toInt());
        eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, (uint8_t)heartbeat_timeout_switch.toInt());
        eeprom_update_byte(&E_ENVIRON_TIMEOUT_SYSMON, (uint8_t)environ_timeout_SysMon.toInt());
        eeprom_update_byte(&E_ENVIRON_TIMEOUT_NC, (uint8_t)environ_timeout_NC.toInt());
        eeprom_update_byte(&E_TEMP_PROCESSOR_TIMEOUT_NC, (uint8_t)temp_processor_timeout_NC.toInt());
        eeprom_update_byte(&E_TEMP_TIMEOUT_SWITCH, (uint8_t)temp_timeout_switch.toInt());
        eeprom_update_byte(&E_POWER_TIMEOUT_SYSMON, (uint8_t)power_timeout_SysMon.toInt());
        eeprom_update_byte(&E_POWER_TIMEOUT_NC, (uint8_t)power_timeout_NC.toInt());
        eeprom_update_byte(&E_POWER_TIMEOUT_SWITCH, (uint8_t)power_timeout_switch.toInt());
        eeprom_update_word(&E_TEMP_MIN_SYSMON, (uint16_t)min_temp_SysMon.toInt());
        eeprom_update_word(&E_TEMP_MAX_SYSMON, (uint16_t)max_temp_SysMon.toInt());
        eeprom_update_word(&E_TEMP_MIN_NC, (uint16_t)min_temp_NC.toInt());
        eeprom_update_word(&E_TEMP_MAX_NC, (uint16_t)max_temp_NC.toInt());
        eeprom_update_word(&E_TEMP_MIN_PROCESSOR_NC, (uint16_t)min_temp_processor_NC.toInt());
        eeprom_update_word(&E_TEMP_MAX_PROCESSOR_NC, (uint16_t)max_temp_processor_NC.toInt());
        eeprom_update_word(&E_TEMP_MIN_SWITCH, (uint16_t)min_temp_switch.toInt());
        eeprom_update_word(&E_TEMP_MAX_SWITCH, (uint16_t)max_temp_switch.toInt());
        eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, (uint8_t)min_humidity_SysMon.toInt());
        eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, (uint8_t)max_humidity_SysMon.toInt());
        eeprom_update_byte(&E_HUMIDITY_MIN_NC, (uint8_t)min_humidity_NC.toInt());
        eeprom_update_byte(&E_HUMIDITY_MAX_NC, (uint8_t)max_humidity_NC.toInt());
        eeprom_update_word(&E_MILLIAMP_MAX_SYSMON, (uint16_t)max_amp_SysMon.toInt());
        eeprom_update_word(&E_MILLIAMP_MAX_NC, (uint16_t)max_amp_NC.toInt());
        eeprom_update_word(&E_MILLIAMP_MAX_SWITCH, (uint16_t)max_amp_switch.toInt());
    }
}



//---------- G E T _ P A R A M S _ G N S --------------------------------------
/*
 *  Requests information about the guest nodes from the node controller.
 *
 *  :rtype: none
 */
void get_params_GNs()
{
    // Send request
    Serial.println(NC_NOTIFIER_PARAMS_GN);

    // Save the node controller's response into a string.
    // Default timeout value is 1 second
    String received_params = "";
    received_params = Serial.readStringUntil(NC_TERMINATOR);

    // Were parameters received?
    if(received_params.length() > 0)
    {
        /* Order of parameters (coming from node controller):
         *
         *        Present/not present (guest node 1)
         *        Present/not present (guest node 2)
         *        Present/not present (guest node 3)
         *        Boot time (guest node 1) (seconds)
         *        Boot time (guest node 2) (seconds)
         *        Boot time (guest node 3) (seconds)
         *        Heartbeat timeout (guest node 1)
         *        Heartbeat timeout (guest node 2)
         *        Heartbeat timeout (guest node 3)
         *        Temperature timeout (guest node 1)
         *        Temperature timeout (guest node 2)
         *        Temperature timeout (guest node 3)
         *        Power timeout (guest node 1)
         *        Power timeout (guest node 2)
         *        Power timeout (guest node 3)
         *        Minimum temperature (Celsius) (guest node 1)
         *        Maximum temperature (Celsius) (guest node 1)
         *        Minimum temperature (Celsius) (guest node 2)
         *        Maximum temperature (Celsius) (guest node 2)
         *        Minimum temperature (Celsius) (guest node 3)
         *        Maximum temperature (Celsius) (guest node 3)
         *        Maximum amp draw (mA) (guest node 1)
         *        Maximum amp draw (mA) (guest node 2)
         *        Maximum amp draw (mA) (guest node 3)
         */

        // Temporary strings for holding each parameter
        String present_GN1 = "";
        String present_GN2 = "";
        String present_GN3 = "";
        String boot_time_GN1 = "";
        String boot_time_GN2 = "";
        String boot_time_GN3 = "";
        String heartbeat_timeout_GN1 = "";
        String heartbeat_timeout_GN2 = "";
        String heartbeat_timeout_GN3 = "";
        String temp_timeout_GN1 = "";
        String temp_timeout_GN2 = "";
        String temp_timeout_GN3 = "";
        String power_timeout_GN1 = "";
        String power_timeout_GN2 = "";
        String power_timeout_GN3 = "";
        String min_temp_GN1 = "";
        String max_temp_GN1 = "";
        String min_temp_GN2 = "";
        String max_temp_GN2 = "";
        String min_temp_GN3 = "";
        String max_temp_GN3 = "";
        String max_amp_GN1 = "";
        String max_amp_GN2 = "";
        String max_amp_GN3 = "";

        // Index for iterating thru the received string
        int i = 0;

        // Parse the received list of parameters:
        while(received_params[i] != NC_DELIMITER)
            present_GN1 += received_params[i++];
        // Skip delimiter
        i++;

        while(received_params[i] != NC_DELIMITER)
            present_GN2 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            present_GN3 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            boot_time_GN1 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            boot_time_GN2 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            boot_time_GN3 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            heartbeat_timeout_GN1 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            heartbeat_timeout_GN2 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            heartbeat_timeout_GN3 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            temp_timeout_GN1 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            temp_timeout_GN2 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            temp_timeout_GN3 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            power_timeout_GN1 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            power_timeout_GN2 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            power_timeout_GN3 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_temp_GN1 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_temp_GN1 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_temp_GN2 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_temp_GN2 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            min_temp_GN3 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_temp_GN3 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_amp_GN1 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_amp_GN2 += received_params[i++];
        i++;

        while(received_params[i] != NC_DELIMITER)
            max_amp_GN3 += received_params[i++];

        // Store new parameters in EEPROM
        eeprom_update_byte(&E_PRESENT_GN1, (uint8_t)present_GN1.toInt());
        eeprom_update_byte(&E_PRESENT_GN2, (uint8_t)present_GN2.toInt());
        eeprom_update_byte(&E_PRESENT_GN3, (uint8_t)present_GN3.toInt());
        eeprom_update_word(&E_BOOT_TIME_GN1, (uint16_t)boot_time_GN1.toInt());
        eeprom_update_word(&E_BOOT_TIME_GN2, (uint16_t)boot_time_GN2.toInt());
        eeprom_update_word(&E_BOOT_TIME_GN3, (uint16_t)boot_time_GN3.toInt());
        eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, (uint8_t)heartbeat_timeout_GN1.toInt());
        eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, (uint8_t)heartbeat_timeout_GN2.toInt());
        eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, (uint8_t)heartbeat_timeout_GN3.toInt());
        eeprom_update_byte(&E_TEMP_TIMEOUT_GN1, (uint8_t)temp_timeout_GN1.toInt());
        eeprom_update_byte(&E_TEMP_TIMEOUT_GN2, (uint8_t)temp_timeout_GN2.toInt());
        eeprom_update_byte(&E_TEMP_TIMEOUT_GN3, (uint8_t)temp_timeout_GN3.toInt());
        eeprom_update_byte(&E_POWER_TIMEOUT_GN1, (uint8_t)power_timeout_GN1.toInt());
        eeprom_update_byte(&E_POWER_TIMEOUT_GN2, (uint8_t)power_timeout_GN2.toInt());
        eeprom_update_byte(&E_POWER_TIMEOUT_GN3, (uint8_t)power_timeout_GN3.toInt());
        eeprom_update_word(&E_TEMP_MIN_GN1, (uint16_t)min_temp_GN1.toInt());
        eeprom_update_word(&E_TEMP_MAX_GN1, (uint16_t)max_temp_GN1.toInt());
        eeprom_update_word(&E_TEMP_MIN_GN2, (uint16_t)min_temp_GN2.toInt());
        eeprom_update_word(&E_TEMP_MAX_GN2, (uint16_t)max_temp_GN2.toInt());
        eeprom_update_word(&E_TEMP_MIN_GN3, (uint16_t)min_temp_GN3.toInt());
        eeprom_update_word(&E_TEMP_MAX_GN3, (uint16_t)max_temp_GN3.toInt());
        eeprom_update_word(&E_MILLIAMP_MAX_GN1, (uint16_t)max_amp_GN1.toInt());
        eeprom_update_word(&E_MILLIAMP_MAX_GN2, (uint16_t)max_amp_GN2.toInt());
        eeprom_update_word(&E_MILLIAMP_MAX_GN3, (uint16_t)max_amp_GN3.toInt());
    }
}

//---------- I N I T _ C U R R E N T _ S E N S O R ------------------------------------------
/*
 *  Initializes the appropriate current sensor with the correct gain value.
 *
 *  :rtype: none
 */


void  init_current_sensor(byte Which_Current_Sensor)
{
    // Start I2C transaction with switch's current sensor
    Wire.beginTransmission(Which_Current_Sensor);
    // Tell sensor we're writing to "gain" register
    Wire.write(0x04);
    // Write 3 expected bytes to "gain" register (select 8 amp range)
    Wire.write(0x00);
    Wire.write(0x00);
    Wire.write(0x02);
    // End I2C transaction (with stop bit)
    Wire.endTransmission(1);
}

//---------- I N I T _ P R I M A R Y ------------------------------------------
/*
 *  Initializes/starts all necessary ports, peripherals, interrupts, etc.
 *
 *  :rtype: none
 */
void init_primary()
{
    #ifdef SERIAL_DEBUG_ON
    Serial.println("Booting Primary...");
    #endif
    // Enable interrupts
    interrupts();

    // Set sleep mode to "power down" (turns off all clocks).
    // See datasheet and sleep.h file.
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    // Start watchdog with 2 second timeout
    wdt_enable(WDTO_2S);
    #ifdef SERIAL_DEBUG_ON
    Serial.println("WD enabled to 2 Seconds...");
    #endif
    // Make sure all the Timer1 registers are cleared
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1C = 0;
    TCNT1 = 0;
    OCR1A = 0;
    OCR1B = 0;
    OCR1C = 0;
    ICR1 = 0;
    TIMSK1 = 0;

    // Enable Timer1 overflow interrupt
    TIMSK1 = _BV(TOIE1);

    // Start Timer1 with prescaler of clk/256 (timeout of approx. 1 second)
    TCCR1B = _BV(CS12);

    // Join I2C bus as master
    Wire.begin();

    // Enable serial comms
    Serial.begin(eeprom_read_dword(&E_USART_BAUD));
    #ifdef SERIAL_DEBUG_ON
    Serial.println("Serial Communication Enabled...");
    #endif

    // Clear POST result to avoid confusion if a future boot fails
    eeprom_update_byte(&E_POST_RESULT, 0);

    // Clear the number of SOS boot attempts to start with a clean slate
    // for the next partial boot failure
    eeprom_update_byte(&E_NUM_SOS_BOOT_ATTEMPTS, 0);

    // Clear the number of primary boot attempts to start with a clean slate
    // for the next boot failure
//     eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);

    // Clear the flag for the timer test being incomplete, otherwise the next
    // POST may incorrectly mark the timer as malfunctioning
    eeprom_update_byte(&E_TIMER_TEST_INCOMPLETE, 0);

    // Set ADC reference voltage to Vcc
    analogReference(DEFAULT);

    // Read ADC channels to settle them down

    analogRead(PIN_PHOTOCELL);
    analogRead(PIN_THERMISTOR_NC);
    analogRead(PIN_THERMISTOR_SWITCH);
    analogRead(PIN_THERMISTOR_GN1);
    analogRead(PIN_THERMISTOR_GN2);
    analogRead(PIN_THERMISTOR_GN3);

    // Start HTU21D
    SysMon_HTU21D.begin();

    init_current_sensor(ADDR_CURRENT_SENSOR_SYSMON);
    init_current_sensor(ADDR_CURRENT_SENSOR_NC);
    init_current_sensor(ADDR_CURRENT_SENSOR_SWITCH);
    init_current_sensor(ADDR_CURRENT_SENSOR_GN1);
    init_current_sensor(ADDR_CURRENT_SENSOR_GN2);
    init_current_sensor(ADDR_CURRENT_SENSOR_GN3);


//     // Start I2C transaction with SysMon's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_SYSMON);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with NC's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_NC);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with switch's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_SWITCH);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with GN1's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN1);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with GN2's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN2);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);
//
//     // Start I2C transaction with GN3's current sensor
//     Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN3);
//     // Tell sensor we're writing to "gain" register
//     Wire.write(0x04);
//     // Write 3 expected bytes to "gain" register (select 8 amp range)
//     Wire.write(0x00);
//     Wire.write(0x00);
//     Wire.write(0x02);
//     // End I2C transaction (with stop bit)
//     Wire.endTransmission(1);

    // Give relays time to settle down, in case there was a chip reset
//     delay(POWER_CYCLE_DELAY);

    // Set relay pins to output mode
    pinMode(PIN_RELAY_NC, OUTPUT);
    pinMode(PIN_RELAY_SWITCH, OUTPUT);
    pinMode(PIN_RELAY_GN1, OUTPUT);
    pinMode(PIN_RELAY_GN2, OUTPUT);
    pinMode(PIN_RELAY_GN3, OUTPUT);

    // Set heartbeat pins to input mode (just for clarity)
    pinMode(PIN_HEARTBEAT_NC, INPUT);
    pinMode(PIN_HEARTBEAT_SWITCH, INPUT);
    pinMode(PIN_HEARTBEAT_GN1, INPUT);
    pinMode(PIN_HEARTBEAT_GN2, INPUT);
    pinMode(PIN_HEARTBEAT_GN3, INPUT);

    #ifdef SERIAL_DEBUG_ON
    Serial.println("Finished the boot sequence ... I have not powered ON anything yet...");
    #endif
}



//---------- S E T _ D E F A U L T _ E E P R O M ------------------------------
/*
 *   Assigns default values to the parameters stored in EEPROM.  This function
 *   is only executed on the first boot of a new SysMon, to avoid writing to
 *   EEPROM every time.
 *
 *   Note: EEPROM only stores raw data, meaning no data types.  If you want to
 *   store a negative number, you'll have to store it as the two's complement
 *   value, then type cast it when you're reading it.
 *
 *   :rtype: none
 */
void set_default_eeprom()
{
    // EEPROM addresses whose values are set by node controller:
    eeprom_update_dword(&E_USART_BAUD, 57600);
    eeprom_update_word(&E_USART_RX_BUFFER_SIZE, 200);
    eeprom_update_byte(&E_STATUS_REPORT_PERIOD, 30);
    eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, 5);
    eeprom_update_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS, 5);
    eeprom_update_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS, 5);
    eeprom_update_word(&E_DEVICE_REBOOT_PERIOD, 60);
    eeprom_update_byte(&E_PRESENT_SWITCH, 0);
    eeprom_update_word(&E_BOOT_TIME_NC, 40);
    eeprom_update_word(&E_CONFIG_TIME_NC, 180);
    eeprom_update_byte(&E_BOOT_TIME_SWITCH, 15);
    eeprom_update_word(&E_BOOT_TIME_GN1, 10);
    eeprom_update_word(&E_BOOT_TIME_GN2, 10);
    eeprom_update_word(&E_BOOT_TIME_GN3, 10);
    eeprom_update_byte(&E_PRESENT_GN1, 0);
    eeprom_update_byte(&E_PRESENT_GN2, 0);
    eeprom_update_byte(&E_PRESENT_GN3, 0);
    eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, 5);
    eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, 5);
    eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, 5);
    eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, 5);
    eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, 5);
    eeprom_update_byte(&E_ENVIRON_TIMEOUT_SYSMON, 5);
    eeprom_update_byte(&E_ENVIRON_TIMEOUT_NC, 5);
    eeprom_update_byte(&E_TEMP_PROCESSOR_TIMEOUT_NC, 5);
    eeprom_update_byte(&E_TEMP_TIMEOUT_SWITCH, 5);
    eeprom_update_byte(&E_TEMP_TIMEOUT_GN1, 5);
    eeprom_update_byte(&E_TEMP_TIMEOUT_GN2, 5);
    eeprom_update_byte(&E_TEMP_TIMEOUT_GN3, 5);
    eeprom_update_byte(&E_POWER_TIMEOUT_SYSMON, 5);
    eeprom_update_byte(&E_POWER_TIMEOUT_NC, 5);
    eeprom_update_byte(&E_POWER_TIMEOUT_SWITCH, 5);
    eeprom_update_byte(&E_POWER_TIMEOUT_GN1, 5);
    eeprom_update_byte(&E_POWER_TIMEOUT_GN2, 5);
    eeprom_update_byte(&E_POWER_TIMEOUT_GN3, 5);
    eeprom_update_word(&E_TEMP_MIN_SYSMON, 0);
    eeprom_update_word(&E_TEMP_MAX_SYSMON, 100);
    eeprom_update_word(&E_TEMP_MIN_NC, 0);
    eeprom_update_word(&E_TEMP_MAX_NC, 100);
    // Temperatures below are ADC values (see WagMan.py on node controller)
    eeprom_update_word(&E_TEMP_MIN_PROCESSOR_NC, 115);
    eeprom_update_word(&E_TEMP_MAX_PROCESSOR_NC, 969);
    eeprom_update_word(&E_TEMP_MIN_SWITCH, 417);
    eeprom_update_word(&E_TEMP_MAX_SWITCH, 969);
    eeprom_update_word(&E_TEMP_MIN_GN1, 417);
    eeprom_update_word(&E_TEMP_MAX_GN1, 969);
    eeprom_update_word(&E_TEMP_MIN_GN2, 417);
    eeprom_update_word(&E_TEMP_MAX_GN2, 969);
    eeprom_update_word(&E_TEMP_MIN_GN3, 417);
    eeprom_update_word(&E_TEMP_MAX_GN3, 969);
    eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, 0);
    eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, 100);
    eeprom_update_byte(&E_HUMIDITY_MIN_NC, 0);
    eeprom_update_byte(&E_HUMIDITY_MAX_NC, 100);
    eeprom_update_word(&E_MILLIAMP_MAX_SYSMON, 5000);
    eeprom_update_word(&E_MILLIAMP_MAX_NC, 2500);
    eeprom_update_word(&E_MILLIAMP_MAX_SWITCH, 1500);
    eeprom_update_word(&E_MILLIAMP_MAX_GN1, 1500);
    eeprom_update_word(&E_MILLIAMP_MAX_GN2, 1500);
    eeprom_update_word(&E_MILLIAMP_MAX_GN3, 1500);

    // Save the indicator that this SysMon has booted before
    eeprom_update_byte(&E_FIRST_BOOT, 0);

    // Clear the counter for number of primary boot attempts
    eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);
}

