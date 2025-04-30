#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> hMap; 
        for (int i=0;i<s.size();++i){
            hMap[s[i]]++;
        }
        for (int i=0;i<s.size();++i){
            if (hMap[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;
    cout<<solution.firstUniqChar("lliovelove")<<endl;
    return 0;
}