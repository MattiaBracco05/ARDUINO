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
int led_laterali = 6;
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
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //CHECK SISTEM
  //suono
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  //spengo tutte le luci posizione
  digitalWrite(led_ant, LOW);
  digitalWrite(led_post, LOW);
  digitalWrite(abbaglianti, LOW);
  digitalWrite(led_laterali, LOW);
  digitalWrite(freccia_dx, LOW);
  digitalWrite(freccia_sx, LOW);
  //servo
  servo1.write(90);
  delay(1000);
  servo1.write(0);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);
  servo1.write(90);
  delay(1000);
  //motori avanti
  analogWrite(sx_p, 255);
  analogWrite(sx_n, 0);
  analogWrite(dx_p, 255);
  analogWrite(dx_n, 0);
  //attendi 0,5 secondi
  delay(500);
  //motori indietro
  analogWrite(sx_p, 0);
  analogWrite(sx_n, 255);
  analogWrite(dx_p, 0);
  analogWrite(dx_n, 255);
  //attendi 0,5 secondi
  delay(500);
  //motori fermi
  analogWrite(sx_p, 0);
  analogWrite(sx_n, 0);
  analogWrite(dx_p, 0);
  analogWrite(dx_n, 0);
  //freccie 3 lampeggi
  for (int i = 0; i < 3; i++) {
    digitalWrite(freccia_dx, HIGH);
    digitalWrite(freccia_sx, HIGH);
    delay(500);
    digitalWrite(freccia_dx, LOW);
    digitalWrite(freccia_sx, LOW);
    delay(500);
  }
  //abbaglianti 2 lampeggi
  for (int i = 0; i < 2; i++) {
    digitalWrite(abbaglianti, HIGH);
    delay(500);
    digitalWrite(abbaglianti, LOW);
    delay(500);
  }
  //check sistem completato (2 suoni)
  //suona per 0,5 secondi
  digitalWrite(buzzer, HIGH);
  delay(250);
  //spegni per 0,5 secondo
  noTone(buzzer);
  delay(250);
  //suona per 0,5 secondi
  digitalWrite(buzzer, HIGH);
  delay(250);
  //spegni
  noTone(buzzer);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //ACCENSIONE LUCI
  for(int i = 0; i < 255; i++){
    analogWrite(led_laterali, i);
    delay(25);
  }
    delay(2000);
  //posizione
  digitalWrite(led_ant, HIGH);
  digitalWrite(led_post, HIGH);
  delay(250);
  digitalWrite(led_ant, LOW);
  digitalWrite(led_post, LOW);
  delay(250);
  digitalWrite(led_ant, HIGH);
  digitalWrite(led_post, HIGH);
  delay(250);
  //abbaglianti e freccie
  digitalWrite(abbaglianti, HIGH);
  digitalWrite((freccia_dx && freccia_sx), HIGH);
  delay(250);
  digitalWrite(abbaglianti, LOW);
  digitalWrite((freccia_dx && freccia_sx), LOW);
  delay(250);
  digitalWrite(abbaglianti, HIGH);
  digitalWrite((freccia_dx && freccia_sx), HIGH);
  delay(250);
  digitalWrite(abbaglianti, LOW);
  digitalWrite((freccia_dx && freccia_sx), LOW);
  
  digitalWrite(trig_pin_ant, LOW);
  digitalWrite(trig_pin_post, LOW);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  Serial.begin(9600);

  //fai 2 misurazioni in 1 secondo (delay 500)
  //misurazione posteriore
  unsigned long distance_post = sensor_post->measure()->cm();
  //misurazione anteriore
  unsigned long distance_ant = sensor_ant->measure()->cm();
  //scrivo valore posteriore
  Serial.println("distance post: ");
  Serial.print(distance_post);
  Serial.print("cm\n");
  //scrivo valore anteriore
  Serial.println("distance ant: ");
  Serial.println(distance_ant);
  Serial.println("cm\n");
  delay(500);
  //AVANTI
  if (distance_ant > 30) {
    //vai avanti
    analogWrite(sx_p, 255);
    analogWrite(sx_n, 0);
    analogWrite(dx_p, 255);
    analogWrite(dx_n, 0);
  }
  else {
    //fermati
    analogWrite(sx_p, 0);
    analogWrite(sx_n, 0);
    analogWrite(dx_p, 0);
    analogWrite(dx_n, 0);
    delay(250);
    //guarda a dx
    servo1.write(180);
    unsigned long distance_right = sensor_ant->measure()->cm();
    Serial.println("distance right:");
    Serial.println(distance_right);
    delay(1000);
    //guardo a sx
    servo1.write(0);
    unsigned long distance_left = sensor_ant->measure()->cm();
    Serial.println("distance left:");
    Serial.println(distance_left);
    delay(1000);
    //servo in posizione centrale
    servo1.write(90);
    delay(500);
    //right > left
    if ((distance_right > distance_left) && (distance_right > 20)) {
      //GIRA A DX
      for (int i = 0; i < 3; i++) {
        digitalWrite(freccia_dx, HIGH);
        delay(500);
        digitalWrite(freccia_dx, LOW);
        delay(500);
      }
      analogWrite(sx_p, 0);
      analogWrite(sx_n, 255);
      analogWrite(dx_p, 255);
      analogWrite(dx_n, 0);
      delay(3000);
      analogWrite(sx_p, 0);
      analogWrite(sx_n, 0);
      analogWrite(dx_p, 0);
      analogWrite(dx_n, 0);
    }
    //left > right
    if ((distance_left > distance_right) && (distance_left > 20)) {
      //GIRA A SX
      for (int i = 0; i < 3; i++) {
        digitalWrite(freccia_sx, HIGH);
        delay(500);
        digitalWrite(freccia_sx, LOW);
        delay(500);
      }
      analogWrite(sx_p, 255);
      analogWrite(sx_n, 0);
      analogWrite(dx_p, 0);
      analogWrite(dx_n, 255);
      delay(3000);
      analogWrite(sx_p, 0);
      analogWrite(sx_n, 0);
      analogWrite(dx_p, 0);
      analogWrite(dx_n, 0);
    }
    //spazio insufficiente
    if (distance_right > 20 || distance_left > 20) {
      //RETROMARCIA
      for (int i = 0; i < 3; i++) {
        digitalWrite(freccia_sx, HIGH);
        digitalWrite(freccia_dx, HIGH);
        delay(500);
        digitalWrite(freccia_sx, LOW);
        digitalWrite(freccia_dx, LOW);
        delay(500);
      }
      analogWrite(sx_p, 0);
      analogWrite(sx_n, 255);
      analogWrite(dx_p, 0);
      analogWrite(dx_n, 255);
      delay(2000);
      analogWrite(sx_p, 0);
      analogWrite(sx_n, 0);
      analogWrite(dx_p, 0);
      analogWrite(dx_n, 0);
    }
    //ANTI IMPATTO POSTERIORE
    Serial.println("ANTI TAMPONAMENTO ATTIVATO");
    if (distance_post < 15) {
      //fermati
      analogWrite(sx_p, 0);
      analogWrite(sx_n, 0);
      analogWrite(dx_p, 0);
      analogWrite(dx_n, 0);
      //aspetta 0,5 secondi
      delay(500);
      //vai avanti per 0,5 secondi
      analogWrite(sx_p, 255);
      analogWrite(sx_n, 0);
      analogWrite(dx_p, 255);
      analogWrite(dx_n, 0);
      delay(500);
      //fermati
      analogWrite(sx_p, 0);
      analogWrite(sx_n, 0);
      analogWrite(dx_p, 0);
      analogWrite(dx_n, 0);
    }
  }
}
