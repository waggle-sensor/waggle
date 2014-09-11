// Sensor Cluster Code, version 4
// Using interrupts, gets readings from three time-sensitive sensors (noise, wind velocity, and 
// acceleration) 25 times per second and gets readings from all other sensors once every second
// Includes a watchdog timer to make sure the code does not hang infinitely if there is a problem
// Time between readings can be adjusted

// Edited By: Kaitlyn MacIntyre

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

#include <OneWire.h> 
#include <dht.h>
#include <Wire.h> 
//I2C library
#include <HIH61XX.h>
#include <LibTempTMP421.h>
#include <DallasTemperature.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include <TimerOne.h>
#include <TimerThree.h>
#include <avr/wdt.h>

#define debug_serial 1

#define SHT75_ADD 1
#define BMP180_ADD 2
#define RHT03_ADD 3
#define TMP102_ADD 4
#define SHT15_ADD 6
#define MMA8452_ADD 5
#define HIH6130_ADD 7
#define DS18B20_ADD 8
#define MLX90614_ADD 9
#define GA1A1S201WP_ADD 10
#define THERMIS_100K_ADD 11
#define MAX4466_ADD 12
#define TMP421_ADD 13
#define IR_D6T_44L_06_ADD 14 
#define HIH4030_ADD 15
#define PhoRes_ADD 16
#define WindVel_ADD 17

int timer1_runs = 0;
int timer3_runs = 0;
int counter = 0;
int counter_time = 0;
byte oldSREG;

void watchdogSetup(void) 
{
  cli();
  wdt_reset(); 
  /*
  WDTCSR configuration: 
  WDIE = 0: Interrupt Enable 
  WDE  = 1: Reset Enable 
  See table for time-out variations: 
  WDP3 = 0: For 1000ms Time-out 
  WDP2 = 1: For 1000ms Time-out 
  WDP1 = 1: For 1000ms Time-out 
  WDP0 = 0: For 1000ms Time-out
  */
  // Enter Watchdog Configuration mode: 
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  // Set Watchdog settings: 
  WDTCSR = (1<<WDE) | (1<<WDP3); // | (0<<WDP2) | (0<<WDP1) | (0<<WDP0);
  sei(); 
}

#ifdef IR_D6T_44L_06_ADD
#include <i2cmaster.h>
#define I2C_ADD 1
int rbuf[35];
float tdata[16];
float t_PTAT;
float tPEC;

bool D6T_get_data(void) {
  int k;
  i2c_start_wait(0x14);
  i2c_write(0x4C);
  
  i2c_rep_start(0x15);
  for (k = 0; k < 35; k++) {
    if (k == 34) {
      rbuf[k] = i2c_readNak();
    }
    else {
      rbuf[k] = i2c_readAck();
    }
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
#endif //IR_D6T_44L_06_ADD

#ifdef MMA8452_ADD
#ifndef I2C_ADD
#include <i2cmaster.h>
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
float xvals[25], yvals[25], zvals[25];
int n = 0;

void MMA8452_get_data(float *xvals, float *yvals, float *zvals)
{
  int accelCount[3]; // Stores the 12-bit signed value

  readAccelData(accelCount); // Read the x/y/z adc values

  float accelG[3]; // Stores the real accel value in g's
  for (int i = 0 ; i < 3 ; i++)
  {
    accelG[i] = (float) accelCount[i] / ((1<<12)/(2*GSCALE)); // get actual g value, this depends on scale being set
  }

  xvals[n] = accelG[0];
  yvals[n] = accelG[1];
  zvals[n] = accelG[2];
  n++;
}

void MMA8452_calc_means(float *xmean, float *ymean, float *zmean, float *rt_mean_sq)
{
  n = 0;
  float xtotal = 0, ytotal = 0, ztotal = 0, xvar = 0, yvar = 0, zvar = 0, mean_square_var;

  while (n < 25){
    xtotal += xvals[n];
    ytotal += yvals[n];
    ztotal += zvals[n];
    n++;
  }

  *xmean = xtotal/25;
  *ymean = ytotal/25;
  *zmean = ztotal/25;

  for (int j = 0; j < 25; j++)
  {
    xvar += sq(xvals[j] - *xmean);
    yvar += sq(yvals[j] - *ymean);
    zvar += sq(zvals[j] - *zmean);
  }

  mean_square_var = (sq(xvar) + sq(yvar) + sq(zvar))/3;
  *rt_mean_sq = sqrt(mean_square_var);
}

void readAccelData(int *destination)
{
  byte rawData[6]; // x/y/z accel register data stored here

  readRegisters(OUT_X_MSB, 6, rawData); // Read the six raw data registers into data array

  // Loop to calculate 12-bit ADC and g value for each axis
  for(int i = 0; i < 3 ; i++)
  {
    int gCount = (rawData[i*2] << 8) | rawData[(i*2)+1]; //Combine the two 8 bit registers into one 12-bit number
    gCount >>= 4; //The registers are left align, here we right align the 12-bit integer
    
    // If the number is negative, we have to make it so manually (no 12-bit data type)
    if (rawData[i*2] > 0x7F)
    {
      gCount = ~gCount + 1;
      gCount *= -1; // Transform into negative 2's complement #
    }

    destination[i] = gCount; //Record this gCount into the 3 int array
  }
}

void initMMA8452()
{
  byte c = readRegister(WHO_AM_I); // Read WHO_AM_I register
  if (c == 0x2A) ; // WHO_AM_I should always be 0x2A
  else
    Serial.print("Error with MMA8452");

  MMA8452Standby(); // Must be in standby to change registers

  byte fsr = GSCALE;
  if(fsr > 8) fsr = 8; //Easy error check
  fsr >>= 2;
  writeRegister(XYZ_DATA_CFG, fsr);

  MMA8452Active(); // Set to active to start reading
}

void MMA8452Standby()
{
  byte c = readRegister(CTRL_REG1);
  writeRegister(CTRL_REG1, c & ~(0x01)); //Clear the active bit to go into standby
}

void MMA8452Active()
{
  byte c = readRegister(CTRL_REG1);
  writeRegister(CTRL_REG1, c | 0x01); //Set the active bit to begin detection
}

void readRegisters(byte addressToRead, int bytesToRead, byte * dest)
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
  }
}

byte readRegister(byte addressToRead)
{
  i2c_start(MMA8452_ADDRESS_WRITE); // Write address
  i2c_write(addressToRead);
  i2c_rep_start(MMA8452_ADDRESS_READ); // Read address

  return i2c_readNak();
}

void writeRegister(byte addressToWrite, byte dataToWrite)
{
  i2c_start(MMA8452_ADDRESS_WRITE);
  i2c_write(addressToWrite);
  i2c_write(dataToWrite);
  i2c_stop();
}
#endif //MMA8452_ADD

#ifdef HIH4030_ADD
#define HIH4030_PIN A2
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
#endif //MLX90614_ADD

#ifdef PhoRes_ADD
#define PhoRes_PIN A3 
int PhoRes_1_Value;
#endif //PhoRes_ADD

#ifdef SHT15_ADD
#include <Sensirion.h>
#define Sensirion_ADD 1
#define SHT15_1_dataPin  11     // SHT15_1 serial data
#define SHT15_1_sclkPin  12     // SHT15_1 serial clock
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
#define SHT75_1_dataPin 10  // SHT15_1 serial data
#define SHT75_1_sclkPin 9   // SHT15_1 serial clock
float SHT75_1_temperature;
float SHT75_1_humidity;
uint16_t SHT75_1_rawData;
uint8_t SHT75_1_error;
Sensirion SHT75_1_tempSensor = Sensirion(SHT75_1_dataPin, SHT75_1_sclkPin);
#endif //SHT75_ADD

#ifdef GA1A1S201WP_ADD
#define AMBI_1_Pin A6    // Ambient sensor
int AMBI_1_Value;
#endif //GA1A1S201WP_ADD

#ifdef MAX4466_ADD
#define MAX4466_PIN 1
const int MAX4466_Buff_Len = 100;
int MAX4466_Val[MAX4466_Buff_Len];   // variable to store the value coming from the sensor
int MAX4466_Peak;
int MAX4466_Peak_Vals[25];
int q = 0;
int p_mean = 0;

void MAX4466_get_data(int *MAX4466_Peak_Vals)
{
  for (int i=0;i<MAX4466_Buff_Len;i++)
  {
    MAX4466_Val[i]= analogRead(MAX4466_PIN);
  } 

  // we have read sample_size values, let us now find the peak of the 100 values. 
  MAX4466_Peak = 0;
  
  for (int i=0;i<MAX4466_Buff_Len;i++)
  {
    MAX4466_Peak = max(MAX4466_Peak , abs(512-MAX4466_Val[i]));
  }

  MAX4466_Peak_Vals[q] = MAX4466_Peak;
  q++;
}

void MAX4466_calc_mean(int *p_mean)
{
  q = 0;
  int p_total = 0;

  while (q < 25){
    p_total += MAX4466_Peak_Vals[q];
    q++;
  }

  *p_mean = p_total/25;
}
#endif //MAX4466_ADD

#ifdef THERMIS_100K_ADD
#define THERMIS_100K_Pin 0    // NTC sensor
int THERMIS_1_Value;
#endif //THERMIS_100K_ADD

#ifdef DS18B20_ADD
#define DS18B20_1_Pin 7
OneWire DS18B20_1_ds(DS18B20_1_Pin);  // Temperature chip i/o on digital pin 2
float DS18B20_1_temperature;

float DS18B20_1_getTemp()
{
  //returns the temperature from one DS18B20 in DEG Celsius
  
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
  
  byte present = DS18B20_1_ds.reset();
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
#define RHT03_1_PIN 8 // RHT03 Sensor pin
dht RHT03_1;
int chk_RHT03_1;
#endif //RHT03_ADD

#ifdef TMP102_ADD
const int tmp102_1_Address = 0x48;
float tmp102_1_temperature;
byte tmp102_1_MSB, tmp102_1_LSB;
#endif //TMP102_ADD

#ifdef HIH6130_ADD
//  Create an HIH61XX with I2C address 0x27, powered by pin 22
HIH61XX HIH_6130_1_hih(0x27,22);
#endif //HIH6130_ADD

#ifdef TMP421_ADD
LibTempTMP421 TMP421_1 = LibTempTMP421(0);
float TMP421_1_temperature;
#endif //TMP421_ADD

#ifdef BMP180_ADD
Adafruit_BMP085_Unified BMP_180_1 = Adafruit_BMP085_Unified(10085);
float BMP_180_1_temperature, BMP_180_1_pressure;
#endif //BMP180_ADD

#ifdef WindVel_ADD
unsigned int count = 0, cur_time = 0;
float RPM, airspeed;

void inc_count() {
  count++;
}
#endif //WindVel_ADD

void quicker_sensors()
{
  #ifdef MMA8452_ADD
  MMA8452_get_data(xvals, yvals, zvals);
  if (n > 24)
  {
    MMA8452_calc_means(&xmean, &ymean, &zmean, &rt_mean_sq);
    n = 0;
  }
  #endif //MMA8452_ADD

  #ifdef MAX4466_ADD 
  MAX4466_get_data(MAX4466_Peak_Vals);

  if (q > 24)
  {
    MAX4466_calc_mean(&p_mean);
    q = 0;
  }
  #endif //MAX4466_ADD

  #ifdef WindVel_ADD
  attachInterrupt(0, inc_count, FALLING);
  detachInterrupt(0);
  #endif //WindVel_ADD

  // counter++;
  timer3_runs += 1;
}

void setup()
{
  Serial.begin(115200);
  #ifdef debug_serial
  Serial.print("Starting Up");
  #endif //debug_serial
  
  #ifndef BMP180_ADD
  Wire.begin();
  #endif //BMP180_ADD

  wdt_reset();

  delay(3000); // waiting for the sensors to settle
  
  wdt_reset();

  #ifdef debug_serial
  Serial.println("...entering Sensor Loop...");
  #endif //debug_serial  
  
  #ifdef BMP180_ADD
  BMP_180_1.begin();
  #endif //BMP180_ADD
  // set the resolution to 10 bit (good enough?)

  #ifdef TMP421_ADD
  /************ The LibTemp421 library turns on Arduino pins A2, A3 (aka 16, 17) to power the sensor.
  *  This is necessary due to the fact that Wire.begin() is called in the constructor and needs to be 
  *  talk to the chip, which needs to be powered. If you are using the sensor in a differnt location
  *  and powering it from dedicated GND and +5V lines then include the lines below to reset the 
  *  A2 & A3 pins for use as analog inputs. */
  
  //  Uncomment the three lines below to reset the analog pins A2 & A3
  pinMode(A2, INPUT);        // GND pin      
  pinMode(A3, INPUT);        // VCC pin
  digitalWrite(A3, LOW);     // turn off pullups   
  #endif //TMP421_ADD
  
  #ifdef MLX90614_ADD
  i2c_init(); //Initialise the i2c bus
  #define I2C_INIT_ADD 1
  PORTC = (1 << PORTC4) | (1 << PORTC5);//enable pullups
  #endif //MLX90614_ADD
  
  #ifdef IR_D6T_44L_06_ADD
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
  #endif //IR_D6T_44L_06_ADD

  #ifdef MMA8452_ADD
  #ifndef I2C_INIT_ADD
  i2c_init();
  #endif //I2C_INIT_ADD
  initMMA8452();
  #endif //MMA8452_ADD

  #if FASTADC
  // set prescale to 16
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
  #endif //FASTADC

  Serial.println("Reached timers");

  Timer1.initialize();
  Timer3.initialize(40000);

  Timer1.attachInterrupt(sensors);
  Timer3.attachInterrupt(quicker_sensors);
  watchdogSetup();
}

void loop()
{
  Serial.print("Timer 1 Runs: ");
  Serial.println(timer1_runs);
  Serial.print("Timer 3 Runs: ");
  Serial.println(timer3_runs);

  Serial.println("Printing Sensor Data: ");

  wdt_reset();

  #ifdef PhoRes_ADD
  Serial.print("PhoRes_10K4.7K_Units:");
  Serial.print(PhoRes_1_Value);
  Serial.print("; ");
  #endif //PhoRes_ADD
  
  #ifdef MLX90614_ADD
  Serial.print("MLX90614_T_F:");
  Serial.print(fahrenheit);
  Serial.print("; ");
  #endif //MLX90614_ADD
  
  #ifdef IR_D6T_44L_06_ADD
  Serial.print("D6T_44L_06_1_T_C:");
  output_csv();
  Serial.print("; ");
  #endif //IR_D6T_44L_06_ADD

  #ifdef THERMIS_100K_ADD
  Serial.print("THERMIS_100K_Units:");
  Serial.print(THERMIS_1_Value);
  Serial.print("; ");
  #endif //THERMIS_100K_ADD
  
  #ifdef HIH6130_ADD
  Serial.print("HIH_6130_1_T_C:");
  Serial.print(HIH_6130_1_hih.temperature(), 2);
  Serial.print("; ");
  Serial.print("HIH_6130_1_H_%:");
  Serial.print(HIH_6130_1_hih.humidity(), 2);
  Serial.print("; ");
  #endif //HIH6130_ADD
  
  #ifdef SHT15_ADD
  Serial.print("SHT15_1_T_C:");
  Serial.print(SHT15_1_temperature,2);
  Serial.print("; ");
  Serial.print("SHT15_1_H_%:");
  Serial.print(SHT15_1_humidity,2);
  Serial.print("; ");
  #endif //SHT15_ADD
  
  #ifdef BMP180_ADD
  Serial.print("BMP_180_1_T_C:");
  Serial.print(BMP_180_1_temperature, 2);
  Serial.print("; ");
  Serial.print("BMP_180_1_P_PA:");
  Serial.print(BMP_180_1_pressure, 2);
  Serial.print("; ");
  #endif //BMP180_ADD
  
  #ifdef MMA8452_ADD
  Serial.print("MMA8452_1_A_X_Units:");
  Serial.print(xmean);
  Serial.print("; ");
  Serial.print("MMA8452_1_A_Y_Units:");
  Serial.print(ymean);
  Serial.print("; ");
  Serial.print("MMA8452_1_A_Z_Units:");
  Serial.print(zmean);
  Serial.print("; ");
  Serial.print("MMA8452_1_A_RMS_Units:");
  Serial.print(rt_mean_sq);
  Serial.print("; ");
  #endif //MMA8452_ADD

  wdt_reset();

  #ifdef DS18B20_ADD
  Serial.print("DS18B20_1_T_C:");
  Serial.print(DS18B20_1_temperature, 2);
  Serial.print("; ");
  #endif //DS18B20_ADD
      
  #ifdef TMP421_ADD
  Serial.print("TMP421_1_T_C:");
  Serial.print(TMP421_1_temperature, 2);
  Serial.print("; ");
  #endif //TMP421_ADD
      
  #ifdef RHT03_ADD
  if (chk_RHT03_1 == DHTLIB_OK)
  { 
    Serial.print("RHT03_1_T_C:");
    Serial.print(RHT03_1.temperature, 2);
    Serial.print("; ");
    Serial.print("RHT03_1_H_%:");
    Serial.print(RHT03_1.humidity, 2);
    Serial.print("; ");
  }
  #endif //RHT03_ADD
  
  #ifdef TMP102_ADD
  Serial.print("TMP102_1_T_F:");
  Serial.print(tmp102_1_temperature,2);
  Serial.print("; ");
  #endif //TMP102_ADD

  #ifdef SHT75_ADD
  Serial.print("SHT75_1_T_C:");
  Serial.print(SHT75_1_temperature,2);
  Serial.print("; ");
  Serial.print("SHT75_1_H_%:");
  Serial.print(SHT75_1_humidity,2);
  Serial.print("; ");
  #endif //SHT75_ADD
  
  #ifdef HIH4030_ADD
  Serial.print("HIH4030_Units:");
  Serial.print(HIH4030_1_Value);
  Serial.print("; ");
  #endif //HIH4030_ADD
  
  #ifdef GA1A1S201WP_ADD
  Serial.print("AMBI_1_Units:");
  Serial.print(AMBI_1_Value);
  Serial.print("; ");
  #endif //GA1A1S201WP_ADD
  
  #ifdef MAX4466_ADD
  Serial.print("MAX4466_1_Units:");
  Serial.print(p_mean);
  Serial.print("; ");
  #endif //MAX4466_ADD
  
  Serial.print('\n');
  // counter++;
  delay(170);
  wdt_reset();
}

void sensors()
{
  oldSREG = SREG;
  interrupts();
  // counter_time++;
  // Serial.print(counter_time); Serial.print(" ");
  // Serial.println(counter);

  #ifdef IR_D6T_44L_06_ADD
  D6T_get_data();
  #endif //IR_D6T_44L_06_ADD

  #ifdef SHT15_ADD
  SHT15_1_error = SHT15_1_tempSensor.measTemp(&SHT15_1_rawData);
  SHT15_1_temperature = SHT15_1_tempSensor.calcTemp(SHT15_1_rawData);
  SHT15_1_error = SHT15_1_tempSensor.measHumi(&SHT15_1_rawData);
  SHT15_1_humidity = SHT15_1_tempSensor.calcHumi(SHT15_1_rawData, SHT15_1_temperature);
  #endif //SHT15_ADD
  
  #ifdef SHT75_ADD
  SHT75_1_error = SHT75_1_tempSensor.measTemp(&SHT75_1_rawData);
  SHT75_1_temperature = SHT75_1_tempSensor.calcTemp(SHT75_1_rawData);
  SHT75_1_error = SHT75_1_tempSensor.measHumi(&SHT75_1_rawData);
  SHT75_1_humidity = SHT75_1_tempSensor.calcHumi(SHT75_1_rawData, SHT75_1_temperature);
  #endif //SHT75_ADD
  
  #ifdef GA1A1S201WP_ADD
  AMBI_1_Value = analogRead(AMBI_1_Pin); 
  #endif //GA1A1S201WP_ADD
  
  #ifdef PhoRes_ADD
  PhoRes_1_Value = analogRead(PhoRes_PIN); 
  #endif //PhoRes_ADD
  
  #ifdef HIH4030_ADD
  HIH4030_1_Value = analogRead(HIH4030_PIN); 
  #endif //HIH4030_ADD
  
  #ifdef THERMIS_100K_ADD
  THERMIS_1_Value = analogRead(THERMIS_100K_Pin); 
  #endif //THERMIS_100K_ADD
  
  #ifdef DS18B20_ADD
  DS18B20_1_temperature = DS18B20_1_getTemp();
  #endif //DS18B20_ADD
      
  #ifdef TMP421_ADD
  oldSREG = SREG;
  interrupts();
  TMP421_1_temperature = TMP421_1.GetTemperature(); // Some error, check this out! 
  SREG = oldSREG;
  #endif //TMP421_ADD
      
  #ifdef RHT03_ADD
  chk_RHT03_1 = RHT03_1.read22(RHT03_1_PIN);
  #endif //RHT03_ADD
  
  #ifdef BMP180_ADD
  oldSREG = SREG;
  interrupts();
  BMP_180_1.getPressure(&BMP_180_1_pressure);  
  BMP_180_1.getTemperature(&BMP_180_1_temperature);
  SREG = oldSREG;
  #endif //BMP180_ADD
  
  #ifdef TMP102_ADD
  oldSREG = SREG;
  interrupts();
  Wire.requestFrom(tmp102_1_Address,2);
  tmp102_1_MSB = Wire.read();
  tmp102_1_LSB = Wire.read();
  tmp102_1_temperature = (((tmp102_1_MSB << 8) | tmp102_1_LSB) >> 4) * 0.11250 + 32; //it's a 12bit int, using two's compliment for negative
  SREG = oldSREG;
  #endif //TMP102_ADD

  #ifdef HIH6130_ADD
  oldSREG = SREG;
  interrupts();
  HIH_6130_1_hih.start();
  HIH_6130_1_hih.update();
  SREG = oldSREG;
  #endif //HIH6130_ADD
  
  #ifdef MLX90614_ADD
  i2c_start_wait(dev+I2C_WRITE);
  i2c_write(0x07);
  
  // read
  i2c_rep_start(dev+I2C_READ);
  data_low = i2c_readAck(); //Read 1 byte and then send ack
  data_high = i2c_readAck(); //Read 1 byte and then send ack
  pec = i2c_readNak();
  i2c_stop();
  
  //This converts high and low bytes together and processes temperature, MSB is a error bit and is ignored for temps
  tempData = 0x0000; // zero out the data
  
  // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
  tempData = (double)(((data_high & 0x007F) << 8) + data_low);
  tempData = (tempData * tempFactor)-0.01;
  
  celcius = tempData - 273.15;
  fahrenheit = (celcius*1.8) + 32;
  #endif //MLX90614_ADD

  #ifdef WindVel_ADD

  #endif
  
  timer1_runs += 1;
  SREG = oldSREG;
}