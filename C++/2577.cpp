/*
solution에서 배운점 
정수나눗셈으로 모든 자리수를 다 알아낼 수 있다!
문자열보다 정수 나눗셈으로 처리하는 방법이 더 효율적이다 
-> 다시 풀어봐자*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long A,B,C,lMul;
    int iNum[10]={0,};
    cin>>A>>B>>C;
    lMul = A*B*C;
    string sTmp = to_string(lMul);
    for (int i=0;i<sTmp.size();++i){
        iNum[sTmp[i]-'0']++;
    }
    for (auto a:iNum){
        cout<<a<<'\n';
    }
}   