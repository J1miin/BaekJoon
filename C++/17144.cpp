/*삼성 기출 미세먼지 안녕 */
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int iR,iC,iT, iRes=0;
vector<vector<pair<int,int>>> vMap; //원래 자신의 미세먼지양, 다른 곳에서 확산되어 올 값
int dC[4] = {0,0,-1,1}; //상하좌우
int dR[4] = {-1,1,0,0};
int sC, sR; //청소기 위치
void spread(){
    
    for (int r=0;r<iR;++r){
        for (int c=0;c<iC;++c){
            if (vMap[r][c].first<=0) continue;
            int dustAmount = vMap[r][c].first / 5;
            int spreadCnt = 0; //몇개의 지역까지 확산되는지 카운트 
            for (int i=0;i<4;++i){
                int nC =c + dC[i];
                int nR = r+ dR[i];
                if (nC<0 || nR<0 || nC>=iC || nR>=iR || vMap[nR][nC].first==-1) continue ;
                //4군데에 확산된 값 더해주기
                vMap[nR][nC].second += dustAmount;
                spreadCnt++;
            }
            vMap[r][c].first -= dustAmount * spreadCnt;
        }
    }
        
    
    for (int i=0;i<iR;++i){
        for (int j=0;j<iC;++j){
            vMap[i][j].first+=vMap[i][j].second;
            vMap[i][j].second=0; //다시 0으로 초기화
        }
    }
}

void clean() {
    // 공기청정기 윗부분 (반시계 방향)
    int topR = sR; // 공기청정기 윗부분 행
    int topC = sC; // 공기청정기 윗부분 열
    
    // 공기청정기 아랫부분 (시계 방향)
    int bottomR = sR + 1; // 공기청정기 아랫부분 행
    int bottomC = sC; // 공기청정기 아랫부분 열
    
    // 반시계방향 순환 (공기청정기 윗부분)
    // 방향: 우 -> 상 -> 좌 -> 하
    int tmp = 0; // 이전 위치의 미세먼지를 저장할 임시 변수
    
    // 1단계: 우측으로 이동 (→)
    for (int c = topC + 1; c < iC; c++) {
        int next = vMap[topR][c].first;
        vMap[topR][c].first = tmp;
        tmp = next;
    }
    
    // 2단계: 위로 이동 (↑)
    for (int r = topR - 1; r >= 0; r--) {
        int next = vMap[r][iC-1].first;
        vMap[r][iC-1].first = tmp;
        tmp = next;
    }
    
    // 3단계: 좌측으로 이동 (←)
    for (int c = iC - 2; c >= topC; c--) {
        int next = vMap[0][c].first;
        vMap[0][c].first = tmp;
        tmp = next;
    }
    
    // 4단계: 아래로 이동 (↓)
    for (int r = 1; r < topR; r++) {
        int next = vMap[r][topC].first;
        vMap[r][topC].first = tmp;
        tmp = next;
    }
    
    // 공기청정기 바로 옆은 항상 0
    vMap[topR][topC+1].first = 0;
    
    // 시계방향 순환 (공기청정기 아랫부분)
    // 방향: 우 -> 하 -> 좌 -> 상
    tmp = 0; // 임시 변수 초기화
    
    // 1단계: 우측으로 이동 (→)
    for (int c = bottomC + 1; c < iC; c++) {
        int next = vMap[bottomR][c].first;
        vMap[bottomR][c].first = tmp;
        tmp = next;
    }
    
    // 2단계: 아래로 이동 (↓)
    for (int r = bottomR + 1; r < iR; r++) {
        int next = vMap[r][iC-1].first;
        vMap[r][iC-1].first = tmp;
        tmp = next;
    }
    
    // 3단계: 좌측으로 이동 (←)
    for (int c = iC - 2; c >= bottomC; c--) {
        int next = vMap[iR-1][c].first;
        vMap[iR-1][c].first = tmp;
        tmp = next;
    }
    
    // 4단계: 위로 이동 (↑)
    for (int r = iR - 2; r > bottomR; r--) {
        int next = vMap[r][bottomC].first;
        vMap[r][bottomC].first = tmp;
        tmp = next;
    }
    
    // 공기청정기 바로 옆은 항상 0
    vMap[bottomR][bottomC+1].first = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> iR >> iC >> iT;
    vMap = vector<vector<pair<int, int>>>(iR, vector<pair<int, int>>(iC,{0,0}));
    bool first = false;
    for (int i=0;i<iR;++i){
        for (int j=0;j<iC;++j){
            int tmp;
            cin >> tmp;
            vMap[i][j] = make_pair(tmp,0);
            if (tmp==-1 && first==false){ //여기도 조심할 것!
                sC=j;
                sR=i;
                first = true;
            }
        }
    }
    for (int t=0;t<iT;++t){
        spread();
        clean();
    }
    for (int i=0;i<iR;++i){
        for (int j=0;j<iC;++j){
            if (vMap[i][j].first==-1) continue;
            iRes += vMap[i][j].first;
        }
    }
    
    cout<<iRes;
    return 0;
}