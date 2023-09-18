#include <stdio.h>
int main(){
    int Arr[10000]={0};
    int inputSize;
    int inputNum;
    scanf("%d %d",&inputSize, &inputNum);

    for (int i=0;i<inputSize;++i){
        scanf("%d",&Arr[i]);
    }

    for (int j=0; j<inputSize;++j){
        if (Arr[j]<inputNum){
            printf("%d ",Arr[j]);
        }
    }
    
    return 0;
}