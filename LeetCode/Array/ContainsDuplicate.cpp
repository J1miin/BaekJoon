#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            auto it = unique(nums.begin(), nums.end());
            if(it==nums.end()) return false; 
            //unique에서 반환받은게 중복된 값의 시작 이터레이터값. 
            //그게 끝과 같다면 중복이 없다는 뜻이니까 false 반환
            else return true;
        }
    };