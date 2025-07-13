/*
등 - 1, 배 - 0
도(배 한 개, 등 세 개) = 3 a
개(배 두 개, 등 두 개) = 2 b
걸(배 세 개, 등 한 개) = 1 c
윷(배 네 개) = 0 d
모(등 네 개) = 4 e
배열을 초기화하지 않으면 쓰레기 값이 있을 수 있다!
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int iSum[3] ={0,};
    int iInput;
    for (int i=0;i<3;++i){
        for (int j=0;j<4;++j){
            cin>>iInput;
            iSum[i]+=iInput;
        }
    }
    for (int i=0;i<3;++i){
        int a = iSum[i];
        if (a == 4){ cout << "E"; }
        else if (a== 3){cout <<"A"; }
        else if (a== 2){cout <<"B"; }
        else if (a== 1){cout <<"C"; }
        else {cout<<"D";}
        cout<<"\n";
    }
}