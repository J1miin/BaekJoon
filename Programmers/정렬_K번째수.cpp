#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i,j,k;
    for (int t=0;t<commands.size();++t){
        i = commands[t][0]-1;
        j = commands[t][1];
        k = commands[t][2]-1;
        vector<int>tmp;
        for (int s = i;s<j;++s){
            tmp.push_back(array[s]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[k]);
    }
    return answer;
}
