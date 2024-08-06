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
    while (iKmokCum != iK) :
        iKmok = iKmok // 2 
        iKmokCum += iKmok
        iCutCnt +=1
        print(f"iKmok = {iKmok}, iKmokCUm = {iKmokCum} iCutCnt ={iCutCnt}")

print(iSize, iCutCnt)