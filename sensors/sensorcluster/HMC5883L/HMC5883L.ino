#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <HMC5883L_waggle.h>

// #include <HTU21D_Waggle.h>
// #include <MCP342X_Waggle.h>
// #include <TMP421_Waggle.h>
//
// TwoWire *wirex=&Wire1;

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(&Wire1);
// Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified();
// Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(23);
// Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(23,&Wire1);
// HTU21D myHumidity;

void setup(void)
{
    delay(4000);
    SerialUSB.begin(115200);
    mag.begin();
    SerialUSB.println("Starting..");
    //     myHumidity.begin();
}

void loop(void)
{
    SerialUSB.println("Starting1..");
    sensors_event_t event;
    mag.getEvent(&event);


    SerialUSB.print("X: "); SerialUSB.print(event.magnetic.x,3); SerialUSB.print("  ");
    SerialUSB.print("Y: "); SerialUSB.print(event.magnetic.y,3); SerialUSB.print("  ");
    SerialUSB.print("Z: "); SerialUSB.print(event.magnetic.z,3); SerialUSB.print("  ");
    SerialUSB.println("gauss");

    //         float humd = myHumidity.readHumidity();
    //         float temp = myHumidity.readTemperature();
    //         SerialUSB.print("Time:");
    //         SerialUSB.print(millis());
    //         SerialUSB.print(" Temperature:");
    //         SerialUSB.print(temp, 1);
    //         SerialUSB.print("C");
    //         SerialUSB.print(" Humidity:");
    //         SerialUSB.print(humd, 1);
    //         SerialUSB.print("%");
    //         SerialUSB.println();

    delay(500);
}
