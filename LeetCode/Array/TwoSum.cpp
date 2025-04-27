#include <algorithm>
#include <vector>
using namespace std;

//Solution 1 - O(n^2)
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> answer;
            for (int i=0;i<nums.size();++i){
                for (int j=1;j<nums.size();++j){
                    if (i!=j && nums[i]+nums[j]==target){
                        answer.push_back(i);
                        answer.push_back(j);
                        return answer;
                    }else{
                        continue;
                    }
                }
            }
            return answer;
        }
    };