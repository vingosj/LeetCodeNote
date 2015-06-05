#include <math.h>

//2015-6-4

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0, i = 0;
        while(m != 0 || n != 0){
            if(m%2 == 1 && n%2 == 1 && n-m < 1){
                result += pow(2, i);
            }
            m /= 2;
            n /= 2;
            i++;
        }
        return result;
    }
};