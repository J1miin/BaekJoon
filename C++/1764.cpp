#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int iN, iM,iRes;
    iRes=0;
    ios::sync_with_stdio(0); cin.tie(0); //cin/cout 빠르게 실행
    string inputName;
    cin>>iN>>iM;
    unordered_map<string,bool> hNoHeardMap;
    vector<string> vNoSeen;
    vector<string> vResult;
    for(int i=0;i<iN;++i){
        cin>>inputName;
        hNoHeardMap[inputName]=true;
    }
    for(int i=0;i<iM;++i){
        cin>>inputName;
        vNoSeen.push_back(inputName);
    }
    for (const auto& name : vNoSeen) {
        if (hNoHeardMap.find(name) != hNoHeardMap.end()) {
            iRes++;
            vResult.push_back(name);
        }
    }
    cout<<iRes<<"\n";
    sort(vResult.begin(),vResult.end()); //사전순 정렬 
    for (const auto& name : vResult) {
        cout << name << "\n";
    }
}