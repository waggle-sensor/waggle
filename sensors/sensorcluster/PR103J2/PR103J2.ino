#define A2D_PRJ103J2 0
int PRJ103J2 = 0;           // variable to store the value read

void setup()
{
    delay(5000);
    SerialUSB.begin(115200);          //  setup serial
}



void loop()

{
    PRJ103J2 = analogRead(A2D_PRJ103J2);
    SerialUSB.println(PRJ103J2);
    delay(1000);
}