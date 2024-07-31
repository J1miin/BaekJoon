import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)
#undirected graph의 연결요소 구하기

def dfs(x,y):
    dx = [0,0,1,-1,1,1,-1,-1] #위,아래,오른쪽,왼쪽,오른쪽위,아래,왼쪽위,아래
    dy = [1,-1,0,0,1,-1,1,-1] 

    iGraph[x][y]=0
    for i in range(len(dx)):
        move_x=x+dx[i]
        move_y=y+dy[i]
        if 0<= move_x < iH and 0<=move_y<iW and iGraph[move_x][move_y]==1:
            dfs(move_x,move_y)    


while True :
    iCnt = 0 #연결요소(=섬의 개수)를 카운트하는 변수 (연결요소의 대각선을 포함한다는 차이 존재)
    iW, iH = map(int,input().split())
    if iW ==0 and iH ==0 :
        break

    iGraph=[[0]*iW for _ in range(iH)]

    for i in range(iH):
        iGraph[i] = list(map(int,input().split()))
    
    for i in range(iH):
        for j in range(iW):
            if iGraph[i][j]==1:
                dfs(i,j)
                iCnt+=1
    print(iCnt)
    