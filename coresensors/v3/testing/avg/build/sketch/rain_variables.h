// soil_integrated
int no_rain_check = 0;


// rain gauger 3 variables

#ifdef RAIN_GAUGER_INCLUDE
int pin_signal = 0;
int count_num = 0;

int tip_count = 0;

uint16_t rain_monitor = 500;
#endif


// 5TE sensor variables

#ifdef DECAGON_INCLUDE
bool PWR_UP_DOWN = false;

int count_trident = 0;

int data_int = 0;
char data_char = 0;

char data_string[25];
int input_num = 0;

int checksum = 0;

int crc_int = 0;
char crc_char = 0;
char crc_from = 0;

bool checkZ = true;
bool crc_byte = false;

float dielectric = 0.0;
float conductivity = 0.0;
float temperature = 0.0;

int param = 0;
int last = 0;
#endif
