#define SPV_1_SPL 6
#define SPV_1_AMP 5
unsigned int SPV_1_AMPV, SPV_1_SPLV;

void setup()
{
    delay(5000);
    SerialUSB.begin(115200);          //  setup serial
}


void loop()

{
    SPV_1_SPLV = analogRead(SPV_1_SPL);
    SPV_1_AMPV = analogRead(SPV_1_AMP);
    SerialUSB.print(SPV_1_AMPV);
    SerialUSB.print(" ");
    SerialUSB.println(SPV_1_SPLV);
    delay(100);
}
