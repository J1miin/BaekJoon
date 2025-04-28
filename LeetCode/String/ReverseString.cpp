#include <iostream>
#include <vector>
using namespace std;
/*reverse 함수 시간 복잡도 O(N) 
다른 사람들 풀이 & 힌트 - Two Pointer 와 Swap함수 이용*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};
//2번째 풀이 using swap()
class Solution {
public:
    void reverseString(vector<char>& s) {
        int iLen = s.size();
        for (int i=0;i<iLen/2;++i){
            swap(s[i],s[iLen-i-1]);
        }
    }
};

//3번째 풀이 - two pointer
class Solution {
public:
    void reverseString(vector<char>& s) {
        int k=s.size(),ptr=0;
        char c;
        for (int i=0;i<(s.size()/2);i++){
            //swap을 그냥 직접 구현한 것!
            c=s[i];
            s[ptr++]=s[--k];
            s[k]=c;
        }
    }
};
