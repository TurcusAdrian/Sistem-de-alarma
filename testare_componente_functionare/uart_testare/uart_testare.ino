// Steps for UART:
// 1) Upload transmitter code to Arduino Uno (COM 9)
// 2) Replace it with receiver code & upload to Groundstudio Jade Uno+ (COM 8)
// 3) Wire TX of Arduino to RX of Jade, RX of Arduino to TX of Jade and GND to GND
// 4) Check Serial monitor


/* TRANSMITTER:
void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Send a message over serial
  Serial.println("Hello from Arduino Uno #1!");
  delay(1000);  // Wait for 1 second before sending the next message
}
*/

//RECEIVER:

void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte
    char incomingByte = Serial.read();
    // Print the received byte to the serial monitor
    Serial.print("Received: ");
    Serial.println(incomingByte);
  }
}
