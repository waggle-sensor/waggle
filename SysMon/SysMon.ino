//---------- I N C L U D E S --------------------------------------------------
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <EEPROM.h>



//---------- C O N S T A N T S ------------------------------------------------
const byte LED = 13;



//---------- S E T U P --------------------------------------------------------
void setup() 
{
  delay(5000);
  Serial.begin(115200);
  POST();
}



//---------- L O O P ----------------------------------------------------------
void loop() 
{

}
