void testnew ()
{
    //     writeEEPROM(0x0a, 0x56);
    //     SerialUSB.println(readEEPROM(0x0a), HEX);
//     SerialUSB.print("Sound Pressure: ");
//     SerialUSB.print(analogRead(PIN_SPV_AMP));
//     delay(100);
//     SerialUSB.print(" ");
//     SerialUSB.print(analogRead(PIN_SVP_SPL));
//     delay(100);
//     SerialUSB.print(" ");
//     SerialUSB.print(analogRead(PIN_RAW_MIC));
//     delay(100);
//     SerialUSB.println("");

    SerialUSB.println("*********************");
    SerialUSB.println(test_seq++);
    #ifdef AIRSENSE_INCLUDE
    airsense_acquire();
    #endif

    #ifdef LIGHTSENSE_INCLUDE
    lightsense_acquire();
    #endif


    #ifdef CHEMSENSE_INCLUDE

    #ifdef SERIAL_DEBUG
    SerialUSB.println("Acquiring ChemSense Data.");
    #endif
    while (Serial3.available() > 0)
    {
        Serial3.read();
    }
    ChemSensed = 0;
    Chemsense_locked = 0;
    LOOPING = millis();
    while(1)
    {
        chemsense_aquire();
        if (ChemSensed == 1)
        {
            chemsense_pack();
            break;
        }

        if (  millis() - LOOPING > 3000)
        {
            #ifdef SERIAL_DEBUG
            SerialUSB.println("Intel Board Missing.");
            #endif
            ChemSensed = 0;
            break;
        }
    }

    #endif
    SerialUSB.println("*********************");
    delay(100);

}
