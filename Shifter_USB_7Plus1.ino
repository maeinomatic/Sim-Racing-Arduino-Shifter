#include <Joystick.h>

// Define the Joystick object
Joystick_ Joystick;

// Define the pin numbers for buttons
const int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  // Initialize the Joystick library
  Joystick.begin();
  
  // Set button pins as inputs and enable internal pull-up resistors
  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // Read button states and update Joystick buttons
  for (int i = 0; i < 8; i++) {
    Joystick.setButton(i + 0, !digitalRead(buttonPins[i]));
  }

  // Send Joystick state
  Joystick.sendState();

  // Add a small delay to avoid sending data too quickly
  delay(10);
}
