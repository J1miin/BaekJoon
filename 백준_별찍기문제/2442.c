// #2442번 

#include <stdio.h>
int main(){
    int line, line_1;
    int blank, blankCnt;
    int star, starCnt;
    int input;
    //input =3;
    scanf("%d",&input);

    for (line=0;line<input;++line){
        line_1=line+1;
        blankCnt=input-line_1;
        for (blank=0;blank<blankCnt;++blank){
            printf(" ");
        }
        starCnt=2*line_1-1;
        for (star=0;star<starCnt;++star){
            printf("*");
        }
        printf("\n");
    }
    
    
    
    return 0;
}

/*
입력값 3
줄  줄+1    별  공란(input-(줄+1))    엔터   
0   1       1   2               1
1   2       3   1               1
2   3       5   0               1
*/