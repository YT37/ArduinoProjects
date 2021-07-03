#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;

LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

const int TrigPin = 2;
const int EchoPin = 3;
const int Max = 400;

NewPing sonar(TrigPin, EchoPin, Max);

float duration, distance;

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  duration = sonar.ping_median(5);

  distance = (duration / 2) * 0.0343;

  lcd.setCursor(0, 0);
  lcd.print("Distance = ");

  if (distance >= 400 || distance <= 2)
  {
    Serial.println("Out of range");
  }

  else
  {
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.setCursor(14, 1);
    lcd.println("Cm");
    delay(500);
  }

  delay(500);
}
