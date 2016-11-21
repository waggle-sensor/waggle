/*
 * /coresensors/v2/pbay/integrated
 * integrated.ino V2 (including NEW INTEL CHEMSENSE BOARD)
 */

// #include "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.4/libraries/Wire/Wire.h"

#include <Wire.h>
#include "config.cpp"
#include "./libs/DueTimer/DueTimer.h"   // SH adds
// extern TwoWire Wire1;
TwoWire *wirex=&Wire1;
#include "./set_sensors.h"
#include "./subpackets.h"


float Temp_float[3];
byte Temp_byte[8];
uint16_t Temp_uint16;
long Temp_long;
int Temp_int[3];
unsigned long Temp_ulong[2];

bool TIMER = false;
bool init_SPV1 = false;


// CRC-8
byte crc = 0x00;
byte I2C_READ_COMPLETE = true;
/**************************************************************************************/

#ifdef I2C_INTERFACE
/** I2C request interrupt *************************************************************/
void requestEvent()
{
    #ifdef I2C_INTERFACE_CONST_SIZE
    Wire.write(packet_whole, I2C_PACKET_SIZE);
    #else
    char bytes_to_send;
    bytes_to_send = packet_whole[0x02] + 0x05;
    Wire.write(packet_whole, bytes_to_send );
    #endif

    I2C_READ_COMPLETE = true;
    assemble_packet_empty();
    TIMER = false;
}
/**************************************************************************************/
#endif

/** Arduino: setup ********************************************************************/
void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(1000);
    Wire1.begin();
    delay(1000);
    
    #ifdef I2C_INTERFACE
    I2C_READ_COMPLETE = false;
    Wire.begin(I2C_SLAVE_ADDRESS);
    Wire.onRequest(requestEvent);
    #endif

    #ifdef USBSERIAL_INTERFACE
    SerialUSB.begin(115200);
    #endif 

    #ifdef SERIAL_DEBUG
    SerialUSB.println("Starting...");
    #endif

    #ifdef CHEMSENSE_INCLUDE
    Serial3.begin(19200);
    #endif

    //     Setup the I2C buffer
    for (byte i=0x00; i<LENGTH_WHOLE; i++)
    {
        packet_whole[i] = 0x00;
    }

    assemble_packet_empty();
    Sensors_Setup();
    sensor_buff_initialization();
    delay(1000);
    
    #ifdef USBSERIAL_INTERFACE
    Timer3.attachInterrupt(handler).setPeriod(1000000 * 5).start(); // print super-packet every 30 secs
    #endif
}
/**************************************************************************************/

void handler()
{
    TIMER = true;
}

void loop()
{
#ifdef USBSERIAL_INTERFACE
    
    #ifdef CHEMSENSE_INCLUDE
    new_chemsense_acquire();
    #endif

    // #undef AIRSENSE_INCLUDE

    if (TIMER)
    {
        #ifdef AIRSENSE_INCLUDE
        airsense_acquire();
        #endif

        #ifdef LIGHTSENSE_INCLUDE
        lightsense_acquire();
        #endif

        assemble_packet_empty();
        assemble_packet_whole();

        for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i ++)
            SerialUSB.write(packet_whole[i]);

        TIMER = false;
    }  
#endif

#ifdef I2C_INTERFACE

    if (I2C_READ_COMPLETE == true)
    {
        #ifdef AIRSENSE_INCLUDE
        airsense_acquire();
        #endif

        #ifdef LIGHTSENSE_INCLUDE
        lightsense_acquire();
        #endif
        
        Timer3.attachInterrupt(handler).setPeriod(1000000 * 24).start(); // print super-packet every 30 secs

        // this is a hack...      
        while (TIMER == false)
        {
            #ifdef CHEMSENSE_INCLUDE
            new_chemsense_acquire();
            #endif
            delay(1);
        }
        
        Timer3.attachInterrupt(handler).stop(); 
        assemble_packet_whole();
        I2C_READ_COMPLETE = false;
    }    
#endif

}
