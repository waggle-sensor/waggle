char incoming[256] = "";
char * token;

void setup()
{
    SerialUSB.begin(115200);    //sendData
    while(!SerialUSB) {;}
    Serial.begin(115200);       //getData
    while(!Serial) {;}
}

void loop()
{
    SerialUSB.println(">>get data packets and parse and send back?<<");
    while (1)
    {
        SerialUSB.println("...");
	SerialUSB.readBytes(incoming, 256);
//	Serial.write(incoming);

	token = strtok(incoming, " ");
//	String one = token;
//	Serial.println(token);

	while (token != NULL)
	{
//	    String one = token;
//	    Serial.println(token);	   

//	    if (one.substring(0, 1) != ">")
//	    {
		Serial.print(token.substring(0, 3));
//		Serial.print(" ");

//		String a = one.substring(4);
//		Serial.print(a.toInt);

//		Serial.print(one.substring(4));
//		Serial.print(" ");
//	    }
//	    else
//	    {
//		Serial.println(one.substring(1, 4));
//		Serial.println(one.substring(5));
//	    }

	    token = strtok(NULL, " ");
	}
	memset(incoming, 0, 256);
    }
}
