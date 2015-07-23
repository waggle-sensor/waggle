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
#define PIN_RELAY2 7

#define PIN_HEARTBEAT2 6

#define PIN_PHOTOCELL A5
#define PIN_THERMISTOR1 A4

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
uint32_t EEMEM E_USART_BAUD;
uint16_t EEMEM E_USART_RX_BUFFER_SIZE;
uint8_t EEMEM E_MAX_NUM_SOS_BOOT_TRIES;
uint8_t EEMEM E_PRESENT_GN1;
uint8_t EEMEM E_PRESENT_GN2;
uint8_t EEMEM E_PRESENT_GN3;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_NC;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_SWITCH;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN1;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN2;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN3;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_SYSMON;
uint8_t EEMEM E_BAD_TEMP_TIMEOUT_NC;
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
uint8_t EEMEM E_NUM_SOS_BOOT_TRIES;
uint8_t EEMEM E_FIRST_BOOT;



//---------- S E T U P --------------------------------------------------------
void setup() 
{
  // Debug
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

  if(boot_primary())
    Serial.println("booted");

  setTime(23, 31, 30, 13, 2, 2009);
  RTC.set(now());
  Serial.println(RTC.get());
}


byte x = 0;
//---------- L O O P ----------------------------------------------------------
void loop() 
{
  // Has the timer finished a cycle?
  if(_timer1_cycle)
  {
    Serial.print("RTC: ");
    Serial.println(RTC.get());
    // Serial.print("HTU21D: ");
    // Serial.print(SysMon_HTU21D.readTemperature());
    // Serial.print(", ");
    // Serial.println(SysMon_HTU21D.readHumidity()); 

    // Clear the flag
    _timer1_cycle = false;

    // Environ. checks go here

    // Send status report to node controller
    send_status();

    // Send problem report to node controller
    //send_problem();

    // Check heartbeat of guest node 2
    check_heartbeat(2);
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
                  String(analogRead(PIN_THERMISTOR1));

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



//---------- C H E C K _ H E A R T B E A T ------------------------------------
/*
   Checks that the device specified by the argument is alive.

   :rtype: boolean
*/
boolean check_heartbeat(byte device)
{
  static byte count2 = 0;

  // Which device is being checked?
  switch (device) {
      case 1:
        break;

      case 2:
        // Is heartbeat detected?
        if(digitalRead(PIN_HEARTBEAT2) == LOW)
        {
          Serial.println("Heartbeat 2 not detected");

          // Increment counter
          count2++;

          // Is the counter equal to the heartbeat timeout for GN2?
          if(count2 == eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_GN2))
          {
            // Power cycle the device
            digitalWrite(PIN_RELAY2, LOW);
            delay(50);
            digitalWrite(PIN_RELAY2, HIGH);

            // Reset the counter
            count2 = 0;
          }
        }
        break;

      case 3:
        break;

      case 4:
        break;

      case 5:
        break;

      // Invalid device
      default:
        break;
  }
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