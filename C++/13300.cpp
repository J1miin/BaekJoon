#include <bits/stdc++.h>
using namespace std;
/*
N = 전체 학생 수 
K = 한 방 최대 인원 수 
S = 성별 0 여학생, 1 남학생
Y = 학년 
*/
/*
1 : 남자 0 여자 1   (1*2-2) (1*2-1)
2 : 남자 2 여자 3
3 : 남자 4 여자 5
4 : 6 7
5 : 8 9 (5*2-2) (5*2-1)
6 : 10(6*2-2) 11(6*2-1) 
-> 그냥 바로 2차원 배열로 해도 됐구나..!!
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int iN,iK, iAns = 0;
    int studentArr[12] = {0,};
    cin >> iN >>iK;
    for (int i=0;i<iN;++i){
        int iY, iS, idx;
        cin >> iS >> iY;
        if (iS==0){
            idx = 2*iY-2;
        }else {
            idx = 2*iY-1;
        }
        studentArr[idx]++;
    }
    for (auto a: studentArr){
        if (a == 0) continue;
        if (a%iK==0){
            iAns+=a/iK;
        }else {
            iAns +=a/iK+1;
        }
    }
    cout<<iAns;
}