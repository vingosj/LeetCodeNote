//   2015-3-22

class Solution {
public:
    int countNext(vector<int>& digits, int previous){
        int count = previous;
        for(int& digit : digits){
            if(digit == 0){
                digit = 1;
                return ++count;
            }
            else{
                digit = 0;
                count--;
            }
        }
        digits.push_back(1);
        return ++count;
    }

    vector<int> countBits(int num) {
        vector<int> result(num+1, 0), digits(1, 0);
        
        for(int i = 1; i < num+1; i++){
            result[i] = countNext(digits, result[i-1]);
        }
        
        return result;
        
    }
};