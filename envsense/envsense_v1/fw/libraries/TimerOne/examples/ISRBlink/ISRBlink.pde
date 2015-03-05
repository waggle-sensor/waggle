#include <TimerOne.h>
 
void setup() 
{
	Serial.begin(9600);
	Serial.println("Setup begun");
  // Initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards
  pinMode(13, OUTPUT);    
  
  Timer1.initialize(100000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here
  Serial.println("Setup finished");
}
 
void loop()
{
	int total = 0;
  // Main code loop
  // TODO: Put your regular (non-ISR) logic here
	Serial.println("Running loop: ");
	for (int n = 0; n < 10; n++) {
		Serial.println(n);
		total += n;
	}
	Serial.println(total);
	delay(1000);
}
 
/// --------------------------
/// Custom ISR Timer Routine
/// --------------------------
void timerIsr()
{
  // Toggle LED
  digitalWrite( 13, digitalRead( 13 ) ^ 1 );
}