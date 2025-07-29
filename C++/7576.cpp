/*익지 않은 토마토는 iDist=-1로 둬서 그 애들만 방문하도록 한다.*/
#include <bits/stdc++.h>
using namespace std;
int iN, iM, iAns=0;
int iDist[1001][1001]={0,};
int iBoard[1001][1001];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
queue <pair<int,int>> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> iM >> iN;
    for (int i=0;i<iN;++i){
        for (int j=0;j<iM;++j){
            cin>>iBoard[i][j];
            if (iBoard[i][j]==1) 
                q.push({i,j}); //익은 토마토나, 없는 곳은 iDist=0으로 자동 초기화되어 있음.
            if (iBoard[i][j]==0)
                iDist[i][j]=-1;
        }
    }
    while (!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for (int i=0;i<4;++i){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if ( nx < 0 || nx>=iN || ny<0 || ny>=iM) continue;
            if (iDist[nx][ny] >=0 ) continue; //iBoard[nx][ny]==-1이게 없어도 iDist로 한번에 해결됨 
            iDist[nx][ny]=iDist[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }
    for (int i =0;i<iN;++i){
        for (int j=0;j<iM;++j){
            if (iDist[i][j]==-1) {
                cout<<-1;
                return 0;
            }
            iAns = max(iAns,iDist[i][j]);
        }
    }
    cout<<iAns;
}