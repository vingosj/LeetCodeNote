#include <vector>

//   Hint#: use dynamic sub array to avoid duplicated calculation

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // index: current cursor position
        // len:   current subarray length
        // sum:   current subarray sum
        int n = nums.size(), len = 0, index = 0, sum = 0;
        if(n == 0) return len;
        while(len < n && sum < s){
            sum += nums[index+len];
            len++;
        }
        if(sum < s) return 0;

        while(index + len < n){
            index++;
            sum = sum + nums[index + len - 1] - nums[index - 1];
            if(sum >= s){
                int temp = index + len - 1;
                while(len >= 1 && sum - nums[temp] >= s){
                    sum -= nums[temp];
                    len--;
                    temp--;
                }
            }
        }
        
        while (index < n){
		    sum -= nums[index++];
		    if (sum >= s) len--;
	    }
        
        return len;
    }
};