/**
 ** soil_integrated.ino
 **/

#include "./libs/DueTimer/DueTimer.h"   //** TIMER3 library
#include "./config.cpp"
#include "./soil_variables.h"
#include "./subpacket.h"


void setup()
{
	pinMode(TRIDENT_POWER, OUTPUT);
	pinMode(RAIN_INTERRUPT_PIN, INPUT_PULLUP);

	// SerialUSB.begin(1200);
	SerialUSB.begin(USBSERIAL_INTERFACE_DATARATE);
	Serial1.begin(DECAGON_DATARATE);

	sensor_buff_initialization();

	attachInterrupt(digitalPinToInterrupt(RAIN_INTERRUPT_PIN), blink, RISING);
	Timer3.attachInterrupt(handler).setPeriod(1000000 * 1).start();

	pin_signal = 0;
}

void loop()
{
#ifdef DECAGON_INCLUDE
	acquire_trident();
#endif


#ifdef RAIN_GAUGER_INCLUDE
	acquire_rain();

	// no_rain_check++;

	if ((count_num != 0 && no_rain_check == 100) || (count_num == 1 && no_rain_check == 4)) // calc 10 mins || 24 sec
		rain_initialization();
#endif
}

void handler()
{
	count++;
}

void blink()
{
	pin_signal++;
	if (pin_signal == 2)
	{
		count_num++;
		pin_signal = 0;
	}
}

// if the tip has not been moved for 30 mins, reset count as 0