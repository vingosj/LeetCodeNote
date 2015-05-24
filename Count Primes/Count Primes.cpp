#include <math.h>
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        
        vector<int> prime(n, true);
        
        int i = 2;
        while(pow(i, 2) < n)
        {
            int cursor = 2;
            while(i * cursor < n){
                prime[i*cursor++] = false;
            }
            do{
                i++;
            }while(prime[i] == false && pow(i, 2) < n);
        }
        
        i = 2;
        int number = 0;
        while(i < n)
        {
            if(prime[i++]){ number++;}
        }
        return number;
    }
};