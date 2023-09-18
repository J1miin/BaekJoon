#include <stdio.h>
int main(){
    int Arr[1000000]={0};
    int inputSize ;
    scanf("%d",&inputSize);

    for (int i=0; i<inputSize;++i){
        scanf("%d",&Arr[i]);
    } //배열 구성
    
    int max, min;
    max=Arr[0];
    min=Arr[0];
    for (int j=0; j<inputSize; ++j){
        if(max<Arr[j]){
            max=Arr[j];
        }
        if(min>Arr[j]){
            min=Arr[j];
        }
    }
    printf("%d %d",min, max);

    return 0;
}