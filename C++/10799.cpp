/*둘다 ()로 표현하는데 쇠막대기와 레이저를 어떻게 구분해야할까??
>> 레이저인 괄호 앞에가 뭐가 나오는지 확인하기 
>> 개수는 어떻게 세야할까?? 수열처럼 직접 써보면서 규칙을 찾아내자...
>> 스택의 사이즈로 하나씩 더해주고, 마지막 에 막대기가 끝나면 +1을 해주면 카운트가 된다.
근데 이런거는 직접 찾아내야하는 것 같다...
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    stack<char> st;
    int iAns = 0;
    string sInput;
    cin>>sInput;
    for (int i=0; i<sInput.size();++i){
        if (sInput[i]=='('){
            st.push(sInput[i]);
        }else {
            if (i-1>=0 && sInput[i-1]=='('){
                st.pop();
                iAns+=st.size();
            }else{
                st.pop();
                iAns++;
            }
        }
    }
    cout <<iAns;
}