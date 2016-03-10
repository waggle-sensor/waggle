void testnew ()
{
//     writeEEPROM(0x0a, 0x56);
//     SerialUSB.println(readEEPROM(0x0a), HEX);
//     writeEEPROM(0x0a, 0x65);
//     SerialUSB.println(readEEPROM(0x0a), HEX);

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
    while(1)
    {
        while (Serial3.available() > 0)
        {
            SerialUSB.print(Serial3.read(), HEX);
        }
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
    delay(5000);

}
