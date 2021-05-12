import serial.tools.list_ports_linux
import serial


def sendSerial(string,angleList):
    portsList = list(serial.tools.list_ports_linux.comports())
    Port = list(portsList[0])[0]
    baudRate = 9600
    Serial = serial.Serial(Port, baudRate, timeout=1)

    sendString = str(string)+str(angleList[0])+","+str(angleList[1])+","+str(angleList[2])+","+str(angleList[3])

    while True:
        Serial.write(sendString.encode())
        rcvString = Serial.readline().decode()
        if(rcvString == "ok\r\n"):
            print("The instruction has been sent.")
            break
    Serial.close()

if __name__=="__main__":
    string=1
    angleList=[0,43,45,90]
    sendSerial(string,angleList)
