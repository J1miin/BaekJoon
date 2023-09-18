#include <stdio.h>

int main(){
    int inputNum;
    int i,j;
    
    scanf("%d",&inputNum);
    i=2;
    j=0;

    while(1){ 
        if(inputNum==1){
            break;
        }else {
            if (inputNum%i==0){ //inputNum=10으로 시작 
                inputNum=inputNum/i; //5이 되겠지
                printf("%d\n",i);// 소인수 저장하는 배열에 2 넣기 
                j=j+1; //배열 다음칸에 해야하니까 ++j
                
            }else {
                ++i;
            }

        }
        
    }
    
    return 0;
}