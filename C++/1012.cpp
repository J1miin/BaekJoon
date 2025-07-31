#include <bits/stdc++.h>
using namespace std;
int iT, iM, iN, iK, iAns;
int iBoard[51][51];
int iVisited[51][51] = {0,};
int dx[4]={-1,1,0,0}; //상하좌우
int dy[4]={0,0,-1,1};
queue<pair<int,int>> q;
void bfs(int x, int y){
    iAns++;
    q.push({x,y});
    iVisited[x][y]=1;
    while(!q.empty()){
        pair <int, int> cur = q.front(); q.pop();
        for (int i=0;i<4;++i){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx <0 || ny<0 || nx>=iN || ny>=iM) continue;
            if (iVisited[nx][ny]!=0 || iBoard[nx][ny]==0) continue;
            q.push({nx,ny});
            iVisited[nx][ny]=1; 
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> iT;
    while(iT>0){
        iAns=0;
        cin >> iM >> iN >> iK;
        for (int i=0;i<iK;++i){
            int iX , iY;
            cin >> iX >> iY;
            iBoard[iY][iX]=1;
        }
        for (int i=0;i<iN;++i){
            for (int j=0;j<iM;++j){
                if (iBoard[i][j]==1 && iVisited[i][j]==0){
                    bfs(i,j);
                }
            }
        }
        cout<<iAns<<'\n';
        iT--;
        for (int i=0;i<iN;++i){
            fill(iBoard[i],iBoard[i]+iM,0);
            fill(iVisited[i],iVisited[i]+iM,0);
        }
    }
    

}