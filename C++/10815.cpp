#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int,int> hMap;
    int iNum, iFindNum;
    vector <int> answer;
    cin >> iNum;
    for (int i=0;i<iNum;++i){
        int iInput;
        cin >> iInput;
        hMap[iInput] ++;
    }

    cin >>iFindNum;
    for (int i=0;i<iFindNum;++i){
        int iTarget;
        cin >> iTarget;
        if (hMap[iTarget]==1){
            answer.push_back(1);
        }else {
            answer.push_back(0);
        }
    }
    for (auto a:answer){
        cout<<a<<" ";
    }
}