import sys
input = sys.stdin.readline

iN , iL = map(int,input().split())

# iA1 = 1 
# iNumOfTerm = 0
# iSn = ((iA1+ iNumOfTerm -1)*iNumOfTerm)/2 #공차가 1인 등차수열의 합
iN *=2

iFlag = 0
preiNumOfTerm = [] #항의 개수가 될 수 있는 후보 숫자들을 담는 리스트로, iN*2의 약수가 들어간다.
result = []
# iN = iSn인 a1과 iNumOfTerm을 찾아야함. 
# iNumOfTerm은 iL보다 크거나 같아야하면서, iN*2의 약수여야 한다.


#iN의 약수 찾기
for i in range(1,int(iN**(1/2))+1):
    if iN%i==0 :
        preiNumOfTerm.append(i)
        if i < iN//i:
            preiNumOfTerm.append(iN//i)

preiNumOfTerm.sort()
# print(preiNumOfTerm)

for i in range(len(preiNumOfTerm)):
    iNumOfTerm = preiNumOfTerm[i]
    if iNumOfTerm >= iL :
        # print("iNumOfTerm:",iNumOfTerm)
        a1_mod = (((iN/iNumOfTerm)+1-iNumOfTerm)%2)
        a1_sign = ((iN/iNumOfTerm)+1-iNumOfTerm)
        # print("imod:",a1_mod)
        # print("sign",a1_sign)
        if a1_sign >=0 and a1_mod == 0:
            a1 = (((iN/iNumOfTerm)+1-iNumOfTerm)/2)
            for i in range(iNumOfTerm):
                result.append(int(a1+i))
                iFlag +=1 
            break

if iFlag == 0:
    result.append(-1)
    print(*result, sep=' ')
else : 
    if len(result)>100:
        print(-1)
    else: print(*result, sep=' ')