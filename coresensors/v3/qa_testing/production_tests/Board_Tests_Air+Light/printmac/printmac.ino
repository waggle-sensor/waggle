#include <Wire.h>
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"



byte MAC_ID[LENGTH_FORMAT3 + 2] = {ID_MAC, 134,0,0,0,0,0,0}; // MAC address
OneWire ds2401(PIN_DS2401);  //DS2401 PIN
byte Temp_byte[8];
byte pass_flag = 1;
unsigned char Temp_uchar[4] = {'F','A','I','L'};


void initializecoresense(void)
{
    byte i;

    pinMode(PIN_SPV_AMP,INPUT);
    pinMode(PIN_SVP_SPL,INPUT);
    pinMode(PIN_RAW_MIC,INPUT);
    pinMode(PIN_HIH4030,INPUT);
    pinMode(PIN_CHEMSENSE_POW, OUTPUT);
    pinMode(PIN_CHEMSENSE_HBT, INPUT);
    pinMode(PIN_CHEMSENSE_RST, OUTPUT);
    pinMode(PIN_HBT, OUTPUT);


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
    SerialUSB.begin(115200);
    Serial3.begin(115200);
    initializecoresense();
}


void loop()
{
    for (byte i=7; i>1; i--)
    {
        if (MAC_ID[i] < 16)
        {
            SerialUSB.print("0");
        }
        SerialUSB.print(MAC_ID[i],HEX);
    }
    SerialUSB.println("");
    delay(1000);
}





