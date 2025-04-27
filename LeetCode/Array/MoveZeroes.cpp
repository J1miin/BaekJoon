#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> nums = {2,1,0};
    int len = nums.size();
    int idx = 0;
    
    for(int i = 0; i < len; i++){
        if(nums[i]==0){
            swap(nums[i], nums[idx]);
            idx++;
        }
    }
    for (int a : nums){
        cout<< a<<" ";
    }
    // vector<int> tmp;
    // int iCnt = 0;
    // int iSize = nums.size();
    // for(int i=0; i<iSize; ++i){ 
    //     if (nums[i]==0){
    //         iCnt ++;
    //     }else {
    //         tmp.push_back(nums[i]);
    //     }
    // }
    // for (int i=0;i<iCnt;++i){
    //     tmp.push_back(0);
    // }

}

class Solution {
    public: 
        void moveZeroes(vector<int>& nums) {
            int len = nums.size();
            int idx = 0;
            
            for(int i = 0; i < len; i++){
                if(nums[i]){
                    swap(nums[i], nums[idx]);
                    idx++;
                }
            }
        }
    };
