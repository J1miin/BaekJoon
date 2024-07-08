import sys
input = sys.stdin.readline
#부분수열의 합
from itertools import combinations 

iN, iS = map(int,input().split())
iInputNumArr = list(map(int,input().split()))
iSubNumArr = []
iResult = 0

for i in range(1, len(iInputNumArr)+1):
    #공집합을 빼기 위해서 1부터 range 설정
    iSubNumArr += list(combinations(iInputNumArr,i))

print(iSubNumArr)
for i in range(len(iSubNumArr)):
    if sum(iSubNumArr[i]) == iS :
        # print(iSubNumArr[i])
        iResult +=1 

print(iResult)