// 025 - PROGETTO SERRA AUTOMATICA 100 PROGETTI CON ARDUINO UNO -
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
//INCLUDIAMO LE LIBRERIE UTILIZZATE NEL PROGETTO
#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

DS3231 clock;
RTCDateTime dt;
LiquidCrystal_I2C lcd(0x26, 20, 4); //Indirizzo I2C, Colonne, Righe del Display

#define DHTPIN 3
#define DHTTYPE DHT11 //Seleziona il tipo di sensore
DHT dht(DHTPIN, DHTTYPE);

#define Rele_Luci 10
#define Rele_Vent 11
#define Rele_Idro 12
#define Rele_Conc 13


//--------------------------------------------------------------------
void setup() {
  //IMPOSTIAMO I PIN COME INGRESSI E USCITE
  pinMode(Rele_Luci, OUTPUT);
  pinMode(Rele_Vent, OUTPUT);
  pinMode(Rele_Idro, OUTPUT);
  pinMode(Rele_Conc, OUTPUT);

  //SPEGNIAMO I RELE AD OGNI AVVIO
  digitalWrite(Rele_Luci, HIGH);
  digitalWrite(Rele_Vent, HIGH);
  digitalWrite(Rele_Idro, HIGH);
  digitalWrite(Rele_Conc, HIGH);
  
  //INIZILIZZIAMO LE COMONICAZIONI SERIALI 
  Serial.begin(9600);
  Serial.println("Inizializziamo il Timer");
  clock.();
  clock.setDateTime(__DATE__, __TIME__);
  dht.begin();

//--------------------------------------------------------------------
  //SPLASH SCREEN INIZIALE
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SERRA AUTOMATICA");
  lcd.setCursor(0, 1);
  lcd.print("--------------------");
  lcd.setCursor(0, 2);
  lcd.print("BRACCO MATTIA");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SERRA AUTOMATICA");
  lcd.setCursor(0, 1);
  lcd.print("--------------------");
  delay(2000);
  lcd.clear();
//-------------------------------------------------------------------- 
  //TEMA LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SERRA AUTO");
  lcd.setCursor(0, 1);
  lcd.print("--------");
  lcd.setCursor(0, 2);
  lcd.print("L V I C");
  lcd.setCursor(0, 3);
  lcd.print("0 0 0 0");

}

//--------------------------------------------------------------------
//FUNZIONE PER AGGIUNGERE UNO ZERO AI VALORI CON UNA SOLA CIFRA
void p2dig(uint8_t P){
  if (P < 10) lcd.print("0");
  lcd.print(P);
}
//--------------------------------------------------------------------
void loop() {
  Ambiente();
  Orologio();
  Luci();
  Idro();
  Vent();
}

//--------------------------------------------------------------------
//FUNZIONI INTERNE AL PROGRAMMA
void Orologio(){
  //STANPIAMO SUL DISPLAY DATA E ORA
  dt = clock.getDateTime();
  lcd.setCursor(10, 0);
  p2dig(dt.day);
  lcd.print("/");
  p2dig(dt.month);
  lcd.print("/");
  lcd.print(dt.year);
  
  lcd.setCursor(12, 1);
  p2dig(dt.hour);
  lcd.print(":");
  p2dig(dt.minute);
  lcd.print(":");
  p2dig(dt.second);
  delay(1000);
  }
void Ambiente(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(10, 2);
  lcd.print("H: ");
  lcd.print(h);
  lcd.print(" %");
  lcd.setCursor(10, 3);
  lcd.print("T: ");
  lcd.print(t);
  lcd.print(" C");
  }
