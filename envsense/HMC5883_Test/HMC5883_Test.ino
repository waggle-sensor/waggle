// #include <HMC5883.h>
// #include <Adafruit_Sensor.h>
#include <Wire.h>
#define SENSORS_GAUSS_TO_MICROTESLA       (100)                   /**< Gauss to micro-Tesla multiplier */
#define HMC5883_ADDRESS_MAG            (0x3C >> 1)         // 0011110x
// typedef struct
// {
//     int32_t version;                          /**< must be sizeof(struct sensors_event_t) */
//     int32_t sensor_id;                        /**< unique sensor identifier */
//     int32_t type;                             /**< sensor type */
//     int32_t reserved0;                        /**< reserved */
//     int32_t timestamp;                        /**< time is in milliseconds */
//     union
//     {
//         float           data[4];
//         sensors_vec_t   acceleration;         /**< acceleration values are in meter per second per second (m/s^2) */
//         sensors_vec_t   magnetic;             /**< magnetic vector values are in micro-Tesla (uT) */
//         sensors_vec_t   orientation;          /**< orientation values are in degrees */
//         sensors_vec_t   gyro;                 /**< gyroscope values are in rad/s */
//         float           temperature;          /**< temperature is in degrees centigrade (Celsius) */
//         float           distance;             /**< distance in centimeters */
//         float           light;                /**< light in SI lux units */
//         float           pressure;             /**< pressure in hectopascal (hPa) */
//         float           relative_humidity;    /**< relative humidity in percent */
//         float           current;              /**< current in milliamps (mA) */
//         float           voltage;              /**< voltage in volts (V) */
//         sensors_color_t color;                /**< color in RGB component values */
//     };
// } sensors_event_t;
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

// hmc5883MagGain   _magGain;

int sensorID = 23181;
// Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(23181);
float data_x, data_y, data_z;
static float _hmc5883_Gauss_LSB_XY = 1100.0F;  // Varies with gain
static float _hmc5883_Gauss_LSB_Z  = 980.0F;   // Varies with gain
// float HMC5883_heading, HMC5883_declinationAngle, HMC5883_headingDegrees;
#ifndef WindVel_ADD
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
#endif
void HMC5883_getEvent() {
  /* Clear the event */
  data_x = 0;
  data_y = 0;
  data_z = 0;

  /* Read new data */
  HMC5883_read();
  
//   event->version   = sizeof(sensors_event_t);
//   event->sensor_id = sensorID;
//   event->type      = 2; // Sensor type Magnetic field
//   event->timestamp = 0;
  data_x = data_x / _hmc5883_Gauss_LSB_XY * SENSORS_GAUSS_TO_MICROTESLA;
  data_y = data_y / _hmc5883_Gauss_LSB_XY * SENSORS_GAUSS_TO_MICROTESLA;
  data_z = data_z / _hmc5883_Gauss_LSB_Z * SENSORS_GAUSS_TO_MICROTESLA;
}
void HMC5883_read()
{
  // Read the magnetometer
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
  data_x = (int16_t)(xlo | ((int16_t)xhi << 8));
  data_y = (int16_t)(ylo | ((int16_t)yhi << 8));
  data_z = (int16_t)(zlo | ((int16_t)zhi << 8));
}
static void i2c_write8(uint8_t address, byte reg, uint8_t value)
{
    Wire.beginTransmission((uint8_t)address);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t)value);
    Wire.endTransmission();
}

void setup()
{
    delay(2000);
    Serial.begin(57600);
    HMC5883_begin();
}

void loop()
{
    HMC5883_getEvent();
    Serial.print("WXSensor;");
    Serial.print("HMC5883_X_uT:");
    Serial.print(data_x);
    Serial.print(";");
    Serial.print("HMC5883_Y_uT:");
    Serial.print(data_y);
    Serial.print(";");
    Serial.print("HMC5883_Z_uT:");
    Serial.print(data_z);
    Serial.print(";");
    Serial.println("WXSensor");
    delay(1000);
}