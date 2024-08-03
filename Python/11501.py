#주식 문제
import sys
input = sys.stdin.readline
#max/index를 함수가 시간초과를 불러온다.
#뒤에서부터 추적하는 방식으로 최대값을 업데이트 하는 방식
iTestCase = int(input())
iResultArr = []
while (iTestCase>0):
    iDay= int(input())
    iStockArr = []
    iStockArr = list(map(int, input().split()))

    iResult = 0
    iMax = iStockArr[-1]
    iDay -= 2
    for i in range(iDay,-1,-1):
        if iStockArr[i]<iMax :
            iResult += iMax-iStockArr[i]
        else :
            iMax=iStockArr[i]
        
    iResultArr.append(iResult)
    iTestCase-=1

for i in iResultArr:
    print(i)