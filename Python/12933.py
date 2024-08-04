#오리문제
import sys
input = sys.stdin.readline

sDuckSound = list(input().strip())
max_ducks = 0
states = []
valid = True

for char in sDuckSound:
    if char == 'q':
        states.append(0)  # 새로운 "quack" 시작
    elif char == 'u':
        valid = False
        for j in range(len(states)):
            if states[j] == 0:
                states[j] = 1  # "q"에서 "u"로 업데이트
                valid = True
                break
        if not valid:
            break
    elif char == 'a':
        valid = False
        for j in range(len(states)):
            if states[j] == 1:
                states[j] = 2  # "u"에서 "a"로 업데이트
                valid = True
                break
        if not valid:
            break
    elif char == 'c':
        valid = False
        for j in range(len(states)):
            if states[j] == 2:
                states[j] = 3  # "a"에서 "c"로 업데이트
                valid = True
                break
        if not valid:
            break
    elif char == 'k':
        valid = False
        for j in range(len(states)):
            if states[j] == 3:
                states.pop(j)  # "c"에서 "k"로 종료
                valid = True
                break
        if not valid:
            break
    
    max_ducks = max(len(states), max_ducks)  # 최대 길이로 오리수 업데이트

# 모든 소리가 유효하게 끝났는지(states가 비어있어야 한다!) 확인
if len(states) == 0 and valid:
    print(max_ducks)
else:
    print(-1)