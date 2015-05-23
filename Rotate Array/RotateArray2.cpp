#include <algorithm>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return;
        
        k %= n;
        std::reverse(nums.begin(), nums.begin() + n - k);
        std::reverse(nums.end() - k, nums.end());
        std::reverse(nums.begin(), nums.end());
        
        return;
    }
};