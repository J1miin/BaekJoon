#include <stdio.h>

int main(){
    int iBasketArr[100]={0};
    int iBasket, iTry; //ibasket=n, itry=m
    int i,j,k; //for iterate
    int iFirst, iEnd; //바꿀 위치
    int iSwitchNum; //바꿀 숫자 개수 확인하는 변수
    int temp, sumofi_j;
    printf("n m");
    scanf("%d %d",&iBasket,&iTry);

    for(i=0;i<iBasket;++i){
        iBasketArr[i]=i+1; //바구니에 1-n까지 번호 붙이기
    }

    for(j=0;j<iTry;++j){
        scanf("%d %d",&iFirst,&iEnd);
        iSwitchNum=iEnd-iFirst+1;
        //iSwitchNum=iSwitchNum/2;
        
        sumofi_j=iFirst-1+iEnd-1;

        for(k=0;k<iSwitchNum;++k){ //iswitchnum인 이유는 2번반 스위치해도 되니까
            temp=iBasketArr[k];
            iBasketArr[k]=iBasketArr[sumofi_j-k];
            iBasketArr[sumofi_j-k]=temp;
        }
        
        // 테스
        for(int q=0;q<iBasket;++q){
        printf("%d ",iBasketArr[q]);
        }

    }

    /*for(int q=0;q<iBasket;++q){
        printf("%d ",iBasketArr[q]);
    }*/
    return 0;
}
