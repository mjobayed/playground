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

  if (isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to get info from the DHT22 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print(" °C/ ");
    Serial.print(tempF);
    Serial.println(" °F");
  }
  delay(2000);
}
