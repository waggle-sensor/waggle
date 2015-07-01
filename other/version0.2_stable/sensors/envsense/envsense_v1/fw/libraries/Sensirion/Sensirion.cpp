/* ========================================================================== */
/*  Sensirion.cpp - Library for Sensirion SHT1x & SHT7x family temperature    */
/*    and humidity sensors                                                    */
/*  Created by Markus Schatzl, November 28, 2008                              */
/*  Released into the public domain                                           */
/*                                                                            */
/*  Revised (v1.1) by Carl Jackson, August 4, 2010                            */
/*  Rewritten (v2.0) by Carl Jackson, December 10, 2010                       */
/*    See README.txt file for details                                         */
/* ========================================================================== */
/*
 * Note: to make this library work with Arduino >= 1.0, you need to make two small changes to Sensirion.cpp:

    uncomment the line #include "WConstants.h" (by prepending '//')
    add a line #include "Arduino.h" after the block extern "C" { ... }", i.e. immediately 
    before the line that includes Sensirion.h 
 
 * */

/******************************************************************************
 * Includes
 ******************************************************************************/

extern "C" {
  // AVR LibC Includes
  #include <stddef.h>
  #include <stdint.h>
  #include <math.h>

  // Wiring Core Includes
//   #include "WConstants.h"
}
#include "Arduino.h"
#include "Sensirion.h"


/******************************************************************************
 * Definitions
 ******************************************************************************/

// Sensirion command definitions:      adr command r/w
const uint8_t MEAS_TEMP   = 0x03;   // 000  0001   1
const uint8_t MEAS_HUMI   = 0x05;   // 000  0010   1
const uint8_t STAT_REG_W  = 0x06;   // 000  0011   0
const uint8_t STAT_REG_R  = 0x07;   // 000  0011   1
const uint8_t SOFT_RESET  = 0x1e;   // 000  1111   0

// Status register writable bits
const uint8_t SR_MASK     = 0x07;

// getByte flags
const bool noACK  = false;
const bool ACK    = true;

// Temperature & humidity equation constants
  const float D1  = -40.1;          // for deg C @ 5V
  const float D2h =   0.01;         // for deg C, 14-bit precision
  const float D2l =   0.04;         // for deg C, 12-bit precision

//  const float C1  = -4.0000;        // for V3 sensors
//  const float C2h =  0.0405;        // for V3 sensors, 12-bit precision
//  const float C3h = -2.8000E-6;     // for V3 sensors, 12-bit precision
//  const float C2l =  0.6480;        // for V3 sensors, 8-bit precision
//  const float C3l = -7.2000E-4;     // for V3 sensors, 8-bit precision
  const float C1  = -2.0468;        // for V4 sensors
  const float C2h =  0.0367;        // for V4 sensors, 12-bit precision
  const float C3h = -1.5955E-6;     // for V4 sensors, 12-bit precision
  const float C2l =  0.5872;        // for V4 sensors, 8-bit precision
  const float C3l = -4.0845E-4;     // for V4 sensors, 8-bit precision

  const float T1  =  0.01;          // for V3 and V4 sensors
  const float T2h =  0.00008;       // for V3 and V4 sensors, 12-bit precision
  const float T2l =  0.00128;       // for V3 and V4 sensors, 8-bit precision


/******************************************************************************
 * Constructors
 ******************************************************************************/

Sensirion::Sensirion(uint8_t dataPin, uint8_t clockPin) {
  // Initialize private storage for library functions
  _pinData = dataPin;
  _pinClock = clockPin;
  _presult = NULL;                  // No pending measurement
  _stat_reg = 0x00;                 // Sensor status register default state

  // Initialize CLK signal direction
  // Note: All functions exit with CLK low and DAT in input mode
  pinMode(_pinClock, OUTPUT);

  // Return sensor to default state
  resetConnection();                // Reset communication link with sensor
  putByte(SOFT_RESET);              // Send soft reset command
}


/******************************************************************************
 * User functions
 ******************************************************************************/

// All-in-one (blocking): Returns temperature, humidity, & dewpoint
uint8_t Sensirion::measure(float *temp, float *humi, float *dew) {
  uint16_t rawData;
  uint8_t error;
  if (error = measTemp(&rawData))
    return error;
  *temp = calcTemp(rawData);
  if (error = measHumi(&rawData))
    return error;
  *humi = calcHumi(rawData, *temp);
  *dew = calcDewpoint(*humi, *temp);
  return 0 ;
}

// Initiate measurement.  If blocking, wait for result
uint8_t Sensirion::meas(uint8_t cmd, uint16_t *result, bool block) {
  uint8_t error, i;
#ifdef CRC_ENA
  _crc = bitrev(_stat_reg & SR_MASK);  // Initialize CRC calculation
#endif
  startTransmission();
  if (cmd == TEMP)
    cmd = MEAS_TEMP;
  else
    cmd = MEAS_HUMI;
  if (error = putByte(cmd))
    return error;
#ifdef CRC_ENA
  calcCRC(cmd, &_crc);              // Include command byte in CRC calculation
#endif
  // If non-blocking, save pointer to result and return
  if (!block) {
    _presult = result;
    return 0;
  }
  // Otherwise, wait for measurement to complete with 720ms timeout
  i = 240;
  while (digitalRead(_pinData)) {
    i--;
    if (i == 0)
      return S_Err_TO;              // Error: Timeout
    delay(3);
  }
  error = getResult(result);
  return error;
}

// Check if non-blocking measurement has completed
// Non-zero return indicates complete (with or without error)
uint8_t Sensirion::measRdy(void) {
  uint8_t error = 0;
  if (_presult == NULL)             // Already done?
    return S_Meas_Rdy;
  if (digitalRead(_pinData) != 0)   // Measurement ready yet?
    return 0;
  error = getResult(_presult);
  _presult = NULL;
  if (error)
    return error;                   // Only possible error is S_Err_CRC
  return S_Meas_Rdy;
}

// Get measurement result from sensor (plus CRC, if enabled)
uint8_t Sensirion::getResult(uint16_t *result) {
  uint8_t val;
#ifdef CRC_ENA
  val = getByte(ACK);
  calcCRC(val, &_crc);
  *result = val;
  val = getByte(ACK);
  calcCRC(val, &_crc);
  *result = (*result << 8) | val;
  val = getByte(noACK);
  val = bitrev(val);
  if (val != _crc) {
    *result = 0xFFFF;
    return S_Err_CRC;
  }
#else
  *result = getByte(ACK);
  *result = (*result << 8) | getByte(noACK);
#endif
  return 0;
}

// Write status register
uint8_t Sensirion::writeSR(uint8_t value) {
  uint8_t error;
  value &= SR_MASK;                 // Mask off unwritable bits
  _stat_reg = value;                // Save local copy
  startTransmission();
  if (error = putByte(STAT_REG_W))
    return error;
  return putByte(value);
}

// Read status register
uint8_t Sensirion::readSR(uint8_t *result) {
  uint8_t val;
  uint8_t error = 0;
#ifdef CRC_ENA
  _crc = bitrev(_stat_reg & SR_MASK);  // Initialize CRC calculation
#endif
  startTransmission();
  if (error = putByte(STAT_REG_R)) {
    *result = 0xFF;
    return error;
  }
#ifdef CRC_ENA
  calcCRC(STAT_REG_R, &_crc);       // Include command byte in CRC calculation
  *result = getByte(ACK);
  calcCRC(*result, &_crc);
  val = getByte(noACK);
  val = bitrev(val);
  if (val != _crc) {
    *result = 0xFF;
    error = S_Err_CRC;
  }
#else
  *result = getByte(noACK);
#endif
  return error;
}

// Public reset function
// Note: Soft reset returns sensor status register to default values
uint8_t Sensirion::reset(void) {
  _stat_reg = 0x00;                 // Sensor status register default state
  resetConnection();                // Reset communication link with sensor
  return putByte(SOFT_RESET);       // Send soft reset command & return status
}


/******************************************************************************
 * Sensirion data communication
 ******************************************************************************/

// Write byte to sensor and check for acknowledge
uint8_t Sensirion::putByte(uint8_t value) {
  uint8_t mask, i;
  uint8_t error = 0;
  pinMode(_pinData, OUTPUT);        // Set data line to output mode
  mask = 0x80;                      // Bit mask to transmit MSB first
  for (i = 8; i > 0; i--) {
    digitalWrite(_pinData, value & mask);
    PULSE_SHORT;
    digitalWrite(_pinClock, HIGH);  // Generate clock pulse
    PULSE_LONG;
    digitalWrite(_pinClock, LOW);
    PULSE_SHORT;
    mask >>= 1;                     // Shift mask for next data bit
  }
  pinMode(_pinData, INPUT);         // Return data line to input mode
#ifdef DATA_PU
  digitalWrite(_pinData, DATA_PU);  // Restore internal pullup state
#endif
  digitalWrite(_pinClock, HIGH);    // Clock #9 for ACK
  PULSE_LONG;
  if (digitalRead(_pinData))        // Verify ACK ('0') received from sensor
    error = S_Err_NoACK;
  PULSE_SHORT;
  digitalWrite(_pinClock, LOW);     // Finish with clock in low state
  return error;
}

// Read byte from sensor and send acknowledge if "ack" is true
uint8_t Sensirion::getByte(bool ack) {
  uint8_t i;
  uint8_t result = 0;
  for (i = 8; i > 0; i--) {
    result <<= 1;                   // Shift received bits towards MSB
    digitalWrite(_pinClock, HIGH);  // Generate clock pulse
    PULSE_SHORT;
    result |= digitalRead(_pinData);  // Merge next bit into LSB position
    digitalWrite(_pinClock, LOW);
    PULSE_SHORT;
  }
  pinMode(_pinData, OUTPUT);
  digitalWrite(_pinData, !ack);     // Assert ACK ('0') if ack == 1
  PULSE_SHORT;
  digitalWrite(_pinClock, HIGH);    // Clock #9 for ACK / noACK
  PULSE_LONG;
  digitalWrite(_pinClock, LOW);     // Finish with clock in low state
  PULSE_SHORT;
  pinMode(_pinData, INPUT);         // Return data line to input mode
#ifdef DATA_PU
  digitalWrite(_pinData, DATA_PU);  // Restore internal pullup state
#endif
  return result;
}


/******************************************************************************
 * Sensirion signaling
 ******************************************************************************/

// Generate Sensirion-specific transmission start sequence
// This is where Sensirion does not conform to the I2C standard and is
// the main reason why the AVR TWI hardware support can not be used.
//       _____         ________
// DATA:      |_______|
//           ___     ___
// SCK : ___|   |___|   |______
void Sensirion::startTransmission(void) {
  digitalWrite(_pinData, HIGH);  // Set data register high before turning on
  pinMode(_pinData, OUTPUT);     // output driver (avoid possible low pulse)
  PULSE_SHORT;
  digitalWrite(_pinClock, HIGH);
  PULSE_SHORT;
  digitalWrite(_pinData, LOW);
  PULSE_SHORT;
  digitalWrite(_pinClock, LOW);
  PULSE_LONG;
  digitalWrite(_pinClock, HIGH);
  PULSE_SHORT;
  digitalWrite(_pinData, HIGH);
  PULSE_SHORT;
  digitalWrite(_pinClock, LOW);
  PULSE_SHORT;
  // Unnecessary here since putByte always follows startTransmission
//  pinMode(_pinData, INPUT);
}

// Communication link reset
// At least 9 SCK cycles with DATA=1, followed by transmission start sequence
//      ______________________________________________________         ________
// DATA:                                                      |_______|
//          _    _    _    _    _    _    _    _    _        ___     ___
// SCK : __| |__| |__| |__| |__| |__| |__| |__| |__| |______|   |___|   |______
void Sensirion::resetConnection(void) {
  uint8_t i;
  digitalWrite(_pinData, HIGH);  // Set data register high before turning on
  pinMode(_pinData, OUTPUT);     // output driver (avoid possible low pulse)
  PULSE_LONG;
  for (i = 0; i < 9; i++) {
    digitalWrite(_pinClock, HIGH);
    PULSE_LONG;
    digitalWrite(_pinClock, LOW);
    PULSE_LONG;
  }
  startTransmission();
}


/******************************************************************************
 * Helper Functions
 ******************************************************************************/

// Calculates temperature in degrees C from raw sensor data
float Sensirion::calcTemp(uint16_t rawData) {
  if (_stat_reg & LOW_RES)
    return D1 + D2l * (float) rawData;
  else
    return D1 + D2h * (float) rawData;
}

// Calculates relative humidity from raw sensor data
//   (with temperature compensation)
float Sensirion::calcHumi(uint16_t rawData, float temp) {
  float humi;
  if (_stat_reg & LOW_RES) {
    humi = C1 + C2l * rawData + C3l * rawData * rawData;
    humi = (temp - 25.0) * (T1 + T2l * rawData) + humi;
  } else {
    humi = C1 + C2h * rawData + C3h * rawData * rawData;
    humi = (temp - 25.0) * (T1 + T2h * rawData) + humi;
  }
  if (humi > 100.0) humi = 100.0;
  if (humi < 0.1) humi = 0.1;
  return humi;
}

// Calculates dew point in degrees C
float Sensirion::calcDewpoint(float humi, float temp) {
  float k;
  k = log(humi/100) + (17.62 * temp) / (243.12 + temp);
  return 243.12 * k / (17.62 - k);
}

#ifdef CRC_ENA
// Calculate CRC for a single byte
void Sensirion::calcCRC(uint8_t value, uint8_t *crc) {
  const uint8_t POLY = 0x31;   // Polynomial: x**8 + x**5 + x**4 + 1
  uint8_t i;
  *crc ^= value;
  for (i = 8; i > 0; i--) {
    if (*crc & 0x80)
      *crc = (*crc << 1) ^ POLY;
    else
      *crc = (*crc << 1);
  }
}

// Bit-reverse a byte (for CRC calculations)
uint8_t Sensirion::bitrev(uint8_t value) {
  uint8_t i;
  uint8_t result = 0;
  for (i = 8; i > 0; i--) {
    result = (result << 1) | (value & 0x01);
    value >>= 1;
  }
  return result;
}
#endif
