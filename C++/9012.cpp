#include <bits/stdc++.h>
using namespace std;
int main(){
    int iN;
    cin >> iN;
    while (iN--){
        stack <char> st;
        string sIn;
        bool isOk = true;
        cin >> sIn;
        for (auto c : sIn){
            if (c=='('){
                st.push(c);
            }else {
                if (!st.empty() && st.top()=='('){
                    st.pop();
                }else {
                    isOk = false;
                    break;
                }
            }
        }
        if (st.empty() && isOk) cout << "YES\n";
        else cout <<"NO\n";
    }
}