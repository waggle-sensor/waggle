
//** integrated.ino
OneWire ds2401(PIN_DS2401);  //DS2401 PIN
byte I2C_READ_COMPLETE = true;
bool TIMER = true;		// TIMER FOR 24sec period of getting data from chemsense
bool UP_DOWN = false; 	//which is zero!!!!!!!
int count = 0;
int count_conf = 0;
int repeat = 0;


//************ common variables air, light, chem, TMP112, TSYS01, MMA84521, HIH, sensor_setup
uint16_t Temp_uint16;
int Temp_int[3];
long Temp_long; 
unsigned long Temp_ulong[2];
float Temp_float[3]; 
byte Temp_byte[8];
int i = 0;			//** CRC, air, light, chemsense, packet_assembler, MMA

//** chemsense
unsigned char INPUT_BYTE;
char KEY[4];
char VAL[13];
char first[6], second[6];
byte formatted_byte_temp[8];
int KEY_NUM_ID = 0;
int VAL_NUM_ID = 0;
bool flag_KEY = false;
bool flag_CHEM_WHILE = false;
int count_chem = 0;

//** lightsense
float prev_HMC[3];
float curr_HMC[3];

//** airsense
int prev_SPV = 0;
int curr_SPV = 0;
float prev_MMA[4];
float curr_MMA[4];

//** alphasensor
byte SPI_read_byte = 0;
SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
//** alphasensor which will be moved to down there and initialization (Jun 30)
uint8_t val1, val2;
int count_alpha = 0;

//** packet_assembler
int packet_whole_index = 0;
byte packet_seq_number = 0x00;

//** alpha_packet
bool flag_alpha= false;

//** OIX verification
int OIX_count = 0;
int OIX_packet_count = 0;
int arb = 0;


//** store formatted values, dataFormat.ino ********************************************************** FORMATS FOR VALUES
byte formatted_data_buffer[MAX_FMT_SIZE];




//************************ Sub-packets for each format
//** Airsense board
byte MAC_ID[LENGTH_FORMAT3 + 2]; // MAC address

byte TMP112[LENGTH_FORMAT6 + 2]; // ambient temp
byte HTU21D_array[(LENGTH_FORMAT6 * 2) + 2]; // ambient RH & temp

byte HIH4030[LENGTH_FORMAT1 + 2]; // humidity 

byte BMP180[LENGTH_FORMAT5 + LENGTH_FORMAT6 + 2]; // atmospheric pressure
byte PR103J2[LENGTH_FORMAT1 + 2]; // light
byte TSL250RD_1[LENGTH_FORMAT1 + 2]; // ambient light (400-950nm)

byte MMA8452Q[(LENGTH_FORMAT6 * 4) + 2]; // 3-axis accel for traffic flow
byte SPV1840LR5HB[LENGTH_FORMAT1 + 2]; // sound pressure
byte TSYS01[LENGTH_FORMAT6 + 2]; // ambient temp

//** Lightsense board
byte HMC5883L[(LENGTH_FORMAT8 * 3) + 2]; // magnetic field strength for traffic flow
byte HIH6130[(LENGTH_FORMAT6 * 2) + 2]; // temp and RH inside transparent box

byte APDS9006020[LENGTH_FORMAT1 + 2]; // ambient light inside cavity
byte TSL260RD[LENGTH_FORMAT1 + 2]; // solar near IR
byte TSL250RD_2[LENGTH_FORMAT1 + 2]; // solar visible light

byte MLX75305[LENGTH_FORMAT1 + 2]; // solar visible light
byte ML8511[LENGTH_FORMAT1 + 2]; // solar UV
byte TMP421[LENGTH_FORMAT6 + 2]; // temp inside transparent box

//** chemsense board
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

//** alphasensor
byte alpha_firmware[LENGTH_ALPHA_FIRMWARE + 2];
byte alpha_histogram[LENGTH_ALPHA_HISTOGRAM + 2];

byte alpha_config_a[LENGTH_ALPHA_CONFIG_A + 2];
byte alpha_config_b[LENGTH_ALPHA_CONFIG_B + 2];
byte alpha_config_c[LENGTH_ALPHA_CONFIG_C + 2];
byte alpha_config_d[LENGTH_ALPHA_CONFIG_D + 2];



//** Whole packet
byte packet_whole[LENGTH_WHOLE];
// byte sensor_health[SENSOR_HEALTH_SIZE+2];
// ************************************************************************************************ FORMATS FOR VALUES
