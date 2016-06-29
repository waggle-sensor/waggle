// the sensor communicates using SPI, so include the library:
#include <SPI.h>

// //Sensor's memory register addresses:
// const int PRESSURE = 0x1F;      //3 most significant bits of pressure
// const int PRESSURE_LSB = 0x20;  //16 least significant bits of pressure
// const int TEMPERATURE = 0x21;   //16 bit temperature reading
// const byte READ = 0b11111100;     // SCP1000's read command
// const byte WRITE = 0b00000010;   // SCP1000's write command
// 
// // pins used for the connection with the sensor
// // the other you need are controlled by the SPI library):
// const int dataReadyPin = 6;
// const int chipSelectPin = 7;
const int select_slave = 4;
const int SPI_MAX_speed = 250000;//500000;

unsigned int ret = -1;

byte buff[62];
byte SPI_read_byte = 0;

SPISettings set1(SPI_MAX_speed, LSBFIRST, SPI_MODE1);

void setup() {
    SerialUSB.begin(115200);

    pinMode(select_slave, OUTPUT);
    digitalWrite(select_slave, HIGH);
    // start the SPI library:
   

    SPI.begin();
	//SPI.setClockDivider(10, 168);

    //   // initalize the  data ready and chip select pins:
    //   pinMode(dataReadyPin, INPUT);
    //   pinMode(chipSelectPin, OUTPUT);
    // 
    //   //Configure SCP1000 for low noise configuration:
    //   writeRegister(0x02, 0x2D);
    //   writeRegister(0x01, 0x03);
    //   writeRegister(0x03, 0x02);
    //   // give the sensor time to set up:
    delay(100);
}

void loop() 
{
    //Select High Resolution Mode
	while (SerialUSB.available() > 0)
	{
		SPI_read_byte = SerialUSB.read();

		if (SPI_read_byte == 's')
		{
			SerialUSB.print("SPI_read_byte = start");
			// POWER OFF the device
		    SPI.beginTransaction(set1);
		    digitalWrite(select_slave, LOW);
		    delay(100);
		    SPI.transfer(0x03);
		    SPI.transfer(0x00);
		    ret = SPI.transfer(0x00);
		    delay(100);
		    digitalWrite(select_slave, HIGH);
		    SPI.endTransaction();
	
		    if (ret != -1)
		    {
		        SerialUSB.print("SPI 0x03 0x00 ");
		        SerialUSB.print(ret, HEX);
		        SerialUSB.println("finish");
		        delay(1000);
		        ret = -1;
		    }
		    SPI_read_byte = 'z';
		}

		else if (SPI_read_byte == 't')
		{
			SerialUSB.print("SPI_read_byte = stop");
		    // POWER ON the device
		    SPI.beginTransaction(set1);
		    digitalWrite(select_slave, LOW);
		    delay(100);
		    //ret = SPI.transfer(10, 0x03, SPI_CONTINUE);
		    //ret = SPI.transfer(10, 0x00);
			SPI.transfer(0x03);
		    SPI.transfer(0x01);
		    ret = SPI.transfer(0x00);
		    delay(100);
		    digitalWrite(select_slave, HIGH);
		    SPI.endTransaction();

		    if (ret != -1)
		    {
		        SerialUSB.print("SPI 0x03 0x01 ");
		        SerialUSB.print(ret, HEX);
		        SerialUSB.println(" finish");
		        delay(1000);
		        ret = -1;
		    }
		   	SPI_read_byte = 'z';
		}

		else if (SPI_read_byte == 'f')
		{
			SerialUSB.print("SPI_read_byte = firmware");
			byte major = 0x00;
			byte minor = 0x00;
		    SPI.beginTransaction(set1);
		    digitalWrite(select_slave, LOW);
		    //ret = SPI.transfer(10, 0x03, SPI_CONTINUE);
		    //ret = SPI.transfer(10, 0x00);
			SPI.transfer(0x12);
		    ret = SPI.transfer(0x12);
		    delay(10);
		    major = SPI.transfer(0x12);
		    delay(10);
		    minor = SPI.transfer(0x12);
		    digitalWrite(select_slave, HIGH);
		    SPI.endTransaction();

		    if (ret != -1)
		    {
		        SerialUSB.print("SPI 0x12 0x12 ");
		        SerialUSB.print(ret, HEX);
		        SerialUSB.print(major, HEX);
		        SerialUSB.print(minor, HEX);
		        SerialUSB.println(" finish");
		        delay(1000);
		        ret = -1;
		    }
			SPI_read_byte = 'z';
		}
   }


	// // GET CONFIGURATION DATA
 //    SPI.beginTransaction(SPISettings(SPI_MAX_speed, LSBFIRST, SPI_MODE1));
 //    digitalWrite(select_slave, LOW);
 //    SPI.transfer(0x3F);
 //    for (int i = 0; i < 60; i++)
 //    {
 //        ret = SPI.transfer(0x3F);
 //        SerialUSB.print("idx: ");
 //        SerialUSB.print(i);
 //        SerialUSB.print(" VAL: ");
 //        SerialUSB.print(ret);
 //        SerialUSB.println(" DEVICE INFO");
 //        ret = -1;
 //        delay(1);
 //    }
 //    digitalWrite(select_slave, HIGH);
 //    SPI.endTransaction();

 //    // GET HISTOGRAM DATA
 //    SPI.beginTransaction(SPISettings(SPI_MAX_speed, LSBFIRST, SPI_MODE1));
 //    digitalWrite(select_slave, LOW);
 //    SPI.transfer(0x30);
 //    delay(10);
 //    for (int i = 0; i < 62; i++)
 //    {
 //        ret = SPI.transfer(0x30);
 //        SerialUSB.print("idx: ");
 //        SerialUSB.print(i);
 //        SerialUSB.print(" VAL: ");
 //        SerialUSB.print(ret);
 //        SerialUSB.println(" HISTOGRAM");
 //        ret = -1;
 //        delay(10);
 //    }
 //    SPI.endTransaction();
    
 //    digitalWrite(select_slave, HIGH);
 //    SPI.endTransaction();

//     
  // don't do anything until the data ready pin is high:
//   if (digitalRead(dataReadyPin) == HIGH) {
//     //Read the temperature data
//     int tempData = readRegister(0x21, 2);
// 
//     // convert the temperature to celsius and display it:
//     float realTemp = (float)tempData / 20.0;
//     Serial.print("Temp[C]=");
//     Serial.print(realTemp);
// 
// 
//     //Read the pressure data highest 3 bits:
//     byte  pressure_data_high = readRegister(0x1F, 1);
//     pressure_data_high &= 0b00000111; //you only needs bits 2 to 0
// 
//     //Read the pressure data lower 16 bits:
//     unsigned int pressure_data_low = readRegister(0x20, 2);
//     //combine the two parts into one 19-bit number:
//     long pressure = ((pressure_data_high << 16) | pressure_data_low) / 4;
// 
//     // display the temperature:
//     Serial.println("\tPressure [Pa]=" + String(pressure));
//   }
}

// //Read from or write to register from the SCP1000:
// unsigned int readRegister(byte thisRegister, int bytesToRead) {
//   byte inByte = 0;           // incoming byte from the SPI
//   unsigned int result = 0;   // result to return
//   Serial.print(thisRegister, BIN);
//   Serial.print("\t");
//   // SCP1000 expects the register name in the upper 6 bits
//   // of the byte. So shift the bits left by two bits:
//   thisRegister = thisRegister << 2;
//   // now combine the address and the command into one byte
//   byte dataToSend = thisRegister & READ;
//   Serial.println(thisRegister, BIN);
//   // take the chip select low to select the device:
//   digitalWrite(chipSelectPin, LOW);
//   // send the device the register you want to read:
//   SPI.transfer(dataToSend);
//   // send a value of 0 to read the first byte returned:
//   result = SPI.transfer(0x00);
//   // decrement the number of bytes left to read:
//   bytesToRead--;
//   // if you still have another byte to read:
//   if (bytesToRead > 0) {
//     // shift the first byte left, then get the second byte:
//     result = result << 8;
//     inByte = SPI.transfer(0x00);
//     // combine the byte you just got with the previous one:
//     result = result | inByte;
//     // decrement the number of bytes left to read:
//     bytesToRead--;
//   }
//   // take the chip select high to de-select:
//   digitalWrite(chipSelectPin, HIGH);
//   // return the result:
//   return (result);
// }
// 
// 
// //Sends a write command to SCP1000
// 
// void writeRegister(byte thisRegister, byte thisValue) {
// 
//   // SCP1000 expects the register address in the upper 6 bits
//   // of the byte. So shift the bits left by two bits:
//   thisRegister = thisRegister << 2;
//   // now combine the register address and the command into one byte:
//   byte dataToSend = thisRegister | WRITE;
// 
//   // take the chip select low to select the device:
//   digitalWrite(chipSelectPin, LOW);
// 
//   SPI.transfer(dataToSend); //Send register location
//   SPI.transfer(thisValue);  //Send value to record into register
// 
//   // take the chip select high to de-select:
//   digitalWrite(chipSelectPin, HIGH);
// }