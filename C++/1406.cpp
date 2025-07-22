#include <bits/stdc++.h>
using namespace std;
int main(){
    list<char> L;
    string sInput;
    cin >> sInput ;
    for (auto a: sInput){
        L.push_back(a);
    }
    auto cursor = L.end();
    char cCmnd;
    int iNum ;
    cin >> iNum;

    for (int i=0;i<iNum;++i){
        cin>>cCmnd;
        if (cCmnd == 'P'){
            char cInput;
            cin>>cInput;
            L.insert(cursor,cInput);
        }else if (cCmnd == 'L'){
            if (cursor != L.begin())cursor--;
        }else if (cCmnd == 'D'){
            if (cursor != L.end()) cursor++;
        }else {
            if (cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (auto a:L){
        cout<<a;
    }
}