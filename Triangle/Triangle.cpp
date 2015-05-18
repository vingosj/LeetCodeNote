#include <vector>

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int N = triangle.size();
        if(N == 0) return 0;
        
        vector<int> s(N);
        s[0] = triangle[0][0];
        
        for(int i = 1; i < N; i++){
            s[i] = s[i-1] + triangle[i][i];
            for(int j = i-1; j > 0; j--){
                s[j] = s[j-1] < s[j] ? s[j-1]+triangle[i][j] : s[j]+triangle[i][j];
            }
            s[0] = s[0] + triangle[i][0];
        }
        
        int result = s[0];
        for(auto a : s){
            if(a < result) result = a;
        }
        
        return result;
    }
};