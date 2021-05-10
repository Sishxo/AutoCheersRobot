# include<Servo.h>

Servo myservo;

int incomedate = 0;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
    myservo.attach(9);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   while(Serial.available()>0)
    {
        pos = Serial.read();
        myservo.write(pos);
        delay(50);
        Serial.println("OK");
        delay(5);
    }
}
