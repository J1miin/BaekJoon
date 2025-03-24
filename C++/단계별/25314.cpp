#include <iostream>
#include <string>
using namespace std;

int main(){
    int iInput,iRepeatNum;
    cin>>iInput;
    iRepeatNum = iInput / 4;
    for (int i=0;i<iRepeatNum;++i){
        cout <<"long ";
    }
    cout << "int";
    return 0;
}