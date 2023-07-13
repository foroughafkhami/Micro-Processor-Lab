#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 2;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  if (val<= 0.1*1023){
    myservo.write(0);    
  }
  else{
    myservo.write(180); 
  }
}