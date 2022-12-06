int led1 = 12;
int led2 = 13;
#include <Wire.h>
#include <Keypad.h>

#define Password_Length 6 // Inserire la lunghezza della password
//se la password è lunga 7 caratteri inserire 8
//se la password è lunga 8 caratteri inserire 9 ecc..

int signalPin = 10;    // Pin su cui è collegato il relè 1
int signalPin2 = 11;    // Pin su cui è collegato il relè 2
int count = 0;
char Data[Password_Length];
char Master[Password_Length] = "1234#";   //Modifica la password
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(signalPin, OUTPUT);
  pinMode(signalPin2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(signalPin, HIGH);
}
void loop() {
  if (count > 10){
  count = 0;
  Serial.println(count);
  }
  
  customKey = customKeypad.getKey();
  if (customKey) {
    Data[data_count] = customKey;
    data_count++;
  }

  if (data_count == Password_Length - 1) {

    if (!strcmp(Data, Master)) {
      for(count = 0; count < 999; count ++)
        Serial.println(count);
        digitalWrite(signalPin, LOW);
        digitalWrite(signalPin2, LOW);
        delay(500);
        digitalWrite(signalPin, HIGH);
        digitalWrite(signalPin2, HIGH);
    }
    else {
      delay(3000);
    }
    clearData();
  }
}

void clearData() {
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
  return;
}
