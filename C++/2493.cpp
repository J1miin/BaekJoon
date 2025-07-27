//이중 반복문 >> 시간 초과 난다. stack으로 O(N)으로 해결해야하는 문제..
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    stack<pair<int,int>> sTower;
    cin>>N;
    sTower.push({100000001, 0}); 
    //최대 높이의 탑을 넣어놓고, 시작한다. 어차피 처음 넣는 탑은 왼쪽에 레이저 못 쏘니까 0이될 수밖에 없음
    for (int i=1;i<=N;++i){
        int height;
        cin>>height;
        while (sTower.top().X < height){
            sTower.pop();
            //어차피 입력 순서대로 가니까 자기보다 작은 왼쪽 애는 지우면 됨
        }
        cout<<sTower.top().Y<<" ";
        sTower.push({height,i});
    }

}
void mysolution(){
    int iN, iSize;
    vector<int>v;
    stack<int> ans;
    cin >>iN;
    for (int i=0;i<iN;++i){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    iSize=iN;
    for (int i=iSize-1;i>=0;--i){
        bool check = false;
        for (int j=i-1;j>=0;--j){ 
            if (v[j]>v[i]){
                check = true;
                ans.push(j+1);
                break;
            }
        }
        if (check==false){
            ans.push(0);
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}