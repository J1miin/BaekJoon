#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<char, int> hMap;
    hMap['A'] = 2; hMap['B'] = 2; hMap['C'] = 2;
    hMap['D'] = 3; hMap['E'] = 3; hMap['F'] = 3;
    hMap['G'] = 4; hMap['H'] = 4; hMap['I'] = 4;
    hMap['J'] = 5; hMap['K'] = 5; hMap['L'] = 5;
    hMap['M'] = 6; hMap['N'] = 6; hMap['O'] = 6;
    hMap['P'] = 7; hMap['Q'] = 7; hMap['R'] = 7; hMap['S'] = 7;
    hMap['T'] = 8; hMap['U'] = 8; hMap['V'] = 8;
    hMap['W'] = 9; hMap['X'] = 9; hMap['Y'] = 9; hMap['Z'] = 9;

    string sInput;
    int iResult=0;
    cin >> sInput;
    for (int i=0;i<sInput.size();++i){
        iResult = iResult + hMap[sInput[i]] + 1;
    }
    cout << iResult;
    return 0;
}