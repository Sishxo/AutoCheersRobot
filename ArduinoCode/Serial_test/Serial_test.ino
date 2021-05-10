#include<SoftwareSerial.h>
#include<avr/wdt.h>
#include<MsTimer2.h>

unsigned char comedata[4] = {};
unsigned char com;

void setup(){
    Serial.begin(9600);
    wdt_enable(WDTO_8S); //看门狗设置为8s
}

void loop(){
    while(Serial.available() > 0){
        for(int i = 0; i< 4; i++)
            //comedata[i] = char (Serial.read());
            Serial.readBytes(comedata,3);
    }
    for(int k = 0; k < 4;k++){
        Serial.println(comedata[k],DEC);
    }
    delay(2000);
    wdt_reset(); //喂狗
}
