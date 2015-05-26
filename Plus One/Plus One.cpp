//  2015-5-25

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), f = 0;
        if(n == 0) return digits;
        for(int i = n-1; i >= 0; i--){
            if(i == (n-1)) digits[i]++;
            else digits[i] += f;
            f = digits[i] / 10;
            digits[i] %= 10;
        }
        
        if(f == 1)  digits.insert(digits.begin(), 1);
        return digits;
    }
};