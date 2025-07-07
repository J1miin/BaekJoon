//여러 개의 연결 요소를 찾아야하니까 BFS를 반복문으로 여러 번 돌려야 한다.
//BFS 한 번은 하나의 연결요소 찾기!
#include <string>
#include <vector>
#include <queue>

using namespace std;
bool visited[201] = {false,};
int iMap[201][201]={0,};
int cnt = 0;

void bfs(int iMap[201][201], int n, int start){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i=0;i<n; ++i){
            if (iMap[cur][i]==1 && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    cnt++;
}

int solution(int n, vector<vector<int>> computers) {

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            iMap[i][j] = computers[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bfs(iMap, n, i); 
        }
    }

    return cnt;
}