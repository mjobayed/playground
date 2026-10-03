#include <Arduino.h>
#include <DHT.h>

const int DHTPIN = 2;
DHT dht(DHTPIN, DHT22);

float tempC;
float tempF;
float hum;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(true);
  hum = dht.readHumidity();

  if (isnan(tempC) || isnan(tempF) || isnan(hum)) {
    Serial.println("Failed to get info from the DHT22 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C / ");
    Serial.print(tempF);
    Serial.print("°F | Humidity: ");
    Serial.print(hum);
    Serial.println("%");
  }
  delay(2000);
}
