#include <Stepper.h>
const int STEPS = 200;
Stepper mystepper(STEPS, 10, 11, 12, 13);
Stepper mystepper2(STEPS, 6, 7, 8, 9);
//Stepper mystepper3(STEPS, 2, 3, 4, 5);
int previous = 0;
int previous2 = 0;
//int previous3 = 0;

void setup() {
  mystepper.setSpeed(50);
  mystepper2.setSpeed(30);
  //mystepper3.setSpeed(30);
}

void loop() {
  
  int val = analogRead(0);
  int stepval = map(val, 0, 1023, 0, 200);
  int val2 = analogRead(1);
  int stepval2 = map(val2, 0, 1023, 0, 200);
  //int val3 = analogRead(2);
  //int stepval3 = map(val3, 0, 1023, 0, 100);


  mystepper.step(-stepval + previous);
  mystepper2.step(stepval2 - previous2);
  //mystepper3.step(-stepval3 + previous3);

  previous = stepval;
  previous2 = stepval2;
  //previous3 = stepval3;  
}
