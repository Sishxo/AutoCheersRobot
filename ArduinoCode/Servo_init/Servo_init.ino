#include<Servo.h>

Servo myservo;

void setup(){
    myservo.attach(9);

    myservo.write(0);
    delay(1000);
}

void loop(){
  myservo.write(0);
  delay(1000);
}
