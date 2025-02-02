/*
최단경로를 찾을 때는 BFS 
BFS의 자료구조는 큐 또는 연결리스트
그래프 문제에서 좌표로 접근하는 방식도 생각해놓자!
*/
#include <iostream>
#include <queue>

using namespace std;

int iN, iM;
int graph[101][101];
int visited[101][101];
bool check(int y, int x){
    if (y<1 || y>iN || x<1 || x>iM){
        return false;
    }
    if (graph[y][x]==0){
        return false;
    }
    if (visited[y][x]){
        return false;
    }
    return true;
}
int main(){
    int iCnt =0;
    cin>>iN>>iM;
    for (int i=1;i<=iN;++i){
        for (int j=1;j<=iM;++j){
            scanf("%1d",&graph[i][j]);
        }
    }
    //x,y좌표의 큐와 길이 카운트 하는 큐 생성
    queue<int> qy, qx, qCnt;
    qy.push(1), qx.push(1), qCnt.push(1); 
    iCnt=0;

    //y좌표를 기준으로 가는 것이 좋다. 
    while(qy.empty()==false){
        int iCurrentY = qy.front();
        qy.pop();
        int iCurrentX = qx.front();
        qx.pop();
        int iCurrentCnt = qCnt.front();
        qCnt.pop();

        if (visited[iCurrentY][iCurrentX]){
            continue;
        }
        visited[iCurrentY][iCurrentX] = 1;

        if (iCurrentY==iN && iCurrentX==iM){
            iCnt=iCurrentCnt;
            break;
        }
        //상하좌우 탐색
        if (check(iCurrentY-1,iCurrentX)){
            qy.push(iCurrentY-1), qx.push(iCurrentX), qCnt.push(iCurrentCnt+1);
        }
        if (check(iCurrentY+1,iCurrentX)){
            qy.push(iCurrentY+1), qx.push(iCurrentX), qCnt.push(iCurrentCnt+1);
        }
        if (check(iCurrentY,iCurrentX-1)){
            qy.push(iCurrentY), qx.push(iCurrentX-1), qCnt.push(iCurrentCnt+1);
        }
        if (check(iCurrentY,iCurrentX+1)){
            qy.push(iCurrentY), qx.push(iCurrentX+1), qCnt.push(iCurrentCnt+1);
        }
    }
    cout<<iCnt;
    return 0;
}