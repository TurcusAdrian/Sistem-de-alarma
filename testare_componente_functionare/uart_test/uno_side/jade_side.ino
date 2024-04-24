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
