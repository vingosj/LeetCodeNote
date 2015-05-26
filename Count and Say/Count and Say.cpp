#include <string>

class Solution {
public:
    string countAndSay(int n) {
        string current = "1", next;
        char cursor;
        int count;
        
        while(--n != 0){
            next = "";
            cursor = '\0';
            count = 0;
            for(auto c : current){
                if(cursor == '\0'){
                    cursor = c;
                    count++;
                }
                else if(cursor == c){
                    count++;
                }else{
                    next = next + std::to_string(count) + cursor;
                    count = 1;
                    cursor = c;
                }
            }
            next = next + std::to_string(count) + cursor;
            
            current = next;
        }
        return current;
    }
};