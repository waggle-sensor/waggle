
#include "./libs/DueTimer/DueTimer.h"   //** TIMER3 library

const byte trident_power = 38; // one of any ditial pins
const byte trident_data = 19; // Serial RX1 to use Serial1 communication

volatile bool UP_DOWN = false;

int count = 0;

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

void setup()
{
	pinMode(trident_power, OUTPUT);
	SerialUSB.begin(1200);
	Serial1.begin(1200);
    Timer3.attachInterrupt(handler).setPeriod(1000000 * 1).start();
}

void initialization()
{
	count = 0;

	data_char = 0;
	data_int = 0;

	for (int i = 0; i < 25; i++)
		data_string[i] = char(32);
	input_num = 0;

	checksum = 0;

	crc_int = 0;
	crc_char = 0;

	data_int = 0;

	checkZ = true;
	crc_byte = false;

	param = 0;
	last = 0;
}

void calc_crc()
{
	crc_int = checksum % 64 + 32;
	crc_char = char(crc_int);
}

void parameters()
{
	int Temp_uint16 = 0;

	for (int i = last; i < (input_num - 1); i++)
	{
		if (data_string[i] < '0' || data_string[i] > '9')
			continue;

		SerialUSB.print(data_string[i]);

		data_string[i] = data_string[i] - '0';
		Temp_uint16 = (Temp_uint16 * 10) + data_string[i];
	}

	SerialUSB.print("converted");
	SerialUSB.print("\t");
	SerialUSB.println(Temp_uint16);

	if (param == 0)
	{
		dielectric = float(Temp_uint16) / 50.000000;

		SerialUSB.print("dielectric");
		SerialUSB.print("\t");
		SerialUSB.println(dielectric);
	}
	else if (param == 1)
	{
		if (Temp_uint16 < 700)
			conductivity = float(Temp_uint16) / 100.0;
		else
			conductivity = (float(Temp_uint16) - 700.0) * 5 + 700;

		SerialUSB.print("conductivity");
		SerialUSB.print("\t");
		SerialUSB.println(conductivity);
	}
	else if (param == 2)
	{
		if (Temp_uint16 < 900)
			temperature = (float(Temp_uint16) - 400.0) / 10.0;
		else
			temperature = (float(Temp_uint16) - 900) * 5 + 900;

		SerialUSB.print("temperature");
		SerialUSB.print("\t");
		SerialUSB.println(temperature);
	}

	last = input_num;
	param++;
}


void loop()
{
	if (count == 5)
	{
		UP_DOWN = true;
		digitalWrite(trident_power, UP_DOWN);
		delay(100);

		while (count < 9)
		{
			if (Serial1.available() > 0)
			{
				data_int = Serial1.read();
				data_char = char(data_int);
				
				input_data += data_char;
				data_string[input_num] = data_char;
				input_num++;

				if (data_int == 32)
					parameters();

				if (crc_byte == true)
				{
					crc_from = data_char;
					crc_byte = false;
				}

				if (data_int == 122)
				{
					parameters();

					checksum += data_int;
					checkZ = false;
					crc_byte = true;
				}

				if (checkZ == true)
					checksum += data_int;
			}
		}

		calc_crc();

		if (crc_char == crc_from)
		{
			// Then send this as a subpacket

			SerialUSB.println("MATCH");
			SerialUSB.print("String");
			SerialUSB.print("\t");
			SerialUSB.println(data_string);
		}


		UP_DOWN = false;
		digitalWrite(trident_power, UP_DOWN);

		initialization();
	}
}

void handler()
{
    count++;
}

// unsigned int reverse(register unsigned int x)
// {
// 	x = (((x & 0xaa) >> 1) | ((x & 0x55) << 1));
// 	x = (((x & 0xcc) >> 2) | ((x & 0x33) << 2));
// 	x = (((x & 0xf0) >> 4) | ((x & 0x0f) << 4));
// 	return x;
// }