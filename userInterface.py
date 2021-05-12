from tkinter import *
import tkinter.font as tkFont
import easygui
import location
import inverseKinematic
import communicate
import transfer
import sendSerial

Z = -7


def userinterface():
    root = Tk()
    root.title("哙享卫筷")

    #GIRLS = ["Google","IE","Ferox","soudog"]

    fontStyle_1 = tkFont.Font(family='microsoft yahei', size=20, weight='bold')
    fontStyle_2 = tkFont.Font(family='microsoft yahei', size=15, weight='bold')

    info = "选择成功"

    var = IntVar()

    group = LabelFrame(root, text="您想获取哪一道菜？",
                       font=fontStyle_1)  # 基于root制作一个框架
    group.pack(padx=70)

    language = [('1号菜品', 1),
                ('2号菜品', 2),
                ('3号菜品', 3),
                ('4号菜品', 4),
                ('5号汤品', 5),
                ('6号汤品', 6)
                ]

    for lang, num in language:
        b = Radiobutton(group, text=lang, variable=var, value=num,
                        indicatoron=False, padx=300, pady=30, font=fontStyle_2)
        l = Label(group, text=' ')  # 将内容添加到框架中

        l.pack()
        b.pack(anchor=W, fill=X)

    theButton = Button(root, text='就是这个了', command=lambda: callback(var.get()))
    theButton.pack(pady=20)

    mainloop()
    return var.get()


def callback(string):
    temp = string
    temp = "您已选中"+str(temp)+"号菜"
    # print(string)
    if(1 <= string and string <= 4):
        cX, cY = location.location()
        X, Y = transfer.transferCoordinate(cX, cY)
        X=int(X)
        Y=int(Y)
        angleList = inverseKinematic.inverseKinematics(X, Y, Z)
        angleList = transfer.transferAngle(angleList)
        if(angleList==[]):
            temp=temp+"\n该位置不可到达"
        else:
            sendSerial.sendSerial(string,angleList)
    else:
        sendString = str(string)
        sendSerial.sendSerial(sendString)

    easygui.msgbox(temp, title='正在进行图像识别......')


if __name__ == "__main__":
    userinterface()
