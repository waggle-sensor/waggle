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
  wdt_disable();
  Serial.begin(115200);
  delay(8000);
  pinMode(LED, OUTPUT);
  POST();
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{

}
