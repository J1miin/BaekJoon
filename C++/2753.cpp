#include <bits/stdc++.h>
using namespace std;
int main(){
    int iInput;
    cin>>iInput;
    if ((iInput % 4 ==0 && iInput%100!=0) || iInput % 400 ==0){
        cout<<1;
    }else {
        cout<<0;
    }
}