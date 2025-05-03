#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ndlSize = needle.size();

        if (ndlSize > haystack.size()) return -1;
        for (int i=0;i<=haystack.size()-ndlSize;++i){
            bool found = true;
            for (int j=0; j<ndlSize;++j){
                if(haystack[i+j]!=needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) return i;
        }
        return -1;
    }
};