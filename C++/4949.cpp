/*
stack에서 top()을 하려면 empty를 먼저 확인해야한다는 점을 잊지 말자! 
1.여는괄호가나오면스택에추가
2.닫는괄호가나왔을경우
    2-1. 스택이비어있으면올바르지않은괄호쌍
    2-2. 스택의top이짝이맞지않는괄호일경우올바르지않은괄호쌍
    2-3. 스택의top이짝이맞는괄호일경우pop
3.모든과정을끝낸후스택에괄호가남아있으면올바르지않은괄호쌍, 남아있지않으면올바른괄호쌍
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    while (true){
        string sentence;
        stack<char> st;
        bool isGood = true;
        getline(cin,sentence);
        if (sentence==".") break;
        for (char c : sentence){
            if (c=='(' || c=='['){
                st.push(c);
            }else if (c==')'){
                if (!st.empty() && st.top()=='('){
                    //cout<<"c: "<<c<<"pop: "<<st.top()<<endl;
                    st.pop();
                }else {
                    isGood = false;
                    break;
                }
            }else if (c==']'){
                if (!st.empty()&&st.top()=='['){
                    //cout<<"c: "<<c<<"pop: "<<st.top()<<endl;
                    st.pop();
                }else {
                    isGood = false; 
                    break;
                }
            }
        }
        if (st.empty() && isGood) cout<< "yes\n";
        else cout << "no\n";
    }

}