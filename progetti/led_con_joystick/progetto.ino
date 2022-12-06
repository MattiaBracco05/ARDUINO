#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_BUTTON 2
int LED_1 = 13;
int LED_2 = 12;
int LED_3 = 11;
int LED_4 = 10;
int LED_5 = 9;
void setup() {
  Serial.begin(9600);
  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);
  pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
}

void loop() {
  int x = analogRead(JOYSTICK_X);
  Serial.print("x = ");
  Serial.print(x);
  int y = analogRead(JOYSTICK_Y);
  Serial.print("y = ");
  Serial.print(y);
  int button = !digitalRead(JOYSTICK_BUTTON);
  if (x < 400) {
    digitalWrite(LED_1, HIGH);
  }
  else {
    digitalWrite(LED_1, LOW);
  }
  if (x > 600) {
    digitalWrite(LED_2, HIGH);
  }
  else {
    digitalWrite(LED_2, LOW);
  }
  if (y < 400) {
    digitalWrite(LED_3, HIGH);
  }
  else {
    digitalWrite(LED_3, LOW);
  }
  if (y > 600) {
    digitalWrite(LED_4, HIGH);
  }
  else {
    digitalWrite(LED_4, LOW);
  }
  if (button == HIGH) {
    digitalWrite(LED_5, HIGH);
  }
  else {
    digitalWrite(LED_5, LOW);
  }
delay(100);
}
