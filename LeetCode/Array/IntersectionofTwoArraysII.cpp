#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*굳이 크기를 비교할 필요가 없구나. 그냥 hash map을 이용해서 찾아가면 되는거니까..*/
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> answer;
            int size1 = nums1.size(); 
            unordered_map <int,int> hashmap;
            
            for (int a : nums2){
                hashmap[a]++;
            }
                            
            for (int i=0;i<size1;++i){
                if(hashmap[nums1[i]]>0) {
                    answer.push_back(nums1[i]);
                    hashmap[nums1[i]]--;
                }
            }
                               
            
            
            return answer;
        }
    };