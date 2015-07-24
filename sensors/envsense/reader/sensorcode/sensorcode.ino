// Sensor Cluster Code, version 5
// Using interrupts, gets readings from three time-sensitive sensors (noise, wind velocity, and
// acceleration) every 6 seconds in order to calculate average values for these sensors, and
// gets readings from all other sensors once every 30 seconds
// Prevents the board from hanging if a sensor is disconnected
// Allows bad sensor readings to be silenced for about a third of the sensors (incomplete)
// Time between readings can be adjusted

// Edited By: Kaitlyn MacIntyre
// Updated: 09/08/14

// BOF preprocessor bug prevent - insert me on top of your arduino-code
// From: http://www.a-control.de/arduino-fehler/?lang=en
// From: http://subethasoftware.com/2013/04/09/arduino-compiler-problem-with-ifdefs-solved/
// From: http://forum.arduino.cc/index.php?PHPSESSID=8395001def82bee5b565614dc4f2d89d&topic=158885.0

#define nop() __asm volatile ("nop")
#if 1
nop();
#endif
/*
 * EOF preprocessor bug prevent
 */

#include <OneWire.h>
#include <dht.h>
#include <Wire.h>
#include <EEPROM.h>
#include <avr/wdt.h>
#include <Sensirion.h>
#include <i2cmaster.h>
#include "HTU21D.h"
#include "features_v2.c"

int counter = 0;
volatile int current_time = 0;
int sleep_time_loop = int(13500.0/MMA_Buff_size);
byte board_ID[8];

#ifdef HMC5883_ADD
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
#endif //HMC5883_ADD


#ifdef IR_D6T_44L_06_ADD
#define I2C_ADD 1
int rbuf[35];
float tdata[16];
float t_PTAT;
float tPEC;
bool data_check;

/* 
 * Get data from the D6T Sensor through I2C bus
 * Data is stored in array tdata
 * :rtype:boolean
 */
bool D6T_get_data(void) {
    int k, start_err = 0, write_err = 0;
    start_err = i2c_start(0x14);
    if (start_err == 1) return false;
    write_err = i2c_write(0x4C);
    if (write_err == 1) return false;
    #ifdef POST
    wdt_reset();
    #endif
    start_err = i2c_rep_start(0x15);
    if (start_err == 1) return false;
    for (k = 0; k < 35; k++) {
        if (k == 34) {
            rbuf[k] = i2c_readNak();
        }
        else {
            rbuf[k] = i2c_readAck();
        }
        #ifdef POST
        wdt_reset();
        #endif
    }
    for (int j = 0; j<35; j++) {
        if (rbuf[j] == -999)
            return false;
    }
    i2c_stop();
    #ifdef POST
    wdt_reset();
    #endif
    
    if (!D6T_checkPEC(rbuf, 34)) {
        return false;
    }
    else {
        t_PTAT = (rbuf[0]+(rbuf[1]<<8))*0.1;
        for (k = 0; k < 16; k++) {
            tdata[k]=(rbuf[(k*2+2)]+(rbuf[(k*2+3)]<<8))*0.1;
            #ifdef POST
            wdt_reset();
            #endif
        }
        tPEC = rbuf[34];
        return true;
    }
}

/*
 * Prints the data of the sensor neatly
 * :rtype:void
 */
void output_csv() {
    Serial.print(t_PTAT);
    Serial.print(",");
    for (int i = 0; i < 16; i++) {
        Serial.print(tdata[i]);
        if (i < 15) {
            Serial.print(",");
        }
    }
}

/*
 * Check the PEC of the reading. PEC check is
 * performed using CSC-8. You can detect communication
 * failures using the PEC, improving reliability of the data.
 * :rtype:int
 */
int D6T_checkPEC(int* buf, int pPEC) {
    byte crc;
    
    crc = calc_crc(0x14);
    crc = calc_crc(0x4C ^ crc);
    crc = calc_crc(0x15 ^ crc);
    for (int i=0; i<pPEC; i++) {
        crc = calc_crc(buf[i] ^ crc);
        #ifdef POST
        wdt_reset();
        #endif
    }
    return (crc == buf[pPEC]);
}

/*
 * Check validity of data with CRC
 * :rtype:byte
 */
byte calc_crc(byte data) {
    for (int index=0; index<8; index++) {
        byte temp = data;
        data = data<<1;
        if (temp & 0x80) data = data ^ 0x07;
    }
    return data;
}
#endif //IR_D6T_44L_06_ADD


#ifdef MMA8452
#ifndef I2C_ADD
#define I2C_ADD 1
#endif //I2C_ADD
#define MMA8452_ADDRESS_WRITE 0x3A
#define MMA8452_ADDRESS_READ 0x3B
#define OUT_X_MSB 0x01
#define XYZ_DATA_CFG 0x0E
#define WHO_AM_I 0x0D
#define CTRL_REG1 0x2A
#define GSCALE 2



float xmean, ymean, zmean, rt_mean_sq;
bool MMA_found;
float xvals[MMA_Buff_size];
float yvals[MMA_Buff_size];
float zvals[MMA_Buff_size];
float xvar = 0, yvar = 0, zvar = 0, mean_square_var = 0;
unsigned int q = 0;

/*
 * This function finds the means to better interpret the
 * accelerometer data. It returns true if the data is good
 * and the process completes successfully
 * :rtype:void
 */
void MMA8452_get_means()
{
    int accelCount[3]; // Stores the 12-bit signed value
    float accelG[3]; // Stores the real accel value in g's
    
    bool good_data = readAccelData(accelCount); // Read the x/y/z adc values
    // Serial.println(accelCount[1]);
    
    
    
    if (good_data == false)
    {
        accelG[0] = -999;
        accelG[1] = -999;
        accelG[2] = -999;
        // return false;
    }
    
    else {
        for (int i = 0 ; i < 3 ; i++) {
            accelG[i] = (float) accelCount[i] / ((1<<12)/(2*GSCALE)); 
            // get actual g value, this depends on scale being set
        }
    }
    
    xvals[q] = accelG[0];
    yvals[q] = accelG[1];
    zvals[q] = accelG[2];
    
    xmean = (xmean*q+xvals[q])/(q+1);
    ymean = (ymean*q+yvals[q])/(q+1);
    zmean = (zmean*q+zvals[q])/(q+1);
    
    q++;
    
    // return true;
}

/*
 * Calculate the root mean square of the data across all 3 axes
 * :rtype:void
 */
void calc_MMA_RMS() {
    for (unsigned int j = 0; j < q; j++)
    {
        xvar += sq(xvals[j] - xmean);
        yvar += sq(yvals[j] - ymean);
        zvar += sq(zvals[j] - zmean);
    }
    
    mean_square_var = (sq(xvar) + sq(yvar) + sq(zvar))/3;
    rt_mean_sq = sqrt(mean_square_var);
}

bool readAccelData(int *destination)
{
    byte rawData[6]; // x/y/z accel register data stored here
    
    bool read_success = readRegisters(OUT_X_MSB, 6, rawData); 
    // Read the six raw data registers into data array
    
    if (read_success == false) return false;
    
    // Loop to calculate 12-bit ADC and g value for each axis
    for(int i = 0; i < 3 ; i++)
    {
        int gCount = (rawData[i*2] << 8) | rawData[(i*2)+1]; 
        //Combine the two 8 bit registers into one 12-bit number
        gCount >>= 4; //The registers are left align, here we right align the 12-bit integer
        
        // If the number is negative, we have to make it so manually (no 12-bit data type)
        if (rawData[i*2] > 0x7F)
        {
            gCount = ~gCount + 1;
            gCount *= -1; // Transform into negative 2's complement #
        }
        
        destination[i] = gCount; //Record this gCount into the 3 int array
    }
    return true;
}

/*
 * Initializes the MMA8452
 * :rtype:void
 */ 
bool initMMA8452()
{
    byte c = readRegister(WHO_AM_I); // Read WHO_AM_I register
    if (c == 0x2A); // WHO_AM_I should always be 0x2A
    else {
        return false;
    }
    MMA8452Standby(); // Must be in standby to change registers
    byte fsr = GSCALE;
    if(fsr > 8) fsr = 8; //Easy error check
    fsr >>= 2;
    writeRegister(XYZ_DATA_CFG, fsr);
    
    MMA8452Active(); // Set to active to start reading
    return true;
}

/*
 * Clears the MMA's active bit to go into standby mode
 * :rtype:void
 */
void MMA8452Standby()
{
    byte c = readRegister(CTRL_REG1);
    writeRegister(CTRL_REG1, c & ~(0x01)); 
}

/*
 * Set the active bit to begin detection
 * :rtype:void
 */
void MMA8452Active()
{
    byte c = readRegister(CTRL_REG1);
    writeRegister(CTRL_REG1, c | 0x01); 
}

/*
 * Performs command to read raw values from multiple registers
 * via I2C bus.
 * :rtype:boolean
 */
bool readRegisters(byte addressToRead, int bytesToRead, byte * dest)
{
    i2c_start(MMA8452_ADDRESS_WRITE);
    i2c_write(addressToRead);
    i2c_rep_start(MMA8452_ADDRESS_READ);
    
    for(int x = 0 ; x < bytesToRead ; x++)
    {
        if (x == bytesToRead - 1)
            dest[x] = i2c_readNak();
        else
            dest[x] = i2c_readAck();
        if (dest[x] == -999) 
        {
            
            i2c_stop();
            return false;
        }
    }
    //i2c_stop();
    return true;
}

/*
 * Performs command to read a raw value from a register
 * via I2C bus.
 * :rtype:byte
 */
byte readRegister(byte addressToRead)
{
    i2c_start(MMA8452_ADDRESS_WRITE); // Write address
    i2c_write(addressToRead);
    i2c_rep_start(MMA8452_ADDRESS_READ); // Read address
    //i2c_stop();
    
    return i2c_readNak();
}

/*
 * Performs command to write a raw value to a register
 * via I2C bus.
 * :rtype:byte
 */
void writeRegister(byte addressToWrite, byte dataToWrite)
{
    i2c_start(MMA8452_ADDRESS_WRITE);
    i2c_write(addressToWrite);
    i2c_write(dataToWrite);
    //i2c_stop();
}
#endif //MMA8452

#ifdef HIH4030_ADD
// #define HIH4030_PIN A2
int HIH4030_1_Value;
#endif //HIH4030_ADD

#ifdef MLX90614_ADD
#ifndef I2C_ADD
#include <i2cmaster.h>
#endif //I2C_ADD
int dev = 0x5A<<1;
int data_low = 0;
int data_high = 0;
int pec = 0;
double tempFactor = 0.02; // 0.02 degrees per LSB (measurement resolution of the MLX90614)
double tempData;
int frac; // data past the decimal point
float celcius;
float fahrenheit;
int start_err = 0, write_err = 0, rep_start_err = 0;
#endif //MLX90614_ADD

#ifdef PhoRes_ADD
// #define PhoRes_PIN A3
int PhoRes_1_Value;
#endif //PhoRes_ADD

#ifdef SHT15_ADD
#include <Sensirion.h>
#define Sensirion_ADD 1
// #define SHT15_1_dataPin  11     // SHT15_1 serial data
// #define SHT15_1_sclkPin  12     // SHT15_1 serial clock
float SHT15_1_temperature;
float SHT15_1_humidity;
uint16_t SHT15_1_rawData;
uint8_t SHT15_1_error;
Sensirion SHT15_1_tempSensor = Sensirion(SHT15_1_dataPin, SHT15_1_sclkPin);
#endif //SHT15_ADD

#ifdef SHT75_ADD
#ifndef Sensirion_ADD
#include <Sensirion.h>
#endif //Sensirion_ADD
// #define SHT75_1_dataPin 10  // SHT15_1 serial data
// #define SHT75_1_sclkPin 9   // SHT15_1 serial clock
float SHT75_1_temperature;
float SHT75_1_humidity;
uint16_t SHT75_1_rawData;
uint8_t SHT75_1_error;
Sensirion SHT75_1_tempSensor = Sensirion(SHT75_1_dataPin, SHT75_1_sclkPin);
#endif //SHT75_ADD

#ifdef GA1A1S201WP_ADD
// #define AMBI_1_Pin A6    // Ambient sensor
int AMBI_1_Value;
#endif //GA1A1S201WP_ADD

#ifdef MAX4466_ADD
// #define MAX4466_PIN 1
// const int MAX4466_Buff_Len = 100;
// int MAX4466_Val[MAX4466_Buff_Len];   // variable to store the value coming from the sensor
int MAX4466_Value = 0;

/*
 * Calcultes a new value by determining the max of a previous reading
 * and a new reading of the MAX sensor/*
 * :rtype:void
 */
void MAX4466_get_max()
{
    MAX4466_Value= max(MAX4466_Value,abs(512-analogRead(MAX4466_PIN)));
}
#endif //MAX4466_ADD

#ifdef THERMIS_100K_ADD
// #define THERMIS_100K_Pin 0    // NTC sensor
int THERMIS_1_Value;
#endif //THERMIS_100K_ADD

#ifdef DS18B20_ADD
// #define DS18B20_1_Pin 7
OneWire DS18B20_1_ds(DS18B20_1_Pin);  // Temperature chip i/o on digital pin 2
float DS18B20_1_temperature;

/*
 * Returns the temperature from one DS18B20 in DEG Celsius
 * :rtype:float
 */
float DS18B20_1_getTemp()
{
    byte data[12];
    byte addr[8];
    
    if (!DS18B20_1_ds.search(addr)) {
        //no more sensors on chain, reset search
        DS18B20_1_ds.reset_search();
        return -1000;
    }
    
    if ( OneWire::crc8( addr, 7) != addr[7]) {
        //Serial.println("CRC is not valid!");
        return -1000;
    }
    
    if ( addr[0] != 0x10 && addr[0] != 0x28) {
        //Serial.print("Device is not recognized");
        return -1000;
    }
    
    DS18B20_1_ds.reset();
    DS18B20_1_ds.select(addr);
    DS18B20_1_ds.write(0x44,1); // start conversion, with parasite power on at the end
    
    //   byte present = DS18B20_1_ds.reset();
    DS18B20_1_ds.reset();
    DS18B20_1_ds.select(addr);
    DS18B20_1_ds.write(0xBE); // Read Scratchpad
    
    for (int i = 0; i < 9; i++) { // we need 9 bytes
        data[i] = DS18B20_1_ds.read();
    }
    
    DS18B20_1_ds.reset_search();
    
    byte MSB = data[1];
    byte LSB = data[0];
    
    //float tempRead = ((MSB << 8) | LSB); //using two's compliment
    float tempRead = ((MSB << 8) | LSB); //using two's compliment
    float TemperatureSum;
    TemperatureSum = tempRead/16.0;
    return TemperatureSum;
}
#endif //DS18B20_ADD

#ifdef RHT03_ADD
// #define RHT03_1_PIN 8 // RHT03 Sensor pin
dht RHT03_1;
int chk_RHT03_1;
#endif //RHT03_ADD

#ifdef TMP102_ADD
const int tmp102_1_Address = 0x48;
float tmp102_1_temperature;
byte tmp102_1_MSB, tmp102_1_LSB;
int err;
#endif //TMP102_ADD

#ifdef HIH6130_ADD
//  Create an HIH61XX with I2C address 0x27, powered by pin 22, need to modify this
//  Taken directly from HIH61XX Library
uint8_t hih6130_address = 0x27;
uint8_t hih6130_powerPin = 22;
uint8_t f = 0;
uint16_t HIH61XX_humidity = 0;
uint16_t HIH61XX_temp = 0;
uint8_t NoError = 0;
uint8_t ConnectionError = 1;
uint8_t CommunicationError = 2;
uint8_t NotRunningError = 3;
uint8_t CommandModeError = 4;
uint8_t ErrorMask = 15;
uint8_t RunningFlag = 128;
uint8_t CommandModeFlag = 64;
uint8_t FlagsMask = ~ErrorMask;

/*
 * Sets the error for the HIH6130 chip
 * :rtype:uint8_t
 */
uint8_t setError(uint8_t error) { 
    f = (f & ~ErrorMask) | error; 
    return error; 
}

/*
 * Initializes the HIH6130 chip
 * :rtype:uint8_t
 */
uint8_t HIH61XX_start()
{
    if(hih6130_powerPin < 255) {
        digitalWrite(hih6130_powerPin, HIGH);
    }
    f |= RunningFlag;
    return setError(0);
}

/*
 * Obtains a new reading for HIH6130 measurement value
 * :rtype:uint8_t
 */
uint8_t HIH61XX_update()
{
    if(!(f & RunningFlag)) {
        f = (f & ~ErrorMask) | NotRunningError;
    }
    
    uint8_t x, y, s;
    
    Wire.beginTransmission(hih6130_address);
    int azer = Wire.endTransmission();
    if(azer == 0) {    
        while(true) {
            delay(10);
            
            int c = Wire.requestFrom(hih6130_address, (uint8_t) 4);
            if (c == 0) Serial.println("Problem with request");
            if(Wire.available()) {
                x = Wire.read();
                y = Wire.read();
                s = x >> 6;
                
                switch(s) { 
                    case 0:
                        HIH61XX_humidity = (((uint16_t) (x & 0x3f)) << 8) | y;
                        x = Wire.read();
                        y = Wire.read();
                        HIH61XX_temp = ((((uint16_t) x) << 8) | y) >> 2;
                        Wire.endTransmission();
                        return setError(0);
                        
                    case 1:
                        Wire.endTransmission();
                        break;
                        
                    case 2:
                        Wire.endTransmission();
                        return setError(CommandModeError);
                }
            }
            else {
                return setError(CommunicationError);
            }
        }
    }
    else {
        Serial.print("...");
        Serial.println(azer);
        return setError(ConnectionError);
    }
}

/*
 * Function to end the use of a HIH6130 chip
 * :rtype:uint8_t
 */
uint8_t HIH61XX_stop()
{
    if(hih6130_powerPin < 255) {
        digitalWrite(hih6130_powerPin, LOW);
    }
    f &= ~RunningFlag;
    return setError(0);
}
#endif //HIH6130_ADD

#ifdef TMP421_ADD
#include <inttypes.h>
float TMP421_1_temperature;

/*
 * getRegisterValue
 *  Get the TMP421 register value via I2C
 *
 * :rtype:uint8_t
 */
uint8_t TMP421_getRegisterValue(void) {
    
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

/*
 * setPtrLoc
 *  Sets the TMP421 pointer register location via I2C
 *
 * :rtype:void
 */
void TMP421_setPtrLoc(uint8_t ptrLoc) {
    
    //Set the pointer location
    Wire.beginTransmission(0x2A);   //begin
    Wire.write(ptrLoc);             //send the pointer location
    Wire.endTransmission();         //end
    delay(8);
}

/*
 * GetTemperature
 *  Gets the current temperature from the sensor.
 *
 * :rtype:float
 */
float TMP421_GetTemperature(void) {
    uint8_t in[2];
    float frac = 0.0;
    uint8_t bit;
    
    TMP421_setPtrLoc(0x00);                //high-byte
    in[0] = TMP421_getRegisterValue();
    
    TMP421_setPtrLoc(0x10);                //low-byte
    in[1] = TMP421_getRegisterValue();
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
#endif //TMP421_ADD

#ifdef BMP180_ADD
int BMP_mode = 3;         //BMP085_MODE_ULTRAHIGHRES
int32_t BMP_id = 10085;
uint8_t BMP_address = 0x77;
float BMP_180_temperature, BMP_180_pressure;


const int BMP085_MODE_ULTRALOWPOWER          = 0;
const int BMP085_MODE_STANDARD               = 1;
const int BMP085_MODE_HIGHRES                = 2;
const int BMP085_MODE_ULTRAHIGHRES           = 3;
enum
{
    BMP085_REGISTER_CAL_AC1            = 0xAA,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_AC2            = 0xAC,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_AC3            = 0xAE,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_AC4            = 0xB0,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_AC5            = 0xB2,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_AC6            = 0xB4,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_B1             = 0xB6,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_B2             = 0xB8,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_MB             = 0xBA,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_MC             = 0xBC,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CAL_MD             = 0xBE,  // R   Calibration data (16 bits)
    BMP085_REGISTER_CHIPID             = 0xD0,
    BMP085_REGISTER_VERSION            = 0xD1,
    BMP085_REGISTER_SOFTRESET          = 0xE0,
    BMP085_REGISTER_CONTROL            = 0xF4,
    BMP085_REGISTER_TEMPDATA           = 0xF6,
    BMP085_REGISTER_PRESSUREDATA       = 0xF6,
    BMP085_REGISTER_READTEMPCMD        = 0x2E,
    BMP085_REGISTER_READPRESSURECMD    = 0x34
};
int16_t bmp085_coeffs_ac1;
int16_t bmp085_coeffs_ac2;
int16_t bmp085_coeffs_ac3;
uint16_t bmp085_coeffs_ac4;
uint16_t bmp085_coeffs_ac5;
uint16_t bmp085_coeffs_ac6;
int16_t bmp085_coeffs_b1;
int16_t bmp085_coeffs_b2;
int16_t bmp085_coeffs_mb;
int16_t bmp085_coeffs_mc;
int16_t bmp085_coeffs_md;


/*
 * Initialize the BMP sensor
 * :rtype:bool
 */
bool BMP_begin()
{
    // Enable I2C
    Wire.begin();
    /* Mode boundary check */
    if ((BMP_mode > BMP085_MODE_ULTRAHIGHRES) || (BMP_mode < 0))
    {
        BMP_mode = BMP085_MODE_ULTRAHIGHRES;  
    }
    
    // Calibrate the device
    i2c_readS16(BMP_address, BMP085_REGISTER_CAL_AC1, &bmp085_coeffs_ac1);
    i2c_readS16(BMP_address, BMP085_REGISTER_CAL_AC2, &bmp085_coeffs_ac2);
    i2c_readS16(BMP_address, BMP085_REGISTER_CAL_AC3, &bmp085_coeffs_ac3);
    i2c_read16(BMP_address, BMP085_REGISTER_CAL_AC4, &bmp085_coeffs_ac4);
    i2c_read16(BMP_address, BMP085_REGISTER_CAL_AC5, &bmp085_coeffs_ac5);
    i2c_read16(BMP_address, BMP085_REGISTER_CAL_AC6, &bmp085_coeffs_ac6);
    i2c_readS16(BMP_address, BMP085_REGISTER_CAL_B1, &bmp085_coeffs_b1);
    i2c_readS16(BMP_address, BMP085_REGISTER_CAL_B2, &bmp085_coeffs_b2);
    i2c_readS16(BMP_address, BMP085_REGISTER_CAL_MB, &bmp085_coeffs_mb);
    i2c_readS16(BMP_address, BMP085_REGISTER_CAL_MC, &bmp085_coeffs_mc);
    i2c_readS16(BMP_address, BMP085_REGISTER_CAL_MD, &bmp085_coeffs_md);
    
    /* Make sure we have the right device */
    uint8_t checkid;
    
    // Read 8 from BMP085_REGISTER_CHIPID
    i2c_read8(BMP_address, BMP085_REGISTER_CHIPID, &checkid);
    if(checkid != 0x55)
    {
        return false;
    }
    return true;
}

/*
 * This function gets the compensated pressure level in kPa
 * :rtype:void
 */
void BMP180_getPressure(float *pressure)
{
    int32_t  ut = 0, up = 0, compp = 0;
    int32_t  x1, x2, b5, b6, x3, b3, p;
    uint32_t b4, b7;
    
    /* Get the raw pressure and temperature values */
    
    uint16_t t;
    i2c_write8(BMP_address, BMP085_REGISTER_CONTROL, BMP085_REGISTER_READTEMPCMD);
    delay(5);
    i2c_read16(BMP_address, BMP085_REGISTER_TEMPDATA, &t);
    ut = t;
    
    uint8_t  p8;
    uint16_t p16;
    int32_t  p32;
    
    i2c_write8(BMP_address, BMP085_REGISTER_CONTROL, BMP085_REGISTER_READPRESSURECMD + (BMP_mode << 6));
    switch(BMP_mode)
    {
        case BMP085_MODE_ULTRALOWPOWER:
            delay(5);
            break;
        case BMP085_MODE_STANDARD:
            delay(8);
            break;
        case BMP085_MODE_HIGHRES:
            delay(14);
            break;
        case BMP085_MODE_ULTRAHIGHRES:
        default:
            delay(26);
            break;
    }
    i2c_read16(BMP_address, BMP085_REGISTER_PRESSUREDATA, &p16);
    if (p16 != -999) {
        p32 = (uint32_t)p16 << 8;
        i2c_read8(BMP_address, BMP085_REGISTER_PRESSUREDATA+2, &p8);
        p32 += p8;
        p32 >>= (8 - BMP_mode);
        
        up = p32;
    }
    else {
        up = p16;
    }
    
    if (ut != -999 && up != -999) {
        /* Temperature compensation */
        x1 = (ut - (int32_t)(bmp085_coeffs_ac6))*((int32_t)(bmp085_coeffs_ac5))/pow(2,15);
        x2 = ((int32_t)(bmp085_coeffs_mc*pow(2,11)))/(x1+(int32_t)(bmp085_coeffs_md));
        b5 = x1 + x2;
        
        /* Pressure compensation */
        b6 = b5 - 4000;
        x1 = (bmp085_coeffs_b2 * ((b6 * b6) >> 12)) >> 11;
        x2 = (bmp085_coeffs_ac2 * b6) >> 11;
        x3 = x1 + x2;
        b3 = (((((int32_t) bmp085_coeffs_ac1) * 4 + x3) << BMP_mode) + 2) >> 2;
        x1 = (bmp085_coeffs_ac3 * b6) >> 13;
        x2 = (bmp085_coeffs_b1 * ((b6 * b6) >> 12)) >> 16;
        x3 = ((x1 + x2) + 2) >> 2;
        b4 = (bmp085_coeffs_ac4 * (uint32_t) (x3 + 32768)) >> 15;
        b7 = ((uint32_t) (up - b3) * (50000 >> BMP_mode));
        
        if (b7 < 0x80000000)
        {
            p = (b7 << 1) / b4;
        }
        else
        {
            p = (b7 / b4) << 1;
        }
        
        x1 = (p >> 8) * (p >> 8);
        x1 = (x1 * 3038) >> 16;
        x2 = (-7357 * p) >> 16;
        compp = p + ((x1 + x2 + 3791) >> 4);
    }
    else {
        compp = up;
    }
    /* Assign compensated pressure value */
    *pressure = compp;
}

/*
 * This function reads the temperatures in degrees Celsius,
 * and stores it at the address of the argument temp
 * :rtype:void
 */
void BMP180_getTemperature(float *temp)
{
    int32_t UT, X1, X2, B5;     // following ds convention
    float t;
    
    uint16_t temp2;
    i2c_write8(BMP_address, BMP085_REGISTER_CONTROL, BMP085_REGISTER_READTEMPCMD);
    delay(5);
    i2c_read16(BMP_address, BMP085_REGISTER_TEMPDATA, &temp2);
    UT = temp2;
    
    
    if (UT != -999) {
        // step 1
        X1 = (UT - (int32_t)bmp085_coeffs_ac6) * ((int32_t)bmp085_coeffs_ac5) / pow(2,15);
        X2 = ((int32_t)bmp085_coeffs_mc * pow(2,11)) / (X1+(int32_t)bmp085_coeffs_md);
        B5 = X1 + X2;
        t = (B5+8)/pow(2,4);
        t /= 10;
    }
    else {
        t = UT;
    }
    *temp = t;
}
#endif //BMP180_ADD

#ifdef WindVel_ADD
#ifndef HMC5883_ADD
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
#endif

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

/*
 * Initializes the HMC5883 Sensor
 * :rtype:bool
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

/*
 * Sets the data ready bit to the argument data so that the first measurement can be taken
 * The argument data should be 0 so that the first measurement can be taken. If DRDY bit is
 * set to 1, the new measurement may not occur
 * :rtype:void
 */
void HMC5883_setDataReady(uint8_t data) {
    /* Sets the DRDY bit for first single measurement to occur */
    data = data & 0x01;     // Make sure to only set one bit
    uint8_t drdy;
    i2c_read8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_SR_REG_Mg, &drdy);   // Get current bit
    drdy = drdy & 0xFE;     // Clear last bit
    drdy = drdy | data;     // Set last bit to desired value
    i2c_write8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_SR_REG_Mg, drdy);    
}


/* 
 * Put the sensor into single measurement mode, and a new measurement
 * is taken immediately after.
 * :rtype:void
 */
void HMC5883_setSingleMeasurementMode() {
    uint8_t value;
    
    i2c_read8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_MR_REG_M, &value);
    value &= 0b11111100;
    value |= 0b01;  // Single measurement
    
    i2c_write8(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_MR_REG_M, value);
}

/* 
 * Collects samples and find frequency of rotation of wind cup device
 * :rtype:void
 */
void take_wind_samples()
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
        #ifdef POST
        wdt_reset();
        #endif
    }
    freq = freq/2/sample_time;  //Overcounted originally
    
    #ifdef POST
    wdt_reset();
    #endif
}

/*
 * This function calculates wind velocity from rotational frequency
 * :rtype:void
 */
void calc_windspeed()
{
    speed_mps = freq * .7324; // constant obtained experimentally
    #ifdef POST
    wdt_reset();
    #endif
}


#endif //WindVel_ADD

#ifdef HTU21D_ADD
HTU21D myHumidity;
float HTU21D_H, HTU21D_T;
#endif //HTU21D_ADD


int testing_addr = 0;   // address in EEPROM where testing bit is kept
int numSensors = 19;    // must be >= 1


/*
 * This function is called to take readings of MMA8452 and MAX4466
 * in the loop function, with delay between each measurement. In order
 * to provide data for these sensors, they must have many samples, and
 * this function controls them
 * :rtype:void
 */
void quick_sensors()
{
    #ifdef MMA8452
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
        MMA8452_get_means();
    #ifdef POST
    wdt_reset();
    #endif
    #endif
    
    #ifdef MAX4466_ADD
    if((EEPROM.read(MAX4466_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        for (int i = 0; i < 900; i++) {
            MAX4466_get_max();
            #ifdef POST
            wdt_reset();
            #endif
        }
    }
    #endif //MAX4466_ADD
}

/*
 * This function writes an 8 bit value over I2C
 * :rtype:static void
 */
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

/*
 * This function controls the quick_sensors() function and counts
 * the number of cycles of measurements for the MAX and MMA sensors
 * :rtype:void
 */ 
void increment_time() {
    current_time++; // Increases every 7 seconds
    quick_sensors();
}

/*
 * This function is executed right on startup. If POST is defined, it testsand
 * all the sensors for their response times. After that, it initializes all
 * the sensors and libraries, and determines the Board's ID via the DS18B20's
 * serial number
 * :rtype:void
 */
void setup()
{
    delay(10000);
    Serial.begin(Communication_Rate);
    #ifdef debug_serial
    Serial.println("\nStarting Up");
    Serial.flush();
    #endif //debug_serial
    
    
    #ifdef POST
    post();
    #ifdef debug_serial
    Serial.println("Post test completed");
    #endif // debug_serial
    #else
    for(int i = 1; i <= numSensors; i++) // Display all sensors as fully functional
    {
        EEPROM.write(i+128, 0xFF);
    }
    #endif
    
    // Determine Board ID
    #ifdef DS18B20_ADD
    if((EEPROM.read(DS18B20_ADD+128) & Consistency_Mask) == Consistency_Mask)
    {  
        byte i;
        byte present = 0;
        byte data[12];
        while(DS18B20_1_ds.search(board_ID)) {
            #ifdef debug_serial
            Serial.println("Found \'1-Wire\' device with address:");
            for( i = 1; i < 7; i++) {
//                 Serial.print("0x");
                if (board_ID[i] < 16) {
                    Serial.print('0');
                }
                Serial.print(board_ID[i], HEX);
                if (i < 6) {
                Serial.print(":");
                }
                else
                    Serial.print("\n");
                Serial.flush();
            }
            if ( OneWire::crc8( board_ID, 7) != board_ID[7]) {
                Serial.print("CRC is not valid!\n");
                continue;
            }
            #endif
            #ifdef POST
            wdt_reset();
            #endif
        }
        DS18B20_1_ds.reset_search();
    }
    else
    {
        for (int i = 0; i<8; i++)
            board_ID[i] = 0;
    }
    #else   
    for (int i = 0; i<8; i++)
        board_ID[i] = 0;
    #endif  // DS18B20


    #ifdef TMP421_ADD
    if((EEPROM.read(TMP421_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        /************ The LibTemp421 library turns on Arduino pins A2, A3 (aka 16, 17) to power the sensor.
         *  This is necessary due to the fact that Wire.begin() is called in the constructor and needs to be
         *  talk to the chip, which needs to be powered. If you are using the sensor in a differnt location
         *  and powering it from dedicated GND and +5V lines then include the lines below to reset the
         *  A2 & A3 pins for use as analog inputs. */
        
        //  Uncomment the three lines below to reset the analog pins A2 & A3
        #ifndef POST
        pinMode(A2, INPUT);        // GND pin
        pinMode(A3, INPUT);        // VCC pin
        digitalWrite(A3, LOW);     // turn off pullups
        Wire.begin();
        #endif
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif //TMP421_ADD
    
    #ifdef MLX90614_ADD
    if((EEPROM.read(MLX90614_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        #ifndef POST
        Serial.println("Initializing MLX");
        i2c_init(); //Initialise the i2c bus
        #define I2C_INIT_ADD 1
        PORTC = (1 << PORTC4) | (1 << PORTC5);//enable pullups
        #ifdef POST
        wdt_reset();
        #endif
        #endif
    }
    #endif //MLX90614_ADD
    
    #ifdef IR_D6T_44L_06_ADD
    if((EEPROM.read(IR_D6T_44L_06_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        #ifndef POST
        #ifdef debug_serial
        Serial.println("Initializing IR");
        #endif
        #ifndef I2C_INIT_ADD
        i2c_init();
        #define I2C_INIT_ADD 1
        #endif //I2C_INIT_ADD
        pinMode(17,OUTPUT);    // Power (VCC) for setting D17 (A3) pin
        digitalWrite(17,HIGH);
        pinMode(16,OUTPUT);    // Power supply (GND) for setting D16 (A2) pin
        digitalWrite(16,LOW);
        pinMode(A4,INPUT);
        digitalWrite(A4,HIGH); // Pull-up resistor for SDA
        pinMode(A5,INPUT);
        digitalWrite(A5,HIGH); // Pull-up resistor for SCL
        #ifdef POST
        wdt_reset();
        #endif
        #endif
    }
    #endif //IR_D6T_44L_06_ADD
    
    #ifdef BMP180_ADD
    if((EEPROM.read(BMP180_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        #ifdef debug_serial
        Serial.println("Initializing BMP");
        Serial.flush();
        #endif  // debug_serial
        BMP_begin(); //Initialise and calibrate the sensor bus
    }
    #endif //BMP180
    
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef MMA8452
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        #ifndef I2C_INIT_ADD
        i2c_init();
        #endif //I2C_INIT_ADD
        #ifdef debug_serial
        Serial.println("Initializing MMA");
        Serial.flush();
        #endif
        MMA_found = initMMA8452();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif //MMA8452
    
    #if FASTADC
    #ifdef debug_serial
    Serial.println("FASTADC");
    #endif
    // set prescale to 16
    sbi(ADCSRA,ADPS2) ;
    cbi(ADCSRA,ADPS1) ;
    cbi(ADCSRA,ADPS0) ;
    #ifdef POST
    wdt_reset();
    #endif
    #endif //FASTADC
    
    #ifdef HTU21D_ADD
    #ifndef POST    // Command executed in self test
    if((EEPROM.read(HTU21D_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        #ifdef debug_serial
        Serial.println("Initializing HTU");
        #endif
        myHumidity.begin();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif //POST
    #endif //HTU21D_ADD
    
    
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef HMC5883_ADD
    if((EEPROM.read(HMC5883_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        #ifndef POST
        #ifdef debug_serial
        Serial.println("Initializing HMC");
        #endif // debug_serial
        HMC5883_begin();    // function called in POST
        #endif  // POST
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif //HMC5883_ADD
    
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef WindVel_ADD
    if((EEPROM.read(WindVel_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor    
    {
        #ifdef debug_serial
        Serial.println("Initializing WindVel");
        #endif
        HMC5883_begin();
        #ifdef POST
        wdt_reset();
        #endif
        // Set Single measurement mode on sensor
        #ifdef POST
        wdt_reset();
        #endif 
        HMC5883_setSingleMeasurementMode();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif //WindVel
    
    #ifdef POST
    wdt_disable();
    wdt_enable(WDTO_8S);
    #endif
}

