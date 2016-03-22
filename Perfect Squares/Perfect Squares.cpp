//    2016-3-22

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 1; ; j++){
                int temp = i + j*j;
                if(temp > n) break;
                else dp[temp] = min(dp[temp], dp[i] + 1);
            }
        }
        return dp[n];
    }
};