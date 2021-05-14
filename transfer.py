def transferCoordinate(X, Y):
    X=round(int(X)*0.325+108)
    Y=round(int(Y)*0.325-96.75)
    return X,Y

def transferAngle(angleList):
    angleList[0]=angleList[0]
    angleList[1]=90-angleList[1]
    angleList[2]=90+angleList[2]
    angleList[3]=angleList[3]
    
    return angleList
      