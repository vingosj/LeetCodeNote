#include <string>
#include <vector>
#include <algorithm>
#include <map>

//   2015-6-7

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {

        map<string, int> basic;
        int n = strs.size();
        if(n == 0) return strs;
        vector<bool> ref(n, false);
        
        for(int i = n-1; i >= 0; i--){
            string t = strs[i];
            std::sort(t.begin(), t.end());
            if(basic.count(t) == 1){
                ref[i] = true;
                ref[basic[t]] = true;
            }
            else{
                basic[t] = i;
            }
        }
        
        for(int i = n-1; i>= 0; i--){
            if(!ref[i]) strs.erase(strs.begin() + i);
        }
        
        return strs;
    }
};