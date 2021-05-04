#!/usr/bin/python 
#-*-coding:utf-8-*- 

import serial

Port = "/dev/ttyACM1"  # 串口
baudRate = 9600  # 波特率
ser = serial.Serial(Port, baudRate, timeout=1)

while True:
    send = '1'  # 发送给arduino的数据
    ser.write(send.encode())
    str = ser.readline().decode()  # 获取arduino发送的数据
    if(str != ""):
        print(str)
        if(str == 'ok\r\n'): # 发送一次便退出
            print('收到')
            break

ser.close()
