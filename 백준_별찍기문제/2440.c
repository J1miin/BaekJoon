// #2440번 

#include <stdio.h>
int main(){
    int line, star;
    int starCnt;
    int input;
    scanf("%d",&input);
    //input =3 ;
    for (line=0;line<input;++line){
        starCnt=input-line;
        for (star=0;star<starCnt;++star){
            printf("*");
        }
        printf("\n");
    }
    
    
    return 0;
}

/*
입력값 3
줄 0 | 1번 줄 별 3개 엔터 1번
줄 1 | 2번 줄 별 2개 엔터 1번
줄 2 | 3번 줄 별 1개 엔터 1번
-1*n(줄)+4(input+1)
*/