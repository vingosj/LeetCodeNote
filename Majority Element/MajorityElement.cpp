#include <map>
#include <math.h>

// 2015-5-21

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> index;
        
        for(int a : nums){
            if(index.find(a) == index.end()){
                index[a] = 1;
            }
            else{
                index[a]++;
            }
        }
        
        int n = (int)floor(nums.size()/2);
        for(auto p : index){
            if(p.second > n) return p.first;
        }
        
        return 0;
    }
};
