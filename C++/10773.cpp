#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    stack<int> st;
    int iK, iAns = 0, iCnt=0;
    cin>>iK;
    for (int i=0;i<iK;++i){
        int tmp;
        cin>>tmp;
        if(tmp==0){
            st.pop();
        }else{
            st.push(tmp);
        }
    }
    while (!st.empty()){
        iAns+= st.top();
        st.pop();
    }
   
    cout<<iAns;
}