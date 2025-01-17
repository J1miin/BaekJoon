/*
크기가 제한 된 순열문제 (순서가 중요하기 때문)
N = 3, M = 3
1부터 3까지 숫자를 이용해서 크기가 2인 순열 만들기 
output : 1,2,3 - 1,3,2 - 2,1,3 - 2,3,1 - 3,1,2 - 3,2,1

조건 : 
1. 수열을 구성하는 숫자가 중복되면 안된다. 
2. 수열의 크기는 iM으로 고정된다. 
3. 수열은 사전 순으로 증가하는 순서로  출력한다.
 */

#include <iostream>
#include <vector>
#define MAX 9
using namespace std;
int iN, iM;
int arr[MAX];
bool visited[MAX];

void backTracking(int iCurrentLoc){
    if (iCurrentLoc==iM){
        for (int i=0;i<iM;++i){
            cout<<arr[i]<<" ";
        }
        cout<<'\n'; //와우.. 이거 endl으로 해서 시간 초과가 나는구나... 
        return;
    }
    for (int i=1;i<=iN;++i){
        if(visited[i]==false){
            visited[i]=true;
            arr[iCurrentLoc]=i;
            backTracking(iCurrentLoc+1);
            visited[i]=false;
        }
    }

}

int main(){
    cin >> iN >> iM;
    backTracking(0);
    return 0;
}