/*숫자로 접근한다면, 25자리 숫자에 대해서 다룰 수 있는 자료형이 없다.
따라서 문자열로 접근하기!*/
#include <iostream>
using namespace std;
int main(){
    int iNum, iRes;
    iRes = 0;
    string sInput;
    
    cin >> iNum >> sInput;
    
    for (int i=0;i<iNum;++i){
        iRes += (int)sInput[i]-48;
    }
    cout << iRes;
}
