#나무자르기 문제
import sys
input = sys.stdin.readline

iN = int(input())
iOrgTreeArr = list(map(int,input().split()))
iGrowLengthArr = list(map(int,input().split()))

iTreeTuple = [(iOrgTreeArr[i], iGrowLengthArr[i]) for i in range(iN)]

iTreeTuple.sort(key=lambda x:x[1])
#print(iTreeTuple)
iResult = 0

for i in range(iN):
    iResult += iTreeTuple[i][0] + iTreeTuple[i][1]*i

print(iResult)