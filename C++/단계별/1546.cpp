#include <iostream>
using namespace std;
int main(){
    int iNum, iMax, iArr[1000];
    iMax =0;
    double iRes =0;
    cin >> iNum;

    for (int i=0;i<iNum;++i){
        cin>>iArr[i];
        if (iArr[i]>= iMax){
            iMax= iArr[i];
        }
    }
    for (int i=0;i<iNum;++i){
        iRes += (double)iArr[i]/iMax*100 ;
    }
    
    cout.precision(2);
    cout<<fixed;
    cout << (double)(iRes) /iNum;
    return 0;
}