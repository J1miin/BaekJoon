#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int iN, iCnt =0;
    queue <int> q;
    cin>>iN;
    for (int i=0;i<iN;++i){
        q.push(i+1);
    }
    while (q.size()>1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front();
}