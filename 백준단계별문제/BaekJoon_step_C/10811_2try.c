#include <stdio.h>
#define SIZE 100
int main(){
    int basketNum, changeNum;  //바구니 개수, 몇 번 바꾸기를 시행할지
    int iFirst, iEnd ;
    int iArr[SIZE]={0};
    int repeatNum;
    int temp,j;
    scanf("%d %d",&basketNum,&changeNum);
    //바구니에 숫자 1부터 채우기 
    for (int i=0;i<basketNum;++i){
        iArr[i]=i+1; 
    }

    for (int i=0;i<changeNum;++i){
        scanf("%d %d",&iFirst,&iEnd);
        repeatNum=(iEnd-iFirst+1)/2;
        iFirst=iFirst-1; //인덱스 맞춰주려고
        iEnd=iEnd-1;

        //12345 1-4번까지 : 14, 23  // 2번 
        for (j=0;j<repeatNum;++j){//서로 바꾸는 것을 반복 (맨 앞과 맨 뒤를 짝지어서)
            //printf("iFrist+j=%d iEnd-j=%d\n",iFirst+j,iEnd-j);
            temp = iArr[iFirst+j];
            iArr[iFirst+j]=iArr[iEnd-j];
            iArr[iEnd-j]=temp;
        }
        /*for (int i=0;i<basketNum;++i){
            printf("%d ",iArr[i]);
        }
        printf("\n");*/ 
    }

    //출력해주기
    for (int i=0;i<basketNum;++i){
        printf("%d ",iArr[i]);
    }
    
    return 0;
}