/*조건 linear runtime complexity and use only constant extra space.*/
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

//hashmap -> O(1) 최악의 경우 O(N)의 시간 복잡도  >> 시간 복잡도는 해당되지만, 
// 공간복잡도는 상수가 아니라서 조건 위배됨
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_map <int,int> m;
            for (int i=0;i<nums.size();++i){
                if (m[nums[i]]){
                    m[nums[i]]++;
                }else {
                    m[nums[i]]=1;
                }
            }
            for (int i=0;i<nums.size();++i){
                if (m[nums[i]]==1){
                    return nums[i];
                }
            }
            return -1;
        }
    };

//XOR을 이용하여 공간복잡도 1로 구현하기
/*숫자들이 두 번씩 등장하면: x ^ x = 0 으로 사라진다.
XOR은 순서를 섞어도 결과가 같기 때문에, 다 짝 지어진 숫자들은 다 없어지고 한 번만 등장한 숫자만 남는다...!*/
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};
