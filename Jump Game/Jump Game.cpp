#include <vector>

//   2015-6-5

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        if(n == 0) return true;
        
        vector<int> s(n);
        
        for(int i = 0; i < n; i++){
            if(reach < i) return false;
            reach = nums[i]+i > reach ? nums[i]+i : reach;
        }
        
        return reach >= n-1;
    }
};