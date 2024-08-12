import sys
input = sys.stdin.readline

sInput = input().strip()
iWCount = 0
iWordCountArr = [0,0,0,0] #순서대로 wolf의 문자 개수를 센다.
i = 0 
j = 0
iFlag = 0 

def countW(idx):
    i = 0 
    iWordCountArr[0]=0
    while i<len(sInput[idx:]) and sInput[i]=='w' :
        iWordCountArr[0]+=1
        i+=1

    
if sInput[0]=='w':
    countW(0)
    for j in range(len(sInput)):
        print('j:',j, sInput[j])
        if sInput[j]=='w': 
            if iWordCountArr[0]!=0 :#두번째 단어의 w인 경우
                countW(j)
                iWordCountArr[1]=0
                iWordCountArr[2]=0
                iWordCountArr[3]=0
        elif sInput[j]=='o' and iWordCountArr[0]>iWordCountArr[1]:
            if j%2==0 :
                sInput[j+iWordCountArr[0]-1]=='o'
                iWordCountArr[1]+=2
        elif sInput[j]=='l' and iWordCountArr[2]<iWordCountArr[1]: #순서대로 있어야하므로
            if j%2==0 :
                sInput[j+iWordCountArr[0]-1]=='l'
                iWordCountArr[2]+=2
        elif sInput[j]=='f' and  iWordCountArr[3]<iWordCountArr[2]: #순서대로 있어야하므로
            if j%2==0 :
                sInput[j+iWordCountArr[0]-1]=='f'
                iWordCountArr[3]+=2
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
