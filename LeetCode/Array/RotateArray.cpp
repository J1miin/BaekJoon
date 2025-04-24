#include <algorithm>
#include <vector>
using namespace std;
//공간 복잡도 O(N) >> 새로운 배열 사용했기 때문
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int iSize = nums.size();
        vector<int> answer(iSize) ;
        for (int i=0;i<iSize;++i){
            if (i+k>=iSize){
                answer[(i+k)%iSize]=nums[i];
            }else{
                answer[i+k]=nums[i];
            }
        }
        for(int i=0;i<iSize;++i){
            nums[i]=answer[i];
        }
    }
};

//공간복잡도 O(1) >> reverse 어떻게 생각하는거니 대체..
class Solution2 {
    public:
        void rotate(vector<int>& nums, int k){
            int n = nums.size();
            k = k%n;
            
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
        
        }
    };