#include <Wire.h>
extern TwoWire Wire1;
#include <OneWire.h>

#define ID_MAC  0x00

#define LENGTH_FORMAT3  6

#define EEPROM_ADDRESS      0x50    //Address of 24LC256 EEPROM
#define PIN_DS2401          48

#define PIN_CHEMSENSE_POW   47
#define PIN_HBT             8   
#define RAIN_MONITOR_PIN    A2

byte MAC_ID[LENGTH_FORMAT3 + 2] = {ID_MAC, 134,0,0,0,0,0,0}; // MAC address
OneWire ds2401(PIN_DS2401);  //DS2401 PIN

byte Temp_byte[8];
byte pass_flag = 1;

unsigned char Temp_uchar[4] = {'F','A','I','L'};
bool UP_DOWN = false;

bool chem = false;
bool rain = false;
bool soil = false;

void initializecoresense(void)
{
    byte i;

    pinMode(PIN_CHEMSENSE_POW, OUTPUT);
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

void writeEEPROM (unsigned int memory_address, byte data_byte )
{
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(memory_address >> 8));   // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.write(data_byte);
    Wire.endTransmission();
    delay(5);
}

byte readEEPROM (unsigned int memory_address )
{
    byte recv_data = 0xff;

    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(memory_address >> 8));   // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(EEPROM_ADDRESS,1);

    if (Wire.available())
    {
        recv_data = Wire.read();
    }
    return recv_data;
}


void setup()
{
    delay(2000);
    Wire.begin();
    delay(2000);
    SerialUSB.begin(115200);
    Serial3.begin(115200);
    initializecoresense();
}


void loop()
{
    byte pass_flag = 1;
    unsigned char Temp_uchar[4] = {'F','A','I','L'};

    SerialUSB.println(">>>>>> Core Sense Testing - Test 1 <<<<<<");
    SerialUSB.println(" ");
    SerialUSB.println("1. Power-ON : PASS");
    SerialUSB.println(" ");
    SerialUSB.println("2. Atmel Power & Communication: PASS ");
    SerialUSB.println(" ");
    SerialUSB.print("3. I2C Bus Test : ");

    for (byte i=0; i<LENGTH_FORMAT3; i++)
        writeEEPROM (i,MAC_ID[i+2]);

    delay(100);

    for (byte i=0; i<LENGTH_FORMAT3; i++)
    {
        if (readEEPROM(i) != MAC_ID[i+2])
        {
            pass_flag = 0;
            break;
        }
    }

    if (pass_flag == 1)
        SerialUSB.println("PASS");
    else
        SerialUSB.println("FAIL");

    SerialUSB.println(" ");
    SerialUSB.print("4. Metsense Unique Board ID - ");

    for (byte i=2; i<8; i++)
    {
        SerialUSB.print(MAC_ID[i],HEX);

        if (i < 7)
            SerialUSB.print(":");
        else
            SerialUSB.print("\n");
    }

    SerialUSB.println(" ");
    SerialUSB.print("5. Metsense-Lightsense Connectivity Test : ");
    
    if (Wire.requestFrom(0x27,1) == 0x01) // we are checking if we can read the HIH6130 chip present on the Lightsense board from the Airsense.
        SerialUSB.println("PASS.");
    else
        SerialUSB.println("FAIL");

    SerialUSB.println(" ");
    SerialUSB.print("6. Metsense Heartbeat Test : ");

    bool heartbeat = digitalRead(PIN_HBT);
    
    UP_DOWN =! heartbeat;
    digitalWrite(PIN_HBT, UP_DOWN);

    if (digitalRead(PIN_HBT) != heartbeat)
        SerialUSB.println("PASS");
    else
        SerialUSB.println("FAIL");


    SerialUSB.println(" ");
    SerialUSB.print("7. Metsense-Chemsense Serial Connectivity Test : ");

    if (Serial3.available() != 0)
    {
        chem = true;
    	SerialUSB.println("PASS");
    }
    else
    	SerialUSB.println("FAIL");


    SerialUSB.println(" ");
    SerialUSB.println("8. Powercontrol Test : The test has PASSED if the LED on the ACHEM breakout board should keep blinking");


	SerialUSB.println(" ");
    SerialUSB.println("9. Alpha sensor : Alpha sensor is connected directly to the nodecontroller for now (11/17/2016), if it is included in the node");

    

    // SerialUSB.println(" ");
    // SerialUSB.print("9. Rain Gauge Connectivity Test : ");

    // if (analogRead(RAIN_MONITOR_PIN) == 0)
    // {
    //     rain = true;
    //     SerialUSB.println("PASS");
    // }
    // else
    //     SerialUSB.println("FAIL");

    // SerialUSB.println(" ");
    // SerialUSB.print("10. Soil Conductivity Sensor Connectivity Test : ");

    // if (Serial1.available() != 0)
    //     SerialUSB.println("PASS");
    // else
    //     SerialUSB.println("FAIL");
    

    SerialUSB.println(" ");
    SerialUSB.println(">>>>>> Test Finished <<<<<<");

    while(1)
    {
        delay(1000);
    }
}