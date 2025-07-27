#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int iN, iK;
    queue <int> q;
    vector <int> vAns;
    cin >> iN >> iK;
    for (int i=0;i<iN;++i){
        q.push(i+1);
    }
    while (!q.empty()){
        for(int i=0;i<iK-1;++i){
            q.push(q.front());
            q.pop();
        }    
        vAns.push_back(q.front());
        q.pop();
    }
    cout << '<';
    for (int i=0;i<vAns.size();++i){
        cout<<vAns[i];
        if (i==vAns.size()-1){
            cout<<'>';
            break;
        }
        cout<<", ";
    }
}
