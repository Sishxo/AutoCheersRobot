import serial.tools.list_ports_linux
import serial
import location
import transfer
import inverseKinematic
import time
Z=-85

def sendSerialGrab(string):
    portsList = list(serial.tools.list_ports_linux.comports())
    Port = list(portsList[0])[0]
    baudRate = 9600
    Serial = serial.Serial(Port, baudRate, timeout=1)

    sendStringDispatch = "D"+str(string)
    Serial.write(sendStringDispatch.encode())
    time.sleep(8)
    '''while 1:
    rcvString=Serial.readline().decode()
    if(rcvString!=""):
        print(rcvString)
        if(rcvString=="Dispatch done.\r\n"):'''
    cX, cY = location.location()
    print(cX+cY)
    X, Y = transfer.transferCoordinate(cX, cY)
    angleList = inverseKinematic.inverseKinematics(X+45, Y+20, Z)
    angleList = transfer.transferAngle(angleList)
    if(angleList==[]):
        Serial.close()
        return 0
    else:
        sendStringGrab="G"+str(string)+str(angleList[0])+","+str(angleList[1])+","+str(angleList[2])+","+str(angleList[3])
        #Serial = serial.Serial(Port, baudRate, timeout=1)
        Serial.write(sendStringGrab.encode())
        Serial.close()
        return 1

def sendSerialSoup(string):
    portsList = list(serial.tools.list_ports_linux.comports())
    Port = list(portsList[0])[0]
    baudRate = 9600
    Serial = serial.Serial(Port, baudRate, timeout=1)

    sendStringDispatch = "D"+str(string)
    Serial.write(sendStringDispatch.encode())
    time.sleep(8)
    sendStringDispatch = "G"+str(string)
    Serial.write(sendStringDispatch.encode())
    '''while 1:
        rcvString=Serial.readline().decode()
        if(rcvString!=""):
            print(rcvString)
            if(rcvString=="Dispatch done.\r\n"):'''
    Serial.close()
    return 1

