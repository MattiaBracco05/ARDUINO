/* FILE:    RC522_RFID_Module_Example
   DATE:    13/07/2016
   VERSION: 0.1
    
Autore Fancello Salvatore

PINOUT:
RC522 MODULE    Uno/Nano    
SDA             D53
SCK             D52
MOSI            D51
MISO            D50
IRQ             N/A
GND             GND
RST             D5
3.3V            3.3V

*/
 
#include <SPI.h>
#include <RFID.h>
/* Vengono definiti PIN del RFID reader*/
#define SDA_DIO 53  // 53 per Arduino Mega
#define RESET_DIO 5
#define delayRead 1000 // Time of delay 
 
/* Viene creata una istanza della RFID libreria */
RFID RC522(SDA_DIO, RESET_DIO); 
 
 
 
void setup()
{ 
  Serial.begin(9600);
  /* Abilita SPI*/
  SPI.begin(); 
  /* Viene inizilizzato RFID reader */
  RC522.init();
  Serial.println("Setup");
}
 
void loop()
{
  /* Temporary loop counter */
  byte i;
   
  // Se viene letta una tessera
  if (RC522.isCard())
  {
    // Viene letto il suo codice 
    RC522.readCardSerial();
    String codiceLetto ="";
    Serial.println("Codice delle tessera letto:");
     
    // Viene caricato il codice della tessera, all'interno di una Stringa
    for(i = 0; i <= 4; i++)
    {
      codiceLetto+= String (RC522.serNum[i],HEX);
      codiceLetto.toUpperCase();
    }
    Serial.println(codiceLetto);
    delay(delayRead);
    Serial.println();
    Serial.println();
  }
}
