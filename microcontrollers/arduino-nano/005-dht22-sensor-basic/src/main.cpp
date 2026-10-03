#include <Arduino.h>
#include <DHT.h>

const int DHTPIN = 2;
DHT dht(DHTPIN, DHT22);

float tempC;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  tempC = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");
  delay(2000);
}
