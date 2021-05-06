from math import *


def RAD2ANG(radian):  # 弧度转角度，用于舵机参数
    angle = (radian / 3.1415926535898) * 180.0
    return angle


def ANG2RAD(angle):  # 角度转弧度，用于三角函数计算
    radian = (angle / 180.0) * 3.1415926535898
    return radian


def inverseKinematics(x, y, z):
    L1 = 10.4
    L2 = 8.9
    L3 = 15  # 三根连杆的长度
    flag = 0
    j0 = atan2(y, x)  # j0为求得云台底部(0#舵机)所需旋转角度
    # print(j0)
    # 求解三元方程中间步骤
    a = x / cos(j0)
    if x == 0:  # 如果x=0，即舵机绕Z轴转了90度这种情况，需要借助y进行中间变量的构建
        a = y / sin(j0)
    b = z
    # print(a)
    for j1 in range(-90, 90):
        j1 = ANG2RAD(j1)
        temp1 = (a**2+b**2+L1**2-L2**2-L3**2-2*a *
                 L1*sin(j1)-2*b*L1*cos(j1))/(2*L2*L3)
        if temp1 > 1 or temp1 < -1:
            continue
        j3 = acos((a**2+b**2+L1**2-L2**2-L3**2-2*a*L1*sin(j1)-2 *
                  b*L1*cos(j1))/(2*L2*L3))  # 推导后得到的j3(3#舵机的角度)的表达式
        #print(str(temp1)+" "+str(j3))
        m = L2*sin(j1)+L3*sin(j1)*cos(j3)+L3*cos(j1)*sin(j3)  # 中间步骤
        n = L2*cos(j1)+L3*cos(j1)*cos(j3)-L3*sin(j1)*sin(j3)
        t = a-L1*sin(j1)
        p = pow((n**2+m**2), 0.5)
        q = asin(m/p)
        j2 = asin(t/p)-q  # 2#舵机表达式
        # print(j2)
        # 进行验证，因为j1是以步进整数1的形式进行拟合，无法获得完美的解，需进行进一步解的验证

        x1 = (L1*sin(j1)+L2*sin(j1+j2)+L3*sin(j1+j2+j3))*cos(j0)
        y1 = (L1*sin(j1)+L2*sin(j1+j2)+L3*sin(j1+j2+j3))*sin(j0)
        z1 = L1*cos(j1)+L2*cos(j1+j2)+L3*cos(j1+j2+j3)
        j1 = RAD2ANG(j1)
        j2 = RAD2ANG(j2)
        j3 = RAD2ANG(j3)
        if x1 > x-1 and x1 < x+1 and y1 > y-1 and y1 < y+1 and z1 > z-1 and z1 < z+1:
            print("j0:%f,j1:%f,j2:%f,j3:%f,x:%f,y:%f,z:%f\r\n" %
                  (RAD2ANG(j0), j1, j2, j3, x1, y1, z1))
            flag = 1
    for j1 in range(-90, 90):
        j1 = ANG2RAD(j1)
        temp1 = (a**2+b**2+L1**2-L2**2-L3**2-2*a *
                 L1*sin(j1)-2*b*L1*cos(j1))/(2*L2*L3)
        if temp1 > 1 or temp1 < -1:
            continue
        j3 = acos((a**2+b**2+L1**2-L2**2-L3**2-2*a*L1*sin(j1)-2 *
                  b*L1*cos(j1))/(2*L2*L3))  # 推导后得到的j3(3#舵机的角度)的表达
        m = L2*sin(j1)+L3*sin(j1)*cos(j3)+L3*cos(j1)*sin(j3)  # 中间步骤
        n = L2*cos(j1)+L3*cos(j1)*cos(j3)-L3*sin(j1)*sin(j3)
        t = a-L1*sin(j1)
        p = pow((n**2+m**2), 0.5)
        q = asin(m/p)
        j2 = -(asin(t/p)-q)  # 2#舵机表达式

        # 进行验证，因为j1是以步进整数1的形式进行拟合，无法获得完美的解，需进行进一步解的验证

        x1 = (L1*sin(j1)+L2*sin(j1+j2)+L3*sin(j1+j2+j3))*cos(j0)
        y1 = (L1*sin(j1)+L2*sin(j1+j2)+L3*sin(j1+j2+j3))*sin(j0)
        z1 = L1*cos(j1)+L2*cos(j1+j2)+L3*cos(j1+j2+j3)
        j1 = RAD2ANG(j1)
        j2 = RAD2ANG(j2)
        j3 = RAD2ANG(j3)
        if x1 > x-1 and x1 < x+1 and y1 > y-1 and y1 < y+1 and z1 > z-1 and z1 < z+1:
            print("j0:%f,j1:%f,j2:%f,j3:%f,x:%f,y:%f,z:%f\r\n" %
                  (RAD2ANG(j0), j1, j2, j3, x1, y1, z1))
            flag = 1  # print("x1:"+str(x1))
    if flag == 0:
        print("无解")


def main():
    inverseKinematics(0, 30, 0)


if __name__ == "__main__":
    main()
