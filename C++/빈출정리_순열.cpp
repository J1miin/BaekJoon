#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v{1,2,3};
    //알고리즘 헤더의 next_permutation쓰려면 오름차순 정렬 필요
    sort(v.begin(),v.end());
    
    vector<vector<int>> permutations; //순열결과 저장할 떄
    // 순열 생성 및 저장
    do {
        // 현재 순열 저장 
        permutations.push_back(v);
    } while (next_permutation(v.begin(), v.end()));
    // 하나씩 확인할 때 

    do{
        for (auto i= v.begin();i!=v.end();++i){
            cout<<*i<<" ";
        }
        cout<<"\n";
    }while(next_permutation(v.begin(),v.end()));
}

