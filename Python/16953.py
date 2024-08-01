import sys
input = sys.stdin.readline
# print(162//10) #16
# print(81%2) #0 나머지
# print(81//10)
# print("입력해")
iA, iB = map(int,input().split())
iCnt=0
iFlag=0


while True :
    # print("iB:",iB)
    if iA == iB:
        break
    elif iA>iB :
        iFlag=1
        break
    else :
        iMod = iB%2
        print("iMod, iB",iMod,iB)
        if iMod==0 :
            #짝수라면
            iB=iB//2
            iCnt+=1
        elif iB%10==1 : #가장 오른쪽 자리 수가 1인지 점검하기
            iB = iB//10 #가장 오른쪽에 있는 1 제거하기
            iCnt+=1
        else :
            iFlag=1
            break


     
if iFlag ==1 :
    print("-1")
else :
    iCnt+=1
    print(iCnt)

