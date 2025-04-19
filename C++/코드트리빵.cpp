#include <iostream>
#include <queue>
#include <climits>
#define MAX_N 15
#define MAX_M 30
#define DIR_NUM 4
#define EMPTY make_pair(-1, -1)
using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
pair<int, int> cvs_list[MAX_M]; // 편의점 위치
pair<int, int> people[MAX_M];   // 사람 위치
int curr_t = 0;                 // 현재 시간

// 상, 좌, 우, 하
int dx[DIR_NUM] = {-1, 0, 0, 1};
int dy[DIR_NUM] = {0, -1, 1, 0};
int step[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && !visited[x][y] && grid[x][y] != 2;
}

void BFS(pair<int, int> start_pos) {
    // visited, step 값 초기화
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            visited[i][j] = false;
            step[i][j] = 0;
        }
    
    queue<pair<int, int>> q;
    int sx = start_pos.first, sy = start_pos.second;
    q.push(start_pos);
    visited[sx][sy] = true;
    step[sx][sy] = 0;
    
    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();
        
        int x = curr_pos.first, y = curr_pos.second;
        for(int dir = 0; dir < DIR_NUM; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(CanGo(nx, ny)) {
                visited[nx][ny] = true;
                step[nx][ny] = step[x][y] + 1; //아기 상어 문제 같구나
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void Simulate() {
    // Step 1. 격자에 있는 사람들을 편의점 방향으로 한 칸 이동
    for(int i = 0; i < m; i++) {
        // 아직 격자 밖에 있는 사람이거나 이미 편의점에 도착했으면 pass
        if(people[i] == EMPTY || people[i] == cvs_list[i])
            continue;
        
        // 편의점 위치에서 BFS를 실행해 최단 경로를 찾습니다.
        BFS(cvs_list[i]);
        
        int px = people[i].first, py = people[i].second;
        int min_dist = INT_MAX;
        int min_x = -1, min_y = -1;
        
        // 상, 좌, 우, 하 순으로 인접한 칸 중 최단 거리가 가장 짧은 칸을 선택합니다.
        for(int dir = 0; dir < DIR_NUM; dir++) {
            int nx = px + dx[dir], ny = py + dy[dir];
            if(InRange(nx, ny) && visited[nx][ny] && min_dist > step[nx][ny]) {
                min_dist = step[nx][ny];
                min_x = nx; //1칸만 이동하기 위해서 nx로 하는구나 
                min_y = ny;  //1칸만 이동하기 위해서 nx로 하는구나 
            }
        }
        
        // 선택된 위치로 이동합니다.
        people[i] = make_pair(min_x, min_y);
    }
    
    // Step 2. 편의점에 도착한 사람들의 위치를 이동 불가능한 칸으로 표시합니다.
    for(int i = 0; i < m; i++) {
        if(people[i] == cvs_list[i]) {
            int px = people[i].first, py = people[i].second;
            grid[px][py] = 2;
        }
    }
    
    // Step 3. 현재 시간 이하의 사람이 베이스 캠프로 이동합니다.
    if(curr_t <= m) {
        int person_idx = curr_t - 1;
        
        // 해당 사람의 편의점에서 가장 가까운 베이스 캠프를 찾습니다.
        BFS(cvs_list[person_idx]);
        
        int min_dist = INT_MAX;
        int min_x = -1, min_y = -1;
        
        // 행, 열 순서대로 탐색하여 가장 가까운 베이스 캠프를 찾습니다.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] && grid[i][j] == 1 && min_dist > step[i][j]) {
                    min_dist = step[i][j];
                    min_x = i;
                    min_y = j;
                }
            }
        }
        
        // 찾은 베이스 캠프로 이동하고, 해당 위치를 이동 불가능하게 표시합니다.
        if(min_x != -1) {
            people[person_idx] = make_pair(min_x, min_y);
            grid[min_x][min_y] = 2;
        }
    }
}

bool End() {
    // 모든 사람이 편의점에 도착했는지 확인합니다.
    for(int i = 0; i < m; i++) {
        if(people[i] != cvs_list[i])
            return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cvs_list[i] = make_pair(x - 1, y - 1);
    }
    
    // 초기 사람들은 격자 밖에 있음을 표시합니다.
    for(int i = 0; i < m; i++)
        people[i] = EMPTY;
    
    // 시뮬레이션을 진행합니다.
    while(true) {
        curr_t++;
        Simulate();
        if(End()) break;
    }
    
    cout << curr_t << '\n';
    return 0;
}
