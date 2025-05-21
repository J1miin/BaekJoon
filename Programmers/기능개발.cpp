#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int iMax =0 ;
    vector<int> vTmp;
    vector<int> answer;
    
    for (int i=0;i<progresses.size();++i){
        int iMax = 0;
        int tmp =  (100 - progresses[i] + speeds[i] - 1) / speeds[i]; //올림 계산
        
        if (iMax<tmp){
            iMax = tmp;
            vTmp.push_back(tmp);
        }
    }
 
    int currentMax = vTmp[0];
    int count = 1;
    
    for (int i=1;i<vTmp.size();++i){
        if (vTmp[i] > currentMax) {
            answer.push_back(count);
            currentMax = vTmp[i];
            count = 1;
        } else {
            count++;
        }
    }
    answer.push_back(count); 
    return answer;
}