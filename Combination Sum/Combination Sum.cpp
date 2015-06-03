#include <algorithm>
#include <vector>

//   2015-6-2

static void findCombo(vector<int> s, 
                int t, 
                vector<vector<int>>& result, 
                int index,                     // no more than this index can be added
                int sum,                       // current sum
                vector<int> entry)             // current vector entry
{
    int n = s.size();
    while(s[index] + sum > t){
        if(++index == n) return;
    }

    if(s[index] + sum == t){
        entry.push_back(s[index]);
        //sort(entry.begin(), entry.end());
        result.push_back(entry);
        entry.erase(entry.end() - 1);
        if(++index == n) return;
    }
    
    for(int i = index; i < n; i++){
        entry.push_back(s[i]);
        sum += s[i];
        findCombo(s, t, result, i, sum, entry);
        sum -= s[i];
        entry.erase(entry.end() - 1);
    }
    return;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size() == 0) return result;
        std::sort(candidates.rbegin(), candidates.rend());
        
        vector<int> entry;
        findCombo(candidates, target, result, 0, 0, entry);
        
        std::sort(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++){
            sort(result[i].begin(), result[i].end());
        }
        
        return result;
    }
};