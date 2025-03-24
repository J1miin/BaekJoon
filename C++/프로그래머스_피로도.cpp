#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(int k, vector<vector<int>>& dungeons, int iCnt, int &iAns) {
    // 던전 모두 탐험한 경우 최대값 업데이트
    iAns = max(iAns, iCnt);

    // 던전 순열을 탐색
    for (int i = 0; i < dungeons.size(); ++i) {
        if (dungeons[i][0] <= k) { // 현재 체력으로 던전을 갈 수 있는 경우
            int temp_k = k - dungeons[i][1];  // 던전을 방문하고 체력 소모
            vector<vector<int>> next_dungeons = dungeons;
            next_dungeons.erase(next_dungeons.begin() + i); // 던전 방문 후, 던전 리스트에서 제거
            backtracking(temp_k, next_dungeons, iCnt + 1, iAns); // 다음 던전 방문
        }
    }
}

int main() {
    int k = 80;
    vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}}; // 던전 목록
    int answer = 0;
    backtracking(k, dungeons, 0, answer);
    cout << answer << endl; // 가능한 최대 던전 방문 수 출력
    return 0;
}
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(int k, vector<vector<int>>& dungeons, int iCnt, int &iAns) {
    // 던전 모두 탐험한 경우 최대값 업데이트
    iAns = max(iAns, iCnt);

    // 던전 순열을 탐색
    for (int i = 0; i < dungeons.size(); ++i) {
        if (dungeons[i][0] <= k) { // 현재 체력으로 던전을 갈 수 있는 경우
            int temp_k = k - dungeons[i][1];  // 던전을 방문하고 체력 소모
            vector<vector<int>> next_dungeons = dungeons;
            next_dungeons.erase(next_dungeons.begin() + i); // 던전 방문 후, 던전 리스트에서 제거
            backtracking(temp_k, next_dungeons, iCnt + 1, iAns); // 다음 던전 방문
        }
    }
}

int main() {
    int k = 80;
    vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}}; // 던전 목록
    int answer = 0;
    backtracking(k, dungeons, 0, answer);
    cout << answer << endl; // 가능한 최대 던전 방문 수 출력
    return 0;
}
