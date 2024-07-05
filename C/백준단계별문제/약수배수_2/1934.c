#include <stdio.h>
int find_Prime(int a);

int main(){
    int iFirst, iSecond;
    int result;//공배수
    result = 1;
    int i=2;
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
                ++i; //2여도 되는게 아닐까아..?
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
          
    
    printf("최소공배수 %d \n",result);
     

    return 0;
}

int find_Prime(int a){
    int checkMod;
    int pCnt=0;
    int result=0; //1이면 소수, 아니면 소수 아님
    for (int i=0;i<a;++i){
        checkMod=a%(1+i);
        if(checkMod==0){
            pCnt+=1;
        }
    }
    if (pCnt==2){
        result = 1;
    }
    return result;
}