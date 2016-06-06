char incoming[256] = "";
char * token;
char * taken;
String one = " ";
String two = " ";


#define MAX_FMT_SIZE 6
byte formatted_data_buffer[MAX_FMT_SIZE];

uint8_t sqn = 0;
int type = 0;
int sq_num;
int form1;
int hex;
int form5;
int form2;

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
//	SerialUSB.println("...");
	SerialUSB.readBytes(incoming, 256);
//	Serial.write(incoming);

	token = strtok(incoming, " ");
//	taken = token;
//	Serial.println(token);

	while (token != NULL)
	{
	    String one = " ";
	    one = token;	   

	    String oneP = one.substring(0, 3);
	    two = one.substring(4);	
	    //Serial.println(two);

	    if (oneP == "BAD")					//string
		type = 0;
	    else if (oneP == "SQN")					//uint8
		type = 1;
	    else if (oneP == "SHH" | oneP == "LPP")					//uint16 from string: format1
		type = 2;
	    else if (oneP == "SUV" | oneP == "SVL" | oneP == "SIR")	//uint16 from hex deciamal from string: format1
		type = 3;
	    else if (sqn == 1 & two != "1")  			//the last for if else, int24: format5
		type = 4;
	    else							//for default, int16: format2
		type = 9;

	    //Serial.print(two);
	    //Serial.print(" "); 

	    switch(type)
	    {
		case 0:	//string "BAD"
		    //Serial.println(two);
		    break;

		case 1:	//uint8 "SQN"
		    sq_num = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
		    sqn = sq_num;
		    //Serial.println(sqn);

		    while (sqn > 4)
		    {
			sqn = sqn % 4;
			//Serial.println("sqn");
			//Serial.println(sqn);
		    }
		    break;

		case 2: 	//uint16 from string: format1 "SHH"
		    form1 = two.toInt();
		    format1(form1);
		    //Serial.println(form1);
		    Serial.write(formatted_data_buffer, 3);
		    break;

		case 3: 	//uint16 from hex deciamal from string: format1 "SUV" "SVL" "SIR"
		    hex = (int)strtol(two.c_str(), NULL, 16);   //hex string to int
		    format1(hex);
		    //Serial.println(hex);
		    Serial.write(formatted_data_buffer, 2);
		    break;

		case 4:	//int24: format5 sqn == 1 & two != "1"
		    form5 = two.toInt();
		    format5(form5);
		    //Serial.println(form5);
		    Serial.write(formatted_data_buffer, 3);
		    break;

		default:
		    form2 = two.toInt();
		    format2(form2);
		    //Serial.println(form2);
		    Serial.write(formatted_data_buffer, 2);
		    break;
	    }

	    Serial.println(" ");

	    token = strtok(NULL, " ");
	    one = " ";
	    two = " ";
	}
	memset(incoming, 0, 256);
    }
}
