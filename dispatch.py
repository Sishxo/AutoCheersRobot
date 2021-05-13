def verify(option,stepFlag):
    if(stepFlag==6):
        stepFlag_Video=1
    else:
        stepFlag_Video=stepFlag+1
    if(option<1 or option>6 or stepFlag_Video<1 or stepFlag_Video>6):
        return 0;
    if(option>stepFlag_Video):
        temp1=option-stepFlag_Video
        temp2=6-option+stepFlag_Video
        if(temp1>=temp2):
            for i in range(temp2):
                print("调用一次顺时针转动")
        else:
            for i in range(temp1):
                print("调用一次逆时针转动")
        print("逆时针旋转一次至柔性爪")
    elif(option<stepFlag_Video):
        temp1=stepFlag_Video-option
        temp2=6-stepFlag_Video+option
        if(temp1<=temp2):
            for i in range(temp1):
                print("调用一次顺时针转动")
        else:
            for i in range(temp2):
                print("调用一次逆时针转动")
        print("逆时针旋转一次至柔性爪")
    else:
        temp=option-stepFlag_Video
        print("顺时针一次到摄像头")
        print("逆时针回到柔性爪")
    

if __name__=="__main__":
    while True:
        option=int(input("输入option(要转到的编号):"))
        stepFlag=int(input("输入stepFlag(当前编号):"))
        verify(option,stepFlag)