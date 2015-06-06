#include <vector>

//   2015-6-6
//   Hint#: to know whether the circle exist, is to check the total amount diff.
//   If exist, then pick the biggest gap to start.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n == 0) return -1;
        
        vector<int> s(n);
        int amount = 0, cumulate = 0, index = 0;
        for(int i = 0; i < n; i++){
            s[i] = gas[i] - cost[i];
            amount += s[i];
            
            cumulate += s[i];
            if(cumulate < 0) {
                cumulate = 0;
                index = i + 1;
            }
        }
        
        if(index == n) index = 0;
        
        if(amount < 0) return -1;
        return index;
    }
};