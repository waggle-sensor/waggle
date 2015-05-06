#include <Wire.h>
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

#define HMC5883_ADDRESS_MAG            (0x3C >> 1)         // 0011110x

// DELAY: 1  - Sampling Rate: 310  Hz    Max observed freq: 155   Hz   Max observed speed: 168.6 m/s
// DELAY: 2  - Sampling Rate: 238  Hz    Max observed freq: 119   Hz   Max observed speed: 129.4 m/s
// DELAY: 3  - Sampling Rate: 192  Hz    Max observed freq: 96    Hz   Max observed speed: 104.4 m/s
// DELAY: 4  - Sampling Rate: 160  Hz    Max observed freq: 80    Hz   Max observed speed: 87.0  m/s
// DELAY: 5  - Sampling Rate: 139  Hz    Max observed freq: 69.5  Hz   Max observed speed: 75.6  m/s
// DELAY: 6  - Sampling Rate: 121  Hz    Max observed freq: 60.5  Hz   Max observed speed: 65.8  m/s
// DELAY: 7  - Sampling Rate: 109  Hz    Max observed freq: 54.5  Hz   Max observed speed: 59.3  m/s
// DELAY: 8  - Sampling Rate: 98.4 Hz    Max observed freq: 49.20 Hz   Max observed speed: 53.5  m/s
// DELAY: 9  - Sampling Rate: 89.3 Hz    Max observed freq: 44.65 Hz   Max observed speed: 48.6  m/s
// DELAY: 10 - Sampling Rate: 81.7 Hz    Max observed freq: 41.35 Hz   Max observed speed: 45.0  m/s
// DELAY: 15 - Sampling Rate: 58.1 Hz    Max observed freq: 29.05 Hz   Max observed speed: 31.6  m/s
// DELAY: 20 - Sampling Rate: 45.0 Hz    Max observed freq: 20.50 Hz   Max observed speed: 22.3  m/s
// DELAY: 25 - Sampling Rate: 36.8 Hz    Max observed freq: 18.40 Hz   Max observed speed: 20.0  m/s
int sample_delay = 4;// Give sensor time to take measurement (must be >= 1)
float sample_rate = 160.0;
// This delay sets the sampling frequency. 
// The rest of the measurement takes ~2.4 ms

int previous=0;
float freq = 0.0;
int sample_time = 3;    // Seconds to sample
float speed_mps = 0;

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


void HMC5883_setDataReady(uint8_t data) {
    /* Sets the DRDY bit for first single measurement to occur */
    data = data & 0x01;     // Make sure to only set one bit
    uint8_t drdy;
    i2c_read8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_SR_REG_Mg, &drdy);   // Get current bit
    drdy = drdy & 0xFE;     // Clear last bit
    drdy = drdy | data;     // Set last bit to desired value
    i2c_write8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_SR_REG_Mg, drdy);    
}

void HMC5883_setSingleMeasurementMode() {
    /* Put the sensor into single measurement mode */
    uint8_t value;
    
    i2c_read8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_MR_REG_M, &value);
    value &= 0b11111100;
    value |= 0b01;  // Single measurement
    
    i2c_write8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_MR_REG_M, value);
}

void take_wind_samples()
// Collects samples and generates FHT array
{
    // Initially, data NOT ready
    HMC5883_setDataReady(0);
    #ifdef POST
    wdt_reset();
    #endif
    int sign = 0;
    for (int i = 0; i<sample_rate*sample_time; i++)
    {
        HMC5883_setSingleMeasurementMode(); // Let the measurement begin
        delay(sample_delay); // Give sensor time to take measurement(must be >=1)   
        byte ready_bit;     
        i2c_read8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_SR_REG_Mg, &ready_bit);
        while((ready_bit & 0x01) != 0x01)
            i2c_read8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_SR_REG_Mg, &ready_bit);
        // DRDY bit monitoring only needed for high sampling frequencies
        
        // Read 16 bit Y value output
        int16_t y_val;
        Wire.beginTransmission(HMC5883_ADDRESS_MAG);  // Open communication w/ HMC
        Wire.write(HMC5883_REGISTER_MAG_OUT_Y_H_M);   // Send call to register Y output
        Wire.endTransmission();
        Wire.beginTransmission(HMC5883_ADDRESS_MAG);     // Begin reading
        Wire.requestFrom(HMC5883_ADDRESS_MAG, 2);     // Request 2 bytes
        while(!Wire.available()) {};
        uint8_t vha = Wire.read();
        uint8_t vla = Wire.read();
        Wire.endTransmission();
        y_val = vha << 8 | vla;          // Adjust output for MSB's and LSB's
        
        if(y_val < 0)   // Establish new hemisphere
            sign = -1;
        else
            sign = 1;
        
        if(sign != previous)    // If hemisphere differs from previous,
        {                       // Count it as a rotation
            previous = sign;
            if(i!=0)            // First measurement to establish initial hemisphere
                freq++;
        }
    }
    freq = freq/2/sample_time;  //Overcounted originally
}

/**************************************************************************/
/*!
 *   @brief  Writes an 8 bit value over I2C
 */
/**************************************************************************/
static void i2c_write8(uint8_t address, byte reg, uint8_t value)
{
    Wire.beginTransmission((uint8_t)address);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t)value);
    Wire.endTransmission();
}

/**************************************************************************/
/*!
 *   @brief  Reads an 8 bit value over I2C
 */
/**************************************************************************/
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

void calc_windspeed()
// .684 offset only to be used when freq > 0
// Coefficient determined experimentally to be .7324
{
    speed_mps = freq * .7324 + .684*(freq>0); // constant obtained experimentally in wind tunnel
    #ifdef POST
    wdt_reset();
    #endif
}

void setup()
{
    Serial.begin(57600);
    HMC5883_begin();
    HMC5883_setSingleMeasurementMode();
    delay(5);
}

void loop()
{
        take_wind_samples(); // Takes samples, take find frequency of them
        calc_windspeed();    // Calculate speed based from frequency in meters/sec
        
        Serial.print("WXSensor;");
        Serial.print("WindVel_1_F_RPS:");
        Serial.print(freq);
        Serial.print(";");
        Serial.print("WindVel_1_V_M/S:");
        Serial.print(speed_mps);
        Serial.print(";");
        Serial.println("WXSensor");
}