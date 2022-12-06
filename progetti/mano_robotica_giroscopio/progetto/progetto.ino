/*
  DICHIARAZIONI LIBRERIE
*/
#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#define MPU 0x68  // I2C address of the MPU-6050

/*
  PROTOTIPI CHIUSURA SINGOLE DITA
*/
void closePollice();
void closeIndice();
void closeMedio();
void closeAnulare();
void closeMignolo();
/*
  PROTOTIPI APERTURA SINGOLE DITA
*/
void openPollice();
void openIndice();
void openMedio();
void openAnulare();
void openMignolo();
/*
  PROTOTIPI APERTURA/CHIUSURA MANO
*/
void closeHand();
void openHand();

/*
  DICHIARAZIONI DEI SEROVMOTORI
*/
Servo pollice;
Servo indice;
Servo medio;
Servo anulare;
Servo mignolo;

/*
  DICHIARAZIONI VARIABILI INCLINAZIONE
*/
double AcX, AcY, AcZ;
int Pitch, Roll;

void setup() {
  Serial.begin(9600);

  /*
    DICHIARAZIONE DEI PIN AI QUALI SONO COLLEGATI I VARI SERVOMOTORI
  */
  pollice.attach(13);
  indice.attach(12);
  medio.attach(11);
  anulare.attach(10);
  mignolo.attach(9);

  /*
    INIZIALIZZAZIONE MPU6050
  */
  init_MPU();
}

void loop() {
  //Acquisisco assi AcX, AcY, AcZ.
  FunctionsMPU();
  //Calcolo angolo Roll
  Roll = FunctionsPitchRoll(AcX, AcY, AcZ);
  //Calcolo angolo Pitch
  Pitch = FunctionsPitchRoll(AcY, AcX, AcZ);

  int ServoRoll = map(Roll, -90, 90, 0, 179);
  int ServoPitch = map(Pitch, -90, 90, 179, 0);

  Serial.print("Pitch: "); Serial.print(Pitch);
  Serial.print("\t");
  Serial.print("Roll: "); Serial.print(Roll);
  Serial.print("\n");

  if (Roll < 0) {
    closeHand();
  }
  if (Roll > 0) {
    openHand();
  }

}

/*
   FUNZIONE INIZIALIZZAZIONE SENSORE MPU6050
*/
void init_MPU() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  delay(1000);
}
/*
  FUNZIONE CALCOLO ANGOLI
*/
double FunctionsPitchRoll(double A, double B, double C) {
  double DatoA, DatoB, Value;
  DatoA = A;
  DatoB = (B * B) + (C * C);
  DatoB = sqrt(DatoB);

  Value = atan2(DatoA, DatoB);
  Value = Value * 180 / 3.14;

  return (int)Value;
}

/*
  FUNZIONE AQUISIZIONE ASSI X,Y,Z
*/
void FunctionsMPU() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
}

/*
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   FUNZIONI PER LA CHIUSRA DELLE SINGOLE DITA
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void closePollice() {
  pollice.write(180);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void closeIndice() {
  indice.write(180);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void closeMedio() {
  medio.write(180);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void closeAnulare() {
  anulare.write(0);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void closeMignolo() {
  mignolo.write(0);
}
/*
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   FUNZIONI PER L'APERTURA DELLE SINGOLE DITA
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void openPollice() {
  pollice.write(90);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openIndice() {
  indice.write(90);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openMedio() {
  medio.write(90);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openAnulare() {
  anulare.write(90);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openMignolo() {
  mignolo.write(90);
}
/*
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  FUNZIONI APERTURA/CHIUSURA MANO
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
void closeHand() {
  closePollice();
  closeIndice();
  closeMedio();
  closeAnulare();
  closeMignolo();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void openHand() {
  openPollice();
  openIndice();
  openMedio();
  openAnulare();
  openMignolo();
}
