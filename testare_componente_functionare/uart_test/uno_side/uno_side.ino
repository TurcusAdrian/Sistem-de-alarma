void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Send a message over serial
  Serial.println("Hello from Arduino Uno #1!");
  delay(1000);  // Wait for 1 second before sending the next message
}
