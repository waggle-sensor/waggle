
// Chemsense data communication rate *********************** FOR CHEMSEMSE DATA COMMUNICATION W/COM or W/SENSOR BOARD
#define USBSERIAL_INTERFACE_DATARATE 115200
#define CHEMSENSE_DATARATE 19200
// ********************************************************* FOR CHEMSEMSE DATA COMMUNICATION W/COM or W/SENSOR BOARD

// Buffer size for each format **************************** ARE USED IN AIR/LIGHT/CHEM/DATAFORMAT/ETC
#define LENGTH_FORMAT1  2
#define LENGTH_FORMAT2  2
#define LENGTH_FORMAT3  6
#define LENGTH_FORMAT4  3
#define LENGTH_FORMAT5  3
#define LENGTH_FORMAT6  2
#define LENGTH_FORMAT7  4
#define LENGTH_FORMAT8  2
#define MAX_FMT_SIZE 6

#define LENGTH_ALPHA_FIRMWARE 2
#define LENGTH_ALPHA_HISTOGRAM 62

#define LENGTH_ALPHA_CONFIG_A 64
#define LENGTH_ALPHA_CONFIG_B 64
#define LENGTH_ALPHA_CONFIG_C 64
#define LENGTH_ALPHA_CONFIG_D 64

// ******************************************************** ARE USED IN AIR/LIGHT/CHEM/DATAFORMAT/ETC

// Packet header *************************************** ARE USED IN PACK ASSEMBLER
#define LENGTH_DATA  250
#define LENGTH_WHOLE  LENGTH_DATA + 5

#define START_BYTE 0xAA
#define END_BYTE 0x55
#define HEADER_RESERVED 0x00 // Upper nibble ***************************************NOT USING THIS VALUE!!!!!!!!!!
#define HEADER_VERSION 0x00 // Lower nibble
// ***************************************************** ARE USED IN PACK ASSEMBLER

// #define SENSOR_HEALTH_SIZE 0x04

// ***************************************************************** ARE USED IN AIR/LIGHT/CHEM

// #define ID_HEALTH  0xFE

#define EEPROM_ADDRESS      0x50    //Address of 24LC256 EEPROM
#define PIN_CHEMSENSE_POW   47
#define PIN_DS2401          48
// #define PIN_CHEMSENSE_RST   49
// #define PIN_CHEMSENSE_HBT   50

#define PIN_HBT             8               // HBEAT PIN (ON/OFF)
// #define PIN_GP2Y_OUT        A7
// #define PIN_GP2Y_IN         A4
#define PIN_SPV_AMP         A5  // Analog In 5, PA4 @ Atmel
#define PIN_SVP_SPL         A6
#define PIN_RAW_MIC         A9

//** alphasense
#define PIN_ALPHASENSE_SLAVE 33
#define SPI_MAX_speed 500000

// Which sensor boards are being used   ************************* IS BEING USED OR NOT
#define AIRSENSE_INCLUDE 0x01
#define LIGHTSENSE_INCLUDE 0x01
#define CHEMSENSE_INCLUDE 0x01
// #define ALPHASENSE_INCLUDE 0x01
//*************************************************************** IS BEING USED OR NOT

// First byte for every formatted buffers **************************** ARE USED IN AIR/LIGHT/CHEM
#define ID_MAC  0x00

//airsense
#define ID_TMP112  0x01
#define ID_HTU21D  0x02

#define ID_HIH4030  0x03

#define ID_BMP180  0x04
#define ID_PR103J2  0x05
#define ID_TSL250RD_1  0x06

#define ID_MMA8452Q  0x07
#define ID_SPV1840LR5HB  0x08
#define ID_TSYS01  0x09


//lightsense
#define ID_HMC5883L  0x0A
#define ID_HIH6130  0x0B

#define ID_APDS9006020  0x0C
#define ID_TSL260RD  0x0D
#define ID_TSL250RD_2  0x0E

#define ID_MLX75305  0x0F
#define ID_ML8511  0x10
#define ID_TMP421  0x13

//** NO USE but FYI interms of using codes in /coresense_plugin
//#define ID_D6T  0x11                  // NO USE
//#define ID_MLX90614  0x12             // NO USE
//#define ID_SPV1840LR5HB_2  0x14       // NO USE

//Chemsense
#define ID_CHEMSENSE_MAC  0x20

#define ID_SHT25 0x1D
#define ID_LPS25H 0x1E
#define ID_Si1145 0x1F

//** NO USE but FYI interms of using codes in /coresense_plugin
// #define ID_ETHANOL  0x16              // NO USE

#define ID_TOTAL_REDUCING_GASES  0x15
#define ID_TOTAL_OXIDIZING_GASES  0x1A
#define ID_SULFUR_DIOXIDE  0x1C
#define ID_HYDROGEN_SULPHIDE  0x19
#define ID_OZONE  0x18
#define ID_NITROGEN_DIOXIDE  0x17
#define ID_CARBON_MONOXIDE  0x1B

#define ID_CO_ADC_TEMP	0x21
#define ID_IAQ_IRR_ADC_TEMP	0x22
#define ID_O3_NO2_ADC_TEMP	0x23
#define ID_SO2_H2S_ADC_TEMP	0x24
#define ID_CO_LMP_TEMP	0x25

#define ID_THREE_ACCEL_AND_VIB	0x26
#define ID_THREE_GYRO_AND_ORIENTATION	0x27

//** alphasensor
#define ID_ALPHA_HISTOGRAM 0x28
#define ID_ALPHA_FIRMWARE 0x29

#define ID_ALPHA_CONFIG_A 0x30
#define ID_ALPHA_CONFIG_B 0x31 
#define ID_ALPHA_CONFIG_C 0x32
#define ID_ALPHA_CONFIG_D 0x33

//** include each sensor
#ifdef AIRSENSE_INCLUDE
    #define MAC_ID_include 0x01

    #define TMP112_include 0x01
    #define HTU21D_include 0x01

    #define HIH4030_include 0x01

    #define BMP180_include 0x01
    #define PR103J2_include 0x01
    #define TSL250RD_1_include 0x01

    #define MMA8452Q_include 0x01
    #define SPV1840LR5HB_include 0x01
    #define TSYS01_include 0x01
#endif

// Lightsense board
#ifdef LIGHTSENSE_INCLUDE
    #define HMC5883L_include 0x01
    #define HIH6130_include 0x01

    #define APDS9006020_include 0x01
    #define TSL260RD_include 0x01
    #define TSL250RD_2_include 0x01

    #define MLX75305_include 0x01
    #define ML8511_include 0x01
    #define TMP421_include 0x01
#endif

#ifdef CHEMSENSE_INCLUDE
    #define chemsense_MAC_ID_include 0x01

    #define SHT25_include 0x01
    #define LPS25H_include 0x01
    #define Si1145_include 0x01

    #define total_reducing_gases_include 0x01
    #define total_oxidizing_gases_include 0x01
    #define sulfur_dioxide_include 0x01
    #define hydrogen_sulphide_include 0x01
    #define ozone_include 0x01
    #define nitrogen_dioxide_include 0x01
    #define carbon_monoxide_include 0x01

    #define CO_ADC_temp_include 0x01
    #define IAQ_IRR_ADC_temp_include 0x01
    #define O3_NO2_ADC_temp_include 0x01
    #define SO2_H2S_ADC_temp_include 0x01
    #define CO_LMP_temp_include 0x01

    #define three_accel_and_vib_include 0x01
    #define three_gyro_and_orientation_include 0x01
#endif

// #define system_health_include 0x01
// #define RANDOMIZE_VALID 0x01
// #define PRINT_BUFFER 0x01
// #define SERIAL_DEBUG 0x01
// #define OIX_DEBUG 0x01
// #define PRINT_ADDRESS 0x01

#define USBSERIAL_INTERFACE 0x01
// #define I2C_INTERFACE_CONST_SIZE 0x01

#ifndef USBSERIAL_INTERFACE
#define I2C_INTERFACE 0x01
#define I2C_SLAVE_ADDRESS 0x03
#endif 

#ifndef I2C_INTERFACE_CONST_SIZE
#define I2C_PACKET_SIZE 191
#endif



