#include <EEPROM.h>

int numSensors = 19;

void setup() {
  // put your setup code here, to run once:
  EEPROM.write(0,0);        // Set testing bit so POST starts from beginning on startup
  for(int i = 1; i<=numSensors; i++)
      EEPROM.write(i+128, 0xFF);    // Give all sensors history of passing
}

void loop() {
  // put your main code here, to run repeatedly:

}