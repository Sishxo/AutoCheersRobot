import cv2
import imutils
def location():
    camera = cv2.VideoCapture(0)

    if(camera.isOpened()):
        print('Camera is working')
    else:
        print('Camera is not open')

    while True:
        ret,frame = camera.read()
        frame=frame[60:420, 60:580]
        #print(camera.get(cv2.CAP_PROP_FRAME_WIDTH))
        #print(camera.get(cv2.CAP_PROP_FRAME_HEIGHT))
        #frame = cv2.resize(frame, (640, 480)) # 统一处理画幅大小
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) # 转为灰度图
        blurred = cv2.GaussianBlur(gray, (5,5), 0) # 进行高斯滤波去噪
        thresh = cv2.threshold(blurred, 108, 255, cv2.THRESH_BINARY_INV)[1] # 二值化处理，找到清晰边界
        #adaptive_thresh=cv2.adaptiveThreshold(blurred, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY_INV , 11 , 2)
        #print("test")
        contours = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        contours = imutils.grab_contours(contours) # 找到边界数组

        #print(contours)

        for c in contours:
            if cv2.contourArea(c) < 3500:
                continue
            M = cv2.moments(c)
            #print(M["m00"])
            if(M["m00"]):
                cX = int(M["m10"] / M["m00"])
                cY = int(M["m01"] / M["m00"]) # 利用图像的矩求得物体中心
                print("("+str(cX)+","+str(cY)+")\n")
                cv2.drawContours(frame, [c], -1, (0,255,0), 2)
                cv2.circle(frame, (cX, cY), 7, (255,255,255), -1)
                cv2.putText(frame, "center", (cX-20, cY-20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255,255,255), 2)
            else:
                cv2.putText(frame, "Focus Losed",(50,50), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255,255,255), 2)
        cv2.imshow("Image",frame)
        cv2.imshow("thresh",thresh)
        #cv2.imshow("adaptive_thresh",adaptive_thresh)
        #cv2.imwrite("test.jpg",frame)
        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            break
    camera.release()
    cv2.destroyAllWindows()

    return cX,cY


if __name__=="__main__":
    findLocation()