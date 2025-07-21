/*
M1) 투포인터 방식 >> O(NlogN) 
    투포인터는 정렬이 필수적이다.
M2) 입력 가능한 모든 숫자에 대한 배열을 만들어서, 
숫자 하나와 타겟을 만드는 숫자를 만드는 수가 존재하는지 아닌지를 확인하는 방식 >> O(N)
*/

//M1 투포인터 방식 
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int iN, iTarget, iAns=0;
    
    cin>>iN;
    
    vector <int> vNum(iN);
    for (int i=0;i<iN;++i){
        cin>>vNum[i];
    }
    cin>>iTarget;

    sort(vNum.begin(),vNum.end());
    
    int iS=0, iE=iN-1;
    
    while(iS<iE){
        int iSum =vNum[iS]+vNum[iE];
        if (iSum==iTarget) {
            iAns ++;
            iS++;
            iE--;
        }else if (iSum<iTarget){
            iS++;
        } else {
            iE--;
        }
    }
    cout<<iAns;
}

//M2
int solution2(){
    int iN, iTarget, iAns=0;
    int a[1000001]={};
    bool occured[2000001];
    cin >> iN;
    for (int i=0;i<iN;++i){cin>>a[i];}
    cin>>iTarget;

    for (int i=0;i<iN;++i){
        if (iTarget-a[i] > 0 && occured[iTarget-a[i]]) iAns++;
        //한 쌍이 (x, y) 라고 할 때, 첫 번째로 x가 나왔을 땐 위의 조건식이 무조건 false이고, occured[a[i]]를 바꾼다. 
        //그리고 y가 나왔을 때 x가 전에 나왔음을 체크해놨으니까 카운트할 수 있게된다. 
        //각 쌍마다 처음에는 패스, 뒤에 가서(두 번째 원소가 등장할 때) pair로 카운트하는 구조이다. 
        occured[a[i]]= true;
    }
    cout << iAns;
}
