import serial


def communicate(angleList):
    Port = "/dev/ttyACM1"
    baduRate = 9600
    ser = serial.Serial(Port, baudRate, timeout=1)

    send = angleList[0]+","+angleList[1]+","+angleList[2]+","+angleList[3]

    while True:
        ser.write(send.encode())
        str = ser.readline().decode()
        if(str != ""):
            print(str)
            if(str == "ok\r\n"):
                break

    ser.close
