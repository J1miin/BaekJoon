import sys
input = sys.stdin.readline


iN = int(input())

for _ in range(iN):
    inputArr = list(input().strip())
    stack_l = []
    stack_r = []

    for i in range(len(inputArr)):
        if inputArr[i]=='<' and stack_l :
            stack_r.append(stack_l.pop())
        elif inputArr[i]=='>' and stack_r :
            stack_l.append(stack_r.pop())
        elif inputArr[i]=='-' and stack_l :
            stack_l.pop()
        else :
            if inputArr[i]=='>' or inputArr[i]=='<' or inputArr[i]=='-':
                pass
            else :
                stack_l.append(inputArr[i])

    stack_l.extend(reversed(stack_r))

    print(''.join(stack_l))