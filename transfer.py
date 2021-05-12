def transferCoordinate(X, Y):
    return X,Y

def transferAngle(angleList):
    angleList[0]=angleList[0]
    angleList[1]=90-angleList[1]
    angleList[2]=90+angleList[2]
    angleList[3]=angleList[3]
    
    return angleList
      