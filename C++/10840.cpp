#include <bits/stdc++.h> 
using namespace std;
int main(){
    int iS, iE;
    int arr[21];
    for (int i=0;i<21;++i){
        arr[i]=i;
    }

    for (int i=0;i<10;++i){
        cin >> iS >> iE;//
        int iDiff = (iE-iS+1)/2;
        for (int i=0;i<iDiff;++i){
            swap(arr[iE-i],arr[iS+i]); 
        }
        // reverse(arr+iS,arr+iE+1);
        //12-15줄을 STL의 reverse를 이용할 수도 있다. -> reverse(arr+iS, arr+iE+1);
    }
    for (int i=1;i<21;++i){
        cout << arr[i]<<" ";
    }
}