#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    stack<pair<char,int>> st;
    string sInput;
    cin>>sInput;
    for (char c: sInput){
        if (c=='(') st.push(c,0);
        else if (c='[') st.push(c);
        else if (c=')'){
            if (!st.empty() && st.top()=='('){
                st.pop();
                st.push('X');
            }
        }else {
            if (!st.empty() && st.top()=='['){
                st.pop();
                st.push('Y');
            }
        }
    }
    
}