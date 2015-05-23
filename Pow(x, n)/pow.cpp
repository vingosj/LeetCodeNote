#include <stdlib.h>
#include <limits.h>

static bool check(double p, double q){
    double max = numeric_limits<double>::max();
    double min = numeric_limits<double>::min();
    if(abs(max / p) < abs(q)) return 0;
    if(abs(min / p) > abs(q)) return 0;
    return true;
}

static double binary(double x, long n){
    if(n == 1) return x;
    else if(n%2 == 1){
        double left = binary(x, n/2);
        //if(!check(left, x)) return 0;
        double right = x * left;
        //if(!check(left, right)) return 0;
        return left * right;
    }else{
        double side = binary(x, n/2);
        //if(check(side, side)) return 0;
        return side*side;
    }
}

class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1;
        long l = (long)n;
        //double max = numeric_limits<double>::max();
        //double min = numeric_limits<double>::min();
        if(n == 0) return answer;
        
        if(n < 0){
            x = 1.0 / x;
            l = abs(l);
        }

        return binary(x, l);
    }
};