// controllare 8 relè
#include <IRremote.h>
#include <IRremoteInt.h>
int rxPin = 3;
int txPin = 2;
int reciver = 5;                                                             // IR //
IRrecv irrecv(reciver); // create instance of 'irrecv'
decode_results results;
int rele1 = 6;  // cancello 1                                                // CANCELLO //
int rele2 = 7;  // cancello 2
int rele3 = 8;  // led camera                                                // LED //
int rele4 = 9;  // led cucina
int rele5 = 10; // led sala
int rele6 = 11; // led scala
int rele7 = 12; // led camera
int rele8 = 13; // portone garage                                            // PORTONE //
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // for serial monitor output
  irrecv.enableIRIn(); // Start the receiver
  pinMode (rele1, OUTPUT);
  pinMode (rele2, OUTPUT);
  pinMode (rele3, OUTPUT);
  pinMode (rele4, OUTPUT);
  pinMode (rele5, OUTPUT);
  pinMode (rele6, OUTPUT);
  pinMode (rele7, OUTPUT);
  pinMode (rele8, OUTPUT);
  digitalWrite (rele1, LOW);
  digitalWrite (rele2, LOW);
  digitalWrite (rele3, LOW);
  digitalWrite (rele4, LOW);
  digitalWrite (rele5, LOW);
  digitalWrite (rele6, LOW);
  digitalWrite (rele7, LOW);
  digitalWrite (rele8, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    Serial.println(results.value, HEX); // display it on serial monitor in hexadecimal
    irrecv.resume();// receive the next value
  }

  if ( results.value == 0xFF30CF ||  results.value == 0xFF30CF ) { //tasto 1 sul telecomando // ESCO DI CASA //
    digitalWrite (rele3, LOW);    // led off         // spegne
    digitalWrite (rele4, LOW);    // led off         // led
    digitalWrite (rele5, LOW);    // led off         // casa
    digitalWrite (rele6, HIGH);   // led scala on
    delay(7000);                  // attende 7 secondi
    digitalWrite (rele6, LOW);    // led scala off
    digitalWrite (rele7, HIGH);   // led garage on
    digitalWrite (rele8, HIGH);   // APRE IL GARAGE
    delay(10000);                 // attende 10 secondi
    digitalWrite (rele8, LOW);    // CHIUDE IL GARAGE
    digitalWrite (rele1, HIGH);   // set rele1 on    // apre
    digitalWrite (rele2, HIGH);   // set rele2 on    // cancello
    delay(15000);                 // attende 15 secondi
    digitalWrite (rele1, HIGH);   // set rele1 on    // chiude
    digitalWrite (rele2, HIGH);   // set rele2 on    // cancello
  }
}
