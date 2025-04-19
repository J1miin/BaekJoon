#include <iostream>
#include <queue>
using namespace std;

int iN, iM, iH;
struct Box {
    int iRow, iCol, iHeight;
    int tomato;
    int visited; // 익은 날짜
};

int dR[6] = {1,-1,0,0,0,0};
int dC[6] = {0,0,-1,1,0,0};
int dH[6] = {0,0,0,0,1,-1};

vector<Box> vBox;

void BFS() {
    queue<int> q;

    // 익은 토마토부터 bfs해야하고, visited가 거리 누적해서 가는 것처럼 +1을 해주는 방식이구만!
    for (int i = 0; i < vBox.size(); ++i){
        if (vBox[i].tomato == 1){
            vBox[i].visited = 0;
            q.push(i);
        }
    }

    // BFS 실행
    while (!q.empty()){
        int curIdx = q.front(); q.pop();
        int curR = vBox[curIdx].iRow;
        int curC = vBox[curIdx].iCol;
        int curH = vBox[curIdx].iHeight;

        for (int dir = 0; dir < 6; ++dir){
            int newR = curR + dR[dir];
            int newC = curC + dC[dir];
            int newH = curH + dH[dir];

            if (newR < 0 || newR >= iN || newC < 0 || newC >= iM || newH < 0 || newH >= iH)
                continue;

            int nextIdx = newH * (iN * iM) + newR * iM + newC;

            if (vBox[nextIdx].tomato == 0 && vBox[nextIdx].visited == -1){
                vBox[nextIdx].tomato = 1;
                vBox[nextIdx].visited = vBox[curIdx].visited + 1;
                q.push(nextIdx);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    cin >> iM >> iN >> iH; // 열, 행, 높이
    int iTemp;

    for (int h = 0; h < iH; ++h){
        for (int r = 0; r < iN; ++r){
            for (int c = 0; c < iM; ++c){
                cin >> iTemp;
                vBox.push_back({r, c, h, iTemp, -1});
            }
        }
    }

    BFS();

    int maxDay = 0;
    for (int i = 0; i < vBox.size(); ++i){
        if (vBox[i].tomato == 0){
            cout << -1 << '\n'; // 안 익은 토마토 있음
            return 0;
        }
        if (vBox[i].visited > maxDay){
            maxDay = vBox[i].visited;
        }
    }

    cout << maxDay << '\n';
    return 0;
}
