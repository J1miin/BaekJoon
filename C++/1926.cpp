#include <bits/stdc++.h>
using namespace std;
int iN, iM, iCnt=0, iSize=0;
int iBoard[502][502];
int iVisited[502][502]={0,};
int dx[4] = {1,-1,0,0}; //상하좌우
int dy[4] = {0,0,-1,1};

void bfs(int x, int y){
    iCnt++;
    queue <pair<int,int>> q;
    iVisited[x][y]=1;
    q.push({x,y});
    int area =0;
    while(!q.empty()){
        area++; //q에서 팝을 한다는 것 자체가 연결된 유효한 영역이라는 뜻이니까 +1해서 영역의 크기 구하기 가능
        pair<int,int> cur = q.front(); q.pop();
        for (int i=0;i<4;++i){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx<0 || nx >= iN || ny <0 || ny >= iM) continue;
            if (iVisited[nx][ny]!=0 || iBoard[nx][ny]!=1) continue;
            iVisited[nx][ny]=1;
            q.push({nx,ny});
        }
    }
    iSize=max(iSize,area);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>iN>>iM;
    for (int i=0;i<iN;++i){
        for (int j=0;j<iM;++j){
            cin>>iBoard[i][j];
        }
    }
    for (int i=0;i<iN;++i){
        for (int j=0;j<iM;++j){
            if(iBoard[i][j]==1 && iVisited[i][j]==0 ){
                bfs(i,j);
            }
        }
    }
    cout<<iCnt<<'\n'<<iSize;
}