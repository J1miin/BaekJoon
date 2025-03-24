/*
오차가 10^-9 이하여야 정답이다 
== 실제 정답에 0.000000001 이하의 값을 더하거나 빼도 정답 처리하겠다.
실제 답 - 내 답 <= 0.000000001 이어야 한다. 
>> 적어도 소수점 9개는 출력해야한다는 뜻
float은 소수점 6자리까지 출력 double은 15자리까지 출력
*/
#include <iostream>
using namespace std;

int main(){
    double iA, iB;
    cin>> iA >> iB;
    cout.precision(15); //정수 포함 15자리로 고정
    cout<<fixed; //소수점 아래 15자리로 고정 
    cout<< iA/iB;
    return 0;
}