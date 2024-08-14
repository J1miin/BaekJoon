#초콜릿 보관함
import sys
input = sys.stdin.readline

def checkChoco(x,y):
    dx = [-1, +1, 0, 0] #좌 우 위 아래
    dy = [0, 0, +1, -1]
    
    choco[x][y]='V'
    count = 1
    for i in range(len(dx)):
        move_x=x+dx[i]
        move_y=y+dy[i]
        if 0<= move_x < 3 and 0<=move_y<3 and choco[move_x][move_y]=='O':
            count += checkChoco(move_x,move_y)   #연결되어 있는 초콜릿의 개수 세기
    return count


iTestCase = int(input())

for _ in range(iTestCase):
    choco = []
    inputResult = []
    realResult = []
    iCnt = 0
    #초코판 채우기
    for row in range(3):
        choco.append(list(input().strip()))
    #보관함 상태 2x2 
    inputResult = (list(map(int,input().split())))
    #점검하기
    for i in range(3):
        for j in range(3):
            #print(f'{i}th : choco[{i}][{j}]={choco[i][j]}, {type(choco[i][j])}')
            if choco[i][j]=='O':
                #print(f'inside if phrase - {i}th : choco[i][j]={choco[i][j]}')
                chocoPerGroup = checkChoco(i,j)
                realResult.append(chocoPerGroup)
    
    # 연결 요소 크기 정렬 (오름차순이니까 이 과정이 필요하다. 처음에는 그거 무시하고 그냥 합만 구했다..)
    realResult.sort()
    expectedResult = inputResult[1:]
    expectedResult.sort()
    
    # 원래 답과 비교하기
    if len(realResult) == inputResult[0] and realResult == expectedResult:
        print(1)
    else:
        print(0)

