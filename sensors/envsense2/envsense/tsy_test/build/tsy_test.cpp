#line 1 "tsy_test.ino"
                                                                                                   
                      

#include <Wire.h>      

                   
#define TSYS01Address 0x77                                                                  
#define TSYS01Reset 0x1E                  
#define TSYS01StartReg 0x48                                                            
#define TSYS01TempReg 0x00                                               
#include "Arduino.h"
void setup();
void loop();
void TSYS01INIT();
void getCoefs(void);
float scaleTemp_C(uint16_t rawAdc);
void TSYS01GetTemp();
#line 11
typedef enum KPoly_E                                                                         
{
  K4 = 0,
  K3,
  K2,
  K1,
  K0
}
KPoly_T;
long tempReading = 0;
float finalTempC = 0.0000;
uint16_t coefficent[5];
float Temp;
byte MSB;     
byte OSB;
byte LSB;



void setup() {
  Serial.begin(9600);
  Wire.begin();
  TSYS01INIT();
  getCoefs();

}

void loop() 
{
  TSYS01GetTemp();

           
  Serial.print("Temperature: ");
  Serial.print(Temp);
  Serial.print((char)176);                  
  Serial.println('C');

  delay(500);
}

void TSYS01INIT() 
{
  Wire.beginTransmission(TSYS01Address);
  Wire.write(0x1E);
  Wire.endTransmission();
  delay(50);
}


void getCoefs(void)                                             
{  
  for (uint8_t n =0; n<5;n++)
  {
    Wire.beginTransmission(TSYS01Address);
    Wire.write(0xA2+(n*2));
    Wire.endTransmission();
    Wire.requestFrom(TSYS01Address,2);
    uint8_t Ai = Wire.read();
    Serial.println(Ai);
    uint8_t Bi = Wire.read();
    Serial.println(Bi);
    uint16_t x = (uint16_t)Ai << 8;
    Serial.println(x);
    x+=Bi;
    Serial.println(x);
    coefficent[n] =x;   
  }
}


float scaleTemp_C(uint16_t rawAdc)
{

  float retVal = 
    (-2)* (float)coefficent[K4] * (float)pow(10,-21) * pow(rawAdc,4) + 
    4 * (float)coefficent[K3] * (float)pow(10,-16) * pow(rawAdc,3) +
    (-2) * (float)coefficent[K2] * (float)pow(10,-11) * pow(rawAdc,2) +
    1 * (float)coefficent[K1] * (float)pow(10,-6) * rawAdc +
    (-1.5) * (float)coefficent[K0] * (float)pow(10,-2);

  return retVal; 

}

void TSYS01GetTemp()
{
  Wire.beginTransmission(TSYS01Address);
  Wire.write(TSYS01StartReg);                            
  Wire.endTransmission();
  delay(10);

  Wire.beginTransmission(TSYS01Address);
  Wire.write(TSYS01TempReg);                      
  Wire.endTransmission();

  Wire.requestFrom(TSYS01Address,3);                        
  MSB = Wire.read();
  OSB = Wire.read();
  LSB = Wire.read();                                                                                                                                               

  Temp = scaleTemp_C((((unsigned long)MSB << 8) | ((unsigned long)OSB)));                                                 
}


