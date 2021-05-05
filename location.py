import cv2
import imutils

camera = cv2.VideoCapture(0)

if(camera.isOpened()):
    print('Camera is working')
else:
    print('Camera is not open')

while True:
    ret,frame = camera.read()
    frame = cv2.resize(frame, (600, 600)) # 统一处理画幅大小
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) # 转为灰度图
    blurred = cv2.GaussianBlur(gray, (5,5), 0) # 进行高斯滤波去噪
    thresh = cv2.threshold(blurred, 60, 255, cv2.THRESH_BINARY)[1] # 二值化处理，找到清晰边界

    contours = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours = imutils.grab_contours(contours) # 找到边界数组

    print(contours)

    for c in contours:
        M = cv2.moments(c)
        print(M["m00"])
        cX = int(M["m10"] / M["m00"])
        cY = int(M["m01"] / M["m00"]) # 利用图像的矩求得物体中心
        
        cv2.drawContours(frame, [c], -1, (0,255,0), 2)
        cv2.circle(frame, (cX, cY), 7, (255,255,255), -1)
        cv2.putText(frame, "center", (cX-20, cY-20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255,255,255), 2)

        cv2.imshow("Image",frame)
        cv2.imwrite("test.jpg",frame)
        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            break

camera.release()
cv2.destroyAllWindows()