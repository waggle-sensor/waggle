/**************************************************************************/
/*! 
    @file     MCP342X.cpp
    @author   C. Schnarel
	@license  BSD (see license.txt)
	
    This is part of an Arduino library to interface with the Microchip
    MCP47X6 series of Analog-to-Digital converters which are connected
    via the I2C bus.

    MCP342X I2C device class
    Based on Microchip datasheets for the following part numbers
        MCP3421, MCP3422, MCP3423, MCP3424, MCP3425, MCP3426, MCP3427, MCP3428
    These parts share a common programming interface

    (c) Copyright 2013 by Chip Schnarel <schnarel@hotmail.com>
    Updates should (hopefully) always be available at
        https://github.com/uchip/MCP342X

	@section  HISTORY

    2013-Dec-24  - First release, C. Schnarel
*/
/**************************************************************************/

#include "MCP342X.h"

/*	static float	stepSizeTbl[] = {
		0.001,		// 12-bit, 1X Gain
		0.0005,		// 12-bit, 2X Gain
		0.00025,	// 12-bit, 4X Gain
		0.000125,	// 12-bit, 8X Gain
		0.00025,	// 14-bit, 1X Gain
		0.000125,	// 14-bit, 2X Gain
		0.0000625,	// 14-bit, 4X Gain
		0.00003125,	// 14-bit, 8X Gain
		0.0000625,	// 16-bit, 1X Gain
		0.00003125,	// 16-bit, 2X Gain
		0.000015625,	// 16-bit, 4X Gain
		0.0000078125,	// 16-bit, 8X Gain
		0.000015625,	// 18-bit, 1X Gain
		0.0000078125,	// 18-bit, 2X Gain
		0.00000390625,	// 18-bit, 4X Gain
		0.000001953125	// 18-bit, 8X Gain
		};
*/

/******************************************
 * Default constructor, uses default I2C address.
 * @see MCP342X_DEFAULT_ADDRESS
 */
MCP342X::MCP342X() {
    devAddr = MCP342X_DEFAULT_ADDRESS;
}

/******************************************
 * Specific address constructor.
 * @param address I2C address
 * @see MCP342X_DEFAULT_ADDRESS
 * @see MCP342X_A0GND_A1GND, etc.
 */
MCP342X::MCP342X(uint8_t address) {
    devAddr = address;
}

/******************************************
 * Verify the I2C connection.
 * Make sure the device is connected and responds as expected.
 * @return True if connection is valid, false otherwise
 */
bool MCP342X::testConnection() {
    Wire.beginTransmission(devAddr);
    return (Wire.endTransmission() == 0);
}


/******************************************
 * Set the configuration shadow register
 */
void MCP342X::configure(uint8_t configData) {
  configRegShdw = configData;
}

/******************************************
 * Get the configuration shadow register
 */
uint8_t MCP342X::getConfigRegShdw(void) {
  return configRegShdw;
}

/******************************************
 * Get the step size based on the configuration shadow register
 */
/*float MCP342X::getStepSize(void) {
  uint8_t select = configRegShdw & (MCP342X_SIZE_MASK | MCP342X_GAIN_MASK);
  return stepSizeTbl[select];
}*/

/******************************************
 * Start a conversion using configuration settings from
 *   the shadow configuration register
 */
bool MCP342X::startConversion(void) {
  Wire.beginTransmission(devAddr);
  Wire.write(configRegShdw | MCP342X_RDY);
  return (Wire.endTransmission() == 0);
}

 
/******************************************
 * Start a conversion using configuration settings from
 *   the shadow configuration register substituting the
 *   supplied channel
 */
bool MCP342X::startConversion(uint8_t channel) {
  Wire.beginTransmission(devAddr);
  configRegShdw = ((configRegShdw & ~MCP342X_CHANNEL_MASK) | 
			   (channel & MCP342X_CHANNEL_MASK));
  Wire.write(configRegShdw | MCP342X_RDY);
  return (Wire.endTransmission() == 0);
}

 
/******************************************
 * Read the conversion value (12, 14 or 16 bit)
 *  Spins reading status until ready then
 *  fills in the supplied location with the 16-bit (two byte)
 *  conversion value and returns the status byte
 *  Note: status of -1 "0xFF' implies read error
 */
uint8_t MCP342X::getResult(int16_t *dataPtr) {
  uint8_t adcStatus;
  if((configRegShdw & MCP342X_SIZE_MASK) == MCP342X_SIZE_18BIT) {
    return 0xFF;
  }

  do {
     if(Wire.requestFrom(devAddr, (uint8_t) 3) == 3) {
       ((char*)dataPtr)[1] = Wire.read();
       ((char*)dataPtr)[0] = Wire.read();
       adcStatus = Wire.read();
     }
     else return 0xFF;
  } while((adcStatus & MCP342X_RDY) != 0x00);
  return adcStatus;
}

 
/******************************************
 * Check to see if the conversion value (12, 14 or 16 bit)
 *  is available.  If so, then
 *  fill in the supplied location with the 16-bit (two byte)
 *  conversion value and status the config byte
 *  Note: status of -1 "0xFF' implies read error
 */
uint8_t MCP342X::checkforResult(int16_t *dataPtr) {
  uint8_t adcStatus;
  if((configRegShdw & MCP342X_SIZE_MASK) == MCP342X_SIZE_18BIT) {
    return 0xFF;
  }

  if(Wire.requestFrom(devAddr, (uint8_t) 3) == 3) {
    ((char*)dataPtr)[1] = Wire.read();
    ((char*)dataPtr)[0] = Wire.read();
    adcStatus = Wire.read();
  }
  else return 0xFF;

  return adcStatus;
}

 
/******************************************
 * Read the conversion value (18 bit)
 *  Spins reading status until ready then
 *  fills in the supplied location (32 bit) with
 *  the 24-bit (three byte) conversion value
 *  and returns the status byte
 *  Note: status of -1 "0xFF' implies read error
 */
uint8_t MCP342X::getResult(int32_t *dataPtr) {
  uint8_t adcStatus;
  if((configRegShdw & MCP342X_SIZE_MASK) != MCP342X_SIZE_18BIT) {
    return 0xFF;
  }

  do {
     if(Wire.requestFrom((uint8_t) devAddr, (uint8_t) 4) == 4) {
       ((char*)dataPtr)[3] = Wire.read();
       ((char*)dataPtr)[2] = Wire.read();
       ((char*)dataPtr)[1] = Wire.read();
       adcStatus = Wire.read();
     }
     else return 0xFF;
  } while((adcStatus & MCP342X_RDY) != 0x00);
  *dataPtr = (*dataPtr)>>8;
  return adcStatus;
}


/******************************************
 * Check to see if the conversion value (18 bit)
 *  is available.  If so, then
 *  fill in the supplied location (32 bit) with
 *  the 24-bit (three byte) conversion value
 *  and return the status byte
 *  Note: status of -1 "0xFF' implies read error
 */
uint8_t MCP342X::checkforResult(int32_t *dataPtr) {
  uint8_t adcStatus;
  if((configRegShdw & MCP342X_SIZE_MASK) != MCP342X_SIZE_18BIT) {
    return 0xFF;
  }

  if(Wire.requestFrom((uint8_t) devAddr, (uint8_t) 4) == 4) {
    ((char*)dataPtr)[3] = Wire.read();
    ((char*)dataPtr)[2] = Wire.read();
    ((char*)dataPtr)[1] = Wire.read();
    adcStatus = Wire.read();
  }
  else return 0xFF;

  *dataPtr = (*dataPtr)>>8;
  return adcStatus;
}


