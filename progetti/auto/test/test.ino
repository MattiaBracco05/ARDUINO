#include <Simple_HCSR04.h>
Simple_HCSR04 *sensor_post;
Simple_HCSR04 *sensor_ant;

#include <Servo.h>
Servo servo1;

const int sx_p  = 11;  // Pin  in1 of L298
const int sx_n  = 10;  // Pin  in2 of L298
const int dx_p  = 9; // Pin in3 of L298
const int dx_n  = 8;  // Pin in4 of L298

#define echo_pin_post A0
#define trig_pin_post A1
#define echo_pin_ant A2
#define trig_pin_ant A3

int speed = 255;

int buzzer = 0;

int led_ant = 13;
int led_post = 12;
int abbaglianti = 1;
int led_laterali = A4;
int freccia_dx = 4;
int freccia_sx = 5;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  sensor_post = new Simple_HCSR04(echo_pin_post, trig_pin_post);
  sensor_ant = new Simple_HCSR04(echo_pin_ant, trig_pin_ant);

  servo1.attach(2); //Pin del servo

  pinMode(echo_pin_post, INPUT);
  pinMode(trig_pin_post, OUTPUT);
  pinMode(echo_pin_ant, INPUT);
  pinMode(trig_pin_ant, OUTPUT);

  pinMode(sx_p, OUTPUT);
  pinMode(sx_n, OUTPUT);
  pinMode(dx_p, OUTPUT);
  pinMode(dx_n, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(led_ant, OUTPUT);
  pinMode(led_post, OUTPUT);
  pinMode(abbaglianti, OUTPUT);
  pinMode(led_laterali, OUTPUT);
  pinMode(freccia_dx, OUTPUT);
  pinMode(freccia_sx, OUTPUT);

  digitalWrite(trig_pin_post, LOW);
  digitalWrite(trig_pin_ant, LOW);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  Serial.begin(9600);
  Serial.println("TEST LUCI POSIZIONE");
  for (int i = 0; i < 5; i++) {
    digitalWrite(led_ant, HIGH);
    digitalWrite(led_post, HIGH);
    delay(250);
    digitalWrite(led_ant, LOW);
    digitalWrite(led_post, LOW);
    delay(250);
  }
  Serial.println("TEST ABBAGLIANTI");
  for (int i = 0; i < 5; i++) {
    digitalWrite(abbaglianti, HIGH);
    delay(250);
    digitalWrite(abbaglianti, LOW);
    delay(250);
  }
  Serial.println("TEST FRECCIE");
  for (int i = 0; i < 5; i++) {
    digitalWrite(freccia_dx, HIGH);
    digitalWrite(freccia_sx, HIGH);
    delay(250);
    digitalWrite(freccia_dx, LOW);
    digitalWrite(freccia_sx, LOW);
    delay(250);
  }
  Serial.println("TEST LED LATERALI");
  for (int i = 0; i < 5; i++) {
    digitalWrite(led_laterali, HIGH);
    delay(250);
    digitalWrite(led_laterali, LOW);
    delay(250);
  }
  Serial.println("TEST SERVO");
  servo1.write(90);
  delay(500);
  servo1.write(0);
  delay(500);
  servo1.write(90);
  delay(500);
  servo1.write(180);
  delay(500);
  servo1.write(90);
  Serial.println("TEST MOTORI");
  Serial.println("ACCELERAZIONE");
  analogWrite(sx_p, 255);
  analogWrite(dx_p, 255);
  delay(5000);
  Serial.println("MOTORI FERMI");
  analogWrite(sx_p, 0);
  analogWrite(sx_n, 0);
  analogWrite(dx_p, 0);
  analogWrite(dx_n, 0);
  delay(2000);
  Serial.println("ACCELERAZIONE IN RETRO");
  analogWrite(sx_n, 255);
  analogWrite(dx_n, 255);
  delay(5000);
  Serial.println("MOTORI FERMI");
  analogWrite(sx_p, 0);
  analogWrite(sx_n, 0);
  analogWrite(dx_p, 0);
  analogWrite(dx_n, 0);
  delay(2000);
  Serial.println("TEST COMPLETATO///////////////////////////////////////////////////////////////////////");
  delay(1000);
}
