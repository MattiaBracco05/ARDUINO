#include <Servo.h>

/*
  PROTOTIPI CHIUSURA SINGOLE DITA
*/
void closePollice();
void closeIndice();
void closeMedio();
void closeAnulare();
void closeMignolo();
/*
  PROTOTIPI APERTURA SINGOLE DITA
*/
void openPollice();
void openIndice();
void openMedio();
void openAnulare();
void openMignolo();
/*
  PROTOTIPI APERTURA/CHIUSURA MANO
*/
void closeHand();
void openHand();
/*
  PROTOTIPI NUMERI 1-5
*/
void n1();
void n2();
void n3();
void n4();
void n5();
/*
  PROTOTIPI GESTI
*/
void ok();
void corna();
void fuck();
void rock();
void bikers();
void L();

/*
  DICHIARAZIONE DEI SERVOMOTORI
*/
Servo pollice;
Servo indice;
Servo medio;
Servo anulare;
Servo mignolo;

int i;
int attesa = 1500;

void setup() {
  Serial.begin(9600);
  /*
    DICHIARAZIONE DEI PIN AI QUALI SONO COLLEGATI I VARI SERVOMOTORI
  */
  pollice.attach(13);
  indice.attach(12);
  medio.attach(11);
  anulare.attach(10);
  mignolo.attach(9);

}

void loop() {
  closeHand();
  delay(attesa);
  openHand();
  delay(attesa);
  ok();
  delay(attesa);
  openHand();
  delay(attesa);
  corna();
  delay(attesa);
  openHand();
  delay(attesa);
  L();
  delay(attesa);
  openHand();
  delay(attesa);
  rock();
  delay(attesa);
  openHand();
  delay(attesa);
  bikers();
  delay(attesa);
  openHand();
  delay(attesa);
  fuck();
  delay(attesa);
  openHand();
  delay(attesa);
  n1();
  delay(attesa);
  n2();
  delay(attesa);
  n3();
  delay(attesa);
  n4();
  delay(attesa);
  n5();
  delay(attesa);
  closeHand();
  delay(attesa);
}
/*
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   FUNZIONI PER LA CHIUSRA DELLE SINGOLE DITA
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void closePollice() {
  pollice.write(180);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void closeIndice() {
  indice.write(180);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void closeMedio() {
  medio.write(180);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void closeAnulare() {
  anulare.write(0);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void closeMignolo() {
  mignolo.write(0);
}
/*
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   FUNZIONI PER L'APERTURA DELLE SINGOLE DITA
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void openPollice() {
  pollice.write(90);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openIndice() {
  indice.write(90);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openMedio() {
  medio.write(90);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openAnulare() {
  anulare.write(90);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openMignolo() {
  mignolo.write(90);
}
/*
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  FUNZIONI APERTURA/CHIUSURA MANO
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void closeHand() {
  closePollice();
  closeIndice();
  closeMedio();
  closeAnulare();
  closeMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openHand() {
  openPollice();
  openIndice();
  openMedio();
  openAnulare();
  openMignolo();
}
/*
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  FUNZIONI NUMERI 1-5
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void n1() {
  openPollice();
  closeIndice();
  closeMedio();
  closeAnulare();
  closeMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void n2() {
  openPollice();
  openIndice();
  closeMedio();
  closeAnulare();
  closeMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void n3() {
  openPollice();
  openIndice();
  openMedio();
  closeAnulare();
  closeMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void n4() {
  closePollice();
  openIndice();
  openMedio();
  openAnulare();
  openMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void n5() {
  openPollice();
  openIndice();
  openMedio();
  openAnulare();
  openMignolo();
}
/*
   ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   FUNZIONI PER GESTI
   ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void ok() {
  closePollice();
  closeIndice();
  openMedio();
  openAnulare();
  openMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void corna() {
  closePollice();
  openIndice();
  closeMedio();
  closeAnulare();
  openMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void fuck() {
  closePollice();
  closeIndice();
  openMedio();
  closeAnulare();
  closeMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void rock() {
  openPollice();
  openIndice();
  closeMedio();
  closeAnulare();
  openMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void bikers() {
  closePollice();
  openIndice();
  openMedio();
  closeAnulare();
  closeMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void L() {
  openPollice();
  openIndice();
  closeMedio();
  closeAnulare();
  closeMignolo();
}
