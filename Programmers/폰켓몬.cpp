/*
해시 문제 - 해시의 크기가 곧 종류와 마찬가지..!! (있기만 하면 되는거니까)
근데 이제 전체 개수 /2 의 크기보다 해시 크기가 작다면, 해시에 있는 개수가 답이 됨
*/
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{   
    int size= nums.size();
    int kind=size/2;
    int answer = 0;
    unordered_map<int,int> hMap;
    
    for (auto a: nums){
        if(hMap[a]) hMap[a]++;
        hMap[a]=1;
    }
    
    if (hMap.size()>=kind){
        answer=kind;
    }else{
        answer=hMap.size();
    }
 
    return answer;
}