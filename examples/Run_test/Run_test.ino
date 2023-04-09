/*
 This code if for TB6612FNG Motor Driver.

 TB6612FNG        Arduino
   AIN1    -----     3
   AIN2    -----     4
   PWMA    -----     5
   BIN1    -----     8
   BIN2    -----     7
   PWMB    -----     6
   GND     -----    GND

   Created by - Sushant Khamaitkar
   Gmail      - skhamaitkar98@gmail.com
 */

#include <Tb6612fng.h>

Tb6612fng driver(3, 4, 5, 8, 7, 6, 2);  // ( AIN1, AIN2, PWMA, BIN1, BIN2, PWMB, STBY )
int Speed = 100;                        // ( 0 TO 255 )
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  //clockwise rotation of motor A while motor B is steady
  driver.Control(Speed, 0);
  delay(2000);

  //clockwise rotation of motor B while motor A is steady
  driver.Control(0, Speed);
  delay(2000);

  //anti-clockwise rotation of motor A while motor B is steady
  driver.Control(-Speed, 0);
  delay(2000);

  //anti-clockwise rotation of motor B while motor A is steady
  driver.Control(0, -Speed);
  delay(2000);

  //both motor steady
  driver.Control(0, 0);
  delay(2000);
}
