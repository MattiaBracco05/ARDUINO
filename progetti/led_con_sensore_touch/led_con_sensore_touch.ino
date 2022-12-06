int led = 13;
int TouchSensor = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(TouchSensor, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(TouchSensor) == HIGH) {
    digitalWrite(led, !digitalRead(led));
    while (digitalRead(TouchSensor) == HIGH) {
    }
    if (digitalRead(led) == HIGH) {
      Serial.println("led accesi");
    }
    else {
      Serial.println("led spenti");
    }
  }
}
