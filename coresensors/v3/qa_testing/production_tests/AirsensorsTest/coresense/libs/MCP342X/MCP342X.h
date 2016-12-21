#ifndef MCP342X_H
#define MCP342X_H

#include <Arduino.h>

class MCP342X {
public:
	static const byte L = 0;
	static const byte H = 1;
	static const byte F = 2;

	static const byte CHANNEL_0 = 0;
	static const byte CHANNEL_1 = 1;
	static const byte CHANNEL_2 = 2;
	static const byte CHANNEL_3 = 3;

	static const byte GAIN_1 = 0;
	static const byte GAIN_2 = 1;
	static const byte GAIN_4 = 2;
	static const byte GAIN_8 = 3;

	void init(byte A0, byte A1);
	void selectChannel(byte channel, byte gain = GAIN_1);
	unsigned int readADC();
private:
	//communication register
	static const byte BIT_RDY = 7; //data ready
	static const byte BIT_C1 = 6; //channel select
	static const byte BIT_C0 = 5; //channel select
	static const byte BIT_OC = 4; //conversion mode (one shot/continuous)
	static const byte BIT_S1 = 3; //sample rate
	static const byte BIT_S0 = 2; //sample rate
	static const byte BIT_G1 = 1; //gain
	static const byte BIT_G0 = 0; //gain

    #define VRef 2.048
	byte I2C_ADDRESS;
};
#endif
