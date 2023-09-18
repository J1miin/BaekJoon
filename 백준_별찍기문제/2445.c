#include <stdio.h>
int main(){
    int input, lineCnt;
    int blankCnt;
    int secondLine;
    //input =5;
    scanf("%d",&input);
    for (int i=0; i<input;++i){
        lineCnt=i+1;
        for (int z=0 ; z<lineCnt;++z){
            printf("*");
        }
        blankCnt=input-lineCnt;
        for (int j=0 ; j<blankCnt;++j){
            printf(" ");
        }
        for (int j=0 ; j<blankCnt;++j){
            printf(" ");
        }
        for (int z=0 ; z<lineCnt;++z){
            printf("*");
        }
        printf("\n");
    }
    secondLine=input-1; //4
    for (int i=0; i<secondLine; ++i){

        for(int z=0; z<secondLine-i;++z){
            printf("*");
        }
        blankCnt=1+i;
        for(int j=0; j<blankCnt;++j){
            printf(" ");
        }
        for(int j=0; j<blankCnt;++j){
            printf(" ");
        }

        for(int z=0; z<secondLine-i;++z){
            printf("*");
        }
        
        printf("\n");
    }
    return 0;
}

/*
input 5
줄      별      공란
0       1       4
1       2       3  
2       3       2
3       4       1
4       5       0
//아래부분
input 5
줄      별      공란
0       4       1
1       3       2  
2       2       3
3       1       4
*/