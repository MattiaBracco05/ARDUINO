//INCLUSIONE DELLE LIBRERIE--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "Nextion.h"
#include "DHT.h"
#define DHTPIN 4     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

//DICHIARAZIONE DELLE VARIABILI----------------------------------------------------------------------------------------------------------------------------------------------------------------
const int zona1 = 6;
const int zona2 = 7;
int totTimer = 0;

//DICHIARAZIONE DEGLI OGGETTI------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Declare your Nextion objects - (es. page id = 0, component id = 1, component name = "b0")
//----------------PAGE: HOME (id n.0)---------------
NexText zone1 = NexText(0, 3, "zone1");
NexText zone2 = NexText(0, 4, "zone2");
//--------------PAGE: SENSORI (id n.2)---------------
NexText valTemp = NexText(2, 3, "valTemp");
NexText valHumidity = NexText(2, 5, "valHumidity");
NexText valLastRain = NexText(2, 9, "valLastRain");
NexText valLand = NexText(2, 11, "valLand");
NexText valPioggia = NexText(2, 7, "valPioggia");
NexButton bUpdate = NexButton(2, 14, "bUpdate");
//------------PAGE: CTRL MANUALE (id n.3)------------
//controllo zona 1
NexButton bOnZone1 = NexButton(3, 5, "bOnZone1");
NexButton bOffZone1 = NexButton(3, 6, "bOffZone1");
NexText textState1 = NexText(3, 9, "textState1");
//controllo zona 2
NexButton bOnZone2 = NexButton(3, 7, "bOnZone2");
NexButton bOffZone2 = NexButton(3, 8, "bOffZone2");
NexText textState2 = NexText(3, 10, "textState2");
//timer
NexButton bUp = NexButton(3, 13, "bUp");
NexButton bDown = NexButton(3, 14, "bDown");
NexButton bConfirmTimer = NexButton(3, 12, "bConfirmTimer");
NexText totTime = NexText(3, 15, "totTime");

//LISTA DEGLI OGGETTI BUTTON REGISTRATI--------------------------------------------------------------------------------------------------------------------------------------------------------
// Register a button object to the touch event list.
NexTouch *nex_listen_list[] = {
  &bOnZone1,
  &bOffZone1,
  &bOnZone2,
  &bOffZone2,
  &bUpdate,
  &bUp,
  &bDown,
  &bConfirmTimer,
  NULL
};

//CONTROLLO MANUALE DELLE 2 ZONE---------------------------------------------------------------------------------------------------------------------------------------------------------------
//Button bOnZone1 component pop callback function. When the ON button is released, the RELAY turns on and the state text changes.
void bOnZone1PopCallback(void *ptr) {
  zone1.setText("Stato: ON");
  textState1.setText("Stato: ON");
  digitalWrite(zona1, HIGH);
}
//Button bOffZone1 component pop callback function. When the OFF button is released, the RELAY turns off and the state text changes.
void bOffZone1PopCallback(void *ptr) {
  zone1.setText("Stato: OFF");
  textState1.setText("Stato: OFF");
  digitalWrite(zona1, LOW);
}
//Button bOnZone2 component pop callback function. When the ON button is released, the RELAY turns on and the state text changes.
void bOnZone2PopCallback(void *ptr) {
  zone2.setText("Stato: ON");
  textState2.setText("Stato: ON");
  digitalWrite(zona2, HIGH);
}
//Button bOffZone2 component pop callback function. When the OFF button is released, the RELAY turns off and the state text changes.
void bOffZone2PopCallback(void *ptr) {
  zone2.setText("Stato: OFF");
  textState2.setText("Stato: OFF");
  digitalWrite(zona2, LOW);
}
//CONTROLLO TASTO UPDATE-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void bUpdatePopCallback(void *ptr) {
  //Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  //Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    return;
  }
  // Update temperature in Celsius
  static char temperatureCTemp[6];
  dtostrf(t, 6, 2, temperatureCTemp);
  valTemp.setText(temperatureCTemp);

  // Update humidity percentage text and progress bar
  char hTemp[10] = {0}; 
  utoa(int(h), hTemp, 10);
  valHumidity.setText(hTemp);
  //jHumidity.setValue(int(h));
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup(void) {
  Serial.begin(9600);
  
  dht.begin();
  
  pinMode(zona1, OUTPUT);
  pinMode(zona2, OUTPUT);
  
  // You might need to change NexConfig.h file in your ITEADLIB_Arduino_Nextion folder
  // Set the baudrate which is for debug and communicate with Nextion screen
  Serial.println("SETTING: Display Nextion Start...");
  nexInit();
  
  //REGISTRAZIONE POP EVENT CALLBACK-----------------------------------------------------------------------------------------------------------------------------------------------------------
  // Register the pop event callback function of the components
  bOnZone1.attachPop(bOnZone1PopCallback, &bOnZone1);
  bOffZone1.attachPop(bOffZone1PopCallback, &bOffZone1);
  bOnZone2.attachPop(bOnZone2PopCallback, &bOnZone2);
  bOffZone2.attachPop(bOffZone2PopCallback, &bOffZone2);
  //bUpdate.attachPop(bUpdatePopCallback, &bUpdate);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop(void) {
  /*
     When a pop or push event occured every time,
     the corresponding component[right page id and component id] in touch event list will be asked.
  */
  nexLoop(nex_listen_list);
}
