#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int iN;
    cin >>iN;
    stack<int> st;
    for (int i=0;i<iN;++i){
        string cmd;
        int iNum;
        cin>> cmd;
        if (cmd=="push"){
            cin>>iNum;
            st.push(iNum);
        }else if (cmd=="top"){
            if (!st.empty()) cout << st.top()<<'\n';
            else cout << -1<<'\n';
        }else if (cmd == "size") cout<<st.size()<<'\n';
        else if (cmd=="empty") {
            if (st.empty()) cout << 1<<'\n';
            else cout << 0 <<'\n';
        }else {
            if (st.empty()){cout << -1<<'\n';}
            else {
                cout << st.top()<<'\n';
                st.pop();
            }
        }
    }
}