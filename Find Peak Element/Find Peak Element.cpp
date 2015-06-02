#include <math.h>
#include <climits>

//   2015-6-1
//   Hint#: separate vector into 3 sections and pick the bigger 2/3
//   Time Complex: 2 * logN/log3 = O(logN)

static int findPeak(int start, int end, vector<int> nums){
    if(end - start <= 2){
        for(int i = start; i <= end; i++){
            if(i == -1) continue;
            if(i == nums.size()) continue;

            if(i == 0){
                if(nums[i] > nums[i+1]) return i;
            }
            else if(i == (nums.size() - 1)){
                if(nums[i] > nums[i-1]) return i;
            }
            else{
                if(nums[i] > nums[i+1] && nums[i] > nums[i-1]) return i;
            }
        }
        return (end + start)/2;
    }
    int s1 = start + floor((end-start)/3);
    int s2 = start + floor((end-start)*2/3);

    int t0 = (start == -1) ? INT_MIN : nums[start];
    int t1 = nums[s1];
    int t2 = nums[s2];
    int t3 = (end == nums.size()) ? INT_MIN : nums[end];

    if(t1 >= t0 && t1 >= t2) return findPeak(start, s2, nums);
    if(t2 >= t1 && t2 >= t3) return findPeak(s1, end, nums);
    return findPeak(s1, s2, nums);
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return findPeak(-1, nums.size(), nums);
    }
};