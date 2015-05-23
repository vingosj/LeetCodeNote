#include <string>
#include <algorithm>
#include <iterator>

bool BothAreSpace(char lhs, char rhs) {
    return (lhs == rhs) && (lhs == ' ');
}

class Solution {
public:
    void reverseWords(string &s) {
        string::iterator new_end = unique(s.begin(), s.end(), BothAreSpace);
        s.erase(new_end, s.end());
        
        int n = s.size();
        if(n != 0 && s[n-1] == ' ') {
            s.erase(n - 1, 1);
            n = s.size();
        }
        if(n != 0 && s[0] == ' ') {
            s.erase(0, 1);
            n = s.size();
        }
        
        int start = 0, end = n;
        char t = ' ';
        
        for(int i = 0; i <= n; i++){
            if(i == n){
                if(t != ' '){
                    end = i - 1;
                    while(start < end){
                        t = s[start];
                        s[start++] = s[end];
                        s[end--] = t;
                    }
                }
            }
            if(t == ' ' && s[i] != ' '){
                t = s[i];
                start = i;
            }
            else if(s[i] == ' ' && t != ' '){
                // swap sub string here
                end = i - 1;
                while(start < end){
                    t = s[start];
                    s[start++] = s[end];
                    s[end--] = t;
                }
                t = ' ';
            }
        }
        
        reverse(s.begin(), s.end());
        
        return;
    }
};