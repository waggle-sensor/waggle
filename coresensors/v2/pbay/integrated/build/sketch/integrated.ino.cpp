#include <Arduino.h>
#line 1
#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/integrated.ino"
// #include "/home/rajesh/.arduino15/packages/arduino/hardware/sam/1.6.4/libraries/Wire/Wire.h"

#include <Wire.h>
#include "./libs/DueTimer/DueTimer.h"   // SH adds
// extern TwoWire Wire1;
TwoWire *wirex=&Wire1;
#include "config.cpp"

#ifdef LIGHTSENSE_INCLUDE
    #include "./libs/MCP342X_Waggle/MCP342X_Waggle.h"
    MCP342X mcp3428_1;
    MCP342X mcp3428_2;
#endif


#ifdef HTU21D_include
    #include "./libs/HTU21D/HTU21D.h"
    HTU21D myHumidity;
#endif

#ifdef  BMP180_include
    #include "./libs/Adafruit_Sensor-master/Adafruit_Sensor.h"
    #include "./libs/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h"
    Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
    sensors_event_t event;
#endif

#ifdef  PR103J2_include
    #define A2D_PRJ103J2 0
#endif

#ifdef SPV1840LR5HB_1_include
    #define SPV_1_SPL 6
    #define SPV_1_AMP 5
#endif

#ifdef TSL250RD_1_include
    #define A2D_TSL250RD_1 1
#endif

#ifdef MMA8452Q_include
    #define MMA8452_ADDRESS 0x1C
    #define OUT_X_MSB 0x01
    #define XYZ_DATA_CFG  0x0E
    #define WHO_AM_I   0x0D
    #define CTRL_REG1  0x2A
    #define GSCALE 2 // Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.
#endif


#ifdef TSYS01_include
    #define TSYS01Address 0x76  //address left shifted by arduino as required to match datasheet
    #define TSYS01Reset 0x1E //initiates reset
    #define TSYS01StartReg 0x48 //commands sensor to begin measurement / output calculation
    #define TSYS01TempReg 0x00 //requests most recent output from measurement
    typedef enum TSYS_KPoly_E //structure to hold calibration values from temperature sensor registers
    {
        TSYS_K4 = 0,
        TSYS_K3,
        TSYS_K2,
        TSYS_K1,
        TSYS_K0
    }
    TSYS_KPoly_T;
    uint16_t TSYS_coefficents[5];
#endif

#ifdef HMC5883L_include
    #include "./libs/HMC5883L_waggle/HMC5883L_waggle.h"
    HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(&Wire1);
#endif



#ifdef HIH6130_include
    #define HIH_ADDRESS 0x27
#endif

#ifdef TMP421_include
    #include "./libs/LibTempTMP421/LibTempTMP421.h"
    LibTempTMP421 TMP421_Sensor = LibTempTMP421();
#endif

byte formatted_data_buffer[MAX_FMT_SIZE];

// Airsense board
byte MAC_ID[LENGTH_FORMAT3 + 2] = {ID_MAC, 134,3,1,8,1,0,6}; // MAC address
byte TMP112[LENGTH_FORMAT6 + 2]; // ambient temp
byte HTU21D[(LENGTH_FORMAT6 * 2) + 2]; // ambient RH & temp

// byte GP2Y1010AU0F[LENGTH_FORMAT2 + 2]; // dust density

byte BMP180[LENGTH_FORMAT5 + LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte PR103J2[LENGTH_FORMAT1 + 2]; // light
byte TSL250RD_1[LENGTH_FORMAT1 + 2]; // ambient light (400-950nm)

byte MMA8452Q[(LENGTH_FORMAT6 * 4) + 2]; // 3-axis accel for traffic flow
byte SPV1840LR5HB_1[LENGTH_FORMAT1 + 2]; // sound pressure
byte TSYS01[LENGTH_FORMAT6 + 2]; // ambient temp

// Lightsense board
byte HMC5883L[(LENGTH_FORMAT8 * 3) + 2]; // magnetic field strength for traffic flow
byte HIH6130[(LENGTH_FORMAT6 * 2) + 2]; // temp and RH inside transparent box

byte APDS9006020[LENGTH_FORMAT1 + 2]; // ambient light inside cavity
byte TSL260RD[LENGTH_FORMAT1 + 2]; // solar near IR
byte TSL250RD_2[LENGTH_FORMAT1 + 2]; // solar visible light

byte MLX75305[LENGTH_FORMAT1 + 2]; // solar visible light
byte ML8511[LENGTH_FORMAT1 + 2]; // solar UV

byte D6T[(LENGTH_FORMAT6 * 17) + 2]; // temp of surrounding objects
byte MLX90614[LENGTH_FORMAT1 + 2]; // temp of pavement

byte TMP421[LENGTH_FORMAT6 + 2]; // temp inside transparent box
byte SPV1840LR5HB_2[LENGTH_FORMAT1 + 2]; // sound pressure

// chemsense board
byte chemsense_MAC_ID[LENGTH_FORMAT3 + 2]; // MAC address of chemsense board

byte SHT25[LENGTH_FORMAT2 + LENGTH_FORMAT1 + 2]; // ambient temp and RH
byte LPS25H[LENGTH_FORMAT2 + LENGTH_FORMAT4 + 2]; // atmospheric temperature and pressure
byte Si1145[(LENGTH_FORMAT1 * 3) + 2]; // UV

byte total_reducing_gases[LENGTH_FORMAT5 + 2]; // ambient concentration
byte total_oxidizing_gases[LENGTH_FORMAT5 + 2]; // ambient concentration
byte sulfur_dioxide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte hydrogen_sulphide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte ozone[LENGTH_FORMAT5 + 2]; // ambient concentration
byte nitrogen_dioxide[LENGTH_FORMAT5 + 2]; // ambient concentration
byte carbon_monoxide[LENGTH_FORMAT5 + 2]; // ambient concentration

byte CO_ADC_temp[LENGTH_FORMAT2 + 2];
byte IAQ_IRR_ADC_temp[LENGTH_FORMAT2 + 2];
byte O3_NO2_ADC_temp[LENGTH_FORMAT2 + 2];
byte SO2_H2S_ADC_temp[LENGTH_FORMAT2 + 2];
byte CO_LMP_temp[LENGTH_FORMAT2 + 2];

byte three_accel_and_vib[(LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4 + 2];
byte three_gyro_and_orientation[(LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4 + 2];

// Whole packet
byte packet_whole[LENGTH_WHOLE];
byte sensor_health[SENSOR_HEALTH_SIZE + 2];
// Data sub-packet
// byte packet_data[LENGTH_DATA];
// Sub-packets for each format


// These lengths are calculated at packet assembly
// byte length_whole_actual;
// byte length_data_actual;


// unsigned char buffer [BUFFER_SIZE_CHEMSENSE];
// unsigned char parameter[PARAM_SIZE_CHEMSENSE];
// unsigned char cnt = 0;
// boolean chemsense_ready = false;
// long param_value;
// unsigned char attenuate = 0;
// byte valid;

byte packet_seq_number = 0x00;

float Temp_float[3];
byte Temp_byte[8];
uint16_t Temp_uint16;
long Temp_long;
int Temp_int[3];
unsigned long Temp_ulong[2];

// char inByte;
// char ChemSensed = 0;
// char Chemsense_locked = 0;
// unsigned long LOOPING;

bool TIMER = false;

// CRC-8
byte crc = 0x00;
byte I2C_READ_COMPLETE = true;
/**************************************************************************************/

#ifdef I2C_INTERFACE
/** I2C request interrupt *************************************************************/
#line 186 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/integrated.ino"
void requestEvent();
#line 204 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/integrated.ino"
void setup();
#line 250 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/integrated.ino"
void handler();
#line 255 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/integrated.ino"
void loop();
#line 2 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/CRC_8_Waggle.ino"
byte CRC_calc(byte length_data);
#line 15 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/CRC_8_Waggle.ino"
byte CRC_8_Waggle(byte data, byte crc);
#line 2 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/HIH.ino"
void HIH_fetch_humidity_temperature();
#line 7 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TMP112.ino"
void TMP112_CONFIG();
#line 26 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TMP112.ino"
void TMP112_read();
#line 3 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TSYS01.ino"
void TSYS01_CONFIG();
#line 9 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TSYS01.ino"
void TSYS01_read();
#line 14 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TSYS01.ino"
void TSYS01INIT();
#line 23 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TSYS01.ino"
void TSYS_Get_Coeff(void);
#line 40 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TSYS01.ino"
float TSYS_ScaleTemp_C(uint16_t rawAdc);
#line 54 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TSYS01.ino"
void TSYS01GetTemp();
#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/airsense.ino"
void airsense_acquire(void);
#line 14 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
void format1(unsigned int input);
#line 26 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
void format2(int input);
#line 48 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
void format3(byte *input);
#line 62 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
void format4(unsigned long input);
#line 75 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
void format5(long input);
#line 101 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
void format6(float input);
#line 129 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
void format7(byte *input);
#line 141 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
void format8(float input);
#line 3 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/initialization.ino"
void sensor_buff_initialization();
#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/lightsense.ino"
void lightsense_acquire(void);
#line 3 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
void MMA8452_read();
#line 14 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
void readAccelData(int *destination);
#line 39 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
void MMA8452_CONFIG();
#line 52 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
void MMA8452Standby();
#line 59 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
void MMA8452Active();
#line 66 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
void MMA8452readRegisters(byte addressToRead, int bytesToRead, byte * dest);
#line 75 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
byte MMA8452readRegister(byte addressToRead);
#line 83 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
void MMA8452writeRegister(byte addressToWrite, byte dataToWrite);
#line 22 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
void form3_hex_string_to_hex();
#line 49 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
void form1_hex_string_to_unsigned_int();
#line 64 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
void form1_int_string_to_unsigned_int();
#line 78 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
void form4_int_string_to_unsigned_long(int shift_needed);
#line 95 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
void form2_int_string_to_int();
#line 111 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
void form5_int_string_to_long();
#line 127 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
int compareKey(char k1, char k2, char k3);
#line 135 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
void new_chemsense_acquire();
#line 186 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
void Carrier();
#line 4 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/packet_assembler.ino"
void assemble_packet_empty();
#line 16 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/packet_assembler.ino"
void assemble_packet_whole();
#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/sensors_setup.ino"
void Sensors_Setup(void);
#line 186
void requestEvent()
{
    #ifdef I2C_INTERFACE_CONST_SIZE
    Wire.write(packet_whole, I2C_PACKET_SIZE);
    #else
    char bytes_to_send;
    bytes_to_send = packet_whole[0x02] + 0x05;
    Wire.write(packet_whole, bytes_to_send );
    #endif

    I2C_READ_COMPLETE = true;
    assemble_packet_empty();
    TIMER = false;
}
/**************************************************************************************/
#endif

/** Arduino: setup ********************************************************************/
void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(1000);
    Wire1.begin();
    delay(1000);
    
    #ifdef I2C_INTERFACE
    I2C_READ_COMPLETE = false;
    Wire.begin(I2C_SLAVE_ADDRESS);
    Wire.onRequest(requestEvent);
    #endif

    #ifdef USBSERIAL_INTERFACE
    SerialUSB.begin(115200);
    #endif

    #ifdef SERIAL_DEBUG
    SerialUSB.println("Starting...");
    #endif

    // #ifdef CHEMSENSE_INCLUDE
    // digitalWrite(PIN_CHEMSENSE_POW, LOW); // Power on the Chemsense board
    // #endif

    Serial3.begin(19200);
    //     Setup the I2C buffer
    for (byte i=0x00; i<LENGTH_WHOLE; i++)
    {
        packet_whole[i] = 0x00;
    }

    assemble_packet_empty();
    Sensors_Setup();
    sensor_buff_initialization();
    delay(1000);
    
    #ifdef USBSERIAL_INTERFACE
    Timer3.attachInterrupt(handler).setPeriod(1000000 * 15).start(); // print super-packet every 30 secs
    #endif
    
   

}
/**************************************************************************************/

void handler()
{
    TIMER = true;
}

void loop()
{

    #ifdef USBSERIAL_INTERFACE
    
    //Serial3.println("hello!!!");
    #ifdef CHEMSENSE_INCLUDE
    new_chemsense_acquire();
    #endif

    if (TIMER)
    {
        #ifdef AIRSENSE_INCLUDE
        airsense_acquire();
        #endif

        #ifdef LIGHTSENSE_INCLUDE
        lightsense_acquire();
        #endif

        assemble_packet_empty();
        assemble_packet_whole();

        for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i ++)
        {
            SerialUSB.write(packet_whole[i]);
        }

        TIMER = false;
    }
    
    #endif

    #ifdef I2C_INTERFACE
    
    
    
    if (I2C_READ_COMPLETE == true)
    {
        #ifdef AIRSENSE_INCLUDE
        airsense_acquire();
        #endif

        #ifdef LIGHTSENSE_INCLUDE
        lightsense_acquire();
        #endif
        
        Timer3.attachInterrupt(handler).setPeriod(4000000 * 6).start(); // print super-packet every 30 secs

        // this is a hack... 
        
        while (TIMER == false)
        {
       
        #ifdef CHEMSENSE_INCLUDE
        new_chemsense_acquire();
        #endif
        delay(1);

        }
        Timer3.attachInterrupt(handler).stop(); 
        assemble_packet_whole();
        I2C_READ_COMPLETE = false;
    }
    
    
    #endif

}


#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/CRC_8_Waggle.ino"
/** Calculate CRC8 ********************************************************************/
byte CRC_calc(byte length_data)
{
    byte crc = 0x00;

    for (int i = 0x03; i < (length_data + 0x03); i++) // 0x03 accounts for header
        crc = CRC_8_Waggle(packet_whole[i], crc);

    return crc;
}
/**************************************************************************************/


/** Calculate CRC, byte by byte *******************************************************/
byte CRC_8_Waggle(byte data, byte crc)
{
    byte i;

    crc ^= data;

    for (i=0x00; i < 0x08; i++)
    {
        if (crc & 0x01)
            crc = (crc >> 0x01) ^ 0x8C;
        else
            crc =  crc >> 0x01;
    }

    return(crc);
}
/**************************************************************************************/


#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/HIH.ino"
 #ifdef HIH6130_include
 void HIH_fetch_humidity_temperature()
 {
     Wire1.beginTransmission(HIH_ADDRESS);
     Wire1.endTransmission();
     delay(100);

     Wire1.requestFrom((int)HIH_ADDRESS, (int) 4);

     Temp_byte[1] = Wire1.read();
     Temp_byte[2] = Wire1.read();
     Temp_byte[3] = Wire1.read();
     Temp_byte[4] = Wire1.read();

     Wire1.endTransmission();

     Temp_byte[0] = (Temp_byte[1] >> 6) & 0x03;

     Temp_byte[1] = Temp_byte[1] & 0x3f;
     Temp_int[0] = (((unsigned int)Temp_byte[1]) << 8) | Temp_byte[2];

     Temp_int[1] = (((unsigned int)Temp_byte[3]) << 8) | Temp_byte[4];
     Temp_int[1] = Temp_int[1] / 4;

     Temp_float[1] = (float) Temp_int[0] * 6.10e-3;
     Temp_float[0] = (float) Temp_int[1] * 1.007e-2 - 40.0;
 }
 #endif
#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TMP112.ino"
#ifdef TMP112_include

#define I2C_TMP112 0x48
#define TMP112_CONFIG_REG 0x01
#define TMP112_TEMP_REG 0x00

void TMP112_CONFIG()
{
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.write(TMP112_CONFIG_REG); // sends register address to read from
    Wire1.write(0x60);  // write data
    Wire1.write(0xB0);  // write data
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.write(TMP112_CONFIG_REG); // sends register address to read from
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.requestFrom(I2C_TMP112, 2);// send data n-bytes read
    Temp_byte[0] = Wire1.read(); // receive DATA
    Temp_byte[1] = Wire1.read();// receive DATA
    Wire1.endTransmission(); // end transmission
}

void TMP112_read()
{
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.write(TMP112_TEMP_REG); // sends register address to read from
    Wire1.endTransmission(); // end transmission
    delay(100);
    Wire1.beginTransmission(I2C_TMP112); // start transmission to device
    Wire1.requestFrom(I2C_TMP112, 2);// send data n-bytes read
    Temp_byte[0] = Wire1.read(); // receive DATA
    Temp_byte[1] = Wire1.read();// receive DATA
    Wire1.endTransmission(); // end transmission

    if ((Temp_byte[0] & 0x80) == 0x00)
    {
        // it is a positive temperature
        Temp_uint16 = Temp_byte[0];
        Temp_uint16 = Temp_uint16 << 5;
        Temp_uint16 = Temp_uint16 | (Temp_byte[1] >> 3);
        Temp_float[0] = (Temp_uint16 & 0x0FFF)*0.0625;
    }
    else
    {
        Temp_byte[0] = ~Temp_byte[0];
        Temp_byte[1] = ~Temp_byte[1];
        Temp_uint16 = Temp_byte[0];
        Temp_uint16 = Temp_uint16 << 5;
        Temp_uint16 = Temp_uint16 | (Temp_byte[1] >> 3);
        Temp_float[0] = (Temp_uint16 & 0x0FFF)*-0.0625;
    }
}

#endif

#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/TSYS01.ino"
#ifdef TSYS01_include

void TSYS01_CONFIG()
{
    TSYS01INIT();
    TSYS_Get_Coeff();
}

void TSYS01_read()
{
    TSYS01GetTemp();
}

void TSYS01INIT()
{
    Wire1.beginTransmission(TSYS01Address);
    Wire1.write(0x1E);
    Wire1.endTransmission();
    delay(50);
}


void TSYS_Get_Coeff(void)  //gathers calibration coefficients to array
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
        TSYS_coefficents[n] =x;
    }
}


float TSYS_ScaleTemp_C(uint16_t rawAdc)
{

    float retVal =
    (-2)* (float)TSYS_coefficents[TSYS_K4] * (float)pow(10,-21) * pow(rawAdc,4) +
    4 * (float)TSYS_coefficents[TSYS_K3] * (float)pow(10,-16) * pow(rawAdc,3) +
    (-2) * (float)TSYS_coefficents[TSYS_K2] * (float)pow(10,-11) * pow(rawAdc,2) +
    1 * (float)TSYS_coefficents[TSYS_K1] * (float)pow(10,-6) * rawAdc +
    (-1.5) * (float)TSYS_coefficents[TSYS_K0] * (float)pow(10,-2);

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
    Temp_byte[0] = Wire1.read();
    Temp_byte[1] = Wire1.read();
    Temp_byte[2] = Wire1.read(); //not used but necessary if 24bit conversion method is found (shifts below return 24bit output / 256 per TSYS01 datasheet conversion equations

    Temp_float[0] = TSYS_ScaleTemp_C((((unsigned long)Temp_byte[0] << 8) | ((unsigned long)Temp_byte[1]))); //convert and cast to Temp with scaling equation
}

#endif

#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/airsense.ino"
void airsense_acquire (void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.print("\n");
    SerialUSB.println("Acquiring AirSense Data.");
    #endif

    #ifdef TMP112_include
    TMP112_read();

    TMP112[1] = (1 << 7) | LENGTH_FORMAT6;

    format6(Temp_float[0]);  // Put it into format 1
    TMP112[2] = formatted_data_buffer[0];
    TMP112[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TMP112:");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif

    #ifdef HTU21D_include
    Temp_float[1] = myHumidity.readHumidity();
    Temp_float[0] = myHumidity.readTemperature();

    HTU21D[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);

    format6(Temp_float[0]);  // Put it into format 1
    HTU21D[2] = formatted_data_buffer[0];
    HTU21D[3] = formatted_data_buffer[1];

    format6(Temp_float[1]);  // Put it into format 1
    HTU21D[4] = formatted_data_buffer[0];
    HTU21D[5] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("HTU21D Temperature:");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print("C");
    SerialUSB.print(" Humidity:");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print("%");
    SerialUSB.println();
    #endif
    #endif

    #ifdef BMP180_include

    bmp.getEvent(&event);
    /* Display the results (barometric pressure is measure in Pascals) */
    if (event.pressure)
    {
        BMP180[1] = (1 << 7) | (LENGTH_FORMAT6 + LENGTH_FORMAT5);
        Temp_long = long(event.pressure);
        bmp.getTemperature(&Temp_float[0]);
        format6(Temp_float[0]);
        BMP180[2] = formatted_data_buffer[0];
        BMP180[3] = formatted_data_buffer[1];
        format5(Temp_long);
        BMP180[4] = formatted_data_buffer[0];
        BMP180[5] = formatted_data_buffer[1];
        BMP180[6] = formatted_data_buffer[2];
    }
    else
    {
        BMP180[1] = (0 << 7) | (LENGTH_FORMAT6 + LENGTH_FORMAT5);
    }

    #ifdef SERIAL_DEBUG
    SerialUSB.print("BMP180 temp: ");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print("C pressure: ");
    SerialUSB.print(Temp_long);
    SerialUSB.println("hPa");
    #endif
    #endif

    #ifdef PR103J2_include

    PR103J2[1] = (1 << 7) | LENGTH_FORMAT1;
    Temp_uint16 = analogRead(A2D_PRJ103J2);
    format1(Temp_uint16);
    PR103J2[2] = formatted_data_buffer[0];
    PR103J2[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("PR103J2: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif


    #ifdef TSL250RD_1_include

    TSL250RD_1[1] = (1 << 7) | LENGTH_FORMAT1;

    Temp_uint16 = analogRead(A2D_TSL250RD_1);
    format1(Temp_uint16);
    TSL250RD_1[2] = formatted_data_buffer[0];
    TSL250RD_1[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL250RD: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif


    #ifdef MMA8452Q_include
    MMA8452_read();

    MMA8452Q[1] = (1 << 7) | (LENGTH_FORMAT6 * 4);

    format6(Temp_float[0]);  // Put it into format 1
    MMA8452Q[2] = formatted_data_buffer[0];
    MMA8452Q[3] = formatted_data_buffer[1];

    format6(Temp_float[1]);  // Put it into format 1
    MMA8452Q[4] = formatted_data_buffer[0];
    MMA8452Q[5] = formatted_data_buffer[1];


    format6(Temp_float[2]);  // Put it into format 1
    MMA8452Q[6] = formatted_data_buffer[0];
    MMA8452Q[7] = formatted_data_buffer[1];


    format6(0);  // Put it into format 1
    MMA8452Q[8] = formatted_data_buffer[0];
    MMA8452Q[9] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("MMA8452Q x: ");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print(" y: ");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print(" z: ");
    SerialUSB.print(Temp_float[2]);
    SerialUSB.print(" rms: ");
    SerialUSB.println(0);
    #endif
    #endif


    #ifdef SPV1840LR5HB_1_include
    long SPV_1_AMPV[100];
    double SPV_1_AMPV_AVG = 0;

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV[i] = 512 - analogRead(SPV_1_AMP);
        if (SPV_1_AMPV[i] < 0)
        {
            SPV_1_AMPV[i] = SPV_1_AMPV[i] * -1;
        }
        delay(1);
    }

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV_AVG = ((SPV_1_AMPV_AVG * i) + SPV_1_AMPV[i]) / (i+1);
    }

    SPV1840LR5HB_1[1] = (1 << 7) | LENGTH_FORMAT1;

    format1(int(SPV_1_AMPV_AVG * 10));

    SPV1840LR5HB_1[2] = formatted_data_buffer[0];
    SPV1840LR5HB_1[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("SPV1840LR5HB: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif


    #ifdef TSYS01_include
    TSYS01_read();

    TSYS01[1] = (1 << 7) | LENGTH_FORMAT6;
    format6(Temp_float[0]);  // Put it into format 2
    TSYS01[2] = formatted_data_buffer[0];
    TSYS01[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSYS01: ");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif
}


#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/dataFormats.ino"
// Packet formatters -
// F1 - unsigned int_16 input, {0-0xffff} - Byte1 Byte2 (16 bit number)
// F2 - int_16 input , +-{0-0x7fff} - 1S|7Bits Byte2
// F3 - byte input[6], {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
// F4 - unsigned long_24 input, {0-0xffffff} - Byte1 Byte2 Byte3
// F5 - long_24 input, +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
// F6 - float input, +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}
// F7 - byte input[4], {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
// F8 - float input, +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac


/** Format 1 assembler ****************************************************************/
// F1 - {0-0xffff} - Byte1 Byte2 (16 bit number)
void format1(unsigned int input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = (input & 0xff00) >> 8;
    formatted_data_buffer[1] = input & 0xff;
}
/**************************************************************************************/



/** Format 2 assembler ****************************************************************/
// F2 - +-{0-0x7fff} - 1S|7Bits Byte2
void format2(int input)
{

    byte _negative;
    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }
    // Get abs. value of input
    input = abs(input);
    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((input & 0x7f00) >> 8);
    formatted_data_buffer[1] = input & 0xff;
}
/**************************************************************************************/


/** Format 3 assembler ****************************************************************/
// F3 - {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
void format3(byte *input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = input[0];
    formatted_data_buffer[1] = input[1];
    formatted_data_buffer[2] = input[2];
    formatted_data_buffer[3] = input[3];
    formatted_data_buffer[4] = input[4];
    formatted_data_buffer[5] = input[5];
}
/**************************************************************************************/

/** Format 4 assembler ****************************************************************/
// F4 - {0-0xffffff} - Byte1 Byte2 Byte3
void format4(unsigned long input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = (input & 0xff0000) >> 16;
    formatted_data_buffer[1] = (input & 0xff00) >> 8;
    formatted_data_buffer[2] = (input & 0xff);
}
/**************************************************************************************/



/** Format 5 assembler ****************************************************************/
// F5 - +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
void format5(long input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((input & 0x7f0000) >> 16);
    formatted_data_buffer[1] = (input & 0xff00) >> 8;
    formatted_data_buffer[2] = (input & 0xff);
}
/**************************************************************************************/


/** Format 6 assembler ****************************************************************/
// F6 - +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}

void format6(float input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    // Extract integer component
    unsigned int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    unsigned int fractional = ((int)(input*100) - integer*100);

    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | integer;
    formatted_data_buffer[1] = (fractional & 0x7F);
}
/**************************************************************************************/

/** Format 7 assembler ****************************************************************/
// F7 - {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
void format7(byte *input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = input[0];
    formatted_data_buffer[1] = input[1];
    formatted_data_buffer[2] = input[2];
    formatted_data_buffer[3] = input[3];
}
/**************************************************************************************/

/** Format 8 assembler ****************************************************************/
// F8 - +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac
void format8(float input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    // Extract integer component
    int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    int fractional = int((input - integer) * 1000);

    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((integer & 0x1F) << 2) | ((fractional & 0x0300) >> 8);
    formatted_data_buffer[1] = (fractional & 0x00FF);;
}
/**************************************************************************************/

#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/initialization.ino"
int sensor_initial = 0;

void sensor_buff_initialization()
{
	MAC_ID[0] = ID_MAC;	MAC_ID[0] = ID_MAC;

	// airsense board
    TMP112[0] = ID_TMP112;
    HTU21D[0] = ID_HTU21D;

    BMP180[0] = ID_BMP180;
    PR103J2[0] = ID_PR103J2;
    TSL250RD_1[0] = ID_TSL250RD_1;

    MMA8452Q[0] = ID_MMA8452Q;
    SPV1840LR5HB_1[0] = ID_SPV1840LR5HB_1;
    TSYS01[0] = ID_TSYS01;



    // lightsense board
    HMC5883L[0] = ID_HMC5883L;
    HIH6130[0] = ID_HIH6130;

    APDS9006020[0] = ID_APDS9006020;
    TSL260RD[0] = ID_TSL260RD;
    TSL250RD_2[0] = ID_TSL250RD_2;

    MLX75305[0] = ID_MLX75305;
    ML8511[0] = ID_ML8511;

    D6T[0] = ID_D6T;
	MLX90614[0] = ID_MLX90614;

    TMP421[0] = ID_TMP421;
	SPV1840LR5HB_2[0] = ID_SPV1840LR5HB_2;



	//chemsense board
	chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;

	SHT25[0] = ID_SHT25;
	LPS25H[0] = ID_LPS25H;
	Si1145[0] = ID_Si1145;

	total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
	total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
	sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
	hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
	ozone[0] = ID_OZONE;
	nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
	carbon_monoxide[0] = ID_CARBON_MONOXIDE;

	CO_ADC_temp[0] = ID_CO_ADC_TEMP;
	IAQ_IRR_ADC_temp[0] = ID_IAQ_IRR_ADC_TEMP;
	O3_NO2_ADC_temp[0] = ID_O3_NO2_ADC_TEMP;
	SO2_H2S_ADC_temp[0] = ID_SO2_H2S_ADC_TEMP;
	CO_LMP_temp[0] = ID_CO_LMP_TEMP;

	three_accel_and_vib[0] = ID_THREE_ACCEL_AND_VIB;
	three_gyro_and_orientation[0] = ID_THREE_GYRO_AND_ORIENTATION;



    // airsense initialization
	MAC_ID[1] = (1 << 7) | LENGTH_FORMAT3;

	// airsense initialization
    TMP112[1] = (sensor_initial << 7) | LENGTH_FORMAT6;
    HTU21D[1] = (sensor_initial << 7) | LENGTH_FORMAT6;

    BMP180[1] = (sensor_initial << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
    PR103J2[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
    TSL250RD_1[1] = (sensor_initial << 7) | LENGTH_FORMAT1;

    MMA8452Q[1] = (sensor_initial << 7) | (LENGTH_FORMAT6 * 4);
    SPV1840LR5HB_1[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
    TSYS01[1] = (sensor_initial << 7) | LENGTH_FORMAT6;


    // lightsense initialization
    HMC5883L[1] = (sensor_initial << 7) | (LENGTH_FORMAT8 * 3);
    HIH6130[1] = (sensor_initial << 7) | (LENGTH_FORMAT6 * 2);

    APDS9006020[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
    TSL260RD[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
    TSL250RD_2[1] = (sensor_initial << 7) | LENGTH_FORMAT1;

    MLX75305[1] = (sensor_initial << 7) | LENGTH_FORMAT1;
    ML8511[1] = (sensor_initial << 7) | LENGTH_FORMAT1;

	D6T[1] = (sensor_initial << 7) | (LENGTH_FORMAT6 * 17);
	MLX90614[1] = (sensor_initial << 7 ) | LENGTH_FORMAT1;

    TMP421[1] = (sensor_initial << 7) | LENGTH_FORMAT6;
	SPV1840LR5HB_2[1] = (sensor_initial << 7) | LENGTH_FORMAT1;


	// chemsemse initialization
	chemsense_MAC_ID[1] = (sensor_initial << 7) | LENGTH_FORMAT3;

	SHT25[1] = (sensor_initial << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
	LPS25H[1] = (sensor_initial << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
	Si1145[1] = (sensor_initial << 7) | (LENGTH_FORMAT1 * 3);

	total_reducing_gases[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	total_oxidizing_gases[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	sulfur_dioxide[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	hydrogen_sulphide[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	ozone[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	nitrogen_dioxide[1] = (sensor_initial << 7) | LENGTH_FORMAT5;
	carbon_monoxide[1] = (sensor_initial << 7) | LENGTH_FORMAT5;

	CO_ADC_temp[1] = (sensor_initial << 7) | LENGTH_FORMAT2;
	IAQ_IRR_ADC_temp[1] = (sensor_initial << 7) | LENGTH_FORMAT2;
	O3_NO2_ADC_temp[1] = (sensor_initial << 7) | LENGTH_FORMAT2;
	SO2_H2S_ADC_temp[1] = (sensor_initial >> 7) | LENGTH_FORMAT2;
	CO_LMP_temp[1] = (sensor_initial << 7) | LENGTH_FORMAT2;

	three_accel_and_vib[1] = (sensor_initial << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);
	three_gyro_and_orientation[1] = (sensor_initial << 7) | ((LENGTH_FORMAT2 * 3) + LENGTH_FORMAT4);
}
#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/lightsense.ino"
void lightsense_acquire (void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.print("\n");
    SerialUSB.println("Acquiring LightSense Data");
    #endif

    #ifdef HMC5883L_include
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);

    HMC5883L[1] = (1 << 7) | (LENGTH_FORMAT8 * 3);
    format8(event.magnetic.x);
    HMC5883L[2] = formatted_data_buffer[0];
    HMC5883L[3] = formatted_data_buffer[1];
    format8(event.magnetic.y);
    HMC5883L[4] = formatted_data_buffer[0];
    HMC5883L[5] = formatted_data_buffer[1];
    format8(event.magnetic.z);
    HMC5883L[6] = formatted_data_buffer[0];
    HMC5883L[7] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("HMC5883L X:");
    SerialUSB.print(event.magnetic.x);
    SerialUSB.print("HMC5883L Y:");
    SerialUSB.print(event.magnetic.y);
    SerialUSB.print("HMC5883L Z:");
    SerialUSB.print(event.magnetic.z);
    #endif
    #endif

    #ifdef HIH6130_include
    HIH_fetch_humidity_temperature();

    HIH6130[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);
    format6(Temp_float[0]);
    HIH6130[2] = formatted_data_buffer[0];
    HIH6130[3] = formatted_data_buffer[1];
    format6(Temp_float[1]);
    HIH6130[4] = formatted_data_buffer[0];
    HIH6130[5] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("HIH6130 RH%:");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print("  Temperature:");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif



    #ifdef APDS9006020_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_2.readADC());

    APDS9006020[1] = (1 << 7) | LENGTH_FORMAT1;
    APDS9006020[2] = formatted_data_buffer[0];
    APDS9006020[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("APDS9006020: ");
    SerialUSB.println(mcp3428_2.readADC());
    #endif
    #endif

    #ifdef TSL260RD_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    TSL260RD[1] = (1 << 7) | LENGTH_FORMAT1;
    TSL260RD[2] = formatted_data_buffer[0];
    TSL260RD[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL260RD: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef TSL250RD_2_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    TSL250RD_2[1] = (1 << 7) | LENGTH_FORMAT1;
    TSL250RD_2[2] = formatted_data_buffer[0];
    TSL250RD_2[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TSL250RD_2: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef MLX75305_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    MLX75305[1] = (1 << 7) | LENGTH_FORMAT1;
    MLX75305[2] = formatted_data_buffer[0];
    MLX75305[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("MLX75305: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif

    #ifdef ML8511_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    ML8511[1] = (1 << 7) | LENGTH_FORMAT1;
    ML8511[2] = formatted_data_buffer[0];
    ML8511[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("ML8511: ");
    SerialUSB.println(mcp3428_1.readADC());
    #endif
    #endif


    #ifdef TMP421_include
    Temp_float[0] = TMP421_Sensor.GetTemperature();

    TMP421[1] = (1 << 7) | LENGTH_FORMAT6;
    format6(Temp_float[0]);
    TMP421[2] = formatted_data_buffer[0];
    TMP421[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("TMP421: ");
    SerialUSB.println(Temp_float[0]);
    #endif
    #endif

    #ifdef SPV1840LR5HB_2_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    format1(mcp3428_2.readADC());

    SPV1840LR5HB_2[1] = (1 << 7) | LENGTH_FORMAT1;
    SPV1840LR5HB_2[2] = formatted_data_buffer[0];
    SPV1840LR5HB_2[3] = formatted_data_buffer[1];
    
    #ifdef SERIAL_DEBUG
    SerialUSB.print("SPV1840LR5HB: ");
    SerialUSB.println(mcp3428_2.readADC());
    #endif
    #endif

}


#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/mma84521.ino"
#ifdef MMA8452Q_include

void MMA8452_read()
{
    readAccelData(Temp_int);

    for (int i = 0 ; i < 3 ; i++)
    {
        Temp_float[i] = (float) Temp_int[i] / ((1<<12)/(2*GSCALE));  // get actual g value, this depends on scale being set
    }

}

void readAccelData(int *destination)
{
    byte rawData[6];  // x/y/z accel register data stored here

    MMA8452readRegisters(OUT_X_MSB, 6, rawData);  // Read the six raw data registers into data array

    // Loop to calculate 12-bit ADC and g value for each axis
    for(int i = 0; i < 3 ; i++)
    {
        int gCount = (rawData[i*2] << 8) | rawData[(i*2)+1];  //Combine the two 8 bit registers into one 12-bit number
        gCount >>= 4; //The registers are left align, here we right align the 12-bit integer

        // If the number is negative, we have to make it so manually (no 12-bit data type)
        if (rawData[i*2] > 0x7F)
        {
            gCount -= 0x1000;
        }

        destination[i] = gCount; //Record this gCount into the 3 int array
    }
}

// Initialize the MMA8452 registers
// See the many application notes for more info on setting all of these registers:
// http://www.freescale.com/webapp/sps/site/prod_summary.jsp?code=MMA8452Q
void MMA8452_CONFIG()
{
    MMA8452Standby();  // Must be in standby to change registers
    // Set up the full scale range to 2, 4, or 8g.
    byte fsr = GSCALE;
    if(fsr > 8) fsr = 8; //Easy error check
    fsr >>= 2; // Neat trick, see page 22. 00 = 2G, 01 = 4A, 10 = 8G
    MMA8452writeRegister(XYZ_DATA_CFG, fsr);
    //The default data rate is 800Hz and we don't modify it in this example code
    MMA8452Active();  // Set to active to start reading
}

// Sets the MMA8452 to standby mode. It must be in standby to change most register settings
void MMA8452Standby()
{
    byte c = MMA8452readRegister(CTRL_REG1);
    MMA8452writeRegister(CTRL_REG1, c & ~(0x01)); //Clear the active bit to go into standby
}

// Sets the MMA8452 to active mode. Needs to be in this mode to output data
void MMA8452Active()
{
    byte c = MMA8452readRegister(CTRL_REG1);
    MMA8452writeRegister(CTRL_REG1, c | 0x01); //Set the active bit to begin detection
}

// Read bytesToRead sequentially, starting at addressToRead into the dest byte array
void MMA8452readRegisters(byte addressToRead, int bytesToRead, byte * dest)
{
    Wire1.requestFrom((uint8_t) MMA8452_ADDRESS, (uint8_t) bytesToRead, (uint32_t) addressToRead, (uint8_t) 1, (uint8_t) 1);
    while(Wire1.available() < bytesToRead); //Hang out until we get the # of bytes we expect
    for(int x = 0 ; x < bytesToRead ; x++)
        dest[x] = Wire1.read();
}

// Read a single byte from addressToRead and return it as a byte
byte MMA8452readRegister(byte addressToRead)
{
    Wire1.requestFrom((uint8_t) MMA8452_ADDRESS, (uint8_t) 1, (uint32_t) addressToRead, (uint8_t) 1, (uint8_t) 1);
    while(!Wire1.available()) ; //Wait for the data to come back
    return Wire1.read(); //Return this one byte
}

// Writes a single byte (dataToWrite) into addressToWrite
void MMA8452writeRegister(byte addressToWrite, byte dataToWrite)
{
    Wire1.beginTransmission(MMA8452_ADDRESS);
    Wire1.write(addressToWrite);
    Wire1.write(dataToWrite);
    Wire1.endTransmission(); //Stop transmitting
}

#endif

#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/new_chemsense.ino"
/* Chemsesne reader using the Serial "Serial3".
 * Suppose that the Chemsense is device /dev/ttyACM0 when you connect the board with light and airsense.
 */

int j = 0;
int valid = 1;

unsigned char INPUT_BYTE;
char KEY[4];
char VAL[13];

char first[6], second[6];
//char *i = VAL;

byte formatted_byte_temp[8];

int KEY_NUM_ID = 0;
int VAL_NUM_ID = 0;

bool flag_KEY = false;

void form3_hex_string_to_hex()                     // Hex to hex: form3
{
    Temp_ulong[0] = 0x000000;
    Temp_ulong[1] = 0x000000;

    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] > '9')                   // letters
            VAL[i] = VAL[i] - 'a' + 0x0a;
        else                                // numbers
            VAL[i] = VAL[i] - '0';

        if (i < VAL_NUM_ID / 2)
            Temp_ulong[0] = Temp_ulong[0] | (VAL[i] << (VAL_NUM_ID / 2 - i - 1) * 4);
        else
            Temp_ulong[1] = Temp_ulong[1] | (VAL[i] << (VAL_NUM_ID - i - 1) * 4);
    }

    Temp_byte[0] = (Temp_ulong[0] & 0xFF0000) >> 16;
    Temp_byte[1] = (Temp_ulong[0] & 0x00FF00) >> 8;
    Temp_byte[2] = (Temp_ulong[0] & 0x0000FF);
    Temp_byte[3] = (Temp_ulong[1] & 0xFF0000) >> 16;
    Temp_byte[4] = (Temp_ulong[1] & 0x00FF00) >> 8;
    Temp_byte[5] = (Temp_ulong[1] & 0x0000FF);
    format3(Temp_byte);
}

void form1_hex_string_to_unsigned_int()            //hex to uint: form1
{
    Temp_uint16 = 0x0000;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] > '9')                   // letters
            VAL[i] = VAL[i] - 'a' + 0x0a;
        else                                // numbers
            VAL[i] = VAL[i] - '0';

        Temp_uint16 = Temp_uint16 | (VAL[i] << (VAL_NUM_ID - i - 1) * 4);
    }
    format1(Temp_uint16);
}

void form1_int_string_to_unsigned_int()                //form1
{
    Temp_uint16 = 0;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] == '-')
            continue;

        VAL[i] = VAL[i] - '0';
        Temp_uint16 = (Temp_uint16 * 10) + VAL[i];
    }
    format1(Temp_uint16);
}

void form4_int_string_to_unsigned_long(int shift_needed)                //form4
{
    Temp_ulong[0] = 0;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] == '-')
            continue;

        VAL[i] = VAL[i] - '0';
        Temp_ulong[0] = (Temp_ulong[0] * 10) + VAL[i];
    }
    if (shift_needed == 1)
        Temp_ulong[0] = (Temp_ulong[0] & 0xffffff00) >> 8;

    format4(Temp_ulong[0] & 0xffffff);
}

void form2_int_string_to_int()                   // form2
{
    Temp_int[0] = 0;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] == '-')
            continue;

        VAL[i] = VAL[i] - '0';
        Temp_int[0] = (Temp_int[0] * 10) + VAL[i];
    }
    if (VAL[0] == '-')
        Temp_int[0] *= -1;
    format2(Temp_int[0]);
}

void form5_int_string_to_long()    // form5
{
    Temp_long = 0;
    for (int i = 0; i < VAL_NUM_ID; i++)
    {
        if (VAL[i] == '-')
            continue;

        VAL[i] = VAL[i] - '0';
        Temp_long = (Temp_long * 10) + VAL[i];
    }
    if (VAL[0] == '-')
        Temp_long *= -1;
    format5(Temp_long);
}

int compareKey(char k1, char k2, char k3)
{
    if (KEY[0] != k1) return -1;
    if (KEY[1] != k2) return -1;
    if (KEY[2] != k3) return -1;
    return 0;
}

void new_chemsense_acquire()
{
    while (Serial3.available() > 0)
    {
        INPUT_BYTE = Serial3.read();     //read the incoming byte

        if (INPUT_BYTE >= 'a' && INPUT_BYTE <= 'z' ||
            INPUT_BYTE >= 'A' && INPUT_BYTE <= 'Z' ||
            INPUT_BYTE >= '0' && INPUT_BYTE <= '9' ||
            INPUT_BYTE == '-')
        {
            if (!flag_KEY)
            {
                if (KEY_NUM_ID < 3)
                {
                    KEY[KEY_NUM_ID] = INPUT_BYTE;
                    KEY_NUM_ID++;
                }
                else
                    KEY_NUM_ID = 0;
            }
            else
            {
                if (VAL_NUM_ID < 12)
                {
                    VAL[VAL_NUM_ID] = INPUT_BYTE;
                    VAL_NUM_ID++;
                }
                else
                {
                    KEY_NUM_ID = 0;
                    VAL_NUM_ID = 0;
                    flag_KEY = false;
                }
            }
        }
        else if (INPUT_BYTE == '=')
        {
            flag_KEY = true;
        }
        else if (INPUT_BYTE == '\r' || INPUT_BYTE == ' ' || INPUT_BYTE == '\n')
        {
            //KEY[KEY_NUM_ID] = '\0';
            //VAL[VAL_NUM_ID] = '\0';
            Carrier();
            KEY_NUM_ID = 0;
            VAL_NUM_ID = 0;
        }
    }
}

void Carrier()
{
    // transform the data format as it defined

	if (!flag_KEY)
		return;

    flag_KEY = false;
    // #ifdef SERIAL_DEBUG
    //     // to confirm output data
    //     SerialUSB.print(KEY);
    //     SerialUSB.print(" ");
    //     SerialUSB.print(VAL);
    //     SerialUSB.print(" ");
    // #endif

	if (compareKey('B', 'A', 'D') == 0)
	{
        //Hex_BAD();
        form3_hex_string_to_hex();

        chemsense_MAC_ID[0] = ID_CHEMSENSE_MAC;
        chemsense_MAC_ID[1] = (valid << 7) | LENGTH_FORMAT3;

        for (j = 0; j < LENGTH_FORMAT3; j++)
            chemsense_MAC_ID[2 + j] = formatted_data_buffer[j];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT3; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
	}

	else if (compareKey('S', 'H', 'T') == 0)  // wait SHH
	{
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check the values
        for (j = 0; j < LENGTH_FORMAT1; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('S', 'H', 'H') == 0)
    {
        //Temp_uint16 = (unsigned int)atoi(VAL);       //char to int
        //format1(Temp_uint16);
        form1_int_string_to_unsigned_int();

        SHT25[0] = ID_SHT25;
        SHT25[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);
        SHT25[2] = formatted_byte_temp[0];
        SHT25[3] = formatted_byte_temp[1];
        SHT25[4] = formatted_data_buffer[0];
        SHT25[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check the values
        for (j = 0; j < LENGTH_FORMAT1; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('L', 'P', 'T') == 0)  // wait LPP
	{
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('L', 'P', 'P') == 0)
    {
        //Int_form4();
        form4_int_string_to_unsigned_long(0);

        LPS25H[0] = ID_LPS25H;
        LPS25H[1] = (valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
        LPS25H[2] = formatted_byte_temp[0];
        LPS25H[3] = formatted_byte_temp[1];
        LPS25H[4] = formatted_data_buffer[0];
        LPS25H[5] = formatted_data_buffer[1];
        LPS25H[6] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT4; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
	}

	else if (compareKey('S', 'U', 'V') == 0)  // wait SVL and SIR
	{
        //Hex_form1();
        form1_hex_string_to_unsigned_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT1; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('S', 'V', 'L') == 0)
    {
        //Hex_form1();
        form1_hex_string_to_unsigned_int();

        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT1; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('S', 'I', 'R') == 0)
    {
        //Hex_form1();
        form1_hex_string_to_unsigned_int();

        Si1145[0] = ID_Si1145;
        Si1145[1] = (valid << 7) | (LENGTH_FORMAT1 * 3);
        Si1145[2] = formatted_byte_temp[0];
        Si1145[3] = formatted_byte_temp[1];
        Si1145[4] = formatted_byte_temp[2];
        Si1145[5] = formatted_byte_temp[3];
        Si1145[6] = formatted_data_buffer[0];
        Si1145[7] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT1; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('I', 'R', 'R') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        total_reducing_gases[0] = ID_TOTAL_REDUCING_GASES;
        total_reducing_gases[1] = (valid << 7) | LENGTH_FORMAT5;
        total_reducing_gases[2] = formatted_data_buffer[0];
        total_reducing_gases[3] = formatted_data_buffer[1];
        total_reducing_gases[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT5; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('I', 'A', 'Q') == 0)
    {
        //Int_form5();
        form5_int_string_to_long();

        total_oxidizing_gases[0] = ID_TOTAL_OXIDIZING_GASES;
        total_oxidizing_gases[1] = (valid << 7) | LENGTH_FORMAT5;
        total_oxidizing_gases[2] = formatted_data_buffer[0];
        total_oxidizing_gases[3] = formatted_data_buffer[1];
        total_oxidizing_gases[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT5; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('S', 'O', '2') == 0)
    {
        //Int_form5();
        form5_int_string_to_long();

        sulfur_dioxide[0] = ID_SULFUR_DIOXIDE;
        sulfur_dioxide[1] = (valid << 7) | LENGTH_FORMAT5;
        sulfur_dioxide[2] = formatted_data_buffer[0];
        sulfur_dioxide[3] = formatted_data_buffer[1];
        sulfur_dioxide[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT5; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('H', '2', 'S') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        hydrogen_sulphide[0] = ID_HYDROGEN_SULPHIDE;
        hydrogen_sulphide[1] = (valid << 7) | LENGTH_FORMAT5;
        hydrogen_sulphide[2] = formatted_data_buffer[0];
        hydrogen_sulphide[3] = formatted_data_buffer[1];
        hydrogen_sulphide[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT5; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('O', 'Z', 'O') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        ozone[0] = ID_OZONE;
        ozone[1] = (valid << 7) | LENGTH_FORMAT5;
        ozone[2] = formatted_data_buffer[0];
        ozone[3] = formatted_data_buffer[1];
        ozone[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT5; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('N', 'O', '2') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        nitrogen_dioxide[0] = ID_NITROGEN_DIOXIDE;
        nitrogen_dioxide[1] = (valid << 7) | LENGTH_FORMAT5;
        nitrogen_dioxide[2] = formatted_data_buffer[0];
        nitrogen_dioxide[3] = formatted_data_buffer[1];
        nitrogen_dioxide[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT5; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('C', 'M', 'O') == 0)
	{
        //Int_form5();
        form5_int_string_to_long();

        carbon_monoxide[0] = ID_CARBON_MONOXIDE;
        carbon_monoxide[1] = (valid << 7) | LENGTH_FORMAT5;
        carbon_monoxide[2] = formatted_data_buffer[0];
        carbon_monoxide[3] = formatted_data_buffer[1];
        carbon_monoxide[4] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT5; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
	}

	else if (compareKey('A', 'T', '0') == 0)
	{
        //Int_form2();
        form2_int_string_to_int();

        CO_ADC_temp[0] = ID_CO_ADC_TEMP;
        CO_ADC_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        CO_ADC_temp[2] = formatted_data_buffer[0];
        CO_ADC_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('A', 'T', '1') == 0)
	{
		//Int_form2();
        form2_int_string_to_int();

        IAQ_IRR_ADC_temp[0] = ID_IAQ_IRR_ADC_TEMP;
        IAQ_IRR_ADC_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        IAQ_IRR_ADC_temp[2] = formatted_data_buffer[0];
        IAQ_IRR_ADC_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('A', 'T', '2') == 0)
	{
		//Int_form2();
        form2_int_string_to_int();

        O3_NO2_ADC_temp[0] = ID_O3_NO2_ADC_TEMP;
        O3_NO2_ADC_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        O3_NO2_ADC_temp[2] = formatted_data_buffer[0];
        O3_NO2_ADC_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('A', 'T', '3') == 0)
	{
        //Int_form2();
        form2_int_string_to_int();

        SO2_H2S_ADC_temp[0] = ID_SO2_H2S_ADC_TEMP;
        SO2_H2S_ADC_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        SO2_H2S_ADC_temp[2] = formatted_data_buffer[0];
        SO2_H2S_ADC_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('L', 'T', 'M') == 0)
	{
		//Int_form2();
        form2_int_string_to_int();

        CO_LMP_temp[0] = ID_CO_LMP_TEMP;
        CO_LMP_temp[1] = (valid << 7) | LENGTH_FORMAT2;
        CO_LMP_temp[2] = formatted_data_buffer[0];
        CO_LMP_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('A', 'C', 'X') == 0)  //wait ACY, ACZ, and VIX
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('A', 'C', 'Y') == 0)
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('A', 'C', 'Z') == 0)
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[4] = formatted_data_buffer[0];
        formatted_byte_temp[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('V', 'I', 'X') == 0)
    {
        //Int_form4();
        form4_int_string_to_unsigned_long(1);

        three_accel_and_vib[0] = ID_THREE_ACCEL_AND_VIB;
        three_accel_and_vib[1] = (valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        three_accel_and_vib[2] = formatted_byte_temp[0];
        three_accel_and_vib[3] = formatted_byte_temp[1];
        three_accel_and_vib[4] = formatted_byte_temp[2];
        three_accel_and_vib[5] = formatted_byte_temp[3];
        three_accel_and_vib[6] = formatted_byte_temp[4];
        three_accel_and_vib[7] = formatted_byte_temp[5];
        three_accel_and_vib[8] = formatted_data_buffer[0];
        three_accel_and_vib[9] = formatted_data_buffer[1];
        three_accel_and_vib[10] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT4; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

	else if (compareKey('G', 'Y', 'X') == 0)  //wait GYY, GYZ, and OIX
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[0] = formatted_data_buffer[0];
        formatted_byte_temp[1] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('G', 'Y', 'Y') == 0)
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[2] = formatted_data_buffer[0];
        formatted_byte_temp[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('G', 'Y', 'Z') == 0)
    {
        //Int_form2();
        form2_int_string_to_int();

        formatted_byte_temp[4] = formatted_data_buffer[0];
        formatted_byte_temp[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT2; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

    else if (compareKey('O', 'I', 'X') == 0)
    {
        //Int_form4();
        form4_int_string_to_unsigned_long(1);

        three_gyro_and_orientation[0] = ID_THREE_GYRO_AND_ORIENTATION;
        three_gyro_and_orientation[1] = (valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
        three_gyro_and_orientation[2] = formatted_byte_temp[0];
        three_gyro_and_orientation[3] = formatted_byte_temp[1];
        three_gyro_and_orientation[4] = formatted_byte_temp[2];
        three_gyro_and_orientation[5] = formatted_byte_temp[3];
        three_gyro_and_orientation[6] = formatted_byte_temp[4];
        three_gyro_and_orientation[7] = formatted_byte_temp[5];
        three_gyro_and_orientation[8] = formatted_byte_temp[6];
        three_gyro_and_orientation[8] = formatted_data_buffer[0];
        three_gyro_and_orientation[9] = formatted_data_buffer[1];
        three_gyro_and_orientation[10] = formatted_data_buffer[2];

#ifdef SERIAL_DEBUG
        // to check output
        for (j = 0; j < LENGTH_FORMAT4; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
#endif
    }

// #ifdef SERIAL_DEBUG
//     SerialUSB.print("\r\n");
// #endif
}

// // formatting data
// void Hex_BAD()          // format3
// {
//     //SerialUSB.println(VAL);
// 	strncpy(first, VAL, 6);
// 	i += 6;
// 	strncpy(second, i, 6);
// 	Temp_ulong[0]= (unsigned long) strtol(first, NULL, 16);      //too short to contain the whole value of 'BAD'
// 	Temp_ulong[1] = (unsigned long) strtol(second, NULL, 16);
// 	byte result[6];
// 	result[0] = (Temp_ulong[0] & 0xFF0000) >> 16;
// 	result[1] = (Temp_ulong[0] & 0x00FF00) >> 8;
// 	result[2] = (Temp_ulong[0] & 0x0000FF);
// 	result[3] = (Temp_ulong[1] & 0xFF0000) >> 16;
// 	result[4] = (Temp_ulong[1] & 0x00FF00) >> 8;
// 	result[5] = (Temp_ulong[1] & 0x0000FF);
// 	format3(result);
// }
//
// void Hex_form1()
// {
//     Temp_uint16 = (unsigned int)strtol(VAL, NULL, 16);   //hex string to int
//     format1(Temp_uint16);
// }
//
// void Int_form2()
// {
//
//     Temp_int[0] = (int)atoi(VAL);
//     format2(Temp_int[0]);
// }
//
// void Int_form4()
// {
//     Temp_ulong[0] = (unsigned long)atol(VAL);              //char to int
//     format4(Temp_ulong[0]);
// }
//
// void Int_form5()
// {
//     Temp_long = (long) strtol(VAL, NULL, 10);
//     format5(Temp_long);
// }



#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/packet_assembler.ino"
int buffer_num = 0;

/** Assemble empty packet *************************************************************/
void assemble_packet_empty()
{
    packet_whole[0x00] = START_BYTE;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | HEADER_VERSION;
    packet_whole[0x02] = 0x00;
    packet_whole[0x03] = 0x00;
    packet_whole[0x04] = END_BYTE;
}
/**************************************************************************************/


/** Assemble whole packet *************************************************************/
void assemble_packet_whole()
{
    int chg_valid = 0;
    int packet_whole_index = 3; // start at 3 to account for header

    #ifdef SERIAL_DEBUG
    SerialUSB.println("Packing.");
    #endif
    
    #ifdef MAC_ID_include
    // Append MAC_ID
    for (buffer_num = 0; buffer_num < sizeof(MAC_ID); buffer_num++)
    {
        packet_whole[packet_whole_index] = MAC_ID[buffer_num];
        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif
    
    #ifdef TMP112_include
    // Append TMP112
    if (TMP112[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(TMP112); buffer_num++)
        {
            packet_whole[packet_whole_index] = TMP112[buffer_num];
            // Increment index for whole packet
            packet_whole_index++;
        }   
        TMP112[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
    #endif

    #ifdef HTU21D_include
    if (HTU21D[1] > 10)
    {
        // Append HTU21D
        for (buffer_num = 0; buffer_num < sizeof(HTU21D); buffer_num++)
        {
            packet_whole[packet_whole_index] = HTU21D[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        HTU21D[1] = (chg_valid << 7) | LENGTH_FORMAT6 ;
    }
    #endif

    // #ifdef GP2Y1010AU0F_include
    // if (GP2Y1010AU0F[1] > 10)
    // {
    //     // Append GP2Y1010AU0F
    //     for (int i = 0; i < sizeof(GP2Y1010AU0F); i++)
    //     {
    //         packet_whole[packet_whole_index] = GP2Y1010AU0F[i];

    //         // Increment index for whole packet
    //         packet_whole_index++;
    //     }
    //     GP2Y1010AU0F[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    // }
    // #endif

    #ifdef BMP180_include
    if (BMP180[1] > 10)
    {
        // Append BMP180
        for (buffer_num = 0; buffer_num < sizeof(BMP180); buffer_num++)
        {
            packet_whole[packet_whole_index] = BMP180[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        BMP180[1] = (chg_valid << 7) | (LENGTH_FORMAT5 + LENGTH_FORMAT6);
    }
    #endif

    #ifdef PR103J2_include
    if (PR103J2[1] > 10)
    {
        // Append PR103J2
        for (buffer_num = 0; buffer_num < sizeof(PR103J2); buffer_num++)
        {
            packet_whole[packet_whole_index] = PR103J2[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        PR103J2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TSL250RD_1_include
    if (TSL250RD_1[1] > 10)
    {
        // Append TSL250RD_1
        for (buffer_num = 0; buffer_num < sizeof(TSL250RD_1); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL250RD_1[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_1[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef MMA8452Q_include
    if (MMA8452Q[1] > 10)
    {
        // Append MMA8452Q
        for (buffer_num = 0; buffer_num < sizeof(MMA8452Q); buffer_num++)
        {
            packet_whole[packet_whole_index] = MMA8452Q[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        MMA8452Q[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 4);
    }
    #endif

    #ifdef SPV1840LR5HB_1_include
    if (SPV1840LR5HB_1[1] > 10)
    {
        // Append SPV1840LR5HB_1
        for (buffer_num = 0; buffer_num < sizeof(SPV1840LR5HB_1); buffer_num++)
        {
            packet_whole[packet_whole_index] = SPV1840LR5HB_1[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        SPV1840LR5HB_1[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TSYS01_include
    if (TSYS01[1] > 10)
    {
        // Append TSYS01
        for (buffer_num = 0; buffer_num < sizeof(TSYS01); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSYS01[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TSYS01[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
    #endif

    #ifdef HMC5883L_include
    if (HMC5883L[1] > 10)
    {
        // Append HMC5883L
        for (buffer_num = 0; buffer_num < sizeof(HMC5883L); buffer_num++)
        {
            packet_whole[packet_whole_index] = HMC5883L[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        HMC5883L[1] = (chg_valid << 7) | (LENGTH_FORMAT8 * 3);
    }
    #endif

    #ifdef HIH6130_include
    if (HIH6130[1] > 10)
    {
        // Append HIH6130
        for (buffer_num = 0; buffer_num < sizeof(HIH6130); buffer_num++)
        {
            packet_whole[packet_whole_index] = HIH6130[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        HIH6130[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 2);
    }
    #endif

    #ifdef APDS9006020_include
    if (APDS9006020[1] > 10)
    {
        // Append APDS9006020
        for (buffer_num = 0; buffer_num < sizeof(APDS9006020); buffer_num++)
        {
            packet_whole[packet_whole_index] = APDS9006020[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        APDS9006020[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TSL260RD_include
    if (TSL260RD[1] > 10) 
    {
        // Append TSL260RD
        for (buffer_num = 0; buffer_num < sizeof(TSL260RD); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL260RD[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL260RD[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TSL250RD_2_include
    if (TSL250RD_2[1] > 10)
    {
        // Append TSL260RD
        for (buffer_num = 0; buffer_num < sizeof(TSL260RD); buffer_num++)
        {
            packet_whole[packet_whole_index] = TSL260RD[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TSL250RD_2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef MLX75305_include
    if (MLX75305[1] > 10)
    {
        // Append MLX75305
        for (buffer_num = 0; buffer_num < sizeof(MLX75305); buffer_num++)
        {
            packet_whole[packet_whole_index] = MLX75305[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        MLX75305[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef ML8511_include
    if (ML8511[1] > 10)
    {
        // Append ML8511
        for (buffer_num = 0; buffer_num < sizeof(ML8511); buffer_num++)
        {
            packet_whole[packet_whole_index] = ML8511[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        ML8511[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef D6T_include
    if (D6T[1] > 10) 
    {
        // Append D6T
        for (buffer_num = 0; buffer_num < sizeof(D6T); buffer_num++)
        {
            packet_whole[packet_whole_index] = D6T[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        D6T[1] = (chg_valid << 7) | (LENGTH_FORMAT6 * 17);
    }
    #endif

    #ifdef MLX90614_include
    if (MLX90614[1] > 10)
    {
        // Append MLX90614
        for (buffer_num = 0; buffer_num < sizeof(MLX90614); buffer_num++)
        {
            packet_whole[packet_whole_index] = MLX90614[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        MLX90614[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif

    #ifdef TMP421_include
    if (TMP421[1] > 10)
    {
        // Append TMP421
        for (buffer_num = 0; buffer_num < sizeof(TMP421); buffer_num++)
        {
            packet_whole[packet_whole_index] = TMP421[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        TMP421[1] = (chg_valid << 7) | LENGTH_FORMAT6;
    }
    #endif

    #ifdef SPV1840LR5HB_2_include
    if (SPV1840LR5HB_2[1] > 10)
    {
        // Append SPV1840LR5HB_2
        for (buffer_num = 0; buffer_num < sizeof(SPV1840LR5HB_2); buffer_num++)
        {
            packet_whole[packet_whole_index] = SPV1840LR5HB_2[buffer_num];

            // Increment index for whole packet
            packet_whole_index++;
        }
        SPV1840LR5HB_2[1] = (chg_valid << 7) | LENGTH_FORMAT1;
    }
    #endif


#ifdef CHEMSENSE_INCLUDE
    if (chemsense_MAC_ID[1] > 10)
    {
        for (buffer_num = 0; buffer_num < sizeof(chemsense_MAC_ID); buffer_num++)
        {
            packet_whole[packet_whole_index] = chemsense_MAC_ID[buffer_num];
            packet_whole_index++;
        }
        chemsense_MAC_ID[1] = (chg_valid << 7) | LENGTH_FORMAT3;
    }

    if (SHT25[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(SHT25); buffer_num++)
        {
            packet_whole[packet_whole_index] = SHT25[buffer_num];
            packet_whole_index++;
        }
        SHT25[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT1);

    }
    
    if (LPS25H[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(LPS25H); buffer_num++)
        {
            packet_whole[packet_whole_index] = LPS25H[buffer_num];
            packet_whole_index++;
        }
        LPS25H[1] = (chg_valid << 7) | (LENGTH_FORMAT2 + LENGTH_FORMAT4);
    }

    if (Si1145[1] > 10)
    { 
        for (buffer_num = 0; buffer_num <  sizeof(Si1145); buffer_num++)
        {
            packet_whole[packet_whole_index] = Si1145[buffer_num];
            packet_whole_index++;
        }
        Si1145[1] = (chg_valid << 7) | (LENGTH_FORMAT1 * 3);
    }   
    
    if (total_reducing_gases[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(total_reducing_gases); buffer_num++)
        {
            packet_whole[packet_whole_index] = total_reducing_gases[buffer_num];
            packet_whole_index++;
        }
        total_reducing_gases[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (total_oxidizing_gases[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(total_oxidizing_gases); buffer_num++)
        {
            packet_whole[packet_whole_index] = total_oxidizing_gases[buffer_num];
            packet_whole_index++;
        }
        total_oxidizing_gases[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (sulfur_dioxide[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(sulfur_dioxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = sulfur_dioxide[buffer_num];
            packet_whole_index++;
        }
        sulfur_dioxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (hydrogen_sulphide[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(hydrogen_sulphide); buffer_num++)
        {
            packet_whole[packet_whole_index] = hydrogen_sulphide[buffer_num];
            packet_whole_index++;
        }
        hydrogen_sulphide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (ozone[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(ozone); buffer_num++)
        {
            packet_whole[packet_whole_index] = ozone[buffer_num];
            packet_whole_index++;
        }
        ozone[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (nitrogen_dioxide[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(nitrogen_dioxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = nitrogen_dioxide[buffer_num];
            packet_whole_index++;
        }
        nitrogen_dioxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (carbon_monoxide[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(carbon_monoxide); buffer_num++)
        {
            packet_whole[packet_whole_index] = carbon_monoxide[buffer_num];
            packet_whole_index++;
        }
        carbon_monoxide[1] = (chg_valid << 7) | LENGTH_FORMAT5;
    }
    
    if (CO_ADC_temp[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(CO_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = CO_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        CO_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if (IAQ_IRR_ADC_temp[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(IAQ_IRR_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = IAQ_IRR_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        IAQ_IRR_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if (O3_NO2_ADC_temp[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(O3_NO2_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = O3_NO2_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        O3_NO2_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }
    
    if (SO2_H2S_ADC_temp[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(SO2_H2S_ADC_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = SO2_H2S_ADC_temp[buffer_num];
            packet_whole_index++;
        }
        SO2_H2S_ADC_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }

    if (CO_LMP_temp[1] > 10)
    { 
        for (buffer_num = 0; buffer_num <  sizeof(CO_LMP_temp); buffer_num++)
        {
            packet_whole[packet_whole_index] = CO_LMP_temp[buffer_num];
            packet_whole_index++;
        }
        CO_LMP_temp[1] = (chg_valid << 7) | LENGTH_FORMAT2;
    }   
    
    if (three_accel_and_vib[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(three_accel_and_vib); buffer_num++)
        {
            packet_whole[packet_whole_index] = three_accel_and_vib[buffer_num];
            packet_whole_index++;
        }
        three_accel_and_vib[1] = (chg_valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
    }
    
    if (three_gyro_and_orientation[1] > 10)
    {
        for (buffer_num = 0; buffer_num <  sizeof(three_gyro_and_orientation); buffer_num++)
        {
            packet_whole[packet_whole_index] = three_gyro_and_orientation[buffer_num];
            packet_whole_index++;
        }
        three_gyro_and_orientation[1] = (chg_valid << 7) | (LENGTH_FORMAT2 * 3 + LENGTH_FORMAT4);
    }
#endif


    #ifdef system_health_include
    // Append health
    for (buffer_num = 0; buffer_num < sizeof(sensor_health); buffer_num++)
    {
        packet_whole[packet_whole_index] = sensor_health[buffer_num];
        // Increment index for whole packet
        packet_whole_index++;
    }
    #endif


    // Length
    packet_whole[0x02] = packet_whole_index - 0x03;
    packet_seq_number++;
    packet_whole[0x01] = ((packet_seq_number & 0x0f) << 4) | HEADER_VERSION;

    // Append CRC8
    packet_whole[packet_whole_index] = CRC_calc(packet_whole_index - 0x03);
    packet_whole[++packet_whole_index] = END_BYTE;

    #ifdef SERIAL_DEBUG
    SerialUSB.println(packet_whole_index,DEC);
    #endif
}
/**************************************************************************************/

#line 1 "/home/spark/repos/waggle/coresensors/v2/pbay/integrated/sensors_setup.ino"
void Sensors_Setup(void)
{
    #ifdef SERIAL_DEBUG
    SerialUSB.println("Setting up sensors...");
    #endif

    #ifdef TMP112_include

    #ifdef SERIAL_DEBUG
    SerialUSB.println("TMP112.");
    #endif

    TMP112_CONFIG();
    #endif

    #ifdef HTU21D_include

    #ifdef SERIAL_DEBUG
    SerialUSB.println("HTU21.");
    #endif

    #endif


    #ifdef  BMP180_include

    #ifdef SERIAL_DEBUG
    SerialUSB.println("BMP180.");
    #endif
    bmp.begin();
    #endif



    #ifdef  PR103J2_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("PR103J2.");
    #endif
    #endif

    #ifdef TSL250RD_1_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSL250RD_1.");
    #endif
    #endif

    #ifdef MMA8452Q_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("MMA8452Q.");
    #endif
    MMA8452_CONFIG();
    #endif

    #ifdef TSYS01_include

    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSYS01.");
    #endif
    TSYS01_CONFIG();
    #endif

    #ifdef HIH6130_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("HIH6130.");
    #endif
    #endif

    #ifdef TMP421_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TMP421.");
    #endif
    #endif

    #ifdef APDS9006020_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("APDS9006020.");
    #endif
    #endif

    #ifdef TSL260RD_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSL260RD.");
    #endif
    #endif

    #ifdef TSL250RD_2_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("TSL250RD_2.");
    #endif
    #endif

    #ifdef MLX75305_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("MLX75305.");
    #endif
    #endif

    #ifdef ML8511_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("ML8511.");
    #endif
    #endif

    #ifdef SPV1840LR5HB_1_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("SPV1840LR5HB_1.");
    #endif
    #endif

    #ifdef SPV1840LR5HB_2_include
    #ifdef SERIAL_DEBUG
    SerialUSB.println("SPV1840LR5HB_2.");
    #endif
    #endif

    #ifdef LIGHTSENSE_INCLUDE
    mcp3428_1.init(MCP342X::L, MCP342X::L);
    mcp3428_2.init(MCP342X::L, MCP342X::F);
    #endif

    #ifdef HMC5883L_include
    HMC5883_Magnetometer.begin();
    #endif
    return;
}

