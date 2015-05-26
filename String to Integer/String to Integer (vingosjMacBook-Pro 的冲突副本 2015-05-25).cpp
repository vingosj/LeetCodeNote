#include <string>
#include <algorithm>
#include <ctype.h>
#include <climits>

static void trim(string& s){
    if(s == "") return;
    int i = 0;
    for(auto c : s){
        if(c != ' ') break;
        else i++;
    }
    if(i != 0) s.erase(0, i);
    return;
}

class Solution {
public:
    int myAtoi(string str) {
        int sign = 0;
        long test = 0;
        // remove spaces
        //str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        trim(str);
        if(str == "") return 0;
        
        for(auto c : str){
            if(c == '+' && sign == 0){
                sign = 1;
                continue;
            }else if(c == '-' && sign == 0){
                sign = 2;
                continue;
            }else if(isdigit(c)){
                test = 10*test + (long)(c-48);
                if((test - 1) > INT_MAX) break;
            }else{
                break;
            }
        }
        
        if(sign == 2) test *= -1;
        if(test > INT_MAX) return INT_MAX;
        if(test < INT_MIN) return INT_MIN;
        
        return (int)test;
    }
};