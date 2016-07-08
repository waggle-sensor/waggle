/**
 ** /coresensors/v3/pbay/v3.1/integrated
 ** integrated.ino V3 (pbay)
 **/

#include <SPI.h>
#include <Wire.h> 
#include "./libs/DueTimer/DueTimer.h"   //** TIMER3 library
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"

#include "./variable.h"     //** byte arrays, variables for all sensors and integrated.ino
#include "./setsensor.h"    //** add variables for sensors on airsense and lightsense boards depening on its availability 

void setup()
{
    //** Let us wait for the processor and the sensors to settle down
    delay(2000);

    //** initialize the super-packet
    //** and sub-packets
    //** sensors_setup.ino, set pinMode and put MACID of airsense
    assemble_packet_empty();
    sensor_buff_initialization();
    initializeSensorBoard();


    //** begin communication lines
    Wire.begin(); // Sensors are on the first I2C Bus, air and light sensor boards
    SerialUSB.begin(USBSERIAL_INTERFACE_DATARATE); // Serial data line to the host computer
    Serial3.begin(CHEMSENSE_DATARATE); // data from the Chemsense board arrives here.
    SPI.begin(); // data from the alphasensor

    #ifdef CHEMSENSE_INCLUDE
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

    Timer3.attachInterrupt(handler).setPeriod(1000000 * 1).start();
}

void loop()
{
    #ifdef AIRSENSE_INCLUDE
    airsense_acquire();
    #endif
    
    #ifdef LIGHTSENSE_INCLUDE
    lightsense_acquire();
    #endif

    while (count < 24)
    {
        #ifdef CHEMSENSE_INCLUDE
        chemsense_acquire();
        #endif
    }

    assemble_packet_whole();

    //** To check how much time has OIX packet been generated in 24 secs
    // SerialUSB.print("OIX_count ");
    // SerialUSB.print(OIX_count);
    // SerialUSB.print(" OIX_packet_count ");
    // SerialUSB.println(OIX_packet_count);

    #ifndef PRINT_ADDRESS
    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
    {
        SerialUSB.write(packet_whole[i]);

        //** To check how much time has OIX packet been generated in 24 secs
        // SerialUSB.print(packet_whole[i], HEX);
        // if (i < packet_whole[0x02] + 0x04)
        //     SerialUSB.print(":");
    }
    // SerialUSB.println("");
    #endif


    OIX_count = 0;
    OIX_packet_count = 0;

    count = 0;

    delay(100);
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


