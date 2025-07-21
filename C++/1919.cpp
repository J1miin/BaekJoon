#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int alpha[26]={0,}, iCnt = 0;
    string sInput1, sInput2;
    cin>> sInput1>>sInput2;
    for (auto a : sInput1) alpha[a-'a']++;
    for (auto a : sInput2) alpha[a-'a']--;
    
    for (auto a : alpha){
        //iCnt+=abs(a);
        if(a!=0){
            if (a<0) iCnt += -(a);
            else iCnt += a;
        }
    }
    cout << iCnt;
}