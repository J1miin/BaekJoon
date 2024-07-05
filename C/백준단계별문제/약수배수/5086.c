#include <stdio.h>
int main(){
    int iNum1, iNum2;
    int iFactor, iMul, iNeither;
    while(1){
        scanf("%d %d",&iNum1,&iNum2);
        if (iNum1==0 && iNum2==0){
            break;
        }
        iFactor=iNum2%iNum1;
        iMul=iNum1%iNum2;
        if(iFactor==0){
            printf("factor \n");
        }else if(iMul==0){
            printf("multiple \n");
        }
        else {
            printf("neither \n");
        }
    }
    

    return 0;
}