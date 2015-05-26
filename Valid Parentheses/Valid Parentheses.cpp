#include <stack>

class Solution {
public:
    bool isValid(string s) {
        int small = 0, mid = 0, big = 0;
        stack<char> last;
        for(auto c : s){
            switch(c){
                case '(': 
                    small++;
                    last.push(c);
                    break;
                case ')':
                    if(--small < 0) return false;
                    if(last.top() != '(') return false;
                    last.pop();
                    break;
                case '[':
                    mid++;
                    last.push(c);
                    break;
                case ']':
                    if(--mid < 0) return false;
                    if(last.top() != '[') return false;
                    last.pop();
                    break;
                case '{':
                    big++;
                    last.push(c);
                    break;
                case '}':
                    if(--big < 0) return false;
                    if(last.top() != '{') return false;
                    last.pop();
                    break;
                default: break;
            }
        }
        
        if(small == 0 && mid == 0 && big == 0) return true;
        else return false;
    }
};