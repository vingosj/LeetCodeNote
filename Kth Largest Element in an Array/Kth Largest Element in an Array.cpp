#include <vector>
#include <algorithm>

//   2015-6-4

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return 0;
        
        vector<int> s(nums.begin(), nums.begin() + k);
        sort(s.begin(), s.end());
        
        for(int i = k; i < n; i++){
            if(nums[i] > s[0]){
                s.push_back(nums[i]);
                sort(s.begin(), s.end());
                s.erase(s.begin());
            }
        }
        
        return s[0];
    }
};