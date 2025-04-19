#include <iostream>
#include <vector>
using namespace std;

int iL, iN, iQ;
int iMap[41][41]; 
struct playerLoc {
    pair<int, int> pos1;
    pair<int, int> pos2;
};
vector<playerLoc> vPlayerData;

int iPlayerMap[41][41];

int dRow[4]={-1,0,1,0};
int dCol[4]={0,1,0,-1}; //상우하좌

vector<pair<int,int>> vPlayerK;

vector<pair<int,int>> vOrder;

bool dfs(int i, int d){
    int cRow1 = vPlayerData[i].pos1.first;
    int cCol1 = vPlayerData[i].pos1.second;
    int cRow2 = vPlayerData[i].pos2.first;
    int cCol2 = vPlayerData[i].pos2.second;

    int nRow1 = cRow1 + dRow[d];
    int nCol1 = cCol1 + dCol[d];
    int nRow2 = cRow2 + dRow[d];
    int nCol2 = cCol2 + dCol[d];
    
    bool isWall = false;

    if (nRow1>=0 && nRow2>=0 && nCol1<iL && nCol2<iL) {
        if (d==2){
            if (iPlayerMap[nRow2][nCol2] != 0){
                 //옆에 병사 확인
                i = iPlayerMap[nRow2][nCol2];   
                dfs(i,d);
            }else if (iMap[nRow2][nCol2]==2){
                //벽인 경우
                isWall = true;
                return isWall;
            }
        }else if (d==0){
            if (iPlayerMap[nRow1][nCol1]!= 0){
                i = iPlayerMap[nRow1][nCol1];   
                dfs(i,d);
            }else if (iMap[nRow1][nCol1]==2){
                isWall=true;
                return isWall;
            }
        }else{
            if (iPlayerMap[nRow1][nCol1]!= 0 || iPlayerMap[nRow2][nCol2] != 0){
                if (iMap[nRow1][nCol1]==2 || iMap[nRow2][nCol2]==2){
                    isWall=true;
                    return isWall; 
                }else {
                    vPlayerK[i].second = vPlayerK[i].second + iMap[nRow1][nCol1] + iMap[nRow2][nCol2];
                    return isWall;
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int iRes = 0;
    cin >>iL>>iN>>iQ;
    vPlayerData.resize(iN); 
    vPlayerK.resize(iN, {0, 0}); // player 체력 저장
    vOrder.resize(iQ); // 명령 입력 받기 위한 벡터

    for (int i=0;i<iL;++i){
        for (int j=0;j<iL;++j){
            cin>>iMap[i][j];
        }
    }

    for (int i=0;i<iN;++i){
        int ir,ic,ih,iw,ik;
        cin >> ir >> ic >> ih >> iw >> ik;
        ir--; ic--;
        iPlayerMap[ir][ic]=i+1;
        iPlayerMap[ir+ih-1][ic+iw-1]=i+1; //인덱스 맞추기 1번째 병사 
        
        vPlayerData[i].pos1 = {ir,ic};
        vPlayerData[i].pos2 = {ir+ih-1, ic+iw-1};
        
        vPlayerK[i].first=ik;
    }

    for (int q=0;q<iQ;++q){
        int i, d;
        cin>>i>>d;
        vOrder[q] = {i-1,d};
    }

    //명령에 따라 밀기 시작
    for (int q=0;q<iQ;++q){
        int d = vOrder[q].second ; //어느 방향인지
        int i = vOrder[q].first ; //몇 번째 병사인지 - ex 1번째 병사
        bool dfsRes = dfs(i,d);
        if (dfsRes==false){
            for (int p=0;p<iN;++p){
                vPlayerK.first-=vPlayerK.second;
                if (vPlayerK.first<=0){
                    vPlayerK.first=0;
                    vPlayerK.second=0;
                }else {
                    iRes += vPlayerK.second;
                    vPlayerK.second=0;
                }
            }
        }else {
            for (int p=0;p<iN;++p){
                vPlayerK.second=0;
            }
        }
    }
    
    
    // 최종 결과 출력 (각 병사의 체력 출력)
    cout<<iRes;
    
    return 0;
}   