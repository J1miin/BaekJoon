#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int iN, data;
    string sOp;
    cin>>iN;
    while(iN--){
        cin>>sOp;
        if (sOp == "push"){
            cin>>data;
            q.push(data);
        }else if (sOp == "front"){
            if (!q.empty()){
                cout<<q.front()<<"\n";
            }else {
                cout << -1<<"\n";
            }
        }else if (sOp=="back"){
            if(!q.empty()){
                cout<<q.back()<<"\n";
            }else{
                cout << -1<<"\n";
            }
        }else if (sOp=="pop"){
            if (!q.empty()){
                cout<<q.front()<<"\n";
                q.pop();
            }else{
                cout<<-1<<"\n";
            }
        }else if (sOp=="empty"){
            if (!q.empty()){
                cout<<0<<'\n';
            }else{
                cout<<1<<'\n';
            }
        }else{
            cout<<q.size()<<'\n';
        }
    }
}