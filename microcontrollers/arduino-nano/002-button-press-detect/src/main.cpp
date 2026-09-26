#include <Arduino.h>

// This targets the D2 pin
const int buttonPin = 2;
int lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);

  // Configure pin as pullup resistor.
  // So it's HIGH when open and LOW when button is pressed.
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    Serial.println("Button Pressed!");
    delay(150);
  }

  lastButtonState = buttonState;
}
