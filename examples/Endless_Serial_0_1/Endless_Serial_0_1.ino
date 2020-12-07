/*
  Infinite loop serial test

  Receives from the main serial port and sends back. The Tw signal is fed also to Serial 1 Rx.
  Receives from serial port 1, sends to the main serial (Serial 0).

  This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc.

  The circuit:
  - A cable connected betwwen "TX" and "10" pins
  - Serial Monitor open on Serial port 0

  This example code is in the public domain.
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
