#include <iostream>
using namespace std;
int iN, iM, iCol, iRow, iDir;
int iMap[51][51] ; 
int iRes = 0;
int dCol[4] = {0, 1, 0, -1}; //북 동 남 서
int dRow[4] = {-1, 0, 1, 0};


int main(){
    cin >> iN >> iM;
    cin >> iRow >> iCol >> iDir; 

    for (int i=0;i<iN;++i){
        for (int j=0;j<iM;++j){
            cin>>iMap[i][j];
        }
    }

    while (true){
        //현재 위치가 청소가 안되어 있으면 청소하기
        if (iMap[iRow][iCol]==0){
            iRes++;
            iMap[iRow][iCol]=2;
        }
        //주변 4방향의 청소 여부 확인하기
        bool isCleand = false; 
        for (int i=0;i<4;++i){
            iDir = (iDir + 3 ) %4; //반시계
            int iNewRow = iRow + dRow[iDir];
            int iNewCol = iCol + dCol[iDir];
            if( iNewRow>=0 && iNewRow<iN &&  iNewCol>=0 &&  iNewCol <iM && iMap[iNewRow][iNewCol] == 0 ){
                iRow=iNewRow;
                iCol=iNewCol;
                isCleand=true;
                break;
            }
        }
        if (!isCleand){
            int iBackDir = (iDir+2)%4;
            if (iMap[iRow+dRow[iBackDir]][iCol+dCol[iBackDir]]==1){
                break;
            }
            iRow += dRow[iBackDir];
            iCol += dCol[iBackDir];
        }
    }

    cout << iRes;
    return 0;
}