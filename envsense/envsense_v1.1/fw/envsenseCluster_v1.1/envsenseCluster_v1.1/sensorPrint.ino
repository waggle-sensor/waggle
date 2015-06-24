void sensor_print()
{
    #ifdef debug_serial
    Serial.println(" print");
    Serial.flush();
    #endif
    #ifdef POST
    wdt_reset();
    #endif
    #ifdef MLX90614_ADD
    if((EEPROM.read(MLX90614_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        if (start_err == 1 || write_err == 1 || rep_start_err == 1)
        {
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("MLX90614_1_T_F:");
            Serial.print(-999);
            Serial.print(";");
            #endif
        }
        else {
            Serial.print("MLX90614_1_T_F:");
            Serial.print(fahrenheit);
            Serial.print(";");
        }
        Serial.println("WXSensor");
    }
    #endif //MLX90614_ADD

    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef IR_D6T_44L_06_ADD
    if((EEPROM.read(IR_D6T_44L_06_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        if (data_check == true) {
            Serial.print("D6T_44L_06_1_T_C:");
            output_csv();
            Serial.print(";");
        }
        else {
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("D6T_44L_06_1_T_C:");
            Serial.print("-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999;");
            #endif
        }
        Serial.println("WXSensor");
    }
    #endif //IR_D6T_44L_06_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef TMP421_ADD
    if((EEPROM.read(TMP421_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        if (TMP421_1_temperature == -999) {
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("TMP421_1_T_C:");
            Serial.print(TMP421_1_temperature, 2);
            Serial.print(";");
            #endif
        }
        else {
            Serial.print("TMP421_1_T_C:");
            Serial.print(TMP421_1_temperature, 2);
            Serial.print(";");
        }
        Serial.println("WXSensor");
    }
    #endif //TMP421_ADD

    #ifdef POST
    wdt_reset();
    #endif
    
    #ifdef BMP180_ADD
    if((EEPROM.read(BMP180_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        if (BMP_180_1_temperature == -999 || BMP_180_1_pressure == -999) {
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("BMP_180_1_T_C:");
            Serial.print(BMP_180_1_temperature, 2);
            Serial.print(";");
            Serial.print("BMP_180_1_P_PA:");
            Serial.print(BMP_180_1_pressure, 2);
            Serial.print(";");
            #endif
        }
        else {
            Serial.print("BMP_180_1_T_C:");
            Serial.print(BMP_180_1_temperature, 2);
            Serial.print(";");
            Serial.print("BMP_180_1_P_PA:");
            Serial.print(BMP_180_1_pressure, 2);
            Serial.print(";");
        }
        Serial.println("WXSensor");
    }
    #endif //BMP180_ADD
    #ifdef POST
    wdt_reset();
    #endif

    #ifdef MMA8452
    if((EEPROM.read(MMA8452+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        if (MMA_found == true) {
            Serial.print("MMA8452_1_A_X_Units:");
            Serial.print(xmean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_Y_Units:");
            Serial.print(ymean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_Z_Units:");
            Serial.print(zmean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_RMS_Units:");
            Serial.print(rt_mean_sq);
            Serial.print(";");
        }
        else {
            #ifndef SILENCE_BAD_SENSORS
            xmean = -999, ymean = -999, zmean = -999, rt_mean_sq = -999;
            Serial.print("MMA8452_1_A_X_Units:");
            Serial.print(xmean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_Y_Units:");
            Serial.print(ymean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_Z_Units:");
            Serial.print(zmean);
            Serial.print(";");
            Serial.print("MMA8452_1_A_RMS_Units:");
            Serial.print(rt_mean_sq);
            Serial.print(";");
            MMA_found = initMMA8452();
            #endif
        }
        Serial.println("WXSensor");
    }
    #endif //MMA8452

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef PhoRes_ADD
    if((EEPROM.read(PhoRes_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("PhoRes_10K4.7K_1_Units:");
        Serial.print(PhoRes_1_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //PhoRes_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef THERMIS_100K_ADD
    if((EEPROM.read(THERMIS_100K_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("THERMIS_100K_1_Units:");
        Serial.print(THERMIS_1_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //THERMIS_100K_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HIH6130_ADD
    if((EEPROM.read(HIH6130_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("HIH_6130_1_T_C:");
        Serial.print(HIH_6130_1_hih.temperature(), 2);
        Serial.print(";");
        Serial.print("HIH_6130_1_H_%:");
        Serial.print(HIH_6130_1_hih.humidity(), 2);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //HIH6130_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef SHT15_ADD
    if((EEPROM.read(SHT15_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("SHT15_1_T_C:");
        Serial.print(SHT15_1_temperature,2);
        Serial.print(";");
        Serial.print("SHT15_1_H_%:");
        Serial.print(SHT15_1_humidity,2);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //SHT15_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef DS18B20_ADD
    if((EEPROM.read(DS18B20_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("DS18B20_1_T_C:");
        Serial.print(DS18B20_1_temperature, 2);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //DS18B20_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef RHT03_ADD
    if((EEPROM.read(RHT03_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        if (chk_RHT03_1 == DHTLIB_OK)
        {
            Serial.print("RHT03_1_T_C:");
            Serial.print(RHT03_1.temperature, 2);
            Serial.print(";");
            Serial.print("RHT03_1_H_%:");
            Serial.print(RHT03_1.humidity, 2);
            Serial.print(";");
        }
        Serial.println("WXSensor");
    }
    #endif //RHT03_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef TMP102_ADD
    if((EEPROM.read(TMP102_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        if (err != 0) {
            Serial.print("TMP102_1_T_F:");
            Serial.print(tmp102_1_temperature,2);
            Serial.print(";");
        }
        else{
            #ifndef SILENCE_BAD_SENSORS
            Serial.print("TMP102_1_T_F:");
            Serial.print(tmp102_1_temperature,2);
            Serial.print(";");
            #endif
        }
        Serial.println("WXSensor");
    }
    #endif //TMP102_ADD

    #ifdef SHT75_ADD
    if((EEPROM.read(SHT75_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("SHT75_1_T_C:");
        Serial.print(SHT75_1_temperature,2);
        Serial.print(";");
        Serial.print("SHT75_1_H_%:");
        Serial.print(SHT75_1_humidity,2);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //SHT75_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HIH4030_ADD
    if((EEPROM.read(HIH4030_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("HIH4030_1_Units:");
        Serial.print(HIH4030_1_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //HIH4030_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef GA1A1S201WP_ADD
    if((EEPROM.read(GA1A1S201WP_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("AMBI_1_Units:");
        Serial.print(AMBI_1_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //GA1A1S201WP_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef MAX4466_ADD
    if((EEPROM.read(MAX4466_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("MAX4466_1_MaxN_Units:");
        Serial.print(MAX4466_Value);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //MAX4466_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef WindVel_ADD
    if((EEPROM.read(WindVel_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
//         Serial.print("WindVel_1_MaxV_M/S:");
//         Serial.print(max_airspeed);
//         Serial.print(";");
//         Serial.print("WindVel_1_AvgV_M/S:");
//         Serial.print(avg_speed);
        Serial.print("WindVel_1_V_M/S:");
        Serial.print(speed_mps);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //WindVel_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HTU21D_ADD
    if((EEPROM.read(HTU21D_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        Serial.print("WXSensor;");
        Serial.print("HTU21D_T_C:");
        Serial.print(HTU21D_T, 1);
        Serial.print(";");
        Serial.print("HTU21D_H_%:");
        Serial.print(HTU21D_H, 1);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //HTU21D_ADD

    #ifdef POST
    wdt_reset();
    #endif

    #ifdef HMC5883_ADD
    if((EEPROM.read(HMC5883_ADD+128) & Consistency_Mask) == Consistency_Mask)    // Determine status of sensor
    {
        /* Display the results (magnetic vector values are in micro-Tesla (uT)) */
        Serial.print("WXSensor;");
        Serial.print("HMC5883_X_uT:");
        Serial.print(HMC5883_event.magnetic.x);
        Serial.print(";");
        Serial.print("HMC5883_Y_uT:");
        Serial.print(HMC5883_event.magnetic.y);
        Serial.print(";");
        Serial.print("HMC5883_Z_uT:");
        Serial.print(HMC5883_event.magnetic.z);
        Serial.print(";");
        Serial.println("WXSensor");
    }
    #endif //HMC5883_ADD
    
    #ifdef POST
    wdt_reset();
    #endif
}
