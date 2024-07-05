//반복문에 쓰인 조건 변수로 if문에 넣어서 조건을 나눌 수 있구나.!! 
#include <stdio.h>
int main(){
    int blankCnt;
    int starCnt;
    int input;
    //input = 4;
    scanf("%d",&input);
    for (int i=0;i<input;++i){
        blankCnt=input-i-1;
        for(int z=0;z<blankCnt;++z){
            printf(" ");
        }
        printf("*");

        for(int blank2=0;blank2<i;++blank2){
            printf(" ");
        }
        for (int blank3=0;blank3<i-1;++blank3){
            printf(" ");
        }
        if (i>0){
            printf("*");
        }
        printf("\n");
        
    }
    return 0;
}

/*
이 풀이에서는 삼각형을 세 구역으로 나눠서 계산한 것임. 노션 참고

*/