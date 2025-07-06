#include <string>
#include <vector>
#include <string>
#include <algorithm>
/* compare 함수 커스텀하는 방식을 제대로 이해하고 있자! 아주 편리하게 써먹을 수 있다! */
using namespace std;
bool comp (const int &a, const int &b){
    string sA = to_string(a);
    string sB = to_string(b);
    return sA + sB > sB + sA;
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),comp);
    for (auto a: numbers){
        answer+= to_string(a);
    }
    if (answer[0] == '0') return "0";
    return answer;
}