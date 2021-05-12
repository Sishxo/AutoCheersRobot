#include<Servo.h>

//定义舵机对象
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

void setup(){
    //打开串口
    Serial.begin(9600);

    //定义舵机引脚
    servo1.attach(2);
    servo2.attach(3);
    servo3.attach(4);
    servo4.attach(5);
    servo5.attach(6);
    servo6.attach(7);
    servo7.attach(8);
    servo8.attach(9);

    //舵机初始化
    servo_init();
    delay(1000);
}

void loop(){
    soup();
    delay(1000);
    servo_reinit();
    delay(1000);
}

//功能：舵机位置初始化（归零）
void servo_init(){
    servo6.write(0);
    delay(500);
    servo5.write(90);
    delay(500);
    servo4.write(90);
    delay(500);
    servo3.write(90);
    delay(500);
    servo7.write(0);
    delay(500);
    servo8.write(0);
    delay(500);
}

//功能：实现勺汤的动作
void soup(){
//勺汤需要的各个舵机运动的角度：180,150,70,90
    for(int i = 0; i < 180; i++){
    servo4.write(i);
    delay(20);
    }
    delay(500);
    for(int i = 90; i < 150; i++){
    servo4.write(i);
    delay(20);
    }
    delay(500);
    for(int i = 90; i > 70; i++){
    servo4.write(i);
    delay(20);
    }
    delay(500); 
    //servo7.write(90);
    //delay(500);
    servo8.write(90);
    delay(500);
    servo8.write(0);
    delay(500);
}

void servo_reinit(){
    for(int i = 150; i > 90; i--){
    servo5.write(i);
    delay(20);
    }
    delay(500);
    for(int i = 70; i < 90; i++){
    servo4.write(i);
    delay(20);
    }
    delay(500);
    for(int i = 180; i > 90; i--){
    servo6.write(i);
    delay(20);
    }
    delay(500);
}
