/*
0313목요일 2578번 - 빙고 
11 12 2 24 10
16 1 13 3 25
6 20 5 21 17
19 4 8 14 9
22 15 7 23 18
-------------
5 10 7 16 2
4 22 8 17 13
3 18 1 6 25
12 19 23 14 21
11 24 9 20 15
중복 카운팅을 방지하기 위해서 
가로 빙고 카운트하는 크기 5 1차원배열 
세로    .. 카운트하는 크기 5 1차원 배열
대각선  ... 크기 2 1차원 배열 만들어서 
iAns를 다시 구해줘야겠다.
*/
#include <iostream>
#include <unordered_map>
using namespace std;
#define ROW 5
#define COL 5

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    unordered_map<int,int> hBingoMap;
    int iBingTrack[25]={0,};
    int iAns = 0, iRes=0;
    int iN, iIdx, iVal ;
    int iRowArr[6]={0,},iColArr[6]={0,}, iDiagonalArr[2]={0,};
    //빙고채우기
    for (int j=0;j<25;++j){
        cin>>iVal;
        hBingoMap[iVal]=j; //0-4, 5-9, 10-14, 15-19, 20-24  {5,1} - 5라는 값이 1번 칸에 있음 
    }
    //사회자가 부른거 체크하기
    int i=0;
    for (i=0;i<25;++i){
        cin >> iN;
        iIdx = hBingoMap[iN];//15/5=3...0
        iBingTrack[iIdx]=1; 
        ///13일 때 +1, 3일 때 +1 , 25일 때 +1 
        if(i>=4){        
            int iCal = 0;
            for (int n=1;n<6;++n){//n=1,2
                //가로
                iCal= iBingTrack[5*n-5] + iBingTrack[5*n-4] + iBingTrack[5*n-3] + iBingTrack[5*n-2] + iBingTrack[5*n-1];
                if (iCal==5 ){
                    iRowArr[n]++; 
                    if (iRowArr[n]==1)iAns++;  
                }
                //세로 
                iCal= iBingTrack[n-1] + iBingTrack[n+4]+ iBingTrack[n+9]+ iBingTrack[n+14]+ iBingTrack[n+19];
                if (iCal==5){
                    iColArr[n]++;
                    if (iColArr[n]==1) iAns++;
                }  
            }
            //대각선
            iCal =  iBingTrack[0]+iBingTrack[6]+iBingTrack[12]+iBingTrack[18]+iBingTrack[24]; //우하향            
            if (iCal==5){
                iDiagonalArr[0]++;
                if(iDiagonalArr[0]==1){
                    iAns++;
                }
            }

            iCal =  iBingTrack[4]+iBingTrack[8]+iBingTrack[12]+iBingTrack[16]+iBingTrack[20]; //좌하향
            if (iCal==5){
                iDiagonalArr[1]++;
                if(iDiagonalArr[1]==1) iAns++;            
            }    
        }
        if (iAns>=3 && iRes==0){
            //이미 1빙고가 있는 상태에서 하나의 숫자로 갑자기 iAns가 동시에 3개가 추가될 수 있는 경우를 고려하려면 iAns >=3 이어야 한다.
            iRes=i+1;
        }
    }
    cout<<iRes<<endl;
    return 0;
}
