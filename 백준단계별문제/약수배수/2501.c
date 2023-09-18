#include <stdio.h>
int main(){
    int ifactorArr[10000]={0};
    int inputNum,k;
    int i,j=0;
    int modulor; //입력받은 수가 6이면 1-6까지 나누려고 하는 수
    int divide;
    int count;
    count=0;

    scanf("%d %d",&inputNum, &k);
    for(i=0;i<inputNum;++i){
        modulor=i+1; //1,2,3,4,5,6
        divide=inputNum%modulor;
        if(divide==0){
            ifactorArr[j]=modulor;
            j++; //123006 방지하고 1236 저장하고자
        }
    }
    printf("%d",ifactorArr[k-1]);

    return 0;
}