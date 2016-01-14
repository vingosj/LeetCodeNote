// 2016-1-13

class Solution {
public:
    string intToRoman(int num) {
        map<int, string, greater<int>> roman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
                                    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        map<int, string>::iterator iter = roman.begin();
        string str;
        int tmp, loop;
        while(num > 0){
            while(num < (tmp = iter->first)){
                advance(iter, 1);
            }
            
            loop = num / tmp;
            num %= tmp;
            for(int i = 0; i < loop; i++){
                str += iter->second;
            }
        }
        
        return str;
    }
};