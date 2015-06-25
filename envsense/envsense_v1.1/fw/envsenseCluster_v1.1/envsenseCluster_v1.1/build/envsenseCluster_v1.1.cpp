#line 1 "envsenseCluster_v1.1.ino"
                                 
                                                                                               
                                                                                            
                                                             
                                                              
                                                                                          
                                        

                               
                    

                                                                       
                                                        
                                                                                           
                                                                                                    

#define nop() __asm volatile ("nop")
#if 1
#include "Arduino.h"
bool D6T_get_data(void);
void output_csv();
int D6T_checkPEC(int* buf, int pPEC);
byte calc_crc(byte data);
void MMA8452_get_means();
void calc_MMA_RMS();
bool readAccelData(int *destination);
bool initMMA8452();
void MMA8452Standby();
void MMA8452Active();
bool readRegisters(byte addressToRead, int bytesToRead, byte * dest);
byte readRegister(byte addressToRead);
void writeRegister(byte addressToWrite, byte dataToWrite);
void MAX4466_get_max();
float DS18B20_1_getTemp();
void take_samples();
void calc_speed();
void quick_sensors();
void increment_time();
void setup();
void loop();
void post();
void sensor_print();
#line 19
nop();
#endif
  
                               
   

#include <OneWire.h>
#include <dht.h>
#include <Wire.h>
#include <HIH61XX.h>
#include <LibTempTMP421.h>
#include <DallasTemperature.h>
#include <Adafruit_Sensor.h>
#include <EEPROM.h>
#include <avr/wdt.h>
#include <Sensirion.h>
#include <i2cmaster.h>
#include <Adafruit_BMP085_U.h>
#include <HMC5883.h>
                        
                          
#include "HTU21D.h"
#include "features_v2.c"

                       
                       
int counter = 0;
volatile int current_time = 0;
int sleep_time_loop = int(13500.0/MMA_Buff_size);

#ifdef HMC5883_ADD
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(23181);
sensors_event_t HMC5883_event;
float HMC5883_heading, HMC5883_declinationAngle, HMC5883_headingDegrees;
#endif              


#ifdef IR_D6T_44L_06_ADD
#define I2C_ADD 1
int rbuf[35];
float tdata[16];
float t_PTAT;
float tPEC;
bool data_check;


bool D6T_get_data(void) {
    int k, start_err = 0, write_err = 0;
    start_err = i2c_start(0x14);
    if (start_err == 1) return false;
    write_err = i2c_write(0x4C);
    if (write_err == 1) return false;

    start_err = i2c_rep_start(0x15);
    if (start_err == 1) return false;
    for (k = 0; k < 35; k++) {
        if (k == 34) {
            rbuf[k] = i2c_readNak();
        }
        else {
            rbuf[k] = i2c_readAck();
        }
    }
    for (int j = 0; j<35; j++) {
        if (rbuf[j] == -999)
            return false;
    }
    i2c_stop();

    if (!D6T_checkPEC(rbuf, 34)) {
        return false;
    }
    else {
        t_PTAT = (rbuf[0]+(rbuf[1]<<8))*0.1;
        for (k = 0; k < 16; k++) {
            tdata[k]=(rbuf[(k*2+2)]+(rbuf[(k*2+3)]<<8))*0.1;
        }
        tPEC = rbuf[34];
        return true;
    }
}

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

int D6T_checkPEC(int* buf, int pPEC) {
    byte crc;

    crc = calc_crc(0x14);
    crc = calc_crc(0x4C ^ crc);
    crc = calc_crc(0x15 ^ crc);
    for (int i=0; i<pPEC; i++) {
        crc = calc_crc(buf[i] ^ crc);
    }
    return (crc == buf[pPEC]);
}

byte calc_crc(byte data) {
    for (int index=0; index<8; index++) {
        byte temp = data;
        data = data<<1;
        if (temp & 0x80) data = data ^ 0x07;
    }
    return data;
}
#endif                    


#ifdef MMA8452
#ifndef I2C_ADD
#define I2C_ADD 1
#endif          
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

void MMA8452_get_means()
{
    int accelCount[3];                                  
    float accelG[3];                                      

    bool good_data = readAccelData(accelCount);                             
                                     



    if (good_data == false)
    {
        accelG[0] = -999;
        accelG[1] = -999;
        accelG[2] = -999;
                        
    }

    else {
        for (int i = 0 ; i < 3 ; i++) {
            accelG[i] = (float) accelCount[i] / ((1<<12)/(2*GSCALE));                                                       
        }
    }

    xvals[q] = accelG[0];
    yvals[q] = accelG[1];
    zvals[q] = accelG[2];

    xmean = (xmean*q+xvals[q])/(q+1);
    ymean = (ymean*q+yvals[q])/(q+1);
    zmean = (zmean*q+zvals[q])/(q+1);

    q++;

                   
}

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
    byte rawData[6];                                         

    bool read_success = readRegisters(OUT_X_MSB, 6, rawData);                                                   

    if (read_success == false) return false;

                                                             
    for(int i = 0; i < 3 ; i++)
    {
        int gCount = (rawData[i*2] << 8) | rawData[(i*2)+1];                                                         
        gCount >>= 4;                                                                       

                                                                                          
        if (rawData[i*2] > 0x7F)
        {
            gCount = ~gCount + 1;
            gCount *= -1;                                            
        }

        destination[i] = gCount;                                          
    }
    return true;
}

bool initMMA8452()
{
    byte c = readRegister(WHO_AM_I);                          
    if (c == 0x2A);                                  
    else {
        return false;
    }

    MMA8452Standby();                                          

    byte fsr = GSCALE;
    if(fsr > 8) fsr = 8;                   
    fsr >>= 2;
    writeRegister(XYZ_DATA_CFG, fsr);

    MMA8452Active();                                  
    return true;
}

void MMA8452Standby()
{
    byte c = readRegister(CTRL_REG1);
    writeRegister(CTRL_REG1, c & ~(0x01));                                          
}

void MMA8452Active()
{
    byte c = readRegister(CTRL_REG1);
    writeRegister(CTRL_REG1, c | 0x01);                                        
}

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
    i2c_stop();
    return true;
}

byte readRegister(byte addressToRead)
{
    i2c_start(MMA8452_ADDRESS_WRITE);                 
    i2c_write(addressToRead);
    i2c_rep_start(MMA8452_ADDRESS_READ);                
    i2c_stop();

    return i2c_readNak();
}

void writeRegister(byte addressToWrite, byte dataToWrite)
{
    i2c_start(MMA8452_ADDRESS_WRITE);
    i2c_write(addressToWrite);
    i2c_write(dataToWrite);
    i2c_stop();
}
#endif          

#ifdef HIH4030_ADD
                         
int HIH4030_1_Value;
#endif              

#ifdef MLX90614_ADD
#ifndef I2C_ADD
#include <i2cmaster.h>
#endif          
int dev = 0x5A<<1;
int data_low = 0;
int data_high = 0;
int pec = 0;
double tempFactor = 0.02;                                                                 
double tempData;
int frac;                               
float celcius;
float fahrenheit;
int start_err = 0, write_err = 0, rep_start_err = 0;
#endif               

#ifdef PhoRes_ADD
                        
int PhoRes_1_Value;
#endif             

#ifdef SHT15_ADD
#include <Sensirion.h>
#define Sensirion_ADD 1
                                                         
                                                          
float SHT15_1_temperature;
float SHT15_1_humidity;
uint16_t SHT15_1_rawData;
uint8_t SHT15_1_error;
Sensirion SHT15_1_tempSensor = Sensirion(SHT15_1_dataPin, SHT15_1_sclkPin);
#endif            

#ifdef SHT75_ADD
#ifndef Sensirion_ADD
#include <Sensirion.h>
#endif                
                                                     
                                                      
float SHT75_1_temperature;
float SHT75_1_humidity;
uint16_t SHT75_1_rawData;
uint8_t SHT75_1_error;
Sensirion SHT75_1_tempSensor = Sensirion(SHT75_1_dataPin, SHT75_1_sclkPin);
#endif            

#ifdef GA1A1S201WP_ADD
                                             
int AMBI_1_Value;
#endif                  

#ifdef MAX4466_ADD
                        
                                    
                                                                                             
int MAX4466_Value = 0;

void MAX4466_get_max()
{
    MAX4466_Value= max(MAX4466_Value,abs(512-analogRead(MAX4466_PIN)));
}
#endif              

#ifdef THERMIS_100K_ADD
                                              
int THERMIS_1_Value;
#endif                   

#ifdef DS18B20_ADD
                          
OneWire DS18B20_1_ds(DS18B20_1_Pin);                                          
float DS18B20_1_temperature;

float DS18B20_1_getTemp()
{
                                                             

    byte data[12];
    byte addr[8];

    if (!DS18B20_1_ds.search(addr)) {
                                                
        DS18B20_1_ds.reset_search();
        return -1000;
    }

    if ( OneWire::crc8( addr, 7) != addr[7]) {
                                              
        return -1000;
    }

    if ( addr[0] != 0x10 && addr[0] != 0x28) {
                                                   
        return -1000;
    }

    DS18B20_1_ds.reset();
    DS18B20_1_ds.select(addr);
    DS18B20_1_ds.write(0x44,1);                                                       

                                             
    DS18B20_1_ds.reset();
    DS18B20_1_ds.select(addr);
    DS18B20_1_ds.write(0xBE);                   

    for (int i = 0; i < 9; i++) {                   
        data[i] = DS18B20_1_ds.read();
    }

    DS18B20_1_ds.reset_search();

    byte MSB = data[1];
    byte LSB = data[0];

                                                                   
    float tempRead = ((MSB << 8) | LSB);                         
    float TemperatureSum;
    TemperatureSum = tempRead/16.0;
    return TemperatureSum;
}
#endif              

#ifdef RHT03_ADD
                                            
dht RHT03_1;
int chk_RHT03_1;
#endif            

#ifdef TMP102_ADD
const int tmp102_1_Address = 0x48;
float tmp102_1_temperature;
byte tmp102_1_MSB, tmp102_1_LSB;
int err;
#endif             

#ifdef HIH6130_ADD
                                                                                   
HIH61XX HIH_6130_1_hih(0x27,22);
#endif              

#ifdef TMP421_ADD
LibTempTMP421 TMP421_1 = LibTempTMP421(0);
float TMP421_1_temperature;
#endif             

#ifdef BMP180_ADD
Adafruit_BMP085_Unified BMP_180_1 = Adafruit_BMP085_Unified(10085);
float BMP_180_1_temperature, BMP_180_1_pressure;
#endif             

#ifdef WindVel_ADD
#ifndef HMC5883_ADD                                         
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
#endif               
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
int sample_delay = 4;                                                      
float sample_rate = 160.0;
                                           
                                            

int previous=0;
float freq = 0.0;
int sample_time = 3;                        
float speed_mps = 0;

void take_samples()
                                           
{
                                
    mag.setDataReady(0);
    #ifdef POST
    wdt_reset();
    #endif
    int sign = 0;
    for (int i = 0; i<sample_rate*sample_time; i++)
    {
        mag.setSingleMeasurementMode();                             
        delay(sample_delay);                                                     
        while((mag.getDataReady() & 0x01) != 0x01);                                 
                                                                        
        
                                     
        int16_t y_val;
        Wire.beginTransmission(HMC5883_ADDRESS_MAG);                              
        Wire.write(HMC5883_REGISTER_MAG_OUT_Y_H_M);                                    
        Wire.endTransmission();
        Wire.beginTransmission(HMC5883_ADDRESS_MAG);                     
        Wire.requestFrom(HMC5883_ADDRESS_MAG, 2);                       
        while(!Wire.available()) {};
        uint8_t vha = Wire.read();
        uint8_t vla = Wire.read();
        Wire.endTransmission();
        y_val = vha << 8 | vla;                                              
        
        if(y_val < 0)                              
            sign = -1;
        else
            sign = 1;
        
        if(sign != previous)                                           
        {                                                
            previous = sign;
            if(i!=0)                                                                
                freq++;
        }
        #ifdef POST
        wdt_reset();
        #endif
    }
    freq = freq/2/sample_time;                          
    
    #ifdef POST
    wdt_reset();
    #endif
}

void calc_speed()
                                          
{
    speed_mps = freq * 1.0876;                                    
    #ifdef POST
    wdt_reset();
    #endif
}

                                
                                         
                              
               
   
                           
                     
    
   
                                                                  
                                    
                       
                        
        
             
                                                                  
        
                                                  
                              
             
                       
    
   
                          
                                         
                                    
                                    
        
                                  
                         
    
#endif              

#ifdef HTU21D_ADD
HTU21D myHumidity;
float HTU21D_H, HTU21D_T;
#endif             


int testing_addr = 0;
int numSensors = 19;                   



void quick_sensors()
{
    #ifdef MMA8452
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)                                 
        MMA8452_get_means();
    #ifdef POST
    wdt_reset();
    #endif
    #endif

    #ifdef MAX4466_ADD
    if((EEPROM.read(MAX4466_ADD+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
        for (int i = 0; i < 900; i++) {
            MAX4466_get_max();
            #ifdef POST
            wdt_reset();
            #endif
        }
    }
    #endif              
}


void increment_time() {
    current_time++;                             
    quick_sensors();
}

void setup()
{
    ;
    delay(10000);
    Serial.begin(Communication_Rate);
    #ifdef debug_serial
    Serial.println("\nStarting Up");
    Serial.flush();
    #endif               
 
    
    #ifdef POST
    post();
    #ifdef debug_serial
    Serial.println("Post test completed");
    #endif                
    #else
    for(int i = 1; i <= numSensors; i++)                                           
    {
        EEPROM.write(i+128, 0xFF);
    }
    #endif

    #ifdef BMP180_ADD
    if((EEPROM.read(BMP180_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        BMP_180_1.begin();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif             
                                                  

    #ifdef TMP421_ADD
    if((EEPROM.read(TMP421_ADD+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
                                                                                                           
                                                                                                           
                                                                                                          
                                                                                                     
                                                    

                                                                            
        #ifndef POST
        pinMode(A2, INPUT);                  
        pinMode(A3, INPUT);                  
        digitalWrite(A3, LOW);                        
        #endif
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif             

    #ifdef MLX90614_ADD
    if((EEPROM.read(MLX90614_ADD+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
        #ifndef POST
        Serial.println("Initializing MLX");
        i2c_init();                         
        #define I2C_INIT_ADD 1
        PORTC = (1 << PORTC4) | (1 << PORTC5);                
        #ifdef POST
        wdt_reset();
        #endif
        #endif
    }
    #endif               

    #ifdef IR_D6T_44L_06_ADD
    if((EEPROM.read(IR_D6T_44L_06_ADD+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
        #ifndef POST
        #ifdef debug_serial
        Serial.println("Initializing IR");
        #endif
        #ifndef I2C_INIT_ADD
        i2c_init();
        #define I2C_INIT_ADD 1
        #endif               
        pinMode(17,OUTPUT);                                           
        digitalWrite(17,HIGH);
        pinMode(16,OUTPUT);                                                  
        digitalWrite(16,LOW);
        pinMode(A4,INPUT);
        digitalWrite(A4,HIGH);                            
        pinMode(A5,INPUT);
        digitalWrite(A5,HIGH);                            
        #ifdef POST
        wdt_reset();
        #endif
        #endif
    }
    #endif                    

    #ifdef MMA8452
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
        #ifndef I2C_INIT_ADD
        i2c_init();
        #endif               
        #ifdef debug_serial
        Serial.println("Initializing MMA");
        #endif
        MMA_found = initMMA8452();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif          

    #if FASTADC
    #ifdef debug_serial
    Serial.println("FASTADC");
    #endif
                         
    sbi(ADCSRA,ADPS2) ;
    cbi(ADCSRA,ADPS1) ;
    cbi(ADCSRA,ADPS0) ;
    #ifdef POST
    wdt_reset();
    #endif
    #endif          

    #ifdef HTU21D_ADD
    #ifndef POST                                    
    if((EEPROM.read(HTU21D_ADD+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
        #ifdef debug_serial
        Serial.println("Initializing HTU");
        #endif
        myHumidity.begin();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif       
    #endif             

    
    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HMC5883_ADD
    if((EEPROM.read(HMC5883_ADD+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
        #ifdef debug_serial
        Serial.println("Initializing HMC");
        #endif
                                                   
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif              
    
    #ifdef POST
    wdt_reset();
    #endif
        
    #ifdef WindVel_ADD
    if((EEPROM.read(WindVel_ADD+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
        #ifdef debug_serial
        Serial.println("Initializing WindVel");
        #endif
        mag.begin();
        #ifdef POST
        wdt_reset();
        #endif
                                                
        #ifdef POST
        wdt_reset();
        #endif 
        mag.setSingleMeasurementMode();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif          
    
    #ifdef POST
    wdt_disable();
    wdt_enable(WDTO_8S);
    #endif
}

#line 1 "loop.ino"
void loop() {
    #ifdef debug_serial
    Serial.println("...entering Sensor Loop...");
    #endif               
                    
             
                            
                        
                         
                   
             
    
    
    
    #ifdef IR_D6T_44L_06_ADD
    if((EEPROM.read(IR_D6T_44L_06_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("IR_D6T_44L_06");
        Serial.flush();
        #endif               
        data_check = D6T_get_data();
    }
    #endif                    
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef SHT15_ADD
    if((EEPROM.read(SHT15_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("SHT_15");
        Serial.flush();
        #endif               
        SHT15_1_error = SHT15_1_tempSensor.measTemp(&SHT15_1_rawData);
        SHT15_1_temperature = SHT15_1_tempSensor.calcTemp(SHT15_1_rawData);
        SHT15_1_error = SHT15_1_tempSensor.measHumi(&SHT15_1_rawData);
        SHT15_1_humidity = SHT15_1_tempSensor.calcHumi(SHT15_1_rawData, SHT15_1_temperature);
    }
    #endif            
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef SHT75_ADD
    if((EEPROM.read(SHT75_ADD+128) & Consistency_Mask) == Consistency_Mask)                                  
    {
        #ifdef debug_serial
        Serial.println("SHT75");
        Serial.flush();
        #endif               
        SHT75_1_error = SHT75_1_tempSensor.measTemp(&SHT75_1_rawData);
        #ifdef POST
        wdt_reset();
        #endif
        SHT75_1_temperature = SHT75_1_tempSensor.calcTemp(SHT75_1_rawData);
        #ifdef POST
        wdt_reset();
        #endif
        SHT75_1_error = SHT75_1_tempSensor.measHumi(&SHT75_1_rawData);
        #ifdef POST
        wdt_reset();
        #endif
        SHT75_1_humidity = SHT75_1_tempSensor.calcHumi(SHT75_1_rawData, SHT75_1_temperature);
    }
    #endif            
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef GA1A1S201WP_ADD
    if((EEPROM.read(GA1A1S201WP_ADD+128) & Consistency_Mask) == Consistency_Mask)                                     
    {
        #ifdef POST
        wdt_reset();
        #endif
        #ifdef debug_serial
        Serial.println("GA1A1S201WP");
        Serial.flush();
        #endif               
        AMBI_1_Value = analogRead(AMBI_1_Pin);
                                  
    }
    #endif                  
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef PhoRes_ADD
    if((EEPROM.read(PhoRes_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("PhoRes");
        Serial.flush();
        #endif               
        PhoRes_1_Value = analogRead(PhoRes_PIN);
    }
    #endif             
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef HTU21D_ADD
    if((EEPROM.read(HTU21D_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("HTU21D");
        Serial.flush();
        #ifdef POST
        wdt_reset();
        #endif
        #endif               
        HTU21D_T = myHumidity.readTemperature();
        #ifdef POST
        wdt_reset();
        #endif
        HTU21D_H = myHumidity.readHumidity();
    }
    #endif             
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef HIH4030_ADD
    if((EEPROM.read(HIH4030_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("HIH4030");
        Serial.flush();
        #endif               
        HIH4030_1_Value = analogRead(HIH4030_PIN);
    }
    #endif              
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef THERMIS_100K_ADD
    if((EEPROM.read(THERMIS_100K_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("THERMIS_100K");
        Serial.flush();
        #endif               
        THERMIS_1_Value = analogRead(THERMIS_100K_Pin);
    }
    #endif                   
    
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef DS18B20_ADD
    if((EEPROM.read(DS18B20_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("DS18B20");
        Serial.flush();
        #endif               
        DS18B20_1_temperature = DS18B20_1_getTemp();
    }
    #endif              
    
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef TMP421_ADD
    if((EEPROM.read(TMP421_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("TMP421");
        Serial.flush();
        #endif               
        TMP421_1_temperature = TMP421_1.GetTemperature();                               
    }
    #endif             
    
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef RHT03_ADD
    if((EEPROM.read(RHT03_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("RHT03");
        Serial.flush();
        #endif               
        chk_RHT03_1 = RHT03_1.read22(RHT03_1_PIN);
    }
    #endif            
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef BMP180_ADD
    if((EEPROM.read(BMP180_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("BMP180");
        Serial.flush();
        #endif               
        BMP_180_1.getPressure(&BMP_180_1_pressure);
        BMP_180_1.getTemperature(&BMP_180_1_temperature);
    }
    #endif             
    
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef TMP102_ADD
    if((EEPROM.read(TMP102_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("TMP102");
        Serial.flush();
        #endif               
        err = Wire.requestFrom(tmp102_1_Address,2);
        if (err != 0) {
            byte tmp102_1_MSB = Wire.read();
            byte tmp102_1_LSB = Wire.read();
            tmp102_1_temperature = (((tmp102_1_MSB << 8) | tmp102_1_LSB) >> 4) * 0.11250 + 32;                                                        
        }
        else {
            tmp102_1_temperature = -999;
        }
    }
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef HIH6130_ADD
    if((EEPROM.read(HIH6130_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("HIH6130");
        Serial.flush();
        #endif               
        
        HIH_6130_1_hih.start();
        #ifdef POST
        wdt_reset();
        #endif
        HIH_6130_1_hih.update();
        #ifdef POST
        wdt_reset();
        #endif
        HIH_6130_1_hih.stop();
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif              
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef MLX90614_ADD
    if((EEPROM.read(MLX90614_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("MLX90614");
        Serial.flush();
        #endif               
        start_err = i2c_start(dev+I2C_WRITE);
        #ifdef POST
        wdt_reset();
        #endif
        write_err = i2c_write(0x07);
        
        #ifdef POST
        wdt_reset();
        #endif
               
        rep_start_err = i2c_rep_start(dev+I2C_READ);
        #ifdef POST
        wdt_reset();
        #endif
        data_low = i2c_readAck();                                
        #ifdef POST
        wdt_reset();
        #endif
        data_high = i2c_readAck();                                
        #ifdef POST
        wdt_reset();
        #endif
        pec = i2c_readNak();
                      
        #ifdef POST
        wdt_reset();
        #endif
                                                                                                                          
        tempData = 0x0000;                     
        
                                                                                                          
        tempData = (double)(((data_high & 0x007F) << 8) + data_low);
        tempData = (tempData * tempFactor)-0.01;
        
        celcius = tempData - 273.15;
        fahrenheit = (celcius*1.8) + 32;
        #ifdef POST
        wdt_reset();
        #endif
    }
    #endif               
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef HMC5883_ADD
    if((EEPROM.read(HMC5883_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("HMC5883");
        Serial.flush();
        #endif
        mag.getEvent(&HMC5883_event);
          
                                              
                                                                                             
           
                                                                                                                                                        
                                                                         
                                                                                             
                                                                                                                        
                                                             
                                                             
           
                                                        
                                        
                                             
           
                                                                  
                                           
                                             
           
                                                               
                                                                       
    }
    #endif              
    #ifdef POST
    wdt_reset();
    #endif
    
                                                            
    for (unsigned int perform_loop = 0; perform_loop < MMA_Buff_size - 10 ; perform_loop ++ )
    {
        increment_time();
        #ifdef POST
        wdt_reset();
        #endif
        #ifdef debug_serial
        Serial.println("increment time");
        Serial.flush();
        #endif               
        #ifdef POST
        wdt_reset();
        #endif
        delay(sleep_time_loop);
        #ifdef POST
        wdt_reset();
        #endif
        #ifdef debug_serial
        Serial.println("delay");
        Serial.flush();
        #endif               
        #ifdef POST
        wdt_reset();
        #endif
        
    }
                                                                              
    #ifdef WindVel_ADD
    if((EEPROM.read(WindVel_ADD+128) & Consistency_Mask) == Consistency_Mask)
    {
        #ifdef debug_serial
        Serial.println("WindVel");
        Serial.print("Number of samples:");
        Serial.println(sample_rate*sample_time);
        Serial.flush();
        #endif
        
        take_samples();                                           
                                                                          
        calc_speed();                                         
                                                        
    }
    #endif
    
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef MMA8452
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("MMA8452");
        Serial.print("Number of samples:");
        Serial.println(q);
        Serial.flush();
        #endif               
        #ifdef POST
        wdt_reset();
        #endif
        calc_MMA_RMS();
    }
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef debug_serial
    Serial.print("Sensor");
    Serial.flush();
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    sensor_print();
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef debug_serial
    Serial.flush();
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef MAX4466_ADD
    if((EEPROM.read(MAX4466_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("MAX4466");
        Serial.flush();
        #endif               
        MAX4466_Value = 0;
    }
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef MMA8452
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        #ifdef debug_serial
        Serial.println("MMA8452");
        Serial.flush();
        #endif
        q = 0;
        xmean = 0;
        ymean = 0;
        zmean = 0;
        rt_mean_sq = 0;
        xvar = 0;
        yvar = 0;
        zvar = 0;
        mean_square_var = 0;
    }
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef debug_serial
    Serial.flush();
    #endif               
}
#line 1 "post.ino"
#ifdef POST
void post() { 
    byte testing_bit = EEPROM.read(testing_addr); 
                                                                  
    byte current_sensor = 1; 
                                                                                  
                                                                              
               
    
    if(testing_bit==0)                            
    {
        #ifdef debug_serial
        Serial.println("Commencing POST");
        Serial.flush();
        #endif
        for(byte i = 1; i <= numSensors; i++)
        {
            EEPROM.write(i, 0);                            
            
            byte history = EEPROM.read(i+128);
            history = history << 1;                                                      
            EEPROM.write(i+128, history); 
        }
        EEPROM.write(testing_addr, 1);                    
    }
    
    
                                                    
    else        
    {
                                                                               
                                                    
       for(byte j = 1; j <= numSensors; j++)
       {
           if(EEPROM.read(j)==1)
           {
               current_sensor=j;
           }
       }
       current_sensor++;
       #ifdef debug_serial
       Serial.print("Test Failed, resuming from sensor ");
       Serial.println(current_sensor);
       Serial.flush();
       #endif
    }
    
                                               
                                                               
        
    wdt_enable(WDTO_2S);                                  
    for(byte k = current_sensor; k<=numSensors; k++)                    
    {
        
        #ifdef SHT75_ADD                    
        if(k==1)
        {
            EEPROM.write(SHT75_ADD,1);
            #ifdef debug_serial
            Serial.print("Testing SHT75\t");
            Serial.flush();
            #endif
                            
                                                                                         
                                    
                                                                  
            float SHT75_1_temperature;
            float SHT75_1_humidity;
            uint16_t SHT75_1_rawData;
            uint8_t SHT75_1_error;
            for(int a = 0; a<10; a++)
                                                  
            {
                SHT75_1_error = SHT75_1_tempSensor.measTemp(&SHT75_1_rawData);
                wdt_reset();
                SHT75_1_temperature = SHT75_1_tempSensor.calcTemp(SHT75_1_rawData);
                wdt_reset();
                SHT75_1_error = SHT75_1_tempSensor.measHumi(&SHT75_1_rawData);
                wdt_reset();
                SHT75_1_humidity = SHT75_1_tempSensor.calcHumi(SHT75_1_rawData, SHT75_1_temperature);
                wdt_reset();
                delay(500);        
                wdt_reset();
            }
            byte history = EEPROM.read(SHT75_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(SHT75_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif
        
        #ifdef BMP180_ADD                   
        if(k==2)
        {
            EEPROM.write(BMP180_ADD, 1);
            
            #ifdef debug_serial
            Serial.print("Testing BMP\t");
            Serial.flush();
            #endif
            Wire.begin();
            Adafruit_BMP085_Unified BMP_180_2 = Adafruit_BMP085_Unified(10085);
            float BMP_180_2_temperature, BMP_180_2_pressure;
            BMP_180_2.begin();
            
            for(int a = 0; a<10; a++)
            {
                BMP_180_2.getTemperature(&BMP_180_2_temperature);
                BMP_180_2.getPressure(&BMP_180_2_pressure);
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(BMP180_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(BMP180_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif          
                                          
        #ifdef RHT03_ADD                    
        if(k==3)
        {
            EEPROM.write(RHT03_ADD, 1);
            #ifdef debug_serial
            Serial.print("Testing RHT03\t");
            Serial.flush();
            #endif
            
            dht RHT03_1;
            int chk_RHT03_1;
            
            for(int a = 0; a<10; a++)
            {
                chk_RHT03_1 = RHT03_1.read22(RHT03_1_PIN);
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(RHT03_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(RHT03_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif
        
        #ifdef TMP102_ADD                   
        if(k==4)
        {
            EEPROM.write(TMP102_ADD, 1);
            
            const int tmp102_1_Address = 0x48;
            float tmp102_1_temperature;
            byte tmp102_1_MSB, tmp102_1_LSB;
            int err;
            Wire.begin();
            
            #ifdef debug_serial
            Serial.print("Testing TMP102\t");
            Serial.flush();
            #endif
            for(int a = 0; a<10; a++)
            {
                err = Wire.requestFrom(tmp102_1_Address,2);
                if (err != 0) {
                    byte tmp102_1_MSB = Wire.read();
                    byte tmp102_1_LSB = Wire.read();
                    tmp102_1_temperature = (((tmp102_1_MSB << 8) | tmp102_1_LSB) >> 4) * 0.11250 + 32; 
                                                                           
                }
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(TMP102_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(TMP102_ADD+128,history);                         
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif

                           
        #ifdef SHT15_ADD                    
        #define SHT15_1_dataPin  11                           
        #define SHT15_1_sclkPin  12                            
        if(k==5)
        {
            EEPROM.write(SHT15_ADD, 1);
            
            float SHT15_1_temperature;
            float SHT15_1_humidity;
            uint16_t SHT15_1_rawData;
            uint8_t SHT15_1_error;
            
            #ifdef debug_serial
            Serial.print("Testing SHT15\t");
            Serial.flush();
            #endif
            
            Sensirion SHT15_1_tempSensor = Sensirion(SHT15_1_dataPin, SHT15_1_sclkPin);
            for(int a = 0; a<10; a++)
            {
                SHT15_1_error = SHT15_1_tempSensor.measTemp(&SHT15_1_rawData);
                SHT15_1_temperature = SHT15_1_tempSensor.calcTemp(SHT15_1_rawData);
                SHT15_1_error = SHT15_1_tempSensor.measHumi(&SHT15_1_rawData);
                SHT15_1_humidity = SHT15_1_tempSensor.calcHumi(SHT15_1_rawData, SHT15_1_temperature);
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(SHT15_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(SHT15_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif

        #ifdef MMA8452              
        if(k==6)
        {
            EEPROM.write(MMA8452,1);
            int accelCount[3];                                  
            float accelG[3];                                      
            
            #ifdef debug_serial
            Serial.print("Testing MMA\t");
            Serial.flush();
            #endif

                                       
                              
                                        
                   
                                             
            for(int a = 0; a<10; a++)
            {
                                                                                           
            
                MMA_found = initMMA8452();
                MMA8452_get_means();
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(MMA8452+128);
            history = history | 0x01;                                              
            EEPROM.write(MMA8452+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif
        
        #ifdef HIH6130_ADD                  
        if(k==7)
        {
            EEPROM.write(HIH6130_ADD,1);
            #ifdef debug_serial
            Serial.print("Testing HIH6130\t");
            Serial.flush();
            #endif
            
            for(int a = 0; a<10; a++)
            {
                HIH_6130_1_hih.start();
                HIH_6130_1_hih.update();
                HIH_6130_1_hih.humidity();
                HIH_6130_1_hih.temperature();
                HIH_6130_1_hih.stop();
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(HIH6130_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(HIH6130_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif
        
                            
        #ifdef DS18B20_ADD                  
        if(k==8)
        {
            EEPROM.write(DS18B20_ADD,1);
            #ifdef debug_serial
            Serial.print("Testing DS18B20\t");
            Serial.flush();
            #endif
            for(int a = 0; a<10; a++)
            {
                float data = DS18B20_1_getTemp();
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(DS18B20_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(DS18B20_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif

        
        #ifdef MLX90614_ADD         
        if(k==9)
        {
            EEPROM.write(MLX90614_ADD,1);
            #ifdef debug_serial
            Serial.print("Testing MLX\t");
            Serial.flush();
            #endif
            
            i2c_init();                         
            #define I2C_INIT_ADD 1
            for(int a = 0; a<10; a++)
            {
                PORTC = (1 << PORTC4) | (1 << PORTC5);                
                
                start_err = i2c_start(dev+I2C_WRITE);
                write_err = i2c_write(0x07);

                
                start_err = i2c_start(dev+I2C_WRITE);
                write_err = i2c_write(0x07);

                       
                rep_start_err = i2c_rep_start(dev+I2C_READ);
                data_low = i2c_readAck();                                
                data_high = i2c_readAck();                                
                pec = i2c_readNak();
                i2c_stop();       
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(MLX90614_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(MLX90614_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif
        
                        
        #ifdef GA1A1S201WP_ADD              
        if(k==10)
        {
            EEPROM.write(GA1A1S201WP_ADD, 1);
            #ifdef debug_serial
            Serial.print("Testing GA1A\t");
            Serial.flush();
            #endif
            for(int a = 0; a<10; a++)
            {
                AMBI_1_Value = analogRead(AMBI_1_Pin);
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(GA1A1S201WP_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(GA1A1S201WP_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif

                    
        #ifdef THERMIS_100K_ADD             
        if(k==11)
        {
            EEPROM.write(THERMIS_100K_ADD, 1);
            #ifdef debug_serial
            Serial.print("Testing THERMIS\t");
            Serial.flush();
            #endif
            
            for(int a = 0; a<10; a++)
            {
                THERMIS_1_Value = analogRead(THERMIS_100K_Pin);
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(THERMIS_100K_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(THERMIS_100K_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif

                    
        #ifdef MAX4466_ADD                 
        if(k==12)
        {
            EEPROM.write(MAX4466_ADD, 1);
            #ifdef debug_serial
            Serial.print("Testing MAX\t");
            Serial.flush();
            #endif
            for(int a = 0; a<10; a++)
            {
                                                      
                MAX4466_get_max();
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(MAX4466_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(MAX4466_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif
        
        #ifdef TMP421_ADD                  
        if(k==13)
        {
            EEPROM.write(TMP421_ADD, 1);
            pinMode(A2, INPUT);                  
            pinMode(A3, INPUT);                  
            digitalWrite(A3, LOW);                        
            
            #ifdef debug_serial
            Serial.print("Testing TMP421\t");
            Serial.flush();
            #endif
            
            for(int a = 0; a<10; a++)
            {
                TMP421_1_temperature = TMP421_1.GetTemperature();
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(TMP421_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(TMP421_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }                
        #endif
        
        #ifdef IR_D6T_44L_06_ADD           
        if(k==14)
        {
            EEPROM.write(IR_D6T_44L_06_ADD,1);
            #ifdef debug_serial
            Serial.print("Testing IR_D6T\t");
            Serial.flush();
            #endif

            int rbuf[35];
            float tdata[16];
            float t_PTAT;
            float tPEC;
            bool data_check;
            
            #ifndef I2C_INIT_ADD
            i2c_init();
            #define I2C_INIT_ADD 1
            #endif               
            pinMode(17,OUTPUT);                                           
            digitalWrite(17,HIGH);
            pinMode(16,OUTPUT);                                                  
            digitalWrite(16,LOW);
            pinMode(A4,INPUT);
            digitalWrite(A4,HIGH);                            
            pinMode(A5,INPUT);
            digitalWrite(A5,HIGH);                            
            
            for(int a = 0; a<10; a++)
                               
            {
                bool temp = D6T_get_data();               
                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            i2c_stop();
            
            byte history = EEPROM.read(IR_D6T_44L_06_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(IR_D6T_44L_06_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif
        
        #ifdef HIH4030_ADD                 
        if(k==15)
        {
            EEPROM.write(HIH4030_ADD, 1);
            #ifdef debug_serial
            Serial.print("Testing HIH4030\t");
            Serial.flush();
            #endif
            for(int a = 0; a<10; a++)
                                    
            {
                HIH4030_1_Value = analogRead(HIH4030_PIN);                
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(HIH4030_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(HIH4030_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif

                    
        #ifdef PhoRes_ADD                  
        if(k==16)
        {
            EEPROM.write(PhoRes_ADD,1);
            #ifdef debug_serial
            Serial.print("Testing PhoRes\t");
            Serial.flush();
            #endif
            for(int a = 0; a<10; a++)
                                    
            {
                PhoRes_1_Value = analogRead(PhoRes_PIN);                  
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(PhoRes_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(PhoRes_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif
                    
        #ifdef WindVel_ADD             
        if(k==17)
        {
            EEPROM.write(WindVel_ADD, 1);
            #ifdef debug_serial
            Serial.print("Testing WindVel\t");
            Serial.flush();
            #endif
            
            mag.begin();
                                        
            mag.setDataReady(0);
            delay(2000);
            
            for(int a = 0; a<10; a++)
                                    
            {
                mag.setSingleMeasurementMode();
                wdt_reset();
                delay(sample_delay);                                        
                while((mag.getDataReady() & 0x01) != 0x01);                           
                wdt_reset();
                
                                             
                int16_t y_val;
                Wire.beginTransmission(HMC5883_ADDRESS_MAG);                              
                Wire.write(HMC5883_REGISTER_MAG_OUT_Y_H_M);                                    
                Wire.endTransmission();
                wdt_reset();
                Wire.beginTransmission(HMC5883_ADDRESS_MAG);                     
                Wire.requestFrom(HMC5883_ADDRESS_MAG, 2);                                  
                wdt_reset();
                while(!Wire.available()) {};
                wdt_reset();
                uint8_t vha = Wire.read();
                uint8_t vla = Wire.read();
                wdt_reset();
                Wire.endTransmission();
                wdt_reset();
                
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(WindVel_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(WindVel_ADD+128,history);
            wdt_reset();
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif               

        #ifdef HTU21D_ADD                   
        if(k==18)
        {
            EEPROM.write(HTU21D_ADD, 1);
            
            #ifdef debug_serial
            Serial.print("Testing HTU21D\t");
            Serial.flush();
            #endif
            
            myHumidity.begin();
            
            if(myHumidity.readHumidity()!=998 && myHumidity.readTemperature()!=998)
                                                                                         
            {   
                wdt_reset();
                byte history = EEPROM.read(HTU21D_ADD+128);
                history = history | 0x01;                                              
                EEPROM.write(HTU21D_ADD+128,history);
                #ifdef debug_serial
                Serial.print("Test passed successfully: History = ");
                Serial.println(history);
                Serial.flush();
                #endif
                wdt_reset();
            }
            else
            {
                Serial.println("\nTest failed, resuming from sensor 19");
            }
        }
        #endif
        wdt_reset();

        #ifdef HMC5883_ADD
        if(k==19)
        {
            EEPROM.write(HMC5883_ADD, 1);
            #ifdef debug_serial
            Serial.print("Testing HMC\t");
            Serial.flush();
            #endif
            
            Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(23181);
            sensors_event_t HMC5883_event;
            
            
            mag.begin();
            for(int a = 0; a<10; a++)
                                    
            {
                mag.getEvent(&HMC5883_event);                 
                wdt_reset();
                delay(500);
                wdt_reset();
            }
            byte history = EEPROM.read(HMC5883_ADD+128);
            history = history | 0x01;                                              
            EEPROM.write(HMC5883_ADD+128,history);
            #ifdef debug_serial
            Serial.print("Test passed successfully: History = ");
            Serial.println(history);
            Serial.flush();
            #endif
            wdt_reset();
        }
        #endif           
        
        wdt_reset();
        
    }
    EEPROM.write(testing_addr, 0);                           
    #ifdef debug_serial
    Serial.println("POST TEST RESULTS:");
    
    #ifdef SHT75_ADD
    Serial.print("SHT75:\t\t");
    if((EEPROM.read(SHT75_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif          
        
    #ifdef BMP180_ADD
    Serial.print("BMP180:\t\t");
    if((EEPROM.read(BMP180_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif           
        
    #ifdef RHT03_ADD
    Serial.print("RHT03:\t\t");
    if((EEPROM.read(RHT03_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif         
        
    #ifdef TMP102_ADD
    Serial.print("TMP102:\t\t");
    if((EEPROM.read(TMP102_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif           
    
    #ifdef SHT15_ADD
    Serial.print("SHT15:\t\t");
    if((EEPROM.read(SHT15_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif          
        
    #ifdef MMA8452
    Serial.print("MMA8452:\t");
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif            
        
    #ifdef HIH6130_ADD
    Serial.print("HIH6130:\t");
    if((EEPROM.read(HIH6130_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif           
        
    #ifdef DS18B20_ADD
    Serial.print("DS18B20:\t");
    if((EEPROM.read(DS18B20_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif           
        
    #ifdef MLX90614_ADD
    Serial.print("MLX90614\t");
    if((EEPROM.read(MLX90614_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif            
        
    #ifdef GA1A1S201WP_ADD
    Serial.print("GA1A1S201WP:\t");
    if((EEPROM.read(GA1A1S201WP_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif              

    #ifdef THERMIS_100K_ADD
    Serial.print("THERMIS_100K:\t");
    if((EEPROM.read(THERMIS_100K_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif          
        
    #ifdef MAX4466_ADD
    Serial.print("MAX4466:\t");
    if((EEPROM.read(MAX4466_ADD+128) & Consistency_Mask) == Consistency_Mask)                                  
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif           

    #ifdef TMP421_ADD
    Serial.print("TMP421:\t\t");
    if((EEPROM.read(TMP421_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif          

    #ifdef IR_D6T_44L_06_ADD
    Serial.print("IR_D6T:\t\t");
    if((EEPROM.read(IR_D6T_44L_06_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif          

    #ifdef HIH4030_ADD
    Serial.print("HIH4030:\t");
    if((EEPROM.read(HIH4030_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif           
        
    #ifdef PhoRes_ADD
    Serial.print("PhoRes:\t\t");
    if((EEPROM.read(PhoRes_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif          
    
    #ifdef WindVel_ADD
    Serial.print("WindVel:\t");
    if((EEPROM.read(WindVel_ADD+128) & Consistency_Mask) == Consistency_Mask)                                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif           
    
    #ifdef HTU21D_ADD
    Serial.print("HTU21D:\t\t");
    if((EEPROM.read(HTU21D_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");
    #endif          
    
    #ifdef HMC5883_ADD
    Serial.print("HMC5883:\t");
    if((EEPROM.read(HMC5883_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
        Serial.println("Functioning");
    else
        Serial.println("Offline");

    Serial.flush();
    #endif          
    #endif               
    wdt_reset();
}
#endif   
#line 1 "sensorPrint.ino"
void sensor_print()
{
    #ifdef debug_serial
    Serial.println(" print");
    Serial.flush();
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef MLX90614_ADD
    if((EEPROM.read(MLX90614_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        if (start_err == 1 || write_err == 1 || rep_start_err == 1)
        {
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("MLX90614_1_T_F:");
            Serial.print(-999);
            Serial.print(";");
            #endif
        }
        else {
            Serial.print("MLX90614_1_T_F:");
            Serial.print(fahrenheit);
            Serial.print(";");
        }
        Serial.println("WXSensor");
    }
    #endif               

    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef IR_D6T_44L_06_ADD
    if((EEPROM.read(IR_D6T_44L_06_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        if (data_check == true) {
            Serial.print("D6T_44L_06_1_T_C:");
            output_csv();
            Serial.print(";");
        }
        else {
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("D6T_44L_06_1_T_C:");
            Serial.print("-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999;");
            #endif
        }
        Serial.println("WXSensor");
    }
    #endif                    

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef TMP421_ADD
    if((EEPROM.read(TMP421_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        if (TMP421_1_temperature == -999) {
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("TMP421_1_T_C:");
            Serial.print(TMP421_1_temperature, 2);
            Serial.print(";");
            #endif
        }
        else {
            Serial.print("TMP421_1_T_C:");
            Serial.print(TMP421_1_temperature, 2);
            Serial.print(";");
        }
        Serial.println("WXSensor");
    }
    #endif             

    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef BMP180_ADD
    if((EEPROM.read(BMP180_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        if (BMP_180_1_temperature == -999 || BMP_180_1_pressure == -999) {
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("BMP_180_1_T_C:");
            Serial.print(BMP_180_1_temperature, 2);
            Serial.print(";");
            Serial.print("BMP_180_1_P_PA:");
            Serial.print(BMP_180_1_pressure, 2);
            Serial.print(";");
            #endif
        }
        else {
            Serial.print("BMP_180_1_T_C:");
            Serial.print(BMP_180_1_temperature, 2);
            Serial.print(";");
            Serial.print("BMP_180_1_P_PA:");
            Serial.print(BMP_180_1_pressure, 2);
            Serial.print(";");
        }
        Serial.println("WXSensor");
    }
    #endif             
    #ifdef POST
    wdt_reset();
    #endif

    #ifdef MMA8452
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        if (MMA_found == true) {
            Serial.print("MMA8452_1_A_X_Units:");
            Serial.print(xmean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_Y_Units:");
            Serial.print(ymean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_Z_Units:");
            Serial.print(zmean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_RMS_Units:");
            Serial.print(rt_mean_sq);
            Serial.print(";");
        }
        else {
            #ifndef SILENCE_BAD_SENSORS
            xmean = -999, ymean = -999, zmean = -999, rt_mean_sq = -999;
            Serial.print("MMA8452_1_A_X_Units:");
            Serial.print(xmean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_Y_Units:");
            Serial.print(ymean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_Z_Units:");
            Serial.print(zmean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_RMS_Units:");
            Serial.print(rt_mean_sq);
            Serial.print(";");
            MMA_found = initMMA8452();
            #endif
        }
        Serial.println("WXSensor");
    }
    #endif          

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef PhoRes_ADD
    if((EEPROM.read(PhoRes_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("PhoRes_10K4.7K_1_Units:");
        Serial.print(PhoRes_1_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif             

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef THERMIS_100K_ADD
    if((EEPROM.read(THERMIS_100K_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("THERMIS_100K_1_Units:");
        Serial.print(THERMIS_1_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif                   

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HIH6130_ADD
    if((EEPROM.read(HIH6130_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("HIH_6130_1_T_C:");
        Serial.print(HIH_6130_1_hih.temperature(), 2);
        Serial.print(";");
        Serial.print("HIH_6130_1_H_%:");
        Serial.print(HIH_6130_1_hih.humidity(), 2);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif              

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef SHT15_ADD
    if((EEPROM.read(SHT15_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("SHT15_1_T_C:");
        Serial.print(SHT15_1_temperature,2);
        Serial.print(";");
        Serial.print("SHT15_1_H_%:");
        Serial.print(SHT15_1_humidity,2);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif            

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef DS18B20_ADD
    if((EEPROM.read(DS18B20_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("DS18B20_1_T_C:");
        Serial.print(DS18B20_1_temperature, 2);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif              

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef RHT03_ADD
    if((EEPROM.read(RHT03_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        if (chk_RHT03_1 == DHTLIB_OK)
        {
            Serial.print("RHT03_1_T_C:");
            Serial.print(RHT03_1.temperature, 2);
            Serial.print(";");
            Serial.print("RHT03_1_H_%:");
            Serial.print(RHT03_1.humidity, 2);
            Serial.print(";");
        }
        Serial.println("WXSensor");
    }
    #endif            

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef TMP102_ADD
    if((EEPROM.read(TMP102_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        if (err != 0) {
            Serial.print("TMP102_1_T_F:");
            Serial.print(tmp102_1_temperature,2);
            Serial.print(";");
        }
        else{
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("TMP102_1_T_F:");
            Serial.print(tmp102_1_temperature,2);
            Serial.print(";");
            #endif
        }
        Serial.println("WXSensor");
    }
    #endif             

    #ifdef SHT75_ADD
    if((EEPROM.read(SHT75_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("SHT75_1_T_C:");
        Serial.print(SHT75_1_temperature,2);
        Serial.print(";");
        Serial.print("SHT75_1_H_%:");
        Serial.print(SHT75_1_humidity,2);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif            

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HIH4030_ADD
    if((EEPROM.read(HIH4030_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("HIH4030_1_Units:");
        Serial.print(HIH4030_1_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif              

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef GA1A1S201WP_ADD
    if((EEPROM.read(GA1A1S201WP_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("AMBI_1_Units:");
        Serial.print(AMBI_1_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif                  

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef MAX4466_ADD
    if((EEPROM.read(MAX4466_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("MAX4466_1_MaxN_Units:");
        Serial.print(MAX4466_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif              

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef WindVel_ADD
    if((EEPROM.read(WindVel_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
                                               
                                      
                             
                                               
                                   
        Serial.print("WindVel_1_V_M/S:");
        Serial.print(speed_mps);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif              

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HTU21D_ADD
    if((EEPROM.read(HTU21D_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
        Serial.print("WXSensor;");
        Serial.print("HTU21D_T_C:");
        Serial.print(HTU21D_T, 1);
        Serial.print(";");
        Serial.print("HTU21D_H_%:");
        Serial.print(HTU21D_H, 1);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif             

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HMC5883_ADD
    if((EEPROM.read(HMC5883_ADD+128) & Consistency_Mask) == Consistency_Mask)                                 
    {
                                                                                  
        Serial.print("WXSensor;");
        Serial.print("HMC5883_X_uT:");
        Serial.print(HMC5883_event.magnetic.x);
        Serial.print(";");
        Serial.print("HMC5883_Y_uT:");
        Serial.print(HMC5883_event.magnetic.y);
        Serial.print(";");
        Serial.print("HMC5883_Z_uT:");
        Serial.print(HMC5883_event.magnetic.z);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif              
    
    #ifdef POST
    wdt_reset();
    #endif
}

