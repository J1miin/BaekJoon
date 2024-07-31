#촌수 계산하기
import sys
input = sys.stdin.readline

def dfs(startVer):
    stack = [(startVer, 0)]  #스택에 노드와 촌수를 둘 다 동시에 가져가는 접근! 
    while stack:
        node, chon = stack.pop()
        if node not in iVisited:
            iVisited.add(node)
            if node == iVertex2:
                return chon
            for i in range(1, iTotalNum+1):
                if iGraph[node][i] == 1 and i not in iVisited:
                    stack.append((i, chon + 1))
    return -1


iTotalNum = int(input())
iVertex1, iVertex2 = map(int,input().split())
iRelationNum = int(input())
iGraph=[[0]*(iTotalNum+1) for _ in range(iTotalNum+1)]

for i in range(iRelationNum):
    v1, v2 = map(int,input().split())
    iGraph[v1][v2]=1
    iGraph[v2][v1]=1

iVisited = set()  # 집합이용 

print(dfs(iVertex1))
