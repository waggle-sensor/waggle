#include "MCP342X.h"
#include <Wire.h>
extern TwoWire Wire1;

MCP342X mcp3428_1;
MCP342X mcp3428_2;
void setup()
{
    delay(5000);
    Wire1.begin();
    SerialUSB.begin(115200);
    SerialUSB.println("Starting");
    mcp3428_1.init(MCP342X::L, MCP342X::L);
    mcp3428_2.init(MCP342X::L, MCP342X::F);
}

void loop()
{
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    SerialUSB.print("MLX75305:");
    SerialUSB.println(mcp3428_1.readADC(),HEX);
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    SerialUSB.print("TSL260:");
    SerialUSB.println(mcp3428_1.readADC(),HEX);
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    SerialUSB.print("ML8511:");
    SerialUSB.println(mcp3428_1.readADC(),HEX);
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    SerialUSB.print("TSL250:");
    SerialUSB.println(mcp3428_1.readADC(),HEX);
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    SerialUSB.print("APDS:");
    SerialUSB.println(mcp3428_2.readADC(),HEX);
    mcp3428_2.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    SerialUSB.print("SPV:");
    SerialUSB.println(mcp3428_2.readADC(),HEX);
    SerialUSB.println("**");
    delay(5000);
}
