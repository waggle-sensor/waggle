
//** integrated.ino
#ifdef I2C_INTERFACE
	byte I2C_READ_COMPLETE = true;
#endif
OneWire ds2401(PIN_DS2401);  //DS2401 PIN
bool TIMER = true;		// TIMER FOR 24sec period of getting data from chemsense
bool UP_DOWN = false; 	//which is zero!!!!!!!
// bool RAIN_CHECK = false;    // no use

int count = 0;
int count_conf = 0;


//************ common variables air, light, chem, TMP112, TSYS01, MMA84521, HIH, sensor_setup
uint16_t Temp_uint16;
int Temp_int[3];
long Temp_long; 
unsigned long Temp_ulong[2];
float Temp_float[3]; 
byte Temp_byte[8];
int i = 0;			//** CRC, air, light, chemsense, packet_assembler, MMA

//************ airsense
float TMP112_float;
float HTU21D_float[2];
float BMP180_float;
long BMP180_long;
float MMA_float[4];
float TSYS_float;
uint16_t HIH4030_uint16;
uint16_t PR_uint16;
uint16_t TSL250_1_uint16;
uint16_t SPV_uint16;

//************ lightsense
float HMC_float[3];
float HIH6130_float[2];
uint16_t APDS_uint16;
uint16_t TSL260_uint16;
uint16_t TSL250_2_uint16;
uint16_t MLX753_uint16;
uint16_t ML8511_uint16;
float TMP421_float;



//** chemsense
#ifdef CHEMSENSE_INCLUDE
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
#endif

//** alphasensor
#ifdef ALPHASENSE_INCLUDE
byte SPI_read_byte = 0;
SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
//** alphasensor which will be moved to down there and initialization (Jun 30)
uint8_t val1, val2;
//** alpha_packet
bool flag_alpha= false;
#endif

//** packet_assembler
int packet_whole_index = 0;
byte packet_seq_number = 0x00;


//** store formatted values, dataFormat.ino ************** FORMATS FOR VALUES
//** Whole packet
byte packet_whole[LENGTH_WHOLE];
byte formatted_data_buffer[MAX_FMT_SIZE];
// byte sensor_health[SENSOR_HEALTH_SIZE+2];