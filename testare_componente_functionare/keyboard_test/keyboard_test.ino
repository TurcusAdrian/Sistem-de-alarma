const int numRows = 4; // Number of rows in the keypad
const int numCols = 4; // Number of columns in the keypad

// Define the keymap for the keypad
char keymap[numRows][numCols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pin numbers for the rows and columns
int rowPins[numRows] = {2, 3, 4, 5}; // Row pins are connected to these Arduino pins
int colPins[numCols] = {6, 7, 8, 9}; // Column pins are connected to these Arduino pins

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the column pins as OUTPUT and HIGH
  for (int col = 0; col < numCols; col++) {
    pinMode(colPins[col], OUTPUT);
    digitalWrite(colPins[col], HIGH);
  }

  // Set the row pins as INPUT and enable internal pull-up resistors
  for (int row = 0; row < numRows; row++) {
    pinMode(rowPins[row], INPUT_PULLUP);
  }
}

void loop() {
  // Scan the keypad for a pressed key
  char pressedKey = scanKeypad();
  
  // Check if a key is pressed
  if (pressedKey != '\0') {
    // Print the pressed key to the serial monitor
    Serial.println(pressedKey);
    
    // Add a delay to debounce the keypad
    delay(100);
  }
}

char scanKeypad() {
  for (int col = 0; col < numCols; col++) {
    // Set the current column as OUTPUT and LOW
    pinMode(colPins[col], OUTPUT);
    digitalWrite(colPins[col], LOW);
    
    for (int row = 0; row < numRows; row++) {
      // Read the current row
      if (digitalRead(rowPins[row]) == LOW) {
        // Key is pressed, return the corresponding character from the keymap
        return keymap[row][col];
      }
    }
    
    // Set the current column back to INPUT and HIGH
    pinMode(colPins[col], INPUT);
    digitalWrite(colPins[col], HIGH);
  }
  
  // No key is pressed
  return '\0';
}
