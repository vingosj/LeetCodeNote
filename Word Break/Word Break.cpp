#include <set>
#include <string>
#include <algorithm>
#include <unordered_set>

//   2015-6-5

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s == "") return wordDict.count(s) == 1;
        
        set<string> word;
        for(string m : wordDict){
            word.insert(m);
        }
        
        int n = s.size();
        vector<bool> t(n);
        
        for(int i = 1; i <= n; i++){
            if(word.count(s.substr(0, i)) == 1){
                t[i-1] = true;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!t[i]) continue;
            for(int j = 1; j < n - i; j++){
                if(t[i + j]) continue;
                if(word.count(s.substr(i + 1, j)) == 1) t[i + j] = true;
            }
        }
        
        return t[n-1];
    }
};