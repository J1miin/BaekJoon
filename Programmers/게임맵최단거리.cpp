/*최단거리를 구하는 문제라서 BFS를 생각한 건 굿 ->
근데 최단거리 길이를 구할 때는 visited에 이동경로를 누적해서 계산해야함! 
segmentatin fault 방지를 위해서 조건문의 순서가 중요하다! - line 29,32*/
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int visited[101][101] = {0,};
int dRow[4] = {0,0,-1,+1}; //동서남북
int dCol[4] = {1,-1,0,0}; 
int iCnt = 0;

void bfs(vector<vector<int>> &maps, int iRow, int iCol){
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] ++;
    iCnt++;
    while (!q.empty()){
        int cRow = q.front().first;
        int cCol = q.front().second;
        
        cout<<"cRow: "<<cRow<<" cCol: "<<cCol<<" iCnt: "<<visited[cRow][cCol]<<endl;
        q.pop();
        
        for (int i=0;i<4;++i){
            int nRow = cRow + dRow[i];
            int nCol = cCol + dCol[i];
            if (nRow < 0 || nRow >= iRow || nCol < 0 || nCol >= iCol)
                continue;

            if (maps[nRow][nCol]!=0 && visited[nRow][nCol]==0){ 
                //벽을 굳이 처리해주지 않아도 되는구나! maps[nRow][nCol]!=0으로 이미 해결하고 있음
                q.push({nRow,nCol});
                visited[nRow][nCol] = visited[cRow][cCol] + 1;
                if (nRow == iRow-1 && cCol == iCol-1){
                    break;
                }
            }
        } 
    }
    iCnt = visited[iRow-1][iCol-1];
    
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int iRow = maps.size();
    int iCol = maps[0].size();

    bfs(maps,iRow,iCol);
    
    if(iCnt ==0){
        answer =-1;
    }else{
        answer= iCnt;
    }
    return answer;
}

