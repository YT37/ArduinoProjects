#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

volatile float PC;
int LP;

const int Relay = 5;
const int WaterSensor = 13;

WidgetBridge bridge1(V1);

BLYNK_CONNECTED()
{
  bridge1.setAuthToken("Auth");
}

ICACHE_RAM_ATTR void RPM()
{
  PC++;
}

void setup()
{
  Serial.begin(115200);

  pinMode(WaterSensor, INPUT);

  Blynk.begin("Auth", "SSID", "Password");

  ArduinoOTA.setHostname("Tank");
  ArduinoOTA.begin();

  attachInterrupt(digitalPinToInterrupt(WaterSensor), RPM, RISING);
}

void loop()
{
  Blynk.run();

  PC = 0;

  sei();
  ArduinoOTA.handle();
  delay(1000);
  cli();

  LP = (PC * 60 / 7.5);

  if (LP > 100)
    bridge1.digitalWrite(Relay, HIGH);
  else
    bridge1.digitalWrite(Relay, LOW);
}
