#include <stdio.h>
int main(){
    int input;
    int blankCnt;
    int starCnt;
    //input =3;
    scanf("%d",&input);
    for (int line=0;line<input;++line){
        blankCnt=input-line-1;
        for(int blank=0; blank<blankCnt;++blank){
            printf(" ");
        }
        starCnt=line+1;
        for (int star=0; star<starCnt;++star){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}