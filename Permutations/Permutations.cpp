#include <vector>
#include <algorithm>

//   2015-6-14

void perm(vector<vector<int>>& res, vector<int> entry, vector<int> remain){
    int n = remain.size();
    
    if(n == 1){
        entry.push_back(remain[0]);
        res.push_back(entry);
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(i != 0 && remain[i] == remain[i-1]) continue;
        
        int copy = remain[i];
        entry.push_back(remain[i]);
        remain.erase(remain.begin() + i);
        perm(res, entry, remain);
        remain.insert(remain.begin() + i, copy);
        entry.erase(entry.end() -1);
    }
    
    return;
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n == 0) return res;
        
        std:sort(nums.begin(), nums.end());
        vector<int> entry;
        perm(res, entry, nums);
        return res;
    }
};