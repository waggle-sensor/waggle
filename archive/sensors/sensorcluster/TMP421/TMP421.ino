/****************************
 * GetLocalTemperature
 *  An example sketch that prints the
 *  local temperature to the PC's serial port
 *
 *  Tested with the TMP421-Breakout
 *  Temperature Sensor from Modern Device
 *****************************/
#include <Wire.h>
#include "LibTempTMP421.h"
extern TwoWire Wire1;

LibTempTMP421 temp = LibTempTMP421();

void setup()
{
    delay(4000);
    Wire1.begin();
    SerialUSB.begin(57600);
}

void loop() {
    SerialUSB.print("Temp: ");
    SerialUSB.print(temp.GetTemperature());
    SerialUSB.println(" degC");
    delay(1000);
}

