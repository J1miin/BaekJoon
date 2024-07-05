#include <stdio.h>
#define SIZE 10000
int prime_Sum(int primeArr[], int size);

int main(){
    int iFirst, iEnd, iRepeatCnt;
    int iPrimeArr[SIZE]={0};
    int checkNum,j,k;
    int iPrimeMod; //60을 1부터 60까지 나눌거임. 그 때마다의 나머지 
    int iPrimeCheckCnt;
    iPrimeCheckCnt=0;
    j=0;
    int iCnt_prime;
    iCnt_prime=0;
    
    
    scanf("%d %d",&iFirst,&iEnd);
    iRepeatCnt=iEnd-iFirst+1;
    //처음과 마지막 수 사이의 범위 내에서 찾을거니까, 소수만 넣는 배열의 크기는 이 값이 될 것.

    //소수 찾아서 배열에 저장
    for (checkNum=iFirst; checkNum<iEnd+1; ++checkNum){
        for (int i=0; i<checkNum;++i){
            iPrimeMod=checkNum%(i+1);
            if(iPrimeMod==0){
                iPrimeCheckCnt+=1;
            }
        }
        if(iPrimeCheckCnt==2){
            iPrimeArr[j]=checkNum;
            ++j;
            iPrimeCheckCnt=0;
        }else {
            iPrimeCheckCnt=0;
        }
    }

    // 범위 내 소수가 없으면 -1 출력
    for (int k=0;k<iRepeatCnt;++k){
        if(iPrimeArr[k]!=0){
            iCnt_prime+=1;
        }
    }
    
    if(iCnt_prime==0){
        printf("-1 \n");
    }else {
        //소수의 합 출력
        int sum;
        sum = prime_Sum(iPrimeArr,iRepeatCnt);
        printf("%d \n",sum);

        //소수의 최솟값 출력하기
        printf("%d",iPrimeArr[0]);
    }

    
    return 0;
}

int prime_Sum(int primeArr[], int size){
    int result;
    result = 0;
    for (int i=0;i<size;++i){
        result = result + primeArr[i];
    }
    return result;
}

//사실 find_Min 함수는 필요가 없었음. 왜냐면 나는 소수를 순서대로 배열에 저장했으니까 
int find_Min(int primeArr[], int size){
    int iMin;
    iMin=primeArr[0];

    for (int i=0;i<size;++i){
        if(iMin>primeArr[i]){
            iMin=primeArr[i];
        }
    }
    return iMin;
}