#include <stdio.h>
int main(){
    int line, line_1;
    int blank, blankCnt;
    int star, starCnt;
    int input;
    //input =5 ;
    scanf("%d",&input);
    for (line=0;line<input;++line){
        line_1=line+1;
        for (blank=0;blank<line;++blank){
            printf(" ");
        }
        starCnt=2*(input-line)-1;
        for (star=0;star<starCnt;++star){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/*
입력값 3
줄  줄+1    별  공란(line이랑 같고)    엔터   
0   1       5   0               1
1   2       3   1               1
2   3       1   2               1
*/