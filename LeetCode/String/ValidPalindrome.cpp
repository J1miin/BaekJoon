#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
/*alphanumeric은 숫자와 알파벳을 포함한다.
예상 시간복잡도 : 
find - O(N)이다.
erase - O(N)
>> trim 에서 O(N^2)
for문 - O(N)
>> 45 ms가 나왔다아... ㄷㄷ;; 
*/
class Solution {
public:
    string trim(string str){
        while (str.find(' ') != string::npos) str.erase(str.find(' '),1);

        return str;
    }

    bool isPalindrome(string s) {
        s = trim(s);
        string sNew = "";
        for (int i=0;i<s.size();++i){
            char cTmp = s[i];
            if (cTmp>='a' &&cTmp<='z') sNew += s[i];
            else if (cTmp>='A' && cTmp<='Z'){
                sNew += tolower(s[i]);
            }else if (cTmp>='0' && cTmp<='9') {
                sNew +=s[i];
            }else continue;
        }
        
        int iSize = sNew.size();
        for (int i=0;i<iSize/2;++i){
            if (sNew[i]!=sNew[iSize-1-i]) return false;
        }
        return true;
    }
};
//개선 -> Runtime 0ms
class Solution2 {
public:
    bool isPalindrome(string s) {
        int iSize = s.size();
        int j =iSize-1;
        int i=0;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};