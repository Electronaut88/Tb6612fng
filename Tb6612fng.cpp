#include "Tb6612fng.h"

Tb6612fng::Tb6612fng(int AIN1, int AIN2, int PWMA, int BIN1, int BIN2, int PWMB, int STBY) {
  _AIN1 = AIN1;
  _AIN2 = AIN2;
  _PWMA = PWMA;
  _BIN1 = BIN1;
  _BIN2 = BIN2;
  _PWMB = PWMB;
  _STBY = STBY;

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
}

void Tb6612fng::Control(int SpeedA, int SpeedB) {
  if (SpeedA > 0) {
    digitalWrite(_AIN1, HIGH);
    digitalWrite(_AIN2, LOW);
    analogWrite(_PWMA, SpeedA);
  }
  if (SpeedA < 0) {
    digitalWrite(_AIN1, LOW);
    digitalWrite(_AIN2, HIGH);
    analogWrite(_PWMA, -SpeedA);
  }
  if (SpeedA == 0) {
    digitalWrite(_AIN1, LOW);
    digitalWrite(_AIN2, LOW);
    analogWrite(_PWMA, 0);
  }
  if (SpeedB > 0) {
    digitalWrite(_BIN1, HIGH);
    digitalWrite(_BIN2, LOW);
    analogWrite(_PWMB, SpeedB);
  }
  if (SpeedB < 0) {
    digitalWrite(_BIN1, LOW);
    digitalWrite(_BIN2, HIGH);
    analogWrite(_PWMB, -SpeedB);
  }
  if (SpeedB == 0) {
    digitalWrite(_BIN1, LOW);
    digitalWrite(_BIN2, LOW);
    analogWrite(_PWMB, 0);
  }
}
