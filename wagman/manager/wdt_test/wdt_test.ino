#include <avr/wdt.h>

void setup() {
  MCUSR = 0;
  wdt_disable();
  Serial.begin(57600);
  delay(5000);
  Serial.println("Starting");
  Serial.flush();
  wdt_enable(WDTO_8S);
}

void loop() {
  Serial.println("loop");
  delay(1000);
}
