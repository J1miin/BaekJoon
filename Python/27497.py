#알파벳 블록
import sys
input = sys.stdin.readline

iPlayNum = int(input())
sResultArr = []
charSequenceArr = []

def blockGame(sInputList, seq):
    if sInputList[0] == '1' :
        sResultArr.append([sInputList[1],seq])
        charSequenceArr.append(sInputList[1])
    elif sInputList[0] == '2' : #맨앞에 추가
        sResultArr.insert(0,[sInputList[1],seq])
        charSequenceArr.append(sInputList[1])
    elif sInputList[0] == '3' :
        tempArr=[]
        if sResultArr == False :
            pass
        for j in range(len(sResultArr)):
            for k in range(len(sResultArr)):
                if charSequenceArr[len(charSequenceArr)-j-1] == sResultArr[k][0] :
                    #같은게 있을 수 있으니까
                    tempArr.append(sResultArr[k])
        if tempArr :
            tempArr.sort(key=lambda x : int(x[1]) ,reverse=True)
            sResultArr.remove(tempArr[0])
            
def printResult(arr):
    result=[]
    if sResultArr :
        for i in range(len(arr)):
            result.append(arr[i][0])
        print(''.join(result))
    else :
        print(0)
##################
for i in range(iPlayNum):
    sInputList = input().split()
    blockGame(sInputList,i)

printResult(sResultArr)