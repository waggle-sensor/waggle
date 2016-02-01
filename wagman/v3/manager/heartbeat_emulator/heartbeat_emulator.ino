void setup() {
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  //delay(10000);
  //digitalWrite(12, LOW);
}

void loop() {
  digitalWrite(12, HIGH);
  delay(20);
  digitalWrite(12, LOW);
  delay(20);
}
