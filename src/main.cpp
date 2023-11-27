#include <Arduino.h>
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// #define BLYNK_TEMPLATE_ID "TMPL6OZoN7aij"
// #define BLYNK_TEMPLATE_NAME "Kualitas Air"
// #define BLYNK_AUTH_TOKEN "DGXuAwxPFhk3wQwzbyl_lsROAtpmEtI5"
// #define WIFI_SSID "SSID"
// #define WIFI_PASS "PASSKEY"
#define ONEWIRE_BUS 4
#define TURBIDITY_PIN 15

// put function declarations here:
OneWire oneWire(ONEWIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");

  int turbidityValue = analogRead(TURBIDITY_PIN);
  Serial.print("Turbidity: ");
  Serial.println(turbidityValue);
  delay(1000);
}
