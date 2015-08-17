#include <Wire.h>
extern TwoWire Wire1;
#include "config.cpp"

#ifdef HTU21D_include
#include <HTU21D.h>
HTU21D myHumidity;
#endif

#ifdef  BMP180_include
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
sensors_event_t event;
#endif


#ifdef  PR103J2_include
#define A2D_PRJ103J2 0
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


// #define CR_ENABLE 0
#define CR_ENABLE 1
#define BUFFER_SIZE_CHEMSENSE 150
#define PARAM_SIZE_CHEMSENSE 15
#define DEBUG_chemsense 0

// Main board
byte MAC_ID[LENGTH_FORMAT3 + 2] = {ID_MAC, 134,2,3,4,5,6,7}; // MAC address
byte TMP112[LENGTH_FORMAT1 + 2]; // ambient temp
byte HTU21D[(LENGTH_FORMAT1 * 2) + 2]; // ambient RH & temp
byte GP2Y1010AU0F[LENGTH_FORMAT2 + 2]; // dust density
byte BMP180[LENGTH_FORMAT1 + LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte PR103J2[LENGTH_FORMAT2 + 2]; // light
byte TSL250RD_1[LENGTH_FORMAT2 + 2]; // ambient light (400-950nm)
byte MMA8452Q[(LENGTH_FORMAT1 * 4) + 2]; // 3-axis accel for traffic flow
byte SPV1840LR5HB_1[LENGTH_FORMAT2 + 2]; // sound pressure
byte TSYS01[LENGTH_FORMAT2 + 2]; // ambient temp

// Aux board
byte HMC5883L[(LENGTH_FORMAT4 * 3) + 2]; // magnetic field strength for traffic flow
byte HIH6130[(LENGTH_FORMAT1 * 2) + 2]; // temp and RH inside transparent box
byte APDS9006020[LENGTH_FORMAT2 + 2]; // ambient light inside cavity
byte TSL260RD[LENGTH_FORMAT2 + 2]; // solar near IR
byte TSL250RD_2[LENGTH_FORMAT2 + 2]; // solar visible light
byte MLX75305[LENGTH_FORMAT2 + 2]; // solar visible light
byte ML8511[LENGTH_FORMAT2 + 2]; // solar UV
byte D6T[(LENGTH_FORMAT1 * 17) + 2]; // temp of surrounding objects
byte MLX90614[LENGTH_FORMAT1 + 2]; // temp of pavement
byte TMP421[LENGTH_FORMAT1 + 2]; // temp inside transparent box
byte SPV1840LR5HB_2[LENGTH_FORMAT2 + 2]; // sound pressure

// chemsense board
byte total_reducing_gases[LENGTH_FORMAT6 + 2]; // ambient concentration
byte ethanol[LENGTH_FORMAT6 + 2]; // ambient concentration
byte nitrogen_dioxide[LENGTH_FORMAT6 + 2]; // ambient concentration
byte ozone[LENGTH_FORMAT6 + 2]; // ambient concentration
byte hydrogen_sulphide[LENGTH_FORMAT6 + 2]; // ambient concentration
byte total_oxidizing_gases[LENGTH_FORMAT6 + 2]; // ambient concentration
byte carbon_monoxide[LENGTH_FORMAT6 + 2]; // ambient concentration
byte sulfur_dioxide[LENGTH_FORMAT6 + 2]; // ambient concentration

byte SHT25[(LENGTH_FORMAT5 * 2) + 2]; // ambient temp and RH
byte LPS25H[LENGTH_FORMAT5 + LENGTH_FORMAT6 + 2]; // atmospheric temperature and pressure
byte Si1145[LENGTH_FORMAT2 + 2]; // UV

byte chemsense_MAC_ID[LENGTH_FORMAT3 + 2] = {0,0,0,0,0,0,0,0}; // MAC address of chemsense board



// Whole packet
byte packet_whole[LENGTH_WHOLE];
byte sensor_health[SENSOR_HEALTH_SIZE+2];
// Data sub-packet
byte packet_data[LENGTH_DATA];
// Sub-packets for each format
byte packet_format1[LENGTH_FORMAT1];
byte packet_format2[LENGTH_FORMAT2];
byte packet_format3[LENGTH_FORMAT3];
byte packet_format4[LENGTH_FORMAT4];
byte packet_format5[LENGTH_FORMAT5];
byte packet_format6[LENGTH_FORMAT6];

// These lengths are calculated at packet assembly
byte length_whole_actual;
byte length_data_actual;


unsigned char buffer [BUFFER_SIZE_CHEMSENSE];
unsigned char parameter[PARAM_SIZE_CHEMSENSE];
unsigned char cnt = 0;
boolean chemsense_ready = false;
long param_value;
unsigned char attenuate = 0;
byte valid;


float Temp_float[3];
byte Temp_byte[3];
uint16_t Temp_uint16;
long Temp_long;
int Temp_int[3];


// CRC-8
byte crc = 0x00;
/**************************************************************************************/



/** I2C request interrupt *************************************************************/
void requestEvent()
{
    // Send it!
    // Wire.write(packet_whole, packet_whole[0x02]+0x05);
    // Put whole packet together
    // assemble_packet_empty();
    assemble_packet_whole();
    for(int i = 0; i < packet_whole[0x02]+0x05; i++)
    {
        SerialUSB.print(packet_whole[i], DEC);
        SerialUSB.print(" ");
    }
    SerialUSB.print("\n");
}
/**************************************************************************************/



/** Arduino: setup ********************************************************************/
void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(6000);
    SerialUSB.begin(115200);
    SerialUSB.println("Starting UP..");
    Serial3.begin(115200);
    //     Setup the I2C buffer
    for (byte i=0x00; i<LENGTH_WHOLE; i++)
    {
        packet_whole[i] = 0x00;
    }
    packet_whole[0x00] = START_BYTE;
    packet_whole[0x01] = HEADER_RESERVED | HEADER_VERSION;
    packet_whole[0x02] = 0x00;
    packet_whole[0x03] = 0x00;
    packet_whole[0x04] = END_BYTE;
    Wire1.begin();
    Sensors_Setup();
    // Join I2C bus as slave
    // Wire.begin(I2C_SLAVE_ADDRESS);
    // Register interrupt
    // Wire.onRequest(requestEvent);
}
/**************************************************************************************/

void loop()
{
    airsense_acquire();
    chemsense_aquire();
    chemsense_pack();
//     requestEvent();
    delay(2000);
}
