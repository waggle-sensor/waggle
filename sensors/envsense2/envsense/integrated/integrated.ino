#define CR_ENABLE 1
#define BUFFER_SIZE_INTEL 150
#define PARAM_SIZE_INTEL 15
// #define CR_ENABLE 0
unsigned char buffer [BUFFER_SIZE_INTEL];
unsigned char parameter[PARAM_SIZE_INTEL];
unsigned char cnt = 0;
boolean ready = false;
unsigned char INTEL_MAC[6] ={0,0,0,0,0,0};

void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);
}

void loop() {
    while (Serial1.available())
    {
        char inByte = Serial1.read();
        Serial.write(inByte);
        if (( inByte != '\n') && (cnt < BUFFER_SIZE_INTEL))
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
        for (unsigned char index = CR_ENABLE; index < cnt; index ++)
        {
            if (buffer[index] != ',')
            {
                if ((count == 0) && (pidx < PARAM_SIZE_INTEL))
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

        if ((count == 15) && (pidx == 12))
        {
            Serial.println("Received full packet");
            unsigned char count = 0, pidx = 0;
            for (unsigned char index = CR_ENABLE; index < cnt; index ++)
            {
                if ((buffer[index] != ',') && (pidx < PARAM_SIZE_INTEL))
                {
                    parameter[pidx] = buffer[index];
                    pidx = pidx + 1;
                }
                else
                {

                    if (count == 0)
                    {
                        Serial.println("MAC");
                        for (unsigned char idx = 0; idx < pidx; idx ++)
                        {
                            if ((parameter[idx] > 96) && (parameter[idx] < 103))
                            {
                                parameter[idx] = parameter[idx] - 87;
                            }
                            else
                            {
                                parameter[idx] = parameter[idx] - 48;
                            }

                            if (idx % 2 == 0)
                            {
                                parameter[idx] = parameter[idx] << 4;
                            }

                            INTEL_MAC [idx/2] = INTEL_MAC[idx/2] | parameter[idx];
                            Serial.print(parameter[idx],HEX);
                        }
                        Serial.print("\n");
                        for (unsigned char idx = 0; idx < 6; idx ++)
                        {
                            Serial.print(INTEL_MAC[idx]);
                        }
                        Serial.print("\n");
                    }

                    else if (count == 1)
                    {
                        Serial.println("HDC_Temp");
                    }
                    else if (count == 2)
                    {
                        Serial.println("HDC_RH");
                    }
                    else if (count == 3)
                    {
                        Serial.println("SHT_Temp");
                    }
                    else if (count == 4)
                    {
                        Serial.println("SHT_RH");
                    }
                    else if (count == 5)
                    {
                        Serial.println("LPS_Temp");
                    }
                    else if (count == 6)
                    {
                        Serial.println("UV");
                    }
                    else if (count == 7)
                    {
                        Serial.println("Pressure");
                    }
                    else if (count == 8)
                    {
                        Serial.println("H2S");
                    }
                    else if (count == 9)
                    {
                        Serial.println("O3");
                    }
                    else if (count == 10)
                    {
                        Serial.println("NO2");
                    }
                    else if (count == 11)
                    {
                        Serial.println("CO");
                    }
                    else if (count == 12)
                    {
                        Serial.println("SO2");
                    }

                    else if (count == 13)
                    {
                        Serial.println("TotalOX");
                    }
                    else if (count == 14)
                    {
                        Serial.println("TotalRed");
                    }
                    else if (count == 15)
                    {
                        Serial.println("ETOH");
                    }

                    count = count + 1;
                }
            }
        }

        cnt = 0;
    }
}
