#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_L 41
#define MAX_N 31

struct Knight {
    int r, c;    // 좌측 상단 좌표
    int h, w;    // 높이, 너비
    int k;       // 체력
    int damage = 0;  // 누적 데미지
    bool alive = true;
};

int L, N, Q;
int grid[MAX_L][MAX_L];  // 0: 빈칸, 1: 함정, 2: 벽
Knight knights[MAX_N];
int knight_map[MAX_L][MAX_L];  // 기사 번호 저장

// 상우하좌 방향
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// 초기 기사 위치 맵에 표시
void init_knight_map() {
    memset(knight_map, 0, sizeof(knight_map));
    for(int i = 1; i <= N; i++) {
        if(!knights[i].alive) continue;
        for(int r = knights[i].r; r < knights[i].r + knights[i].h; r++) {
            for(int c = knights[i].c; c < knights[i].c + knights[i].w; c++) {
                knight_map[r][c] = i;
            }
        }
    }
}

// 기사 이동 가능 여부 체크 (BFS)
bool can_move(int idx, int dir, vector<int>& pushed) {
    queue<int> q;
    bool visited[MAX_N] = {false};
    
    q.push(idx);
    visited[idx] = true;
    pushed.push_back(idx);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        // 이동 방향 경계 계산
        int nr = knights[cur].r + dr[dir];
        int nc = knights[cur].c + dc[dir];
        int end_r = nr + knights[cur].h - 1;
        int end_c = nc + knights[cur].w - 1;
        
        // 맵 경계 체크
        if(nr < 1 || nc < 1 || end_r > L || end_c > L) return false;
        
        // 벽 충돌 체크
        for(int r = nr; r <= end_r; r++) {
            for(int c = nc; c <= end_c; c++) {
                if(grid[r][c] == 2) return false;
            }
        }
        
        // 다른 기사와 충돌 체크
        for(int r = nr; r <= end_r; r++) {
            for(int c = nc; c <= end_c; c++) {
                int other = knight_map[r][c];
                if(other != 0 && other != cur && !visited[other]) {
                    visited[other] = true;
                    q.push(other);
                    pushed.push_back(other);
                }
            }
        }
    }
    return true;
}

// 기사 이동 및 데미지 처리
void move_knights(vector<int>& pushed, int dir) {
    // 1. 기존 위치에서 제거
    for(int idx : pushed) {
        for(int r = knights[idx].r; r < knights[idx].r + knights[idx].h; r++) {
            for(int c = knights[idx].c; c < knights[idx].c + knights[idx].w; c++) {
                knight_map[r][c] = 0;
            }
        }
    }
    
    // 2. 새 위치로 이동
    for(int idx : pushed) {
        knights[idx].r += dr[dir];
        knights[idx].c += dc[dir];
    }
    
    // 3. 새 위치에 재배치
    for(int idx : pushed) {
        for(int r = knights[idx].r; r < knights[idx].r + knights[idx].h; r++) {
            for(int c = knights[idx].c; c < knights[idx].c + knights[idx].w; c++) {
                knight_map[r][c] = idx;
            }
        }
    }
    
    // 4. 함정 데미지 계산 (명령 받은 기사 제외)
    for(int i = 1; i < pushed.size(); i++) {
        int idx = pushed[i];
        int cnt = 0;
        for(int r = knights[idx].r; r < knights[idx].r + knights[idx].h; r++) {
            for(int c = knights[idx].c; c < knights[idx].c + knights[idx].w; c++) {
                if(grid[r][c] == 1) cnt++;
            }
        }
        knights[idx].k -= cnt;
        knights[idx].damage += cnt;
        if(knights[idx].k <= 0) {
            knights[idx].alive = false;
            // 맵에서 제거
            for(int r = knights[idx].r; r < knights[idx].r + knights[idx].h; r++) {
                for(int c = knights[idx].c; c < knights[idx].c + knights[idx].w; c++) {
                    knight_map[r][c] = 0;
                }
            }
        }
    }
}

int main() {
    // 입력 처리
    cin >> L >> N >> Q;
    for(int r = 1; r <= L; r++)
        for(int c = 1; c <= L; c++)
            cin >> grid[r][c];
    
    for(int i = 1; i <= N; i++) {
        cin >> knights[i].r >> knights[i].c >> knights[i].h >> knights[i].w >> knights[i].k;
        knights[i].alive = true;
    }
    init_knight_map();
    
    // 명령 처리
    while(Q--) {
        int idx, dir;
        cin >> idx >> dir;
        
        if(!knights[idx].alive) continue;
        
        vector<int> pushed;
        if(can_move(idx, dir, pushed)) {
            move_knights(pushed, dir);
        }
    }
    
    // 결과 계산
    int total_damage = 0;
    for(int i = 1; i <= N; i++) {
        if(knights[i].alive)
            total_damage += knights[i].damage;
    }
    cout << total_damage << endl;
    
    return 0;
}


