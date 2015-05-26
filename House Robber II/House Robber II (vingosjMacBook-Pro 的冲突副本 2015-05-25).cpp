#include <vector>

//    2015-5-25
//    Hint#: there exist three possiblity when convert to house robber one

static int robLine(vector<int> nums){
    int n = nums.size();

    if(n <= 0) return 0;
    vector<int> s(n);
    
    if(n == 1) return nums[0];
    s[0] = nums[0];

    s[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    if(n == 2){
        return s[1];
    }
    
    for(int i = 3; i <= n; i++){
        s[i-1] = (nums[i-1] + s[i-3]) > s[i-2] ? (nums[i-1] + s[i-3]) : s[i-2];
    }

    return s[n-1];
}

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), result = 0, next = 0;
        if(n == 0) return 0;
        result = nums[0];
        if(n == 1) return result;
        result = result > nums[1] ? result : nums[1];
        if(n == 2) return result;
        
        vector<int> s(nums);
        s.erase(s.begin() + n - 1);
        
        vector<int> t(nums);
        t.erase(t.begin());
        
        vector<int> p(nums);
        p.erase(p.begin(), p.begin()+2);
        p.push_back(nums[0]);
        
        result = robLine(s);
        next = robLine(t);
        result = result > next ? result : next;
        next = robLine(p);
        result = result > next ? result : next;
        return result;
    }
};