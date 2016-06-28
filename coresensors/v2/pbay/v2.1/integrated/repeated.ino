/*
 * /coresensors/v2/pbay/integrated
 * repeated.ino V2 (including NEW INTEL CHEMSENSE BOARD)
 */

// airsense board  
void airsensor_MMA8452Q()
{
    #ifdef MMA8452Q_include
    
    if (init_MMA == true)
    {
        previous_MMA[0] = 0.0;
        previous_MMA[1] = 0.0;
        previous_MMA[2] = 0.0;
        previous_MMA[3] = 0.0;
        
        current_MMA[0] = 0.0;
        current_MMA[1] = 0.0;
        current_MMA[2] = 0.0;
        current_MMA[3] = 0.0;

        ave_MMA[0] = 0.0;
        ave_MMA[1] = 0.0;
        ave_MMA[2] = 0.0;
        ave_MMA[3] = 0.0;

        init_MMA = false;
        flag_MMA = false;
    }

    MMA8452_read();

    MMA8452Q[1] = (1 << 7) | (LENGTH_FORMAT6 * 4);

    if (flag_MMA == true)
    {
        current_MMA[0] = Temp_float[0];
        current_MMA[1] = Temp_float[1];
        current_MMA[2] = Temp_float[2];
        current_MMA[3] = Temp_float[3];

        ave_MMA[0] = (previous_MMA[0] + Temp_float[0]) / 2;
        ave_MMA[1] = (previous_MMA[1] + Temp_float[1]) / 2;
        ave_MMA[2] = (previous_MMA[2] + Temp_float[2]) / 2;
        ave_MMA[3] = (previous_MMA[3] + Temp_float[3]) / 2;

        previous_MMA[0] = current_MMA[0];
        previous_MMA[1] = current_MMA[1];
        previous_MMA[2] = current_MMA[2];
        previous_MMA[3] = current_MMA[3];
        
    }
    else if (flag_MMA == false)
    {
        previous_MMA[0] = Temp_float[0];
        previous_MMA[1] = Temp_float[1];
        previous_MMA[2] = Temp_float[2];
        previous_MMA[3] = Temp_float[3];

        flag_MMA = true;
    }

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

// initialization for averaging
    if (init_SPV1 == true)
    {
        // SerialUSB.print("init_SPV1");

        previous_SPV1 = 0;
        current_SPV1 = 0;
        init_SPV1 = false;
        flag_SPV1 = false;
    }

    for(j= 0; j < 100; j++)
    {
        SPV_1_AMPV[j] = 512 - analogRead(SPV_1_AMP);
        if (SPV_1_AMPV[j] < 0)
        {
            SPV_1_AMPV[j] = SPV_1_AMPV[j] * -1;
        }
        delay(1);
    }

    for(j = 0; j < 100; j++)
    {
        SPV_1_AMPV_AVG = ((SPV_1_AMPV_AVG * j) + SPV_1_AMPV[j]) / (j+1);
    }

// AVERAGING
    if (flag_SPV1 == true)
    {
        // SerialUSB.print("nth_SPV1");

        current_SPV1 = int(SPV_1_AMPV_AVG * 10);
        ave_SPV1 = (previous_SPV1 + current_SPV1) / 2;
        previous_SPV1 = current_SPV1;
    }
    else if (flag_SPV1 == false)
    {
        // SerialUSB.print("first_SPV1");

        previous_SPV1 = int(SPV_1_AMPV_AVG * 10);
        previous_SPV1 = ave_SPV1;
        flag_SPV1 = true;
    }
// END AVERAGING

    //format1(int(SPV_1_AMPV_AVG * 10))
    format1(int(ave_SPV1));

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

// initialization for averaging
    if (init_SPV2 == true)
    {
        // SerialUSB.print("init_SPV2");

        previous_SPV2 = 0;
        current_SPV2 = 0;
        init_SPV2 = false;
        flag_SPV2 = false;
    }

    mcp3428_2.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);

// AVERAGING
    if (flag_SPV2 == true)
    {
        // SerialUSB.print("nth_SPV2");
        
        current_SPV2 = mcp3428_2.readADC();
        ave_SPV2 = (current_SPV2 + previous_SPV2) / 2;
        previous_SPV2 = current_SPV2;
    }
    else if (flag_SPV2 == false)
    {
        // SerialUSB.print("first_SPV2");
        
        previous_SPV2 = mcp3428_2.readADC();
        ave_SPV2 = previous_SPV2;
        flag_SPV2 = true;
    }
// END AVERAGING
        
    // format1(mcp3428_2.readADC());
    format1(ave_SPV2);

    SPV1840LR5HB_2[1] = (1 << 7) | LENGTH_FORMAT1;
    SPV1840LR5HB_2[2] = formatted_data_buffer[0];
    SPV1840LR5HB_2[3] = formatted_data_buffer[1];
   
    #ifdef SERIAL_DEBUG
    SerialUSB.print("SPV1840LR5HB: ");
    SerialUSB.println(mcp3428_2.readADC());
    #endif
    #endif
}