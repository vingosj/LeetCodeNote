#include <vector>

//   2015-6-5

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), result = 1;
        if(n <= 1) return 0;
        
        int min = 1, max = nums[0];
        if(max >= n-1) return result;
        
        while(max < n-1){
            result++;
            int nextmax = max + 1;
            for(int i = min; i <= max; i++){
                if(nums[i] + i > nextmax) nextmax = nums[i] + i;
            }
            min = max + 1;
            max = nextmax;
        }
        
        return result;
    }
};