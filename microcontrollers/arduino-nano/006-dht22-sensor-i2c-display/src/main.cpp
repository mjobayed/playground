#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int OLED_RESET = -1;
const uint8_t SCREEN_ADDRESS = 0x3C;
const int DHT_PIN = 2;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHT_PIN, DHT22);

float tempC;
float tempF;
float hum;

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed!");
    while (true)
      ;
  }
  dht.begin();
}

void loop() {
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(true);
  hum = dht.readHumidity();

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("     Temperature");
  display.println("     ===========");
  display.print("  ");
  display.print(tempC);
  display.print(" C | ");
  display.print(tempF);
  display.println(" F");
  display.println();
  display.println("       Humidity");
  display.println("       ========");
  display.print("        ");
  display.print(hum);
  display.println("%");
  display.display();
  delay(2000);
}
