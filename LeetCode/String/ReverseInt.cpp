#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib> //abs 사용 목적 
#include <climits> //INT_MIN, INT_MAX 사용 목적 
/* INT_MIN : -2147483648 INT_MAX : 2147483648 */
using namespace std;
//시간복잡도는 일번 풀이가 더 작음
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        std::queue<int> q;
        bool bFlag = false;
        long long lx = x; 

        if (lx < 0) {
            bFlag = true;
            lx = -lx; //음수 오버플로우 방지
        }

        while (true) {
            if (lx < 10) {
                q.push(lx);
                break;
            }
            q.push(lx % 10);
            lx /= 10;
        }

        if (q.size() > 10) return 0;

        int iSize = q.size() - 1;
        while (!q.empty()) {
            long long tmp = q.front();
            q.pop();
            for (int i = iSize; i > 0; --i) {
                if (tmp > LLONG_MAX / 10) return 0;
                tmp *= 10;
            }
            if (ans > LLONG_MAX - tmp) return 0;
            ans += tmp;
            iSize--;
        }

        if (bFlag) {
            ans = -ans;
        }

        if (ans < INT_MIN || ans > INT_MAX) return 0;
        return (int)ans;
    }
};
//2번째 풀이 
/*
int -> string으로 형변환 하는 방법이 to_string인데 (string)으로 해서 안됐었다.;;
*/
class Solution2 {
    public:
        int reverse(int x) {
            bool bFlag = false;
            long long lx = x;
            if (lx < 0){
                lx = -lx;
                bFlag = true;
            }
            
            string sTmp = to_string(lx);
            ::reverse(sTmp.begin(),sTmp.end());
            
            long long res = stoll(sTmp); 
    
            if (bFlag) res = -res;
            if (res < INT_MIN || res > INT_MAX) return 0;
    
            return (int)res;
            
        }
    };