int carRed = 12; // assegnazione luci auto
int carYellow = 11;
int carGreen = 10;
int pedRed = 9; // assegnazione luci pedoni
int pedGreen = 8;
int button = 2; // pin del buttone
int crossTime = 5000; // tempo per attraversare
unsigned long changeTime;

void setup() {
pinMode(carRed, OUTPUT);
pinMode(carYellow, OUTPUT);
pinMode(carGreen, OUTPUT);
pinMode(pedRed, OUTPUT);
pinMode(pedGreen, OUTPUT);
pinMode(button, INPUT);// il bottone accende il verde.
}

void loop() {
digitalWrite(carGreen, HIGH);
digitalWrite(pedRed, HIGH);
digitalWrite(pedGreen, LOW);
digitalWrite(carYellow, LOW);
digitalWrite(carRed, HIGH);
delay(10000);
digitalWrite(carYellow, HIGH);
delay(3000);
digitalWrite(carRed, HIGH);
digitalWrite(pedRed, LOW);
digitalWrite(pedGreen, HIGH);
delay(5000);
int state = digitalRead(button);
digitalWrite(pedGreen, HIGH);
delay(1000);
digitalWrite(pedGreen, LOW);
delay(1000),
digitalWrite(pedGreen, HIGH);
delay(1000);
digitalWrite(pedGreen, LOW);
digitalWrite(carGreen, LOW);
digitalWrite(carRed, LOW);
digitalWrite(carYellow, HIGH);
delay(3000);
digitalWrite(carYellow, LOW);
digitalWrite(carRed, HIGH);
delay(5000);
}
