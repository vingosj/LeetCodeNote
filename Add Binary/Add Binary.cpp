#include <string>

//   2015-5-25

static char convert(char a, char b, char& c){
    int count = 0;
    if(a == '1') count++;
    if(b == '1') count++;
    if(c == '1') count++;
    
    if(count >= 2) c = '1';
    else c = '0';
    if(count%2 == 0) return '0';
    else return '1';
}

class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "") return b;
        if(b == "") return a;
        int p = a.size() - 1, q = b.size() - 1; string s = "";
        char f = '0';
        while(p >= 0 || q >= 0){
             char n = '0', m = '0', c = '0';
             if(p >= 0) n = a[p--];
             if(q >= 0) m = b[q--];
             c = convert(n, m, f);
             s = c + s;
        }
        if(f == '1') s = f + s;
        return s;
    }
};