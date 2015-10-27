/*
 * HTU21D Humidity Sensor Example Code
 * By: Nathan Seidle
 * SparkFun Electronics
 * Date: September 15th, 2013
 * License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 *
 * Uses the HTU21D library to display the current humidity and temperature
 *
 * Open serial monitor at 9600 baud to see readings. Errors 998 if not sensor is detected. Error 999 if CRC is bad.
 *
 * Hardware Connections (Breakoutboard to Arduino):
 * -VCC = 3.3V
 * -GND = GND
 * -SDA = A4 (use inline 10k resistor if your board is 5V)
 * -SCL = A5 (use inline 10k resistor if your board is 5V)
 *
 */

#include <Wire.h>
#include "HTU21D.h"
#include <MCP79412RTC.h>    //http://github.com/JChristensen/MCP79412RTC
#include <Time.h>
#include <avr/wdt.h>

// light sensor
#define light_sensor A5

// Thermistors
#define Thermistor1 A0
#define Thermistor2 A1
#define Thermistor3 A2
#define Thermistor4 A3
#define Thermistor5 A4

// Power ports
#define POW1 4
#define POW_LATCH1 0

#define POW2 6
#define POW3 8
#define POW4 10
#define POW5 12

// HTU21D
HTU21D myHumidity;

//RTC

//Hearbeat and Reset lines.

#define HBT1 5
#define HBT2 7
#define HBT3 9
#define HBT4 11
#define HBT5 13

// Current Sensors
#define CURRENT_SYS 0x60
#define CURRENT_POW1 0x62
#define CURRENT_POW2 0x63
#define CURRENT_POW3 0x68
#define CURRENT_POW4 0x6A
#define CURRENT_POW5 0x6B
// Resolution of current sensors (with 8A range) (mA)
#define MILLIAMPS_PER_STEP 16

void setup()
{
    delay(5000);
    Serial.begin(115200);
    myHumidity.begin();
    pinMode(POW1, OUTPUT);
    pinMode(POW_LATCH1, OUTPUT);
    pinMode(POW2, OUTPUT);
    pinMode(POW3, OUTPUT);
    pinMode(POW4, OUTPUT);
    pinMode(POW5, OUTPUT);

    pinMode(HBT1, INPUT);
    pinMode(HBT2, INPUT);
    pinMode(HBT3, INPUT);
    pinMode(HBT4, INPUT);
    pinMode(HBT5, INPUT);

    Serial.println("Powering up Wagman...");
    if (analogRead(Thermistor5) == 0)
    {
        Serial.println("Power PORT 1 was found to be in OFF state.");
    }
    else
    {
        Serial.println("Power PORT 1 was found to be in ON state.");
    }

//     RTC.set(1445889890);


}


void turnON_POW1 () {
    digitalWrite(POW_LATCH1, LOW);
    //Setting state to ON
    digitalWrite(POW1, HIGH);
    delay(1);
    // giving raising clock edge
    digitalWrite(POW_LATCH1, HIGH);
    delay(1);
    // lowering clock edge
    digitalWrite(POW_LATCH1, LOW);
    delay(1);
}

void turnOFF_POW1 () {
    digitalWrite(POW_LATCH1, LOW);
    //Setting state to ON
    digitalWrite(POW1, LOW);
    delay(1);
    // giving raising clock edge
    digitalWrite(POW_LATCH1, HIGH);
    delay(1);
    // lowering clock edge
    digitalWrite(POW_LATCH1, LOW);
    delay(5);

}

void thermistor_read()
{
    Serial.print(analogRead(Thermistor1));
    Serial.print(',');
    delay(1);
    Serial.print(analogRead(Thermistor2));
    Serial.print(',');
    delay(1);
    Serial.print(analogRead(Thermistor3));
    Serial.print(',');
    delay(1);
    Serial.print(analogRead(Thermistor4));
    Serial.print(',');
    delay(1);
    Serial.println(analogRead(Thermistor5));
    delay(1);
}

void hbt_read()
{
    Serial.print(digitalRead(HBT1));
    Serial.print(',');
    delay(1);
    Serial.print(digitalRead(HBT2));
    Serial.print(',');
    delay(1);
    Serial.print(digitalRead(HBT3));
    Serial.print(',');
    delay(1);
    Serial.print(digitalRead(HBT4));
    Serial.print(',');
    delay(1);
    Serial.println(digitalRead(HBT5));
    delay(1);
}


int read_current(int addr)
{
    byte msb,csb,lsb, logged;
    // Start I2C transaction with current sensor

    logged = 0;
    do{

        Wire.beginTransmission(addr);
        // Tell sensor we want to read "data" register
        Wire.write(0);
        // Sensor expects restart condition, so end I2C transaction (no stop bit)
        Wire.endTransmission(0);
        // Ask sensor for data
        Wire.requestFrom(addr, 3);

        // Read the 3 bytes that the sensor returns
        if(Wire.available())
        {
            msb = Wire.read();
            // We only care about the data, so the mask hides the SYNC flag
            csb = Wire.read() & 0x01;
            lsb = Wire.read();
            logged = 1;
        }
        else
        {
            delay(500);
        }
    }while(logged == 0);

    // End I2C transaction (with stop bit)
    Wire.endTransmission(1);

    // Calculate milliamps from raw sensor data
    unsigned int milliamps = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;
    return milliamps;
}

void print_currentUsage(void)
{
    delay(5);
    Serial.print(read_current(CURRENT_SYS));
    Serial.print(',');
    delay(5);
    Serial.print(read_current(CURRENT_POW1));
    Serial.print(',');
    delay(5);
    Serial.print(read_current(CURRENT_POW2));
    Serial.print(',');
    delay(5);
    Serial.print(read_current(CURRENT_POW3));
    Serial.print(',');
    delay(5);
    Serial.print(read_current(CURRENT_POW4));
    Serial.print(',');
    delay(5);
    Serial.println(read_current(CURRENT_POW5));
    return;
}

void loop()
{

    float humd = myHumidity.readHumidity();
    float temp = myHumidity.readTemperature();
    //turnOFF_POW1();
    Serial.println("Resetting all power ports to OFF state.");
    delay(2000);


    Serial.println("Starting Checks...");
    delay(1000);
    Serial.print("Thermistor Checks (all values should be 0): ");
    thermistor_read();
    Serial.print('\n');
    delay(1000);
    Serial.print("Light sensor check (should be a value between 0 and 1023): ");
    Serial.println(analogRead(light_sensor));
    Serial.print('\n');
    delay(1000);
    Serial.print("HBT links check (all values should be 0): ");
    hbt_read();
    Serial.print('\n');
    delay(1000);

    Serial.print("Current Checks (All values less than 130):");
    print_currentUsage();
    Serial.print('\n');
    delay(1000);

    Serial.println("Powering ON all Ports:");
    turnON_POW1();
    digitalWrite(POW2, HIGH);
    digitalWrite(POW3, HIGH);
    digitalWrite(POW4, HIGH);
    digitalWrite(POW5, HIGH);
    delay(1000);


    Serial.print("Ports Power ON Check (All values should be 1023):");
    thermistor_read();
    Serial.print('\n');
    delay(1000);
    Serial.print("HBT links check (all values should be 1): ");
    hbt_read();
    Serial.print('\n');
    delay(1000);
    Serial.print("Current Checks (First value should be in the region of 175, others less than 130):");
    print_currentUsage();
    Serial.print('\n');
    delay(1000);
    Serial.println("Powering OFF all Ports...");
    delay(1000);
    //turnOFF_POW1();
    digitalWrite(POW2, LOW);
    digitalWrite(POW3, LOW);
    digitalWrite(POW4, LOW);
    digitalWrite(POW5, LOW);
    delay(1000);

    Serial.print("Ports Power OFF Check (All values should be 0):");
    thermistor_read();
    Serial.print('\n');
    delay(1000);
    Serial.print("HBT links check (all values should be 0): ");
    hbt_read();
    Serial.print('\n');
    delay(1000);
    Serial.print("Current Checks (All values less than 130):");
    print_currentUsage();
    Serial.print('\n');
    delay(1000);
    Serial.print("HTU21 Temperature and Humidity check: ");
    Serial.print(" Temperature:");
    Serial.print(temp, 1);
    Serial.print("C");
    Serial.print(" Humidity:");
    Serial.print(humd, 1);
    Serial.print("%");
    Serial.println('\n');
    delay(1000);
//     RTC.set(1445734146);
//     Serial.println("Set RTC clock to 1445734146 seconds.");
    Serial.print("RTC Time check: (We will read the time from the RTC for 5 consecutive seconds): ");
    delay(1000);
    for (int i =0; i<5; i++)
    {
        delay(995);
        Serial.print(RTC.get());
        Serial.print(" ");
    }

    Serial.println(" ");
    delay(1000);

    Serial.println("Setting up PORT1 to POWER ON state...");
    turnON_POW1();
    Serial.print("The port is powered ON, counting down to reboot to check if state is preserved : ");
    for (int i =0; i<10; i++)
    {
        delay(995);
        Serial.print(10-i);
        Serial.print(' ');
    }
    Serial.print("Rebooting...");
    delay(3000);
    wdt_enable(WDTO_120MS);
    while(1)
    {
        delay(5000);
    }

}

