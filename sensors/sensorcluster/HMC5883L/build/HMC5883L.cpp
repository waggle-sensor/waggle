#line 1 "HMC5883L.ino"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

#include "Arduino.h"
void setup(void);
void loop(void);
#line 5
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setup(void)
{
    delay(2000);
    SerialUSB.begin(115200);
    mag.begin();
}

void loop(void)
{
        sensors_event_t event;
        mag.getEvent(&event);
        SerialUSB.print("X: "); SerialUSB.print(event.magnetic.x,3); SerialUSB.print("  ");
        SerialUSB.print("Y: "); SerialUSB.print(event.magnetic.y,3); SerialUSB.print("  ");
        SerialUSB.print("Z: "); SerialUSB.print(event.magnetic.z,3); SerialUSB.print("  ");SerialUSB.println("gauss");
        delay(500);
}

