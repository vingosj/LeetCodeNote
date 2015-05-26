#include <string>

//   2015-5-25

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), count = 0;
        if(n == 0) return 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ' '){
                if(count != 0) return count;
            }
            else count++;
        }
            
        return count;
    }
};