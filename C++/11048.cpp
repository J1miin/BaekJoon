//DP -> 자료구조 만들기
#include <iostream>
using namespace std;

int iN, iM;
int inputArr[1001][1001];
int checkArr[1001][1001]={0,};

int search(){
    int iRight=0;
    int iDown=0;
    int iMax=0;
    for (int i=1;i<=iN;++i){
        for (int j=1;j<=iM;++j){
            if (i==1 && j==1){
                checkArr[i][j]=inputArr[i][j];
            }
            //아래쪽
            if(i+1<=iN){
                iDown=checkArr[i][j]+inputArr[i+1][j];
                if (iDown >= checkArr[i+1][j]){
                    checkArr[i+1][j]=iDown;
                    if (iMax<=iDown){
                        iMax=iDown;
                    }
                }
            }
            //오른쪽
            if (j+1<=iM){
                iRight=checkArr[i][j]+inputArr[i][j+1];
                if (iRight >= checkArr[i][j+1]){
                    checkArr[i][j+1]=iRight;
                    if (iMax<=iRight){
                        iMax=iRight;
                    }
                }
            }
        }
    }
    return iMax;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); //cin/cout 빠르게 실행
    cin>>iN>>iM;
    for (int i=1;i<=iN;++i){
        for(int j=1;j<=iM;++j){
            cin>>inputArr[i][j];
        }
    }    
    cout << search();
    return 0;
}

