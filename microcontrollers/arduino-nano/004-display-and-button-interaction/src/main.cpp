#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int OLED_RESET = -1;
const uint8_t SCREEN_ADDRESS = 0x3C;

// Buttons on D2 and D3 pin
const int BTN1_PIN = 2;
const int BTN2_PIN = 3;

int btn1LastState = HIGH;
int btn2LastState = HIGH;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  pinMode(BTN1_PIN, INPUT_PULLUP);
  pinMode(BTN2_PIN, INPUT_PULLUP);

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
  int btn2State = digitalRead(BTN2_PIN);

  if (btn1State == LOW && btn1LastState == HIGH) {
    delay(20);
    if (digitalRead(BTN1_PIN) == LOW) {
      display.println("Button Pressed!");
      display.display();
    }
  }

  if (btn2State == LOW && btn2LastState == HIGH) {
    delay(20);
    if (digitalRead(BTN2_PIN) == LOW) {
      display.clearDisplay();
      display.println("Program Start");
      display.println("=============");
      display.display();
    }
  }

  btn1LastState = btn1State;
  btn2LastState = btn2State;
}
