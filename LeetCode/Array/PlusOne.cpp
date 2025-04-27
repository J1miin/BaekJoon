#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//오버플로우가 발생한다..... digit이 엄청 커질 수 있다....
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer;
        int maxDigit = digits.size()-1;
        long long iNum=0; 
        
        for (int i=0;i<digits.size();++i){
            int mul = 1;
            for (int j=0;j<maxDigit-i;++j){
                mul = mul * 10;
            }
            iNum += digits[i]*mul;
        }
        iNum+=1;

        stack<int> s;
        while (true){
            if (iNum<10){
                answer.push_back(iNum);
                break;
            }
            s.push(iNum%10);
            iNum=iNum/10;
        }
        while(!s.empty()){
            answer.push_back(s.top());
            s.pop();
        }
        return answer;
    }
};

/*solution2 자릿수를 다 하나하나 구하고 더한다 생각하지 말기
carry 덧셈 처럼 생각하기!! ㅠㅠ 9일 떄를 기준으로 뒤에서부터 정리해나가는 것. 
*/
int main(){
    vector<int> digits = {9,9,9,8,9};
    for (int i=digits.size()-1;i>=0;--i){
        if (digits[i]<9){
            digits[i]++;
            break;
        }
        digits[i]=0;
    }
    if (digits[0]==0){
        digits.insert(digits.begin(),1);
    }
    for (int a: digits){
        cout<<a<<" ";
    }
}