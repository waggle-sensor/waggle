/**
 ** soil.ino
 **/

// const byte ledPin = 13;
const byte interruptPin = 39;
volatile byte state = LOW;

volatile int pin_sinal = 0;
volatile int count_num = 0;

void setup()
{
	SerialUSB.begin(115200);

    // pinMode(ledPin, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
	pin_sinal = 0;
}

void loop()
{
	if (state == HIGH)
	{
		SerialUSB.print("count_num");
		SerialUSB.println(count_num);
		SerialUSB.print("pin_sinal :");
		SerialUSB.println(pin_sinal);
		state = LOW;
	}
  // digitalWrite(ledPin, state);
}

void blink()
{
	state = HIGH;
	pin_sinal++;
	if (pin_sinal == 2)
	{
		count_num++;
		pin_sinal = 0;
	}
    // state != state;
    // Serial.print("Hello world");
}

// Another interrupt, a timer, if the tip has not been moved for 30 mins, reset count as 0