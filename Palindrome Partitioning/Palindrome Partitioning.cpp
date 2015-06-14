#include <vector>
#include <algorithm>
#include <string>

//   2015-6-14

static void part(vector<vector<string>>& res, vector<string> entry, string remain)
{
    int n = remain.size();
    for(int i = n; i > 0; i--){
        string left = remain.substr(0, i);
        string right = remain.substr(i);
        
        string rleft(left.rbegin(), left.rend());
        if(rleft == left){
            entry.push_back(left);
            if(right == "") res.push_back(entry);
            else part(res, entry, right);
            entry.erase(entry.end() - 1);
        }
    }
    return;
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s == "") return res;
        vector<string> entry;
        
        part(res, entry, s);
        return res;
    }
};