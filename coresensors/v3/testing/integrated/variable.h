
//** integrated.ino
#ifdef I2C_INTERFACE
	byte I2C_READ_COMPLETE = true;
#endif

OneWire ds2401(PIN_DS2401);  //DS2401 PIN
bool TIMER = true;		// TIMER FOR 24sec period of getting data from chemsense
bool UP_DOWN = false; 	//which is zero!!!!!!!
int count = 0;
int count_conf = 0;
int repeat = 0;

bool serial_available = false;
bool modulate_beat_rate = false;


//************ common variables air, light, chem, TMP112, TSYS01, MMA84521, HIH, sensor_setup
uint16_t Temp_uint16;
int Temp_int[3];
long Temp_long; 
unsigned long Temp_ulong[2];
float Temp_float[3]; 
byte Temp_byte[8];
int i = 0;			//** CRC, air, light, chemsense, packet_assembler, MMA

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

//** lightsense
float prev_HMC[3];
float curr_HMC[3];

//** airsense
int prev_SPV = 0;
int curr_SPV = 0;
float prev_MMA[4];
float curr_MMA[4];
float prev_TSYS01 = 0;
float curr_TSYS01 = 0;

//** alphasensor
#ifdef ALPHASENSE_INCLUDE
byte SPI_read_byte = 0;
SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
//** alphasensor which will be moved to down there and initialization (Jun 30)
uint8_t val1, val2;
int count_alpha = 0;
//** alpha_packet
bool flag_alpha= false;
#endif

//** packet_assembler
int packet_whole_index = 0;
byte packet_seq_number = 0x00;


//** store formatted values, dataFormat.ino ***************** FORMATS FOR VALUES
//** Whole packet
byte packet_whole[LENGTH_WHOLE];
byte formatted_data_buffer[MAX_FMT_SIZE];
// byte sensor_health[SENSOR_HEALTH_SIZE+2];