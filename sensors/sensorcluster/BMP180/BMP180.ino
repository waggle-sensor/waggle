#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);


/**************************************************************************/
/*
 *    Arduino setup function (automatically called at startup)
 */
/**************************************************************************/
void setup(void)
{
    delay(5000);
    SerialUSB.begin(115200);
    /* Initialise the sensor */
    bmp.begin();
}

/**************************************************************************/
/*
 *    Arduino loop function, called once 'setup' is complete (your own code
 *    should go here)
 */
/**************************************************************************/
void loop(void)
{
    /* Get a new sensor event */
    sensors_event_t event;
    bmp.getEvent(&event);

    /* Display the results (barometric pressure is measure in hPa) */
    if (event.pressure)
    {
        /* Display atmospheric pressue in hPa */
        SerialUSB.print("Pressure:    ");
        SerialUSB.print(event.pressure);
        SerialUSB.println(" hPa");

        float temperature;
        bmp.getTemperature(&temperature);
        SerialUSB.print("Temperature: ");
        SerialUSB.print(temperature);
        SerialUSB.println(" C");

    }
    else
    {
        SerialUSB.println("Sensor error");
    }
    delay(1000);
}
