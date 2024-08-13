#알파벳 블록
import sys
from collections import deque

input = sys.stdin.readline

iPlayNum = int(input())
sResultArr = deque()  # 덱으로 변경해야 하는 것 같다...ㅠ
charSequenceArr = []

#덱이 아니라 리스트를 쓰면 insert하고 pop하는데 O(n)의 시간이 걸린다.
#But 덱을 쓰면 O(1)의 시간 복잡도로 동일 작업을 할 수 있게 된다.

def blockGame(sInputList):
    #charSequenceArr에 들어온 순서가 아니라 메뉴 번호를 넣어서 앞에서 지울지 뒤에서 지울지를 정하면 된다!
    if sInputList[0] == '1':
        sResultArr.append(sInputList[1])  
        charSequenceArr.append(sInputList[0])
        
    elif sInputList[0] == '2':  # 맨앞에 추가
        sResultArr.appendleft(sInputList[1])  
        charSequenceArr.append(sInputList[0])

    elif sInputList[0] == '3':
        if charSequenceArr:
            sMenu = charSequenceArr.pop()
            if sMenu == '1':
                sResultArr.pop()  
            elif sMenu == '2':
                sResultArr.popleft()  
  
##########
def printResult():
    if sResultArr:
        print(''.join(sResultArr))  # 덱의 요소를 모두 출력
    else:
        print(0)
##################

for _ in range(iPlayNum):
    sInputList = input().split()
    blockGame(sInputList)

printResult()