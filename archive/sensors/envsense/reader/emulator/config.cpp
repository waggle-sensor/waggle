
/** Constants *************************************************************************/
#define I2C_SLAVE_ADDRESS 0x03

#define DELAY_MS 15000

#define LENGTH_DATA  194
#define LENGTH_WHOLE  LENGTH_DATA + 5
#define LENGTH_FORMAT1  2
#define LENGTH_FORMAT2  2
#define LENGTH_FORMAT3  6
#define LENGTH_FORMAT4  2
#define LENGTH_FORMAT5  2
#define LENGTH_FORMAT6  3

#define START_BYTE 0xAA
#define END_BYTE 0x55
#define HEADER_RESERVED 0x00 // Upper nibble
#define HEADER_VERSION 0x00 // Lower nibble
#define SENSOR_HEALTH_SIZE 0x04

#define ID_MAC  0x00
#define ID_TMP112  0x01
#define ID_HTU21D  0x02
#define ID_GP2Y1010AU0F  0x03
#define ID_BMP180  0x04
#define ID_PR103J2  0x05
#define ID_TSL250RD_1  0x06
#define ID_MMA8452Q  0x07
#define ID_SPV1840LR5HB_1  0x08
#define ID_TSYS01  0x09
#define ID_HMC5883L  0x0A
#define ID_HIH6130  0x0B
#define ID_APDS9006020  0x0C
#define ID_TSL260RD  0x0D
#define ID_TSL250RD_2  0x0E
#define ID_MLX75305  0x0F
#define ID_ML8511  0x10
#define ID_D6T  0x11
#define ID_MLX90614  0x12
#define ID_TMP421  0x13
#define ID_SPV1840LR5HB_2  0x14
#define ID_TOTAL_REDUCING_GASES  0x15
#define ID_ETHANOL  0x16
#define ID_NITROGEN_DIOXIDE  0x17
#define ID_OZONE  0x18
#define ID_HYDROGEN_SULPHIDE  0x19
#define ID_TOTAL_OXIDIZING_GASES  0x1A
#define ID_CARBON_MONOXIDE  0x1B
#define ID_SULFUR_DIOXIDE  0x1C
#define ID_SENSIRION  0x1D
#define ID_BOSH  0x1E
#define ID_INTEL_MAC  0x1F
#define ID_HEALTH  0xFE

/**************************************************************************************/


// Main board
#define MAC_ID_include 0x01
#define TMP112_include 0x01
#define HTU21D_include 0x01
#define GP2Y1010AU0F_include 0x01
#define BMP180_include 0x01
#define PR103J2_include 0x01
#define TSL250RD_1_include 0x01
#define MMA8452Q_include 0x01
#define SPV1840LR5HB_1_include 0x01
#define TSYS01_include 0x01

// Aux board
#define HMC5883L_include 0x01
#define HIH6130_include 0x01
#define APDS9006020_include 0x01
#define TSL260RD_include 0x01
#define TSL250RD_2_include 0x01
#define MLX75305_include 0x01
#define ML8511_include 0x01
#define D6T_include 0x01
#define MLX90614_include 0x01
#define TMP421_include 0x01
#define SPV1840LR5HB_2_include 0x01

// Intel board
#define total_reducing_gases_include 0x01
#define ethanol_include 0x01
#define nitrogen_dioxide_include 0x01
#define ozone_include 0x01
#define hydrogen_sulphide_include 0x01
#define total_oxidizing_gases_include 0x01
#define carbon_monoxide_include 0x01
#define sulfur_dioxide_include 0x01
#define sensirion_include 0x01
#define bosh_include 0x01
#define intel_MAC_ID_include 0x01
#define system_health_include 0x01


#define RANDOMIZE_VALID 0x01
// #define SERIAL_DEBUG 0x01
