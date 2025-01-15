#...그냥 진짜 다 비용 비교....?
import sys
input = sys.stdin.readline
from itertools import permutations #순열 이용해서 모든 조합을 다 비교하는 방식 ,,, 맘에 안든닷..

iN = int(input())
iCostArr = [list(map(int,input().split())) for _ in range(iN)]
total_cost = sys.maxsize
checkCost = 0
#도시의 순서 조합 만들때 쓰일 '도시를 담고 있는 리스트'
sequenceCase = [i for i in range(iN)]

caseArr = list(permutations(sequenceCase,iN))
#print(caseArr)
for i in range(len(caseArr)):
    for j in range(iN):
        if j== iN-1 and iCostArr[caseArr[i][j]][caseArr[i][0]] != 0 :
            #print(f"i:{i}, j: {j}", caseArr[i][j], caseArr[i][0])
            checkCost+= iCostArr[caseArr[i][j]][caseArr[i][0]] #처음으로
        else :
            if iCostArr[caseArr[i][j]][caseArr[i][j+1]] == 0 :
                continue
            else :
                #print(f"i:{i}, j: {j}", caseArr[i][j], caseArr[i][j+1])
                checkCost += iCostArr[caseArr[i][j]][caseArr[i][j+1]]
        #print("cost: ", checkCost)
    if checkCost <= total_cost :
        total_cost = checkCost
        checkCost = 0
    #print(f"{i}: total_cost: ", total_cost)
print(total_cost)