#ifndef TB6612FNG_H
#define TB6612FNG_H
#include "Arduino.h"

class Tb6612fng {
  public:
    Tb6612fng(int AIN1, int AIN2, int PWMA, int BIN1, int BIN2, int PWMB, int STBY);

    int _AIN1;
    int _AIN2;
    int _PWMA;
    int _BIN1;
    int _BIN2;
    int _PWMB;
    int _STBY;

    char data;

    void Control(int SpeedA, int SpeedB);

};

#endif
