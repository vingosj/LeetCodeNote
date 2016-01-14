// 2016-1-13
#include <math.h>

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0, s = n, tmp, reminder = 0;
        if(n <= 0) return count;
        vector<int> digit;
        while(s > 0){
            digit.push_back(s % 10);
            s /= 10;
        }
        
        for(int i = 0; i < digit.size(); i++){
            tmp = n / pow(10, i + 1);
            count += tmp * pow(10, i);
            if(i != 0) reminder = reminder + digit[i-1] * pow(10, i-1);
            
            // if this digit stuck between at 1;
            if(digit[i] == 1) count += (i == 0 ? 1 : reminder + 1);
            else if(digit[i] > 1) count += pow(10, i);
        }
        return count;
    }
};