//P-TECH Rover

#include <Servo.h> 
 
Servo myservo;
                
int pos = 0;    
String color = "grey";
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  
} 

void loop() {
  while (Serial.available()) {
    String input = (String)Serial.read();
    if (input == "left") {
      color = "black";
      myservo.write(45);
    {
      if (input == "right") {
        color == "grey";
        myservo.write(90);
      } else {
    color == "white";
    myservo.write(135); }    
    }
    }
  }
}
    
    
