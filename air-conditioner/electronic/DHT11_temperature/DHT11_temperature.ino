#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT11 test!");

  dht.begin();
}

void loop() {
  delay(5000);
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();//Humedad
  float t = dht.readTemperature();//Temperatura en Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor");
    return ;
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" C");
  Serial.println("");
}
