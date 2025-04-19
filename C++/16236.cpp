#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, sharkSize = 2, eatCount = 0, totalTime = 0;
int sharkRow, sharkCol;
int visited[20][20];
int dr[4] = {-1, 0, 0, 1}; // 상 좌 우 하
int dc[4] = {0, -1, 1, 0};
vector<vector<int>> map;

int bfs() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    //c++14상부터는 greater안 명시 필요 없지만, 얘는 아닌 듯 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fish;

    q.push({sharkRow, sharkCol});
    visited[sharkRow][sharkCol] = 1;
    int minDist = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 범위 벗어나거나 이미 방문했으면 pass
            if (nr < 0 || nc < 0 || nr >= N || nc >= N || visited[nr][nc]) continue;

            // 상어보다 큰 물고기면 pass
            if (map[nr][nc] > sharkSize) continue;

            // 이동 가능
            visited[nr][nc] = visited[r][c] + 1;

            // 먹을 수 있는 물고기
            if (map[nr][nc] != 0 && map[nr][nc] < sharkSize) {
                // 처음 물고기 발견한 거리 저장
                if (minDist == 0) minDist = visited[nr][nc];
                if (visited[nr][nc] == minDist) {
                    fish.push({nr, nc});
                }
            }
            // 이동만 가능 (빈 칸 or 같은 크기)
            else if (map[nr][nc] == 0 || map[nr][nc] == sharkSize) {
                q.push({nr, nc});
            }
        }
    }

    // 먹을 수 있는 물고기 없음
    if (fish.empty()) return 0;

    // 가장 위, 가장 왼쪽 우선
    sharkRow = fish.top().first;
    sharkCol = fish.top().second;
    map[sharkRow][sharkCol] = 0;
    eatCount++;

    if (eatCount == sharkSize) {
        sharkSize++;
        eatCount = 0;
    }

    return visited[sharkRow][sharkCol] - 1; // 걸린 시간 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    map = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                sharkRow = i;
                sharkCol = j;
                map[i][j] = 0;
            }
        }

    while (true) {
        int time = bfs();  // 한 마리 먹는 데 걸린 시간
        if (time == 0) break;
        totalTime += time;
    }

    cout << totalTime;
}
