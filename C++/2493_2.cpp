/*
이전 요소들 중엥서 특정 조건을 만족하는 가장 가까운 요소 찾는 경우
이전 상태가 필요하지만, 전부 필요한 건 아니고, 조건 만족하지 않는 경우는 무시해도 될 때 
-> 스택을 쓸 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    stack<pair<int,int>> st; //높이와 위치 인덱스
    st.push({100000001,0});
    int iN;
    cin >> iN;
    for (int i=0;i<iN;++i){
        int iHeight;
        cin>>iHeight;
        while (st.top().first<iHeight){
            st.pop();
        }
        cout<<st.top().second<<' ';
        st.push({iHeight,i+1});
    }
}