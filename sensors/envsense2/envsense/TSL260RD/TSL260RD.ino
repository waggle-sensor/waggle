void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(A2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A2);
  Serial.println(x);
  delay(500);
} 
