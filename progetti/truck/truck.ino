/*
  Bracco Mattia, Lego Technic && Arduino
*/

#include <LiquidCrystal.h>
#include <Stepper.h>
#include <IRremote.h>
#include "DHT.h"

//pin sensore colore
#define S0 52
#define S1 50
#define S2 48
#define S3 46
#define sensorOut 44

//numero di steps per una rivoluzione interna
#define STEPS  32

//sensore temperatura e umidità
#define DHTPIN 51
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

//definisco il display LCD 16 X 2
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//definisco il motore passo a passo sui pin 22 - 25
Stepper small_stepper(STEPS, 22, 23, 24, 25);

//definisco il sensore per la temperatura e per l' umidità
DHT dht(DHTPIN, DHTTYPE);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Steps2Take;

int receiver = 53;

//sensore colore
int frequency = 0, color = 0, Red = 0, Blue = 0, Green = 0;

int i = 0;

//luci
int lamp_1 = A8, lamp_2 = A9, luci_cassone = A10, function_led = 0;

//led RGB
int red = 3, green = 4, blu = 5, function_color = 0, function_luci = 0;
long randomRed, randomGreen, randomBlu;

//laser
int laser = A0, pin_sicurezza_laser = 2, sicurezza_laser = 0, function_laser = 0;

//CONTROLLO TENSIONE DELLA BATTERIA
int PinBatteria = A7, ValPinBatteria; //PinBatteria = pin dove misuro la tensione
float ValPinPerc, ValoreBatteria, resistenza, R1 = 10000, R2 = 10000; //R1 e R2 = VALORI RESISTENZE

IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// caratteri personalizzati
byte lucchettoChiuso[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11011,
  0b11011,
  0b11111
};

byte lucchettoAperto[8] = {
  0b01110,
  0b10000,
  0b10000,
  0b10000,
  0b11111,
  0b11011,
  0b11011,
  0b11111
};

byte simboloMenu[8] = {
  0b11111,
  0b11111,
  0b00000,
  0b11111,
  0b11111,
  0b00000,
  0b11111,
  0b11111
};

byte luceSpenta[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01010,
  0b01110,
  0b01110,
  0b00100
};

byte luceAccesa[8] = {
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b01110,
  0b01110,
  0b00100
};

byte batteriaCarica[8] = {
  0b00100,
  0b11011,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte batteriaMezza[8] = {
  0b00100,
  0b11011,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte batteriaScarica[8] = {
  0b00100,
  0b11011,
  0b10101,
  0b10101,
  0b10001,
  0b10101,
  0b10001,
  0b11111
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {

  //pin del sensore di colore
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  //pin del controllo della batterria
  pinMode (PinBatteria, INPUT);

  //pin dei led
  pinMode(lamp_1, OUTPUT);
  pinMode(lamp_2, OUTPUT);
  pinMode(luci_cassone, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blu, OUTPUT);

  //pin del laser
  pinMode(laser, OUTPUT);
  pinMode(pin_sicurezza_laser, INPUT);


  //spengo tutte le luci
  digitalWrite(lamp_1, LOW);
  digitalWrite(lamp_2, LOW);
  digitalWrite(luci_cassone, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blu, LOW);

  //spengo il laser
  digitalWrite(laser, LOW);

  //imposto frequency-scaling al 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  //inizializzo il display LCD
  lcd.begin(16, 2);
  lcd.createChar(0, lucchettoChiuso);
  lcd.createChar(1, lucchettoAperto);
  lcd.createChar(2, simboloMenu);
  lcd.createChar(3, luceSpenta);
  lcd.createChar(4, luceAccesa);
  lcd.createChar(5, batteriaCarica);
  lcd.createChar(6, batteriaMezza);
  lcd.createChar(7, batteriaScarica);

  //inizializzo il sensore della temperatura
  dht.begin();

  //inizio la ricezione
  irrecv.enableIRIn();

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //INIZIO DELLO START UP
  lcd.clear();
  delay(10);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
  lcd.print("System Locked");
  delay(1000);
  lcd.clear();
  delay(10);
  lcd.write(byte(2));
  lcd.setCursor(0, 1);
  lcd.print("configuration...");
  delay(1000);
  lcd.clear();
  delay(10);
  lcd.write(byte(1));
  lcd.setCursor(0, 1);
  lcd.print("System Unlocked");
  delay(1000);
  //ROSSO CRESCENTE - DECRESCENTE
  for (int i = 0; i < 255; i++) {
    analogWrite(red, i);
    delay(10);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(red, i);
    delay(10);
  }
  digitalWrite(red, LOW);
  //LMAPEGGIANTI
  for (int i = 0; i < 5; i++) {
    digitalWrite(lamp_1, HIGH);
    digitalWrite(lamp_2, LOW);
    delay(250);
    digitalWrite(lamp_1, LOW);
    digitalWrite(lamp_2, HIGH);
    delay(250);
  }
  digitalWrite(lamp_1, HIGH);
  digitalWrite(lamp_2, HIGH);
  digitalWrite(luci_cassone, HIGH);
  delay(1000);
  lcd.clear();
  delay(10);
  lcd.print("    WELCOME");
  lcd.setCursor(0, 1);
  lcd.print(" Mattia Bracco");
  //FINE DELLO START UP

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Serial.begin(9600);
  resistenza = (R1 + R2) / R2;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

  sicurezza_laser = digitalRead(pin_sicurezza_laser);

  if (sicurezza_laser == LOW) { //LASER DISABILITATO
    function_laser = 0;
  }

  if (sicurezza_laser == HIGH) { //LASER ABILITATO
  }

  if ((function_laser > 2) || (function_laser < 0)) { //VALORE LIMITE FUNCTION LASER
    function_laser = 0;
  }

  if (function_laser == 0) { //LASER SPENTO
    digitalWrite(laser, LOW);
  }

  if (function_laser == 1) { //LASER ACCESO FISSO
    digitalWrite(laser, HIGH);
  }

  if (function_laser == 2) { //LASER MODALITA' SPARO
    digitalWrite(laser, HIGH);
    delay(100);
    digitalWrite(laser, LOW);
    delay(100);
    digitalWrite(laser, HIGH);
    delay(100);
    digitalWrite(laser, LOW);
    delay(250);
    digitalWrite(laser, HIGH);
    delay(250);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if ((function_led > 3) || (function_led < 0)) { //VALORE LIMITE FUNCTION LED
    function_led = 0;
  }

  if (function_led == 0) { //LAMP SPENTI
    digitalWrite(lamp_1, LOW);
    digitalWrite(lamp_2, LOW);
  }

  if (function_led == 1) { //LAMP ACCESI FISSI
    digitalWrite(lamp_1, HIGH);
    digitalWrite(lamp_2, HIGH);
  }

  if (function_led == 2) { //LAMP INSIEME
    digitalWrite(lamp_1, LOW);
    digitalWrite(lamp_2, LOW);
    delay(250);
    digitalWrite(lamp_1, HIGH);
    digitalWrite(lamp_2, HIGH);
    delay(250);
  }

  if (function_led == 3) { //LAMP ALTERNATI
    digitalWrite(lamp_1, HIGH);
    digitalWrite(lamp_2, LOW);
    delay(250);
    digitalWrite(lamp_1, LOW);
    digitalWrite(lamp_2, HIGH);
    delay(250);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if ((function_color > 1) || (function_color < 0)) { //VALORE LIMITE FUNCTION COLOR
    function_color = 0;
  }

  if (function_color == 0) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blu, LOW);
  }
  
  if (function_color == 1) {
    GetColors();
    analogWrite(red, map(Red, 15, 60, 255, 0));
    analogWrite(green, map(Green, 30, 55, 255, 0));
    analogWrite(blu, map(Blue, 13, 45, 255, 0));
    delay(500);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if ((function_luci > 2) || (function_luci < 0)) { //VALORE LIMITE FUNCTION LUCI
    function_luci = 0;
  }

  if (function_luci == 0) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blu, LOW);
  }
  
  if (function_luci == 1) {
    //random 0 - 255 per Red, Green e Blu
    randomRed = random(256);
    randomGreen = random(256);
    randomBlu = random(256);
    analogWrite(red, randomRed);
    analogWrite(green, randomGreen);
    analogWrite(blu, randomBlu);
    delay(1000);
  }

  if (function_luci == 2) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blu, LOW);
    for (int i = 0; i < 255; i++) {
      analogWrite(red, i);
      delay(5);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(red, i);
      delay(5);
    }
    for (int i = 0; i < 255; i++) {
      analogWrite(green, i);
      delay(5);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(green, i);
      delay(5);
    }
    for (int i = 0; i < 255; i++) {
      analogWrite(blu, i);
      delay(5);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(blu, i);
      delay(5);
    }
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blu, LOW);
    delay(1000);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ValPinBatteria = analogRead(PinBatteria);
  //leggerò 1023 quando ho 5 volt sul pin, quindi scalo 0-1023 in 0-500.
  ValPinPerc = map (ValPinBatteria, 0, 1023, 0, 500);
  //ora divido tutto per 100 perchè sopra ho scalato da 0 a 500 anzichè da 0 a 5V
  ValoreBatteria = ValPinPerc * resistenza / 100 ;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  float h = dht.readHumidity();
  // LEGGO LA TEMPERATURA IN GRADI CELSIOUS (default)
  float t = dht.readTemperature();
  // LEGGO LA TEMPERATURA IN FAHRENHEIT (se Fahrenheit = true)
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //verifico se ho ricevuto un segnale
  if (irrecv.decode(&results)) {

    switch (results.value) {

      //TASTO POWER - Luci On
      case 0xFFA25D:
        lcd.clear();
        delay(10);
        lcd.write(byte(4));
        lcd.setCursor(0, 1);
        lcd.print("LIGHT ON");
        digitalWrite(luci_cassone, HIGH);
        delay(1000);
        lcd.clear();
        delay(10);
        break;

      //TASTO 0 - Luci Off
      case 0xFF6897:
        lcd.clear();
        delay(10);
        lcd.write(byte(3));
        lcd.setCursor(0, 1);
        lcd.print("LIGHT OFF");
        digitalWrite(luci_cassone, LOW);
        digitalWrite(lamp_1, LOW);
        digitalWrite(lamp_2, LOW);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(blu, LOW);
        function_led = 0;
        delay(1000);
        lcd.clear();
        delay(10);
        break;

      //TASTO FUNTION - Modalità dei lampeggianti
      case 0xFFE21D:
        function_led = function_led + 1;
        lcd.clear();
        delay(10);
        lcd.print("LED MODE");
        lcd.setCursor(0, 1);
        lcd.print(function_led);
        delay(1000);
        lcd.clear();
        delay(10);
        break;

      //TASTO EQ - Tensione della Batteria
      case 0xFF9867:
        lcd.clear();
        delay(10);
        lcd.print("TENSIONE BATT.");
        lcd.setCursor(0, 1);
        lcd.print(ValoreBatteria);
        lcd.setCursor(6, 1);
        lcd.print("V");
        delay(1000);
        lcd.clear();
        delay(10);
        if (ValoreBatteria > 8) {
          lcd.print("STATO BATTERIA:");
          lcd.setCursor(0, 1);
          lcd.write(byte(5));
          delay(1000);
          lcd.clear();
          delay(10);
        }
        else {
          if (ValoreBatteria < 6) {
            lcd.print("STATO BATTERIA:");
            lcd.setCursor(0, 1);
            lcd.write(byte(7));
            delay(1000);
            lcd.clear();
            delay(10);
          }
          else {
            lcd.print("STATO BATTERIA:");
            lcd.setCursor(0, 1);
            lcd.write(byte(6));
            delay(1000);
            lcd.clear();
            delay(10);
          }
        }
        break;

      //TASTO UP - Compie una rotazione in senso orario (imposta modalità guida)
      case 0xFF906F:
        lcd.clear();
        delay(10);
        lcd.print("ROTATE CV");
        lcd.setCursor(0, 1);
        lcd.print("DRIVE MODE");
        small_stepper.setSpeed(500);
        Steps2Take  =  2048;
        small_stepper.step(Steps2Take);
        delay(1000);
        lcd.clear();
        delay(10);
        break;

      //TASTO DOWN - Compie una rotazione in senso antiorario (imposta il selettore sulla strumentazione)
      case 0xFFE01F:
        lcd.clear();
        delay(10);
        lcd.print("ROTATE CCW");
        lcd.setCursor(0, 1);
        lcd.print("STRUMENTAZIONE");
        small_stepper.setSpeed(500);
        Steps2Take  =  -2048;
        small_stepper.step(Steps2Take);
        delay(1000);
        lcd.clear();
        delay(10);
        break;

      //TASTO ST / REPT - Modalità del laser (solo se sicurezza laser è a 1)
      case 0xFFB04F:
        if (sicurezza_laser == 1) {
          function_laser = function_laser + 1;
          lcd.clear();
          delay(10);
          lcd.print("LASER MODE");
          lcd.setCursor(0, 1);
          lcd.print(function_laser);
          delay(1000);
          lcd.clear();
          delay(10);
        }
        else {
          lcd.clear();
          delay(10);
          lcd.print("ERROR !");
          lcd.setCursor(0, 1);
          lcd.print("LASER DISABLED");
          delay(1000);
          lcd.clear();
          delay(10);
        }
        break;

      //TASTO PLAY - Temperatura e umidità
      case 0xFF02FD:
        lcd.clear();
        delay(10);
        lcd.print("TEMPERATURA:");
        lcd.setCursor(0, 1);
        lcd.print(t);
        lcd.setCursor(6, 1);
        lcd.print("C");
        delay(1000);
        lcd.clear();
        delay(10);
        lcd.print("UMIDITA'");
        lcd.setCursor(0, 1);
        lcd.print(h);
        lcd.setCursor(6, 1);
        lcd.print("%");
        delay(1000);
        lcd.clear();
        delay(10);
        break;

      //TASTO 9 - Rileva il colore e impostalo sui led RGB
      case 0xFF52AD:
        lcd.clear();
        delay(10);
        lcd.print("TASTO 9");
        lcd.setCursor(0, 1);
        lcd.print("RILEV. COLORE");
        delay(1000);
        lcd.clear();
        delay(10);
        function_color = function_color + 1;
        break;

      //TASTO VOL+ led RGB (gioco di luce + 1)
      case 0xFF629D:
        lcd.clear();
        delay(10);
        function_luci = function_luci + 1;
        lcd.print("GIOCHI DI LUCE");
        lcd.setCursor(0, 1);
        lcd.print(function_luci);
        delay(1000);
        lcd.clear();
        delay(10);
        break;

      //TASTO VOL- led RGB (gioco di luce - 1)
      case 0xFFA857:
        lcd.clear();
        delay(10);
        function_luci = function_luci - 1;
        lcd.print("GIOCHI DI LUCE");
        lcd.setCursor(0, 1);
        lcd.print(function_luci);
        delay(1000);
        lcd.clear();
        delay(10);
        break;

    }

    //ricevo il prossimo segnale
    irrecv.resume();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GetColors()  {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);  Red = pulseIn(sensorOut, digitalRead(sensorOut) == HIGH ? LOW : HIGH);
  delay(20);
  digitalWrite(S3, HIGH);
  Blue = pulseIn(sensorOut, digitalRead(sensorOut) == HIGH ? LOW : HIGH);
  delay(20);
  digitalWrite(S2, HIGH);
  Green = pulseIn(sensorOut, digitalRead(sensorOut) == HIGH ? LOW : HIGH);
  delay(20);
}
