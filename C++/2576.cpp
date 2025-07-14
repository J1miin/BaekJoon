/*
solution에서 배운 점
& 연산자를 이용하여 (입력값 & 1) 비트 연산을 통해서 홀 짝을 구분할 수 있다.
입력값 & 1해서 맨 으론쯕 비트값이 1이라면 홀수, 0이라면 짝수가 된다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int iMin = INT_MAX;
    int iTmp, iSum =0;
    bool check = false;
    for (int i=0;i<7;++i){
        cin>>iTmp;
            check = true;
            iSum+=iTmp;
            iMin = min(iMin,iTmp);
        }
    }
    if (check == false){
        cout <<-1;
    }else {
        cout<<iSum<<'\n'<<iMin;
    }   
}