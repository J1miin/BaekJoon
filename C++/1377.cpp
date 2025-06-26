//버블소트의 시간 복잡도를 줄이는 방법 -> bool change의 여부를 확인하기
//버블소트의 내부 반복문의 횟수 = 스왑 횟수 -> 정렬 전후 인덱스 차이의 최대값 +1로 구할 수 있다
/*
버블소트에서 스왑이 발생하지 않을 때까지 내부 반복문이 몇 번 돌았는지 확인하는 코드 
시간제한 -> O(N^2) 으로 풀면 X
즉 몇 번 만에 정렬이 다 되냐!
정렬전 인덱스 - 정렬후 인덱스를 뺀 값이 왼쪽으로(양수값) 오른쪽으로(음수값) 얼마나 이동했냐를 의미하는데
이거는 swap을 한 횟수와 동일하다. (내부 반복문 한 번 돌아갈 때 생기는 swap으로 한 번 왼쪽으로 이동하기 때문)
그래서 이 인덱스 차의 최대 값을 찾으면 총 swap한 횟수가 나오고, 
여기에 마지막에 다시 돌면서 swap이 없는 완전한 상태일 떄의 경우 1을 더해줘야한다. 
처음에는 인덱스 값 바꾸기 전 후 비교를 할 때 해시 자료구조를 썼는데, 그러면 배열의 값이 중복되는 경우가 덮어씌여지는 문제가 있따.
따라서... vector<pair<int,int>>로 관리하자..! 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,diff=0;
    cin >> N;
    vector<pair<int,int>> A(N);
    
    for (int i=0;i<N;++i){
        cin>> A[i].first ;
        A[i].second = i; //인덱스값
    }
    sort(A.begin(),A.end()); //첫번째 값을 기준으로 정렬이 됨

    for (int i=0;i<N;++i){
        int minus = A[i].second-i;
        if (minus>diff){
            diff = minus;
        }
    }
    cout<<diff+1<<'\n';
    
    return 0;
}