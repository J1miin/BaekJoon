#include <iostream>
using namespace std;

int main(){
    int iNum, iRepeat;
    string sInput;
    cin >> iNum;
    for (int i =0;i<iNum;++i){
        cin >>iRepeat>> sInput;

        for (int j=0;j<sInput.size();++j){
            for (int k=0;k<iRepeat;++k){
                cout<<sInput[j];
            }
        }
        cout<<endl;

    }
    return 0;
}