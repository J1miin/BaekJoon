#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vAns;
        for (int i=1;i<=n;++i){
            if (i%3==0 && i%5==0){
                vAns.push_back("FizzBuzz");
            }else if (i%3==0){
                vAns.push_back("Fizz");
            }else if (i%5==0){
                vAns.push_back("Buzz");
            }else {
                vAns.push_back(to_string(i));
            }
        }
        return vAns;
    }
};

//미리 answer의 사이즈를 n으로 지정해놔서 불필요하게 많이 생성하지 않아도 된다.
class Solution2 {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer(n, "");
        for(int i=1; i<=n; i++){
            if(i%3 == 0){
                answer[i-1] += "Fizz";
            }
            if(i%5 == 0){
                answer[i-1] += "Buzz";
            }
            if(answer[i-1] == ""){
                answer[i-1] = to_string(i);
            }
        }

        return answer;
    }
};