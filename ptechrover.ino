#include <Configuration.h>
#include <Debug.h>
#include <ParsedStream.h>
#include <SpiUart.h>
#include <WiFly.h>
#include <WiFlyClient.h>
#include <WiFlyDevice.h>
#include <WiFlyServer.h>

#include <SPI.h>
//#include <WiFly.h>
#include <Servo.h> 
 
char* ssid = "pmobile";
char* pass = "homework"; 
 
char* serverAddress = "192.168.43.23"; 
int serverPort = 3000; 
 
 const int ledPin = 13; 
 
WiFlyClient client;
Servo myservo;
String color = "grey";
 
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  WiFly.setUart(&Serial);
  WiFly.begin();
  WiFly.join(ssid, pass, true);
  client.connect(serverAddress,serverPort);
  myservo.write(0);
}
 
void loop() {
  String input;
  int ledPin = 13;
    if (client.connected()) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  //check for incoming data over TCP
  if (client.available()) {
    char input = client.read();
  }
    if (input == "1") {
      color = "black";
      client.print("left");
      myservo.write(1);
      delay(1000);
    {
      if (input == "2") {
        color == "grey";
        myservo.write(91);
        client.print("right");
        delay(1000);
      } else {
    color == "white";
    myservo.write(179);
    delay(1000); }    
    }
    }
  }
