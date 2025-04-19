#include <iostream>
using namespace std;
int iN, iM, iCol, iRow, iDir;
int iMap[51][51] ; 
int iRes = 0;
int dCol[4] = {1,-1,0,0};  //동 서 북 남 
int dRow[4] = {0,0,1,-1}; 


int main(){
    cin >> iN >> iM;
    cin >> iCol >> iRow >> iDir; 

    for (int i=0;i<iN;++i){
        for (int j=0;j<iM;++j){
            cin>>iMap[i][j];
        }
    }

    while (true){
        int iTrack4 = 0;
        //현재 위치가 청소가 안되어 있으면 청소하기
        if (iMap[iRow][iCol]==0){
            iRes++;
            iMap[iRow][iCol]=2;
        }
        //주변 4방향의 청소 여부 확인하기
        for (int i=0;i<4;++i){
            if( iRow+dRow[i]>=0 && iRow+dRow[i]<iN && iCol+dCol[i]>=0 && iCol+dCol[i] <iM && iMap[iRow+dRow[i]][iCol+dCol[i]] == 1 ){
                iTrack4 ++;
            }
        }
        if (iTrack4 == 4){ //전부 벽
            cout << iRes;
            return 0 ;
        }else { //0인 공간이 하나 이상 
            //90도 돌리기
            if (iDir == 0){ //북
                iDir = 1;
                if (iMap[iRow+dRow[2]][iCol+dCol[2]]==0){
                    iRow+=dRow[2];
                    iCol+=dCol[2];
                    iMap[iRow][iCol]=2; //청소했다는 의미
                    iRes++;
                }else{
                    if (iMap[iRow+dRow[3]][iCol+dCol[3]]==0){
                        iRow+=dRow[3];
                        iCol+=dCol[3];
                        iMap[iRow][iCol]=2; //청소했다는 의미
                        iRes++;
                    }
                }
            }else if (iDir == 1){ //동
                iDir = 3;
                if (iMap[iRow+dRow[0]][iCol+dCol[0]]==0){
                    iRow+=dRow[0];
                    iCol+=dCol[0];
                    iMap[iRow][iCol]=2; //청소했다는 의미
                    iRes++;
                }else{
                    if (iMap[iRow+dRow[1]][iCol+dCol[1]]==0){
                        iRow+=dRow[1];
                        iCol+=dCol[1];
                        iMap[iRow][iCol]=2; //청소했다는 의미
                        iRes++;
                    }
                }
            }else if (iDir == 2) { //서
                iDir = 0;
                if (iMap[iRow+dRow[1]][iCol+dCol[1]]==0){
                    iRow+=dRow[1];
                    iCol+=dCol[1];
                    iMap[iRow][iCol]=2; //청소했다는 의미
                    iRes++;
                }else{
                    if (iMap[iRow+dRow[0]][iCol+dCol[0]]==0){
                        iRow+=dRow[0];
                        iCol+=dCol[0];
                        iMap[iRow][iCol]=2; //청소했다는 의미
                        iRes++;
                    }
                }
            }else if (iDir == 3){ //남 
                iDir = 2;
                if (iMap[iRow+dRow[3]][iCol+dCol[3]]==0){
                    iRow+=dRow[3];
                    iCol+=dCol[3];
                    iMap[iRow][iCol]=2; //청소했다는 의미
                    iRes++;
                }else{
                    if (iMap[iRow+dRow[2]][iCol+dCol[2]]==0){
                        iRow+=dRow[2];
                        iCol+=dCol[2];
                        iMap[iRow][iCol]=2; //청소했다는 의미
                        iRes++;
                    }
                }
            }
        }
        
    }

    cout << iRes;
    return 0;
}