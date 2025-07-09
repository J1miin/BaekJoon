#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.rbegin(), citations.rend());
    for (int i=citations.size()-1;0<=i;--i){
        cout<<citations[i]<<" "<<i+1<<endl;
        if (citations[i] >= i+1) return i+1;
    }
    return 0;
}

int main(){
    solution({0, 0, 0,0,0});
}
