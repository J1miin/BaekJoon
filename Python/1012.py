import sys
input = sys.stdin.readline

## 2차원 배열 출력 함수 for debug##
def print2x2Array(arr):
    for i in arr:
        for j in i:
            print(j, end=" ")
        print()
####################

def check():
    while searchQueue:
        iorgY, iorgX = searchQueue.pop()
        # 아래
        iDownY = iorgY + 1
        if iDownY < iHeight:
            if iCheckField[iDownY][iorgX] == 0 and iField[iDownY][iorgX] == 1:
                iCheckField[iDownY][iorgX] = 1
                searchQueue.append([iDownY, iorgX])
        # 오른쪽
        iRightX = iorgX + 1
        if iRightX < iWidth:
            if iCheckField[iorgY][iRightX] == 0 and iField[iorgY][iRightX] == 1:
                iCheckField[iorgY][iRightX] = 1
                searchQueue.append([iorgY, iRightX])
        # 왼쪽
        iLeftX = iorgX - 1
        if iLeftX >= 0:
            if iCheckField[iorgY][iLeftX] == 0 and iField[iorgY][iLeftX] == 1:
                iCheckField[iorgY][iLeftX] = 1
                searchQueue.append([iorgY, iLeftX])
        # 위쪽
        iUpY = iorgY - 1
        if iUpY >= 0:
            if iCheckField[iUpY][iorgX] == 0 and iField[iUpY][iorgX] == 1:
                iCheckField[iUpY][iorgX] = 1
                searchQueue.append([iUpY, iorgX])

iTestCaseNum = int(input())
results = []

for _ in range(iTestCaseNum):
    iWidth, iHeight, iK = map(int, input().split())   # iK = Total number of Cabbages
    searchQueue = []
    iTotalResult = 0

    # 2차원 배열 초기화 하기
    iField = [[0] * iWidth for _ in range(iHeight)]

    # 배추의 존재 여부를 확인했는지를 기록하는 2차원 배열 (0으로 초기화)
    iCheckField = [[0] * iWidth for _ in range(iHeight)]

    # 배추가 있는 곳에 1로 바꿔주기
    for _ in range(iK):
        iY, iX = map(int, input().split())
        iField[iX][iY] = 1

    for iRow in range(iHeight):
        for iCol in range(iWidth):
            if iCheckField[iRow][iCol] == 0 and iField[iRow][iCol] == 1:
                iCheckField[iRow][iCol] = 1
                searchQueue.append([iRow, iCol])
                check()
                iTotalResult += 1

    results.append(iTotalResult)


##최종 결과 출력
for result in results:
    print(result)
