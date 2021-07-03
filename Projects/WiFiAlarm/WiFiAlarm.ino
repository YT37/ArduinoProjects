#define BLYNK_TEMPLATE_ID "TMPLEYZICfU-"
#define BLYNK_DEVICE_NAME "Alarm"

#define BLYNK_FIRMWARE_VERSION "1.0.0"

#define BLYNK_PRINT Serial
#define APP_DEBUG

#include "BlynkEdgent.h"

#define Alarm D1

BLYNK_WRITE(V1)
{
  digitalWrite(Alarm, param.asInt());
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  pinMode(Alarm, OUTPUT);

  BlynkEdgent.begin();
}

void loop()
{
  BlynkEdgent.run();
}
