/***************************************************************************************
 * Emulates data coming from all sensors on AoT device and assembles them into a packet.
 * Operates as I2C slave that responds to master's data requests.
 *
 * Arduino Mega2560 connections:
 *  GND ---> GND
 *  SDA (Pin 20) ---> Master's SDA
 *  SCL (Pin 21) ---> Master's SCL
 *
 * Author: Daniel Schrader (dschrader@anl.gov)
 *
 * Last updated: 20 May 2015
 ***************************************************************************************/



/** Includes **************************************************************************/
#include <Wire.h>
#include "config.cpp"
/**************************************************************************************/

/** Global vars ***********************************************************************/
// Main board
byte MAC_ID[LENGTH_FORMAT3 + 2]; // MAC address
byte TMP112[LENGTH_FORMAT1 + 2]; // ambient temp
byte HTU21D[(LENGTH_FORMAT1 * 2) + 2]; // ambient RH & temp
byte GP2Y1010AU0F[LENGTH_FORMAT2 + 2]; // dust density
byte BMP180[LENGTH_FORMAT1 + LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte PR103J2[LENGTH_FORMAT2 + 2]; // light
byte TSL250RD_1[LENGTH_FORMAT2 + 2]; // ambient light (400-950nm)
byte MMA8452Q[(LENGTH_FORMAT1 * 4) + 2]; // 3-axis accel for traffic flow
byte SPV1840LR5HB_1[LENGTH_FORMAT2 + 2]; // sound pressure
byte TSYS01[LENGTH_FORMAT2 + 2]; // ambient temp

// Aux board
byte HMC5883L[(LENGTH_FORMAT4 * 3) + 2]; // magnetic field strength for traffic flow
byte HIH6130[(LENGTH_FORMAT1 * 2) + 2]; // temp and RH inside transparent box
byte APDS9006020[LENGTH_FORMAT2 + 2]; // ambient light inside cavity
byte TSL260RD[LENGTH_FORMAT2 + 2]; // solar near IR
byte TSL250RD_2[LENGTH_FORMAT2 + 2]; // solar visible light
byte MLX75305[LENGTH_FORMAT2 + 2]; // solar visible light
byte ML8511[LENGTH_FORMAT2 + 2]; // solar UV
byte D6T[(LENGTH_FORMAT1 * 17) + 2]; // temp of surrounding objects
byte MLX90614[LENGTH_FORMAT1 + 2]; // temp of pavement
byte TMP421[LENGTH_FORMAT1 + 2]; // temp inside transparent box
byte SPV1840LR5HB_2[LENGTH_FORMAT2 + 2]; // sound pressure

// Intel board
byte total_reducing_gases[LENGTH_FORMAT2 + 2]; // ambient concentration
byte ethanol[LENGTH_FORMAT2 + 2]; // ambient concentration
byte nitrogen_dioxide[LENGTH_FORMAT2 + 2]; // ambient concentration
byte ozone[LENGTH_FORMAT2 + 2]; // ambient concentration
byte hydrogen_sulphide[LENGTH_FORMAT2 + 2]; // ambient concentration
byte total_oxidizing_gases[LENGTH_FORMAT2 + 2]; // ambient concentration
byte carbon_monoxide[LENGTH_FORMAT2 + 2]; // ambient concentration
byte sulfur_dioxide[LENGTH_FORMAT2 + 2]; // ambient concentration
byte sensirion[(LENGTH_FORMAT1 * 2) + 2]; // ambient temp and RH
byte bosh[LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte intel_MAC_ID[LENGTH_FORMAT3 + 2]; // MAC address of Intel board

// Whole packet
byte packet_whole[LENGTH_WHOLE];
byte sensor_health[SENSOR_HEALTH_SIZE+2];
// Data sub-packet
byte packet_data[LENGTH_DATA];
// Sub-packets for each format
byte packet_format1[LENGTH_FORMAT1];
byte packet_format2[LENGTH_FORMAT2];
byte packet_format3[LENGTH_FORMAT3];
byte packet_format4[LENGTH_FORMAT4];
byte packet_format5[LENGTH_FORMAT5];
byte packet_format6[LENGTH_FORMAT6];

// These lengths are calculated at packet assembly
byte length_whole_actual;
byte length_data_actual;

// CRC-8
byte crc = 0x00;
/**************************************************************************************/

/** I2C request interrupt *************************************************************/
void requestEvent()
{
    // Send it!
    Wire.write(packet_whole, packet_whole[0x02]+0x05);
    // Assemble empty packet, in case master requests more data before its available
    assemble_packet_empty();
}
/**************************************************************************************/



/** Arduino: setup ********************************************************************/
void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(3000);
    //     Setup the I2C buffer
    for (byte i=0x00; i<LENGTH_WHOLE; i++)
    {
        packet_whole[i] = 0x00;
    }
    packet_whole[0x00] = START_BYTE;
    packet_whole[0x01] = HEADER_RESERVED | HEADER_VERSION;
    packet_whole[0x02] = 0x00;
    packet_whole[0x03] = 0x00;
    packet_whole[0x04] = END_BYTE;

    // Join I2C bus as slave
    Wire.begin(I2C_SLAVE_ADDRESS);
    // Register interrupt
    Wire.onRequest(requestEvent);
    
    Serial.begin(115200);
}
/**************************************************************************************/



/** Arduino: loop *********************************************************************/
void loop()
{
    // Generate fake sensor data
    generate_data();
    // Put whole packet together
    assemble_packet_whole();
    // Simulate sensor data accumulation period
    delay(DELAY_MS);
}
/**************************************************************************************/

