/*
 * /coresensors/v2/pbay/integrated
 * config.cpp V2 (including NEW INTEL CHEMSENSE BOARD)
 */

/** Constants *************************************************************************/
#define I2C_SLAVE_ADDRESS 0x03

// #define DELAY_MS 15000

#define LENGTH_DATA  250
#define LENGTH_WHOLE  LENGTH_DATA + 5

#define LENGTH_FORMAT1  2
#define LENGTH_FORMAT2  2
#define LENGTH_FORMAT3  6
#define LENGTH_FORMAT4  3
#define LENGTH_FORMAT5  3
#define LENGTH_FORMAT6  2
#define LENGTH_FORMAT7  4
#define LENGTH_FORMAT8  2
#define MAX_FMT_SIZE 6


#define START_BYTE 0xAA
#define END_BYTE 0x55
#define HEADER_RESERVED 0x00 // Upper nibble
#define HEADER_VERSION 0x00 // Lower nibble
#define SENSOR_HEALTH_SIZE 0x04

#define ID_MAC  0x00

// Airsense
#define ID_TMP112  0x01
#define ID_HTU21D  0x02

//#define ID_GP2Y1010AU0F  0x03
#define ID_BMP180  0x04
#define ID_PR103J2  0x05
#define ID_TSL250RD_1  0x06

#define ID_MMA8452Q  0x07
#define ID_SPV1840LR5HB_1  0x08
#define ID_TSYS01  0x09

//Lightsense
#define ID_HMC5883L  0x0A
#define ID_HIH6130  0x0B

#define ID_APDS9006020  0x0C
#define ID_TSL260RD  0x0D
#define ID_TSL250RD_2  0x0E

#define ID_MLX75305  0x0F
#define ID_ML8511  0x10

#define ID_D6T  0x11            // WHERE DOES IT COME FROM?????
#define ID_MLX90614  0x12       // WHERE DOES IT COME FROM?????

#define ID_TMP421  0x13 
#define ID_SPV1840LR5HB_2  0x14

// Chensense
#define ID_CHEMSENSE_MAC  0x20

#define ID_SHT25 0x1D
#define ID_LPS25H 0x1E
#define ID_Si1145 0x1F

#define ID_TOTAL_REDUCING_GASES  0x15
#define ID_TOTAL_OXIDIZING_GASES  0x1A
#define ID_SULFUR_DIOXIDE  0x1C
#define ID_HYDROGEN_SULPHIDE  0x19
#define ID_OZONE  0x18
#define ID_NITROGEN_DIOXIDE  0x17
#define ID_CARBON_MONOXIDE  0x1B

#define ID_CO_ADC_TEMP  0x21
#define ID_IAQ_IRR_ADC_TEMP 0x22
#define ID_O3_NO2_ADC_TEMP  0x23
#define ID_SO2_H2S_ADC_TEMP 0x24
#define ID_CO_LMP_TEMP  0x25

#define ID_THREE_ACCEL_AND_VIB  0x26
#define ID_THREE_GYRO_AND_ORIENTATION   0x27

// #define ID_ETHANOL  0x16

/**************************************************************************************/

#define AIRSENSE_INCLUDE 0x01
#define LIGHTSENSE_INCLUDE 0x01
#define CHEMSENSE_INCLUDE 0x01

// AirsenseBoard
#ifdef AIRSENSE_INCLUDE
    #define MAC_ID_include 0x01

    #define TMP112_include 0x01
    #define HTU21D_include 0x01

    #define BMP180_include 0x01
    #define PR103J2_include 0x01
    #define TSL250RD_1_include 0x01

    #define MMA8452Q_include 0x01
    #define SPV1840LR5HB_1_include 0x01
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

    #define D6T_include 0x01 // does not exist in the board, in fact, apparently
    #define MLX90614_include 0x01 // does not exist in the board, in fact, apparently

    #define TMP421_include 0x01
    #define SPV1840LR5HB_2_include 0x01
#endif

// #define system_health_include 0x01
// #define RANDOMIZE_VALID 0x01
// #define SERIAL_DEBUG 0x01

// #define USBSERIAL_INTERFACE 0x01
#define I2C_INTERFACE 0x01
// #define I2C_PACKET_SIZE 191
// #define I2C_INTERFACE_CONST_SIZE 0x01
