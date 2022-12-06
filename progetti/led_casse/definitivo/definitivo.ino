int blu = 3;
int rosso = 5;
int giallo = 6;
int verde = 9;
int bianco = 10;


void setup() {
  pinMode(blu, OUTPUT);
  pinMode(rosso, OUTPUT);
  pinMode(giallo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(bianco, OUTPUT);
}

void loop() {

  //BLU CRESCENTE - DECRESCENTE
  //SPENGO GLI ALTRI LED
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  //ACCENDO BLU (FADE)
  for (int i = 0; i < 255; i++) {
    analogWrite(blu, i);
    delay(5);
  }
  //SPENGO BLU (FADE)
  for (int i = 255; i > 0; i--) {
    analogWrite(blu, i);
    delay(5);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //ROSSO CRESCENTE - DECRESCENRTE
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  //ACCENDO ROSSO (FADE)
  for (int i = 0; i < 255; i++) {
    analogWrite(rosso, i);
    delay(5);
  }
  //SPENGO ROSSO (FADE)
  for (int i = 255; i > 0; i--) {
    analogWrite(rosso, i);
    delay(5);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //GIALLO CRESCENTE - DECRESCENTE
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  //ACCENDO GIALLO (FADE)
  for (int i = 0; i < 255; i++) {
    analogWrite(giallo, i);
    delay(5);
  }
  //SPENGO GIALLO (FADE)
  for (int i = 255; i > 0; i--) {
    analogWrite(giallo , i);
    delay(5);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //VERDE CRESCNTE - DECRESCENTE
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(bianco, LOW);
  //ACCENDO VERDE (FADE)
  for (int i = 0; i < 255; i++) {
    analogWrite(verde, i);
    delay(5);
  }
  //SPENGO VERDE (FADE)
  for (int i = 255; i > 0; i--) {
    analogWrite(verde, i);
    delay(5);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //BIANCO CRESCENTE - DECRESCENTE
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  //ACCENDO BIANCO (FADE)
  for (int i = 0; i < 255; i++) {
    analogWrite(bianco, i);
    delay(5);
  }
  //SPENGO BIANCO (FADE)
  for (int i = 255; i > 0; i--) {
    analogWrite(bianco, i);
    delay(5);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //TUTTO CRESCENTE - DECRESCENTE
  //ACCENDO TUTTO (FADE)
  for (int i = 0; i < 255; i++) {
    analogWrite(blu, i);
    analogWrite(rosso, i);
    analogWrite(giallo, i);
    analogWrite(verde, i);
    analogWrite(bianco, i);
    delay(5);
  }
  //SPENGO TUTTO (FADE)
  for (int i = 255; i > 0; i--) {
    analogWrite(blu, i);
    analogWrite(rosso, i);
    analogWrite(giallo, i);
    analogWrite(verde, i);
    analogWrite(bianco, i);
    delay(5);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //SEQUENZA
  //spengo i led
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  //attendo 250 ms
  delay(250);
  //SEQUENZA "ANDATA" (blu - rosso - giallo - verde - bianco)
  digitalWrite(blu, HIGH);
  delay(250);
  digitalWrite(blu, LOW);
  digitalWrite(rosso, HIGH);
  delay(250);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, HIGH);
  delay(250);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, HIGH);
  delay(250);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, HIGH);
  delay(250);
  digitalWrite(bianco, LOW);
  delay(250);
  //SEQUENZA "RITORNO" (bianco - verde - giallo - rosso - blu)
  digitalWrite(bianco, HIGH);
  delay(250);
  digitalWrite(bianco, LOW);
  digitalWrite(verde, HIGH);
  delay(250);
  digitalWrite(verde, LOW);
  digitalWrite(giallo, HIGH);
  delay(250);
  digitalWrite(giallo, LOW);
  digitalWrite(rosso, HIGH);
  delay(250);
  digitalWrite(rosso, LOW);
  digitalWrite(blu, HIGH);
  delay(250);
  digitalWrite(blu, LOW);
  delay(250);
  //interno - esterno
  digitalWrite(giallo, HIGH);
  delay(250);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(rosso, HIGH);
  delay(250);
  digitalWrite(verde, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(blu, HIGH);
  digitalWrite(bianco, HIGH);
  delay(250);
  digitalWrite(blu, LOW);
  digitalWrite(bianco, LOW);
  delay(250);
  //esterno -  interno
  digitalWrite(blu, HIGH);
  digitalWrite(bianco, HIGH);
  delay(250);
  digitalWrite(blu, LOW);
  digitalWrite(bianco, LOW);
  digitalWrite(rosso, HIGH);
  digitalWrite(verde, HIGH);
  delay(250);
  digitalWrite(rosso, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(giallo, HIGH);
  delay(250);
  digitalWrite(giallo, LOW);

  //ASPETTO 0,250 SECONDI
  delay(250);

  //lampeggio totale
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  delay(250);
  digitalWrite(blu, HIGH);
  digitalWrite(rosso, HIGH);
  digitalWrite(giallo, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(bianco, HIGH);
  delay(250);
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  delay(250);
  digitalWrite(blu, HIGH);
  digitalWrite(rosso, HIGH);
  digitalWrite(giallo, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(bianco, HIGH);

  //ASPETTO 0,250 SECONDI
  delay(250);

  //STROBO (TOTALE)
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  delay(150);
  digitalWrite(blu, HIGH);
  digitalWrite(rosso, HIGH);
  digitalWrite(giallo, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(bianco, HIGH);
  delay(150);

  //STROBO (BLU)
  //SPENGO GLI ALTRI LED
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(blu, HIGH);
    delay(150);
    digitalWrite(blu, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(100);

  //STROBO (ROSSO)
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(rosso, HIGH);
    delay(150);
    digitalWrite(rosso, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(100);

  //STROBO (GIALLO)
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(giallo, HIGH);
    delay(150);
    digitalWrite(giallo, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(100);

  //STROBO (VERDE)
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(bianco, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(verde, HIGH);
    delay(150);
    digitalWrite(verde, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(100);

  //STROBO (BIANCO)
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(bianco, HIGH);
    delay(150);
    digitalWrite(bianco, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(100);

  //STROBO (BLU e BIANCO)
  //SPENGO GLI ALTRI LED
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(blu, HIGH);
    digitalWrite(bianco, HIGH);
    delay(150);
    digitalWrite(blu, LOW);
    digitalWrite(bianco, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //STROBO (ROSSO e VERDE)
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(bianco, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(rosso, HIGH);
    digitalWrite(verde, HIGH);
    delay(150);
    digitalWrite(rosso, LOW);
    digitalWrite(verde, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //STROBO (GIALLO)
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(rosso, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(bianco, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(giallo, HIGH);
    delay(150);
    digitalWrite(giallo, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //STROBO (ROSSO e VERDE)
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(bianco, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(rosso, HIGH);
    digitalWrite(verde, HIGH);
    delay(150);
    digitalWrite(rosso, LOW);
    digitalWrite(verde, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //STROBO (BLU e BIANCO)
  //SPENGO GLI ALTRI LED
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(verde, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(blu, HIGH);
    digitalWrite(bianco, HIGH);
    delay(150);
    digitalWrite(blu, LOW);
    digitalWrite(bianco, LOW); 
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //STROBO (BLU - GIALLO -BIANCO)
  //SPENGO GLI ALTRI LED
  digitalWrite(rosso, LOW);
  digitalWrite(verde, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(blu, HIGH);
    digitalWrite(giallo, HIGH);
    digitalWrite(bianco, HIGH);
    delay(150);
    digitalWrite(blu, LOW);
    digitalWrite(giallo, LOW);
    digitalWrite(bianco, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);

  //STROBO (ROSSO - VERDE)
  //SPENGO GLI ALTRI LED
  digitalWrite(blu, LOW);
  digitalWrite(giallo, LOW);
  digitalWrite(bianco, LOW);
  for (int i = 0; i < 10; i++) {
    digitalWrite(rosso, HIGH);
    digitalWrite(verde, HIGH);
    delay(150);
    digitalWrite(rosso, LOW);
    digitalWrite(verde, LOW);
    delay(150);
  }

  //ASPETTO 0,250 SECONDI
  delay(250);
}
