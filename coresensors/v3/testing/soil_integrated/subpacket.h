
// Sub-packets for each format
#ifdef DECAGON_INCLUDE
byte DECAGON[LENGTH_FORMAT6 * 3 + 2];  // three float data
#endif

#ifdef RAIN_GAUGER_INCLUDE
byte RAIN_GAUGER[LENGTH_FORMAT1 + 2]; // one int data (2 bytes)
#endif