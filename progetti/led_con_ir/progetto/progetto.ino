#include <SoftwareSerial.h>
#include <IRremoteInt.h>
#include <IRremote.h> // use the library
int receiver = 53; // pin 1 of IR receiver to Arduino digital pin 11
IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results;
void setup()
{
  Serial.begin(9600); // for serial monitor output
  irrecv.enableIRIn(); // Start the receiver
  pinMode(A8, OUTPUT); // Pin 13 output
  pinMode(A9, OUTPUT); // Pin 12 output
  pinMode(A10, OUTPUT); // Pin 11 output
  pinMode(10, OUTPUT); // Pin 10 output
}
void loop()
{
  if (irrecv.decode()) {
  results.value, HEX; // display it on serial monitor in hexadecimal
  irrecv.resume();// receive the next value
  }

  if ( results.value == 0xFF30CF ||  results.value == 0xFF30CF ) { //tasto 1 sul telecomando
  digitalWrite(13, HIGH);   // set the LED on
  }
  if ( results.value == 0xFF18E7 ||  results.value == 0xFF18E7 ) { //tasto 2 sul telecomando
  digitalWrite(13, LOW);   // set the LED 0ff
  }
  if ( results.value == 0xFF7A85 ||  results.value == 0xFF7A85 ) { //tasto 3 sul telecomando
  digitalWrite(12, HIGH);   // set the LED on
  }
  if ( results.value == 0xFF10EF ||  results.value == 0xFF10EF ) { //tasto 4 sul telecomando
  digitalWrite(12, LOW);   // set the LED off
  }
  if ( results.value == 0xFF38C7 ||  results.value == 0xFF38C7 ) { //tasto 5 sul telecomando
  digitalWrite(11, HIGH);   // set the LED on
  }
  if ( results.value == 0xFF5AA5 ||  results.value == 0xFF5AA5 ) { //tasto 6 sul telecomando
  digitalWrite(11, LOW);   // set the LED off
  }
  if ( results.value == 0xFF42BD ||  results.value == 0xFF42BD ) { //tasto 7 sul telecomando
  digitalWrite(10, HIGH);   // set the LED on
  }
  if ( results.value == 0xFF4AB5 ||  results.value == 0xFF4AB5 ) { //tasto 8 sul telecomando
  digitalWrite(10, LOW);   // set the LED off
  }
  if ( results.value == 0xFFA25D ||  results.value == 0xFFA25D ) { //tasto power sul telecomando
  digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW); // set all the LED off
  }
  if ( results.value == 0xFFE21D ||  results.value == 0xFFE21D ) { //tasto funzioni/stop sul telecomando
  digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH); // set all the LED on
  }
  if ( results.value == 0xFF906F ||  results.value == 0xFF906F ) { //tasto up sul telecomando
  digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(2000);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    delay(2000);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    delay(2000);
    digitalWrite(10, LOW);
  }
  if ( results.value == 0xFF629D ||  results.value == 0xFF629D ) { //tasto vol + sul telecomando
  for (int i = 0; i < 20; i++) {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      delay(500);
      digitalWrite(13, HIGH);
      digitalWrite(10, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      digitalWrite(10, LOW);
      delay(500);
      digitalWrite(13, HIGH);
      digitalWrite(10, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      digitalWrite(10, LOW);
      delay(500);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      delay(500);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      delay(500);
    }
  }
  if ( results.value == 0xFFA857 ||  results.value == 0xFFA857 ) { //tasto vol - sul telecomando
  digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
}
