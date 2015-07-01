/*
 * Query a SHT10 temperature and humidity sensor
 *
 * A simple example that queries the sensor every 5 seconds
 * and communicates the result over a serial connection.
 * Error handling is omitted in this example.
 */

#include <Sensirion.h>

const uint8_t dataPin  =  2;
const uint8_t clockPin =  3;

float temperature;
float humidity;
float dewpoint;

Sensirion tempSensor = Sensirion(dataPin, clockPin);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  tempSensor.measure(&temperature, &humidity, &dewpoint);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Dewpoint: ");
  Serial.print(dewpoint);
  Serial.println(" C");
  
  delay(5000);  
}
