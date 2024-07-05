#include <stdio.h>
#define SIZE 100
int main(){
    int iPrimeCnt, iPrimeCheckCnt, iTotalNum;
    int iPrimeArr[SIZE]={0};
    int iPrimeCheck; //나머지 가질 예정

    iPrimeCheckCnt=0; //나머지가 0인 수가 몇개 나오는지 확인하는 카운트
    iPrimeCnt=0; //소수 개수 카운트
    scanf("%d",&iTotalNum);
    for (int i=0;i<iTotalNum;++i){
        scanf("%d",&iPrimeArr[i]);
    }

    for (int i=0;i<iTotalNum;++i){
        for (int j=0;j<iPrimeArr[i];++j){
            iPrimeCheck=iPrimeArr[i]%(j+1); //j+1은 자기자신까지 나누겠다는 뜻
            //printf("[%d], iPrimeCheck is %d \n",iPrimeArr[i],iPrimeCheck);
            if(iPrimeCheck==0){
                iPrimeCheckCnt+=1;
            }
        }
        if (iPrimeCheckCnt==2){ //소수이려면 1과 자기자신으로만 나눠져야 하니까
            iPrimeCnt+=1;
            iPrimeCheckCnt=0; //매 숫자마다 나머지가 0인게 몇개인지 확인을 해야하니까 다시 0으로 초기화해야함.
        }else {
            iPrimeCheckCnt=0;
        }
    }

    printf("%d",iPrimeCnt);
    return 0;
}