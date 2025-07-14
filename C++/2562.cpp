/* solution에서 배운 점
- max_element 함수 사용: <algorithm>에 포함되어 있으며 컨테이너에서 최댓값을 찾는 함수이다.
- max_element(start, end) 형태로 사용하고 [start, end) 구간 내에서 가장 큰 값의 iterator를 반환한다.
- 따라서 최댓값을 얻으려면 * 연산자로 iterator를 역참조해야 하고,
- 최댓값의 인덱스를 찾으려면 max_element(a, a+9) - a 처럼
  최댓값의 포인터에서 배열의 시작 주소를 빼주면 된다.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int iArr[9];
    int iIdx, iMax=0;
    for (int i=0;i<9;++i){
        cin >> iArr[i];
    }
    for (int i=0;i<9;++i){
        if (iMax < iArr[i]){
            iMax = iArr[i];
            iIdx = i;
        }
    }
    cout << iMax<<'\n'<<iIdx+1;
}