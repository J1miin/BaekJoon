#include <bits/stdc++.h>
using namespace std;
int main(){
    int iN, iM, iAns=0;
    cin >> iN >> iM;
    deque<int> dq;
    for(int i=0;i<iN;++i){ dq.push_back(i+1);}
    
    while(iM--){
        int target;
        cin>> target;
        int idx = find(dq.begin(),dq.end(), target) - dq.begin(); //target의 인덱스
        while(dq.front()!=target){
            //왼쪽 거리와 오른쪽 거리를 차로 구한 후 비교한 것
            if(idx<dq.size()-idx){
                dq.push_back(dq.front());
                dq.pop_front();
            }else{
                dq.push_front(dq.back());
                dq.pop_back();
            }
            iAns++;
        }
        dq.pop_front();
    }
    cout<<iAns;
}
