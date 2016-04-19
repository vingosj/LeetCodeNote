// 2016-4-18

class Solution {
public:
    int integerBreak(int n) {
        int previous, part = 1, current = 0;
        do{
            part++;
            previous = current;
            current = 1;
            int temp = n / part + 1;
            for(int i = n % part; i > 0; i--){
                current *= temp;
            }
            temp--;
            for(int i = part - n % part; i > 0; i--){
                current *= temp;
            }
        }while(current > previous);
        
        return previous;
    }
};