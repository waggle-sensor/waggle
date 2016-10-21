
#define USBSERIAL_INTERFACE_DATARATE 115200
#define DECAGON_DATARATE 1200


#define LENGTH_FORMAT1  2
#define LENGTH_FORMAT2  2
#define LENGTH_FORMAT3  6
#define LENGTH_FORMAT4  3
#define LENGTH_FORMAT5  3
#define LENGTH_FORMAT6  2
#define LENGTH_FORMAT7  4
#define LENGTH_FORMAT8  2


// rain gauger 3 variables
#define RAIN_INTERRUPT_PIN	39

// 5TE sensor variables
#define TRIDENT_POWER		38 // one of any ditial pins
// #define TRIDENT_DATA		19 // Serial RX1 to use Serial1 communication --> automatically detected



#define RAIN_GAUGER_INCLUDE 0x01
#define DECAGON_INCLUDE 0x01

#ifdef DECAGON_INCLUDE
	#define ID_DECAGON	0xFB
#endif

#ifdef RAIN_GAUGER_INCLUDE
	#define ID_RAIN_GAUGER	0xFC
#endif
