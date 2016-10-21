// #include "./subpacket.h"

void sensor_buff_initialization()
{
// Sub-packets for each format
#ifdef DECAGON_INCLUDE
	DECAGON[0] = ID_DECAGON;  // three float data
	DECAGON[1] = (0 << 7) | (LENGTH_FORMAT6 * 3);
#endif

#ifdef RAIN_GAUGER_INCLUDE
	RAIN_GAUGER[0] = ID_RAIN_GAUGER; // one int data (2 bytes)
	RAIN_GAUGER[1] = (0 << 7) | LENGTH_FORMAT1;
#endif
}
