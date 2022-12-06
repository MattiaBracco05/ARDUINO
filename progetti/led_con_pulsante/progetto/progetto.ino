int led = 9;
int pulsante = 5;
int stato = 0;

void setup() {
  pinMode (led, OUTPUT);
  pinMode (pulsante, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  stato = digitalRead(pulsante);
  if (stato == 1) {
    for (int i = 0; i < 255; i++) {
      analogWrite(led, i);
      delay(20);
    }
  }
  else {
    digitalWrite(led, LOW);
  }
}
