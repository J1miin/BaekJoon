/*
아 나는 뒤집기라고 해서 reverse 함수를 생각했는데, 그냥 뒤집으면 뒤에서 빼고, 
뒤집기가 아니면 앞에서 빼는 방식으로 가면 시간복잡도도 훨씬 줄겠구나
그리고 그걸 덱으로 하면 앞뒤에서 수월하게 뽑을 수 있는거고!
*/
#include <bits/stdc++.h>
using namespace std;
void parse(string & tmp, deque<int> & d){
    int cur = 0;
    for (int i=1; i+1<tmp.size();++i){ 
        //아예 시작 괄호와 마지막 괄호는 제거하고 시작하는 셈 (i=1과 i+1<tmp.size())
        if (tmp[i]==','){
            d.push_back(cur);
            cur=0;
        }else{
            cur = 10*cur + (tmp[i]-'0'); 
            //문자열을 숫자로 바꾸는 과정임. 두자리 자연수 같은 경우를 방지해서 cur*10이 꼭 필요하다.
            cout<<cur<<'\n';
        }
    }
    if (cur != 0) d.push_back(cur);
}
void print_result(deque<int>&d){
    cout<<'[';
    for (int i=0;i<d.size();++i){
        cout<<d[i];
        if (i+1!=d.size())
        cout<<',';
    }
    cout<<"]\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int iT;
    cin >> iT;
    
    while (iT--){
        deque<int> d;
        int rev = 0;
        int n; //몇 개의 숫자가 들어올지
        bool isWrong = false;
        string query, tmp; //query = 명령, tmp = 괄호가 포함된 숫자배열
        cin >> query >> n >> tmp;
        parse(tmp,d);
        for (char c : query){
            if (c=='R'){
                rev = 1 - rev;
            }else {
                if (d.empty()){
                    isWrong=true;
                    break;
                }
                if (!rev) d.pop_front();
                else d.pop_back();
            }
        }
        if (isWrong) cout << "error\n";
        else {
            if (rev) reverse(d.begin(),d.end());
            print_result(d);
        }
    }
}