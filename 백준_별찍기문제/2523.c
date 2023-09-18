#include <stdio.h>
int main(){
    int input;
    //input =3 ;
    int starCnt, blankCnt;
    //아래 삼각형을 위한 변수
    int secondLine;
    int starCnt2;
    int blankCnt2;

    scanf("%d",&input);

    for(int i=0; i<input;++i){
        starCnt=i+1;
        for(int j=0; j<starCnt;++j){
            printf("*");
        }
        
        printf(" ");
        
        printf("\n");
    }
    secondLine=input-1;
    for(int i=0; i<secondLine;++i){
        starCnt2=input-i-1;
        for (int j=0; j<starCnt2;++j){
            printf("*");
        }
        printf(" ");
        printf("\n");

    }
    
    return 0;
}

/*

*/