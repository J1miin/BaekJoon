/*
O(nlogn) 시간 복잡도의 정렬이 필요한 문제
method1. sort 함수를 쓴다. O(nlogn)
method2. quickSort를 이용한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int iN, iK;
    cin>>iN>>iK;
    vector<int> arr(iN,0);
    for (int i=0;i<iN;++i){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    cout<<arr[iK-1];
    
}