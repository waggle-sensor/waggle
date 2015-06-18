/****************************
 * GetLocalTemperature
 *  An example sketch that prints the
 *  local temperature to the PC's serial port
 *
 *  Tested with the TMP421-Breakout
 *  Temperature Sensor from Modern Device
 *****************************/
#include "Wire.h"
#include <LibTempTMP421.h>

LibTempTMP421 temp = LibTempTMP421(0);

void setup() {


    /************ The LibTemp421 library turns on Arduino pins A2, A3 (aka 16, 17) to power the sensor.
    This is necessary due to the fact that Wire.begin() is called in the constructor and needs to be 
    talk to the chip, which needs to be powered. If you are using the sensor in a differnt location
    and powering it from dedicated GND and +5V lines then include the lines below to reset the 
    A2 & A3 pins for use as analog inputs. */

//   Uncomment the three lines below to reset the analog pins A2 & A3
//   pinMode(A2, INPUT);        // GND pin      
//   pinMode(A3, INPUT);        // VCC pin
//   digitalWrite(A3, LOW);     // turn off pullups   

    Serial.begin(9600);
}

void loop() {
    Serial.print("Temp: ");
    Serial.print(temp.GetTemperature());
    Serial.println(" degC");
    delay(100);
}

