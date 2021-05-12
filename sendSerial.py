import serial.tools.list_ports_linux
import serial


def sendSerial(sendString):
    portsList = list(serial.tools.list_ports_linux.comports())
    Port = list(portsList[0])[0]
    baudRate = 9600
    Serial = serial.Serial(Port, baudRate, timeout=1)

    while True:
        rcvString = Serial.readline().decode()
        if(Serial.write(send.encode())):
            print(sendString)
            if(rcvString == "ok\r\n"):
                print("Send complete")
                break
    Serial.close()
