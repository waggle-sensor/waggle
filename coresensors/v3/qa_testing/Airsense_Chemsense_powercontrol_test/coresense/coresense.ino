#include <Wire.h>
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"



byte MAC_ID[LENGTH_FORMAT3 + 2] = {ID_MAC, 134,0,0,0,0,0,0}; // MAC address
OneWire ds2401(PIN_DS2401);  //DS2401 PIN
byte Temp_byte[8];


void initializecoresense(void)
{
    byte i;

    pinMode(PIN_SPV_AMP,INPUT);
    pinMode(PIN_SVP_SPL,INPUT);
    pinMode(PIN_RAW_MIC,INPUT);
    pinMode(PIN_HIH4030,INPUT);
    pinMode(PIN_CHEMSENSE_POW, OUTPUT);

    if (ds2401.reset() == TRUE)
    {
        ds2401.write(0x33);
        for (i = 0; i < 8; i++)
        {
            Temp_byte[i] = ds2401.read();
        }

        if (OneWire::crc8(Temp_byte, 8) == 0)
        {
            for (i=1; i<7; i++)
            {
                MAC_ID[i + 1] = Temp_byte[i];
            }

        }

        else
        {

            MAC_ID[3] = 0xff;

        }
    }
    else //Nothing is connected in the bus
    {
        MAC_ID[3] = 0xaa;
    }
}


void setup()
{
    delay(2000);
    Wire.begin();
    delay(2000);
    SerialUSB.begin(115200);
    initializecoresense();
}


void loop()
{
    SerialUSB.println(">>>>>> Core Sense Testing - Airsense Chemsense Powercontrol Test <<<<<<");
    SerialUSB.println(" ");
    SerialUSB.print("Unique Board ID - ");
    for (byte i=2; i<8; i++)
    {
        SerialUSB.print(MAC_ID[i],HEX);

        if (i < 7)
        {
            SerialUSB.print(":");
        }
        else
        {
            SerialUSB.print("\n");
        }
    }
    SerialUSB.println(" ");
    delay(2000);
    SerialUSB.print("1. Powercontrol Test : (The LED on the ACHEM breakout board should keep blinking) ");
    SerialUSB.println(" ");
    SerialUSB.println(">>>>>> Test Finished <<<<<<");
    while (1)
    {
        digitalWrite(PIN_CHEMSENSE_POW, LOW);
        delay(1000);
        digitalWrite(PIN_CHEMSENSE_POW, HIGH);
        delay(1000);
    }

}





