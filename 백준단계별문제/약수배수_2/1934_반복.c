#include <stdio.h>
int find_Prime(int a);

int main(){
    int inputNum;
    int iFirst, iSecond;
    int result;//공배수
    result = 1;
    int i=2;
    scanf("%d",&inputNum);
    for (int k=0;k<inputNum;++k){
        scanf("%d %d",&iFirst,&iSecond);
        int iFirstDiv, iSecondDiv;

        while(1){
            if(iFirst ==1 || iSecond==1){
                result=result *iFirst * iSecond;
                break;
            }else {
                iFirstDiv=iFirst%i;
                iSecondDiv=iSecond%i;
                if(iFirstDiv==0 && iSecondDiv==0){
                    iFirst=iFirst/i;
                    iSecond=iSecond/i;
                    result=result*i;
                    ++i;
                    if(iFirst==1 || iSecond==1){
                        result=result*iFirst*iSecond;  
                        break;
                    }
                }else{
                    if (find_Prime(iFirst)==1 || find_Prime(iSecond)==1){
                        result=result*iFirst*iSecond;  
                        break;
                    };
                    ++i;
                }
            }
        }   
        printf("%d \n",result);
        result=1;

    }

    return 0;
}

int find_Prime(int a){
    int checkMod;
    int pCnt=0;
    int result;
    result =0; //1이면 소수, 아니면 소수 아님
    for (int i=0;i<a;++i){
        checkMod=a%(1+i);
        if(checkMod==0){
            pCnt+=1;
        }
    }
    if (pCnt==2){
        result = 1;
    }else {
        result = 0;
    }
    return result;
}