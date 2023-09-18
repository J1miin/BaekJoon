#include <stdio.h>
int main(){
    int input;
    //input =3 ;
    int line;
    int blankCnt;
    scanf("%d",&input);
    for (int i=0; i<input;++i){
        line=i+1;
        blankCnt=input-line;
        for(int j=0; j<blankCnt;++j){
            printf(" ");
        }
        for(int z=0; z<line; ++z){
            printf("*");
        }
        printf("\n");
    }

    int secondTriangle;
    int blankCnt2;
    int starCnt2;
    secondTriangle=input-1; //2
    for (int i=0; i<secondTriangle;++i){
        blankCnt2=i+1;
        for(int j=0; j<blankCnt2;++j){
            printf(" ");
        }
        starCnt2=secondTriangle-i;
        for(int z=0; z<starCnt2;++z){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}