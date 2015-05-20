/***************************************************************************************
Connects to UART on sensor board and forwards received data to Due's USB port.

Arduino Due connections:
  +5V ---> sensor board JP1 (closest to USB port)
  GND ---> sensor board JP1 (furthest from USB port)
  GND ---> sensor board JP2 (middle)
  RX1 (19) <--- sensor board JP2 (closest to J1)
  USB (programming) --> recipient of data
  
Author: Daniel Schrader (dschrader@anl.gov)
***************************************************************************************/



/**************************************************************************************/
// Global vars
String sensorData = "";
boolean _newData = false;
/**************************************************************************************/



/**************************************************************************************/
void setup() {
  // Start serial port for comms with final recipient
  Serial.begin(115200);
  
  // Start serial port for comms with sensor board
  Serial1.begin(115200);
}
/**************************************************************************************/
void loop() {
  // New data available?
  if(_newData) {
    // Send it
    Serial.print(sensorData);
    
    // Reset flag
    _newData = false;
    
    // Empty sensorData to avoid overflow
    sensorData = "";
  }

}
/**************************************************************************************/
// Interrupt for Serial1
void serialEvent1() {
  // Get byte from serial buffer
  char newByte = Serial1.read();
  
  // Add new byte to string
  sensorData += newByte;
  
  // Received terminator?
  if(newByte == '\n')
    // Set flag to let main() know there is new data
    _newData = true;
}
/**************************************************************************************/
