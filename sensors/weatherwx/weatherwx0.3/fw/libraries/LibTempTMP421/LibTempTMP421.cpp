/*
 LibTemperature - A Temperature Library for Arduino.
 
 Supported Temperature Sensor modules:
 TMP421-Breakout Module - http://shop.moderndevice.com/products/tmp421-temperature-sensor
 
 code by Christopher Ladden 2009. 
 revised Paul Badger 2012
 
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <inttypes.h>
#include <Wire.h>
#include <Arduino.h>
#include "LibTempTMP421.h"

/******************************************************************************
 * Constructors 
 ******************************************************************************/

/**
 * Initialize the sensor based on the specified type.
 */
LibTempTMP421::LibTempTMP421(uint8_t TempSensorType) {
	
	
	
	/* power the TMP421 Temp Sensor from an Arduino's analog pins
	 These pin assignments should really be done in the sketch but apparently 
	 will not work if set after wire.begin is called, because the chip hasn't
	 been powered.
	 There may be a C++ solution for this */
	
	
	pinMode(A2, OUTPUT);
	digitalWrite(A2, LOW);       // GND pin
	pinMode(A3, OUTPUT);
	digitalWrite(A3, HIGH);      // VCC pin
	
    Wire.begin();
}

/******************************************************************************
 * Global Functions
 ******************************************************************************/

/**********************************************************
 * GetTemperature
 *  Gets the current temperature from the sensor.
 *
 * @return float - The local temperature in degrees C
 **********************************************************/
float LibTempTMP421::GetTemperature(void) {
    uint8_t in[2];
    float frac = 0.0;
    uint8_t bit;
	
    setPtrLoc(0x00);                //high-byte
    in[0] = getRegisterValue();
	
    setPtrLoc(0x10);                //low-byte
    in[1] = getRegisterValue();
    in[1] >>=4;                     //shift-off the unused bits
	
    if (in[0] == -999 || in[1] == -999) {
		frac = -999;
    }
    else {
		/* Assemble the fraction */
		bit = in[1] & 0x01;
		frac += (bit * 0.5) * (bit * 0.5) * (bit * 0.5) * (bit * 0.5);
		
		in[1] >>= 1;
		bit = in[1] & 0x01;
		frac += (bit * 0.5) * (bit * 0.5) * (bit * 0.5);
		
		in[1] >>= 1;
		bit = in[1] & 0x01;
		frac += (bit * 0.5) * (bit * 0.5);
		
		in[1] >>= 1;
		bit = in[1] & 0x01;
		frac += (bit * 0.5);
		
		/* Add the MSB to the fraction */
		frac += in[0];
		
		/* frac is unsigned, make it signed to allow for negative temps */
		if (frac > 128.0)
			frac -= 256;
    }
    return frac;
}

/**********************************************************
 * getRegisterValue
 *  Get the TMP421 register value via I2C
 *
 * @return uint8_t - The register value
 **********************************************************/
uint8_t LibTempTMP421::getRegisterValue(void) {
	
    int TMP_err = Wire.requestFrom(0x2A, 1);
    if (TMP_err != 0) {
		while(Wire.available() <= 0) {
			; //wait
		}
		return Wire.read();
    }
    else {
		return -999;
    }
}

/**********************************************************
 * setPtrLoc
 *  Sets the TMP421 pointer register location via I2C
 *
 * @param ptrLoc - The pointer register address
 **********************************************************/
void LibTempTMP421::setPtrLoc(uint8_t ptrLoc) {
	
    //Set the pointer location
    Wire.beginTransmission(0x2A);   //begin
    Wire.write(ptrLoc);             //send the pointer location
    Wire.endTransmission();         //end
    delay(8);
}

