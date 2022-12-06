int blu = 3;
int rosso = 5;
int giallo = 6;
int verde = 9;
int bianco = 10;
int button = 4;
int led = 1;

void setup() {
  pinMode(blu, OUTPUT);
  pinMode(rosso, OUTPUT);
  pinMode(giallo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(bianco, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead (button) == 0) {  //se il pulsante è premuto
    led++;       // Incrementa la variabile led
    if (led > 9) { // Se la variabile supera il valore 9
      led = 1;     // Riporta la variabile a 1
    }
    delay (500);   // Pausa per antirimbalzo
  }
  if (led == 1) {
    //BLU CRESCENTE - DECRESCENTE
    digitalWrite(rosso, LOW);
    digitalWrite(giallo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(bianco, LOW);
    for (int i = 0; i < 255; i++) {
      analogWrite(blu, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(blu, i);
      delay(10);
    }
  }
  if (led == 2) {
    //ROSSO CRESCENTE - DECRESCENRTE
    digitalWrite(blu, LOW);
    digitalWrite(giallo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(bianco, LOW);
    for (int i = 0; i < 255; i++) {
      analogWrite(rosso, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(rosso, i);
      delay(10);
    }
  }
  if (led == 3) {
    //GIALLO CRESCENTE - DECRESCENTE
    digitalWrite(blu, LOW);
    digitalWrite(rosso, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(bianco, LOW);
    for (int i = 0; i < 255; i++) {
      analogWrite(giallo, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(giallo , i);
      delay(10);
    }
  }
  if (led == 4)  {
    //VERDE CRESCNTE - DECRESCENTE
    digitalWrite(blu, LOW);
    digitalWrite(rosso, LOW);
    digitalWrite(giallo, LOW);
    digitalWrite(bianco, LOW);
    for (int i = 0; i < 255; i++) {
      analogWrite(verde, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(verde, i);
      delay(10);
    }
  }
  if (led == 5) {
    //BIANCO CRESCENTE - DECRESCENTE
    digitalWrite(blu, LOW);
    digitalWrite(rosso, LOW);
    digitalWrite(giallo, LOW);
    digitalWrite(verde, LOW);
    for (int i = 0; i < 255; i++) {
      analogWrite(bianco, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(bianco, i);
      delay(10);
    }
  }
  if (led == 6) {
    //TUTTO FISSO
    digitalWrite(blu, HIGH);
    digitalWrite(rosso, HIGH);
    digitalWrite(giallo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(bianco, HIGH);
  }
  if (led == 7) {
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
    digitalWrite(bianco, HIGH);
    delay(250);
    digitalWrite(bianco, LOW);
    delay(250);
  }
  if (led == 8) {
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
  }
  if (led == 9) {
    //spengo i led
    digitalWrite(blu, LOW);
    digitalWrite(rosso, LOW);
    digitalWrite(giallo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(bianco, LOW);
    delay(250);
    //dimmer blu
    for (int i = 0; i < 255; i++) {
      analogWrite(blu, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(blu, i);
      delay(10);
    }
    //dimmer rosso
    for (int i = 0; i < 255; i++) {
      analogWrite(rosso, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(rosso, i);
      delay(10);
    //dimmer giallo
    }
    for (int i = 0; i < 255; i++) {
      analogWrite(giallo, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(giallo, i);
      delay(10);
    }
    //dimmer verde
    for (int i = 0; i < 255; i++) {
      analogWrite(verde, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(verde, i);
      delay(10);
    }
    //dimmer bianco
    for (int i = 0; i < 255; i++) {
      analogWrite(bianco, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(bianco, i);
      delay(10);
    }
    //dimmer totale
    for (int i = 0; i < 255; i++) {
      analogWrite(blu, i);
      analogWrite(rosso, i);
      analogWrite(giallo, i);
      analogWrite(verde, i);
      analogWrite(bianco, i);
      delay(10);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(blu, i);
      analogWrite(rosso, i);
      analogWrite(giallo, i);
      analogWrite(verde, i);
      analogWrite(bianco, i);
      delay(10);
    }
  }
}
