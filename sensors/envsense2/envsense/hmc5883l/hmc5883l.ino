#include <Wire.h>

#define HMC5883_ADDRESS_MAG            (0x3C >> 1)         // 0011110x
#define SENSORS_GAUSS_TO_MICROTESLA       (100)                   /**< Gauss to micro-Tesla multiplier */
typedef enum
{
    HMC5883_REGISTER_MAG_CRA_REG_M             = 0x00,
    HMC5883_REGISTER_MAG_CRB_REG_M             = 0x01,
    HMC5883_REGISTER_MAG_MR_REG_M              = 0x02,
    HMC5883_REGISTER_MAG_OUT_X_H_M             = 0x03,
    HMC5883_REGISTER_MAG_OUT_X_L_M             = 0x04,
    HMC5883_REGISTER_MAG_OUT_Z_H_M             = 0x05,
    HMC5883_REGISTER_MAG_OUT_Z_L_M             = 0x06,
    HMC5883_REGISTER_MAG_OUT_Y_H_M             = 0x07,
    HMC5883_REGISTER_MAG_OUT_Y_L_M             = 0x08,
    HMC5883_REGISTER_MAG_SR_REG_Mg             = 0x09,
    HMC5883_REGISTER_MAG_IRA_REG_M             = 0x0A,
    HMC5883_REGISTER_MAG_IRB_REG_M             = 0x0B,
    HMC5883_REGISTER_MAG_IRC_REG_M             = 0x0C,
    HMC5883_REGISTER_MAG_TEMP_OUT_H_M          = 0x31,
    HMC5883_REGISTER_MAG_TEMP_OUT_L_M          = 0x32
} hmc5883MagRegisters_t;
float HMC5883_data_x, HMC5883_data_y, HMC5883_data_z;
static float _hmc5883_Gauss_LSB_XY = 1100.0F;  // Varies with gain
static float _hmc5883_Gauss_LSB_Z  = 980.0F;   // Varies with gain
#ifndef WindVel_ADD
/*
 * Enables the magnetometer, and sets gain to the proper level
 * :rtype:boolean
 */
bool HMC5883_begin()
{
    // Enable I2C
    Wire.begin();
    
    // Enable the magnetometer
    i2c_write8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_MR_REG_M, 0x00);
    
    // Set the gain to a known level
    i2c_write8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_CRB_REG_M, (byte)0x20);
    return true;
}
#endif  // WindVel

/*
 * Read magnetic field data and process it
 * :rtype:void
 */
void HMC5883_getEvent() {
    /* Clear the event */
    HMC5883_data_x = 0;
    HMC5883_data_y = 0;
    HMC5883_data_z = 0;
    
    /* Read new data */
    HMC5883_read();
    
    /* Process the raw data */
    HMC5883_data_x = HMC5883_data_x / _hmc5883_Gauss_LSB_XY * SENSORS_GAUSS_TO_MICROTESLA;
    HMC5883_data_y = HMC5883_data_y / _hmc5883_Gauss_LSB_XY * SENSORS_GAUSS_TO_MICROTESLA;
    HMC5883_data_z = HMC5883_data_z / _hmc5883_Gauss_LSB_Z * SENSORS_GAUSS_TO_MICROTESLA;
}

/*
 * Obtain raw data from the sensor
 * :rtype:void
 */
void HMC5883_read()
{
    // Read 6 bytes from the magnetometer
    Wire.beginTransmission((byte)HMC5883_ADDRESS_MAG);
    #if ARDUINO >= 100
    Wire.write(HMC5883_REGISTER_MAG_OUT_X_H_M);
    #else
    Wire.send(HMC5883_REGISTER_MAG_OUT_X_H_M);
    #endif
    Wire.endTransmission();
    Wire.requestFrom((byte)HMC5883_ADDRESS_MAG, (byte)6);
    
    // Wait around until enough data is available
    while (Wire.available() < 6);
    
    // Note high before low (different than accel)  
    uint8_t xhi = Wire.read();
    uint8_t xlo = Wire.read();
    uint8_t zhi = Wire.read();
    uint8_t zlo = Wire.read();
    uint8_t yhi = Wire.read();
    uint8_t ylo = Wire.read();
    
    // Shift values to create properly formed integer (low byte first)
    HMC5883_data_x = (int16_t)(xlo | ((int16_t)xhi << 8));
    HMC5883_data_y = (int16_t)(ylo | ((int16_t)yhi << 8));
    HMC5883_data_z = (int16_t)(zlo | ((int16_t)zhi << 8));
}
static void i2c_write8(uint8_t address, byte reg, uint8_t value)
{
    Wire.beginTransmission((uint8_t)address);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t)value);
    Wire.endTransmission();
}

/*
 * This function reads an 8 bit value over I2C
 */
static void i2c_read8(byte address, byte reg, uint8_t *value)
{
    Wire.beginTransmission((uint8_t)address);
    Wire.write((uint8_t)reg);
    Wire.endTransmission();
    int err = Wire.requestFrom((uint8_t)address, (byte)1);
    if (err != 0) {
        *value = Wire.read();
    }
    else {
        *value = -999;
    }
    Wire.endTransmission();
}

/*
 * This function reads a 16 bit value over I2C
 * :rtype:static void
 */
static void i2c_read16(byte address, byte reg, uint16_t *value)
{
    Wire.beginTransmission((uint8_t) address);
    Wire.write((uint8_t)reg);
    Wire.endTransmission();
    int err = Wire.requestFrom((uint8_t) address, (byte)2);
    if (err != 0) {
        *value = (Wire.read() << 8) | Wire.read();
    }
    else{
        *value = -999;
    }
    Wire.endTransmission();
}

/*
 * This function writes a 16 bit value over I2C
 * For the use of BMP180, it determines the factory-written coefficients
 * :rtype:static void
 */
static void i2c_readS16(byte address, byte reg, int16_t *value)
{
    uint16_t i;
    i2c_read16(address, reg, &i);
    *value = (int16_t)i;
}

void setup() {
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(57600);
  Serial.println("here1");
        HMC5883_begin();    // function called in POST
        Serial.println("here2");
        delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  
        HMC5883_getEvent();
        Serial.print("WXSensor;");
        Serial.print("HMC5883_X_uT:");
        Serial.print(HMC5883_data_x);
        Serial.print(";");
        Serial.print("HMC5883_Y_uT:");
        Serial.print(HMC5883_data_y);
        Serial.print(";");
        Serial.print("HMC5883_Z_uT:");
        Serial.print(HMC5883_data_z);
        Serial.print(";");
        Serial.println("WXSensor");
        delay(500);
}
