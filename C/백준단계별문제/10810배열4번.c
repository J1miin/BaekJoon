#include <stdio.h>
int main(){
    int inputSize; //배열크기=n
    int m ; //몇 번 시행을 할지
    int i,j; 
    int Arr[100]={0};
    int ballInBasket;
    int p;
    int temp; //for swap
    
    //printf("basket num and m\n");
    scanf("%d %d",&inputSize, &m);
    for (p=0; p<inputSize;++p){
        ballInBasket=p+1;
        Arr[p]=ballInBasket; //순서대로 공 넣기 0번 인데스에 1번 공
    }
    for (int q=0;q<m;++q){
        //printf("where do u want to swap? \n");
        scanf("%d %d",&i,&j);
        i=i-1;
        j=j-1; //index 맞춰주기 (1번방이면 0번 인덱스)
        temp=Arr[i];
        Arr[i]=Arr[j];
        Arr[j]=temp;
    }

    for (int final=0;final<inputSize;++final){
        printf("%d ", Arr[final]);
    }
    
    return 0;
}