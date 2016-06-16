#include <Wire.h>
#include "./libs/DueTimer/DueTimer.h"
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"

// Air/Lightsense ******************************************************** INCLUDING SENSORS ON AIR/LIGHTSENSE
#ifdef LIGHTSENSE_INCLUDE
    #include "./libs/MCP342X/MCP342X.h"
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

#ifdef LIGHTSENSE_INCLUDE
#ifdef HMC5883L_include
#include "./libs/HMC5883L_waggle/HMC5883L_waggle.h"
HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(&Wire);
#endif

#ifdef HIH6130_include
#define HIH_ADDRESS 0x27
#endif

#ifdef TMP421_include
#include "./libs/LibTempTMP421/LibTempTMP421.h"
LibTempTMP421 TMP421_Sensor = LibTempTMP421();
#endif
#endif
// ****************************************************************** INCLUDING SENSORS ON AIR/LIGHTSENSE

byte computecrc(byte *data, byte size, byte crc)
{
    for (int j = 0; j < size; j++) {
        
        crc ^= data[j];
    
        for (byte i = 0; i < 8; i++)
        {
            if (crc & 0x01)
                crc = (crc >> 0x01) ^ 0x8C;
            else
                crc =  crc >> 0x01;
        }
    }

    return crc;
}

class Communicator
{
    public:

        Communicator();

        void transfer();

        void packetBegin();
        void packetEnd();
        
        void subpacketBegin(byte sensor, bool valid=true);
        void subpacketEnd();

        void subpacketFormat1(unsigned int input);
        void subpacketFormat2(int input);
        void subpacketFormat3(byte *input);
        void subpacketFormat4(unsigned long value);
        void subpacketFormat5(long value);
        void subpacketFormat6(float value);
        void subpacketFormat7(byte *value);
        void subpacketFormat8(float value);

    private:

        byte sequence;
        byte version;

        byte packet[256];
        byte packetSize;

        byte subpacketSensor;
        bool subpacketValid;

        byte subpacket[256];
        byte subpacketSize;
};

Communicator::Communicator()
{
    sequence = 0;
    version = 2;
}

void Communicator::transfer()
{
    byte seqver = ((sequence << 4) & 0xF0) | (version & 0x0F);
    byte crc = computecrc(packet, packetSize, 0);
    
    SerialUSB.write((byte)0xAA);
    SerialUSB.write((byte)seqver);
    SerialUSB.write((byte)packetSize);
    SerialUSB.write(packet, packetSize);
    SerialUSB.write((byte)crc);
    SerialUSB.write((byte)0x55);

    sequence++;
}

void Communicator::packetBegin()
{
    packetSize = 0;
}

void Communicator::packetEnd()
{
}

void Communicator::subpacketBegin(byte sensor, bool valid)
{
    subpacketSize = 0;
    subpacketSensor = sensor;
    subpacketValid = valid;
}

void Communicator::subpacketEnd()
{
    byte vallen = subpacketSize & 0x7F;

    if (subpacketValid)
        vallen |= 0x80;
    
    packet[packetSize++] = subpacketSensor;
    packet[packetSize++] = vallen;
    
    for (int i = 0; i < subpacketSize; i++) {
        packet[packetSize++] = subpacket[i];
    }
}

void Communicator::subpacketFormat1(unsigned int input)
{
    subpacket[subpacketSize++] = (input & 0xff00) >> 8;
    subpacket[subpacketSize++] = input & 0xff;
}

void Communicator::subpacketFormat2(int input)
{
    byte _negative;
    
    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    input = abs(input);
    
    subpacket[subpacketSize++] = (_negative << 7) | ((input & 0x7f00) >> 8);
    subpacket[subpacketSize++] = input & 0xff;
}

void Communicator::subpacketFormat3(byte *input)
{
    for (int i = 0; i < 6; i++) {
        subpacket[subpacketSize++] = input[i];
    }
}

void Communicator::subpacketFormat4(unsigned long input)
{
    subpacket[subpacketSize++] = (input & 0xff0000) >> 16;
    subpacket[subpacketSize++] = (input & 0xff00) >> 8;
    subpacket[subpacketSize++] = (input & 0xff);
}

void Communicator::subpacketFormat5(long input)
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
    subpacket[subpacketSize++] = (_negative << 7) | ((input & 0x7f0000) >> 16);
    subpacket[subpacketSize++] = (input & 0xff00) >> 8;
    subpacket[subpacketSize++] = (input & 0xff);
}

void Communicator::subpacketFormat6(float input)
{
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    input = abs(input);
    
    // Extract integer component
    unsigned int integer = (int)input;
    
    // Extract fractional component (and turn it into an integer)
    unsigned int fractional = ((int)(input*100) - integer*100);

    subpacket[subpacketSize++] = (_negative << 7) | integer;
    subpacket[subpacketSize++] = (fractional & 0x7F);
}

void Communicator::subpacketFormat7(byte *input)
{
    for (int i = 0; i < 4; i++) {
        subpacket[subpacketSize++] = input[i];
    }
}

void Communicator::subpacketFormat8(float input)
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

    input = abs(input);
    
    // Extract integer component
    int integer = (int)input;
    
    // Extract fractional component (and turn it into an integer)
    int fractional = int((input - integer) * 1000);

    // Assemble sub-packet
    subpacket[subpacketSize++] = (_negative << 7) | ((integer & 0x1F) << 2) | ((fractional & 0x0300) >> 8);
    subpacket[subpacketSize++] = (fractional & 0x00FF);
}

Communicator comm;

// store formatted values, dataFormat.ino ********************************************************** FORMATS FOR VALUES
byte formatted_data_buffer[MAX_FMT_SIZE];

// Sub-packets for each format
// Airsense board
byte MAC_ID[LENGTH_FORMAT3 + 2] = {ID_MAC, 134,0,0,0,0,0,0}; // MAC address

byte BMP180[LENGTH_FORMAT5 + LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte TMP112[LENGTH_FORMAT6 + 2]; // ambient temp
byte TSYS01[LENGTH_FORMAT6 + 2]; // ambient temp
byte HTU21D[(LENGTH_FORMAT6 * 2) + 2]; // ambient RH & temp
byte MMA8452Q[(LENGTH_FORMAT6 * 4) + 2]; // 3-axis accel for traffic flow
byte PR103J2[LENGTH_FORMAT1 + 2]; // light
byte TSL250RD_1[LENGTH_FORMAT1 + 2]; // ambient light (400-950nm)
byte SPV1840LR5HB[LENGTH_FORMAT1 + 2]; // sound pressure
byte HIH4030[LENGTH_FORMAT1 + 2]; // humidity **************************************************does not exist in packet_assembler.ino

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

//chemsense board
byte chemsense_MAC_ID[LENGTH_FORMAT3 + 2] = {0,0,0,0,0,0,0,0}; // MAC address of chemsense board

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
byte sensor_health[SENSOR_HEALTH_SIZE+2];


// ************************************************************************************************ FORMATS FOR VALUES

OneWire ds2401(PIN_DS2401);  //DS2401 PIN

//byte test_seq;   //********************************** NOT USING NOW


// Data sub-packet
//byte packet_data[LENGTH_DATA];  //********************************** NOT USING NOW


// These lengths are calculated at packet assembly
//byte length_whole_actual;
//byte length_data_actual;

int valid = 1;
int packet_whole_index = 0;

//unsigned char buffer [BUFFER_SIZE_CHEMSENSE];
//unsigned char parameter[PARAM_SIZE_CHEMSENSE];
//unsigned char cnt = 0;
//boolean chemsense_ready = false;
//long param_value;
//unsigned char attenuate = 0;
//byte valid;

float Temp_float[3];    //air, light
uint16_t Temp_uint16;   //air, TMP112
long Temp_long;         //air, TMP112
unsigned long Temp_ulong[2]; // Chem
int Temp_int[3];        //HIH
byte Temp_byte[8];      //sensor setup, HIH

bool TIMER = false;
byte I2C_READ_COMPLETE = true;

void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(2000);
    Wire.begin(); // Sensors are on the first I2C Bus.
    SerialUSB.begin(USBSERIAL_INTERFACE_DATARATE); // Serial data line to the host computer
    Serial3.begin(CHEMSENSE_DATARATE); // data from the Chemsense board arrives here.

    initializeSensorBoard();

    Sensors_Setup();

    #ifdef CHEMSENSE_INCLUDE
    digitalWrite(PIN_CHEMSENSE_POW, LOW); // Power on the Chemsense board
    #endif

//    Timer3.attachInterrupt(handler).setPeriod(1000000 * 5).start(); // print super-packet every 30 secs
}

//void handler()
//{
//    TIMER = true;
//}

void loop()
{
    comm.packetBegin();
    
//    #ifdef CHEMSENSE_INCLUDE
//    chemsense_acquire();
//    #endif

    #ifdef AIRSENSE_INCLUDE
    airsense_acquire();
    #endif

//    #ifdef LIGHTSENSE_INCLUDE
//    lightsense_acquire();
//    #endif

    comm.packetEnd();

    comm.transfer();

    delay(5000);
}

