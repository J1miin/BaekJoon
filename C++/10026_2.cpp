/*적록색약 : R=G 와 B 
일반인 : R, G, B 각각 
출력 - 적록색약 /n 일반인
*/
#include <bits/stdc++.h>
using namespace std;
int iN, iAns;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
string sBoard[101];
int iVisited[101][101];
queue<pair<int,int>> q;

void bfs(int x, int y, int t){
    iAns++;
    q.push({x,y});
    iVisited[x][y]=1;
    while (!q.empty()){
        pair <int, int> cur = q.front(); q.pop();
        char c = sBoard[cur.first][cur.second];
        for (int i=0;i<4;++i){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if (nx>=iN || ny>=iN || nx <0 || ny<0) continue;
            if (t==0){
                if (sBoard[nx][ny]!=c || iVisited[nx][ny]!=0) continue;
                q.push({nx,ny});
                iVisited[nx][ny]=1;
            }else {
                //적록색약
                if(iVisited[nx][ny]!=0){
                    continue;
                }else{
                    if (c!=sBoard[nx][ny]){
                        if (c=='B' || sBoard[nx][ny]=='B') continue;
                    }
                    q.push({nx,ny});
                    iVisited[nx][ny]=1;    
                }
            }
            
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> iN;
    for (int i=0;i<iN;++i) {
        cin>>sBoard[i];
    }
    for (int t=0;t<2;++t){
        iAns=0;
        for (int i=0;i<iN;++i){
            for (int j=0;j<iN;++j){
                if(iVisited[i][j]==0){
                    //일반인부터
                    bfs(i,j,t);
                }
            }
        }
        cout<<iAns<<' ';
        for (int i=0;i<iN;++i){
            fill(iVisited[i],iVisited[i]+iN,0);
        }
    }
}