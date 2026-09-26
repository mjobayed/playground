#include <Arduino.h>

// This targets the D2 pin
const int buttonPin = 2;

void setup() {
  Serial.begin(9600);

  // Configure pin as pullup resistor.
  // So it's HIGH when open and LOW when button is pressed.
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  delay(200);
}
