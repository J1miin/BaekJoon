#트리의 부모 찾기 not yet
import sys
input = sys.stdin.readline

iVerNum = int(input())
iGraph=[[0]*(iVerNum+1) for _ in range(iVerNum+1)]

for _ in range(iVerNum-1):
    v1, v2 = map(int,input().split())
    iGraph[v1][v2]=1
    iGraph[v2][v1]=1


def dfs(startVer):
    stack = [startVer]  #스택에 노드와 촌수를 둘 다 동시에 가져가는 접근!
    while stack:
        node = stack.pop()
        print("node",node)
        if node not in iVisited:
            iVisited.add(node)
            for i in range(1, iVerNum+1):
                if iGraph[node][i] == 1 and i not in iVisited:
                    print("i",i)
                    return i

 
iVisited = set()  # 집합이용 

for i in range(2,iVerNum+1):
    print(dfs(i))
