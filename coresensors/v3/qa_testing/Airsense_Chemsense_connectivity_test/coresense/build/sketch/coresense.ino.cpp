#include <Arduino.h>
#line 1
#line 1 "/media/rajesh/Bharadwaja/github/waggle/coresensors/v3/qa_testing/Airsense_Lightsense_connectivity_test/coresense/coresense.ino"
#include <Wire.h>
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"



byte MAC_ID[LENGTH_FORMAT3 + 2] = {ID_MAC, 134,0,0,0,0,0,0}; // MAC address
OneWire ds2401(PIN_DS2401);  //DS2401 PIN
byte Temp_byte[8];


#line 13 "/media/rajesh/Bharadwaja/github/waggle/coresensors/v3/qa_testing/Airsense_Lightsense_connectivity_test/coresense/coresense.ino"
void initializecoresense(void);
#line 54 "/media/rajesh/Bharadwaja/github/waggle/coresensors/v3/qa_testing/Airsense_Lightsense_connectivity_test/coresense/coresense.ino"
void setup();
#line 64 "/media/rajesh/Bharadwaja/github/waggle/coresensors/v3/qa_testing/Airsense_Lightsense_connectivity_test/coresense/coresense.ino"
void loop();
#line 13
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
    SerialUSB.println(">>>>>> Core Sense Testing - Airsense-Lightsense Connectivity Test <<<<<<");
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
    SerialUSB.print("1. Airsense-Lightsense Connectivity Test : ");
    if (Wire.requestFrom(0x27,1) == 0x01) // we are checking if we can read the HIH6130 chip present on the Lightsense board from the Airsense.
    {
        SerialUSB.println("PASS.");
    }

    else
    {
        SerialUSB.println("FAIL.");
    }

    SerialUSB.println(" ");
    SerialUSB.println(">>>>>> Test Finished <<<<<<");

    while (1)
    {
        delay(100);
    }

}






