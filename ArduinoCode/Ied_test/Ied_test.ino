int incomedate = 0;
void setup() {
    Serial.begin(9600); //设置串口波特率9600
}

void loop() {
    while (Serial.available() > 0)//串口接收到数据
    {
    incomedate = Serial.read();//获取串口接收到的数据
    if (incomedate == '1')
    {
    //若接收到1则执行
        pinMode(13, OUTPUT);
        digitalWrite(13, HIGH); //亮灯    
        Serial.println("ok"); //向树莓派发送信息
    }
    delay(5);
    }
}