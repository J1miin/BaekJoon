#include <stdio.h>
int main(){
    int subjectNum,inputScore;
    int originalScore[1000]={0};
    double changeScore[1000]={0};
    int i,j,k;
    int maxScore;
    double avr;
    avr=0;
    maxScore=originalScore[0];

    scanf("%d",&subjectNum);
    for(i=0;i<subjectNum;++i){
        scanf("%d",&inputScore);
        //if(inputScore<=100 && inputScore>=0){}
        originalScore[i]=inputScore;
    }
    for (int p=0;p<subjectNum;++p){
        if(maxScore<originalScore[p]){
            maxScore=originalScore[p];
        }
    }
    //printf("%d \n",maxScore);
    for (j=0;j<subjectNum;++j){
        changeScore[j]=(double)originalScore[j]/maxScore*100;
        avr=avr+changeScore[j];
        //printf("%lf ",changeScore[j]);
    }
    avr=(double)(avr)/subjectNum;
    printf("%.2lf",avr); //.2lf로 해야가능한듯..
    return 0;
}