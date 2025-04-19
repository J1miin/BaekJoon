// #include <iostream>
// #include <stack>
// #include <vector>
// #include <cstring>
// using namespace std;

// // number of Nodes and edges, startNode
// int iN, iM, iStart;
// vector<vector<int>> graph;  // 그래프는 동적으로 할당
// vector<bool> visited;  // visited는 동적으로 할당

// void DFS(int iFirst) {
//     stack<int> st;
//     st.push(iFirst);
//     visited[iFirst] = true;
    
//     while (!st.empty()) {
//         int curNode = st.top();
//         st.pop();
//         cout << curNode << '\n';

//         // 내림차순으로 탐색
//         for (int i = 1; i <= iN; ++i) {  
//             if (graph[curNode][i] == 1 && !visited[i]) {
//                 st.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
// }

// int main() {
//     cin >> iN >> iM >> iStart;

//     // 그래프 및 방문 배열을 동적으로 할당
//     graph.resize(iN + 1, vector<int>(iN + 1, 0));  // iN + 1 크기의 2D 벡터
//     visited.resize(iN + 1, false);  // iN + 1 크기의 visited 배열

//     for (int i = 0; i < iM; ++i) {
//         int iRow, iCol;
//         cin >> iRow >> iCol;
//         graph[iRow][iCol] = 1;
//         graph[iCol][iRow] = 1;  // 양방향 연결
//     }
    
//     DFS(iStart);
//     cout << 0;  // 마지막에 0 출력
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100001];
bool visited[100001] = {false};
int result[100001] = {0};
int cnt = 0;

void dfs(int R)
{
    visited[R] = true;
    cnt++;
    result[R] = cnt;

    for (int i = 0; i < graph[R].size(); i++)
    {
        // 방문하지 않은 노드에 대해서만 dfs 호출
        if (!visited[graph[R][i]]) {
            dfs(graph[R][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, R, tempX, tempY;
    cin >> N >> M >> R;

    // 그래프 입력받기
    for (int i = 0; i < M; i++)
    {
        cin >> tempX >> tempY;
        graph[tempX].push_back(tempY);
        graph[tempY].push_back(tempX);
    }

    // 그래프의 각 인접 리스트를 내림차순으로 정렬
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    // DFS 시작
    dfs(R);

    // 방문 순서 출력
    for (int i = 1; i <= N; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}
