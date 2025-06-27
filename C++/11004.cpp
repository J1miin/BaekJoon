/*
O(nlogn) 시간 복잡도의 정렬이 필요한 문제
method1. sort 함수를 쓴다. O(nlogn)
method2. quickSort를 이용한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap(vector<int> &arr, int S, int E){
    int tmp = arr[S];
    arr[S]=arr[E];
    arr[E]=tmp;
}
int partition (vector<int> &arr, int S, int E){
    if (S+1 == E){
        if (arr[S]>arr[E]) swap(arr,S,E);
        return E;
    }

    int M = (S+E)/2;
    swap(arr,S,M);
    int pivot = arr[S];
    int i = S+1;
    int j = E;

    while (i<=j){
        while(pivot < arr[j] && j>0) j--;
        while(pivot > arr[i] && i < arr.size()-1) i++;
        if (i<=j) swap(arr,i++, j--);
    }
    arr[S]=arr[j];
    arr[j]=pivot;
    return j;
}
void quickSort(vector<int> &arr, int S, int E, int K){
    int pivot = partition(arr,S,E); //pivot 위치 반환
    if (pivot == K){ return; }
    else if (K < pivot){
        quickSort(arr,S, pivot-1,K);
    }else {
        quickSort(arr,pivot+1,E,K);
    }

}
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
    // method1
    // sort(arr.begin(),arr.end());
    //method2 
    quickSort(arr, 0, iN-1, iK-1);
    cout<<arr[iK-1];
}