const int Buzzer = 11;
const int LDR = A0;

void setup()
{
  Serial.begin(9600);

  pinMode(Buzzer, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop()
{
  int ldrStatus = analogRead(LDR);
  Serial.println(ldrStatus);

  if (ldrStatus >= 20)
  {
    tone(Buzzer, 100);
    delay(100);
    noTone(Buzzer);
    delay(100);
  }

  else
  {
    noTone(Buzzer);
  }
}
