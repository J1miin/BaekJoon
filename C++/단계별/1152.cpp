//문자열을 공백 기준으로 자르기
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string sInput;
    string sTmp = "";
    vector <string> vString ;
    getline(cin,sInput); //공백포함 한 줄 받기

    for (int i = 0; i < sInput.size(); ++i) {
        if (sInput[i] == ' ') {
            if (!sTmp.empty()) {
                vString.push_back(sTmp);
                sTmp = "";
            }
        } else {
            sTmp += sInput[i];
        }
    }

    if (!sTmp.empty()) {
        vString.push_back(sTmp);
    }

    cout << vString.size();
    return 0;
}