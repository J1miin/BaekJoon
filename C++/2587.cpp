#include <bits/stdc++.h>
using namespace std;
int main(){
    int iNum[5];
    int iSum = 0;
    for (int i=0;i<5;++i){
        cin>>iNum[i];
        iSum+=iNum[i];
    }
    sort(iNum,iNum+5);
    cout<<iSum/5<<'\n'<<iNum[2];
}