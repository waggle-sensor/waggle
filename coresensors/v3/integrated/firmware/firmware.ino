/**
 * * /coresensors/v3/pbay/v3.1/integrated
 ** integrated.ino V3 (pbay)
 **/

#include <SPI.h> // Shall we move the version of the libraries that work for us inside lib?
#include <Wire.h> 
#include "./libs/DueTimer/DueTimer.h"   //** TIMER3 library
#include <OneWire.h>

#include "config.cpp"
#include "pin_config.cpp"

#include "./subpacket.h"
#include "./setsensor.h"    //** add variables for sensors on airsense and lightsense boards 

#include "./variable.h"     //** byte arrays, variables for all sensors and integrated.ino
//** depening on its availability 


#ifndef USBSERIAL_INTERFACE
extern TwoWire Wire1;
#endif


void setup()
{
    //** Let us wait for the processor and the sensors to settle down
    delay(2000);

    #ifdef USBSERIAL_INTERFACE 
    SerialUSB.begin(USBSERIAL_INTERFACE_DATARATE); // Serial data line to the host computer
    #endif

    //** initialize the super-packet
    //** and sub-packets
    //** sensors_setup.ino, set pinMode and put MACID of airsense
    assemble_packet_empty();    
    sensor_buff_initialization();    
    initializeSensorBoard();

    #ifdef I2C_SENSORS
    //** begin communication lines
    Wire.begin(); // Sensors are on the first I2C Bus, air and light sensor boards    
    #endif


    delay(3000);
    #ifdef CHEMSENSE_INCLUDE
    Serial3.begin(CHEMSENSE_DATARATE); // data from the Chemsense board arrives here.
    digitalWrite(PIN_CHEMSENSE_POW, LOW);  //** Power on the Chemsense board
    #endif

    //** sensors_setup.ino, initialize sensors in airsense and lightsense boards
    Sensors_Setup();    // TMP112 config(); Chemsense turned off, This has to come later than chemsense digital write

    //** begin I2C interface
    #ifdef I2C_INTERFACE
    I2C_READ_COMPLETE = false;
    Wire1.begin(I2C_SLAVE_ADDRESS);
    Wire1.onRequest(requestEvent);    
    #endif

    #ifdef ALPHASENSE_INCLUDE    
    SPI.begin(); // data from the ****************************************************** alphasensor
    delay(15000);
    alphasense_on();
    SerialUSB.print("on");
    delay(10000);

    alphasense_firmware();
    alphasense_config();
    //     Serial.print("configuration");
    delay(1000);

    flag_alpha = true;
    #endif

    #ifdef VERSION_INCLUDE
    version_info();
    #endif

    Timer3.attachInterrupt(handler).setPeriod(1000000 * 1).start();
}

void loop()
{
    count = 0;


    while(count < 10)
    {    
        #ifdef CHEMSENSE_INCLUDE        
        flag_CHEM_WHILE = true;
        chemsense_acquire();
        #endif
    }

    #ifdef AIRSENSE_INCLUDE
    airsense_initial();
    #endif

    #ifdef LIGHTSENSE_INCLUDE    
    lightsense_initial();
    #endif

    while (count < 24)       // every 24 sec
    {
        #ifdef AIRSENSE_INCLUDE    
        airsense_acquire();
        #endif

        #ifdef LIGHTSENSE_INCLUDE    
        lightsense_acquire();
        #endif


        #ifdef ALPHASENSE_INCLUDE        
        alphasense_histo();
        delay(100);
        
        if (count == 23)        //every 23 sec
        {
            count_conf++;
            if (count_conf == 26)       // every 598 secs, about 10 min
            {
                alphasense_config();
                delay(100);
                alphasense_firmware();
                delay(100);
                
                flag_alpha = true;
                count_conf = 0;
            }
        }
        #endif
        
        delay(1);
    }
        
    assemble_packet_whole();        //******** packetize air/light/chem
    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
        SerialUSB.write(packet_whole[i]);
    
    #ifdef ALPHASENSE_INCLUDE    
    alpha_packet_whole();           //******** packetize histo/firmware/config(part)
    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
        SerialUSB.write(packet_whole[i]);
    
    if (flag_alpha == true)
    {
        alpha_packet_config();       //******** packetize config(part)
        
        for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
            SerialUSB.write(packet_whole[i]);
    }
    
    flag_alpha = false;
    #endif
    
    count = 0;
}

#ifdef I2C_INTERFACE
void requestEvent()
{
    #ifdef I2C_INTERFACE_CONST_SIZE
    Wire1.write(packet_whole, I2C_PACKET_SIZE);
    
    #else
    char bytes_to_send;
    bytes_to_send = packet_whole[0x02] + 0x05;
    Wire1.write(packet_whole, bytes_to_send );
    #endif
    
    I2C_READ_COMPLETE = true;
    assemble_packet_empty();
}
#endif

void handler()
{
    count++;
    UP_DOWN =! UP_DOWN;
    digitalWrite(PIN_HBT, UP_DOWN);
}