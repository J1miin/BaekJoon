import sys
input = sys.stdin.readline

iN = int(input())
iLeftNumList = list(map(int,input().split()))
iResultList = [0]*iN #결과 담을 리스트

for i in range(iN):
    iCnt = 0 #iCnt로 왼쪽에 있는 사람의 숫자를 맞춰간다.
    for j in range(iN): #j로 i+1라는 사람이 어디에 있는지 위치를 조정한다.
        if iCnt == iLeftNumList[i] and iResultList[j]==0:
            iResultList[j] = i+1
            break
        elif iResultList[j]==0:
            iCnt +=1 

print(*iResultList, sep=' ')