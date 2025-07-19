#include <bits/stdc++.h>
using namespace std;
int main(){
    int num[10]={0,};
    string sInput;
    cin >> sInput;
    for (int i=0;i<sInput.size();++i){
        num[sInput[i]-'0']++;        
    }
    int iSixNine = (num[6]+num[9]+1)/2;
    num[6]=iSixNine;
    num[9]=iSixNine;
    sort(num,num+10);
    cout<<num[9];
}