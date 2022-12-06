// ACCENDERE E SPEGNERE UN LED CON IL TASTO 1 E DUE

#include <Keypad.h>

const byte ROWS = 4; // quattro righe
const byte COLS = 4; // quattro colonne
// Definizione del Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
// Connessione Keypad ROW0, ROW1, ROW2 e ROW3 ai pin Arduino
byte rowPins[ROWS] = { 9,8,7,6};
// Connessione Kaypad COL0, COL1 e COL2 ai pin Arduino
byte colPins[COLS] = { 5,4,3,2 };

// Creazione del Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledpin 13

void setup()
{
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  char key = kpd.getKey();
  if(key)  // Controllo del tasto premuto
  Serial.println(key);
  {
    switch (key)
    {
      case '0':
        digitalWrite(ledpin, LOW);
        break;
       
      case '1':
        digitalWrite(ledpin, HIGH);
        break;

      case '2':
      for(int i=0; i<5; i++)
        {
        digitalWrite(ledpin, HIGH);
        delay(2000);
        digitalWrite(ledpin, LOW);
        delay(2000);
        }
        break;
        
      case '3':
      for(int i=0; i<10; i++)
        {
        digitalWrite(ledpin, HIGH);
        delay(1000);
        digitalWrite(ledpin, LOW);
        delay(1000);
        }
    }
  }
}   
