
/*
 Analog Input with prescale change
 Reading a 1 kHz sine wave, 0 to 5 volts
 Using analog 0
 Results stored in memory for highest speed
 using code from:
 http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1208715493/11
 with special thanks to jmknapp
 */

#define FASTADC 1
// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

// #define debug_serial 1
#define SILENCE_BAD_SENSORS 1
#define debug_serial
#define POST    // enables power on self test to prevent sensors hanging up
// // 
// // // I2C devices
// #define MMA8452 6
// #define MLX90614_ADD 9
// #define IR_D6T_44L_06_ADD 14
// #define BMP180_ADD 2
// #define TMP102_ADD 4
// #define TMP421_ADD 13
// #define HIH6130_ADD 7
// #define HTU21D_ADD 18
// #define HMC5883_ADD 19
// 
// // Single Wire devices
// #define RHT03_ADD 3
// #define RHT03_1_PIN 8 // RHT03 Sensor pin
// 
// 
// 
// // // Two Wire devices
// #define SHT15_ADD 5
// #define SHT15_1_dataPin  11     // SHT15_1 serial data
// #define SHT15_1_sclkPin  12     // SHT15_1 serial clock
// 
// #define SHT75_ADD 1
// #define SHT75_1_dataPin 10  // SHT15_1 serial data
// #define SHT75_1_sclkPin 9   // SHT15_1 serial clock
// 
// // 1-wire devices
// #define DS18B20_ADD 8
// #define DS18B20_1_Pin 7
// 
// // Analog Inputs
// #define GA1A1S201WP_ADD 10
// #define AMBI_1_Pin A6    // Ambient sensor
// 
// #define THERMIS_100K_ADD 11
// #define THERMIS_100K_Pin 0    // NTC sensor
// 
// #define MAX4466_ADD 12
// #define MAX4466_PIN 1
// 
// #define HIH4030_ADD 15
// #define HIH4030_PIN A2
// 
// #define PhoRes_ADD 16
// #define PhoRes_PIN A3
// 
// // 
#define WindVel_ADD 17


#define MMA_Buff_size 40 //460
#define Communication_Rate 57600
#define Consistency_Mask 0x03  // Sensor must pass 2 consecutive tests to be considered active









