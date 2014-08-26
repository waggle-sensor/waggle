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

/*
 A nal*og Input with prescale change
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

#include <OneWire.h> 
#include <dht.h>
#include <Wire.h> 
//I2C library
#include <HIH61XX.h>
#include <LibTempTMP421.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>


#define debug_serial 1

#define SHT75_ADD 1
#define BMP180_ADD 2
#define RHT03_ADD 3
#define TMP102_ADD 4
#define DS18B20_ADD 5
#define SHT15_ADD 6
#define HIH6130_ADD 7
// #define HTU21D_ADD 8 //Burnt!!!!
#define HIH4030_ADD 9
// #define TSYS01_ADD 10 //Surface mount - not now. 
#define DS18S20_ADD 11
// #define LM35CZ_ADD 12
#define MLX90614_ADD 13
// #define SHT25_ADD 14
#define GA1A1S201WP_ADD 15
#define THERMIS_100K_ADD 16
#define MAV4466_ADD 18
#define TMP421_ADD 19

// #define IR_D6T_44L_06_ADD 20 // Motorola does this 
#define PhoRes_ADD 21

#ifdef DS18B20_ADD
// Data wire is plugged into pin 3 on the Arduino
#define DS18B20_PIN 3
// Setup a oneWire instance to communicate with any OneWire devices
OneWire DS18B20_Bus(DS18B20_PIN);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature DS18B20(&DS18B20_Bus);
// Assign the addresses of your 1-Wire temp sensors.
// See the tutorial on how to obtain these addresses:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html
DeviceAddress DS18B20_1 = { 0x28, 0x2D, 0xE4, 0xAF, 0x02, 0x00, 0x00, 0x5B };
DeviceAddress DS18B20_2 = { 0x28, 0x51, 0x01, 0xB0, 0x02, 0x00, 0x00, 0x14 };

#endif

#ifdef MLX90614_ADD
#include <i2cmaster.h>
#endif //MLX90614_ADD


#ifdef PhoRes_ADD
#define PhoRes_PIN 3
#endif //PhoRes_ADD

#ifdef SHT15_ADD
#include <Sensirion.h>
#define Sensirion_ADD 1
#define SHT15_1_dataPin  3              // SHT15_1 serial data
#define SHT15_1_sclkPin  2              // SHT15_1 serial clock
float SHT15_1_temperature;
float SHT15_1_humidity;
Sensirion SHT15_1_tempSensor = Sensirion(SHT15_1_dataPin, SHT15_1_sclkPin);
#endif 



#ifdef SHT75_ADD
#ifndef Sensirion_ADD
#include <Sensirion.h>
#endif //Sensirion_ADD
#define SHT75_1_dataPin 6  // SHT15_1 serial data
#define SHT75_1_sclkPin 7  // SHT15_1 serial clock
float SHT75_1_temperature;
float SHT75_1_humidity;
Sensirion SHT75_1_tempSensor = Sensirion(SHT75_1_dataPin, SHT75_1_sclkPin);
#endif //SHT75_ADD

#ifdef GA1A1S201WP_ADD
#define AMBI_1_Pin 0    // Ambient sensor
#endif //GA1A1S201WP_ADD


#ifdef MAV4466_ADD
#define MAV4466_PIN 2
const int MAV4466_Buff_Len = 100;
int MAV4466_Val[MAV4466_Buff_Len];   // variable to store the value coming from the sensor
#endif //MAV4466_ADD


#ifdef THERMIS_100K_ADD
#define THERMIS_100K_Pin 1    // NTC sensor
#endif

#ifdef DS18S20_ADD
#define DS18S20_1_Pin 13 
OneWire DS18S20_1_ds(DS18S20_1_Pin);  // Temperature chip i/o on digital pin 2
float DS18S20_1_getTemp()
{
    //returns the temperature from one DS18S20 in DEG Celsius
    
    byte data[12];
    byte addr[8];
    
    if ( !DS18S20_1_ds.search(addr)) {
        //no more sensors on chain, reset search
        DS18S20_1_ds.reset_search();
        return -1000;
    }
    
    if ( OneWire::crc8( addr, 7) != addr[7]) {
        //       Serial.println("CRC is not valid!");
        return -1000;
    }
    
    if ( addr[0] != 0x10 && addr[0] != 0x28) {
        //       Serial.print("Device is not recognized");
        return -1000;
    }
    
    DS18S20_1_ds.reset();
    DS18S20_1_ds.select(addr);
    DS18S20_1_ds.write(0x44,1); // start conversion, with parasite power on at the end
    
    byte present = DS18S20_1_ds.reset();
    DS18S20_1_ds.select(addr);    
    DS18S20_1_ds.write(0xBE); // Read Scratchpad
    
    
    for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = DS18S20_1_ds.read();
    }
    
    DS18S20_1_ds.reset_search();
    
    byte MSB = data[1];
    byte LSB = data[0];
    
    //   float tempRead = ((MSB << 8) | LSB); //using two's compliment
    float tempRead = ((MSB << 8) | LSB); //using two's compliment
    float TemperatureSum;
    TemperatureSum = tempRead/16.0;
    return TemperatureSum;
    
}
#endif //DS18S20_ADD

#ifdef RHT03_ADD
#define RHT03_1_PIN 5 // RHT03 Sensor pin
dht RHT03_1;
#endif //RHT03_ADD


#ifdef TMP102_ADD
const int tmp102_1_Address = 0x48;
#endif //TMP421_ADD

#ifdef HIH6130_ADD
//  Create an HIH61XX with I2C address 0x27, powered by pin 13, need to modify this
HIH61XX HIH_6130_1_hih(0x27,13);
#endif //HIH6130_ADD

#ifdef TMP421_ADD
LibTempTMP421 TMP421_1 = LibTempTMP421(0);
#endif //TMP421_ADD

#ifdef BMP180_ADD
Adafruit_BMP085_Unified BMP_180_1 = Adafruit_BMP085_Unified(10085);
#endif //BMP180_ADD

void setup()
{
    Serial.begin(115200);
    #ifdef debug_serial
    Serial.print("Starting Up.");
    #endif
    
    Wire.begin();
    
    #ifdef TMP421_ADD
    /************ The LibTemp421 library turns on Arduino pins A2, A3 (aka 16, 17) to power the sensor.
    *  This is necessary due to the fact that Wire.begin() is called in the constructor and needs to be 
    *  talk to the chip, which needs to be powered. If you are using the sensor in a differnt location
    *  and powering it from dedicated GND and +5V lines then include the lines below to reset the 
    *  A2 & A3 pins for use as analog inputs. */
    
    //   Uncomment the three lines below to reset the analog pins A2 & A3
    pinMode(A2, INPUT);        // GND pin      
    pinMode(A3, INPUT);        // VCC pin
    digitalWrite(A3, LOW);     // turn off pullups   
    #endif //TMP421_ADD
    
    #ifdef BMP180_ADD
    BMP_180_1.begin();
    #endif
    // set the resolution to 10 bit (good enough?)
    #ifdef DS18B20_ADD
    DS18B20.begin();
    DS18B20.setResolution(DS18B20_1, 10);
    DS18B20.setResolution(DS18B20_2, 10);
    #endif
    
    delay(3000); // waiting for the sensors to settle
    
    #ifdef debug_serial
    Serial.println("...entering Sensor Loop...");
    #endif //debug_serial  
    
    #ifdef MLX90614_ADD
    i2c_init(); //Initialise the i2c bus
    PORTC = (1 << PORTC4) | (1 << PORTC5);//enable pullups
    #endif //MLX90614_ADD
    
    #if FASTADC
    // set prescale to 16
    sbi(ADCSRA,ADPS2) ;
    cbi(ADCSRA,ADPS1) ;
    cbi(ADCSRA,ADPS0) ;
    #endif
    
}

void loop()
{
    #ifdef SHT15_ADD
    uint16_t SHT15_1_rawData;
    uint8_t SHT15_1_error; 
    SHT15_1_error = SHT15_1_tempSensor.measTemp(&SHT15_1_rawData);
    SHT15_1_temperature = SHT15_1_tempSensor.calcTemp(SHT15_1_rawData);
    SHT15_1_error = SHT15_1_tempSensor.measHumi(&SHT15_1_rawData);
    SHT15_1_humidity = SHT15_1_tempSensor.calcHumi(SHT15_1_rawData, SHT15_1_temperature);
    Serial.print("SHT15_1_T_C:");
    Serial.print(SHT15_1_temperature,2);
    Serial.print("; ");
    Serial.print("SHT15_1_H_%:");
    Serial.print(SHT15_1_humidity,2);
    Serial.print("; ");
    #endif //SHT15_ADD
    
    #ifdef SHT75_ADD
    uint16_t SHT75_1_rawData;
    uint8_t SHT75_1_error;
    SHT75_1_error = SHT75_1_tempSensor.measTemp(&SHT75_1_rawData);
    SHT75_1_temperature = SHT75_1_tempSensor.calcTemp(SHT75_1_rawData);
    SHT75_1_error = SHT75_1_tempSensor.measHumi(&SHT75_1_rawData);
    SHT75_1_humidity = SHT75_1_tempSensor.calcHumi(SHT75_1_rawData, SHT75_1_temperature);
    
    Serial.print("SHT75_1_T_C:");
    Serial.print(SHT75_1_temperature,2);
    Serial.print("; ");
    Serial.print("SHT75_1_H_%:");
    Serial.print(SHT75_1_humidity,2);
    Serial.print("; ");
    #endif //SHT75_ADD
    
    #ifdef MAV4466_ADD
    int i=0;
    int MAV4466_Peak;
    
    for (i=0;i<MAV4466_Buff_Len;i++)
    {
        MAV4466_Val[i]= analogRead(MAV4466_PIN);
    } 

    // we have read sample_size values, let us now find the peak of the 100 values. 
    MAV4466_Peak = 0;
    
    for (i=0;i<MAV4466_Buff_Len;i++)
    {
        MAV4466_Peak = max(MAV4466_Peak , abs(512-MAV4466_Val[i]));
    }
    Serial.print("MAV4466_1_Units:");
    Serial.print(MAV4466_Peak);
    Serial.print("; ");
    #endif //MAV4466_ADD
    
    #ifdef GA1A1S201WP_ADD
    int AMBI_1_Value;
    AMBI_1_Value = analogRead(AMBI_1_Pin); 
    Serial.print("AMBI_1_Units:");
    Serial.print(AMBI_1_Value);
    Serial.print("; ");
    #endif //GA1A1S201WP_ADD
    
    #ifdef PhoRes_ADD
    int PhoRes_1_Value;
    PhoRes_1_Value = analogRead(PhoRes_PIN); 
    Serial.print("PhoRes_10K4.7K_Units:");
    Serial.print(PhoRes_1_Value);
    Serial.print("; ");
    #endif //PhoRes_ADD
    
    #ifdef THERMIS_100K_ADD
    int THERMIS_1_Value;
    THERMIS_1_Value = analogRead(THERMIS_100K_Pin); 
    Serial.print("THERMIS_100K_Units:");
    Serial.print(THERMIS_1_Value);
    Serial.print("; ");
    #endif //THERMIS_100K_ADD
    
    #ifdef DS18S20_ADD
    float DS18S20_1_temperature;
    DS18S20_1_temperature = DS18S20_1_getTemp();
    Serial.print("DS18S20_1_T_C:");
    Serial.print(DS18S20_1_temperature, 2);
    Serial.print("; ");
    #endif
    
    
    #ifdef TMP421_ADD
    float TMP421_1_temperature;
    TMP421_1_temperature = TMP421_1.GetTemperature(); // Some error, check this out! 
    Serial.print("TMP421_1_T_C:");
    Serial.print(TMP421_1_temperature, 2);
    Serial.print("; ");
    #endif
    
    #ifdef DS18B20_ADD
    float DS18B20_1_T; 
    float DS18B20_2_T;
    DS18B20_1_T=DS18B20.getTempC(DS18B20_1);
    DS18B20_2_T=DS18B20.getTempC(DS18B20_2);
    Serial.print("DS18B20_1_T_C:");
    Serial.print(DS18B20_1_T, 2);
    Serial.print("; ");
    Serial.print("DS18B20_2_T_C:");
    Serial.print(DS18B20_2_T, 2);
    Serial.print("; ");
    #endif
    
    #ifdef RHT03_ADD
    int chk_RHT03_1;
    chk_RHT03_1 = RHT03_1.read22(RHT03_1_PIN);
    if ( chk_RHT03_1 == DHTLIB_OK)
    { 
        Serial.print("RHT03_1_T_C:");
        Serial.print(RHT03_1.temperature, 2);
        Serial.print("; ");
        Serial.print("RHT03_1_H_%:");
        Serial.print(RHT03_1.humidity, 2);
        Serial.print("; ");
    }
    #endif
    
    
    #ifdef BMP180_ADD
    float BMP_180_1_temperature, BMP_180_1_pressure;
    BMP_180_1.getPressure(&BMP_180_1_pressure);  
    BMP_180_1.getTemperature(&BMP_180_1_temperature);
    Serial.print("BMP_180_1_T_C:");
    Serial.print(BMP_180_1_temperature, 2);
    Serial.print("; ");
    Serial.print("BMP_180_1_P_PA:");
    Serial.print(BMP_180_1_pressure, 2);
    Serial.print("; ");
    #endif
    
    #ifdef TMP102_ADD
    float tmp102_1_temperature;
    Wire.requestFrom(tmp102_1_Address,2);
    byte tmp102_1_MSB = Wire.read();
    byte tmp102_1_LSB = Wire.read();
    tmp102_1_temperature = (((tmp102_1_MSB << 8) | tmp102_1_LSB) >> 4) * 0.11250 + 32; //it's a 12bit int, using two's compliment for negative
    Serial.print("TMP102_1_T_F:");
    Serial.print(tmp102_1_temperature,2);
    Serial.print("; ");
    #endif
    
     
    
    #ifdef  HIH6130_ADD
    HIH_6130_1_hih.start();
    HIH_6130_1_hih.update();
    Serial.print("HIH_6130_1_T_C:");
    Serial.print(HIH_6130_1_hih.temperature(), 2);
    Serial.print("; ");
    Serial.print("HIH_6130_1_H_%:");
    Serial.print(HIH_6130_1_hih.humidity(), 2);
    Serial.print("; ");
    #endif
    
    
    #ifdef MLX90614_ADD
    int dev = 0x5A<<1;
    int data_low = 0;
    int data_high = 0;
    int pec = 0;
    
    i2c_start_wait(dev+I2C_WRITE);
    i2c_write(0x07);
    
    // read
    i2c_rep_start(dev+I2C_READ);
    data_low = i2c_readAck(); //Read 1 byte and then send ack
    data_high = i2c_readAck(); //Read 1 byte and then send ack
    pec = i2c_readNak();
    i2c_stop();
    
    //This converts high and low bytes together and processes temperature, MSB is a error bit and is ignored for temps
    double tempFactor = 0.02; // 0.02 degrees per LSB (measurement resolution of the MLX90614)
    double tempData = 0x0000; // zero out the data
    int frac; // data past the decimal point
    
    // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
    tempData = (double)(((data_high & 0x007F) << 8) + data_low);
    tempData = (tempData * tempFactor)-0.01;
    
    float celcius = tempData - 273.15;
    float fahrenheit = (celcius*1.8) + 32;
    
    Serial.print("MLX90614_T_F:");
    Serial.print(fahrenheit);
    Serial.print("; ");
    #endif
    
    Serial.print('\n');
    delay(1000);  
}
