#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
처음에 쓴 코드에서는 누적으로 합만 했다.
ex. a/a+b/a+b+c/b/b+c/c 이렇게.. 그래서 a+c/조합이 빠지는 문제가 발생했음.
각각 종류에서 의상을 고르냐 마냐 경우의 수를 구해줘야한다.
ex. A={a,a'}이라면, A를 a로 입거나, a'으로 입거나 아예 안입는 총 3가지의 경우가 나온다. 
B={b,b',b''}이라면 B 종류의 옷을 b||b'||b''으로 입거나 아예 안입는 총 4가지의 경우가 나온다.
그래서 각 종류 별 옷의 개수 +1 을 해서 서로 곱해주면 전체 경우의 수가 나온다.
하지만 최소 한 벌은 입어야만 하므로 -1을 해줘야 한다.

*/
int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> hMap;
    int cnt = 1;
    for(int i=0;i<clothes.size();++i){
        hMap[clothes[i][1]]++;
    }
    //해시 탐색
    for (auto p : hMap){
        cnt *=(p.second+1);
    }
    cnt-=1; //모두 안입는 경우 제외
    return cnt;
}