//P-TECH Rover

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
String color = "grey";
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  if (color == "black") {
  myservo.write(45);  }
  if (color == "grey") {
  myservo.write(90);  }
  if (color == "white") {
  myservo.write(135);  }
} 

void loop() {


}
