

#include "RCM_TMP112.h"

RCM_TMP112::RCM_TMP112()
{
    
}


boolean RCM_TMP112::begin()
{
    Wire.begin();
    boolean sensorOk = true;
    write16(TMP112_CONFIGURATION_REGISTER, 0x60, 0x00);
    delay(10);
    read16(TMP112_CONFIGURATION_REGISTER);
    
    if ((readBuffer[0] & 0x7F) == 0x60)
    {
        sensorOk = true;
    }
    else
    {
        sensorOk = false;
    }
    
    return sensorOk;
    
}

void RCM_TMP112::readTemperature()
{
    
    read16(TMP112_TEMPERATURE_REGISTER);
    
    pTemperatureRaw = (uint16_t)((uint16_t)readBuffer[0] << 8 ) + (uint16_t)readBuffer[1];
    pTemperature    = readBuffer[0];

}

/*********************************************************************/

void RCM_TMP112::read16(uint8_t reg) {
  uint16_t ret;

  Wire.beginTransmission(TMP112_ADDRESS); // start transmission to device
  Wire.write(TMP112_ADDRESS); // sends register address to read from
  Wire.write(reg); // sends register address to read from
  Wire.endTransmission(); // end transmission
    delay(10);
  
  Wire.beginTransmission(TMP112_ADDRESS); // start transmission to device
  Wire.requestFrom(TMP112_ADDRESS, 2);// send data n-bytes read
    
  readBuffer[0] = Wire.read(); // receive DATA
  readBuffer[1] = Wire.read(); // receive DATA
    
  Wire.endTransmission(); // end transmission

}

void RCM_TMP112::write16(uint8_t a, uint8_t d1, uint8_t d2) {
  Wire.beginTransmission(TMP112_ADDRESS); // start transmission to device
  Wire.write(a); // sends register address to read from
  Wire.write(d1);  // write data
  Wire.write(d2);  // write data
  Wire.endTransmission(); // end transmission
}
