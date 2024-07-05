#include <stdio.h>
#define SIZE 9

int main(){
    int Arr[SIZE]={0};
    int max,maxOrder;
    max=0;
    maxOrder=0; 
    int i,j;

    for (i=0; i<SIZE; ++i){
        scanf("%d",&Arr[i]); //배열에 저장해야 하는데 이상한데다 했움..ㅋ
    }
    for (j=0; j<SIZE ; ++j){
        if(max<Arr[j]){
            max=Arr[j];
            maxOrder=j+1;
        }
    }
    printf("%d %d",max,maxOrder);
    return 0;
}