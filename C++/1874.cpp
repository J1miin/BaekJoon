//다시 풀어보기
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> S;
    int cnt = 1;
    string ans;
    while(n--){
        int iInput;
        cin >> iInput;
        while(cnt<=iInput){
            S.push(cnt++);
            ans+="+\n";
        }
        if (S.top()!= iInput){
            cout<<"NO\n";
            return 0;
        }
        S.pop();
        ans+="-\n";
    }   
    cout<<ans;
}
// int main(){
//     int iN,iTmp,j;
//     queue<int> q;
//     stack<int> st;
//     cin >> iN;
//     for (int i=0;i<iN;++i){
//         cin >> iTmp;
//         q.push(iTmp);
//     }
//     int iValue = q.front();
//     for (j=0;j<iValue;++j){
//         st.push(j+1);
//         //cout<<"+ "<<j+1<<'\n';
//         cout<<"+\n";
//     }
//     // int top = st.top();
//     // // cout<<"- "<<st.top()<<'\n';
//     // cout<<"-\n";
//     // st.pop(); q.pop();
    
//     while (!q.empty()){    
//         iValue = q.front();
//         int top;
//         if (!st.empty()){
//             top = st.top();
//             if (iValue<=top){
//                 for (int i=0;i<=top-iValue;++i){
//                     //cout<<"- "<<st.top()<<'\n';
//                     cout<<"-\n";
//                     st.pop();
//                 }
//                 q.pop();
//             }else {
//                 j+=1;
//                 st.push(j);
//                 //cout<<"+ "<<j<<'\n';
//                 cout<<"+\n";
//             }
//         }else{
//             cout<<"NO\n";
//             break;
//         }
//         //cout<<"iValue: "<<iValue<<" top "<<top<<endl;
        
//     }
// }