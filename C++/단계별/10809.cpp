#include <iostream>
#include <string>
using namespace std;

int main(){
    string sInput;
    int iIdx;
    int iAlphaArr[26];
    for (int i=0;i<26;++i){iAlphaArr[i]=-1;}
    
    cin >> sInput;
    for (int i=0;i<sInput.size();++i){
        iIdx = (int)sInput[i]-97;
        if (iAlphaArr[iIdx]==-1){
            iAlphaArr[iIdx]=i;
        }
    }
    for (int i=0;i<26;++i){
        cout<<iAlphaArr[i]<<" ";
    }
    return 0;
}