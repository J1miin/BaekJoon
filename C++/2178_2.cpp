#include <bits/stdc++.h>
using namespace std;
int iN, iM;
int iDis[101][101];
string sBoard[101];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> iN >> iM;
    for (int i=0;i<iN;++i){
        cin>>sBoard[i];
        fill(iDis[i],iDis[i]+iM,-1);
    }
    queue <pair<int,int>> q;
    q.push({0,0});
    iDis[0][0]=0;
    while (!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for (int i=0;i<4;++i){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx<0 || nx>=iN || ny<0 || ny>=iM) continue;
            if (iDis[nx][ny]!=-1 || sBoard[nx][ny]=='0') continue;
            iDis[nx][ny] = iDis[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }
    cout<<iDis[iN-1][iM-1]+1;
}