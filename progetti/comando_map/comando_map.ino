int potenziometro = A0;
int led = 9;
int inputVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int valore = analogRead(potenziometro);
  inputVal = map(valore, 0, 1023, 0, 254);
  Serial.print("valore letto  ");
  Serial.println(valore);
  Serial.print("valore map  ");
  Serial.println(inputVal);
  analogWrite(led, inputVal);
  delay(1000);
}
