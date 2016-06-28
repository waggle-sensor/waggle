/*
 * /coresensors/v3/pbay/integrated
 * integrated.ino V3 (pbay)
 */

#include <Wire.h>
#include "./libs/DueTimer/DueTimer.h"
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"

// Air/Lightsense ******************************************************** INCLUDING SENSORS ON AIR/LIGHTSENSE
#ifdef AIRSENSE_INCLUDE

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

#endif


#ifdef LIGHTSENSE_INCLUDE

#ifdef HMC5883L_include
    #include "./libs/HMC5883L_waggle/HMC5883L_waggle.h"
    HMC5883_Sensor HMC5883_Magnetometer = HMC5883_Sensor(&Wire);
#endif

#ifdef HIH6130_include
    #define HIH_ADDRESS 0x27
#endif

#ifdef TSL260RD_include
    #include "./libs/MCP342X/MCP342X.h"
    MCP342X mcp3428_1;
    MCP342X mcp3428_2;
#endif

#ifdef TMP421_include
    #include "./libs/LibTempTMP421/LibTempTMP421.h"
    LibTempTMP421 TMP421_Sensor = LibTempTMP421();
#endif

// #ifdef SPV1840LR5HB_1_include
//     #define SPV_1_SPL 6
//     #define SPV_1_AMP 5
// #endif

#endif
// ****************************************************************** INCLUDING SENSORS ON AIR/LIGHTSENSE

// store formatted values, dataFormat.ino ********************************************************** FORMATS FOR VALUES
byte formatted_data_buffer[MAX_FMT_SIZE];

// Sub-packets for each format
byte MAC_ID[LENGTH_FORMAT3 + 2]; // MAC address

// Airsense board
byte TMP112[LENGTH_FORMAT6 + 2]; // ambient temp
byte HTU21D[(LENGTH_FORMAT6 * 2) + 2]; // ambient RH & temp

byte HIH4030[LENGTH_FORMAT1 + 2]; // humidity 

byte BMP180[LENGTH_FORMAT5 + LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte PR103J2[LENGTH_FORMAT1 + 2]; // light
byte TSL250RD_1[LENGTH_FORMAT1 + 2]; // ambient light (400-950nm)

byte MMA8452Q[(LENGTH_FORMAT6 * 4) + 2]; // 3-axis accel for traffic flow
byte SPV1840LR5HB[LENGTH_FORMAT1 + 2]; // sound pressure
byte TSYS01[LENGTH_FORMAT6 + 2]; // ambient temp


// Lightsense board
byte HMC5883L[(LENGTH_FORMAT8 * 3) + 2]; // magnetic field strength for traffic flow
byte HIH6130[(LENGTH_FORMAT6 * 2) + 2]; // temp and RH inside transparent box

byte APDS9006020[LENGTH_FORMAT1 + 2]; // ambient light inside cavity
byte TSL260RD[LENGTH_FORMAT1 + 2]; // solar near IR
byte TSL250RD_2[LENGTH_FORMAT1 + 2]; // solar visible light

byte MLX75305[LENGTH_FORMAT1 + 2]; // solar visible light
byte ML8511[LENGTH_FORMAT1 + 2]; // solar UV
byte TMP421[LENGTH_FORMAT6 + 2]; // temp inside transparent box

// byte D6T[(LENGTH_FORMAT6 * 17) + 2]; // temp of surrounding objects
// byte MLX90614[LENGTH_FORMAT1 + 2]; // temp of pavement


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
//Data sub-packet
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

bool TIMER = true;

int on_off_counter = 1;;
bool CHEM_OFF = false;
bool TESTER = false;


byte I2C_READ_COMPLETE = true;

void setup()
{
    // Let us wait for the processor and the sensors to settle down
    delay(2000);
    Wire.begin(); // Sensors are on the first I2C Bus.
    SerialUSB.begin(USBSERIAL_INTERFACE_DATARATE); // Serial data line to the host computer
    Serial3.begin(CHEMSENSE_DATARATE); // data from the Chemsense board arrives here.

    initializeSensorBoard();

    //Setup the I2C buffer
    for (byte i=0x00; i<LENGTH_WHOLE; i++)
        packet_whole[i] = 0x00;

    assemble_packet_empty();
    Sensors_Setup();

    #ifdef CHEMSENSE_INCLUDE
    digitalWrite(PIN_CHEMSENSE_POW, LOW); // Power on the Chemsense board
    #endif

    #ifdef I2C_INTERFACE
    I2C_READ_COMPLETE = false;
    Wire1.begin(I2C_SLAVE_ADDRESS);
    Wire1.onRequest(requestEvent);
    #endif

    sensor_buff_initialization();
    
    //Timer3.attachInterrupt(tester).setPeriod(1000000 * 35).start();  // POWER ON/OFF Chemsense board
}

void handler()
{
    TIMER = false;
}

void loop()
{

    #ifdef AIRSENSE_INCLUDE
    airsense_acquire();
    #endif
    #ifdef LIGHTSENSE_INCLUDE
    lightsense_acquire();
    #endif

    Timer3.attachInterrupt(handler).setPeriod(1000000 * TIME_DELAY).start(); // print super-packet every 30 secs


    while (TIMER)
    {
        #ifdef CHEMSENSE_INCLUDE
        chemsense_acquire();
        #endif
    }

    Timer3.attachInterrupt(handler).stop();
    assemble_packet_whole();
    TIMER = true;
    /*
    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
    {
        SerialUSB.write(packet_whole[i]);
        SerialUSB.print(packet_whole[i], HEX);
        SerialUSB.print(":");
    }
    */
        
}

#ifdef I2C_INTERFACE
void requestEvent()
{
    #ifdef I2C_INTERFACE_CONST_SIZE
    Wire1.write(packet_whole, I2C_PACKET_SIZE);

    #else
    char bytes_to_send;
    bytes_to_send = packet_whole[0x02] + 0x05;
    Wire1.write(packet_whole, bytes_to_send );
    #endif

    I2C_READ_COMPLETE = true;
    assemble_packet_empty();
}
#endif



