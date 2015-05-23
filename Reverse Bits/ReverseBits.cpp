#include <math.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t s = pow(2, 31), t = 1;
        
        while(n != 0){
            if(n > s){
                n -= s;
                s /= 2;
                result += t;
                t *= 2;
            }
            else if(n < s){
                s /= 2;
                t *= 2;
            }
            else{
                n -= s;
                result += t;
                return result;
            }
        }
        
        return result;
    }
};