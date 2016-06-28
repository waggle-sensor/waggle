/**
 ** /coresensors/v3/pbay/v3.1/integrated
 ** reintegrated.ino V3 (pbay)
 **/

#include <Wire.h> 
#include "./libs/DueTimer/DueTimer.h"   //** TIMER3 library
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"

#include "./variables.h"     //** byte arrays, variables for all sensors and integrated.ino
#include "./setsensor.h"    //** add variables for sensors on airsense and lightsense boards depening on its availability 

void setup()
{
    //** Let us wait for the processor and the sensors to settle down
    delay(2000);

    //** begin all communication lines
    Wire.begin(); // Sensors are on the first I2C Bus.
    SerialUSB.begin(USBSERIAL_INTERFACE_DATARATE); // Serial data line to the host computer
    Serial3.begin(CHEMSENSE_DATARATE); // data from the Chemsense board arrives here.

    //** initialize the super-packet and sub-packets
    assemble_packet_empty();
    sensor_buff_initialization();

    //** sensors_setup.ino, set pinMode and put MACID of airsense
    initializeSensorBoard();
    
    #ifdef CHEMSENSE_INCLUDE
    digitalWrite(PIN_CHEMSENSE_POW, LOW);  //** Power on the Chemsense board
    #endif

    //** sensors_setup.ino, initialize sensors in airsense and lightsense boards
    Sensors_Setup();

    //** Setup the I2C buffer
    for (byte i=0x00; i<LENGTH_WHOLE; i++)
        packet_whole[i] = 0x00;

    #ifdef I2C_INTERFACE
    I2C_READ_COMPLETE = false;
    Wire1.begin(I2C_SLAVE_ADDRESS);
    Wire1.onRequest(requestEvent);
    #endif
}

void handler()
{
    TIMER = true;
}

void loop()
{
    Timer3.attachInterrupt(handler).setPeriod(1000000 * 25).start();
    while (TIMER)
    {
        #ifdef CHEMSENSE_INCLUDE
        chemsense_acquire();
        #endif        
    }

    Timer3.attachInterrupt(handler).stop();

    #ifdef AIRSENSE_INCLUDE
    airsense_acquire();
    #endif
    
    #ifdef LIGHTSENSE_INCLUDE
    lightsense_acquire();
    #endif

    assemble_packet_whole();
    for (byte i = 0; i < packet_whole[1] + 5; i++)
        SerialUSB.write(packet_whole[i]);


#ifdef I2C_INTERFACE

    if (I2C_READ_COMPLETE == true)
    {
        #ifdef AIRSENSE_INCLUDE
        airsense_acquire();
        #endif

        #ifdef LIGHTSENSE_INCLUDE
        lightsense_acquire();
        #endif

        #ifdef CHEMSENSE_INCLUDE
        new_chemsense_acquire();
        #endif
    }
        
        assemble_packet_whole();
        I2C_READ_COMPLETE = false;
#endif
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
