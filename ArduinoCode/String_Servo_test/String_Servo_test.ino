/*
预期功能：当我在串口监视器中输入一串用","分隔的字符串的时候，Arduino可以自动读取字符串并将他分割成整型数据（角度），随后相应的舵机要做出相应的动作。
*/
#include<Servo.h>

//定义舵机对象
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

String comedata = ""; //定义空的字符串用于接收串口监视器发送的数据
String buffer = "";  
int angleList[4] = {0}; //定义空的数组用于接收四个舵机的角度
int mark = 0; //定义mark用于标记串口状态
String temp="";

void setup(){
    //打开串口
    Serial.begin(9600);

    //定义舵机引脚
    servo0.attach(8);
    servo1.attach(9);
    servo2.attach(5);
    servo3.attach(6);

    //舵机初始化
    servo_init();
}

void loop(){
    serial_scan();
}

//功能：舵机位置初始化（归零）
void servo_init(){
    servo0.write(0);
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
}

//功能：接收串口数据并将舵机的角度发送
void serial_scan(){
    int j = 0;

    while(Serial.available() > 0){
        comedata += char(Serial.read());
        delay(2);
        mark = 1;
    }

    if(mark == 1){
        Serial.println("Mark = 1!");
        Serial.println(comedata);
        Serial.println(comedata.length());
        for(int i = 0; i < comedata.length()-1; i++){
            
            //Serial.println(comedata[i]);
            temp=comedata[i];
            if(temp.equals(",")){
                //Serial.println("test");
                angleList[j] = buffer.toInt();
                j++;
                buffer = "";
            }
            else{
                buffer.concat(comedata[i]);
            }
             //Serial.println(buffer);
        }
       angleList[j] = buffer.toInt();
        for(int i = 0; i < 4; i++){
            Serial.println(angleList[i]);
        }

        /*if(angleList[1] != 0|| angleList[2] != 0 || angleList[3] != 0 || angleList[0] != 0 || mark == 1){
            servo0.write(angleList[0]);
            delay(500);
            servo1.write(angleList[1]);
            delay(500);
            servo2.write(angleList[2]);
            delay(500);
            servo3.write(angleList[3]);
            delay(500);
        } */
            servo0.write(angleList[0]);
            delay(500);
            servo1.write(angleList[1]);
            delay(500);
            servo2.write(angleList[2]);
            delay(500);
            servo3.write(angleList[3]);
            delay(500);  

        for(int i=0;i<4;i++){
        angleList[i]=0;     
        }
        
        buffer = "";
        comedata = String("");
        mark = 0;
    }
}
