#include <stdio.h>
int main(){
    int input;
    int starCnt2;
    //input =5;
    scanf("%d",&input);
    int starCnt;
    int secondStarInput;

    for (int i=0;i<input;++i){
        for(int j=0; j<i; ++j){
            printf(" ");
        }
        starCnt=2*input-(2*i+1);
        for (int z=0; z<starCnt;++z){
            printf("*");
        }
        printf("\n");
    }

    secondStarInput=input-1;

    for (int i=0;i<secondStarInput;++i){
        
        for (int j=0;j<secondStarInput-i-1;++j){//공란찍기
            printf(" ");
        }
        starCnt2=(i+1)*2+1;
        for(int z=0;z<starCnt2;++z){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/*
input 5
줄      별      공란    
0       9       0
1       7       1
2       5       2
3       3       3
4       1       4
---
secondinput=5-1=4
0       3       3
1       5       2
2       7       1
3       9       0

*/