#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[26]={0,};
    string s;
    cin>>s;
    for (int i=0;i<s.size();++i){
        arr[s[i]-'a']++;
    }
    for (auto a : arr){
        cout<<a<<" ";
    }
}