#include <bits/stdc++.h>
using namespace std;
int iN; 
vector<string> vStr;

int main(){
    cin >> iN;
    for (int i=0;i<iN;++i){
        string str, sAns = "";
        list<char> l;
        cin>>str;
        auto it = l.begin();

        for (char c : str){
            if (c=='<'){
                if (it != l.begin()){
                    it--;
                }
            }else if (c=='>'){
                if (it != l.end()){
                    it++;
                }
            }else if (c=='-'){
                if (it != l.begin()){
                    it--;
                    it=l.erase(it);
                }
            }else{
                l.insert(it,c);
            }
        }
        for (auto a: l){
            sAns.push_back(a);
        }
        vStr.push_back(sAns);
    }
    for (auto a: vStr){
        cout<<a<<'\n';
    }
}