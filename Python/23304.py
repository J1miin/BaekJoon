#펠린드롬 문제 - 문제 이해를 잘못했다 |S|가 1이 될 때까지 계속 확인해야한다.
import sys
input = sys.stdin.readline

def isPelindrome(sInput, iLen):
    if iLen == 1 :
        return 1 
    
    iHalf = iLen//2 
    for i in range(iHalf):
        if sInput[i] != sInput[iLen-1-i] :
            return 0
        # else :
        #     print( i, ': ',sInput, sInput[i], sInput[iLen-1-i])
    
    iSuffix = isPelindrome(sInput[:iHalf], iHalf)
    # iPrefix = isPelindrome(sInput[-1*iHalf:], iHalf)
    #이미 펠린드롬이면 앞이나 뒤만 검사해도 충분하구나

    if iSuffix ==1 :
        return 1


sInputString = input().strip()
iStringLen = len(sInputString)

iResult = isPelindrome(sInputString,iStringLen)

if iResult == 1 :
    print('AKARAKA')
else :
    print('IPSELENTI')