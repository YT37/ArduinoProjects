#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

void setup() {
  Serial.begin(115200);

  Blynk.begin("Auth", "SSID", "Password");

  ArduinoOTA.setHostname("Alarm");
  ArduinoOTA.begin();
}

void loop() {
  Blynk.run();
  ArduinoOTA.handle();
}
