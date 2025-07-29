#include <bits/stdc++.h>
//거리 배열을 -1로 초기화하는 게 BFS에서 최단 거리 계산할 때 가장 일반적임.
int iVisted[100001];
queue<int> q;
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int iN, iK;
    cin>>iN>>iK;
    fill(iVisted,iVisted+100001,-1);
    iVisted[iN]=0;
    q.push(iN);
    while (iVisted[iK]==-1){
        int cur = q.front(); q.pop();
        for (int nxt : {cur-1,  cur+1, 2*cur}){ 
            //(range-based for loop)문법으로 위의 경우는 각 경우마다 총 3번을 하게 된다.
            if (nxt < 0 || nxt > 100000) continue;
            if(iVisted[nxt] != -1 ) continue;
            iVisted[nxt] = iVisted[cur]+1;
            q.push(nxt);
        }
    }
    cout<<iVisted[iK];
}