#include <stdio.h>
int main(){
    int iTotalPrice, iTotalNum,iNum, iPrice,i;
    int iCheckPrice=0;
    scanf("%d",&iTotalPrice);
    scanf("%d",&iTotalNum);
    
    for (i=0;i<iTotalNum;++i){
        scanf("%d %d",&iPrice, &iNum);
        iCheckPrice=iCheckPrice+(iPrice*iNum);
    }
    if (iCheckPrice==iTotalPrice){
        printf("Yes \n");
    }else {
        printf("No \n");
    }
    return 0;
}