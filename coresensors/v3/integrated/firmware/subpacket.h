
// Sub-packets for each format

#ifdef VERSION_INCLUDE
byte FIRMWARE_VERSION[LENGTH_FORMAT1 + LENGTH_BUILD_TIME + LENGTH_BUILD_GIT + 2];
#endif

#ifdef AIRSENSE_INCLUDE
byte MAC_ID[LENGTH_FORMAT3 + 2]; // MAC address

#ifdef I2C_SENSORS
byte TMP112[LENGTH_FORMAT6 + 2]; // ambient temp
byte HTU21D_array[(LENGTH_FORMAT6 * 2) + 2]; // ambient RH & temp
byte BMP180[LENGTH_FORMAT5 + LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte MMA8452Q[(LENGTH_FORMAT6 * 4) + 2]; // 3-axis accel for traffic flow
byte TSYS01[LENGTH_FORMAT6 + 2]; // ambient temp
#endif

#ifdef ANALOG_SENSORS
byte HIH4030[LENGTH_FORMAT1 + 2]; // humidity 
byte PR103J2[LENGTH_FORMAT1 + 2]; // light
byte TSL250RD_1[LENGTH_FORMAT1 + 2]; // ambient light (400-950nm)
byte SPV1840LR5HB[LENGTH_FORMAT1 + 2]; // sound pressure
#endif
#endif


#ifdef LIGHTSENSE_INCLUDE
#ifdef I2C_SENSORS
byte HMC5883L[(LENGTH_FORMAT8 * 3) + 2]; // magnetic field strength for traffic flow
byte HIH6130[(LENGTH_FORMAT6 * 2) + 2]; // temp and RH inside transparent box

byte APDS9006020[LENGTH_FORMAT1 + 2]; // ambient light inside cavity
byte TSL260RD[LENGTH_FORMAT1 + 2]; // solar near IR
byte TSL250RD_2[LENGTH_FORMAT1 + 2]; // solar visible light

byte MLX75305[LENGTH_FORMAT1 + 2]; // solar visible light
byte ML8511[LENGTH_FORMAT1 + 2]; // solar UV
byte TMP421[LENGTH_FORMAT6 + 2]; // temp inside transparent box
#endif
#endif


#ifdef CHEMSENSE_INCLUDE
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
#endif

#ifdef ALPHASENSE_INCLUDE
//** alphasensor
byte alpha_firmware[LENGTH_ALPHA_FIRMWARE + 2];
byte alpha_histogram[LENGTH_ALPHA_HISTOGRAM + 2];

byte alpha_config_a[LENGTH_ALPHA_CONFIG_A + 2];
byte alpha_config_b[LENGTH_ALPHA_CONFIG_B + 2];
byte alpha_config_c[LENGTH_ALPHA_CONFIG_C + 2];
byte alpha_config_d[LENGTH_ALPHA_CONFIG_D + 2];
#endif

// void sensor_buff_initialization();