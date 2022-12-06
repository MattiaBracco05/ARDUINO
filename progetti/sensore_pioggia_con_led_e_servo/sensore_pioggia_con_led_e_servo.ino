#include <Servo.h>
Servo Servo1;

int pinIngresso = 2;
int led = 3;
int pioggia = 0;
int misurazione = 0;

void setup()
{
  Serial.begin(9600);
  Servo1.attach(4);
  pinMode(pinIngresso, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  pioggia = digitalRead(pinIngresso);
  misurazione = analogRead(A0);
  Serial.println(misurazione);


  if (pioggia == 1) {
    Serial.println("STATO: OK");
    digitalWrite(led, LOW);
    Servo1.write(90);
  }
  if (pioggia == 0) {
    Serial.println("STATO: RILEVATA PIOGGIA");
    digitalWrite(led, HIGH);
    Servo1.write(0);
  }
  delay(1000);

}
