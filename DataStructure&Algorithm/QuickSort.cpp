#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> & v, int left, int right);
void change(vector<int> & v, int left, int right);

void QuickSort(vector <int> & v, int left, int right){
    int pivot = partition(v, left, right);
    if (left<pivot-1) QuickSort(v,left,pivot-1);
    if (pivot<right) QuickSort(v,pivot,right);
}

int partition(vector<int>& v, int left, int right){
    int pivot = v[(left+right)/2];
    
    while (left<=right){
        while (v[left] < pivot){ left++; }
        while (pivot<v[right]){ right--; }
        if (left<=right){
            change(v,left,right);
            left ++;
            right--;
        }
    }
    return left;
}

void change(vector<int>&v, int left, int right){
    int tmp = v[left];
    v[left]=v[right];
    v[right]=tmp;
}

void printVector(vector<int> v){
    for (int a : v){
        cout<<a<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {-5,3,2,10,4,-3,9,1};
    printVector(v);
    QuickSort(v,0,v.size()-1);
    printVector(v);
}