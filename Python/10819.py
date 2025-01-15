#차이를 최대로 (가장 작은애 양 옆을 가장 큰 애들로 두고, 큰 애들 옆에는 가장 작은 애들이 오도록!)
import sys
input = sys.stdin.readline
from collections import deque

def calculate(resultArr):
    result = 0
    for i in range(len(resultArr)-1):
        result += abs(resultArr[i]-resultArr[i+1])
    print(result)
    
iN = int(input())
iArr = list(map(int,input().split()))
resultArr = deque()

while len(resultArr)<iN:
    ##최대값부터 처리
    #최대값 넣기
    resultArr.appendleft(max(iArr))
    #원래배열에서 최대값 지우기
    iArr.remove(max(iArr))
    
    ##최소값 처리(1)
    #첫 번째 최소값은 appendleft
    resultArr.appendleft(min(iArr))
    iArr.remove(min(iArr))
    
    if iArr:
        #두 번째 최소값은 append
        resultArr.append(min(iArr))
        iArr.remove(min(iArr))

print(resultArr)
calculate(resultArr)
