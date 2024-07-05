#include <stdio.h>
#define SIZE 5
#define CHECK 3
int main(){
    int Arr[SIZE]={0};
    int inputNum;
    int Absent[CHECK]={0};
    int k, q, min, secondMin;

    for (int i=0; i<CHECK ; ++i){
        scanf("%d",&inputNum);
        Arr[inputNum-1]=inputNum; //1번 학생은 0번 인덱스에 
    }
    for (int j=0; j<SIZE; ++j){
        if(Arr[j]==0){
            Absent[j]=j+1; //몇 번 애가 과제 안냈는지 체크 가능
        }
    }
    for (q=0; q<SIZE; ++q){
        printf("전체 제출 현황 : %d \n",Arr[q]);
    }
    for (int k=0; k<SIZE; ++k){
        printf("미제출 번호 : %d \n",Absent[k]);
    }


    return 0;
}