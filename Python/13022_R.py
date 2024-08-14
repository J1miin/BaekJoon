import sys
input = sys.stdin.readline

sInput = input().strip()
iWCount = 0
iWordCountArr = [0,0,0,0] #순서대로 wolf의 문자 개수를 센다.
j = 0
iFlag = 0 

def countW(idx):
    i = 0
    iWordCountArr[0]=0
    iWordCountArr[1]=0
    iWordCountArr[2]=0
    iWordCountArr[3]=0

    if idx != 0 :
        i = idx 
    print("i", i, "idx:", idx )
    while i<len(sInput) and sInput[i]=='w' :
        iWordCountArr[0]+=1
        print(f'i:{i}, idx:{idx}, iWordCountArr: {iWordCountArr[0]}')
        i+=1

    
if sInput[0]=='w':
    countW(0)
    for j in range(len(sInput)):
        print('j:',j, sInput[j])
        if sInput[j]=='w': 
            if iWordCountArr[0]!=0 and (iWordCountArr[1]>=1 or iWordCountArr[2]>=1 or iWordCountArr[3]>=1 ) :#두번째 단어의 w인 경우를 나누려고했으나, ww의 w가 포함되어버리네
                countW(j)
                print("maybe second",iWordCountArr[0])
                
        elif sInput[j]=='o' and iWordCountArr[0]>iWordCountArr[1]:
            iWordCountArr[1]+=1
        elif sInput[j]=='l' and iWordCountArr[2]<iWordCountArr[1]: #순서대로 있어야하므로
            iWordCountArr[2]+=1
        elif sInput[j]=='f' and  iWordCountArr[3]<iWordCountArr[2]: #순서대로 있어야하므로
            iWordCountArr[3]+=1
            if j == len(sInput)-1 or sInput[j+1]!='f':
                #f는 항상 마지막에 올거니까 제일끝일 때나, f의 다음이 w가 아닐 때(그러면 순서가 다른거니까)
                #wwolfolf 이런 경우 방지
                if iWordCountArr[0] == iWordCountArr[1] and iWordCountArr[2]==iWordCountArr[1] and iWordCountArr[3]==iWordCountArr[0]: #동일 개수인지 점검
                    iFlag = 0
                else :
                    iFlag = 1 
                    break
        else :
            iFlag = 1
            break
        print(iWordCountArr)

    if iFlag == 0 :
        if iWordCountArr[0] == iWordCountArr[1] and iWordCountArr[2]==iWordCountArr[1] and iWordCountArr[3]==iWordCountArr[0]: #동일 개수인지 점검
            print(1)
        else :
            print(0)
    else :
        print(0)

else :
    print(0)
