#include "MCP342X.h"
#include <Wire.h>

MCP342X mcp3428_1;
MCP342X mcp3428_2;
void setup()
{
    delay(5000);
    Wire.begin();
    Serial.begin(57600);
    Serial.println("Starting");
    mcp3428_1.init(MCP342X::L, MCP342X::L);
    mcp3428_2.init(MCP342X::L, MCP342X::F);
}

void loop()
{
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    Serial.print("MLX75305:");
    Serial.println(mcp3428_1.readADC(),HEX);
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    Serial.print("TSL260:");
    Serial.println(mcp3428_1.readADC(),HEX);
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    Serial.print("ML8511:");
    Serial.println(mcp3428_1.readADC(),HEX);
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    Serial.print("TSL250:");
    Serial.println(mcp3428_1.readADC(),HEX);
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    Serial.print("APDS:");
    Serial.println(mcp3428_2.readADC(),HEX);
    mcp3428_2.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    Serial.print("SPV:");
    Serial.println(mcp3428_2.readADC(),HEX);
    Serial.println("**");
    delay(5000);
}
