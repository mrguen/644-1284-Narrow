/*
  Infinite loop serial test

  Receives from the Serial Monitor on the hardware serial 0 port and sends back. 
  The serial 0 Tx signal is also fed to the serial 1 Rx pin.
  When Serial 1 receives it writes again from Serial 0.
  Hence it loops endlessly whatever you type in the Serial Monitor

  The circuit:
  - On the 644/1284 Narrow variant
  - A cable connected betwwen pin "Tx" (hardware serial 0 Tx) and pin "10" (hardware serial 1 Rx)
  - Serial Monitor open on Serial port 0

*/



void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // read from port 1, send to port 0:

  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial.write(inByte);
  }
}
