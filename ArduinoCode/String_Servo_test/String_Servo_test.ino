/*
预期功能：当我在串口监视器中输入一串用","分隔的字符串的时候，Arduino可以自动读取字符串并将他分割成整型数据（角度），随后相应的舵机要做出相应的动作。
*/
#include <Servo.h>

//定义舵机对象
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

String comedata = ""; //定义空的字符串用于接收串口监视器发送的数据
String buffer = "";
int angleList[4] = {0}; //定义空的数组用于接收四个舵机的角度
int mark = 0;           //定义mark用于标记串口状态
String temp = "";
int option = 0;

void setup()
{
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
}

void loop()
{
    serial_scan();
}

//功能：舵机位置初始化（归零）
void servo_init()
{
    servo8.write(90);
    delay(500);
    servo7.write(0);
    delay(500);
    servo6.write(90);
    delay(500);
    servo5.write(90);
    delay(500);
    servo4.write(90);
    delay(500);
    servo3.write(90);
    delay(500);
    servo2.write(0);
    delay(500);
    servo1.write(90);
    delay(500);
}

//功能：接收串口数据并将舵机的角度发送
void serial_scan()
{
    int j = 0;

    while (Serial.available() > 0)
    {
        comedata += char(Serial.read());
        delay(2);
        mark = 1;
    }

    if (mark == 1)
    {
        Serial.println("Mark = 1!");
        Serial.println(comedata);
        Serial.println(comedata.length());

        option = comedata[0]-'0';
        //Serial.println(option);
        if (option >= 1 && option <= 4)
        {
            comedata = comedata.substring(1) ;
            //Serial.println(comedata);
            for (int i = 0; i < comedata.length() - 1; i++)
            {
                //TODO
                //步进电机运动代码
                //Serial.println(comedata[i]);
                temp = comedata[i];
                if (temp.equals(","))
                {
                    //Serial.println("test");
                    angleList[j] = buffer.toInt();
                    j++;
                    buffer = "";
                }
                else
                {
                    buffer.concat(comedata[i]);
                }
                //Serial.println(buffer);
            }
            angleList[j] = buffer.toInt();
            for (int i = 0; i < 4; i++)
            {
                Serial.println(angleList[i]);
            }
            grab(angleList);
            objectDown(angleList);
        }
        else if(option == 5||option == 6){
            //TODO
            Serial.println("soup()");
            soup();
        }
        else if(option == 7){
            //TODO
            Serial.println("clean()");
            clean();
        }
    }
    buffer = "";
    comedata = String("");
    mark = 0;
}

void soup()
{
    //舵机6转动180°
    for (int i = 90; i < 180; i++)
    {
        servo6.write(i);
        delay(15);
    }
    delay(500);
    //舵机5转动135°
    for (int i = 90; i < 135; i++)
    {
        servo5.write(i);
        delay(15);
    }
    delay(500);
    //舵机4转动45°
    for (int i = 90; i > 45; i--)
    {
        servo4.write(i);
        delay(15);
    }
    delay(500);
    //舵机7从90°转到0°
    for (int i = 90; i > 0; i--)
    {
        servo7.write(i);
        delay(15);
    }
    delay(500);
    //舵机7转动90°
    for (int i = 0; i < 90; i++)
    {
        servo7.write(i);
        delay(15);
    }
    delay(500);

    //短暂延时
    delay(2000);

    //机械臂执行倒汤的动作
    //舵机6将旋转至120°
    for (int i = 180; i > 120; i--)
    {
        servo6.write(i);
        delay(50);
    }
    delay(500);
    //舵机5前倾至150°
    for (int i = 135; i < 150; i++)
    {
        servo5.write(i);
        delay(50);
    }
    delay(500);
    //舵机8旋转至0°，倒汤
    for (int i = 90; i > 0; i--)
    {
        servo8.write(i);
        delay(15);
    }
    delay(500);
    //舵机6将旋转至135°
    for (int i = 120; i < 135; i++)
    {
        servo6.write(i);
        delay(50);
    }
    delay(500);

    //机械臂复位
    //舵机8复位
    for (int i = 0; i < 90; i++)
    {
        servo8.write(i);
        delay(15);
    }
    delay(500);
    //抖动汤勺
    for (int j = 0; j < 3; j++)
    {
        servo8.write(180);
        delay(500);
        servo8.write(90);
        delay(500);
        servo8.write(0);
        delay(500);
        servo8.write(90);
        delay(500);
    }
    //舵机5从150°回到90°
    for (int i = 150; i > 90; i--)
    {
        servo5.write(i);
        delay(15);
    }
    delay(500);
    //舵机4将从45°回到90°
    for (int i = 45; i < 90; i++)
    {
        servo4.write(i);
        delay(15);
    }
    delay(500);
    //舵机6将从120°的角度回到90°
    for (int i = 120; i > 90; i--)
    {
        servo6.write(i);
        delay(15);
    }
    delay(500);
}

void grab(int *angleList)
{
    //机械臂接收到串口的信号后做出相应的动作
    //舵机6收到的角度在0到180°之间,夹菜的角度是小于90°，勺汤的角度是大于90°
    //servo6.write(angleList[0]);
    for (int i = 90; i > angleList[0]; i--)
    {
        servo6.write(i);
        delay(15);
    }
    delay(500);
    //舵机5收到的角度应该是小于90°的
    //servo5.write(angleList[1]);
    for (int i = 90; i > angleList[1]; i--)
    {
        servo5.write(i);
        delay(15);
    }
    delay(500);
    //舵机4收到的角度应该是大于90°的
    //servo4.write(angleList[2]);
    for (int i = 90; i < angleList[2]; i++)
    {
        servo4.write(i);
        delay(15);
    }
    delay(500);

    //机械臂执行夹菜的动作
    servo2.write(0);
    delay(500);
    servo1.write(0); //柔性爪打开
    delay(500);

    //舵机3接收的角度应该是小于90°
    //servo3.write(angleList[3]);
    for (int i = 90; i > angleList[3]; i--)
    {
        servo3.write(i);
        delay(15);
    }
    delay(1000);

    servo1.write(70); //柔性爪关闭
    delay(500);

    //短暂延时
    delay(2000);

    
}

void clean(){
    //TODO
}

void objectDown(int *angleList){
    //机械臂执行放菜的动作
    //舵机5将从小于90°的角度回到90°
    //servo5.write(90);
    /*for(int i=0;i<4;i++){
        Serial.println(angleList[i]);
    }*/
    for (int i = angleList[1]; i < 90; i++)
    {
        servo5.write(i);
        delay(15);
    }
    delay(500);
    //舵机6将旋转至指定角度
    //servo6.write(angleList[0]);
    for (int i = angleList[0]; i < 45; i++)
    {
        servo6.write(i);
        delay(15);
    }
    delay(500);
    //舵机3前倾1个角度
    for (int i = 90; i > 45; i--)
    {
        servo3.write(i);
        delay(15);
    }
    //舵机5前倾一个角度
    for (int i = 90; i > 45; i--)
    {
        servo5.write(i);
        delay(15);
    }
    delay(500);
    //柔性爪打开
    servo1.write(0);
    delay(500);

    //机械臂复位
    //舵机6将从小于90°的角度回到90°
    //servo6.write(angleList[0]);
    for (int i = 45; i < 90; i++)
    {
        servo6.write(i);
        delay(15);
    }
    delay(500);
    //舵机5从45°回到90°
    for (int i = 45; i < 90; i++)
    {
        servo5.write(i);
        delay(15);
    }
    delay(500);
    //舵机4将从大于90°的角度回到90°
    //servo4.write(90);
    for (int i = angleList[2]; i > 90; i--)
    {
        servo4.write(i);
        delay(15);
    }
    delay(500);
    //舵机3从45°复位到
    //servo3.write(90);
    for (int i = 45; i < 90; i++)
    {
        servo3.write(i);
        delay(15);
    }
    delay(500);

    servo1.write(90);
    delay(500);

    for (int i = 0; i < 4; i++)
    {
        angleList[i] = 0;
    }
}
