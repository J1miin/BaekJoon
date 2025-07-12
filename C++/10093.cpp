/*예외처리 & int 가 32비트라서 9자리 이상 숫자 다룰 떄는 long long 생각하기*/
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int main(){
//     ios::sync_with_stdio(0), cin.tie(0);
//     long long lA, lB, lStart, lEnd, lCnt;
//     cin >> lA >> lB;
//     if (lA>lB){
//         lStart = lB; 
//         lEnd = lA;
//     }else {
//         lStart = lA;
//         lEnd = lB;
//     }
//     lCnt = lEnd-lStart;
//     if (lCnt ==0 || lCnt ==1 ){
//         lCnt = 0;
//     }else {
//         lCnt--;
//     }
//     cout << lCnt<<'\n';
//     while (lCnt > 0){
//         lStart++;
//         cout << lStart << " "; 
//         lCnt--;
//     }
// }

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    long long lA, lB, lStart, lEnd, lCnt;
    cin >> lA >> lB;
    if (lA > lB){
        swap(lB,lA);
    }
    if (lA==lB || lA-lB==1){
        cout<<0;
    }else {
        lCnt=lB-lA-1;
        cout<<lCnt<<"\n";
        for (long long i =lA+1 ; i<lB ;++i){
            cout << i<<" ";
        }
    }
}