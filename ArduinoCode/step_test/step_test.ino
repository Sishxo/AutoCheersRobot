//步进电机引脚的定义
//采用共阴极接线方式，红线接A+，绿线接A-，黄线接B+，蓝线接B-
#define stepPin 11
#define dirPin 12
#define enPin 13

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(stepPin,OUTPUT);
    pinMode(dirPin,OUTPUT);
    pinMode(enPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(dirPin, HIGH);

    for (int x = 0; x < 10000; x ++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
    }   
    
    //digitalWrite(dirPin, LOW);

    for (int x = 0; x < 10000; x ++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
    }   
}
