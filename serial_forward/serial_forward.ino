/***************************************************************************************
I2C master that requests slave's data and forwards it out to serial.
 
Arduino Mega2560 connections:
  GND ---> GND
  SDA (Pin 20) ---> Slave's SDA
  SCL (Pin 21) ---> Slave's SCL
 
Author: Daniel Schrader (dschrader@anl.gov)
 
Last updated: 20 May 2015
***************************************************************************************/
 
 
 
/** Includes **************************************************************************/
#include <Wire.h>
/**************************************************************************************/
 
 
 
/** Constants *************************************************************************/
const byte PACKET_SIZE = 199;
const unsigned int DELAY_MS = 2000;
const byte I2C_SLAVE_ADDRESS = 0x03;
/**************************************************************************************/
 
 
 
/** Global vars ***********************************************************************/
 
/**************************************************************************************/
 
 
 
/** Arduino: setup ********************************************************************/
void setup() {
  // Fire up serial port at 115200 baud
  Serial.begin(115200);
 
  // Join I2C bus as master
  Wire.begin();
  Serial.print("Starting...\n");
}
/**************************************************************************************/
 
 
 
/** Arduino: loop *********************************************************************/
void loop() {
  // Array to store received data
  byte packet[PACKET_SIZE];
  // Index for packet array
  int i = 0;
 
  // Request packet from slave (and grab the number of bytes to be transferred)
  byte num_bytes = Wire.requestFrom(I2C_SLAVE_ADDRESS, PACKET_SIZE);
 
  // Grab bytes until slave is finished sending
  while(Wire.available())
    packet[i++] = Wire.read();
 
  // Got anything from slave?
  if(num_bytes > 0)
  {
    // Write data to serial
    for(int x = 0; x < num_bytes; x++)
    {
        Serial.print(packet[x]);
        Serial.print(',');
    }
    Serial.print("\n");
  }
 
  // Wait awhile before making another request to slave
  delay(DELAY_MS);
}
/**************************************************************************************/
