#include <stdio.h>
int main(){
    int inputNum;//n
    int numFactor[100000]={0}; //약수를 모으는 배열
    int i,j,k;
    j=0;
    k=1;
    int divideNum, modCheck;
    int sum;
    int count;
   
    while (1){
        sum=0;
        count=0;
        scanf("%d",&inputNum); //6
        for (i=0;i<inputNum;++i){
            divideNum=i+1; //1,2,3,4,5,6
            //printf("divideNum=%d \n",divideNum);
            modCheck=inputNum % divideNum; // 6/1,6/2,...
            if(modCheck==0){//약수 거르기
                if(i!=inputNum-1){
                    numFactor[j]=divideNum;
                    //printf("numFactor[%d]=%d\n",j,numFactor[j]);
                    sum=sum+numFactor[j];
                    ++j;
                }
            }
        }
        if(sum==inputNum){
            printf("%d = %d",inputNum,numFactor[0]);
            while(1){
                if(numFactor[k]==0){
                    break;
                }else if (numFactor[k]==inputNum){
                    break;
                }else{
                    printf(" + %d",numFactor[k]);
                    ++k;
                }
            }
            printf("\n");
        }else if (inputNum==-1){
            break;
        }
        else{
            printf("%d is NOT perfect. \n",inputNum);
        }
        
       
    }
    return 0;
}