//  2015-5-23


class Solution {
public:
    string convert(string s, int numRows) {
        if(s == "" || numRows == 1) return s;
        
        string result = "";
        int first = 2*numRows - 2, second = 0, length = s.size();
        bool f = true;
        for(int n = 1; n <= numRows; n++){
            int index = n-1;
            f = true;
            if(n == 1 || n == numRows){
                int gap;
                if(n == 1) gap = first;
                else gap = second;
                while(index<length){
                    result += s[index];
                    index += gap;
                }
                first -= 2;
                second += 2;
            }
            else{
                while(index<length){
                    result += s[index];
                    if(f) index += first;
                    else index += second;
                    f = !f;
                }
                first -= 2;
                second += 2;
            }
        }
        
        return result;
    }
};