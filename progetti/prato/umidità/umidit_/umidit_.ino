#define buttonup 13 //pulsante SU al pin 13
#define buttondown 12 //Pulsante GIU al pin 12
#define buttonselect 11 //Pulsante SELEZIONA al pin 9

#define red A2 //LED rosso al pin A2
#define green A3 //LED verde al pin A3

#define settore1 10 //Relè 1 al pin 10
#define settore2 9 //Rele 2 al pin 9

#define umidity A0 //sensore umidità terreno al pin A0
const int soglia_critica = 300; //soglia critica umidità terreno
int valore; //variabile umidità terreno

//Funzioni dei vari cicli
void changeMenu();
void dispMenu();
void mostraMsg();

void controlsettore1();
void controlsettore2();
void umidita();


//Variabili globali
char menu = 0x01;
char set1 = 0x00, set2 = 0x00 , set3 = 0x00;
boolean t_buttonup, t_buttondown, t_buttonselect;


//DISPLAY Mappa Hardware

#include <LiquidCrystal.h>

LiquidCrystal lcd ( 2,   //RS
                    3,  //EN
                    4,  //D4
                    5,  //D5
                    6,  //D6
                    7); //D7

void setup() {

  lcd.begin(16, 2);

  pinMode(buttonup, INPUT_PULLUP);
  pinMode(buttondown, INPUT_PULLUP);
  pinMode(buttonselect, INPUT_PULLUP);

  pinMode(red, OUTPUT); //LED ROSSO
  pinMode(green, OUTPUT); //LED VERDE
  pinMode(settore1, OUTPUT); //RELÈ 1 (settore 1)
  pinMode(settore2, OUTPUT); //RELÈ 2 (settore 2)

  digitalWrite (settore1, LOW);    //Imposto inizialmente il relè1 (settore 1)  allo stato basso (spento)
  digitalWrite (settore2, LOW);    //Imposto inizialmente il relè2 (settore 2) allo stato basso (spento)

  t_buttonup   = 0x00;             //Inizializza le variabili come ZERO
  t_buttondown = 0x00;
  t_buttonselect  = 0x00;
}

void loop() {
  changeMenu();               //Menu di scambio
  dispMenu();                //Selezionare il menu

  int valore = analogRead(A0); //Legge il valore analogico
  Serial.println(valore); //Stampa a schermo il valore
}
//Funzioni
void changeMenu() {

  if (digitalRead(buttonup) == 0x00) {     //Setta la variabile in 1 se si preme il pulsante UP
    t_buttonup = 0x01;
  }

  if (digitalRead(buttondown) == 0x00) {    //Setta la variabile in 1 se si preme il pulsante DOWN
    t_buttondown = 0x01;
  }

  if (digitalRead(buttonup) && t_buttonup) {
    t_buttonup = 0x00;
    lcd.clear();        //Cancella Schermo lcd
    menu++;
    if (menu > 0x04) {
      menu = 0x01;
    }
  }
  if (digitalRead(buttondown) && t_buttondown) {
    t_buttondown = 0x00;
    lcd.clear();
    menu--;
    if (menu < 0x01) {
      menu = 0x04;
    }
  }
}

void dispMenu() {
  switch (menu) {
    case 0x01:
      controlsettore1(); //Funzione controllo settore 1
      break;
    case 0x02:
      controlsettore2(); //Funzione controllo settore 2
      break;
    case 0x03:
      umidita(); //Funzione controllo umidità
      break;
    case 0x04:
      controlRTC(); //Funzione controllo modulo RTC
      break;
  }
}

/*Ciclo per la funzione controllo settore1*/
void controlsettore1() {
  lcd.setCursor(0, 0);
  lcd.print("ACCENSIONE SET 1");

  if (digitalRead(buttonselect) == 0x00) {
    t_buttonselect = 0x01;
  }
  if (digitalRead(buttonselect) && t_buttonselect) {
    t_buttonselect = 0x00;
    set1++;

    if (set1 > 2) {
      set1 = 0x01;
    }
    switch (set1) {
      case 0x01:
        lcd.clear();
        lcd.setCursor(0, 1);
        digitalWrite (settore1, HIGH);  //Accendo il settore 1
        lcd.print("SET 1 ON");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0, 1);
        digitalWrite (settore1, LOW);  //Spengo il settore 1
        lcd.print("SET 1 OFF");
        break;
    }
  }
}
/*Ciclo per la funzione controllo settore 2*/
void controlsettore2() {
  lcd.setCursor(0, 0);
  lcd.print("ACCENSIONE SET 2");

  if (digitalRead(buttonselect) == 0x00) {
    t_buttonselect = 0x01;
  }
  if (digitalRead(buttonselect) && t_buttonselect) {
    t_buttonselect = 0x00;
    set2++;

    if (set2 > 2) {
      set2 = 0x01;
    }
    switch (set2) {
      case 0x01:
        lcd.clear();
        lcd.setCursor(0, 1);
        digitalWrite (settore2, HIGH);
        lcd.print("SET 2 ON");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0, 1);
        digitalWrite (settore2, LOW);
        lcd.print("SET 2 OFF");
        break;
    }
  }
}

/*Ciclo per la funzione controllo umidità*/
void umidita() {
  lcd.setCursor(0, 0);
  lcd.print("Umidità: ");
  lcd.setCursor(0, 1);
  lcd.print(valore);
  delay(10);
}


/*Ciclo per la funzione controllo modulo RTC*/
void controlRTC() {
  lcd.setCursor(0, 0);
  lcd.print("MODULO RTC");

  if (digitalRead(buttonselect) == 0x00) {
    t_buttonselect = 0x01;
  }
  if (digitalRead(buttonselect) && t_buttonselect) {
    t_buttonselect = 0x00;
    set3++;

    if (set3 > 2) {
      set3 = 0x01;
    }
    switch (set3) {
      case 0x01:
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("RTC");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("RTC");
        break;
    }
  }
}
