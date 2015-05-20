#include <math.h>

// Hint#: the problem actually is count how many ZERO in the end
//        then it can be switch to how many FIVE appears within N!

class Solution {
public:
    int trailingZeroes(int n) {
        if(n <= 0) return 0;
        
        int upper = (int)floor(log(n)/log(5));
        int result = 0;
        
        for(int i = 1; i <= upper; i++){
            result += (n/pow(5, i));
        }
        
        return result;
    }
};