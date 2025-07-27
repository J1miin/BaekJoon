#include <bits/stdc++.h>
using namespace std;
int main(){
    int iArr[9];
    int iAns[7];
    //키 입력 받기
    for (int i=0;i<9;++i){
        cin>>iArr[i];
    }
    for (int i=0;i<8;++i){
        int iSum = 0;
        for (int j=i+1;j<9;++j){
            for (int a=0,b=0;a<9;++a){
                if (a!=i && a!=j){
                    iAns[b++]=iArr[a];
                }
            }
            for (int k=0; k<7;++k){
                iSum+=iAns[k];
            }
            if (iSum==100) break;
        }
        if (iSum==100) break;
    }
    sort(iAns,iAns+7);
    for (auto a: iAns){
        cout<<a<<"\n";
    }
}