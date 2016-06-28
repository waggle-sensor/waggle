/*
 * /coresensors/v2/pbay/integrated
 * repeated.ino V2 (including NEW INTEL CHEMSENSE BOARD)
 */

// airsense board  
void airsensor_MMA8452Q()
{
    #ifdef MMA8452Q_include
    MMA8452_read();

    MMA8452Q[1] = (1 << 7) | (LENGTH_FORMAT6 * 4);

    format6(Temp_float[0]);  // Put it into format 1
    MMA8452Q[2] = formatted_data_buffer[0];
    MMA8452Q[3] = formatted_data_buffer[1];

    format6(Temp_float[1]);  // Put it into format 1
    MMA8452Q[4] = formatted_data_buffer[0];
    MMA8452Q[5] = formatted_data_buffer[1];


    format6(Temp_float[2]);  // Put it into format 1
    MMA8452Q[6] = formatted_data_buffer[0];
    MMA8452Q[7] = formatted_data_buffer[1];


    format6(0);  // Put it into format 1
    MMA8452Q[8] = formatted_data_buffer[0];
    MMA8452Q[9] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("MMA8452Q x: ");
    SerialUSB.print(Temp_float[0]);
    SerialUSB.print(" y: ");
    SerialUSB.print(Temp_float[1]);
    SerialUSB.print(" z: ");
    SerialUSB.print(Temp_float[2]);
    SerialUSB.print(" rms: ");
    SerialUSB.println(0);
    #endif
    #endif
}

// get an average value as the noise level
void airsense_SPV1840LRHB_1()
{
    #ifdef SPV1840LR5HB_1_include
    long SPV_1_AMPV[100];
    double SPV_1_AMPV_AVG = 0;

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV[i] = 512 - analogRead(SPV_1_AMP);
        if (SPV_1_AMPV[i] < 0)
        {
            SPV_1_AMPV[i] = SPV_1_AMPV[i] * -1;
        }
        delay(1);
    }

    for(int i = 0; i < 100; i++)
    {
        SPV_1_AMPV_AVG = ((SPV_1_AMPV_AVG * i) + SPV_1_AMPV[i]) / (i+1);
    }

    format1(int(SPV_1_AMPV_AVG * 10));

    SPV1840LR5HB_1[1] = (1 << 7) | LENGTH_FORMAT1;
    SPV1840LR5HB_1[2] = formatted_data_buffer[0];
    SPV1840LR5HB_1[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("SPV1840LR5HB: ");
    SerialUSB.println(Temp_uint16);
    #endif
    #endif
}

// lightsense board
void lightsense_SPV1840LR5HB_2()
{
   #ifdef SPV1840LR5HB_2_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
        
    format1(mcp3428_2.readADC());

    SPV1840LR5HB_2[1] = (1 << 7) | LENGTH_FORMAT1;
    SPV1840LR5HB_2[2] = formatted_data_buffer[0];
    SPV1840LR5HB_2[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
    SerialUSB.print("SPV1840LR5HB: ");
    SerialUSB.println(mcp3428_2.readADC());
    #endif
    #endif
}