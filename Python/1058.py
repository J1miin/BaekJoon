import sys
input = sys.stdin.readline

## 2차원 배열 출력 함수 for debug##
def print2x2Array(arr):
    for i in arr:
        for j in i:
            print(j, end=" ")
        print()
####################

def floyd(iN):
    iDistanceTable = [[0]*iN for _ in range(iN)]

    #입력받기
    # for i in range(iN):
    #     iRow = input().strip()
    #     iDistanceTable[i] = list(iRow)
    # 입력을 아래와 같이 더 간결하게 받을 수도 있구낭 아직 어색하다..ㅠ
    friend = [list(input()) for _ in range(iN)]
                
    #Floyd
    for k in range(iN):
        for i in range(iN):
            for j in range(iN):
                if i==j :
                    continue
                if friend[i][j] =='Y' or (friend[i][k]=='Y' and friend[k][j]=='Y'):
                    #친구이거나, k를 통해 한다리 건너 친구이거나!
                    iDistanceTable[i][j]=1
    
    return iDistanceTable
########

iN = int(input()) #사람 수
INF = 100000
#친구 관계를 표현하는 2차원 거리 테이블

iDistanceTable = floyd(iN)

#친구 수 세기
iFreindNumList = [0]*iN
maxFriend = 0

for i in range(iN):
    for j in range(iN):
        if iDistanceTable[i][j]==1:
            iFreindNumList[i]+=1
# print(iFreindNumList)

for i in range(len(iFreindNumList)):
    if iFreindNumList[i]>maxFriend:
        maxFriend = iFreindNumList[i]

print(maxFriend)

