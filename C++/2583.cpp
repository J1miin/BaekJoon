#include <iostream>
#include <queue> 
#include <vector> 
#include <algorithm>
using namespace std; 

int iMap[100][100] = {0,};
bool visited[100][100] = {false,};
int iRes = 0;
int dC[4] = {-1,1,0,0} ;
int dR[4] = {0,0,-1,1} ;
int iM, iN, iK;
vector<int> vAnswer;

void checkRectangle(int iLc, int iLr, int iRc, int iRr){
    for (int i=iLr;i<iRr;++i){
        for (int j=iLc; j<iRc;++j){
            iMap[i][j]=1;
        }
    }
}

void BFS(int iR, int iC){
    queue<pair<int,int>> q;
    q.push({iR,iC});
    visited[iR][iC]=true;
    iRes++;
    while(!q.empty()){
        int cR = q.front().first;
        int cC = q.front().second;
        q.pop();
        for (int i=0;i<4;++i){
            int nR = cR + dR[i];
            int nC = cC + dC[i];
            if (nR<0 || nR >=iM || nC < 0 || nC >= iN ) continue;
            if (iMap[nR][nC]==1 || visited[nR][nC]==true) continue;
            visited[nR][nC]=true;
            iRes++;
            q.push({nR,nC});
        }
    }
}
int main(){    
    int iLeftCol, iLeftRow, iRightCol, iRightRow;
    cin >> iM >> iN >> iK;
    for (int i=0;i<iK;++i){
        cin>> iLeftCol >> iLeftRow >> iRightCol >> iRightRow;
        checkRectangle(iLeftCol,iLeftRow,iRightCol,iRightRow);
    }

    for (int i=0;i<iM;++i){
        for (int j=0;j<iN;++j){
            if (iMap[i][j]==1 || visited[i][j]== true) continue;
            BFS(i,j);
            vAnswer.push_back(iRes);
            iRes=0;
        }
    }

    sort(vAnswer.begin(),vAnswer.end());
    cout << vAnswer.size() << '\n';
    for (int answer : vAnswer){
        cout << answer <<" " ;
    }

}