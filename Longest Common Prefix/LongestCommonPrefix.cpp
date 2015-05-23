#include <string>

// 2015-5-22
// Hint#: truncate prefix by each string in vector

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string pre = strs[0];
        for(auto s : strs){
            int size = s.size() < pre.size() ? s.size() : pre.size();
            if(pre.size() > size) pre = pre.substr(0, size);
            for(int i = 0; i < size; i++){
                if(s[i] != pre[i]){
                    pre = pre.substr(0, i);
                    break;
                }
            }
        }
        
        return pre;
    }
};