// the sensor communicates using SPI, so include the library:
#include <SPI.h>

// will use digital pin 33 instead of pin 10 
// because of the cirsumstnace of the airsense boards
const int select_slave = 33;
const int SPI_MAX_speed = 500000;   //2000000;  //250000;

uint8_t stat1, val1, val2, result;

byte buff[62];
byte SPI_read_byte = 0;

SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);

void setup() {
    SerialUSB.begin(115200);

    pinMode(select_slave, OUTPUT);
    SPI.begin();
}

void loop() 
{

	SPI_read_byte = SerialUSB.read();

	if (SPI_read_byte == 's')
	{
		SerialUSB.print("SPI_read_byte = start");
		// POWER OFF the device
	    SPI.beginTransaction(set1);
	    digitalWrite(select_slave, LOW);
	    delay(100);

	    val1 = SPI.transfer(0x03);
	    delay(20);
	    val2 = SPI.transfer(0x00);
	    delay(100);
	    
	    digitalWrite(select_slave, HIGH);
	    SPI.endTransaction();

	    SerialUSB.print(val1, HEX);
	    SerialUSB.print(val2, HEX);

	    SPI_read_byte = 'z';
	}

	else if (SPI_read_byte == 't')
	{
		SerialUSB.print("SPI_read_byte = stop");
	    // POWER ON the device
	    SPI.beginTransaction(set1);
	    digitalWrite(select_slave, LOW);
	    delay(100);

		val1 = SPI.transfer(0x03);
		delay(20);
	    val2 = SPI.transfer(0x01);
	    delay(100);

		digitalWrite(select_slave, HIGH);
	    SPI.endTransaction();

	    SerialUSB.print(val1, HEX);
	    SerialUSB.print(val2, HEX);

	   	SPI_read_byte = 'z';
	}

	else if (SPI_read_byte == 'f')
	{
		SerialUSB.print("SPI_read_byte = firmware");

		byte major = 0x00;
		byte minor = 0x00;
	    
	    SPI.beginTransaction(set1);
	    digitalWrite(select_slave, LOW);
	    
	    val1 = SPI.transfer(0x12);
	    val2 = SPI.transfer(0x12);
	    
	    digitalWrite(select_slave, HIGH);
	    SPI.endTransaction();

	    SerialUSB.print(val1, HEX);
	    SerialUSB.print(val2, HEX);

		SPI_read_byte = 'z';
	}
}