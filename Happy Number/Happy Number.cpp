#include <string>
#include <set>
#include <stdlib.h>
#include <math>

static int sumUp(int n){
    string s = to_string(n);
    int result = 0;
    for(auto a : s){
        result += pow((int)(a - 48), 2);
    }
    return result;
}

class Solution {
public:
    bool isHappy(int n) {
        set<int> duplicate;
        
        while(n != 1)
        {
            if(duplicate.count(n) == 1) return false;
            else {
                duplicate.insert(n);
                n = sumUp(n);
            }
        }
        
        return true;
    }
};