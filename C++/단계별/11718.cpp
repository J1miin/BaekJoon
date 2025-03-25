#include <iostream>
using namespace std;
int main(){
    string sTmp;
    for (int i=0;i<100;++i){
        getline(cin, sTmp);
        if (sTmp.empty()){
            break;
        }
        cout<<sTmp<<'\n';
        sTmp="";
    }
    return 0;
}
