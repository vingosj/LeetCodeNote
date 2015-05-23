#include <math.h>

// 2025-5-22
// Hint#: treat n as a 26bit number
// Dont forget to set n = n - 1;


class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 0) return NULL;
        
        string s = "";
        int temp;
        
        while(n != 0){
            temp = n % 26;
            n = (n - 1) / 26;
            
            if(temp == 0) s = 'Z' + s;
            else s = (char)(temp + 64) + s;
        }
        
        return s;
    }
};