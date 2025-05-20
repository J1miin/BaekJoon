#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    unordered_map<int,int> hMap;
    int answer = 0;
    vector <int> realLost;
    for (auto a:reserve){
        hMap[a]=1;
    }
    for (auto a: lost){
        if (hMap[a]){
            hMap[a]--;
            continue;
        }
        realLost.push_back(a);
    }
    sort(realLost.begin(),realLost.end());
    for (auto a:realLost){
        if (hMap[a-1]>0){
            hMap[a-1]--;
        }else if (hMap[a+1]>0){
            hMap[a+1]--;
        }else{
            n--;
        } 
    }
    answer = n;
    return answer;
}
int main(){
    solution(5, {1,2,3}, {2,3,4});
}