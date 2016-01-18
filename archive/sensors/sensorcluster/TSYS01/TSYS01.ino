//This example code illustratesr the basic functions necessary to communicate with a TSYS01 via I2C
//Tony White 6/5/2015

#include <Wire.h> //I2C
extern TwoWire Wire1;

#define TSYS01Address 0x76  //address left shifted by arduino as required to match datasheet
#define TSYS01Reset 0x1E //initiates reset
#define TSYS01StartReg 0x48 //commands sensor to begin measurement / output calculation
#define TSYS01TempReg 0x00 //requests most recent output from measurement
typedef enum KPoly_E //structure to hold calibration values from temperature sensor registers
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
byte MSB;//hol
byte OSB;
byte LSB;



void setup() {
    delay(5000);
    SerialUSB.begin(115200);
    Wire1.begin();
    TSYS01INIT();
    getCoefs();

}

void loop()
{
    TSYS01GetTemp();
    SerialUSB.print("Temperature: ");
    SerialUSB.print(Temp);
    SerialUSB.println('C');

    delay(500);
}

void TSYS01INIT()
{
    Wire1.beginTransmission(TSYS01Address);
    Wire1.write(0x1E);
    Wire1.endTransmission();
    delay(50);
}


void getCoefs(void)  //gathers calibration coefficients to array
{
    for (uint8_t n =0; n<5;n++)
    {
        Wire1.beginTransmission(TSYS01Address);
        Wire1.write(0xA2+(n*2));
        Wire1.endTransmission();
        Wire1.requestFrom(TSYS01Address,2);
        uint8_t Ai = Wire1.read();
        uint8_t Bi = Wire1.read();
        uint16_t x = (uint16_t)Ai << 8;
        x+=Bi;
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
    Wire1.beginTransmission(TSYS01Address);
    Wire1.write(TSYS01StartReg); //Start measurement process
    Wire1.endTransmission();
    delay(10);

    Wire1.beginTransmission(TSYS01Address);
    Wire1.write(TSYS01TempReg); //Request measurement
    Wire1.endTransmission();

    Wire1.requestFrom(TSYS01Address,3); //read in 24 bit output
    MSB = Wire1.read();
    OSB = Wire1.read();
    LSB = Wire1.read(); //not used but necessary if 24bit conversion method is found (shifts below return 24bit output / 256 per TSYS01 datasheet conversion equations

    Temp = scaleTemp_C((((unsigned long)MSB << 8) | ((unsigned long)OSB))); //convert and cast to Temp with scaling equation
}

