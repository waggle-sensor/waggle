//---------- I N C L U D E S --------------------------------------------------
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <EEPROM.h>



//---------- C O N S T A N T S ------------------------------------------------
const byte LED = 13;



//---------- S E T U P --------------------------------------------------------
void setup() 
{
  // Start serial comms @ 115200 bps
  Serial.begin(115200);

  // Set LED pin to output so we can turn on the LED
  pinMode(LED, OUTPUT);
  
  // Power on self test
  POST();

  // Debug
  Serial.println("POST done");
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{

}
