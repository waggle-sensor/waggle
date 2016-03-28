#include "config.cpp"

int question_no = 1;
byte HBT_VALUE;
byte HBT_VALUE_OLD = 0;
byte success = 0;

void setup()
{
    delay(1000);
    set_up_pinmodes();
    delay(1000);
    turnON_POW3();
    Serial.begin(115200);
    delay(4000);
}




void loop()

{
    Serial.println("------Airsense Heartbeat Test------");
    Serial.println("");
    Serial.print(question_no++); Serial.print(". ");
    Serial.print("Heartbeat test:");
    for (int test_time = 0; test_time < 100; test_time ++)
    {
        HBT_VALUE = digitalRead(PIN_HBT3);
        if ((HBT_VALUE == 0 ) && (HBT_VALUE_OLD == 1)) // waiting for a negative edge, the first edge will be a positive edge.
        {
            success = 1;
            delay(10);
            break;
        }
        HBT_VALUE_OLD = HBT_VALUE;
        delay(100);
    }

    if (success == 1)
    {
        Serial.print("PASS");
    }
    else
    {
        Serial.print("FAIL");
    }
    Serial.println("\n");
    Serial.println("------End of Test------");
    while(1)
    {
        delay(100);
    }
}


