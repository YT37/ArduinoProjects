#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>

#define ESP8266_BAUD 9600
SoftwareSerial EspSerial(2, 3);
ESP8266 wifi(&EspSerial);

const int Soil = A1;
const int DC = 4;
const int AC = 5;
int SoilRead = 0;

int Val;

BLYNK_WRITE(V1) {
  Val = param.asInt();
  SoilRead = (100 - (analogRead(Soil) / 1023.00) * 100)

      if (Val == HIGH || SMRead >= 15)
  {
    digitalWrite(RelayDC, HIGH);
    digitalWrite(RelayAC, HIGH);
  }

  else
  {
    digitalWrite(RelayDC, LOW);
    digitalWrite(RelayAC, LOW);
  }
}

void setup() {
  pinMode(RelayDC, OUTPUT);
  pinMode(RelayAC, OUTPUT);
  pinMode(SoilMoi, INPUT);

  Serial.begin(9600);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin("Auth", "SSID", "Password");
}

void loop() {
  Blynk.run();
}