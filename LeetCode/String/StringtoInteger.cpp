#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool bFlag = false;
        int iSign = 1;
        string sNew ="";
        /*
        공백이거나 숫자, -라면 문제 없음.
        처음이 문자라면 문제!
        */
        if (s.size()==0) return 0;
        if (isalpha(s[0])) return 0;
        
        for (int i=0;i<s.size();++i){
            if (s[i]==' ' && bFlag == false) continue; 
            if (s[i]=='-' || s[i]=='+'){
                if( bFlag == false ){
                    bFlag = true; //처음에 나온 부호만 사용가능하므로 이렇게 플래그 이용!
                    if (s[i]=='-') iSign = -1;
                    continue;
                }else {
                    break;
                }
            }
            if (isdigit(s[i])){
                sNew += s[i];
                bFlag=true; //이제 숫자 나왔다는 의미에서 이 뒤에 문자 나오면 멈추기 위한 용도
                continue;
            }else break; 
            /*원래는 이렇게 isalpha면 break했지만, 
            .과 같은 소수점도 나오면 안되는거라 else에서 break으로 바꿨다. */
            // if (isalpha(s[i])){
            //     break;
            // }

        }
        long long result = 0;
        for (char c : sNew) {
            result = result * 10 + (c - '0');
            //round 처리
            if (result * iSign > INT_MAX) return INT_MAX;
            if (result * iSign < INT_MIN) return INT_MIN;
        }
        return result * iSign;
    }   
};