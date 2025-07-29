#include <bits/stdc++.h>
using namespace std;
int iM, iN, iH; //열 행 높이
int iBoard[101][101][101];
int iDist[101][101][101];
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1}; //상하좌우위아래
queue<tuple<int,int,int>> q;
int iAns =0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> iM >> iN >> iH;
    for (int i=0;i<iH;++i){
        for (int j=0;j<iN;++j){
            for (int k=0;k<iM;++k){
                cin>>iBoard[i][j][k];
                if (iBoard[i][j][k] == 0 ) iDist[i][j][k]=-1;
                if (iBoard[i][j][k]==1) q.push({i,j,k});
            }
        }
    }

    while (!q.empty()){
        tuple<int,int,int> cur = q.front(); q.pop();
        for (int i=0;i<6;++i){
            int nz = get<0>(cur) + dz[i];
            int nx = get<1>(cur) + dx[i];
            int ny = get<2>(cur) + dy[i];
            if (nz <0 || nz>=iH || nx <0 || nx >= iN || ny<0 || ny >= iM) continue;
            if (iDist[nz][nx][ny]>=0) continue;
            iDist[nz][nx][ny] = iDist[get<0>(cur)][get<1>(cur)][get<2>(cur)] +1;
            q.push({nz,nx,ny});
        }
    }

    for (int i=0;i<iH;++i){
        for (int j=0;j<iN;++j){
            for (int k=0;k<iM;++k){
                if (iDist[i][j][k]== -1 ) {
                    cout << -1 ;
                    return 0;
                }
                iAns = max(iAns,iDist[i][j][k]);
            }
        }
    }
    cout<<iAns;
}