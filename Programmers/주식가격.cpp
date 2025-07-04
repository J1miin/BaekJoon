#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    bool check = false;
    int iSize = prices.size();
    int j;
    for (int i=0;i<iSize;++i){
        int cnt = 0;
        int tmp = prices[i];
        check = false;

        for (j=i+1;j<iSize;++j){
            if (tmp > prices[j]){ //가격이 떨어졌을 때
                answer.push_back(j-i);
                check = true;
                break;
            }
        }
        if (check==false){ //끝까지 가격이 안떨어졌을 때 (앞에 반복문에서 j가 하나더 커지고 나와서 -1 해준다)
            answer.push_back(j-i-1);
        }
    }
    return answer;
}

//디버깅용
// vector<int> solution(vector<int> prices) {
//     vector<int> answer;
//     bool check = false;
//     int iSize = prices.size();
//     int j;
//     for (int i=0;i<iSize;++i){
//         cout<<"------i "<<i<<endl;
//         int cnt = 0;
//         int tmp = prices[i];
//         check = false;
//         cout<<"tmp "<<tmp<<endl;
//         for (j=i+1;j<iSize;++j){
//             cout<<"j "<<j;
//             cout<<" prices[j] "<<prices[j]<<endl;
//             if (tmp > prices[j]){ //가격이 떨어졌을 떄
//                 answer.push_back(j-i);
//                 check = true;
//                 break;
//             }
//         }
//         if (check==false){
//             answer.push_back(j-i-1);
//         }
//         cout<<"answer debug "<<answer[i]<<endl;
//     }
//     return answer;
// }

int main(){
    vector<int> answer = solution({1, 2, 3, 2, 3});
    for(auto a: answer){
        cout<< a<<" ";
    }
}