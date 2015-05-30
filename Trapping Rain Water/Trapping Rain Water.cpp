#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        
        int max = *std::max_element(height.begin(), height.end()), count = 0, h = 0;
        int first = std::distance(height.begin(), std::find(height.begin(), height.end(), max));
        vector<int> rise, fall;
        
        // from 0 to pick
        for(int i = 0; i < first; i++){
            if(height[i] > h) h = height[i];
            else count += (h - height[i]);
        }
        

        // from pick to end
        h = height[n-1];
        for(int i = n - 1; i > first; i--){
            if(height[i] > h) h = height[i];
            else count += (h - height[i]);
        }
        
        return count;
    }
};