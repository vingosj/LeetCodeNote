//   2015-5-25
//   Hint#: Dynamic Programming

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> s(n+1);
        s[0] = 1;
        s[1] = 1;
        for(int i = 2; i <= n; i++){
            s[i] = s[i-2] + s[i-1];
        }
        
        return s[n];
    }
};