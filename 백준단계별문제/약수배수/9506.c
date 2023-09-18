#include <stdio.h>
int main(){
    int inputNum;//n
    int i,j,k;

    j=0;
    int divideNum, modCheck;
    int sum;
    int count;
   
    while (1){
        int numFactor[100000]={0}; //약수를 모으는 배열
        sum=0;
        count=0;
        scanf("%d",&inputNum); //6
        for (i=0;i<inputNum;++i){
            divideNum=i+1; //1,2,3,4,5,6
            //printf("divideNum=%d \n",divideNum);
            modCheck=inputNum % divideNum; // 6/1,6/2,...
            if(modCheck==0){//약수 거르기
                if(i!=inputNum-1){//inputnum-1=5번째 인덱스 접근한다면, 즉 마지막 자기자신은 빼려고
                    numFactor[i]=divideNum;
                    sum=sum+numFactor[i];
                }
            }
            //printf("j = [%d]",j);
            //printf("numfactor = %d \n",numFactor[i]);
        }
       /* 
        for(int p=0;p<inputNum;++p){
            printf("numfactor %d\n",numFactor[p]);
        }
        */

        if (sum == inputNum) {
            printf("%d = %d", inputNum, numFactor[0]);
            k = 1;
            while (numFactor[k] != 0 && numFactor[k] != inputNum) {
                printf(" + %d", numFactor[k]);
                ++k;
            }
            printf("\n");
        }else{
            printf("%d is NOT perfect. \n",inputNum);
        }

        if (inputNum==-1){
            break;
        }
        
        
       
    }
    return 0;
}