#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int iFirst, iSecond;
    //pq에 벡터 값 바로 복사 할 때, begin, end 이용하기
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(), scoville.end());
    while (pq.size()>1 && pq.top()<K){
        iFirst = pq.top();
        pq.pop();
        iSecond = pq.top();
        pq.pop();
        pq.push(iFirst+iSecond*2);
        answer++;
    }
    if (pq.top()<K) return -1;
    
    return answer;
}