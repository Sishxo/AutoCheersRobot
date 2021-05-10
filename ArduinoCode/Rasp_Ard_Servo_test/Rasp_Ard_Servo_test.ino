# include<Servo.h>

Servo myservo;

int incomedate = 0;
int pos = 0;


void setup(){
    myservo.attach(9);
    Serial.begin(9600);
}

void loop(){
    while(Serial.available()>0)
    {
        incomedate = Serial.read();
        if(incomedate == '1')
        {
            for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
                // in steps of 1 degree
                myservo.write(pos);              // tell servo to go to position in variable 'pos'
                delay(15);                       // waits 15ms for the servo to reach the position
            }
            for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
                myservo.write(pos);              // tell servo to go to position in variable 'pos'
                delay(15);                       // waits 15ms for the servo to reach the position
            }
            Serial.println("ok");
            delay(5);
        }
        else if(incomedate != '1')
        {
            pinMode(13, OUTPUT);
            digitalWrite(13, HIGH); //亮灯    
            Serial.println("stop"); //向树莓派发送信息
            delay(5);
        }
    }
}
