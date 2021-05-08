int incomedate=0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    while(Serial.available()>0){
        incomedate=Serial.read();
        Serial.print(incomedate);
    }
}