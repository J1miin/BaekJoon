/*
N : 정수의 개수 
S : N으로 만든 부분 수열의 합

`5 0`
`-7 -3 -2 5 8`
    → (-3,-2,5)는 0이 되지만 그 왜의 부분 수열은 합이 0이되는 경우가 없음
output : 1 출력

제약 조건 : 부분 수열은 중복된 원소로 구성될 수 없다.
해가 되는 조건 : 부분 수열의 합이 S와 동일한 경우 정답 cnt 변수 +1

then, 모든 부분 수열을 다 만들어놓고(=2^n), 다시 합 하면서 찾아가야하나? 
-> NO! 만들면서 합이 S랑 같으면 더 이상 탐색하지 않고 탈출 
-> 오름차순 정렬 필요
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*전체 입력값을 벡터로 관리하고, 인덱스를 이용해서 부분집합으로 만들 원소 선택하기
그리고 부부집합을 만들면서 바로바로 합을 구하고 비교하기
부분집합의 크기를 따로 고려하지 않더라도 이 원소를 포함할지 말지를 기준으로 생각하다보면
모든 사이즈의 부분집합이 다 구해지게 되는구나
나는 부분집합의 사이즈를 고려하다보니 자꾸 산으로 갔었는데..
*/
void backTracking(vector<int> &iVec, int idx, int iCurrentSum, int iTargetSum, int &cnt, bool selected){
    if (idx ==iVec.size()){
        if (selected && iCurrentSum==iTargetSum){
            cnt ++;
        }
        return ;
    }

    //현재 원소를 포함하지 않는 경우
    backTracking(iVec,idx+1,iCurrentSum,iTargetSum,cnt, selected);
    //현재 원소를 포함하는 경우 -> iCurrentSum에 더해주기
    backTracking(iVec,idx+1,iCurrentSum+iVec[idx],iTargetSum,cnt, true);
}


int main(){
    int iN, iS, iInput, iCnt;
    iCnt=0;
    vector<int> iVec ;

    cin >> iN >> iS ;
    for (int i=0;i<iN;++i){
        cin>> iInput;
        iVec.push_back(iInput);
    }
    //오름차순 정렬
    sort(iVec.begin(),iVec.end());
    
    backTracking(iVec,0,0,iS,iCnt,false);

    cout<<iCnt<<endl;
    return 0;
}