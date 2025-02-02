/*
계단오르기 문제 
연속으로 세 계단을 밟으면 안된다. -> 점화식으로 규칙 세우기!
마지막 계단은 무조건 밟아야 한다.
-> 바로전 칸을 밟은 경우 마지막 칸의 점수 : n-3+ n-1 + n  (... 0 X 0 0)  이렇게
-> 전전칸을 밝은 경우 마지막 칸의 점수 : n-2 + n 
*/
#include <iostream>
#include <algorithm>
using namespace std;
int iStair;
int iScoreArr[301];
int iCheckArr[301]={0,};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    cin>>iStair;
    for (int i=1;i<=iStair;++i) cin>>iScoreArr[i];

    iCheckArr[1]=iScoreArr[1];
    iCheckArr[2]=iScoreArr[1]+iScoreArr[2];
    iCheckArr[3]=max(iScoreArr[1]+iScoreArr[3], iScoreArr[2]+iScoreArr[3]);

    for (int i=4;i<=iStair;++i){
        iCheckArr[i]=max(iCheckArr[i-2]+iScoreArr[i],iCheckArr[i-3]+iScoreArr[i-1]+iScoreArr[i]);
    }
    cout<<iCheckArr[iStair];
}


