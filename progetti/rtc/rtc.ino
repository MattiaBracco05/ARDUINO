// La Wire.h vi serve per l'interfaccia I2C
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Dom", "Lun", "Mar", "Mer", "Gio", "Ven", "Sab"};

void setup () {

#ifndef ESP8266
 while (!Serial); // Leonardo/Micro/Zero
#endif

Serial.begin(9600);

delay(3000);

if (! rtc.begin()) {
 Serial.println("Erorre nella comunicazione con il modulo RTC");
 while (1);
 }

if (rtc.lostPower()) {
 Serial.println("Rilevata perdita di orario del modulo RTC");
 // uso la data e l'ora di compilazione dello sketch
 rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
 // Puoi usare la rtc.adjust anche per settare manualmente data e ora. I parametri sono AA,MM,GG,HH,MM,SS
 // per il 21 gennaio 2014 alle 3 del mattino puoi usare:
 // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
 }
}

void loop () {
 DateTime now = rtc.now();
 
 Serial.print(now.year(), DEC);
 Serial.print('/');
 Serial.print(now.month(), DEC);
 Serial.print('/');
 Serial.print(now.day(), DEC);
 Serial.print(" (");
 Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
 Serial.print(") ");
 Serial.print(now.hour(), DEC);
 Serial.print(':');
 Serial.print(now.minute(), DEC);
 Serial.print(':');
 Serial.print(now.second(), DEC);
 Serial.println();
 delay(3000);
}
