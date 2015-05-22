

/** Format 1 assembler ****************************************************************/
void format1(float input)
{
    Serial.print("debug: ");
  Serial.println(input);
  
  
  // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    // Extract integer component
    unsigned int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    Serial.println(input*100);
    Serial.println(integer*100);
    unsigned int fractional = ((int)(input*100) - integer*100);
    
    Serial.println(fractional);
    

    // Second byte (for integer) (1 = converted data)
    byte byte1 = (1 << 7) | integer;

    // Third byte (for fractional)
    byte byte2 = (_negative << 7) | (fractional & 0x7F);

    // Assemble sub-packet
    packet_format1[0] = byte1;
    packet_format1[1] = byte2;
    
    Serial.print(byte1, HEX);
    Serial.print(" ");
    Serial.print(byte2, HEX);
    Serial.println(" ");
}
/**************************************************************************************/



/** Format 2 assembler ****************************************************************/
void format2(int input)
{
    // Extract MSB
    byte byte1 = input >> 8;

    // Extract LSB
    byte byte2 = input;

    // Assemble sub-packet
    packet_format2[0] = byte1;
    packet_format2[1] = byte2;
}
/**************************************************************************************/



/** Format 3 assembler ****************************************************************/
void format3(byte *input)
{
    // Assemble sub-packet
    packet_format3[0] = input[0];
    packet_format3[1] = input[1];
    packet_format3[2] = input[2];
    packet_format3[3] = input[3];
    packet_format3[4] = input[4];
    packet_format3[5] = input[5];
}
/**************************************************************************************/



/** Format 4 assembler ****************************************************************/
void format4(float input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    // Extract integer component
    int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    int fractional = (input*1000 - integer*1000);

    // Second byte
    byte byte1 = (1 << 7) | (_negative << 6); // 1 = converted data
    byte1 |= ((integer & 0x0F) << 2);  // Insert integer component
    byte1 |= ((fractional & 0x0300) >> 8); // Insert fractional component

    // Third byte
    byte byte2 = (fractional & 0x00FF);

    // Assemble sub-packet
    packet_format4[0] = byte1;
    packet_format4[1] = byte2;
}
/**************************************************************************************/



/** Format 5 assembler ****************************************************************/
void format5(int input)
{
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);

    // Second byte
    byte byte1 = _negative << 6;
    // Add 6 upper bits to complete byte 1
    byte1 |= input >> 8;

    // Third byte
    byte byte2 = input;

    // Assemble sub-packet
    packet_format5[0] = byte1;
    packet_format5[1] = byte2;
}
/**************************************************************************************/



/** Format 6 assembler ****************************************************************/
void format6(long input)
{  
    // Flag to store pos/neg info
    byte _negative;

    // Input negative?
    if (input < 0) {
        _negative = 1;
    }
    else {
        _negative = 0;
    }

    // Get abs. value of input
    input = abs(input);
    

    // Second byte
    byte byte1 = (1 << 7) | (_negative << 6); // 1 = converted data
    // Add 6 upper bits to complete byte 1
    byte1 |= input >> 16;

    // Third byte
    byte byte2 = input >> 8;

    // Fourth byte
    byte byte3 = input;

    // Assemble sub-packet
    packet_format6[0] = byte1;
    packet_format6[1] = byte2;
    packet_format6[2] = byte3;
}
/**************************************************************************************/


