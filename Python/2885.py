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
            print(iK, iKmok, iCutCnt)
        else : 
            iCutCnt +=1
            #print("else ans") 5의 경우 2개짜리 조각은 필요없고 (4+1) 로 1개짜리 조각이 필요해서 그런 경우 자르기만 하니까 이 else문이 필요
        
#K를 K보다 작고, 사이즈보다 작은 수(가장 작은 조합으로)의 합으로 구성하는 문제이다. 그래서 K가 0이될때까지 찾아주면 되는것!
print(iSize, iCutCnt)