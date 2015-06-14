#include <vector>
#include <algorithm>

//   2015-6-14

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                int next = i + 1;               // used to know which number is next
                for(int j = i+2; j < n; j++){
                    if(nums[j] > nums[i] && nums[j] < nums[next]){
                        next = j;
                    }
                }
                int temp = nums[i];
                nums[i] = nums[next];
                nums[next] = temp;
                
                std::sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        
        std::sort(nums.begin(), nums.end());
        return;
    }
};