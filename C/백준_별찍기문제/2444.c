//다시해보기
#include <stdio.h>
int main(){
    int line0,line0_1,line0Cnt;
    int blank0, blank0Cnt;
    int star0, star0Cnt;
    //
    int line, line_1;
    int blank, blankCnt;
    int star, starCnt;
    int input;
    input =5 ;
    //scanf("%d",&input);
    
    for (line0=0;line0<input-1;++line0){
        line0_1=line0+1; //1 2 3 4 5 
        blank0Cnt=input-line0_1; //4 3 2 1 0
        //printf("%d\n",blank0Cnt);
        for(blank=0;blank<blank0Cnt;++blank){
            printf(" ");
        }
        star0Cnt=2*line0+1;
        //printf("%d",star0Cnt);
        for (star=0;star<star0Cnt;++star){
            printf("*");
        }
        printf("\n");
    }
    //아래 역삼각형
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
입력값 5
위의 줄
줄 줄+1     별      공란
0   1       1       4   
1   2       3       3
2   3       5       2
3   4       7       1
줄  줄+1    별  공란(line이랑 같고)    엔터   
0   1       5   0               1
1   2       3   1               1
2   3       1   2               1
*/