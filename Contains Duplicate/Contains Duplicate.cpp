#include <vector>
#include <algorithm>

//   2015-5-25

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return false;
        sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return n != nums.size();
    }
};