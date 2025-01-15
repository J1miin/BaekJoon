#마인크래프트 문제
import sys
input = sys.stdin.readline
#세로, 가로, 블록개수
iRow, iCol, iB = map(int,input().split())
iFieldArr = [list(map(int,input().split())) for _ in range(iRow)]
answer = sys.maxsize
idx = 0

for floor in range(257):
    max_target, min_target = 0, 0

    for i in range(iRow):
        for j in range(iCol):

            if iFieldArr[i][j] >= floor:
                max_target += iFieldArr[i][j] - floor
            
            else:
                min_target += floor - iFieldArr[i][j]
            
    if max_target + iB >= min_target:
        if min_target + (max_target*2) <= answer:
            answer = min_target + (max_target*2)
            idx = floor
    

print(answer,idx)