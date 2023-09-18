//5597번 과제 안 낸 사람
#include <stdio.h>
#define STUDNETNUM 30
#define SUBMITTER 28
int main(){
    int iStudentID[STUDNETNUM]={0};
    int Absent[STUDNETNUM]={0};
    int submitID;
    int i,j,k,p,q;

    printf("제출자의 번호를 쓰시오");
    for(i=0;i<SUBMITTER;++i){       
        scanf("%d",&submitID); 
        iStudentID[submitID-1]=submitID;
    }
    /* 1 0 3 0 5
    for (j=0;j<STUDNETNUM;++j){
        printf("%d ",iStudentID[j]);
    }
    */
    for (k=0;k<STUDNETNUM;++k){
        if(iStudentID[k]==0){
            Absent[k]=k+1;
        }
    }
    /* 0 2 0 4 0
    for (j=0;j<STUDNETNUM;++j){
        printf("%d ",Absent[j]);
    }
    */
    for (p=0;p<STUDNETNUM;++p){
        if(Absent[p]!=0){
            printf("%d\n",Absent[p]);
        }
    }
    return 0;
}