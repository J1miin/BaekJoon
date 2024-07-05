//3052번 나머지 문제
//처음에 틀린 이유 : count 초기화 안했음
#include <stdio.h>
#define SIZE 10
#define MODULOR 42
int main () {
    int iArr10[SIZE]={0};
    int iCheckMod[MODULOR]={0};
    int inputNum;
    int iCount=0;
    int i,j,k;

    for (i=0;i<SIZE;++i){ //나머지 저장하기 
        scanf("%d",&inputNum);
        inputNum=inputNum%42;
        iArr10[i]=inputNum;
    }


    for (j=0;j<SIZE;++j){
        for(k=0;k<MODULOR;++k){
            if(iArr10[j]==k){
                iCheckMod[k]=iCheckMod[k]+1;
            }
        }
    }

    //0부터 41까지의 나머지를 인덱스 번호에 맞추고, 각각 나머지가 몇개 나오나 세주는 icheckmod확인용 출력
    /*
    for (int q=0;q<MODULOR;++q){
        printf("%d ",iCheckMod[q]);
    }
    */

    for (k=0;k<MODULOR;++k){
        if (iCheckMod[k]>=1){
            iCount=iCount+1;
        }
    }
    printf("%d",iCount);


    return 0;
}