/**************************************************************************/
/*!
    @file     MCP342X.h
    @author   C. Schnarel
	@license  BSD (see license.txt)

    This is part of an Arduino library to interface with the Microchip
    MCP47X6 series of Analog-to-Digital converters which are connected
    via the I2C bus.

    MCP342X I2C device class header file
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

#ifndef _MCP342X_H_
#define _MCP342X_H_

#ifdef ARDUINO
    #if ARDUINO < 100
        #include "WProgram.h"
    #else
        #include "Arduino.h"
    #endif
#else
    #include "ArduinoWrapper.h"
#endif

#include <Wire.h>

// I2C Address of device
// MCP3421, MCP3425 & MCP3426 are factory programed for any of 0x68 thru 0x6F
#define MCP342X_DEFAULT_ADDRESS	0x68

// MCP3422, MCP3423, MCP3424, MCP3427 & MCP3428 addresses are controlled by address lines A0 and A1
// each address line can be low (GND), high (VCC) or floating (FLT)
#define MCP342X_A0GND_A1GND		0x68
#define MCP342X_A0GND_A1FLT		0x69
#define MCP342X_A0GND_A1VCC		0x6A
#define MCP342X_A0FLT_A1GND		0x6B
#define MCP342X_A0VCC_A1GND		0x6C
#define MCP342X_A0VCC_A1FLT		0x6D
#define MCP342X_A0VCC_A1VCC		0x6E
#define MCP342X_A0FLT_A1VCC		0x6F


// Conversion mode definitions
#define MCP342X_MODE_ONESHOT	0x00
#define MCP342X_MODE_CONTINUOUS	0x10


// Channel definitions
// MCP3421 & MCP3425 have only the one channel and ignore this param
// MCP3422, MCP3423, MCP3426 & MCP3427 have two channels and treat 3 & 4 as repeats of 1 & 2 respectively
// MCP3424 & MCP3428 have all four channels
#define	MCP342X_CHANNEL_1	0x00
#define	MCP342X_CHANNEL_2	0x20
#define	MCP342X_CHANNEL_3	0x40
#define	MCP342X_CHANNEL_4	0x60
#define	MCP342X_CHANNEL_MASK	0x60


// Sample size definitions - these also affect the sampling rate
// 12-bit has a max sample rate of 240sps
// 14-bit has a max sample rate of  60sps
// 16-bit has a max sample rate of  15sps
// 18-bit has a max sample rate of   3.75sps (MCP3421, MCP3422, MCP3423, MCP3424 only)
#define MCP342X_SIZE_12BIT	0x00
#define MCP342X_SIZE_14BIT	0x04
#define MCP342X_SIZE_16BIT	0x08
#define MCP342X_SIZE_18BIT	0x0C
#define MCP342X_SIZE_MASK	0x0C


// Programmable Gain definitions
#define MCP342X_GAIN_1X	0x00
#define MCP342X_GAIN_2X	0x01
#define MCP342X_GAIN_4X	0x02
#define MCP342X_GAIN_8X	0x03
#define MCP342X_GAIN_MASK 0x03


// /RDY bit definition
#define MCP342X_RDY	0x80


class MCP342X {
    public:
        MCP342X();
        MCP342X(uint8_t address);

        bool testConnection(void);

        // Set/Get the configuration bits for the ADC
        void configure(uint8_t config);
        uint8_t getConfigRegShdw(void);
	   //float getStepSize(); // returns step size based on configRegShdw

        // Start a conversion
        bool startConversion(void);
        bool startConversion(uint8_t channel);

        // Read the ADC result
        uint8_t getResult(int16_t *data);
        uint8_t getResult(int32_t *data);

        // Non-blocking Read the ADC result
        uint8_t checkforResult(int16_t *data);
        uint8_t checkforResult(int32_t *data);

    private:
        uint8_t devAddr;
        uint8_t configRegShdw;
	//float	stepSizeTbl[];
};

#endif /* _MCP342X_H_ */
