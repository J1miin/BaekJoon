#define TRUE 1
#include <stdio.h>

int main(){
    int input1, input2;
    int result;

    while (TRUE){
        scanf("%d %d",&input1,&input2);
        if (input1>0 && input1<10 && input2>0 && input2<10){
            result=input1+input2;
            printf("%d \n", result);
        }
        if (input1==EOF && input2==EOF){
            break;
        }
        
    }

    return 0;
}





/* 11022번
    int TryCnt, Input1, Input2, Result;
    int CaseCnt;
    scanf("%d",&TryCnt);

    for (int i=0; i<TryCnt; ++i){
        scanf("%d %d",&Input1,&Input2);  
        if ((Input1>=1 && Input1<10) && (Input2>=1 && Input2<10)){
            Result=Input1+Input2;
            CaseCnt=i+1;
            printf("Case #%d: %d + %d = %d\n",CaseCnt,Input1,Input2, Result);
        }else {
            printf("범위를 초과합니다.\n");
        }      
    }    
*/