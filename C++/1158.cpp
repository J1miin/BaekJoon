#include <bits/stdc++.h>
using namespace std;
//큐로 다시 풀어보자!
int main(){
    list<int> L;
    int iN, iK;
    vector <int> vAns;
    cin >> iN >> iK;

    for (int i=0;i<iN;++i){
        L.push_back(i+1);
    }

    auto it = L.begin();
    for (int i=0;i<iN;++i){
        for (int j=0;j<iK-1;++j){
            ++it;
            if (it == L.end()){
                it=L.begin();
            }   
        } 
        vAns.push_back(*(it));
        it = L.erase(it);
        if(it == L.end()) it = L.begin();
        
    }
    cout<<"<";
    for (int i=0;i<vAns.size();++i){
        cout<<vAns[i];
        if (i!=vAns.size()-1){
            cout<<", ";
        }
    }
    cout<<">";
}