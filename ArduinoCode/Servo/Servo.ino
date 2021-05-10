/*
name:“哙享味筷”智能服务机器人 Arduino 部分代码
auther:张子轩 
dete:2021年5月
*/

//引用库文件
# include<Servo.h>

//创建8个舵机的对象
Servo servo0; //控制机械臂底座旋转的舵机
Servo servo1; //控制机械臂大臂抬起的舵机
Servo servo2; //控制连接机械臂大臂和小臂的舵机
Servo servo3; //控制柔性爪抬起的舵机
Servo servo4; //控制柔性爪旋转的舵机
Servo servo5; //控制柔性爪开合的舵机
Servo servo6; //控制勺子抬起的舵机
Servo servo7; //控制勺子旋转的舵机

//定义舵机的角度pos
int pos0 = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
int pos6 = 0;
int pos7 = 0;

void setup(){
    //打开串口，波特率9600
    Serial.begin(9600);

    //定义8个舵机的引脚
    servo0.attach (2);
    servo1.attach (3);
    servo2.attach (4);
    servo3.attach (5);
    servo4.attach (6);
    servo5.attach (7);
    servo6.attach (8);
    servo7.attach (9);

    //舵机复位
    servo_init();

}

void loop(){

}

/*
name:servo_init
function:所有舵机复位
*/
void servo_init(){
    servo0.write(0);
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
    servo4.write(0);
    servo5.write(0);
    servo6.write(0);
    servo7.write(0);
}

/*
name:servo_cap
function:柔性爪张开一定角度,之后下降一定的高度，闭合，将物体夹住
*/
void servo_cap(){
    servo5.write(); //柔性爪张开一定角度
    delay(500);

    servo4.write(); //柔性爪下降一定高度
    delay(500);

    servo5.write(); //柔性爪闭合
    delay(500);
}