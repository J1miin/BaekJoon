#include <bits/stdc++.h>
using namespace std;
int iR, iC, iAns = 10001;
int iFire[1001][1001];
int iJ[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
string sBoard[1001];
queue<pair<int,int>> jQ;
queue<pair<int,int>> fQ;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>iR>>iC;
    for (int i=0;i<iR;++i){
        cin>>sBoard[i];
    }
    for (int i=0;i<iR;++i){
        for (int j=0;j<iC;++j){
            iFire[i][j]=-1;
            iJ[i][j]=-1;
            if (sBoard[i][j]=='J') 
            {   jQ.push({i,j}); 
                iJ[i][j]=0;
            }
            if (sBoard[i][j]=='F') {
                fQ.push({i,j}); 
                iFire[i][j]=0;
            }
        }
    }
    //불부터
    while (!fQ.empty()){
        pair<int,int> cur = fQ.front(); fQ.pop();   
        for (int i=0;i<4;++i){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if (nx<0 || nx>=iR || ny <0 || ny>=iC) continue;
            if (iFire[nx][ny]>=0 || sBoard[nx][ny]=='#') continue; 
            iFire[nx][ny]=iFire[cur.first][cur.second]+1;
            fQ.push({nx,ny});
        }
    }
    while (!jQ.empty()){
        pair<int,int> cur = jQ.front(); jQ.pop();   
        for (int i=0;i<4;++i){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if (nx<0 || nx>=iR || ny <0 || ny>=iC) {
                //여기 nx,ny는 지훈이가 BFS에 넣은 값으로 벽은 포함될 수 없다. 그래서 바로 return 할 수 있는 것
                cout<< iJ[cur.first][cur.second]+1;
                return 0;
            }
            if (iJ[nx][ny]>=0 || sBoard[nx][ny]== '#') continue;
            if (iFire[nx][ny]!=-1 && iJ[cur.first][cur.second]+1>=iFire[nx][ny]) continue;
            // 여기서 iFire[nx][ny]!=-1이 없으면 불이 아예 안 퍼진 칸도 "가지 마세요"가 되기 떄문에 문제가 된다.
            iJ[nx][ny]=iJ[cur.first][cur.second]+1;
            jQ.push({nx,ny});
        }
    }
    cout<<"IMPOSSIBLE";
}  