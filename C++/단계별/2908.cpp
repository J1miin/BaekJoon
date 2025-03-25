#include <iostream>
using namespace std;
int main(){
    string sInput1, sInput2,sTmp1, sTmp2;
    sTmp1="";
    sTmp2="";
    int iSize1, iSize2;

    cin >> sInput1 >> sInput2;
    iSize1 = sInput1.size();
    iSize2 = sInput2.size();
    
    for (int i=0;i<iSize1;++i){
        sTmp1+= sInput1[iSize1-i-1];   
    }
    for (int i=0;i<iSize2;++i){
        sTmp2+= sInput2[iSize2-i-1];   
    }
    if (sTmp2 > sTmp1){
        cout<<sTmp2;
    }else{
        cout<<sTmp1;
    }

    return 0;
}