#include <map>
#include <vector>

//   2015-6-6

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k <= 0){
            return false;
        }
        
        map<int, int> ref;
        for(int i = 0; i < n; i++){
            int value = nums[i];
            if(ref.count(value) == 0){
                ref[value] = i;
                nums[i] = -1;
            }
            else{
                if(i - ref[value] <= k) return true;
                nums[i] = ref[value];
                ref[value] = i;
            }
        }
        
        return false;
    }
};