#초콜릿 문제
import sys
input = sys.stdin.readline

def findSize(iK):
    i=0
    while True :
        if iK==1:
            iSize = 1
            break
        elif iK==2 :
            iSize = 2
            break
        elif iK>2**i and iK<=2**(i+1) :
            iSize = 2**(i+1)
            break
        i+=1
    return iSize

iK = int(input())
iSize = findSize(iK) #k에 따른 초콜릿 사이즈 찾기


iCutCnt = 0
iKmokCum = 0
iKmok=iSize

if iK==iSize :
    iCutCnt=0
else :
    while (iK) :
        iKmok = iKmok // 2 
        if iK >= iKmok :
            iK -= iKmok
            iCutCnt +=1
            #print(iK, iKmok, iCutCnt)
        else : 
            iCutCnt +=1
            #print("else ans")
        

print(iSize, iCutCnt)