/*
아군 = 흰색 W
적군 = 파란색 B
n명이 뭉쳐있으면 n^2의 파워 있음
누가 승리할 것인가를 찾는 문제
*대각선은 뭉쳐있다고 보지 않는다.
-> solution
병사의 배치를 그래프로 표현 -> 아군은 0, 적군은 1로 표시하고
뭉쳐있는 아군의 수를 각각 카운트해서 승리여부 판단
연결요소와 다른 점은 연결요소는 연결된 그룹의 개수만 알면 되지만,
여기서는 연결된 그룹을 구성하는 인원의 수가 필요함
일단 연결된 사람을 다 방문해서 찾아야하므로 dfs 사용하여 시작할 수 있음 
 */

#include <iostream>
using namespace std;

int iN, iM;
char graph[101][101];

void dfs(int x, int y, int & iCntN, char target){
    if (x<=-1 || x>=iM || y<=-1 || y>=iN){
        //x랑 y 행렬 헷갈려서 이 조건 때문에 계속 틀렸다... 바부...
        return ;
    }

    if (graph[x][y]==target){
        graph[x][y]='V'; //방문했다고 표시
        iCntN +=1;
        dfs(x-1,y,iCntN,target); //상
        dfs(x+1,y,iCntN, target); //하
        dfs(x,y+1, iCntN, target); //우
        dfs(x,y-1, iCntN,target); //좌
        return ;
    }
    return ;
}


int main (){
    int iBlueCnt = 0;
    int iWhiteCnt = 0;
    int iCnt;
    cin>>iN >> iM;
    
    for (int i=0;i<iM;++i){
        for (int j=0;j<iN;++j){
            scanf("%1s",&graph[i][j]);
        }
    }

    for (int i=0;i<iM;++i){
        for (int j=0;j<iN;++j){
            if (graph[i][j]=='B'){
                iCnt = 0;
                dfs(i,j,iCnt,'B');
                //dfs한 번 돌 때마다 하나의 그룹(연결요소)의 크기를 iCnt로 알아올 수 있음 
                //따라서 iCnt는 dfs로 한 개의 그룹내 구성원을 계산할 애라서 초기화 해줘야 한다.
                iBlueCnt += iCnt*iCnt;
            }
            if (graph[i][j]=='W'){
                iCnt = 0;
                dfs(i,j,iCnt,'W');
                iWhiteCnt+=iCnt*iCnt;
            }
        }
    }
    cout<< iWhiteCnt <<" "<<iBlueCnt;
}