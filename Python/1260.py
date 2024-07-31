import sys
input = sys.stdin.readline
#bfs/dfs 문제 -> bfs는 queue, dfs으로 stack할 건데, 둘 다 배열 기반으로 생성할 예정
#두 개 배열 필요 -> 1차원 배열 for visited arr , 2차원 배열 for graph 표현
########################################
def dfs(iGraph, startVer):
    dStack.append(startVer)
    while(dStack):
        node = dStack.pop()
        # print("node, ivisitiedArr",node,dVisitedArr)
        if node not in dVisitedArr :
            dVisitedArr.append(node)
            # print("node, ivisitiedArr",node,dVisitedArr)
            for i in range(iVertexNum,0,-1): #stack에 내림차순으로 넣기 위함
                checkNum = iGraph[node-1][i-1]
                if checkNum==1 and i not in dVisitedArr:
                    dStack.append(i)
        # dStack.reverse()
        #print("dstack:",dStack)

    for i in dVisitedArr:
        print(i,end=' ')
########################################
def bfs(iGraph, startVer):
    bQueue.append(startVer)
    while(bQueue):
        node = bQueue.pop(0)
        # print("node: ",node)
        if node not in bVisitedArr :
            bVisitedArr.append(node)
            for i in range(iVertexNum):
                checkNum = iGraph[node-1][i]
                if checkNum==1 and (i+1) not in bVisitedArr:
                    bQueue.append(i+1)

    for i in bVisitedArr:
        print(i,end=' ')
########################################

iVertexNum, iEdgeNum, iStartVer = map(int,input().split())

dVisitedArr = []
bVisitedArr = []
iGraph = [[0]*iVertexNum for _ in range(iVertexNum)]
dStack = [] #dfs를 위한 stack 생성
bQueue = [] #bfs를 위한 queue 생성

for i in range(iEdgeNum):
    v1, v2 = map(int,input().split())
    v1=v1-1 #vertex와 index 맞춰주기
    v2=v2-1
    iGraph[v1][v2]=1
    iGraph[v2][v1]=1
# print2x2Array(iGraph)
dfs(iGraph=iGraph, startVer=iStartVer)
print()
bfs(iGraph=iGraph, startVer=iStartVer)