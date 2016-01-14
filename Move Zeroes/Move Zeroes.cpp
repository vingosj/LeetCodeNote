class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, count = 1;
        
        while(true){
            while(left < n && nums[left] != 0) {
                count++;
                left++;
            }
            if(left > n-1) return;
            nums.push_back(nums[left]);
            nums.erase(nums.begin() + left);
            if(++count >= n) return;
        }
    }
};