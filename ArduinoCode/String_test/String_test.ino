
String comedata = "";
String buffer="";
int angleList[4]={0};
int mark = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int j = 0;
  
  while(Serial.available()>0){
    comedata += char(Serial.read());
    delay(2);
    mark = 1;
  }
  if(mark == 1){
    Serial.println("Mark = 1 !");
    Serial.println(comedata);
    Serial.println(comedata.length());
    for(int i = 0; i<comedata.length();i++){
        if(comedata[i]==','){
          angleList[j]=buffer.toInt();
          j++;
          buffer="";
        }else{
          buffer.concat(comedata[i]);
        }
    }
    angleList[j]=buffer.toInt();
    for(int i=0;i<4;i++){
        Serial.println(angleList[i]);
    }
      /*   if(comedata[i] == ','){
            j++;
            }
          else{
            revdata[j]= revdata[j]*10 + (comedata[i] - '0');
            }
         }*/
    }
    for(int i=0;i<4;i++){
      angleList[i]=0;
    }
    buffer="";
    comedata = String("");
    mark = 0;
}
