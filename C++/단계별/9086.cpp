#include <iostream>
using namespace std;

int main(){
    int iNum, iSize;
    string sInput;
    cin>>iNum;
    for (int i=0;i<iNum;++i){
        cin >> sInput;
        iSize = sInput.size();
        cout << sInput[0]<<sInput[iSize-1]<<endl;
    }
    return 0;
}