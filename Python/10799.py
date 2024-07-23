# import sys
# input = sys.stdin.readline

# iInput = list(input())
# iInput = iInput[:-1] #개행문자 처리

# newStack = []

# for _ in range(len(iInput)):
#     if iInput :
#         test = iInput.pop()
#         if test == ")" and iInput[-1] == "(":
#             iInput.pop()
#             newStack.append("r") #razor의 r
#         else :
#             newStack.append(test)

# print("print newStack", newStack)

# iCnt=0
# checkStack=[]
# newStackLen = len(newStack)
# for j in range(newStackLen):
#     if newStack[newStackLen-j-1] == ")":
#         print("j:",j,newStack[j])
#         print("checkStack",checkStack)
#         for i in range(len(checkStack)):
#             if checkStack[i] == 'r':
#                 iCnt +=1
#             elif checkStack[i] =='(':
#                 break
#             print("i, iCnt:", i, iCnt)
#     else :
#         checkStack.append(newStack[newStackLen-j-1])

# print("print checkStack", checkStack)
# print("iCnt",iCnt)



import sys
input = sys.stdin.readline

iInput = list(input())
iInput = iInput[:-1] #개행문자 처리

newStack = []
result = 0

for i in range(len(iInput)):
    if iInput[i] == '(':
        newStack.append('(')
    else :
        if iInput[i-1]=='(':
            newStack.pop()
            result += len(newStack)
        else : 
            newStack.pop()
            result+=1

print(result)