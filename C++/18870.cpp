/*
좌표압축 - 현재값보다 작은 수들의 개수를 카운트해서 출력하기
일단 입력받은 값의 순서대로 좌표압축한 값을 출력해야하므로, 입력받은 값 순서를 유지하고 있는 배열(벡터)와
입력받은 값을 가지고 조작을 가한 배열(벡터)를 하나 더 준비한다(vSorted).
vSorted 배열은 중복을 제거하고 (unique), sort(오름차순)정렬을 해준다.
이렇게 정렬 및 정리된 vSorted의 index가 해당 인덱스에서의 값보다 작은 숫자의 개수가 된다.
따라서 출력을 위해 vSorted의 값을 key로, index를 value로 하는 해시맵(hCntMap)을 만들고 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
vector<int> vNumArr;
vector<int> vSorted;
unordered_map <int, int> hCntMap;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int iN,iTmp;
    cin>>iN;
    for (int i=0;i<iN;++i){
        cin>>iTmp;
        vNumArr.push_back(iTmp);
        vSorted.push_back(iTmp);
    }
    sort(vSorted.begin(),vSorted.end());
    vSorted.erase(unique(vSorted.begin(),vSorted.end()),vSorted.end());
    for (int i=0;i<vSorted.size();++i){
        hCntMap[vSorted[i]]=i;
    }

    for (int i=0;i<iN;++i){
        cout<<hCntMap[vNumArr[i]]<<" ";
    }

    return 0;
}