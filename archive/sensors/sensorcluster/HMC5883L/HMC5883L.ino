#include <Wire.h>
#include "./libs/Adafruit_Sensor-master/Adafruit_Sensor.h"
#include "./libs/HMC5883L_waggle/HMC5883L_waggle.h"

HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(&Wire1);
// HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor();
// HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(23);
// HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(23,&Wire1);

void setup(void)
{
    delay(4000);
    SerialUSB.begin(115200);
    HMC5883_Magnetometer.begin();
}

void loop(void)
{
    SerialUSB.println("Starting1..");
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);

    SerialUSB.print("X: "); SerialUSB.print(event.magnetic.x,3); SerialUSB.print("  ");
    SerialUSB.print("Y: "); SerialUSB.print(event.magnetic.y,3); SerialUSB.print("  ");
    SerialUSB.print("Z: "); SerialUSB.print(event.magnetic.z,3); SerialUSB.print("  ");
    SerialUSB.println("gauss");

    delay(500);
}
