#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    string answer = "";
    unordered_map<string,int> hMap;
    for (auto a : participant){
        hMap[a]++;  
    }
    for (auto c : completion){
        hMap[c]--;
    }
    for (auto a: participant){
        if (hMap[a]>=1){
            answer = a;
        }
    }
    cout<<answer<<endl;
    return 0;
}
