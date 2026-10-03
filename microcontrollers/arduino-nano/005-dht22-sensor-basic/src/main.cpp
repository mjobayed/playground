#include <Arduino.h>
#include <DHT.h>

const int DHTPIN = 2;
DHT dht(DHTPIN, DHT22);

float tempC;
float tempF;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(true);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" °C/ ");
  Serial.print(tempF);
  Serial.println(" °F");
  delay(2000);
}
