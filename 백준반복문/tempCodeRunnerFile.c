#include <stdio.h>
int main(){
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
    return 0;
}