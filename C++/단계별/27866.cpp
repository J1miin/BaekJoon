/*문자와 문자열 */
#include <iostream>
#include <string>
using namespace std;

int main(){
    string sInput;
    int iIdx;
    cin >> sInput >> iIdx;
    for (int i=0;i<iIdx;++i){
        if (i==iIdx-1){
            cout<<sInput[i];
        }
    }
    return 0;
}