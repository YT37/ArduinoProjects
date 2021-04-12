#include <Servo.h>

Servo servo1;

const int X = A0;
const int Y = A1;

const int Switch = 12;
const int LED = 13;

int XYval;
int sVal;

void setup() {
  pinMode(Switch, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  servo1.attach(5);
  servo1.write(90);
}
void loop() {
  XYval = analogRead(X);
  XYval = map(XYval, 0, 1023, 0, 180);
  servo1.write(XYval);

  sVal = digitalRead(Switch);
  if (sVal == 1)
  {
    digitalWrite(LED, HIGH);
  }

  else if (sVal == 0)
  {
    digitalWrite(LED, LOW);
  }
}
