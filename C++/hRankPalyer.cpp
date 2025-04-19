#include <iostream>

using namespace std;

int main(){
    int n=2;
    int m=6;  
    vector<int> vTower(n,m); //n개의 m으로 초기화 
    vector <int> vMfactor ; //m의 약수 (자기 자신 제외)
    int iTrack = 1; //1플레이어는 1,3,5,7 홀수, 2플레이어는 짝수
    for (int i=0;i<m;++i){
        if (m%i==0 && i!=0){
            vMfactor.push_back(i);
        }
    }
    //n이 1일 때부터 해보자~
    for (int j=0;j<n;++j){
        for (int i=0;i<vMfactor.size();++i){
            if (vTower[j]==1 && j+1==n){
                if(iTrack%2==0 ){
                    cout<< 1<<endl;
                }else {
                    cout<< 2<<endl;
                }
            }
            if (vMfactor[i]<m){
                vTower[j]=vMfactor[i]; 
            }
            iTrack++;  
        }
    }
    return 1;
}

/*
vector<int> vTower(n,m); 
    vector <int> vMfactor ; 
    int iTrack = 1; 
    int iTowerTrack = 0;
    for (int i=0;i<m;++i){
        if (i!=0 && m%i==0){
            vMfactor.push_back(i);
        }
    }
    while(true){
        int i = 0;
        while (iTowerTrack<n){
            if(i<vMfactor.size() && vMfactor[i]<vTower[iTowerTrack]){
                vTower[iTowerTrack]=vMfactor[i];
                iTrack++;
                ++i;
                break;
            }else{
                iTowerTrack++;
            }
        }
        for (int j=0;j<n;++j){
            if( vTower[j]==1 && j==n-1){
                if (iTrack%2==0){
                    return 1;
                }else{
                    return 2;
                }
            }
        }    
    }
    return 1;
    */

/*허탈하다.. 수학적 규칙을 찾는거구나..........하하...
좀더 예시를 보고 분석해보자... 시뮬레이션 문제...
*/