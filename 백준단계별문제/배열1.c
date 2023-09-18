#include <stdio.h>
int main(){
    int inputSize ;
    scanf("%d",&inputSize);

    int Arr[100]={0};

    for (int i=0;i<inputSize;++i){
        scanf("%d",&Arr[i]);
    }
    //printf("what is the number that u want to find?\n");
    int CntNum, Cnt;
    Cnt=0;

    scanf("%d",&CntNum);
    for (int i=0;i<inputSize;++i){
        if(Arr[i]==CntNum){
            Cnt=Cnt+1;
        }
    }
    printf("%d",Cnt);
    return 0;
}