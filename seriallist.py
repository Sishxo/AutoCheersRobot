import serial.tools.list_ports_windows
import serial

portsList=list(serial.tools.list_ports_windows.comports())
Port=list(portsList[0])[0]
baudRate=9600
Serial=serial.Serial(Port,baudRate,timeout=1)

list=[123,43,70]

while True:
    send='1'
    if(Serial.write(send.encode())):
        print("2")
    break
Serial.close()
