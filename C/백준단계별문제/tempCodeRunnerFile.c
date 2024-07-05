#include <stdio.h>
#define SIZE 100000
int main(){
    int inputNum; 
    int iFactorArr[SIZE]={0};
    int modCheck;
    int sum;
    sum=0;
    
    scanf("%d",&inputNum);
    for(int i=0;i<inputNum;++i){
        modCheck=inputNum%(i+1);
        if(modCheck==0){//약수라면
            iFactorArr[i]=i+1; //약수저장
            if(i<inputNum){//자기 자신은 빼야 하니까
                sum=sum+iFactorArr[i];
            }
        }        
    }
    if(sum==inputNum){
        printf("%d = %d ",inputNum,iFactorArr[0]);
        for(int j=1;j<inputNum;++j){
            if(iFactorArr[j]!=0){
                printf("+ %d",iFactorArr[j]);
            }
        }
    }else {
        printf("%d is NOT perfect",inputNum);
    }
    if(inputNum==-1){
        break;
    }
    return 0;
}