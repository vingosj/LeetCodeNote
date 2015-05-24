class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> s(N);
        
        if(N == 0) return 0;
        s[0] = nums[0];
        
        if(N == 1) return s[0];
        s[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        
        for(int i = 2; i < N; i++ ){
            s[i] = (s[i-2] + nums[i]) > s[i-1] ? (s[i-2] + nums[i]) : s[i-1];
        }
        
        return s[N-1];
    }
};