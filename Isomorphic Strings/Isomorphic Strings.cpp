#include <map>
#include <vector>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> sMap;
        map<char, int> tMap;
        
        vector<int> sNote(s.size(), -1);
        vector<int> tNote(t.size(), -1);
        
        for(int i = 0; i < s.size(); i++)
        {
            if(sMap.find(s[i]) == sMap.end()){
                sNote[i] = -1;
                sMap[s[i]] = i;
            }else{
                sNote[i] = sMap[s[i]];
                sMap[s[i]] = i;
            }
        }
        
        for(int i = 0; i < t.size(); i++)
        {
            if(tMap.find(t[i]) == tMap.end()){
                tNote[i] = -1;
                tMap[t[i]] = i;
            }else{
                tNote[i] = tMap[t[i]];
                tMap[t[i]] = i;
            }
            
            if(tNote[i] != sNote[i]) return false;
        }
        
        
        return true;
    }
};