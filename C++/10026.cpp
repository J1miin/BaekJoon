#include <iostream>
#include <queue>
#include <string>
using namespace std;

char cMap[100][100];
bool visited[100][100]={false,};
bool visited2[100][100]={false,};
int iAns1=0, iAns2=0;
int iN; 
int dRow[4] = {-1,1,0,0};
int dCol[4] = {0,0,-1,1};

//일반인 버전
void BFS(int cR, int cC){
    queue<pair<int,int>> q ;
    q.push({cR,cC});
    visited[cR][cC]=true;
    while (!q.empty()){
        int nowR = q.front().first;
        int nowC = q.front().second;
        q.pop();
        for (int i=0;i<4;++i){
            int nR = nowR + dRow[i];
            int nC = nowC + dCol[i];
            if (nR<0 || nR>=iN || nC <0 || nC >= iN) continue;
            if (visited[nR][nC]==true) continue;
            if (cMap[nR][nC]!=cMap[nowR][nowC]) continue;
            visited[nR][nC]=true;
            q.push({nR,nC});
        }
    }
}

void BFS2(int cR, int cC){
    queue<pair<int,int>> q ;
    q.push({cR,cC});
    visited2[cR][cC]=true;
    while (!q.empty()){
        int nowR = q.front().first;
        int nowC = q.front().second;
        q.pop();
        for (int i=0;i<4;++i){
            int nR = nowR + dRow[i];
            int nC = nowC + dCol[i];
            if (nR<0 || nR>=iN || nC <0 || nC >= iN) continue;
            if (visited2[nR][nC]==true) continue;
            if (cMap[nR][nC]!=cMap[nowR][nowC]) {
                if (!((cMap[nR][nC]=='R' && cMap[nowR][nowC]=='G') || (cMap[nR][nC]=='G' && cMap[nowR][nowC]=='R'))) continue;
            }
            visited2[nR][nC]=true;
            q.push({nR,nC});
        }
    }
}


int main(){
    cin >> iN;
    for (int i=0;i<iN;++i){
        for (int j=0;j<iN;++j){
            cin >> cMap[i][j];
        }
    }
    for (int i=0;i<iN;++i){
        for (int j=0;j<iN;++j){
            if (visited[i][j]==false) {
                iAns1++;
                BFS(i,j);
            }
        }
    }
    for (int i=0;i<iN;++i){
        for (int j=0;j<iN;++j){
            if (visited2[i][j]==false) {
                iAns2++;
                BFS2(i,j);
            }
        }
    }
    cout << iAns1 <<" "<<iAns2;
    return 0;
}