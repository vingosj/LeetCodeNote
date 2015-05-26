#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dic;
        vector<int> result(2);
        int index = 1, N = nums.size(), comp;
        
        for(auto i : nums){
            if(2*i == target){
                if(dic[i] >= 1){
                    result[0] = dic[i];
                    result[1] = index;
                    return result;
                }
            }
            
            comp = target - i;
            if(dic[comp] >= 1){
                result[0] = dic[comp];
                result[1] = index;
                return result;
            }
            dic[i] = index;
            index++;
        }
        
        return result;
    }
};