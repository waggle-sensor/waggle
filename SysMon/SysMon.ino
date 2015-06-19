#include <avr/io.h>

// Debug
static byte LED = 13;

void setup() {
	// Debug
	pinMode(LED, OUTPUT);
	digitalWrite(LED, HIGH);
	POST();
	//digitalWrite(LED, LOW);
}

void loop() {

}