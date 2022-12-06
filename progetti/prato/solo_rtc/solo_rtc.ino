/*
 * RTC & LCD
 *
 * Autore: Mauro Alfieri
 * Tw: @mauroalfieri
 *
 * Web: https://www.mauroalfieri.it
 */
 
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
 
#define BACKLIGHT 2
#define CONTRAST  3
 
char buffer[11];
 
RTC_DS1307 RTC;
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
 
void setup () {
    pinMode( BACKLIGHT, OUTPUT );
    pinMode( CONTRAST, OUTPUT );
    digitalWrite( BACKLIGHT, HIGH );
    analogWrite( CONTRAST, 40 );
 
    Wire.begin();
    RTC.begin();
    lcd.begin(16, 2);
 

    if (! RTC.isrunning()) {
      RTC.adjust(DateTime(__DATE__, __TIME__));
    }
}
 
void loop () {
 
    DateTime now = RTC.now();
    lcd.clear();
 
    sprintf(buffer,  "%02d/%02d/%d", now.day(), now.month(), now.year());
    lcd.setCursor(0,0);
    lcd.print( buffer );
 
    char buffer[10] = "";
 
    sprintf(buffer,  "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
    lcd.setCursor(0,1);
    lcd.print( buffer );
 
    delay(1000);
}
