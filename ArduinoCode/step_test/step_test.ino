//步进电机引脚的定义
//采用共阴极接线方式，红线接A+，绿线接A-，黄线接B+，蓝线接B-
#define stepPin 11
#define dirPin 12
#define enPin 13

int stepFlag=1;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(stepPin,OUTPUT);
    pinMode(dirPin,OUTPUT);
    pinMode(enPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    stepDispatch(3,1);
    delay(5000);
    
}

void stepDispatch(int option, int stepFlag)
{
    int stepFlag_Video;
    if(stepFlag==6)
    {
        stepFlag_Video=1;
    }
    else
    {
      stepFlag_Video=stepFlag+1;
    }
    int temp1, temp2;
    if (option < 1 || option > 6 || stepFlag < 1 || stepFlag > 6)
    {
        return 0;
    }
    if (option > stepFlag_Video)
    {
        temp1 = option - stepFlag_Video;
        temp2 = 6 - option + stepFlag_Video;
        if (temp1 >= temp2)
        {
            for (int i = 0; i < temp2; i++)
            {
                stepTimeClock();
            }
        }
        else
        {
            for (int i = 0; i < temp1; i++)
            {
                stepAntiClock();
            }
        }
        Serial.println("视觉识别中.....");
        delay(1000);
        stepAntiClock();
    }
    else if (option < stepFlag_Video)
    {
        temp1 = stepFlag_Video - option;
        temp2 = 6 - stepFlag_Video + option;
        if (temp1 <= temp2)
        {
            for (int i = 0; i < temp1; i++)
            {
                stepTimeClock();
            }
        }
        else
        {
            for (int i = 0; i < temp2; i++)
            {
                stepAntiClock();
            }
        }
        Serial.println("视觉识别中.....");
        delay(1000);
        stepAntiClock();
    }
    else
    {
        stepTimeClock();
        Serial.println("视觉识别中.....");
        delay(1000);
        stepAntiClock();
    }
}

void stepTimeClock()
{
    digitalWrite(dirPin, HIGH);

    for (int i = 0; i < 3057; i++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(800);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(800);
    }
}

void stepAntiClock()
{
    digitalWrite(dirPin, LOW);

    for (int i = 0; i < 3057; i++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(800);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(800);
    }
}
