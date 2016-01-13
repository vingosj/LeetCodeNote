// 2016-1-13

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n <= 0) return 0;
        vector<int> dp(n+1, 1);
        dp[1] = s[0] != '0' ? 1 : 0;
        
        for(int i = 2; i <= n; i++){
            dp[i] = s[i-1] == '0' ? 0 : dp[i-1];
            if(s[i-2] != '0' && stoi(s.substr(i-2, 2)) <= 26)
                dp[i] += dp[i-2];
            if(s[i-2] == '0' && s[i-1] == '0') return 0;
        }
        
        return dp[n];
    }
};