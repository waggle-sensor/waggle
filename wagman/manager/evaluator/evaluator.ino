#define r1 4
#define r2 6
#define r3 8
#define r4 10
#define r5 12

#define D1 10000
#define D2 1000
int times = 0;
void setup()
{
  delay(10000);
  Serial.begin(115200);
  pinMode(r1, OUTPUT);      // sets the digital pin as output
  pinMode(r2, OUTPUT);      // sets the digital pin as output
  pinMode(r3, OUTPUT);      // sets the digital pin as output
  pinMode(r4, OUTPUT);      // sets the digital pin as output
  pinMode(r5, OUTPUT);      // sets the digital pin as output
}

void loop()
{

  digitalWrite(r1, HIGH);   // sets the LED on
  delay(D2);                  // waits for a second
  digitalWrite(r2, HIGH);   // sets the LED on
  delay(D2);                  // waits for a second
  digitalWrite(r3, HIGH);   // sets the LED on
  delay(D2);                  // waits for a second
  digitalWrite(r4, HIGH);   // sets the LED on
  delay(D2);                  // waits for a second
  digitalWrite(r5, HIGH);   // sets the LED on

  delay(D1);                  // waits for a second

  digitalWrite(r1, LOW);    // sets the LED off
  digitalWrite(r2, LOW);    // sets the LED off
  digitalWrite(r3, LOW);    // sets the LED off
  digitalWrite(r4, LOW);    // sets the LED off
  digitalWrite(r5, LOW);    // sets the LED off

  delay(D2);                  // waits for a second
//  Serial.println(times);
//  times++;
}
