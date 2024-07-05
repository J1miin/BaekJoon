// #2441번 

#include <stdio.h>
int main(){
    int line, input, star;
    int starCnt;
    int blank;
    //input=3;
    scanf("%d",&input);
    for (line=0;line<input;++line){
        starCnt=input-line;
        for (blank=0;blank<line;++blank){
            printf(" ");
        }
        for(star=0;star<starCnt;++star){
            printf("*");
        }
        printf("\n");
    }
    
    
    return 0;
}

/*
input 3
줄cnt 별 공백 엔터
0     3  0   1
1     2  1   1
2     1  2   1

*/
