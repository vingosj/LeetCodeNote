#include <iostream>
#include <locate>
#include <string>
#include <math.h>

// Hint#: std::tolower(std::string s, std::locale loc) 

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size(), result = 0;
        locale loc;
        if(n == 0) return result;
        
        for(int i = n-1; i >= 0; i--){
            result += (pow(26, n-i-1)*(int)(tolower(s[i], loc) - 96));
        }
        
        return result;
    }
};