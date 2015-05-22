#include <string>

// 2015-5-22

static int first(string& s){
    if(s == "") return 0;
    
    int i = s.find('.');
    int result = 0;
    if(i == string::npos){
        result = std::stoi(s);
        s = "";
    }else{
        result = std::stoi(s.substr(0, i));
        s = s.substr(i+1);
    }
    
    return result;
}

static int Compare(int a, int b){
    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int f1 = first(version1), f2 = first(version2);
        
        while(f1 == f2 && version1 != version2){
            f1 = first(version1);
            f2 = first(version2);
        }
        
        return Compare(f1, f2);
    }
};