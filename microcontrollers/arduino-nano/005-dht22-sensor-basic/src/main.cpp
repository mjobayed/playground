#include <Arduino.h>
#include <DHT.h>

const int DHTPIN = 2;
DHT dht(DHTPIN, DHT22);

float temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");
  delay(2000);
}
