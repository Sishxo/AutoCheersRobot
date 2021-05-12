# RaspberryPi Commondline

## 列出设备所有端口
```shell
ls /dev/tty*
```


## 树莓派安装pySerial
```shell
pip install pyserial
```

# pySerial 

## 导入pyserial模块

```
import serial
```

## 打开串行口

```python
// 打开串口0， 9600，8N1，连接超时0.5秒
import serial
①选择设备
ser=serial.Serial("/dev/ttyUSB0",9600,timeout=0.5) #使用USB连接串行口
ser=serial.Serial("/dev/ttyAMA0",9600,timeout=0.5) #使用树莓派的GPIO口连接串行口
ser=serial.Serial(1,9600,timeout=0.5)#winsows系统使用com1口连接串行口
ser=serial.Serial("com1",9600,timeout=0.5)#winsows系统使用com1口连接串行口
ser=serial.Serial("/dev/ttyS1",9600,timeout=0.5)#Linux系统使用com1口连接串行口
print ser.name #打印设备名称
print ser.port #打印设备名
ser.open ()  #打开端口
s = ser.read(10)#从端口读10个字节
ser.write("hello") #向端口写数据
ser.close() #关闭端口
data = ser.read(20) #是读20个字符
data = ser.readline() #是读一行，以/n结束，要是没有/n就一直读，阻塞。
data = ser.readlines()和ser.xreadlines()#都需要设置超时时间
ser.baudrate = 9600 #设置波特率
ser.isOpen() #看看这个串口是否已经被打开
```

## 获得串行口状态

### 串行口的属性：

>   name:设备名字
    portstr:已废弃，用name代替
    port：读或者写端口
    baudrate：波特率
    bytesize：字节大小
    parity：校验位
    stopbits：停止位
    timeout：读超时设置
    writeTimeout：写超时
    xonxoff：软件流控
    rtscts：硬件流控
    dsrdtr：硬件流控
    interCharTimeout:字符间隔超时

### 属性的使用方法：

```python
ser=serial.Serial("/dev/ttyAMA0",9600,timeout=0.5)
ser.open()
print ser. name
print ser.port
print ser.baudrate #波特率
print ser.bytesize #字节大小
print ser.parity #校验位N－无校验，E－偶校验，O－奇校验
print ser.stopbits #停止位
print ser.timeout #读超时设置
print ser.writeTimeout #写超时
print ser.xonxoff #软件流控
print ser.rtscts #硬件流控
print ser.dsrdtr #硬件流控
print ser.interCharTimeout #字符间隔超时  
ser.close()
```