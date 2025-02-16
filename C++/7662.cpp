/*
최대힙, 최소힙을 이용해볼까?  >> priority queue를 이용하자
pair<type1, type2> p;
p.first와 p.second로 각 요소에 접근함
make_pair(value1, value2)를 사용하여 pair를 생성할 수 있습니다23
간단한 데이터 구조를 표현할 때는 주로 구조체를 사용한다고 한다.
*/
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

priority_queue<int> maxHeapQ ;
priority_queue<int,vector<int>,greater<int>> minHeapQ ;
map<int,int> mTracking;
int iTotal,iInputNum; //몇 번 입력 받을지 & 한 횟수에서 몇 개 숫자 넣을지
string sInput;
int iValue, delTarget;

void reset(){
    //초기화
    while (!maxHeapQ.empty()) {
        maxHeapQ.pop();
    }
    while (!minHeapQ.empty()) {
        minHeapQ.pop();
    }
    mTracking.clear();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); //cin/cout 빠르게 실행
    cin>>iTotal;

    for (int j=0;j<iTotal;++j){
        cin>>iInputNum;
        reset();
        for (int i=0;i<iInputNum;++i){
            cin>>sInput>>iValue;
    
            if (sInput =="I"){
                maxHeapQ.push(iValue);
                minHeapQ.push(iValue);
                mTracking[iValue]++;
    
            }else if (sInput=="D"){
                if (!maxHeapQ.empty()){
                    if (iValue==1){
                        while(!maxHeapQ.empty()&&mTracking[maxHeapQ.top()]==0){
                            maxHeapQ.pop();
                        }
                        if (!maxHeapQ.empty()){
                            int maxVal = maxHeapQ.top();
                            maxHeapQ.pop();
                            mTracking[maxVal]--;
                        }
                    }else if (iValue == -1) {
                        while(!minHeapQ.empty()&& mTracking[minHeapQ.top()]==0){
                            minHeapQ.pop();
                        }
                        if (!minHeapQ.empty()){
                            int minVal = minHeapQ.top();
                            minHeapQ.pop();
                            mTracking[minVal]--;
                        }
                    }
                }
            }
        }
        while (!maxHeapQ.empty() && mTracking[maxHeapQ.top()] == 0) {
            maxHeapQ.pop();
        }
        while (!minHeapQ.empty() && mTracking[minHeapQ.top()] == 0) {
            minHeapQ.pop();
        }
    
        if (maxHeapQ.empty()){
            cout<<"EMPTY"<<endl;
        }else {
            cout<<maxHeapQ.top()<<" "<<minHeapQ.top()<<endl;
        }
    }
}