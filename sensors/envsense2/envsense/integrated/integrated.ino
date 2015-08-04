unsigned char buffer [150];
unsigned char parameter[15];
unsigned char cnt = 0;
boolean ready = false;

void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);
}

void loop() {
    while (Serial1.available()) {
        char inByte = Serial1.read();
        Serial.write(inByte);
        if ( inByte != '\n')
        {
            buffer[cnt] = inByte;
            cnt = cnt + 1;
        }
        else
        {
            ready = true;
            cnt = cnt + 1;
        }
    }
    if (ready == true)
    {
        ready = false;
        unsigned char count = 0, pidx = 0;
        for (unsigned char index = 0; index < cnt; index ++)
        {
            if (buffer[index] != ',')
            {
                if (count == 0)
                {
                    parameter[pidx] = buffer[index];
                    pidx = pidx + 1;
                }
            }

            else
            {
                count = count + 1;
            }
        }
        Serial.println(count,DEC);
        Serial.println(pidx,DEC);
        cnt = 0;
    }
}
