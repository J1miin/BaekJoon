#include <bits/stdc++.h>
using namespace std;
int main(){
    int iNum[3];
    for (int i=0;i<3;++i){
        cin>>iNum[i];
    }
    sort(iNum,iNum+3);
    for (auto a:iNum){
        cout<<a<<'\n';
    }
}