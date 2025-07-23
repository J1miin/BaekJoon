#include<bits/stdc++.h>
using namespace std;
int main(){
    int iN;
    cin>>iN;
    deque<int> dQ;
    while (iN--){
        string op;
        int val;
        cin>>op;
        if (op=="push_front"){
            cin>>val;
            dQ.push_front(val);
        }else if (op=="push_back"){
            cin>>val;
            dQ.push_back(val);
        }else if (op=="pop_front"){
            if (!dQ.empty()) {cout<<dQ.front()<<"\n"; dQ.pop_front();}
            else cout<<-1<<"\n";
        }else if (op=="pop_back"){
            if (!dQ.empty()) {cout<<dQ.back()<<"\n"; dQ.pop_back();}
            else cout<<-1<<"\n";
        }else if (op=="size"){
            cout<<dQ.size()<<"\n";
        }else if (op=="empty"){
            if (dQ.empty()) cout<<1<<'\n';
            else cout<<0<<"\n";
        }else if (op=="front"){
            if (!dQ.empty()) cout<<dQ.front()<<"\n";
            else cout<<-1<<"\n";
        }else if (op=="back"){
             if (!dQ.empty()) cout<<dQ.back()<<"\n";
            else cout<<-1<<"\n";
        }
    }
}