#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int OLED_RESET = -1;
const uint8_t SCREEN_ADDRESS = 0x3C;

// Button on D2 pin
const int BTN1_PIN = 2;

int btn1LastState = HIGH;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  pinMode(BTN1_PIN, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed!");
    while (true)
      ;
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.println("Program Start");
  display.println("=============");
  display.display();
}

void loop() {
  int btn1State = digitalRead(BTN1_PIN);
  if (btn1State == LOW && btn1LastState == HIGH) {
    delay(20);
    if (digitalRead(BTN1_PIN) == LOW) {
      display.println("Button Pressed!");
      display.display();
    }
  }

  btn1LastState = btn1State;
}
