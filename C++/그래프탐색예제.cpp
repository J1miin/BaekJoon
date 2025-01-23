#include <iostream>
#include <vector>
using namespace std;

int iN, iM;
int graph[1001][1001];

bool dfs(int x, int y){
    if (x<=-1 || x>=iN || y<=-1 || y>=iM){
        return false; 
    }

    if (graph[x][y]==0){
        graph[x][y]=1; //방문했음으로 표시하기
        dfs(x-1,y); //좌
        dfs(x,y-1); //상
        dfs(x+1,y); //우
        dfs(x,y+1); //하 
        return true;
    }
    return false;
}

int main(){
    cin>>iN>>iM;
    for (int i=0;i<iN;++i){
        for (int j=0;j<iM;++j){
            scanf("%1d",&graph[i][j]);
        }
    }


    int iResult = 0;
    for (int i=0;i<iN;++i){
        for (int j=0;j<iM;++j){
            if (dfs(i,j)){
                iResult +=1;
            }
        }
    }
    cout<<iResult<<'\n';
    
}
