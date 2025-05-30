import sys
input = sys.stdin.readline

stack_l = list(input().strip()) #개행문자 제거
stack_r = []
iN = int(input())

for i in range(iN):
    command = input().strip().split()
    if command[0] == "L" and stack_l:
        stack_r.append(stack_l.pop())
    elif command[0] == "D" and stack_r:
        stack_l.append(stack_r.pop())
    elif command[0] == "B" and stack_l:
        stack_l.pop()
    elif command[0] == "P":
        stack_l.append(command[1])

print("".join(stack_l + list(reversed(stack_r))))