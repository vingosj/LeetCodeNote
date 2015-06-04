#include <vector>

//   2015-6-3

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        int result = 0, min = prices[0], gap;
        for(int i = 0; i < n; i++){
            if(prices[i] <= min) min = prices[i];
            else{
                gap = prices[i] - min;
                if(gap > result) result = gap;
            }
        }
        return result;
    }
};