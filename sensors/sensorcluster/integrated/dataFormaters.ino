// Packet formatters -
// F1 - unsigned int_16 input, {0-0xffff} - Byte1 Byte2 (16 bit number)
// F2 - int_16 input , +-{0-0x7fff} - 1S|7Bits Byte2
// F3 - byte input[6], {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
// F4 - unsigned long_24 input, {0-0xffffff} - Byte1 Byte2 Byte3
// F5 - long_24 input, +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
// F6 - float input, +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}
// F7 - byte input[4], {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
// F8 - float input, +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac


/** Format 1 assembler ****************************************************************/
// F1 - {0-0xffff} - Byte1 Byte2 (16 bit number)
void format1(unsigned int input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = (input & 0xff00) >> 8;
    formatted_data_buffer[1] = input & 0xff;
}
/**************************************************************************************/



/** Format 2 assembler ****************************************************************/
// F2 - +-{0-0x7fff} - 1S|7Bits Byte2
void format2(int input)
{

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
    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((input & 0x7f00) >> 8);
    formatted_data_buffer[1] = input & 0xff;
}
/**************************************************************************************/


/** Format 3 assembler ****************************************************************/
// F3 - {0-0xffffffffffff} - Byte1 Byte2 Byte3 Byte4 Byte5 Byte6
void format3(byte *input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = input[0];
    formatted_data_buffer[1] = input[1];
    formatted_data_buffer[2] = input[2];
    formatted_data_buffer[3] = input[3];
    formatted_data_buffer[4] = input[4];
    formatted_data_buffer[5] = input[5];
}
/**************************************************************************************/

/** Format 4 assembler ****************************************************************/
// F4 - {0-0xffffff} - Byte1 Byte2 Byte3
void format4(unsigned long input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = (input & 0xff0000) >> 16;
    formatted_data_buffer[1] = (input & 0xff00) >> 8;
    formatted_data_buffer[2] = (input & 0xff);
}
/**************************************************************************************/



/** Format 5 assembler ****************************************************************/
// F5 - +-{0-0x7fffff} - 1S|7Bits Byte2 Byte3
void format5(long input)
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
    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((input & 0x7f0000) >> 16);
    formatted_data_buffer[1] = (input & 0xff00) >> 8;
    formatted_data_buffer[2] = (input & 0xff);
}
/**************************************************************************************/


/** Format 6 assembler ****************************************************************/
// F6 - +-{0-127}.{0-99} - 1S|7Bit_Int 0|7Bit_Frac{0-99}

void format6(float input)
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
    unsigned int integer = (int)input;
    // Extract fractional component (and turn it into an integer)
    unsigned int fractional = ((int)(input*100) - integer*100);

    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | integer;
    formatted_data_buffer[1] = (fractional & 0x7F);
}
/**************************************************************************************/

/** Format 7 assembler ****************************************************************/
// F7 - {0-0xffffffff} - Byte1 Byte2 Byte3 Byte4
void format7(byte *input)
{
    // Assemble sub-packet
    formatted_data_buffer[0] = input[0];
    formatted_data_buffer[1] = input[1];
    formatted_data_buffer[2] = input[2];
    formatted_data_buffer[3] = input[3];
}
/**************************************************************************************/

/** Format 8 assembler ****************************************************************/
// F8 - +-{0-31}.{0-999} - 1S|5Bit_Int|2MSBit_Frac  8LSBits_Frac
void format8(float input)
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

    // Assemble sub-packet
    formatted_data_buffer[0] = (_negative << 7) | ((integer & 0x1F) << 2) | ((fractional & 0x0300) >> 8);
    formatted_data_buffer[1] = (fractional & 0x00FF);;
}
/**************************************************************************************/
