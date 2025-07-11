#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int iN;
    cin>>iN;
    vector<int> inputValue(iN);
    for (int i=0;i<iN;++i){
        cin>>inputValue[i];
    }
    sort(inputValue.begin(),inputValue.end());
    for (auto a: inputValue){
        cout<<a<<endl;
    }
}