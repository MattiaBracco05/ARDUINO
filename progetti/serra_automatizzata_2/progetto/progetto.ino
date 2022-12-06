//   Serra autonoma con sensore di temperatura e umidità (DHT11), igrometro, fotoresistore, display LCD 20x4, sensore livello acqua e relè.

const int valore_limite = 990; //Valore dell'igrometro al quale il relay sarà ON

//DHT11 Sensor:
#include "DHT.h"
#define DHTPIN 12     // Sensore collegato al PIN 12
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);


//I2C LCD:
#include <Wire.h> // Libreria WIRE (da aggiornare se non funziona)
#include <LiquidCrystal_I2C.h> // Libreria LCD I2C

// LCD I2C address
LiquidCrystal_I2C lcd(2, 1, 0, 4, 5, 6, 7, 3); // da cambiare se si ha un modello diverso
int led_allarm;


void setup()
{
  pinMode(led_alarm, OUTPUT);
  // PIN 9 al Relè - IN1
  Serial.begin(9600);
  pinMode(9, OUTPUT);

  // PIN 10 al relè - IN2 //VENTOLA
  pinMode(10, OUTPUT);

  //PIN 13 al LED
  pinMode (13, OUTPUT);

  //I2C LCD
  Serial.begin(9600);
  lcd.begin(20, 4);
  Serial.println("SERRA AUTO");

  // Avvio sensore DHT11
  dht.begin();
}


void loop()
{
  //Livello Acqua
  int water = analogRead(A1);
  Serial.print ("acqua: ");
  Serial.println(water, DEC);  // Stampa il valore decimale del sensore di livello acqua

  if (water >= 100) {

    lcd.setCursor(0, 3); // Indica posizione del cursore su LCD
    lcd.print("Acqua: OK"); // Stampa su LCD il testo
  }
  else
  {
    lcd.setCursor(0, 3); // Indica posizione del cursore su LCD
    lcd.print("Acqua: BASSA"); // Stampa su LCD il testo
    digitalWrite(led_alarm, HIGH);
    delay(500);
    digitalWrite(led_alarm, LOW);
    delay(500);
    digitalWrite(led_alarm, HIGH);
    delay(500);
    digitalWrite(led_alarm, LOW)
    delay(2000); // Intervallo di 2 secondi
  }

  // Igrometro
  int igro = analogRead(A3); // Legge il valore analogico
  int umdtrr = 0; // Variabile umidità suolo
  umdtrr = map (igro, 100, 990, 100, 0); // converto il valore analogico in percentuale
  Serial.print("Umidità del terreno: ");
  Serial.print(umdtrr);
  Serial.println ("%"); //Stampa a schermo il valore

  if (igro <= valore_limite)
    digitalWrite(9, LOW); // Attiva Relè 1
  else
    digitalWrite(9, HIGH); // Spegni Relè 1
  delay(2000); // Attende due secondi


  // Lettura umidità e temperatura del sensore DHT11
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  // Misura la temperatura e se maggiore di 35 gradi attiva relè per accendere la ventola
  if (t >= 35 )
    digitalWrite (10, HIGH); // Attiva Relè 2 (accende la ventola)
  else
    digitalWrite (10, LOW); // Spegni Relè 2  (spegne la ventola)
  delay (2000);

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("C, Umid: ");
  Serial.print(h);
  Serial.println("%");


  // impostare cursore sulla prima riga:
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.print(t);
  lcd.print("C");

  // imposta cursore sulla seconda riga:
  lcd.setCursor(0, 1);
  lcd.print("Umidita': ");
  lcd.print(h);
  lcd.print("%");

  // imposta il cursore sulla terza riga:
  lcd.setCursor(0, 2);
  lcd.print("Umidita' terra: ");
  lcd.print(umdtrr);
  lcd.print("%");

}
