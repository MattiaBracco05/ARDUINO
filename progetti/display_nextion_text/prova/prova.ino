#include "Nextion.h"
#include "DHT.h"
#define DHTPIN 4     // what digital pin we're connected to
// LED pins
const int led1 = 8;

// Declare your Nextion objects - (es. page id = 0, component id = 1, component name = "b0")
NexText tState = NexText(0, 2, "tState");
NexButton bOn = NexButton(0, 3, "bOn");
NexButton bOff = NexButton(0, 4, "bOff");

// Register a button object to the touch event list.
NexTouch *nex_listen_list[] = {
  &bOn,
  &bOff,
  NULL
};

/*
   Button bOn component pop callback function.
   When the ON button is released, the LED turns on and the state text changes.
*/
void bOnPopCallback(void *ptr) {
  tState.setText("State: on");
  digitalWrite(led1, HIGH);
}

/*
   Button bOff component pop callback function.
   When the OFF button is released, the LED turns off and the state text changes.
*/
void bOffPopCallback(void *ptr) {
  tState.setText("State: off");
  digitalWrite(led1, LOW);
}

void setup(void) {
  Serial.begin(9600);

  // You might need to change NexConfig.h file in your ITEADLIB_Arduino_Nextion folder
  // Set the baudrate which is for debug and communicate with Nextion screen
  nexInit();

  // Register the pop event callback function of the components
  bOn.attachPop(bOnPopCallback, &bOn);
  bOff.attachPop(bOffPopCallback, &bOff);

  // Set LEDs as outputs
  pinMode(led1, OUTPUT);
}

void loop(void) {
  /*
     When a pop or push event occured every time,
     the corresponding component[right page id and component id] in touch event list will be asked.
  */
  nexLoop(nex_listen_list);
}
