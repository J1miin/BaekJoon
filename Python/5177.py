#출력형식 문제
# 1. 대문자 -> 소문자로 변경하기 .lower()
# 2. 앞뒤 공백은 삭제하기 .strip() 
# 3. 괄호 통일하기 '()' 형태로 다 바꾸기  .replace(old, new)
# 4. ;을 ,로 바꾸기
# .split() 문자열 띄어쓰기 기준으로 나누기

import sys
import re

input = sys.stdin.readline

def Changing(s1, s2):
    # 대문자 -> 소문자 & 앞뒤 공백 삭제
    s1 = s1.lower().strip()
    s2 = s2.lower().strip()

    # 괄호 처리
    s1 = s1.replace('{', '(').replace('}', ')').replace('[', '(').replace(']', ')')
    s2 = s2.replace('{', '(').replace('}', ')').replace('[', '(').replace(']', ')')

    # ;->,
    s1 = s1.replace(';', ',')
    s2 = s2.replace(';', ',')

    ### 정규식 이용 ###
    # 모든 공백 -> 단일 공백
    s1 = re.sub(r'\s+', ' ', s1)
    s2 = re.sub(r'\s+', ' ', s2)

    # 특수부호 앞뒤 공백 삭제
    s1 = re.sub(r'\s*([(),\[\]{}.:;])\s*', r'\1', s1)
    s2 = re.sub(r'\s*([(),\[\]{}.:;])\s*', r'\1', s2)

    return s1, s2

i = 1
iTestCaseNum = int(input())

while iTestCaseNum > 0:
    sentence1 = input().strip()
    sentence2 = input().strip()

    sentence1, sentence2 = Changing(sentence1, sentence2)

    if sentence1 == sentence2:
        print(f'Data Set {i}: equal')
    
    else:
        print(f'Data Set {i}: not equal')
    print() #ㅂㄷㅂㄷ 이거 안넣어서 틀림
    iTestCaseNum -= 1
    i += 1