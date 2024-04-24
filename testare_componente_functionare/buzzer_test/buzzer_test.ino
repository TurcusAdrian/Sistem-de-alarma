// Define buzzer pin
const int buzzerPin = 9;

void setup() {
  // Initialize buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Turn on the buzzer
  digitalWrite(buzzerPin, HIGH);
  
  // Wait for 1 second
  delay(1000);
  
  // Turn off the buzzer
  digitalWrite(buzzerPin, LOW);
  
  // Wait for 1 second
  delay(1000);
}
