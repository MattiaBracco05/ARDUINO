void setup() {
  // put your setup code here, to run once:
  int led_blu = 13;
  int led_verde = 12;
  int led_giallo = 11;
  pinMode(led_blu, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_giallo, OUTPUT);
  digitalWrite(led_blu, LOW);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_giallo, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //3 giri blu-giallo-verde
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH),
  delay(250);
  digitalWrite(12, LOW);
  delay(250);
  //2 giro
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH),
  delay(250);
  digitalWrite(12, LOW);
  delay(250);
  //3 giro
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH),
  delay(250);
  digitalWrite(12, LOW);
  delay(250);
  //3 giri blu-verde-giallo
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(250);
  //2 giro
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(250);
  //3 giro
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(250);
  //flash
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(250);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(250);
  //lampeggio blu
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);
  //lampeggio giallo
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(250);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(250);
  //lampeggio verde
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  delay(250);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  delay(250);
  //5 giri blu-giallo-verde veloci
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH),
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
  //2 giro
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH),
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
  //3 giro
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH),
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
  //4 giro
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH),
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
  // 5 giro
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH),
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
 //5 giri blu-verde-giallo veloci
 digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  //2 giro
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  //3 giro
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  //4 giro
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  //5 giro
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  //blu fisso verde e giallo lampeggio
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(13, LOW);
  delay(250);
  //giallo fisso blu e verde lampeggio
  digitalWrite(11, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(250);
  //verde fisso blu e giallo lampeggio
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  delay(250);
}
