import sys
input = sys.stdin.readline
#undirected graph의 연결요소 구하기

iVerNum, iEdgeNum = map(int,input().split())
iGraph=[[0]*iVerNum for _ in range(iVerNum)]
iCnt = 0 #연결요소를 카운트하는 변수 

for _ in range(iEdgeNum):
    v1, v2 = map(int,input().split())
    v1 = v1-1
    v2 = v2-1
    iGraph[v1][v2]=1
    iGraph[v2][v1]=1


# def finding (iStartVertex, iVisited):
#     if (iStartVertex+1) not in iVisited:
#         iVisited.append(iStartVertex+1)
#         for i in range(iVerNum):
#             if (i+1) not in iVisited and iGraph[iStartVertex][i]==1 :
#                 finding(i, iVisited)
#             else :
#                 continue
#     else :
#         return

# iCnt=0
# for i in range(iVerNum):
#     if (i+1) not in iVisited :
#         finding(i,iVisited)
#         # print(f"Startnum= {i}, iVisited: {iVisited}")
#         iCnt+=1
# print(iCnt)

def dfs(startVer, dVisitedArr):
    stack = [startVer]
    while stack:
        node = stack.pop()
        if node not in dVisitedArr:
            dVisitedArr.add(node)
            for i in range(iVerNum - 1, -1, -1):  
                if iGraph[node][i] == 1 and i not in dVisitedArr:
                    stack.append(i)

iVisited = set()  # 집합이용 
iCnt = 0

for i in range(iVerNum):
    if i not in iVisited:
        dfs(i, iVisited)
        iCnt += 1

print(iCnt)
