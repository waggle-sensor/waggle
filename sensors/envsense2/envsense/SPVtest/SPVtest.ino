void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(A5,INPUT);
pinMode(A6,INPUT);
delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  SerialUSB.println("A5");
SerialUSB.println(analogRead(A5));
SerialUSB.println("A6");
SerialUSB.println(analogRead(A6));
delay(300);
}
