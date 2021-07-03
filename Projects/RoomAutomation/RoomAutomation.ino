#define BLYNK_TEMPLATE_ID "TMPLgeCt5VkE"
#define BLYNK_DEVICE_NAME "Room"

#define BLYNK_FIRMWARE_VERSION "0.5.0"

#define BLYNK_PRINT Serial
#define APP_DEBUG

#include "BlynkEdgent.h"
bool connectedFlag = 0;

#define relay1 D4
#define switch1 D5
#define virtual1 V1

int state1 = 0;

void toggleRelay(int relay)
{
  switch (relay)
  {
  case 1:
    if (state1 == 1)
    {
      digitalWrite(relay1, LOW);
      state1 = 0;
    }
    else
    {
      digitalWrite(relay1, HIGH);
      state1 = 1;
    }
    delay(100);
    break;

  default:
    break;
  }
}

void online()
{
  if (digitalRead(switch1) == LOW)
  {
    delay(200);
    toggleRelay(1);
    Blynk.virtualWrite(virtual1, state1);
  }
}
void offline()
{
  if (digitalRead(switch1) == LOW)
  {
    delay(200);
    toggleRelay(1);
  }
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(virtual1);
}

BLYNK_WRITE(virtual1)
{
  state1 = param.asInt();
  digitalWrite(relay1, state1);
}

void checkConnection()
{
  connectedFlag = Blynk.connected();
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  pinMode(relay1, OUTPUT);
  pinMode(switch1, INPUT_PULLUP);
  digitalWrite(relay1, state1);

  timer.setInterval(3000L, checkConnection);
  BlynkEdgent.begin();
}

void loop()
{
  BlynkEdgent.run();

  timer.run();
  if (connectedFlag)
    online();
  else
    offline();
}
