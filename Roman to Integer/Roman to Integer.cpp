// 2016-1-13

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int num = 0, cur, next, n = s.size();
        
        for(int i = 0; i < n; i++){
            cur = roman[s[i]];
            if(i != n - 1){
                next = roman[s[i+1]];
                if(next > cur){
                    num += (next - cur);
                    i++;
                    continue;
                }
            }
            num += cur;
        }
        
        return num;
    }
};