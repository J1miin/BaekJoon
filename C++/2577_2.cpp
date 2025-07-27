#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int iA, iB, iC, iMul=1, iAns[10]={0,};
    cin >> iA >> iB >> iC;
    iMul = iA*iB*iC;
    while (iMul>0){
        iAns[iMul%10]++;
        iMul/=10;
    }
    for (auto a: iAns){
        cout<<a<<'\n';
    }
}