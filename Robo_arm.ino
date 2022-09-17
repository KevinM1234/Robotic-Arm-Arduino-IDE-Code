#include <Stepper.h>

const int stepsPerRevolution = 200;
Stepper myStepper1(stepsPerRevolution, 13, 12, 10, 11);
Stepper myStepper2(stepsPerRevolution, 6, 7, 8, 9);
Stepper myStepper3(stepsPerRevolution, 2, 3, 4, 5);
void setup() { 
  Serial.begin(9600);  // initialize the serial port

  float X=8.0;
  float Y=8.0;
  float Z=8.0;
  float T1=atan(Y/X);  //Eq.1 stepper1 rotates along the Z-axis
  float a1=3.0; //distance from stepper 1 to stepper 2 in cm
  float Zb=abs(Z-a1);   //Eq.2
  float r1=sqrt((sq(X)) + (sq(Zb))); //Eq. 3 distance from stepper 2 to the end effector
  float a2=6.0; //distance from stepper 2 to stepper 3 in cm
  float a3=5.0; //distance from stepper 2 to stepper 3 in cm
  float phi1=acos((sq(a3)-sq(a2)-sq(r1))/(-2*a2*r1)); //Eq. 4
  float phi2=atan(Zb/X);//Eq. 5
  float T2=phi2 - phi1;//Eq. 6  stepper2 rotates along the Y-axis
  float phi3=acos((sq(r1)-sq(a2)-sq(a3))/(-2*a2*a3));//Eq. 7
        phi3=(phi3/3.14159)*180;
  float T3=180 - phi3;//Eq. 8
 
  myStepper1.setSpeed(1);
  myStepper1.step(Theta((T1/3.14159)*180));
//  Serial.print("T1 is: ");
//  Serial.println(T1);
//  Serial.print("r1 is: ");
//  Serial.println(r1);
//  Serial.print("phi1 is: ");
//  Serial.println(phi1);
  delay (1000);
  myStepper2.setSpeed(1);
  myStepper2.step(Theta((T2/3.14159)*180));
//  Serial.print("phi2 is: ");
//  Serial.println(phi2);
//  Serial.print("T2 is: ");
//  Serial.println(T2);
  delay (1000);
  myStepper3.setSpeed(1);
  myStepper3.step(Theta(T3));
//  Serial.print("T3 is: ");
//  Serial.println(T3);

}

void loop() {  
}
float Theta(float angle){  //used to convert angles to steps the motor can read

  float min_comp=0.0;
  float max_comp=200.0;
  float min_ang=0.0;
  float max_ang=360.0;
  float result;
  
  result =((max_comp - min_comp)/(max_ang - min_ang))*(angle - min_ang) + min_comp;
  
  return result;
}
