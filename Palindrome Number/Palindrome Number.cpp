#include <stdlib.h>
#include <string>
#include <algorithm>

//    2015-2-24

class Solution {
public:
    bool isPalindrome(int x) {
        abs(x);
        
        string s = std::to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        
        if(t == s) return true;
        else return false;
    }
};