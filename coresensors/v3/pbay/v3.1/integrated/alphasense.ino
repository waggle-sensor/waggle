// the sensor communicates using SPI, so include the library:
// #include <SPI.h>

// // will use digital pin 33 instead of pin 10 
// // because of the cirsumstnace of the airsense boards
// const int select_slave = 33;
// const int SPI_MAX_speed = 500000;   //2000000;  //250000;

// uint8_t stat1, val1, val2, result;

// byte buff[62];
// byte SPI_read_byte = 0;

// SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);

// void setup() {
//     SerialUSB.begin(115200);

//     pinMode(select_slave, OUTPUT);
//     SPI.begin();
// }

void alphasense_on() 
{
	//** POWER ON
	SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    val1 = SPI.transfer(0x03);
    delay(20);
    val2 = SPI.transfer(0x00);
    delay(100);
    
    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

//     SerialUSB.print(val1, HEX);
//     SerialUSB.print(val2, HEX);
// 
}

void alphasense_off()
{
    //** POWER OFF
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

	val1 = SPI.transfer(0x03);
	delay(20);
    val2 = SPI.transfer(0x01);
    delay(100);

	digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

    // SerialUSB.print(val1, HEX);
    // SerialUSB.print(val2, HEX);
}

void alphasense_firmware()
{
	//** Get firmware    
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);
    
    SPI.transfer(0x12);    // 0xF3
    delay(20);

    alpha_firmware[0] = SPI.transfer(0x12);
    delay(20);
    alpha_firmware[2] = SPI.transfer(0x12);
    delay(100);

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

    SerialUSB.print(alpha_firmware[0], HEX);
    SerialUSB.print(alpha_firmware[1], HEX);
}

void alphasense_histo()
{
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    SPI.transfer(0x30);   // 0xF3
    delay(20);
    
    for (i = 0; i < 62; i++)
    {
	    alpha_config[i] = SPI.transfer(0x30);
	    delay(10);
	    SerialUSB.print(alpha_config[i]);
	}
	delay(90);

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();	
}

void alphasense_config()
{
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    SPI.transfer(0x3C);   // 0xF3
    delay(20);
    
    for (i = 0; i < 256; i++)
    {
	    alpha_config[i] = SPI.transfer(0x3C);
	    delay(10);
	    SerialUSB.print(alpha_config[i]);
	}
	delay(90);

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();
}