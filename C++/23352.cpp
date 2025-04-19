/*BFS는 queue자료구조 이용! 
not 재귀 
큐 사용 특징 : q.front()로 먼저 값을 읽은 후에 q.pop()으로 팝하기
memset은 cstring에 있는 것으로 초기화를 할 수 있다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int iArr[51][51];
bool bVisited[51][51];
int iN, iM;
int dRow[4] = {-1, +1, 0, 0}; // 상, 하
int dCol[4] = {0, 0, +1, -1}; // 우, 좌

pair<int,int> bfs(int startRow, int startCol) {    
    memset (bVisited, false, sizeof(bVisited));
    int maxLen = 0;
    int startValue = iArr[startRow][startCol]; 
    int endValue = 0;
    queue<pair<pair<int, int>,int>> q;

    q.push({{startRow, startCol},1});
    bVisited[startRow][startCol] = true;
    
    while (!q.empty()) {
        int currRow = q.front().first.first;
        int currCol = q.front().first.second;
        int currLen = q.front().second;
        if(currLen>maxLen || (currLen == maxLen && iArr[currRow][currCol]>endValue)){
            maxLen = currLen;
            endValue = iArr[currRow][currCol];
        }
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextRow = currRow + dRow[i];
            int nextCol = currCol + dCol[i];
            if (nextRow >= 0 && nextCol >= 0 && nextRow < iN && nextCol < iM) {
                if (!bVisited[nextRow][nextCol] && iArr[nextRow][nextCol] != 0) {
                    bVisited[nextRow][nextCol] = true;
                    q.push({{nextRow, nextCol},currLen+1});
                }
            }
        }
    }
    int iRes = startValue+endValue;
    return {maxLen, iRes};
}

int main(){
    int iLen , iRes, iAns,iMaxLen;
    cin>>iN>>iM;
    for (int i=0;i<iN;++i){
        for (int j=0; j<iM;++j){
            cin>>iArr[i][j];
        }
    }

    //탐색 시작 
    iMaxLen=0;
    iAns=0;
    for (int i=0;i<iN;++i){
        for (int j=0;j<iM;++j){
            if (iArr[i][j]!=0){
                pair<int, int> p = bfs(i,j);
                iLen = p.first;
                iRes = p.second;
                if (iLen>iMaxLen){
                    iMaxLen=iLen;
                    iAns = iRes;
                }else if (iLen == iMaxLen && iRes > iAns){
                    iMaxLen = iLen;
                    iAns = iRes;
                }
            }
        }
    }

    cout << iAns;
    return 0;
}