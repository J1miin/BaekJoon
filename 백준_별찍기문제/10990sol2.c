#include <stdio.h>
int main(){
    int input;
    int first_blankCnt;
    int second_blankCnt;
    input =4;
    for (int line =0; line<input;++line){
        first_blankCnt=input-line-1;
        for(int blank=0; blank<first_blankCnt;++blank){
            printf(" ");
        }
        printf("*");
        
        if (line>0){ //가운데 공란을 하나의 삼각형으로 보고 뒤에 별 하나 출력 (별은 변화하는 애가 아니니까) + 두번째 줄부터 출력하고 싶으니까
            second_blankCnt=2*line-1;
            for (int second_blank=0; second_blank<second_blankCnt;++second_blank){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}