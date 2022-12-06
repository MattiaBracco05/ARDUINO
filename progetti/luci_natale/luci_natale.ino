int relay_capanna = 3;
int relay_giuseppe =  5;
int relay_bastone = 7;
int relay_maria = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay_capanna, OUTPUT);
  pinMode(relay_giuseppe, OUTPUT);
  pinMode(relay_bastone, OUTPUT);
  pinMode(relay_maria, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //spengo tutto
  digitalWrite(relay_capanna, HIGH);
  digitalWrite(relay_giuseppe, HIGH);
  digitalWrite(relay_maria, HIGH);
  digitalWrite(relay_bastone, HIGH);
  //attendo 1,5 secondi
  delay(1500);
  //accendo la capanna
  digitalWrite(relay_capanna, LOW);
  //attendo 1,5 secondi
  delay(1500);
  //accendo maria
  digitalWrite(relay_maria, LOW);
  //attendo 1,5 secondi
  delay(1500);
  //accendo giuseppe e il bastone
  digitalWrite(relay_giuseppe, LOW);
  digitalWrite(relay_bastone, LOW);
  delay(3000);
  //lampeggio
    digitalWrite(relay_capanna, HIGH);
    digitalWrite(relay_giuseppe, HIGH);
    digitalWrite(relay_maria, HIGH);
    digitalWrite(relay_bastone, HIGH);
    delay(2000);
    digitalWrite(relay_capanna, LOW);
    digitalWrite(relay_giuseppe, LOW);
    digitalWrite(relay_maria, LOW);
    digitalWrite(relay_bastone, LOW);
    delay(2000);
    digitalWrite(relay_capanna, HIGH);
    digitalWrite(relay_giuseppe, HIGH);
    digitalWrite(relay_maria, HIGH);
    digitalWrite(relay_bastone, HIGH);
    delay(2000);
    digitalWrite(relay_capanna, LOW);
    digitalWrite(relay_giuseppe, LOW);
    digitalWrite(relay_maria, LOW);
    digitalWrite(relay_bastone, LOW);
    delay(2000);
    digitalWrite(relay_capanna, HIGH);
    digitalWrite(relay_giuseppe, HIGH);
    digitalWrite(relay_maria, HIGH);
    digitalWrite(relay_bastone, HIGH);
    delay(2000);
    digitalWrite(relay_capanna, LOW);
    digitalWrite(relay_giuseppe, LOW);
    digitalWrite(relay_maria, LOW);
    digitalWrite(relay_bastone, LOW);
    delay(2000);
    digitalWrite(relay_capanna, HIGH);
    digitalWrite(relay_giuseppe, HIGH);
    digitalWrite(relay_maria, HIGH);
    digitalWrite(relay_bastone, HIGH);
    delay(2000);
    digitalWrite(relay_capanna, LOW);
    digitalWrite(relay_giuseppe, LOW);
    digitalWrite(relay_maria, LOW);
    digitalWrite(relay_bastone, LOW);
    delay(2000);
    digitalWrite(relay_capanna, HIGH);
    digitalWrite(relay_giuseppe, HIGH);
    digitalWrite(relay_maria, HIGH);
    digitalWrite(relay_bastone, HIGH);
    delay(2000);
    digitalWrite(relay_capanna, LOW);
    digitalWrite(relay_giuseppe, LOW);
    digitalWrite(relay_maria, LOW);
    digitalWrite(relay_bastone, LOW);
    delay(2000);
  //attendo 13 secondi (15 con quello del for)
  delay(13000);
}
