#include <iostream>
#include <vector>
#include <queue>
#include<cstdlib> 
using namespace std;
#include <queue>
#include <climits>

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
