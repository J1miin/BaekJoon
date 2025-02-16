/*sol-1 : using DP */
#include <iostream>
using namespace std;
int iNumArr[100001];
int iDp[100001]={0,};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int iN, iM, iTmp;
    cin>>iN>>iM;
    
    // 숫자 입력받고 누적합 구하기
    for (int i=1;i<=iN;++i){
        cin>>iNumArr[i];
        iDp[i]=iDp[i-1]+iNumArr[i];
    }

    // 구간합
    for (int j=1;j<iM+1;++j){
        int iStart, iEnd;
        cin>>iStart>>iEnd;
        cout << iDp[iEnd]-iDp[iStart-1]<<'\n'; 
    }
    return 0;
}